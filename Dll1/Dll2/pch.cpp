// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#undef UNICODE

#define WIN32_LEAN_AND_MEAN




// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
using namespace std;

int test()
{
 
	cout << "-----------服务器-----------" << endl;

	//	1	初始化
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);	//make word,你把鼠标移到WSAStartup看看参数列表,是不是就是一个word啊


	//	2	创建服务器的套接字
	SOCKET serviceSocket;
	serviceSocket = socket(AF_INET, SOCK_STREAM, 0);	//socket(协议族,socket数据传输方式,某个协议)	我们默认为0,其实就是一个宏
	if (SOCKET_ERROR == serviceSocket) {
		cout << "套接字闯创建失败!" << endl;
	}
	else {
		cout << "套接字创建成功!" << endl;
	}


	//	3	绑定套接字	指定绑定的IP地址和端口号
	sockaddr_in socketAddr;								//一个绑定地址:有IP地址,有端口号,有协议族
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");		//代码开头第一行我们定义的宏在这就其作用啦
	socketAddr.sin_port = htons(1234);
	int bRes = bind(serviceSocket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));	//绑定注意的一点就是记得强制类型转换
	if (SOCKET_ERROR == bRes) {
		cout << "绑定失败!" << endl;
	}
	else {
		cout << "绑定成功!" << endl;
	}

	//	4	服务器监听	
	int lLen = listen(serviceSocket, 5);	//监听的第二个参数就是:能存放多少个客户端请求,到并发编程的时候很有用哦
	if (SOCKET_ERROR == lLen) {
		cout << "监听失败!" << endl;
	}
	else {
		cout << "监听成功!" << endl;
	}


	//	5	接受请求
	sockaddr_in revClientAddr;
	SOCKET recvClientSocket = INVALID_SOCKET;	//初始化一个接受的客户端socket
	int _revSize = sizeof(sockaddr_in);
	recvClientSocket = accept(serviceSocket, (SOCKADDR*)&revClientAddr, &_revSize);
	if (INVALID_SOCKET == recvClientSocket) {
		cout << "服务端接受请求失败!" << endl;
	}
	else {
		cout << "服务端接受请求成功!" << endl;
	}


	//	6	发送/接受 数据
	char recvBuf[1024] = {};
	int reLen = recv(recvClientSocket, recvBuf, 1024, 0);
	int sLen = send(recvClientSocket, recvBuf, reLen, 0);
	if (SOCKET_ERROR == reLen) {
		cout << "服务端发送数据失败" << endl;
	}
	else {
		cout << "服务器接受到数据:    " << recvBuf << endl << endl;
	}


	//	7	关闭socket
	closesocket(recvClientSocket);
	closesocket(serviceSocket);

	//	8	终止
	WSACleanup();

	cout << "服务器停止" << endl;
	cin.get();
	return 0;
}

