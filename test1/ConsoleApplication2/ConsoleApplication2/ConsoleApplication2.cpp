#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include<iostream>
using namespace std;
//定义IP首部格式
typedef struct  _IPHeader
{
    u_char vile;           // 版本和首部长度
    u_char ser;            // 服务类型
    u_short totalLen;      // 总长度
    u_short id;            // 标示符
    u_short flag;          // 标记+分片偏移
    u_char ttl;            // 存活时间
    u_char protocol;       // 协议
    u_short checkSum;      // 首部校验和
    in_addr srcIP;         // 源IP地址
    in_addr destIP;        // 目的IP地址
}IPHeader, * PIPHDR;

//ICMP头部
typedef struct _ICMPHeader
{
    u_char type;            // 类型
    u_char code;            // 代码
    u_short checkSum;       // 校验和
    u_short id;             // 标示符
    u_short seq;            // 序列号
}ICMPHeader, * PICMPHDR;

//ICMP时间戳请求报文
typedef struct _ECHOREQUEST
{
    ICMPHeader icmpHeader;       //ICMP头部
    int time;                    //记录ping时间  
    char data[32];               //数据
}ECHOREQUEST, * pechorequest;

//ICMP时间戳应答报文
typedef struct _ECHORESPONSE
{
    IPHeader ipHeader;
    ECHOREQUEST echoRequest;
    char fill[255];            //接收其他多余的应答数据

}ECHORESPONSE, * PECHORESPONSE;

// 计算校验和(16位二进制反码求和)
u_short checksum(u_short* buffer, int len)
{
    register int nleft = len;
    register u_short* w = buffer;
    register u_short answer;
    register int sum = 0;
    // 使用32bit的累加器，进行16bit的反馈计算
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }
    // 补全奇数位
    if (nleft == 1) {
        u_short u = 0;

        *(u_char*)(&u) = *(u_char*)w;
        sum += u;
    }
    // 将反馈的16bit从高位移至地位
    sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
    sum += (sum >> 16);                 /* add carry */
    answer = ~sum;                      /* truncate to 16 bits */
    return (answer);
}
//发送ICMP数据包 sendEchoReQuest
void sendEchoReQuest(SOCKET sock, sockaddr_in dstIP)
{
    static int id = 1;
    static int seq = 1;

    //ICMP请求
    ECHOREQUEST echoRequest = { 0 };
    //主要是用来记录请求应答的时间，当发送ECHO请求时记录发送时间，当接受到应答数据时，在用GetTickcount()- echoRequest.time这样就能得到请求应答需要多少时间了。
    echoRequest.time = GetTickCount();
    echoRequest.icmpHeader.type = 8;
    echoRequest.icmpHeader.code = 0;
    echoRequest.icmpHeader.id = id++;
    echoRequest.icmpHeader.seq = seq++;
    echoRequest.icmpHeader.checkSum =
        checksum((u_short*)&echoRequest, sizeof(echoRequest));

    int re = sendto(sock,
        (char*)&echoRequest,
        sizeof(echoRequest),
        0,
        (sockaddr*)&dstIP,
        sizeof(dstIP));

    if (re == SOCKET_ERROR)
    {
        std::cout<<" send error \n ";
    }
    return;
}


//接收ICMP数据包 recvEchoReQuest
void recvEchoReQuest(SOCKET sock,
    ECHORESPONSE* sponse, sockaddr_in* dstIP)
{
    int size = sizeof(sockaddr);
    int re = recvfrom(sock, (char*)sponse, sizeof(ECHORESPONSE), 0,
        (sockaddr*)dstIP, &size);
    if (re == SOCKET_ERROR)
    {
        printf(" recvfrom error");
    }
    return;
}


//ping函数
void Ping(const char* host)
{
    //2.创建套接字
    SOCKET sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);


    //获取域名对应的IP
    HOSTENT* lpHost = gethostbyname(host);

    sockaddr_in dstIP = { 0 };
    dstIP.sin_family = AF_INET;
    dstIP.sin_addr.S_un.S_addr = *(u_long*)lpHost->h_addr;

    for (int i = 0; i < 4; i++)
    {
        //发送ICMP数据
        sendEchoReQuest(sock, dstIP);

        //接收ICMP数据
        ECHORESPONSE sponse;
        recvEchoReQuest(sock, &sponse, &dstIP);

        printf("来自 %s 的回复: 字节=32 时间=%dms TTL=%d \n",
            inet_ntoa(dstIP.sin_addr),
            GetTickCount() - sponse.echoRequest.time,
            sponse.ipHeader.ttl
        );
    }
}

int main()
{
    //1.初始化winsock环境
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    while (true)
    {
        Ping("www.baidu.com");
        char in = getchar();
        if (in == 'q')
        {
            break;
        }

    }
    //2.释放环境
    WSACleanup();

    return 0;
}