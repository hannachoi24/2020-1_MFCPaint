﻿
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Figure.h"
#include "2020-1_MFCPaint.h"
#include "ChildView.h"
#include <vector>
#include <string>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// CChildView

/* khlee: window view 의 생성자 */
CChildView::CChildView()
{
}

CChildView::~CChildView()
{
	drawings.clear();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_DRAWCIRCLE, &CChildView::OnDrawcircle)
	ON_UPDATE_COMMAND_UI(ID_DRAWCIRCLE, &CChildView::OnUpdateDrawcircle)
	ON_COMMAND(ID_DRAWLINE, &CChildView::OnDrawline)
	ON_UPDATE_COMMAND_UI(ID_DRAWLINE, &CChildView::OnUpdateDrawline)
	ON_COMMAND(ID_DRAWRECT, &CChildView::OnDrawrect)
	ON_UPDATE_COMMAND_UI(ID_DRAWRECT, &CChildView::OnUpdateDrawrect)
	ON_COMMAND(ID_EDITCOPY, &CChildView::OnEditcopy)
	ON_UPDATE_COMMAND_UI(ID_EDITCOPY, &CChildView::OnUpdateEditcopy)
	ON_COMMAND(ID_EDITCUT, &CChildView::OnEditcut)
	ON_UPDATE_COMMAND_UI(ID_EDITCUT, &CChildView::OnUpdateEditcut)
	ON_COMMAND(ID_EDITDEL, &CChildView::OnEditdel)
	ON_UPDATE_COMMAND_UI(ID_EDITDEL, &CChildView::OnUpdateEditdel)
	ON_COMMAND(ID_EDITDELALL, &CChildView::OnEditdelall)
	ON_UPDATE_COMMAND_UI(ID_EDITDELALL, &CChildView::OnUpdateEditdelall)
	ON_COMMAND(ID_EDITGROUP, &CChildView::OnEditgroup)
	ON_UPDATE_COMMAND_UI(ID_EDITGROUP, &CChildView::OnUpdateEditgroup)
	ON_COMMAND(ID_EDITPASTE, &CChildView::OnEditpaste)
	ON_UPDATE_COMMAND_UI(ID_EDITPASTE, &CChildView::OnUpdateEditpaste)
	ON_COMMAND(ID_EDITUNGROUP, &CChildView::OnEditungroup)
	ON_UPDATE_COMMAND_UI(ID_EDITUNGROUP, &CChildView::OnUpdateEditungroup)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	/* khlee: 도형 그리기 예시 */
	
	/* khlee: 참고용 원 그리기 */
	dc.Ellipse(50, 50, 300, 300);

	/* khlee: 참고용 선 그리기 */
	dc.MoveTo(50, 50);
	dc.LineTo(300, 300);

	/* khlee: 저장해둔 도형들을 모두 그려줌. */
	for (int i = 0; i < drawings.size(); i++)
		drawings[i]->draw(&dc);
	
	// khlee: 그리기나 영역선택등 임의로 영역을 잡을경우 
	// pen과 brush를 다르게 설정 (점선과 투명 영역)
	CPen temp_pen(PS_DASH, 1, RGB(0,0,200));
	CPen* old_pen = dc.SelectObject(&temp_pen);

	int i;
	switch(mode)
	{
	case DRAW_RECT:
		dc.SelectStockObject(HOLLOW_BRUSH);
		if (selecting_region)
			dc.Rectangle(selecting_region->getp1().x, selecting_region->getp1().y, selecting_region->getp2().x, selecting_region->getp2().y);
		break;
	}

	/* khlee: 현재 마우스 포인터의 좌표값 출력 (좌표계에 익숙해지면 삭제하세요) */
	string msg = "Mouse Pose x : " + to_string(current_point.x) + " y: " + to_string(current_point.y);
	CString cmsg(msg.c_str());
	dc.TextOut(0, 0, cmsg);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnDrawcircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateDrawcircle(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnDrawline()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateDrawline(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnDrawrect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/* khlee: 모드를 사각형 그리기 모드로 변경 */
	mode = DRAW_RECT;
}


void CChildView::OnUpdateDrawrect(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnEditcopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditcopy(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	/* Khlee: 버튼 활성화/비활성화 */
	if (drawings.size() > 0)
		pCmdUI->Enable(true);
	else
		pCmdUI->Enable(false);
}


void CChildView::OnEditcut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditcut(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	/* Khlee: 버튼 활성화/비활성화 */
	if (drawings.size() > 0)
		pCmdUI->Enable(true);
	else
		pCmdUI->Enable(false);
}


void CChildView::OnEditdel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditdel(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	/* Khlee: 버튼 활성화/비활성화 */
	if (drawings.size() > 0)
		pCmdUI->Enable(true);
	else
		pCmdUI->Enable(false);
}


void CChildView::OnEditdelall()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditdelall(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.

}


void CChildView::OnEditgroup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditgroup(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnEditpaste()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditpaste(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	/* Khlee: 버튼 활성화/비활성화 */
	if (drawings.size() > 0)
		pCmdUI->Enable(true);
	else
		pCmdUI->Enable(false);
}


void CChildView::OnEditungroup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateEditungroup(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}

/* khlee: 마우스 왼쪽 버튼 누를 때 */
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/* khlee: 마우스 왼쪽 버튼이 눌렸을 때, cursor mode에 따른 여러가지 처리 */
	/* 두번째 parameter인 point에 클릭 당시의 좌표가 넘어옴 */
	/* CChildView 멤버 변수인 starting_point에 현재 point 좌표를 저장: 
	마우스 드래그를 지원하기 위하여 */
	starting_point = point;

	if (mode == DRAW_RECT)
	{
		/* khlee: 선택영역을 표현하기 위한 임시 사각형 모양 생성 */
		
		selecting_region = new Rectangle(starting_point, point);
		/* khlee: 아래 코드를 실행하면 OnPaint()가 바로 실행됨 */
		Invalidate(true);
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}

/* khlee: 마우스 왼쪽 버튼 뗄 때 */
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (mode)
	{
	case DRAW_RECT:
		/* 현재까지 그려진 모양 그대로 도형 (사각형) 을 생성해서, 내부 벡터에 저장해줌*/
		drawings.push_back(new Rectangle(selecting_region->getp1(), selecting_region->getp2()));

		/* khlee: 각종 설정을 리셋*/
		delete selecting_region;	/* khlee: 임시 도형 삭제*/
		mode = NORMAL;				/* 마우스 선택 모드를 일반 모드로 변경*/
		Invalidate(true);			/* OnPaint() 호출로 화면 업데이트*/
		break;
	}
	CWnd::OnLButtonUp(nFlags, point);
}

/* khlee: 마우스 이동 중 */
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* dc = GetDC();

	/* Khlee: 마우스 왼쪽 버튼이 눌린 상태로 움직이고 있을 때,
	point는 현재의 마우스 좌표 (이동된) 를 넘겨받음 */
	current_point = point;
	
	if (nFlags & MK_LBUTTON)
	{
		/* khlee: 사각형을 그리기 위한 임시 사각형이 이미 생성되어 있다면,  */
		if (mode == DRAW_RECT && selecting_region)
		{
			selecting_region->setp1(starting_point);
			selecting_region->setp2(point);
			Invalidate(true);
		}	
	}
	
	CWnd::OnMouseMove(nFlags, point);
}

/* khlee: 커서 모양 설정 */
BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/* khlee: 모드에 따른 커서 모양 변경*/
	/* SetCursor(LoadCursor(0, IDC_CROSS)); 의 마지막 매개변수 조절 (IDC_XXXX)
	 * IDC_HAND 손모양
	 * IDC_SIZENS, IDC_SIZENS, IDC_SIZEWE, IDC_SIZENWSW, IDC_SIZENESW 크기조절화살표
	 * IDC_ARROW 화살표 
	 * IDC_CROSS 십자가 
	 */

	switch (mode)
	{
	case DRAW_RECT:
		SetCursor(LoadCursor(0, IDC_CROSS));
		break;
	default:
		SetCursor(LoadCursor(0, IDC_ARROW));
		break;
	}
	return true;

	//return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
