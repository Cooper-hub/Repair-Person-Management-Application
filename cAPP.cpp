#include "cAPP.h"
wxIMPLEMENT_APP(cAPP);// kind of like defining main

cAPP::cAPP()
{


	

}

cAPP:: ~cAPP()
{

}

bool cAPP::OnInit()
{
	m_frame1 = new Main();
	m_frame1->Show();
	return true;

}