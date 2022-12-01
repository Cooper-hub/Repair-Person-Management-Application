#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include<stdio.h> //for removing and renaming
using namespace std;

void getrequests(string IDsearch)// fetches requests for certain repairperson based off of ID
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
				cout<<l<<endl;
			}
		}
	}
	finput.close();
}

void dbedittype(string IDsearch, string newtype)//Function to edit the repairperson type
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
	sortandsend();
}

void dbeditfname(string IDsearch, string newfname)//Function to edit the repairperson first name
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
	sortandsend();
}

void dbeditlname(string IDsearch, string newlname)//Function to edit the repairperson last name
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
	sortandsend();
}

void dbeditdistance(string IDsearch, string newdistance)//Function to edit the repairperson distance
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
	sortandsend();
}

void dbeditcost(string IDsearch, string newprice)//Function to edit the repairperson cost
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
	sortandsend();
}


void insertionSort(string array[],string array2[], int size) //insertion sorting the ID based off of rating
{

for (int s = 1; s < size; s++) {
string key = array[s];
string key2 = array2[s];

int i = s - 1;

while (key > array[i] && i >= 0) {	
array[i + 1] = array[i];
array2[i + 1] = array2[i];
--i;
}
array[i + 1] = key;
array2[i + 1] = key2;
}
}


void dbinsertrepairperson(string rat,string ty, string fn, string ln, string pri,string dist, string I )//Inserts repairperson
{
ofstream foutput; 
 ifstream finput;
 finput.open ("rplist.txt");
 foutput.open ("rplist.txt",ios::app); 
 
if(finput.is_open())
foutput<<rat<<" "<<ty<<" "<<fn<<" "<<ln<<" "<<pri<<" "<<dist<<" "<<I<<endl;  
finput.close();
foutput.close(); 
sortandsend();
}



void sortandsend()//sorts and then puts the sorted values into a sorted text file
{
string l,line, temp1,temp2,temp3,temp4,temp5,temp6,temp7;
int line_count = 0;

//counting the number of repair people in the system
ifstream rtext("rplist.txt");
	while (rtext.good()) {
		getline(rtext, l);
		line_count++;
	}
rtext.close();

string rating[line_count];
string type[line_count];
string fname[line_count];
string lname[line_count];
string price[line_count];
string distance[line_count];
string ID[line_count];
string arr[line_count];
string idcheck[line_count];

ifstream rtext2("rplist.txt");
	//splitting up the text into files
	for(int i= 0; i<line_count; i++) {
		getline(rtext2, line); 
rtext2>>rating[i]>>type[i]>>fname[i]>>lname[i]>>price[i]>>distance[i]>>ID[i];
arr[i] = rating[i];
idcheck[i] = ID[i];
	}
rtext2.close();

insertionSort(arr,idcheck,line_count);




ofstream rtext3;
rtext3.open("rplistsorted.txt");
for(int j = 0; j<line_count; j++)
{
	ifstream rtext4;	
	rtext4.open("rplist.txt");
	while(!rtext4.eof())
	{
		rtext4>>temp1>>temp2>>temp3>>temp4>>temp5>>temp6>>temp7;
		if(temp7 == idcheck[j] && rtext4.good())
		{

			rtext3<<" "<<temp1<<" "<<temp2<<" "<<temp3<<" "<<temp4<<" "<<temp5<<" "<<temp6<<" "<<temp7<<endl;
		}
	}
	rtext4.close();
}
rtext3.close();	
}

void dbremoverepairperson(string IDsearch)
{
	string rating, type,  fname,  lname, price, distance, ID;
	ifstream finput;
	finput.open ("rplist.txt");
	ofstream temp1;
	temp1.open("temp.txt");
	temp1<<endl;
	while (finput.good()) {
		finput>>rating>>type>>fname>>lname>>price>>distance>>ID;
		if(ID != IDsearch)
		{
			temp1<<rating<<" "<<type<<" "<<fname<<" "<<lname<<" "<<price<<" "<<distance<<" "<<ID<<endl;
		}	
	}
	finput.close();
temp1.close();

remove("rplist.txt");
rename("temp.txt", "rplist.txt");

}


void clearrequestdb()
{
	string temp1,temp2,temp3,temp4,temp5,temp6,temp7;;

ofstream client;
client.open("rquests.txt");


	ifstream rq;	
	rq.open("rplist.txt");
	while(!rq.eof())
	{
		rq>>temp1>>temp2>>temp3>>temp4>>temp5>>temp6>>temp7;
		if(rq.good())
		{
			client<<temp7<<"\n";
		}
	}
	rq.close();
client.close();
}

void clientrequests(string rpID,string message)
{
string l;
ifstream filein("rquests.txt"); //File to read from
ofstream fileout("temp.txt"); //Temporary file
while(getline (filein,l))
{
fileout<<l<<endl;	
if(l == rpID)
{
	fileout<<message<<endl;
}
}
    
filein.close();
fileout.close();

remove("rquests.txt");
rename("temp.txt","rquests.txt");		
}

int main()
{
	
	
	
    return 0;
}


