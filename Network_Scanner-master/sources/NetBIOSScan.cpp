// NetBIOSScan.cpp : implementation file
//

#include "stdafx.h"
#include "Scanner.h"
#include "NetBIOSScan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CNetBIOSScan *pDlgNetBIOSScan;
/////////////////////////////////////////////////////////////////////////////
// CNetBIOSScan dialog


CNetBIOSScan::CNetBIOSScan(CWnd* pParent /*=NULL*/)
	: CDialog(CNetBIOSScan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetBIOSScan)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNetBIOSScan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetBIOSScan)
	DDX_Control(pDX, IDC_TREEResult, m_ctlTreeResult);
	DDX_Control(pDX, IDC_IPADDRESSIP, m_ctlIP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNetBIOSScan, CDialog)
	//{{AFX_MSG_MAP(CNetBIOSScan)
	ON_BN_CLICKED(IDC_BUTTONStart, OnBUTTONStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetBIOSScan message handlers

BOOL CNetBIOSScan::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	WSADATA	wsaData;
	WORD	version=MAKEWORD(2,0);
	int ret = WSAStartup(version,&wsaData);
	if(ret!=0){
		MessageBox("�׽��ֳ�������");
		return false;
	}

	char buff[MAX_PATH];
	GetPrivateProfileString("NetBIOSScan","TargetIP","192.168.0.101",buff,MAX_PATH,INIFILENAME);
	m_ctlIP.SetWindowText(buff);
	UpdateData(false);
	pDlgNetBIOSScan=this;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNetBIOSScan::OnBUTTONStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	UCHAR	a,b,c,d;
	CString	strTemp,strIP;
	m_ctlIP.GetAddress(a,b,c,d);
	strIP.Format("%d.%d.%d.%d",a,b,c,d);
	strTemp.Format("NetBIOSɨ��[%s]",strIP);
	HTREEITEM root=m_ctlTreeResult.InsertItem(strTemp,0,1,TVI_ROOT);

	ConnectServer(strIP,true,root);
	ReadHostName(strIP,root);
	ReadMAC(strTemp,root);

	char netNB[MAX_PATH]={0};
	sprintf(netNB,"\\\\%s",strIP);
	USHORT lpwHostStr[MAX_PATH]={0};
	MultiByteToWideChar(CP_ACP,0,netNB,-1,(LPWSTR)lpwHostStr,MAX_PATH);

	ReadTime(lpwHostStr,root);
	ReadShareDirectory(lpwHostStr,root);
	ReadGroup(lpwHostStr,root);
	ReadLocalGroup(lpwHostStr,root);
	ReadOS(lpwHostStr,root);
	ReadProtocol(lpwHostStr,root);
	ReadUser(lpwHostStr,root);
	ReadSession(lpwHostStr,root);
	ReadTransport(lpwHostStr,root);

	ConnectServer(strIP,false,root);
}

BOOL CNetBIOSScan::ConnectServer(CString strIP, BOOL bConnect, HTREEITEM rtItem)
{
	CString strTemp;
	char	ipc[MAX_PATH]={0};
	sprintf(ipc,"\\\\%s",strIP);

	DWORD ret = ERROR_SUCCESS;
	if(bConnect){
		NETRESOURCE nr;
		memset((char *)&nr,0,sizeof(nr));
		nr.lpLocalName=NULL;
		nr.lpProvider=NULL;
		nr.dwType=RESOURCETYPE_ANY;
		nr.lpRemoteName=(char *)&ipc;
		ret = WNetAddConnection2(&nr,NULL,NULL,0);
		if(ret!=ERROR_SUCCESS){
			strTemp.Format("����ʧ�ܣ��Է����ܲ���xpϵͳ������Զ������");
			m_ctlTreeResult.InsertItem(strTemp,2,3,rtItem);
		}
	}else{
		ret = WNetCancelConnection2((char *)ipc,0,true);
	}
	return true;
}

BOOL CNetBIOSScan::ReadHostName(CString strIP, HTREEITEM rtItem)
{
	BOOL	bConnectSuccess=false;
	CString	strTemp;
	struct hostent *pHost;
	struct in_addr addr;
	addr.S_un.S_addr=inet_addr(strIP);
	pHost=gethostbyaddr((char *)&addr,sizeof(addr),AF_INET);
	if(pHost!=NULL){
		strTemp.Format("��������%s",pHost->h_name);
		m_ctlTreeResult.InsertItem(strTemp,2,3,rtItem);
		bConnectSuccess=true;
	}
	return bConnectSuccess;
}

BOOL CNetBIOSScan::ReadMAC(CString strIP, HTREEITEM rtItem)
{
	BOOL bConnectSuccess;
	CString strTemp;

	UNIONIP unIPAddr;
	unIPAddr.iInt=inet_addr(strIP);
	UCHAR Mac[6]={0xff,0xff,0xff,0xff,0xff,0xff};
	PULONG pMac=(PULONG)Mac;
	ULONG len=6;
	HRESULT hr=SendARP(unIPAddr.iInt,0,pMac,&len);
	if(hr==0){
		strTemp.Format("MAC��ַ��%02X-%02X-%02X-%02X-%02X-%02X",Mac[0],Mac[1],Mac[2],Mac[3],Mac[4],Mac[5]);
		m_ctlTreeResult.InsertItem(strTemp,2,3,rtItem);
		bConnectSuccess=true;
	}
	return bConnectSuccess;
}

BOOL CNetBIOSScan::ReadTime(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;

	LPTIME_OF_DAY_INFO pBuf=NULL;
	nStatus=NetRemoteTOD((LPCWSTR)strIP,(LPBYTE *)&pBuf);
	if(nStatus==NERR_Success){
		if(pBuf!=NULL){
			CTime time(pBuf->tod_year,pBuf->tod_month,pBuf->tod_day,pBuf->tod_hours,pBuf->tod_mins,pBuf->tod_secs);
			CTimeSpan ts(0,8,0,0);
			time+=ts;
			strTemp.Format("����ʱ�䣺%04d-%02d-%02d %02d:%02d:%02d",time.GetYear(),time.GetMonth(),time.GetDay(),
				time.GetHour(),time.GetMinute(),time.GetSecond());
			m_ctlTreeResult.InsertItem(strTemp,2,3,rtItem);
		}
	}
	if(pBuf!=NULL){
		NetApiBufferFree(pBuf);
	}
	return true;
}

BOOL CNetBIOSScan::ReadShareDirectory(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;

	LPSHARE_INFO_1 pShare_1=NULL;
	DWORD	dwPrefMaxLen=-1;
	DWORD	dwEntriesRead=0;
	DWORD	dwTotalEntries=0;
	DWORD	dwResumeHandle=0;
	DWORD	i;
	DWORD	dwLevel=1;
	nStatus=NetShareEnum((LPWSTR)strIP,dwLevel,(LPBYTE *)&pShare_1,dwPrefMaxLen,&dwEntriesRead,
		&dwTotalEntries,&dwResumeHandle);
	if((nStatus==NERR_Success)||(nStatus==ERROR_MORE_DATA)){
		HTREEITEM curr=m_ctlTreeResult.InsertItem("�����ļ���",2,3,rtItem);
		LPSHARE_INFO_1 pTmpShare_1=pShare_1;
		for(i=0;i<dwEntriesRead;i++){
			char NameBuff[160];
			WideCharToMultiByte(CP_ACP,0,(LPCWCH)pTmpShare_1->shi1_netname,150,
				NameBuff,100,NULL,NULL);
			strTemp.Format("%s[%s]",NameBuff,pTmpShare_1->shi1_remark);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			pTmpShare_1++;
		}
	}
	if(pShare_1!=NULL)
		NetApiBufferFree(pShare_1);
	return true;
}

BOOL CNetBIOSScan::ReadGroup(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;

	PGROUP_INFO_2 pGroup_2=NULL;
	DWORD	dwPrefMaxLen=-1;
	DWORD	dwEntriesRead=0;
	DWORD	dwTotalEntries=0;
	DWORD	dwResumeHandle=0;
	DWORD	dwLevel=2;
	nStatus = NetGroupEnum((LPWSTR)strIP,dwLevel,(LPBYTE *)&pGroup_2,dwPrefMaxLen,&dwEntriesRead,&dwTotalEntries,&dwResumeHandle);
	if((nStatus==NERR_Success)||(nStatus==ERROR_MORE_DATA)){
		HTREEITEM curr=m_ctlTreeResult.InsertItem("ȫ������",2,3,rtItem);
		PGROUP_INFO_2 pTmpGroup_2=pGroup_2;
		for(DWORD i=0;i<dwEntriesRead;i++){
			strTemp.Format("������%s[%s],��ID��%d,���ԣ�%d",pTmpGroup_2->grpi2_name,pTmpGroup_2->grpi2_comment,
				pTmpGroup_2->grpi2_group_id,pTmpGroup_2->grpi2_attributes);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			pTmpGroup_2++;
		}
	}
	if(pGroup_2!=NULL)
		NetApiBufferFree(pGroup_2);
	return true;
}

BOOL CNetBIOSScan::ReadLocalGroup(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;

	PGROUP_INFO_2 pGroup_2=NULL;
	DWORD	dwPrefMaxLen=-1;
	DWORD	dwEntriesRead=0;
	DWORD	dwTotalEntries=0;
	DWORD	dwResumeHandle=0;
	DWORD	dwLevel=2;
	nStatus=NetLocalGroupEnum((LPWSTR)strIP,dwLevel,(LPBYTE *)&pGroup_2,dwPrefMaxLen,&dwEntriesRead,&dwTotalEntries,&dwResumeHandle);
	if(nStatus==NERR_Success){
		HTREEITEM curr=m_ctlTreeResult.InsertItem("��������",2,3,rtItem);
		PGROUP_INFO_2 pTmpGroup_2=pGroup_2;
		for(DWORD i=0;i<dwEntriesRead;i++){
			strTemp.Format("������%s[%s]����ID��%d�����ԣ�%d",pTmpGroup_2->grpi2_name,pTmpGroup_2->grpi2_comment,
				pTmpGroup_2->grpi2_group_id,pTmpGroup_2->grpi2_attributes);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			pTmpGroup_2++;
		}
	}
	if(pGroup_2!=NULL)
		NetApiBufferFree(pGroup_2);

	return true;
}

BOOL CNetBIOSScan::ReadOS(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS	nStatus;
	CString strTemp;

	PSERVER_INFO_102 pServer=NULL;
	nStatus=NetServerGetInfo((LPWSTR)strIP,102,(PBYTE *)&pServer);
	if(nStatus==NERR_Success){
		if(pServer!=NULL){
			HTREEITEM curr=m_ctlTreeResult.InsertItem("����ϵͳ",2,3,rtItem);
			strTemp.Format("ƽ̨ID��%d",pServer->sv102_platform_id);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("���ƣ�%s",pServer->sv102_name);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("�汾��%d.%d",pServer->sv102_version_major,pServer->sv102_version_minor);
			switch(pServer->sv102_version_major){
			case 4:
				strTemp+="[Win NT 4]";
				break;
			case 5:
				if(pServer->sv102_version_minor==0)
					strTemp+="[Win 2000]";
				else
				{
					if(pServer->sv102_version_minor==1)
						strTemp+="[Win XP]";
					else
						strTemp+="[win 2000/XP]";
				}
			case 6:
				strTemp+="[Win 2003]";
				break;
			case 7:
				strTemp+="[Win Vista/7]";
				break;
			default:
				strTemp+="[Other OS]";
				break;
			}
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp="���ͣ�";
			if((pServer->sv102_type & SV_TYPE_WORKSTATION)!=0)
				strTemp+="[����վ]";
			if((pServer->sv102_type & SV_TYPE_SERVER)!=0)
				strTemp+="[������]";
			if((pServer->sv102_type & SV_TYPE_SQLSERVER)!=0)
				strTemp+="[SQL������]";
			if((pServer->sv102_type & SV_TYPE_DOMAIN_CTRL)!=0)
				strTemp+="[���������]";
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);

			strTemp.Format("ע�ͣ�%s",pServer->sv102_comment);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("���̣�%d",pServer->sv102_disc);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("���أ�%s",pServer->sv102_hidden?"��":"��");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("������%d",pServer->sv102_announce);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("anndelta:%d",pServer->sv102_anndelta);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("licenses:%d",pServer->sv102_licenses);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			strTemp.Format("·����%s",pServer->sv102_userpath);
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
	}
	if(pServer!=NULL)
		NetApiBufferFree(pServer);
	return true;
}

BOOL CNetBIOSScan::ReadProtocol(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS	nStatus;
	CString strTemp;

	DWORD	OptionsWanted=SUPPORTS_REMOTE_ADMIN_PROTOCOL | SUPPORTS_RPC | SUPPORTS_SAM_PROTOCOL | 
							SUPPORTS_UNICODE | SUPPORTS_LOCAL;
	DWORD	OptionsSupported;
	LPDWORD	pOptionsSupported=&OptionsSupported;
	nStatus	= NetRemoteComputerSupports((LPCWSTR)strIP,OptionsWanted,pOptionsSupported);
	if(nStatus==NERR_Success){
		HTREEITEM curr=m_ctlTreeResult.InsertItem("֧�ַ���",2,3,rtItem);
		if (OptionsSupported & SUPPORTS_REMOTE_ADMIN_PROTOCOL)
		{
			strTemp.Format("֧��Զ�˹���");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
		if (OptionsSupported & SUPPORTS_RPC)
		{
			strTemp.Format("֧��RPC");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
		if (OptionsSupported & SUPPORTS_SAM_PROTOCOL)
		{
			strTemp.Format("֧��SAM");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
		if (OptionsSupported & SUPPORTS_UNICODE)
		{
			strTemp.Format("֧��UNICODE");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
		if (OptionsSupported & SUPPORTS_LOCAL)
		{
			strTemp.Format("֧��LOCAL");
			m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
		}
		
	}
	
	return TRUE;
}

BOOL CNetBIOSScan::ReadUser(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;
	
	//�û�========================================
	LPUSER_INFO_3 pUser_3=NULL;
	DWORD dwPrefMaxLen=-1;
	DWORD dwEntriesRead=0;
	DWORD dwTotalEntries=0;
	DWORD dwResumeHandle=0;
	DWORD dwLevel=3;
	nStatus=NetUserEnum((LPCWSTR)strIP,//Զ��������
		dwLevel,								 //����Ϊ0
		FILTER_NORMAL_ACCOUNT,					 //��ȫ���û���
		(LPBYTE*)&pUser_3,						 //����
		dwPrefMaxLen,							 
		&dwEntriesRead,
		&dwTotalEntries,
		&dwResumeHandle);
	if (nStatus!=NERR_Success && nStatus!=ERROR_MORE_DATA)
	{
		strTemp.Format("%d %d %d %d",nStatus,ERROR_ACCESS_DENIED,NERR_InvalidComputer,ERROR_MORE_DATA);
		MessageBox(strTemp);
	}
	else
	{
		HTREEITEM curr=m_ctlTreeResult.InsertItem("�û���",2,3,rtItem);
		LPUSER_INFO_3 pTmpUser_3=pUser_3;
		for (DWORD i=0;i<dwEntriesRead;i++)
		{
			char NameBuff[160];
			//WideCharToMultiByte(CP_ACP,0,(unsigned short *)pTmpGroup_1->grpi1_name,
			//	150,NameBuff,100,NULL,NULL);

			strTemp.Format("%S[%S]",pTmpUser_3->usri3_name,pTmpUser_3->usri3_full_name);
			HTREEITEM sub=m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
			
			WideCharToMultiByte(CP_ACP,0,pTmpUser_3->usri3_full_name,150,NameBuff,100,NULL,NULL);
			strTemp.Format("�û�ȫ��:%s",NameBuff);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			WideCharToMultiByte(CP_ACP,0,pTmpUser_3->usri3_comment,150,NameBuff,100,NULL,NULL);
			strTemp.Format("�û�����:%s",NameBuff);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			WideCharToMultiByte(CP_ACP,0,pTmpUser_3->usri3_logon_server,150,NameBuff,100,NULL,NULL);
			strTemp.Format("��¼����:%s [\\\\*:�ɴ�����������¼]",NameBuff);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			WideCharToMultiByte(CP_ACP,0,pTmpUser_3->usri3_script_path,150,NameBuff,100,NULL,NULL);
			strTemp.Format("��¼�ű�:%s",NameBuff);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			WideCharToMultiByte(CP_ACP,0,pTmpUser_3->usri3_profile,150,NameBuff,100,NULL,NULL);
			strTemp.Format("Profile:%s",NameBuff);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			int dValue=pTmpUser_3->usri3_password_age;
			strTemp.Format("��������:%ld��%dСʱ%d��",dValue/(24*3600),dValue%(24*3600)/(3600),(dValue%3600)/60);
			dValue=pTmpUser_3->usri3_acct_expires;
			if(dValue==TIMEQ_FOREVER)
				strTemp+=" ��������";
			else
			{
				strTemp.Format(" %ld��%dСʱ%d�ֺ����",dValue/(24*3600),dValue%(24*3600)/(3600),(dValue%3600)/60);
			}
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			dValue=pTmpUser_3->usri3_last_logon;
			strTemp.Format("�����¼:%ld��%dСʱ%d��",dValue/(24*3600),dValue%(24*3600)/(3600),(dValue%3600)/60);
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			switch(pTmpUser_3->usri3_priv)
			{
			case USER_PRIV_GUEST:strTemp.Format("�û�����:Guest");break;
			case USER_PRIV_USER:strTemp.Format("�û�����:User");break;
			case USER_PRIV_ADMIN:strTemp.Format("�û�����:Administrator");break;
			default:strTemp.Format("�û�����:δ����");break;
			}
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			dValue=pTmpUser_3->usri3_bad_pw_count;
			if (dValue==0)
				strTemp="��¼����:����";
			else
			{
				if (dValue==0xFFFFFFFF)
					strTemp="��¼����:unknown";
				else
					strTemp.Format("��¼����:%ld",dValue);
			}
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			dValue=pTmpUser_3->usri3_num_logons;
			if (dValue==0)
				strTemp="�ɹ�����:��δ�ù�";
			else
			{
				if (dValue==0xFFFFFFFF)
					strTemp="�ɹ�����:unknown";
				else
					strTemp.Format("�ɹ�����:%ld",dValue);
			}
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);
			
			strTemp.Format("�û�����:");
			if (pTmpUser_3->usri3_flags&UF_ACCOUNTDISABLE)
				strTemp+="��ͣ�� ";
			if (pTmpUser_3->usri3_flags&UF_PASSWD_CANT_CHANGE)
				strTemp+="�����޸� ";
			if (pTmpUser_3->usri3_flags&UF_DONT_EXPIRE_PASSWD)
				strTemp+="�������� ";
			if (pTmpUser_3->usri3_flags&UF_PASSWD_NOTREQD)
				strTemp+="�������";
			m_ctlTreeResult.InsertItem(strTemp,4,5,sub);

			pTmpUser_3++;
		}
	}
	if (pUser_3 != NULL)
		NetApiBufferFree(pUser_3);
	
	return TRUE;
}

BOOL CNetBIOSScan::ReadSession(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;
	
	//�Ự========================================
	PSESSION_INFO_10 pSession_10;
	DWORD dwLevel=10; 
	DWORD dwTotalEntries=0;
	DWORD dwResumeHandle=0; 
	DWORD dwTotalCount=0; 
	DWORD dwLength=sizeof(strIP); 
	PTSTR pszClient=NULL; 
	PTSTR pszUser=NULL;
	DWORD dwPrefMaxLen=-1;
	DWORD dwEntriesRead=0;
		
	do 
	{ 
		nStatus=NetSessionEnum((LPWSTR)strIP,
			(LPWSTR)pszClient,
			(LPWSTR)pszUser,
			dwLevel,
			(PBYTE *)&pSession_10,
			MAX_PREFERRED_LENGTH,
			&dwEntriesRead,
			&dwTotalEntries,
			&dwResumeHandle);
		if((nStatus==NERR_Success) || (nStatus==ERROR_MORE_DATA)) 
		{ 
			HTREEITEM curr=m_ctlTreeResult.InsertItem("�Ự",2,3,rtItem);
			PSESSION_INFO_10 pTmpSession_10=pSession_10;
			for (DWORD i=0;i<dwEntriesRead;i++)
			{ 
				if(pTmpSession_10==NULL) 
				{ 
					strTemp="��ȡ�����г��ִ���";
					m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
					break;
				} 
				strTemp.Format("�ͻ��ˣ�%S;�û�����%S;Active:%d;Idle:%d",pTmpSession_10->sesi10_cname,
					pTmpSession_10->sesi10_username,pTmpSession_10->sesi10_time,pTmpSession_10->sesi10_idle_time);
				m_ctlTreeResult.InsertItem(strTemp,4,5,curr);
				
				pSession_10++; 
				dwTotalCount++;
			}//end of for
		}//end if
		if (pSession_10 != NULL) 
		{ 
			NetApiBufferFree(pSession_10); 
		}  
	} while(nStatus==ERROR_MORE_DATA); 
	return TRUE;
}

BOOL CNetBIOSScan::ReadTransport(USHORT *strIP, HTREEITEM rtItem)
{
	NET_API_STATUS nStatus;
	CString strTemp;
	
	//�Ự========================================
	PSERVER_TRANSPORT_INFO_1 pTransport_1;
	DWORD dwLevel=1; 
	DWORD dwTotalEntries=0;
	DWORD dwResumeHandle=0; 
	DWORD dwTotalCount=0;
	DWORD dwEntriesRead=0;
	
	do 
	{ 
		nStatus=NetServerTransportEnum((LPWSTR)strIP,
			dwLevel,
			(PBYTE *)&pTransport_1,
			MAX_PREFERRED_LENGTH,
			&dwEntriesRead,
			&dwTotalEntries,
			&dwResumeHandle);
		if((nStatus==NERR_Success) || (nStatus==ERROR_MORE_DATA)) 
		{ 
			HTREEITEM curr=m_ctlTreeResult.InsertItem("����",2,3,rtItem);
			PSERVER_TRANSPORT_INFO_1 pTmpTransport_1=pTransport_1;
			for (DWORD i=0;i<dwEntriesRead;i++)
			{ 
				strTemp.Format("����:%S;��ַ:%S;����:%d;��ַ:%S;��:%S",pTmpTransport_1->svti1_transportname,
					pTmpTransport_1->svti1_networkaddress,pTmpTransport_1->svti1_numberofvcs,
					pTmpTransport_1->svti1_networkaddress,pTmpTransport_1->svti1_domain);
				m_ctlTreeResult.InsertItem(strTemp,4,5,curr);

				pTransport_1++; 
				dwTotalCount++;
			}//end of for
		}//end if
		if (pTransport_1 != NULL) 
		{ 
			NetApiBufferFree(pTransport_1); 
		}  
	} while(nStatus==ERROR_MORE_DATA); 
	return TRUE;
}
