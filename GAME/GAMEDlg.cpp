
// GAMEDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "GAME.h"
#include "GAMEDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL CGAMEDlg::m_MyType;
CString CGAMEDlg::m_ip;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGAMEDlg 대화 상자



CGAMEDlg::CGAMEDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGAMEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON3, m_p1);
	//  DDX_Control(pDX, IDC_BUTTON2, m_p2);
	DDX_Text(pDX, IDC_EDIT1, m_ip);
	DDX_Control(pDX, IDC_BUTTON3, m_p1);
	DDX_Control(pDX, IDC_BUTTON2, m_p2);
}

BEGIN_MESSAGE_MAP(CGAMEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CGAMEDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CGAMEDlg::OnBnClickedButton2)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC2, &CGAMEDlg::OnStnClickedStatic2)
END_MESSAGE_MAP()


// CGAMEDlg 메시지 처리기

BOOL CGAMEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_font.CreateFont(50, 50, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("RixVideoGame Bold"));
	// 폰트
	Intro = new CSelect;
	Intro ->Create(IDD_select);
	// 인트로 화면 구현

	GetDlgItem(IDC_STATIC2)->SetFont(&m_font);
	start_toggle = FALSE;
	SetTimer(1, 500, NULL);

	SetBackgroundColor(RGB(0, 0, 0));


	m_p1.SetFont(&m_font, TRUE);
	m_p1.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	m_p1.SetTextColor(RGB(255, 0, 0)); //글자색 변경
	m_p1.SetFaceColor(RGB(0, 0, 0)); //배경색 변경
	

	m_p2.SetFont(&m_font, TRUE);
	m_p2.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	m_p2.SetTextColor(RGB(0, 255, 0)); //글자색 변경
	m_p2.SetFaceColor(RGB(0, 0, 0)); //배경색 변경
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGAMEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGAMEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGAMEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGAMEDlg::OnBnClickedButton3() // 1P
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_MyType = false;
}


void CGAMEDlg::OnBnClickedButton2() // 2P
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_MyType = true;
}


HBRUSH CGAMEDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (pWnd->GetDlgCtrlID() == IDC_STATIC)
	{
		pDC->SetTextColor(RGB(255, 255, 255));
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC2)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

void CGAMEDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);
	switch (nIDEvent) {
	case 1:
		start_toggle = !start_toggle;
		if (start_toggle)
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		else
			GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		break;
	}
}


void CGAMEDlg::OnStnClickedStatic2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Intro->ShowWindow(SW_SHOW);
	ShowWindow(SW_HIDE);
}
