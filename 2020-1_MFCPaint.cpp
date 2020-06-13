﻿
// 2020-1_MFCPaint.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "2020-1_MFCPaint.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20201MFCPaintApp

BEGIN_MESSAGE_MAP(CMy20201MFCPaintApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMy20201MFCPaintApp::OnAppAbout)
END_MESSAGE_MAP()


// CMy20201MFCPaintApp 생성

CMy20201MFCPaintApp::CMy20201MFCPaintApp() noexcept
{
	// TODO: 아래 애플리케이션 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("My20201MFCPaint.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 유일한 CMy20201MFCPaintApp 개체입니다.

CMy20201MFCPaintApp theApp;


// CMy20201MFCPaintApp 초기화

BOOL CMy20201MFCPaintApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면 AfxInitRichEdit2()가 있어야 합니다.
	// AfxInitRichEdit2();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 애플리케이션 마법사에서 생성된 애플리케이션"));


	// 주 창을 만들기 위해 이 코드에서는 새 프레임 창 개체를
	// 만든 다음 이를 애플리케이션의 주 창 개체로 설정합니다.
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 프레임을 만들어 리소스와 함께 로드합니다.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);





	// 창 하나만 초기화되었으므로 이를 표시하고 업데이트합니다.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CMy20201MFCPaintApp::ExitInstance()
{
	//TODO: 추가한 추가 리소스를 처리합니다.
	return CWinApp::ExitInstance();
}

// CMy20201MFCPaintApp 메시지 처리기


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawcircle();
	afx_msg void OnUpdateDrawcircle(CCmdUI* pCmdUI);
	afx_msg void OnDrawline();
	afx_msg void OnUpdateDrawline(CCmdUI* pCmdUI);
	afx_msg void OnDrawrect();
	afx_msg void OnUpdateDrawrect(CCmdUI* pCmdUI);
	afx_msg void OnEditcopy();
	afx_msg void OnUpdateEditcopy(CCmdUI* pCmdUI);
	afx_msg void OnEditcut();
	afx_msg void OnUpdateEditcut(CCmdUI* pCmdUI);
	afx_msg void OnEditdel();
	afx_msg void OnUpdateEditdel(CCmdUI* pCmdUI);
	afx_msg void OnEditdelall();
	afx_msg void OnUpdateEditdelall(CCmdUI* pCmdUI);
	afx_msg void OnEditgroup();
	afx_msg void OnUpdateEditgroup(CCmdUI* pCmdUI);
	afx_msg void OnEditpaste();
	afx_msg void OnUpdateEditpaste(CCmdUI* pCmdUI);
	afx_msg void OnEditungroup();
	afx_msg void OnUpdateEditungroup(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CMy20201MFCPaintApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMy20201MFCPaintApp 메시지 처리기