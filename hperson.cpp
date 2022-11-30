#include "hperson.h"






using namespace std;
string rpsID;//global variable for the ID of the selected repair person


wxBEGIN_EVENT_TABLE(hperson, wxFrame)
EVT_BUTTON(3, b3click)
EVT_COMBOBOX(4, typeselect) 
EVT_BUTTON(5, b4click)
EVT_LISTBOX_DCLICK(6, rpselected)
wxEND_EVENT_TABLE()

hperson::hperson() :wxFrame(nullptr, wxID_ANY, "Repair Needed Page", wxPoint(480, 30), wxSize(290, 600))
{

	
	menu = new wxComboBox(this, 4, "Type of repair", wxPoint(10, 10), wxSize(130, -1));
	menu->Append(wxT("Air-Conditioner"));
	menu->Append(wxT("Fridge/Freezer"));
	menu->Append(wxT("Stove/Oven"));
	menu->Append(wxT("Microwave"));
	menu->Append(wxT("Sink/Shower/Toilet"));
	menu->Append(wxT("Laundry-Machine"));
	menu->Append(wxT("Dishwasher"));
	
	
	m_list2 = new wxListBox(this, 6, wxPoint(10, 80), wxSize(245, 70));
	
	tbox1 = new wxStaticText(this, wxID_ANY, "Rating | Name | Price($) | Distance(km)", wxPoint(10, 60), wxSize(245, 20));
	tbox2 = new wxStaticText(this, wxID_ANY, "Please enter your information", wxPoint(10, 200), wxSize(245, 20));
	tbox3 = new wxStaticText(this, wxID_ANY, "Name | Email", wxPoint(10, 220), wxSize(245, 20));
	
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 240), wxSize(245, -1));//name and email information textbox
	
	m_btn4 = new wxButton(this, 5, wxT("Send Request"), wxPoint(165, 380), wxSize(90, -1));//button to send everything
	m_txt2 = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(10, 290), wxSize(245, 80));//repair information textbox
	tbox4 = new wxStaticText(this, wxID_ANY, "Enter repair details:", wxPoint(10, 270), wxSize(245, 20));

	backscreen = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(290, 600));
	backscreen->SetBackgroundColour(wxColour(2, 54, 24));
	
	menuconfirm = new wxPanel(this, wxID_ANY, wxPoint(140, 10), wxSize(5, 23));
	menuconfirm->SetBackgroundColour(wxColour(200, 29, 37));
	
	
	doubleclickconfirm = new wxPanel(this, wxID_ANY, wxPoint(255, 60), wxSize(5, 90));
	doubleclickconfirm->SetBackgroundColour(wxColour(200, 29, 37));

	buttonconf = new wxPanel(this, wxID_ANY, wxPoint(255, 200), wxSize(5, 203));
	buttonconf->SetBackgroundColour(wxColour(200, 29, 37));
}

hperson ::~hperson()
{

}

void hperson::b3click(wxCommandEvent& evt)
{
	
}



void hperson::typeselect(wxCommandEvent& evt)
{
	string temp1, temp2, temp3, temp4, temp5, temp6, temp7;

//inserting values into the table of potential repair people
	ifstream rtext4("rplistsorted.txt");
	while (!rtext4.eof())
	{
		rtext4 >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >>temp7;
		if (temp2 == menu->GetValue())
		{
			m_list2->AppendString(" " + temp1 + " " + temp3 + " " + temp4 + " " + temp5 + " " + temp6);
		}
	}
	rtext4.close();
	menuconfirm->SetBackgroundColour(wxColor(*wxGREEN));
	menuconfirm->Refresh();
	menuconfirm->Update();
}

void hperson::rpselected(wxCommandEvent& evt)
{
	int index = menu->GetSelection();
	int j = 0;
	string temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	ifstream rtext4("rplistsorted.txt");
	while (!rtext4.eof())
	{
		rtext4 >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> temp7;
		if (temp2 == menu->GetValue())
		{
			j++;
			if (j == index)
			{
				rpsID = temp7;
			}
		}
	}
	rtext4.close();

	doubleclickconfirm->SetBackgroundColour(wxColor(*wxGREEN));
	doubleclickconfirm->Refresh();
	doubleclickconfirm->Update();
}

void hperson::b4click(wxCommandEvent& evt)
{
	string m =m_txt2->GetValue().ToStdString();
	string n = m_txt1->GetValue().ToStdString();
	string combined = n + " " +m;

	clientrequests(rpsID, combined);
	buttonconf->SetBackgroundColour(wxColor(*wxGREEN));
	buttonconf->Refresh();
	buttonconf->Update();
}

void hperson::clientrequests(string rpID, string message)
{
	string l;
	ifstream filein("rquests.txt"); //File to read from
	ofstream fileout("temp.txt"); //Temporary file
	while (getline(filein, l))
	{
		fileout << l << endl;
		if (l == rpID)
		{
			fileout << message << endl;
		}
	}

	filein.close();
	fileout.close();

	remove("rquests.txt");
	int value = rename("temp.txt", "rquests.txt");
}

void hperson::clearrequestdb()
{
	string temp1, temp2, temp3, temp4, temp5, temp6, temp7;;

	ofstream client;
	client.open("rquests.txt");


	ifstream rq;
	rq.open("rplist.txt");
	while (!rq.eof())
	{
		rq >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> temp7;
		if (rq.good())
		{
			client << temp7 << "\n";
		}
	}
	rq.close();
	client.close();
}