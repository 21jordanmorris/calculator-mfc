#include <string>
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedNine();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEquals();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedClearentry();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedPlusminus();
	afx_msg void OnBnClickedDecimal();
private:
	void AddDigit(char num);
	void ChooseOperator(char oper);
	void DisplayNumber(double num);
	double Calculate(char oper);
	std::string TrimNumber(CString str);

	CFont m_fontButtons;
	CFont m_fontDisplay;
	CFont m_fontHistory;
	CString m_Display;

	CMFCButton m_Zero;
	CMFCButton m_One;
	CMFCButton m_Two;
	CMFCButton m_Three;
	CMFCButton m_Four;
	CMFCButton m_Five;
	CMFCButton m_Six;
	CMFCButton m_Seven;
	CMFCButton m_Eight;
	CMFCButton m_Nine;

	CMFCButton m_PlusMinus;
	CMFCButton m_Decimal;
	CMFCButton m_Plus;
	CMFCButton m_Minus;
	CMFCButton m_Multiply;
	CMFCButton m_Divide;
	CMFCButton m_Equals;
	CMFCButton m_Clear;
	CMFCButton m_ClearEntry;
	CMFCButton m_Backspace;
	CEdit m_DisplayText;

	CString lhs;
	CString rhs;
	CString answerToCString;
	CString holding;
	double answer;
	char oper;
	char prevOper;

	CEdit m_HistoryText;
	CString m_History;

	bool ContainsOperator;
};
