#pragma once
#include "wx/wx.h"
#include <string>
#include <fstream>
//#include <cstdio>//for renaming and removing
const int line_count = 100;//temporary until I can get dynamic array working


using namespace std;


class rperson : public wxFrame
{
public:
	rperson();
	~rperson();
public:
	
	wxPanel* panel = nullptr;//Background color 
	
	
	//Button indicators
	wxPanel* idind = nullptr;//indicator for userID
	wxPanel* typeind = nullptr;//indicator for Type
	wxPanel* fnameind = nullptr;//indicator for First Name
	wxPanel* lnameind = nullptr;//indicator for Last Name
	wxPanel* distanceind = nullptr;//indicator for Distance
	wxPanel* newaccind = nullptr;//indicator for New Account
	wxPanel* newcostind = nullptr;//indicator for New cost
	wxPanel* deleteind = nullptr;//indicator for Deleting account
	wxPanel* resortind = nullptr;//indicator for Resorting
	wxPanel* newratingind = nullptr;//indicator for Adding a new rating
	wxListBox* requestbox = nullptr;//indicator for the request box
	
	
	wxTextCtrl* id_txt = nullptr; //textbox to take the repairpersons ID
	wxComboBox* type_box = nullptr; //drop down menu to select the repairpersons new type
	wxTextCtrl* fname_txt = nullptr;//textbox to take new first name
	wxTextCtrl* lname_txt = nullptr;//textbox to take new last name
	wxTextCtrl* distance_txt = nullptr;//textbox to take the new distance
	wxTextCtrl* cost_txt = nullptr;//textbox to take the new cost



	//used to create new account
	wxTextCtrl* rat = nullptr;//new Rating
	wxTextCtrl* ty = nullptr;//new Type
	wxTextCtrl* fnam = nullptr;//new First name
	wxTextCtrl* lnam = nullptr;//new last name
	wxTextCtrl* cos = nullptr;//new Cost
	wxTextCtrl* dist = nullptr;//new Distance
	wxTextCtrl* I = nullptr;//new ID

	//update rating
	wxTextCtrl* newrat = nullptr;
	wxTextCtrl* IDsearch_ = nullptr;

	wxButton* ubtn = nullptr;//button to send repairperson ID
	wxButton* tbtn = nullptr;//button to send repairperson new type
	wxButton* fbtn = nullptr;//button to send new first name
	wxButton* lbtn = nullptr;//button to send new last name
	wxButton* dbtn = nullptr;//button to send new distance
	wxButton* cobtn = nullptr;//button to send a new cost
	wxButton* cbtn = nullptr;//button to send create account
	wxButton* del = nullptr;//button to delete users account
	wxButton* resortbtn = nullptr;//Button to resort repair people
	wxButton* updaterat = nullptr;//button to update rating


	wxStaticText* tb1 = nullptr;//User ID text
	wxStaticText* tb2 = nullptr;//work Requests
	wxStaticText* tb3 = nullptr;//change repair specialty
	wxStaticText* tb4 = nullptr;//Change first name
	wxStaticText* tb5 = nullptr;//Change last name
	wxStaticText* tb6 = nullptr;//Change distance
	wxStaticText* tb7 = nullptr;//Change distance
	wxStaticText* tb8 = nullptr;//Change rating
	wxStaticText* tb9 = nullptr;//change cost

	//functions
	void insertionSort(string array[], string array2[], int size);//function for sorting repairpeople by their rating
	void dbinsertrepairperson(string rating, string type, string fname, string lname, string price, string distance, string ID);//function for inserting a new repairperson into the system
	void sortandsend();//sorts and inserts the sorted values into a seperate text file
	void dbremoverepairperson(string IDsearch);//removes a repair person from the unsorted database
	void getrequests(string IDsearch);//enters the work requests into the list
	
	void dbedittype(string IDsearch, string newtype);//function to edit the type for repairpeople
	void dbeditfname(string IDsearch, string newfname);//function to edit the first name of repairperson
	void dbeditlname(string IDsearch, string newlname);//function to edit the last name of repairperson
	void dbeditdistance(string IDsearch, string newdistance);//function to edit the distance of repairperson
	void dbeditcost(string IDsearch, string newcost);// function to edit cost

	//event functions
	void ubclick(wxCommandEvent& evt);
	void typeselect(wxCommandEvent& evt);
	void fbclick(wxCommandEvent& evt);
	void lbclick(wxCommandEvent& evt);
	void dbclick(wxCommandEvent& evt);
	void cbclick(wxCommandEvent& evt);
	void cobclick(wxCommandEvent& evt);
	void deletebclick(wxCommandEvent& evt);
	void resortbclick(wxCommandEvent& evt);
	void updateratbclick(wxCommandEvent& evt);
	void selectrequest(wxCommandEvent& evt);

	
	wxDECLARE_EVENT_TABLE();
};

