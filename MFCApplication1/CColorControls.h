﻿#pragma once
#include "afxdialogex.h"
#include "afxcolordialog.h"
#include "windows.h"

#include "opencv2/opencv.hpp"
using namespace cv;

// CColorControls 대화 상자

class CColorControls : public CDialogEx
{
	DECLARE_DYNAMIC(CColorControls)

public:
	CColorControls();   // 표준 생성자입니다.
	CColorControls(Mat Img, BITMAPINFO* bitmapInfo);
	virtual ~CColorControls();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLOR_CONYROLS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV 지원입니다.		
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog(); //다이얼로그가 생성될 때 호출되는 초기화

	Mat myImg; // 이미지 정보를 담고 있는 객체.
	BITMAPINFO* myBitmapInfo; // Bitmap 정보를 담고 있는 구조체.	
	CStatic m_imageControl;

	void DrawImage(Mat requestImg, BITMAPINFO* requestBmpInfo);
	void CreateBitmapInfo(BITMAPINFO** newInfo, int w, int h, int bpp);

	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
		
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBack();

	//afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	CMFCColorButton m_mfcColorBtn;
	CStatic m_staticColor;
	CBrush m_brushColor;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedMfccolorbuttonColor();

	CSliderCtrl m_slider_h;
	afx_msg void OnNMCustomdrawSliderH(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_slider_edit_h;
	CEdit m_color_edit;
};
