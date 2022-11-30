#pragma once
#include <wx/wx.h>
#include "rperson.h"
#include "hperson.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;


class Main : public wxFrame
{
public:
	Main();
	~Main();


public:
	wxButton *m_btn1 = nullptr; //button for homeowner
	wxButton *m_btn2 = nullptr; //button for repair person
	
	

	void b1click(wxCommandEvent &evt);
	void b2click(wxCommandEvent& evt);
	
	wxPanel* back = nullptr;
	



	wxDECLARE_EVENT_TABLE();

private:
	rperson* m_frame2 = nullptr;//the frame that opens if it is a repairperson
	hperson* m_frame3 = nullptr;//the frame that opens if it is a homeowner
};

