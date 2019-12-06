// CSelect.cpp: 구현 파일
//

#include "stdafx.h"
#include "GAME.h"
#include "CSelect.h"
#include "afxdialogex.h"
#include "GAMEDlg.h"
#include "CWIF.h"
// CSelect 대화 상자

IMPLEMENT_DYNAMIC(CSelect, CDialog)

CSelect::CSelect(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_select, pParent)
{

}

CSelect::~CSelect()
{
}

void CSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GAME1, m_Game1);
	DDX_Control(pDX, IDC_GAME2, m_Game2);
	DDX_Control(pDX, IDC_GAME3, m_Game3);
}


BEGIN_MESSAGE_MAP(CSelect, CDialog)
	ON_BN_CLICKED(IDC_GAME1, &CSelect::OnBnClickedGame1)
	ON_BN_CLICKED(IDC_GAME2, &CSelect::OnBnClickedGame2)
	ON_BN_CLICKED(IDC_GAME3, &CSelect::OnBnClickedGame3)
END_MESSAGE_MAP()


// CSelect 메시지 처리기


BOOL CSelect::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_font.CreateFont(20, 20, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("RixVideoGame Bold"));
	
	m_Game1.SetFont(&m_font, TRUE);
	m_Game1.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	m_Game1.SetTextColor(RGB(255, 255, 255)); //글자색 변경
	m_Game1.SetFaceColor(RGB(0, 0, 0)); //배경색 변경

	m_Game2.SetFont(&m_font, TRUE);
	m_Game2.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	m_Game2.SetTextColor(RGB(255, 255, 255)); //글자색 변경
	m_Game2.SetFaceColor(RGB(0, 0, 0)); //배경색 변경
	
	m_Game3.SetFont(&m_font, TRUE);
	m_Game3.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	m_Game3.SetTextColor(RGB(255, 255, 255)); //글자색 변경
	m_Game3.SetFaceColor(RGB(0, 0, 0)); //배경색 변경
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSelect::OnBnClickedGame1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSelect::OnBnClickedGame2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSelect::OnBnClickedGame3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWIF wif; 
	wif.isMe = CGAMEDlg::m_MyType;
	wif.m_strName = CGAMEDlg::m_ip;
	wif.DoModal();
	int i = wif.win;
	CString str;
	str.Format(_T("%d"), i);
	MessageBox(str);
	if (i != 0) {
		GetDlgItem(IDC_GAME3)->EnableWindow(FALSE);
	}
}
