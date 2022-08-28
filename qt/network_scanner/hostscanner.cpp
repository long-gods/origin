#include "hostscanner.h"
host::host()
{
    this->stopped=0;
}


void host::generate(int start,int end)
{
    for(int i=start;i<=end;++i)
    {
        this->Q.enqueue(i);
    }
}

#include <iostream>
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

// IP数据包头结构
typedef struct iphdr
{
    unsigned int headLen : 4;
    unsigned int version : 4;
    unsigned char tos;
    unsigned short totalLen;
    unsigned short ident;
    unsigned short fragAndFlags;
    unsigned char ttl;
    unsigned char proto;
    unsigned short checkSum;
    unsigned int sourceIP;
    unsigned int destIP;
}IpHeader;

// ICMP数据头结构
typedef struct ihdr
{
    unsigned char iType;
    unsigned char iCode;
    unsigned short iCheckSum;
    unsigned short iID;
    unsigned short iSeq;
    unsigned long  timeStamp;
}IcmpHeader;

// 计算ICMP包的校验和(发送前要用)
unsigned short checkSum(unsigned short* buffer, int size)
{
    unsigned long ckSum = 0;

    while (size > 1)
    {
        ckSum += *buffer++;
        size -= sizeof(unsigned short);
    }

    if (size)
    {
        ckSum += *(unsigned char*)buffer;
    }

    ckSum = (ckSum >> 16) + (ckSum & 0xffff);
    ckSum += (ckSum >> 16);

    return (unsigned short)(~ckSum);
}

// 填充ICMP请求包的具体参数
void fillIcmpData(char* icmpData, int dataSize)
{
    IcmpHeader* icmpHead = (IcmpHeader*)icmpData;
    icmpHead->iType = 8;  // 8表示请求包
    icmpHead->iCode = 0;
    icmpHead->iID = (unsigned short)GetCurrentThreadId();
    icmpHead->iSeq = 0;
    icmpHead->timeStamp = GetTickCount();
    char* datapart = icmpData + sizeof(IcmpHeader);
    memset(datapart, 'x', dataSize - sizeof(IcmpHeader)); // 数据部分为xxx..., 实际上有32个x
    icmpHead->iCheckSum = checkSum((unsigned short*)icmpData, dataSize); // 千万要注意，这个一定要放到最后
}

// 对返回的IP数据包进行解析，定位到ICMP数据
int decodeResponse(char* buf, int bytes, struct sockaddr_in* from, int tid)
{
    IpHeader* ipHead = (IpHeader*)buf;
    unsigned short ipHeadLen = ipHead->headLen * 4;
    if (bytes < ipHeadLen + 8) // ICMP数据不完整, 或者不包含ICMP数据
    {
        return -1;
    }

    IcmpHeader* icmpHead = (IcmpHeader*)(buf + ipHeadLen);  // 定位到ICMP包头的起始位置
    if (icmpHead->iType != 0)   // 0表示回应包
    {
        return -2;
    }

    if (icmpHead->iID != (unsigned short)tid) // 理应相等
    {
        return -3;
    }

    int time = GetTickCount() - (icmpHead->timeStamp); // 返回时间与发送时间的差值
    if (time >= 0)
    {
        return time;
    }

    return -4; // 时间错误
}

// ping操作
bool ping(const char* ip, unsigned int timeout)
{
    // 网络初始化
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1, 1), &wsaData);
    unsigned int sockRaw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);  // 注意，第三个参数非常重要，指定了是icmp
    setsockopt(sockRaw, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));  // 设置套接字的接收超时选项
    setsockopt(sockRaw, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));  // 设置套接字的发送超时选项

    // 准备要发送的数据
    int  dataSize = sizeof(IcmpHeader) + 32; // 待会儿会有32个x
    char icmpData[1024] = { 0 };
    fillIcmpData(icmpData, dataSize);
    unsigned long startTime = ((IcmpHeader*)icmpData)->timeStamp;

    // 远程通信端
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    struct hostent* hp = gethostbyname(ip);
    memcpy(&(dest.sin_addr), hp->h_addr, hp->h_length);
    dest.sin_family = hp->h_addrtype;

    // 发送数据
    sendto(sockRaw, icmpData, dataSize, 0, (struct sockaddr*)&dest, sizeof(dest));

    int iRet = -1;
    struct sockaddr_in from;
    int fromLen = sizeof(from);
    while (1)
    {
        // 接收数据
        char recvBuf[1024] = { 0 };
        int iRecv = recvfrom(sockRaw, recvBuf, 1024, 0, (struct sockaddr*)&from, &fromLen);
        int time = decodeResponse(recvBuf, iRecv, &from, GetCurrentThreadId());
        if (time >= 0)
        {
//            qDebug()<<iRecv;
//            qDebug()<<QString::fromLocal8Bit(recvBuf);
            iRet = 0;   // ping ok
            break;
        }
        else if (GetTickCount() - startTime >= timeout || GetTickCount() < startTime)
        {
            iRet = -1;  // ping超时
            break;
        }
    }

    // 释放
    closesocket(sockRaw);
    WSACleanup();

    return iRet==0;
}

void host::run()
{
       QMutex mutex;
       QMutex text;
       QString ip=this->ip;
       while(!this->Q.empty()){
//       QTcpSocket tsocket(0);
//       QUdpSocket usocket(0);
//       tsocket.setProxy(QNetworkProxy::NoProxy);
//       tsocket.abort();
//       usocket.setProxy(QNetworkProxy::NoProxy);
//       usocket.abort();
       mutex.lock();
       int tmpip =this->Q.dequeue();
       if(this->stopped)
       {
           mutex.unlock();
           this->nowip=tmpip;
           this->quit();
           break;
       }
//       tsocket.connectToHost(ip+QString::number(tmpip),135);
//       usocket.connectToHost(ip+QString::number(nowip),0);
       QString  str=ip+QString::number(tmpip);
       char*  ch;
       QByteArray ba = str.toLatin1(); // must
       ch=ba.data();
       bool tres=ping(ch,1000);
      // bool ures=usocket.waitForConnected(100);
//       qDebug()<<tres;
       if(tres)
       {
           text.lock();
           QString message=ip+QString::number(tmpip);
           emit sig3(message);
           text.unlock();
       }
//       else if(ures)
//       {
//           text.lock();
//           QString message=ip+":";
//           message+=QString::number(tmpport,10)+"udp  opened!";
//           emit sig3(message);
//           text.unlock();
//       }
       emit sentnowip(tmpip);
       mutex.unlock();
       }
}

void host::stop()
{
    this->stopped=true;
}
