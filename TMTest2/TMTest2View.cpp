
// TMTest2View.cpp : implementation of the CTMTest2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TMTest2.h"
#endif

#include "TMTest2Doc.h"
#include "TMTest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTMTest2View

IMPLEMENT_DYNCREATE(CTMTest2View, CView)

BEGIN_MESSAGE_MAP(CTMTest2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTMTest2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTMTest2View construction/destruction

CTMTest2View::CTMTest2View()
{
	// TODO: add construction code here

}

CTMTest2View::~CTMTest2View()
{
}

BOOL CTMTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTMTest2View drawing

void CTMTest2View::OnDraw(CDC* /*pDC*/)
{
	CTMTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTMTest2View printing


void CTMTest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTMTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTMTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTMTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTMTest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTMTest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTMTest2View diagnostics

#ifdef _DEBUG
void CTMTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CTMTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTMTest2Doc* CTMTest2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTMTest2Doc)));
	return (CTMTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTMTest2View message handlers
