#include <iostream>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(8000);
	bind(servSock, (sockaddr*)&servAddr, sizeof(servAddr));

	//º‡Ã˝
	listen(servSock, 20);
	//Ω” ‹«Î«Û
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
}