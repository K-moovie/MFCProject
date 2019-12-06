
// GAMEDlg.h: 헤더 파일
//

#pragma once
#include "CSelect.h"

// CGAMEDlg 대화 상자
class CGAMEDlg : public CDialogEx
{
// 생성입니다.
public:
	CGAMEDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	static BOOL m_MyType;
	static CString m_ip;

//	CButton m_p1;
//	CButton m_p2;

	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	BOOL start_toggle;
	CSelect *Intro;

	CFont m_font;
	CMFCButton m_p1;
	CMFCButton m_p2;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStatic2();
};
