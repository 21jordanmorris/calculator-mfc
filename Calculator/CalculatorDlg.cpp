
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_Display(_T(""))
	, m_History(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_Display);
	DDX_Text(pDX, IDC_HISTORY, m_History);
	DDX_Control(pDX, IDC_ZERO, m_Zero);
	DDX_Control(pDX, IDC_ONE, m_One);
	DDX_Control(pDX, IDC_TWO, m_Two);
	DDX_Control(pDX, IDC_THREE, m_Three);
	DDX_Control(pDX, IDC_FOUR, m_Four);
	DDX_Control(pDX, IDC_FIVE, m_Five);
	DDX_Control(pDX, IDC_SIX, m_Six);
	DDX_Control(pDX, IDC_SEVEN, m_Seven);
	DDX_Control(pDX, IDC_EIGHT, m_Eight);
	DDX_Control(pDX, IDC_NINE, m_Nine);
	DDX_Control(pDX, IDC_PLUSMINUS, m_PlusMinus);
	DDX_Control(pDX, IDC_DECIMAL, m_Decimal);
	DDX_Control(pDX, IDC_PLUS, m_Plus);
	DDX_Control(pDX, IDC_MINUS, m_Minus);
	DDX_Control(pDX, IDC_MULTIPLY, m_Multiply);
	DDX_Control(pDX, IDC_DIVIDE, m_Divide);
	DDX_Control(pDX, IDC_EQUALS, m_Equals);
	DDX_Control(pDX, IDC_CLEAR, m_Clear);
	DDX_Control(pDX, IDC_CLEARENTRY, m_ClearEntry);
	DDX_Control(pDX, IDC_BACKSPACE, m_Backspace);
	DDX_Control(pDX, IDC_DISPLAY, m_DisplayText);
	DDX_Control(pDX, IDC_HISTORY, m_HistoryText);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ZERO, &CCalculatorDlg::OnBnClickedZero)
	ON_BN_CLICKED(IDC_ONE, &CCalculatorDlg::OnBnClickedOne)
	ON_BN_CLICKED(IDC_TWO, &CCalculatorDlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_THREE, &CCalculatorDlg::OnBnClickedThree)
	ON_BN_CLICKED(IDC_FOUR, &CCalculatorDlg::OnBnClickedFour)
	ON_BN_CLICKED(IDC_FIVE, &CCalculatorDlg::OnBnClickedFive)
	ON_BN_CLICKED(IDC_SIX, &CCalculatorDlg::OnBnClickedSix)
	ON_BN_CLICKED(IDC_SEVEN, &CCalculatorDlg::OnBnClickedSeven)
	ON_BN_CLICKED(IDC_EIGHT, &CCalculatorDlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_NINE, &CCalculatorDlg::OnBnClickedNine)
	ON_BN_CLICKED(IDC_PLUS, &CCalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CCalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULTIPLY, &CCalculatorDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_DIVIDE, &CCalculatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_EQUALS, &CCalculatorDlg::OnBnClickedEquals)
	ON_BN_CLICKED(IDC_CLEAR, &CCalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_CLEARENTRY, &CCalculatorDlg::OnBnClickedClearentry)
	ON_BN_CLICKED(IDC_BACKSPACE, &CCalculatorDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_PLUSMINUS, &CCalculatorDlg::OnBnClickedPlusminus)
	ON_BN_CLICKED(IDC_DECIMAL, &CCalculatorDlg::OnBnClickedDecimal)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_fontButtons.CreateFont(32,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,FALSE,FALSE,FALSE,FALSE,_T("Microsoft Sans Serif"));
	
	m_Zero.SetFont(&m_fontButtons);
	m_One.SetFont(&m_fontButtons);
	m_Two.SetFont(&m_fontButtons);
	m_Three.SetFont(&m_fontButtons);
	m_Four.SetFont(&m_fontButtons);
	m_Five.SetFont(&m_fontButtons);
	m_Six.SetFont(&m_fontButtons);
	m_Seven.SetFont(&m_fontButtons);
	m_Eight.SetFont(&m_fontButtons);
	m_Nine.SetFont(&m_fontButtons);

	m_PlusMinus.SetFont(&m_fontButtons);
	m_Decimal.SetFont(&m_fontButtons);
	m_Plus.SetFont(&m_fontButtons);
	m_Minus.SetFont(&m_fontButtons);
	m_Multiply.SetFont(&m_fontButtons);
	m_Divide.SetFont(&m_fontButtons);
	m_Equals.SetFont(&m_fontButtons);
	m_Clear.SetFont(&m_fontButtons);
	m_ClearEntry.SetFont(&m_fontButtons);
	m_Backspace.SetFont(&m_fontButtons);

	m_fontDisplay.CreateFont(112, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, FALSE, FALSE, FALSE, FALSE, _T("Microsoft Sans Serif"));
	m_DisplayText.SetFont(&m_fontDisplay);

	m_fontHistory.CreateFont(24, 0, 0, 0, FW_DEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, FALSE, FALSE, FALSE, FALSE, _T("Microsoft Sans Serif"));
	m_HistoryText.SetFont(&m_fontHistory);


	return TRUE;  // return TRUE  unless you set the focus to a control
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
  First checks if the character limit has yet to be reached and if not, moves on to then checking if the user is or is not
  on the solution stage (where the history display will contain an equals sign). If it is then clicking a numerical button 
  should reset the display.
*/
void CCalculatorDlg::AddDigit(char num)
{
	if (m_Display.GetLength() < 9)
	{
		if (m_History.GetLength() == 0 || m_History.GetAt(m_History.GetLength() - 1) != '=')
		{
			m_Display += num;
		}
		else
		{
			m_Display = num;
			m_History = "";
		}
		UpdateData(FALSE);
	}
}

std::string CCalculatorDlg::TrimNumber(CString str)
{
	std::string strToString = std::to_string(_tstof(str));
	bool stayInLoop = true;
	while (strToString.find('.') != strToString.npos && stayInLoop)
	{
		if (strToString.back() == '0' || strToString.back() == '.')
		{
			strToString.pop_back();
		}
		else
		{
			stayInLoop = false;
		}
	}
	return strToString;
}

/*
  Stores the current number on the display in lhs .and displays that plus the chosen operator in the history display. Also clears
  the display so it is ready for the rhs number.

  TODO: CLEANUP THIS CODE
*/
void CCalculatorDlg::ChooseOperator(char oper)
{
	if (m_Display != "")
	{
		prevOper = this->oper;
		this->oper = oper;

		UpdateData(TRUE);
		if (m_History.Find('=') != -1 || (m_Display != "" && !ContainsOperator))
		{
			lhs = m_Display;
			m_History = lhs + ' ' + oper;
		}
		else
		{
			/* What to do when (num oper num) oper */
			rhs = m_Display;
			lhs = std::to_string(Calculate(prevOper)).c_str();
			CString strTemp(TrimNumber(lhs).c_str());
			m_History = strTemp + ' ' + oper;
		}
		m_Display = "";
	}
	else
	{
		if (m_History.Find('=') == -1 && ContainsOperator)
		{
			this->oper = oper;
			m_History = lhs + ' ' + oper;
		}
	}

	UpdateData(FALSE);
	ContainsOperator = true;
}

/*
  When equals is clicked this will display the number provided while also taking off unnessecary zeros and possibly a decimal place.
*/
void CCalculatorDlg::DisplayNumber(double num)
{
	answerToCString = std::to_string(num).c_str();

	m_Display = TrimNumber(answerToCString).c_str();

	m_History += ' ' + rhs + ' ' + '=';

	UpdateData(FALSE);
}

double CCalculatorDlg::Calculate(char oper)
{
	if (oper == '+')
		return _tstof(lhs) + _tstof(rhs);
	else if (oper == '-')
		return _tstof(lhs) - _tstof(rhs);
	else if (oper == '*')
		return _tstof(lhs) * _tstof(rhs);
	else
	{
		if(_tstof(rhs) != 0)
			return _tstof(lhs) / _tstof(rhs);
		else
		{
			m_History = "";
			m_Display = "";
			UpdateData(FALSE);
		}
	}
}

/*
  Each one calls AddDigit('#');
*/
void CCalculatorDlg::OnBnClickedZero()
{
	AddDigit('0');
}
void CCalculatorDlg::OnBnClickedOne()
{
	AddDigit('1');
}
void CCalculatorDlg::OnBnClickedTwo()
{
	AddDigit('2');
}
void CCalculatorDlg::OnBnClickedThree()
{
	AddDigit('3');
}
void CCalculatorDlg::OnBnClickedFour()
{
	AddDigit('4');
}
void CCalculatorDlg::OnBnClickedFive()
{
	AddDigit('5');
}
void CCalculatorDlg::OnBnClickedSix()
{
	AddDigit('6');
}
void CCalculatorDlg::OnBnClickedSeven()
{
	AddDigit('7');
}
void CCalculatorDlg::OnBnClickedEight()
{
	AddDigit('8');
}
void CCalculatorDlg::OnBnClickedNine()
{
	AddDigit('9');
}
void CCalculatorDlg::OnBnClickedDecimal()
{
	AddDigit('.');
}

/*
  Each one calls ChooseOperator('oper');
*/
void CCalculatorDlg::OnBnClickedPlus()
{
	ChooseOperator('+');
}
void CCalculatorDlg::OnBnClickedMinus()
{
	ChooseOperator('-');
}
void CCalculatorDlg::OnBnClickedMultiply()
{
	ChooseOperator('*');
}
void CCalculatorDlg::OnBnClickedDivide()
{
	ChooseOperator('/');
}

void CCalculatorDlg::OnBnClickedEquals()
{
	UpdateData(TRUE);
	rhs = m_Display;

	DisplayNumber(Calculate(oper));

	ContainsOperator = false;
	oper = ' ';
}

/*
  Clears display and history text along with the lhs,rhs,oper variables
*/
void CCalculatorDlg::OnBnClickedClear()
{
	m_Display = "";
	m_History = "";
	lhs = "";
	rhs = "";
	oper = ' ';
	ContainsOperator = false;
	UpdateData(FALSE);
}

/*
  Clears current number shown on display (unless it is the solution, then it simulates clicking 'C')
*/
void CCalculatorDlg::OnBnClickedClearentry()
{
	m_Display = "";
	if (m_History.GetLength() != 0 && m_History.GetAt(m_History.GetLength() - 1) == '=')
	{
		lhs = "";
		rhs = "";
		m_History = "";
	}
	UpdateData(FALSE);
}

/*
  Removes last number/character shown on the display.
*/
void CCalculatorDlg::OnBnClickedBackspace()
{
	holding = m_Display;
	if (holding.GetLength() != 0)
	{
		holding.Delete(holding.GetLength() - 1);
		m_Display = holding;
		UpdateData(FALSE);
	}
}

/*
  Changes sign of the current number shown on the display.
*/
void CCalculatorDlg::OnBnClickedPlusminus()
{
	holding = m_Display;
	if (holding.Find('-') == 0)
	{
		holding.Delete(0);
		m_Display = holding;
	}
	else
		m_Display = '-' + m_Display;

	UpdateData(FALSE);
}
