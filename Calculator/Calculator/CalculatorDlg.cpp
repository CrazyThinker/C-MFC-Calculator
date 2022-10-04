
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#include <stack>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CCalculatorDlg 대화 상자



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_Input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_Input);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDOK, &CCalculatorDlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
ON_BN_CLICKED(IDC_BUTTON_N0, &CCalculatorDlg::OnBnClickedButtonN0)
ON_BN_CLICKED(IDC_BUTTON_N1, &CCalculatorDlg::OnBnClickedButtonN1)
ON_BN_CLICKED(IDC_BUTTON_N2, &CCalculatorDlg::OnBnClickedButtonN2)
ON_BN_CLICKED(IDC_BUTTON_N3, &CCalculatorDlg::OnBnClickedButtonN3)
ON_BN_CLICKED(IDC_BUTTON_N4, &CCalculatorDlg::OnBnClickedButtonN4)
ON_BN_CLICKED(IDC_BUTTON_N5, &CCalculatorDlg::OnBnClickedButtonN5)
ON_BN_CLICKED(IDC_BUTTON_N6, &CCalculatorDlg::OnBnClickedButtonN6)
ON_BN_CLICKED(IDC_BUTTON_N7, &CCalculatorDlg::OnBnClickedButtonN7)
ON_BN_CLICKED(IDC_BUTTON_N8, &CCalculatorDlg::OnBnClickedButtonN8)
ON_BN_CLICKED(IDC_BUTTON_N9, &CCalculatorDlg::OnBnClickedButtonN9)
ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
ON_BN_CLICKED(IDC_BUTTON_MULTI, &CCalculatorDlg::OnBnClickedButtonMulti)
ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
ON_BN_CLICKED(IDC_BUTTON_LBRACKET, &CCalculatorDlg::OnBnClickedButtonLbracket)
ON_BN_CLICKED(IDC_BUTTON_RBRACKET, &CCalculatorDlg::OnBnClickedButtonRbracket)
ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CCalculatorDlg::OnBnClickedButtonBackspace)
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CCalculatorDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	CString szText;

	szText.Format(_T("%g"), GetCalculate(m_Input));
	MessageBox(szText, _T("Value"));
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Input = _T("");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("0");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("1");
	UpdateData(FALSE);
}



void CCalculatorDlg::OnBnClickedButtonN2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("2");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("3");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("4");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("5");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("6");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("7");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("8");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonN9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("9");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("+");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("-");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMulti()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("*");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("/");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonLbracket()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T("(");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonRbracket()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Input += _T(")");
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonBackspace()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_Input.GetLength() == 0) return;
	m_Input.SetAt(m_Input.GetLength() - 1, '\0');
	UpdateData(FALSE);
}

int CCalculatorDlg::Rank(int c)
{
	if (c == '(') return 1;
	else if (c == '+' || c == '-') return 2;
	else return 3;
}

double CCalculatorDlg::GetCalculate(CString Input)
{
	int i, j, len, l = 0;
	double d1, d2;
	len = Input.GetLength();
	pair<int, int> Result[1024];

	stack<pair<int, int> > intStack;
	stack<double> doubleStack;

	for (i = 0; i < len; i++)
	{
		if ('0' <= Input[i] && Input[i] <= '9')
		{
			Result[l] = make_pair(0, 0);
			for (j = i; j < len; j++)
			{
				if ('0' > Input[j] || Input[j] > '9') break;
				Result[l].first = Result[l].first * 10 + Input[j] - '0';
			}
			l++;
			i = j - 1;
		}
		else if (Input[i] == ')')
		{
			while (intStack.top().first != '(' || intStack.top().second != 1)
			{
				Result[l++] = intStack.top();
				intStack.pop();
			}
			intStack.pop();
		}
		else
		{
			while (!intStack.empty() && Input[i] != '(' && intStack.top().second==1 && (Rank(Input[i]) <= Rank(intStack.top().first)))
			{
				Result[l++] = intStack.top();
				intStack.pop();
			}
			intStack.push(make_pair(Input[i], 1));
		}
	}

	while (!intStack.empty())
	{
		Result[l++] = intStack.top();
		intStack.pop();
	}

	for (i = 0; i < l; i++)
	{
		if (Result[i].second == 0) doubleStack.push(Result[i].first);
		else
		{
			d2 = doubleStack.top(), doubleStack.pop();
			d1 = doubleStack.top(), doubleStack.pop();
			//op1과 op2가 숫자가 아니라면 표현식의 오류가 됨. 
			switch (Result[i].first)
			{
			case '+':
				doubleStack.push(d1 + d2);
				break;
			case '-':
				doubleStack.push(d1 - d2);
				break;
			case '*':
				doubleStack.push(d1 * d2);
				break;
			case '/':
				doubleStack.push(d1 / d2);
				break;
			}
		}
	}

	return doubleStack.top();
}
