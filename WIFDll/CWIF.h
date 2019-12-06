#pragma once
#include "resource.h"
#include "CMySocket.h"
// CWIF 대화 상자

class AFX_EXT_CLASS CWIF : public CDialog
{
	DECLARE_DYNAMIC(CWIF)

public:
	CWIF(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CWIF();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	static BOOL isMe;
	CString m_strName;
	static CMySocket m_Csocket;
	static CMySocket m_Ssocket;
	void OnAccept();
	void OnClose();
	void OnConnect();
	void OnReceive();
	void OnSend();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int count1;
	int count2;
	afx_msg void OnPaint();
	static int iSent;
	static int iLen;
	int me;
	int win;
	BOOL isRight;
	static UINT CreateThread(void *lParam);
};
