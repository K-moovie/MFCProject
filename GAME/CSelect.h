#pragma once


// CSelect 대화 상자

class CSelect : public CDialog
{
	DECLARE_DYNAMIC(CSelect)

public:
	CSelect(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelect();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_select };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_Game1;
	CMFCButton m_Game2;
	CMFCButton m_Game3;
	CFont m_font;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedGame1();
	afx_msg void OnBnClickedGame2();
	afx_msg void OnBnClickedGame3();
};
