#include "stdafx.h"
#include "CMySocket.h"
#include "CWIF.h"

CMySocket::CMySocket()
{
}


CMySocket::~CMySocket()
{
}

void CMySocket::SetParent(CDialog *pWnd) {
	m_pWnd = pWnd;
}



void CMySocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CWIF*)m_pWnd)->OnAccept();
	//CAsyncSocket::OnAccept(nErrorCode);
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CWIF*)m_pWnd)->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CWIF*)m_pWnd)->OnConnect();
	//CAsyncSocket::OnConnect(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CWIF*)m_pWnd)->OnReceive();
	//CAsyncSocket::OnReceive(nErrorCode);
}


void CMySocket::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0)
		((CWIF*)m_pWnd)->OnSend();
	//CAsyncSocket::OnSend(nErrorCode);
}
