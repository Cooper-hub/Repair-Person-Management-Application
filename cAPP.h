#pragma once


#include "wx/wx.h"
#include "cMain.h"

class cAPP :public wxApp
{
public:
	cAPP();
	~cAPP();

private: 
	Main *m_frame1 = nullptr;//the main opening page
	
	

public:
	virtual bool OnInit();//function that happens on initiation
};



