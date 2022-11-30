#include "cMain.h"


wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(1,b1click)
EVT_BUTTON(2, b2click)
wxEND_EVENT_TABLE()



Main::Main() :wxFrame(nullptr, wxID_ANY, "Repair IT", wxPoint(30,30), wxSize(800,600))
{
	m_btn1 = new wxButton(this, 1, wxT("You are a repairperson"), wxPoint(100, 50), wxSize(150, 150));
	m_btn2 = new wxButton(this, 2, wxT("You need repairs"), wxPoint(550, 50), wxSize(150, 150));
	back = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(800, 600));
	back->SetBackgroundColour(wxColour(34, 43, 48));
}

Main ::~Main()
{

}

void Main::b1click(wxCommandEvent& evt)
{
	m_frame2 = new rperson();
	m_frame2->Show();
}

void Main::b2click(wxCommandEvent& evt) 
{
	m_frame3 = new hperson();
	m_frame3->Show();
}




