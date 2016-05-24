///-----------------------------------------------------------------
///
/// @file      hobbies_dialog.cpp
/// @author    user
/// Created:   10/23/2013 12:40:20 PM
/// @section   DESCRIPTION
///            hobbies_dialog class implementation
///
///------------------------------------------------------------------

#include "hobbies_dialog.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// hobbies_dialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(hobbies_dialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(hobbies_dialog::OnClose)
	EVT_BUTTON(ID_BTN_HOBBIESOK,hobbies_dialog::btn_hobbiesOkClick)
END_EVENT_TABLE()
////Event Table End

hobbies_dialog::hobbies_dialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

hobbies_dialog::~hobbies_dialog()
{
} 

void hobbies_dialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	edt_hobbies4 = new wxTextCtrl(this, ID_EDT_HOBBIES4, _(""), wxPoint(43, 220), wxSize(222, 35), 0, wxDefaultValidator, _("edt_hobbies4"));

	edt_hobbies3 = new wxTextCtrl(this, ID_EDT_HOBBIES3, _(""), wxPoint(42, 177), wxSize(227, 31), 0, wxDefaultValidator, _("edt_hobbies3"));

	btn_hobbiesOk = new wxButton(this, ID_BTN_HOBBIESOK, _("Ok"), wxPoint(265, 318), wxSize(124, 45), 0, wxDefaultValidator, _("btn_hobbiesOk"));

	edt_hobbies10 = new wxTextCtrl(this, ID_EDT_HOBBIES10, _(""), wxPoint(382, 258), wxSize(242, 24), 0, wxDefaultValidator, _("edt_hobbies10"));

	edt_hobbies9 = new wxTextCtrl(this, ID_EDT_HOBBIES9, _(""), wxPoint(380, 211), wxSize(244, 31), 0, wxDefaultValidator, _("edt_hobbies9"));

	edt_hobbies8 = new wxTextCtrl(this, ID_EDT_HOBBIES8, _(""), wxPoint(379, 172), wxSize(245, 27), 0, wxDefaultValidator, _("edt_hobbies8"));

	edt_hobbies7 = new wxTextCtrl(this, ID_EDT_HOBBIES7, _(""), wxPoint(380, 134), wxSize(242, 26), 0, wxDefaultValidator, _("edt_hobbies7"));

	edt_hobbies6 = new wxTextCtrl(this, ID_EDT_HOBBIES6, _(""), wxPoint(379, 94), wxSize(241, 27), 0, wxDefaultValidator, _("edt_hobbies6"));

	box_hobbies2 = new wxStaticBox(this, ID_BOX_HOBBIES2, _("box_hobbies2"), wxPoint(366, 71), wxSize(271, 225));

	edt_hobbies5 = new wxTextCtrl(this, ID_EDT_HOBBIES5, _(""), wxPoint(42, 261), wxSize(226, 28), 0, wxDefaultValidator, _("edt_hobbies5"));

	edt_hobbies2 = new wxTextCtrl(this, ID_EDT_HOBBIES2, _(""), wxPoint(40, 137), wxSize(232, 28), 0, wxDefaultValidator, _("edt_hobbies2"));

	edt_hobbies1 = new wxTextCtrl(this, ID_EDT_HOBBIES1, _(""), wxPoint(41, 98), wxSize(231, 25), 0, wxDefaultValidator, _("edt_hobbies1"));

	box_hobbies = new wxStaticBox(this, ID_BOX_HOBBIES, _("box_hobbies"), wxPoint(22, 71), wxSize(261, 227));

	static_hpbboes_txt = new wxStaticText(this, ID_STATIC_HPBBOES_TXT, _("Ingrese los hobbies:"), wxPoint(25, 15), wxDefaultSize, 0, _("static_hpbboes_txt"));
	static_hpbboes_txt->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	SetTitle(_("hobbies_dialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,682,419);
	Center();
	
	////GUI Items Creation End
}

void hobbies_dialog::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * btn_hobbiesOkClick
 */
void hobbies_dialog::btn_hobbiesOkClick(wxCommandEvent& event)
{
	this->EndModal(1);
}
