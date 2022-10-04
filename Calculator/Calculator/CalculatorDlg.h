
// CalculatorDlg.h: 헤더 파일
//

#pragma once


// CCalculatorDlg 대화 상자
class CCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
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
	afx_msg void OnBnClickedOk();
	CString m_Input;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonN0();
	afx_msg void OnBnClickedButtonN1();
	afx_msg void OnBnClickedButtonN2();
	afx_msg void OnBnClickedButtonN3();
	afx_msg void OnBnClickedButtonN4();
	afx_msg void OnBnClickedButtonN5();
	afx_msg void OnBnClickedButtonN6();
	afx_msg void OnBnClickedButtonN7();
	afx_msg void OnBnClickedButtonN8();
	afx_msg void OnBnClickedButtonN9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonLbracket();
	afx_msg void OnBnClickedButtonRbracket();
	afx_msg void OnBnClickedButtonBackspace();
	double GetCalculate(CString Input);
	int Rank(int c);
};
