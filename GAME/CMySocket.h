#pragma once
#include <afxsock.h>
class CMySocket :
	public CAsyncSocket
{
private:
	CDialog* m_pWnd;
public:
	CMySocket();
	~CMySocket();
	void SetParent(CDialog* pWnd);
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};

