// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__77844DEE_B96F_4DB6_BFA7_39B3A7CD0A1F__INCLUDED_)
#define AFX_STDAFX_H__77844DEE_B96F_4DB6_BFA7_39B3A7CD0A1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define INIFILENAME ".\\Scanner.ini"
#define LIST_RESULT_INDEX	0
#define LIST_RESULT_IP		1
#define LIST_RESULT_STATE	2
#define LIST_RESULT_OS		3

#include	<winsock2.h>

#pragma comment(lib,"ws2_32")
#include	<afxsock.h>

typedef union MultiByteStruct
{
	int iInt;
	float fFloat;
	UINT uInt;
	ULONG uLong;
	DWORD dwDword;
	WORD wWord[2];
	UCHAR ucByte[4];
}UNIONIP,*PUNIONIP;

typedef struct iphdr{
	UCHAR	ver_pack;
	UCHAR	tos;
	USHORT	total_len;
	USHORT	ident;
	USHORT	frag_and_flags;
	UCHAR	ttl;
	UCHAR	proto;
	USHORT	checksum;
	UINT	sourceIP;
	UINT	desrIP;
}IPHEADER,*PIPHEADER;

typedef struct tcphdr //����TCP�ײ�
{
	USHORT th_sport; //16λԴ�˿�
	USHORT th_dport; //16λĿ�Ķ˿�
	unsigned int th_seq; //32λ���к�
	unsigned int th_ack; //32λȷ�Ϻ�
	unsigned char th_lenres; //4λ�ײ�����/6λ������
	unsigned char th_flag; //6λ��־λ
	USHORT th_win; //16λ���ڴ�С
	USHORT th_sum; //16λУ���
	USHORT th_urp; //16λ��������ƫ����
}TCPHEADER;

typedef struct udphdr //����UDP�ײ�
{
	unsigned short uh_sport;     //16λԴ�˿�
	unsigned short uh_dport;     //16λĿ�Ķ˿�
	unsigned short uh_len;           //16λ����
	unsigned short uh_sum;    //16λУ���
} UDPHEADER;

typedef struct icmpher{
	BYTE	i_type;
	BYTE	i_code;
	USHORT	i_cksum;
	USHORT	i_id;
	USHORT	i_seq;
	UCHAR	buff[32];
}ICMPHEADER,*PICMPHEADER;

CString IPIntToStr(UINT IPInt);
UINT IPStrToInt(CString IPStr);
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__77844DEE_B96F_4DB6_BFA7_39B3A7CD0A1F__INCLUDED_)
