
// TMTest2View.h : interface of the CTMTest2View class
//

#pragma once


class CTMTest2View : public CView
{
protected: // create from serialization only
	CTMTest2View();
	DECLARE_DYNCREATE(CTMTest2View)

// Attributes
public:
	CTMTest2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTMTest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TMTest2View.cpp
inline CTMTest2Doc* CTMTest2View::GetDocument() const
   { return reinterpret_cast<CTMTest2Doc*>(m_pDocument); }
#endif

