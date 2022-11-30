#pragma once
#include <wx/wx.h>
#include <string>
#include <fstream>//for dealing with file handling
#include <stdio.h> //for removing 
#include <cstdio>//for renaming
using namespace std;

class hperson : public wxFrame
{
public:
	hperson();
	~hperson();
   

public:
	//background color
	wxPanel* backscreen = nullptr;//change color when request is sent

	//indicators
	wxPanel* menuconfirm = nullptr;//menu confirm indicator
	wxPanel* doubleclickconfirm = nullptr;//repairperson selection indicator
	wxPanel* buttonconf = nullptr;//send button indicator
	
	wxListBox* m_list2 = nullptr;
	wxComboBox* menu = nullptr;//drop down menu for selecting the type of repair
	
	
	//text descriptions
	wxStaticText* tbox1 = nullptr;//a descriptor textbox for repair people list
	wxStaticText* tbox2 = nullptr;//a prompt to insert personal information	
	wxStaticText* tbox3 = nullptr;//a what information to enter
	wxStaticText* tbox4 = nullptr;//Descriptor for what to put in m_txt2
	wxTextCtrl* m_txt1 = nullptr;//textbox for personal information

	//Buttons
	wxButton* m_btn4 = nullptr;//button for entering personal information
	wxTextCtrl* m_txt2 = nullptr;//textbox for entering repair message
	
	string rpselection;//a spot to hold the repair person selection
	
	//functions
	void clientrequests(string rpID, string message);//enter the customers request into the request database
	void clearrequestdb();//clears the request database
	

	//event functions stuff
	void b3click(wxCommandEvent& evt);
	void typeselect(wxCommandEvent& evt);
	void b4click(wxCommandEvent& evt);
	void rpselected(wxCommandEvent& evt);
	
    wxDECLARE_EVENT_TABLE();
};


