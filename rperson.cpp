#include "rperson.h"
using namespace std;

wxBEGIN_EVENT_TABLE(rperson, wxFrame)
EVT_BUTTON(1, ubclick)

EVT_COMBOBOX(2, typeselect)
EVT_BUTTON(3, fbclick)
EVT_BUTTON(4, lbclick)
EVT_BUTTON(5, dbclick)
EVT_BUTTON(6, cbclick)
EVT_BUTTON(11, cobclick)
EVT_BUTTON(7, deletebclick)
EVT_BUTTON(8, resortbclick)
EVT_BUTTON(9, updateratbclick)
EVT_LISTBOX_DCLICK(10, selectrequest)
wxEND_EVENT_TABLE()

rperson::rperson() :wxFrame(nullptr, wxID_ANY, "Repair Person Page", wxPoint(30, 30), wxSize(607, 600))
{
	tb1 = new wxStaticText(this, wxID_ANY, "User ID", wxPoint(10, 10), wxSize(40, 20));
	id_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 35), wxSize(80, 25));
	ubtn = new wxButton(this, 1, "Enter", wxPoint(95, 35), wxSize(40, 25));
	
	tb2 = new wxStaticText(this, wxID_ANY, "Work Requests", wxPoint(10, 65), wxSize(80, 20));
	requestbox = new wxListBox(this, 10, wxPoint(10, 90), wxSize(570, 90));
	
	tb3 = new wxStaticText(this, wxID_ANY, "Change Repair Person Type", wxPoint(10, 230), wxSize(145, 20));
	type_box = new wxComboBox(this, 2, "Repair Specialty", wxPoint(160, 230), wxSize(130, 20));
	type_box->Append(wxT("Air-Conditioner"));
	type_box->Append(wxT("Fridge/Freezer"));
	type_box->Append(wxT("Stove/Oven"));
	type_box->Append(wxT("Microwave"));
	type_box->Append(wxT("Sink/Shower/Toilet"));
	type_box->Append(wxT("Laundry-Machine"));
	type_box->Append(wxT("Dishwasher"));
	
	tb4 = new wxStaticText(this, wxID_ANY, "Change First Name", wxPoint(10, 255), wxSize(145, 24));
	fname_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(160, 255), wxSize(130, 25));
	fbtn = new wxButton(this, 3, "Enter", wxPoint(295, 255), wxSize(40, 25));


	tb5 = new wxStaticText(this, wxID_ANY, "Change Last Name", wxPoint(10, 285), wxSize(145, 24));
	lname_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(160, 285), wxSize(130, 25));
	lbtn = new wxButton(this, 4, "Enter", wxPoint(295, 285), wxSize(40, 25));
	
	
	tb6 = new wxStaticText(this, wxID_ANY, "Change Distance", wxPoint(10, 315), wxSize(145, 24));
	distance_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(160, 315), wxSize(130, 25));
	dbtn = new wxButton(this, 5, "Enter", wxPoint(295, 315), wxSize(40, 25));

	tb9 = new wxStaticText(this, wxID_ANY, "Change Cost", wxPoint(10, 345), wxSize(145, 24));
	cost_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(160, 345), wxSize(130, 25));
	cobtn = new wxButton(this, 11, "Enter", wxPoint(295, 345), wxSize(40, 25));


	tb7 = new wxStaticText(this, wxID_ANY, "Create New Account [if admin ID!]", wxPoint(10, 400), wxSize(185, 24));
	
	rat = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 430), wxSize(60, 25));
	ty = new wxTextCtrl(this, wxID_ANY, "", wxPoint(75, 430), wxSize(80, 25));
	fnam = new wxTextCtrl(this, wxID_ANY, "", wxPoint(160, 430), wxSize(80, 25));
	lnam = new wxTextCtrl(this, wxID_ANY, "", wxPoint(245, 430), wxSize(80, 25));
	cos = new wxTextCtrl(this, wxID_ANY, "", wxPoint(330, 430), wxSize(80, 25));
	dist = new wxTextCtrl(this, wxID_ANY, "", wxPoint(415, 430), wxSize(80, 25));
	I = new wxTextCtrl(this, wxID_ANY, "", wxPoint(500, 430), wxSize(80, 25));
	
	cbtn = new wxButton(this, 6, "Create", wxPoint(500, 460), wxSize(80, 25));


	del = new wxButton(this, 7, "Delete Account", wxPoint(10, 525), wxSize(100, 25));
	
	resortbtn = new wxButton(this, 8, "Re-sort Account", wxPoint(200, 525), wxSize(100, 25));
	
	tb8 = new wxStaticText(this, wxID_ANY, "Update Rating[if admin ID]: new Rating|ID", wxPoint(10, 495), wxSize(225, 24));
	newrat = new wxTextCtrl(this, wxID_ANY, "", wxPoint(240, 495), wxSize(80, 25));
	IDsearch_ = new wxTextCtrl(this, wxID_ANY, "", wxPoint(325, 495), wxSize(80, 25));
	updaterat = new wxButton(this, 9, "Update", wxPoint(410, 495), wxSize(80, 25));

	panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(800, 600));
	panel->SetBackgroundColour(wxColour(2, 54, 24));

	idind = new wxPanel(this, wxID_ANY, wxPoint(90, 35), wxSize(5, 25));
	idind->SetBackgroundColour(wxColour(200, 29, 37));

	typeind = new wxPanel(this, wxID_ANY, wxPoint(155, 230), wxSize(5, 20));
	typeind->SetBackgroundColour(wxColour(200, 29, 37));

	fnameind = new wxPanel(this, wxID_ANY, wxPoint(155, 255), wxSize(5, 25));
	fnameind->SetBackgroundColour(wxColour(200, 29, 37));

	lnameind = new wxPanel(this, wxID_ANY, wxPoint(155, 285), wxSize(5, 25));
	lnameind->SetBackgroundColour(wxColour(200, 29, 37));

	distanceind = new wxPanel(this, wxID_ANY, wxPoint(155, 315), wxSize(5, 25));
	distanceind->SetBackgroundColour(wxColour(200, 29, 37));

	newaccind = new wxPanel(this, wxID_ANY, wxPoint(495, 430), wxSize(5, 55));
	newaccind->SetBackgroundColour(wxColour(200, 29, 37));
	
	deleteind = new wxPanel(this, wxID_ANY, wxPoint(110, 525), wxSize(5, 25));
	deleteind->SetBackgroundColour(wxColour(200, 29, 37));


	resortind = new wxPanel(this, wxID_ANY, wxPoint(300, 525), wxSize(5, 25));
	resortind->SetBackgroundColour(wxColour(200, 29, 37));


	newratingind = new wxPanel(this, wxID_ANY, wxPoint(405, 495), wxSize(5, 25));
	newratingind->SetBackgroundColour(wxColour(200, 29, 37));

	newcostind = new wxPanel(this, wxID_ANY, wxPoint(155, 345), wxSize(5, 25));
	newcostind->SetBackgroundColour(wxColour(200, 29, 37));
}

rperson ::~rperson()
{

}

void rperson::ubclick(wxCommandEvent& evt)
{
	getrequests(id_txt->GetValue().ToStdString());
	idind->SetBackgroundColour(wxColor(*wxGREEN));
	idind->Refresh();
	idind->Update();
}

void rperson::getrequests(string IDsearch)
{
	string l, comp;
	bool savethese = false;
	int nextrperson = stoi(IDsearch) + 1;
	if (nextrperson < 10)
	{
		comp = "00" + to_string(nextrperson);
	}
	else
		comp = "0" + to_string(nextrperson);
	ifstream finput;
	finput.open("rquests.txt");
	while (getline(finput, l)) {

		if (finput.good())
		{
			if (l == IDsearch)
			{
				savethese = true;
			}
			if (l == comp)
			{
				savethese = false;
			}
			if (savethese == true)
			{
				requestbox->AppendString(l);
			}
		}
	}
	finput.close();
}

void rperson::typeselect(wxCommandEvent& evt)
{
	dbedittype(id_txt->GetValue().ToStdString(), type_box->GetValue().ToStdString());
	typeind->SetBackgroundColour(wxColor(*wxGREEN));
	typeind->Refresh();
	typeind->Update();
}

void rperson::fbclick(wxCommandEvent& evt)
{
	dbeditfname(id_txt->GetValue().ToStdString(), fname_txt->GetValue().ToStdString());
	fnameind->SetBackgroundColour(wxColor(*wxGREEN));
	fnameind->Refresh();
	fnameind->Update();
}

void rperson::lbclick(wxCommandEvent& evt)
{
	dbeditlname(id_txt->GetValue().ToStdString(), lname_txt->GetValue().ToStdString());
	lnameind->SetBackgroundColour(wxColor(*wxGREEN));
	lnameind->Refresh();
	lnameind->Update();
}

void rperson::cobclick(wxCommandEvent& evt)
{
	dbeditcost(id_txt->GetValue().ToStdString(), cost_txt->GetValue().ToStdString());
	newcostind->SetBackgroundColour(wxColor(*wxGREEN));
	newcostind->Refresh();
	newcostind->Update();
}

void rperson::dbclick(wxCommandEvent& evt)
{
	dbeditdistance(id_txt->GetValue().ToStdString(), distance_txt->GetValue().ToStdString());
	distanceind->SetBackgroundColour(wxColor(*wxGREEN));
	distanceind->Refresh();
	distanceind->Update();
}

void rperson::cbclick(wxCommandEvent& evt)
{
	if (id_txt->GetValue().ToStdString() == "111")
	{
		dbinsertrepairperson(rat->GetValue().ToStdString(), ty->GetValue().ToStdString(), fnam->GetValue().ToStdString(), lnam->GetValue().ToStdString(), cos->GetValue().ToStdString(), dist->GetValue().ToStdString(), I->GetValue().ToStdString());
		newaccind->SetBackgroundColour(wxColor(*wxGREEN));
		newaccind->Refresh();
		newaccind->Update();
	}
	else
	newaccind->SetBackgroundColour(wxColor(*wxYELLOW));
	newaccind->Refresh();
	newaccind->Update();
}

void rperson::dbinsertrepairperson(string rat, string ty, string fn, string ln, string pri, string dist, string I)
{
	ofstream foutput;
	ifstream finput;
	finput.open("rplist.txt");
	foutput.open("rplist.txt", ios::app);

	if (finput.is_open())
		foutput << rat << " " << ty << " " << fn << " " << ln << " " << pri << " " << dist << " " << I << endl;
	finput.close();
	foutput.close();
}

void rperson::dbedittype(string IDsearch, string newtype)
{
	string rating, type, fname, lname, price, distance, ID, l;



	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << rating << " " << newtype << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");
}

void rperson::dbeditfname(string IDsearch, string newfname)
{
	string rating, type, fname, lname, price, distance, ID, l;



	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << rating << " " << type << " " << newfname << " " << lname << " " << price << " " << distance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");
}

void rperson::dbeditlname(string IDsearch, string newlname)
{
	string rating, type, fname, lname, price, distance, ID, l;



	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << rating << " " << type << " " << fname << " " << newlname << " " << price << " " << distance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");
}

void rperson::dbeditdistance(string IDsearch, string newdistance)
{
	string rating, type, fname, lname, price, distance, ID, l;



	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << newdistance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");
}

void rperson::dbeditcost(string IDsearch, string newprice)
{
	string rating, type, fname, lname, price, distance, ID,l;
	


	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;
	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << newprice << " " << distance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");
}

void rperson::insertionSort(string array[], string array2[], int size)
{

	for (int s = 1; s < size; s++) {
		string key = array[s];
		string key2 = array2[s];

		int i = s - 1;

		while ((key > array[i]) && (i >= 0)) 
		{
			
			array[i + 1] = array[i];
			array2[i + 1] = array2[i];
			--i;
			
		}
		
		array[i + 1] = key;
		array2[i + 1] = key2;
	}
}

void rperson::dbremoverepairperson(string IDsearch)
{
	string rating, type, fname, lname, price, distance, ID;
	ifstream finput;
	finput.open("rplist.txt");
	ofstream temp1;
	temp1.open("temp.txt");
	temp1 << endl;
	while (finput.good()) {
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;
		if (ID != IDsearch)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");

}


void rperson::sortandsend()
{
	string l, line, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	int line_count = 0;

	//counting the number of repair people in the system

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();

	//using a testing value of 100 until dynamic arrays can be figured out
	string rating[100];
	string type[100];
	string fname[100];
	string lname[100];
	string price[100];
	string distance[100];
	string ID[100];
	string arr[100];
	string idcheck[100];

	//splitting up the text into arrays

	ifstream rtext2("rplist.txt");
	for (int i = 0; i < line_count; i++) {
		getline(rtext2, line);
		rtext2 >> rating[i] >> type[i] >> fname[i] >> lname[i] >> price[i] >> distance[i] >> ID[i];
		arr[i] = rating[i];
		idcheck[i] = ID[i];
	}
	rtext2.close();

	rperson::insertionSort(arr, idcheck, line_count);

	//inserting values into the sorted text file
	ofstream rtext3;
	rtext3.open("rplistsorted.txt");
	for (int j = 0; j < line_count; j++)
	{
		ifstream rtext4;
		rtext4.open("rplist.txt");
		while (!rtext4.eof())
		{
			rtext4 >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> temp7;
			if (temp7 == idcheck[j] && rtext4.good())
			{
				rtext3 << " " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << " " << temp6 << " " << temp7 << endl;
			}
		}
		rtext4.close();
	}
	rtext3.close();

	resortind->SetBackgroundColour(wxColor(*wxGREEN));
	resortind->Refresh();
	resortind->Update();
}

void rperson:: deletebclick(wxCommandEvent& evt)
{
	dbremoverepairperson(id_txt->GetValue().ToStdString());
	deleteind->SetBackgroundColour(wxColor(*wxGREEN));
	deleteind->Refresh();
	deleteind->Update();
}

void rperson::resortbclick(wxCommandEvent& evt)
{
	sortandsend();
	resortind->SetBackgroundColour(wxColor(*wxGREEN));
	resortind->Refresh();
	resortind->Update();
}

void rperson::updateratbclick(wxCommandEvent& evt)
{
	string rating, type, fname, lname, price, distance, ID, IDs, new_rating, l;

	IDs = id_txt->GetValue().ToStdString();
	new_rating = newrat->GetValue().ToStdString();
	string IDse = IDsearch_->GetValue().ToStdString();
	if (IDs == "111")
	{


	int line_count = 0;

	ifstream rtext("rplist.txt");
	while (true)
	{
		getline(rtext, l);
		if (l.length() == 0)
		{
			break;
		}
		line_count++;
		if (line_count > 17)
			break;

	}
	rtext.close();


	ifstream finput;
	finput.open("rplist.txt");

	ofstream temp1;
	temp1.open("temp.txt");

	for (int h = 0; h < line_count; h++)
	{
		finput >> rating >> type >> fname >> lname >> price >> distance >> ID;

		if (ID != IDse)
		{
			temp1 << rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
		}
		else
			temp1 << new_rating << " " << type << " " << fname << " " << lname << " " << price << " " << distance << " " << ID << endl;
	}
	finput.close();
	temp1.close();

	remove("rplist.txt");
	int value = rename("temp.txt", "rplist.txt");


	newratingind->SetBackgroundColour(wxColor(*wxGREEN));
	newratingind->Refresh();
	newratingind->Update();
}
	else
	newratingind->SetBackgroundColour(wxColor(*wxYELLOW));
	newratingind->Refresh();
	newratingind->Update();

	}

void rperson::selectrequest(wxCommandEvent& evt)
{
	string IDsearch, l;
	int linedel, j;
	j = 0;
	bool idhit = false;
	linedel = requestbox->GetSelection()+1;
	IDsearch = id_txt->GetValue().ToStdString();
	//requestbox->AppendString(to_string(linedel));
	
	ifstream finput;
	finput.open("rquests.txt");
	ofstream temp1;
	temp1.open("temp1.txt");

	while (finput.good()) {
		getline(finput, l);
		if (l == IDsearch)
		{
			idhit = true;
		}
		if (idhit == true)
		{
			j++;
		}


		if (j != linedel)

		{
			temp1 << l << endl;
		}
	}
	finput.close();
	temp1.close();

	remove("rquests.txt");
	int value = rename("temp1.txt", "rquests.txt");

}