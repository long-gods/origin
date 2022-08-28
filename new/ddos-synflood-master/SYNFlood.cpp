#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib,"ws2_32.lib")

#define IPVER 4
#define MAX_BUFF_LEN 65500

typedef struct ip_hdr
{
    UCHAR h_verlen;
    UCHAR tos;
    USHORT total_len;
    USHORT ident;
    USHORT frag_and_flags;
    UCHAR ttl;
    UCHAR proto;
    USHORT checksum;
    ULONG sourceIP;
    ULONG destIP;
}IP_HEADER;

typedef struct tsd_hdr
{
    ULONG saddr;
    ULONG daddr;
    UCHAR mbz;
    UCHAR ptcl;
    USHORT tcpl;
}PSD_HEADER;

typedef struct tcp_hdr
{
    USHORT th_sport;
    USHORT th_dport;
    ULONG th_seq;
    ULONG th_ack;
    UCHAR th_lenres;
    UCHAR th_flag;
    USHORT th_win;
    USHORT th_sum;
    USHORT th_urp;
}TCP_HEADER;

USHORT checksum(USHORT* buffer, int size)
{
    unsigned long cksum = 0;
    while (size > 1)
    {
        cksum += *buffer++;
        size -= sizeof(USHORT);
    }
    if (size)
    {
        cksum += *(UCHAR*)buffer;
    }

    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);
    return (USHORT)(~cksum);
}

int main()
{
    WSADATA WSAData;
    SOCKET sock;

    IP_HEADER ipHeader;
    TCP_HEADER tcpHeader;
    PSD_HEADER psdHeader;

    char Sendto_Buff[MAX_BUFF_LEN];
    unsigned short check_Buff[MAX_BUFF_LEN];
    const char tcp_send_data[] = { "This is TCP data!" };

    BOOL flag;
    int rect, nTimeOver;

    //if (argc != 5)
    //{
    //    printf("Useage: SendTcp soruce_ip source_port dest_ip dest_port \n");

    //    return false;
    //}

    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
    {
        printf("WSAStartup Error!\n");
        return false;
    }

    if ((sock = WSASocket

    (AF_INET, SOCK_RAW, IPPROTO_IP, NULL, 0, WSA_FLAG_OVERLAPPED))

        == INVALID_SOCKET)
    {
        printf("Socket Setup Error!\n");
        return false;
    }
    flag = true;
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*)&flag, sizeof(flag)) == SOCKET_ERROR)
    {
        printf("setsockopt IP_HDRINCL error!\n");
        return false;
    }
    nTimeOver = 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&nTimeOver, sizeof(nTimeOver)) == SOCKET_ERROR)
    {
        printf("setsockopt SO_SNDTIMEO error!\n");
        return false;
    }

    ipHeader.h_verlen = (IPVER << 4 | sizeof(ipHeader) / sizeof(unsigned long));

    ipHeader.tos = (UCHAR)0;
    ipHeader.total_len = htons((unsigned short)sizeof(ipHeader) + sizeof

    (tcpHeader)+sizeof(tcp_send_data));
    ipHeader.ident = 0;
    ipHeader.frag_and_flags = 0;
    ipHeader.ttl = 128;
    ipHeader.proto = IPPROTO_TCP;
    ipHeader.checksum = 0;
    ipHeader.sourceIP = inet_addr("192.168.123.137");
    ipHeader.destIP = inet_addr("192.168.1.128");

    memset(check_Buff, 0, MAX_BUFF_LEN);
    memcpy(check_Buff, &ipHeader, sizeof(IP_HEADER));
    ipHeader.checksum = checksum(check_Buff, sizeof(IP_HEADER));

    psdHeader.saddr = ipHeader.sourceIP;
    psdHeader.daddr = ipHeader.destIP;
    psdHeader.mbz = 0;
    psdHeader.ptcl = ipHeader.proto;
    psdHeader.tcpl = htons(sizeof(TCP_HEADER) + sizeof(tcp_send_data));

    tcpHeader.th_dport = htons(atoi("80"));
    tcpHeader.th_sport = htons(atoi("8009"));
    tcpHeader.th_seq = 0;
    tcpHeader.th_ack = 0;
    tcpHeader.th_lenres = (sizeof(tcpHeader) / sizeof(unsigned long) << 4 | 0);
    tcpHeader.th_flag = 2;

    tcpHeader.th_win = htons((unsigned short)16384);
    tcpHeader.th_urp = 0;
    tcpHeader.th_sum = 0;

    memset(check_Buff, 0, MAX_BUFF_LEN);
    memcpy(check_Buff, &psdHeader, sizeof(psdHeader));
    memcpy(check_Buff + sizeof(psdHeader), &tcpHeader, sizeof(tcpHeader));
    memcpy(check_Buff + sizeof(PSD_HEADER) + sizeof

    (TCP_HEADER), tcp_send_data, sizeof(tcp_send_data));
    tcpHeader.th_sum = checksum(check_Buff, sizeof(PSD_HEADER) + sizeof

    (TCP_HEADER)+sizeof(tcp_send_data));

    memset(Sendto_Buff, 0, MAX_BUFF_LEN);
    memcpy(Sendto_Buff, &ipHeader, sizeof(IP_HEADER));
    memcpy(Sendto_Buff + sizeof(IP_HEADER), &tcpHeader, sizeof

    (TCP_HEADER));
    memcpy(Sendto_Buff + sizeof(IP_HEADER) + sizeof

    (TCP_HEADER), tcp_send_data, sizeof(tcp_send_data));
    int datasize = sizeof(IP_HEADER) + sizeof(TCP_HEADER) + sizeof

    (tcp_send_data);
    SOCKADDR_IN dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr("192.168.1.128");

    rect = sendto(sock, Sendto_Buff, datasize, 0, (struct sockaddr*)&dest,

        sizeof(dest));
    if (rect == SOCKET_ERROR)
    {
        printf("send error!:%d\n", WSAGetLastError());
        return false;
    }
    else
        printf("send ok!\n");
    closesocket(sock);
    WSACleanup();

    return 0;
}
