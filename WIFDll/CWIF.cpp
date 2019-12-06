// CWIF.cpp: 구현 파일
//

#include "stdafx.h"
#include "CWIF.h"
#include "afxdialogex.h"



// CWIF 대화 상자
int CWIF::iSent;
int CWIF::iLen;
CMySocket CWIF::m_Csocket;
CMySocket CWIF::m_Ssocket;
BOOL CWIF::isMe;

IMPLEMENT_DYNAMIC(CWIF, CDialog)

CWIF::CWIF(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MAIN, pParent)
{

}

CWIF::~CWIF()
{
}

void CWIF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWIF, CDialog)
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CWIF 메시지 처리기

void CWIF::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CString str;

	if (count1 > 100 || count2 > 100) {
		win = count1 > count2 ? 1 : 2;
		const char * str("end");
		iLen = strlen(str) + 1;
		iSent = m_Csocket.Send(LPCTSTR(str), iLen);
		OnOK();
	}
		
	str.Format(_T("O"));
	dc.TextOutW(count1, 100,str); // 서버의 좌표
	dc.TextOutW(count2, 300, str); // 클라이언트의 좌표
}



BOOL CWIF::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_Csocket.SetParent(this);
	m_Ssocket.SetParent(this);
	count1 = 0;
	count2 = 0;
	isRight = FALSE;
	me = 0;
	win = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CWIF::OnAccept() {
	m_Ssocket.Accept(m_Csocket);
}

void CWIF::OnConnect() {

}

void CWIF::OnClose() {
	m_Csocket.Close();
}

void CWIF::OnSend() {

}

void CWIF::OnReceive() {
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	iRcvd = m_Csocket.Receive(pBuf, iBufSize);
	if (iRcvd == SOCKET_ERROR) {
		MessageBox(_T("receiveError"));
	}

	else {
		pBuf[iRcvd - 1] = NULL;
		if (strcmp(pBuf, "count1") == 0)
		{
			count1 += 20;
			Invalidate(TRUE);
		}
		else if (strcmp(pBuf, "count2") == 0) {
			count2 += 20;
			Invalidate(TRUE);
		}
		else if (strcmp(pBuf, "end") == 0) {
			MessageBox(_T("YOU LOSE!"));
			OnOK();
		}
			
	}

}


void CWIF::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);

	switch (nChar)
	{
	case 'p':
	case 'P':
		count1 = count2 = 0;
		Invalidate(TRUE);
		if (!isMe) { //서버
			m_Ssocket.Create(4000);
			m_Ssocket.Listen();
			break;
		}

		if (isMe) {
			m_Csocket.Create();
			m_Csocket.Connect(m_strName, 4000);
			break;
		}
	}
	if (!isMe) { // 서버
		switch (nChar) {
		case 'a':
		case 'A':
			if (!isRight) {
				me++;
				isRight = TRUE;
				break;
			}
			else break;

		case 'd':
		case'D':
			if (isRight) {
				me++;
				if (me == 10) {
					me = 0;
					count1 += 20;
					Invalidate(TRUE);
					AfxBeginThread(CreateThread, this); // 쓰레드
				}
				isRight = FALSE;
				break;
			}
			else break;
		}
	}

	if (isMe) {  // 클라이언트
		switch (nChar) {
		case 'a':
		case 'A':
			if (!isRight) {
				me++;
				isRight = TRUE;
				break;
			}
			else break;

		case 'd':
		case'D':
			if (isRight) {
				me++;
				if (me == 10) {
					me = 0;
					count2 += 20;
					Invalidate(TRUE);
					AfxBeginThread(CreateThread, this); //쓰레드
				}
				isRight = FALSE;
				break;
			}
			else break;
		}
	}
	


	
}

UINT CWIF::CreateThread(void *lParam) {
	CWIF *pDlg = (CWIF*)lParam;
	const char * str1("count1");
	const char * str2("count2");
	if (!isMe) {
		iLen = strlen(str1) + 1;
		iSent = m_Csocket.Send(LPCTSTR(str1), iLen);
		if (iSent == SOCKET_ERROR) {
			AfxMessageBox(_T("send Error"));
		}
	}
	else if (isMe) {
		iLen = strlen(str2) + 1;
		iSent = m_Csocket.Send(LPCTSTR(str2), iLen);
		if (iSent == SOCKET_ERROR) {
			AfxMessageBox(_T("send Error"));
		}
	}
	return 0;
}
