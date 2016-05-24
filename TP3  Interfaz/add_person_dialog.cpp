///-----------------------------------------------------------------
///
/// @file      add_person_dialog.cpp
/// @author    administrador
/// Created:   23/10/2013 10:14:50 a.m.
/// @section   DESCRIPTION
///            add_person_dialog class implementation
///
///------------------------------------------------------------------



//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include "hobbies_dialog.h"
#include "add_person_dialog.h"
//----------------------------------------------------------------------------
// add_person_dialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(add_person_dialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(add_person_dialog::OnClose)
	EVT_ACTIVATE(add_person_dialog::add_person_dialogActivate)
	EVT_DROP_FILES(add_person_dialog::add_person_dialogDropFiles)
	
	EVT_TEXT(ID_EDT_SEXO,add_person_dialog::edt_sexoUpdated)
	EVT_BUTTON(ID_BTN_OK,add_person_dialog::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

add_person_dialog::add_person_dialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    was_closed=false;
	CreateGUIControls();
}

add_person_dialog::~add_person_dialog()
{
} 

void add_person_dialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	edt_hobbies = new wxTextCtrl(this, ID_EDT_HOBBIES, _(""), wxPoint(85, 285), wxSize(240, 22), 0, wxDefaultValidator, _("edt_hobbies"));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Ingrese 10 hobbies, cada hobbie debe ir separado por una coma:"), wxPoint(78, 246), wxDefaultSize, 0, _("WxStaticText5"));

	edt_sexo = new wxTextCtrl(this, ID_EDT_SEXO, _(""), wxPoint(276, 199), wxSize(48, 28), 0, wxDefaultValidator, _("edt_sexo"));

	edt_edad = new wxTextCtrl(this, ID_EDT_EDAD, _(""), wxPoint(150, 203), wxSize(40, 27), 0, wxDefaultValidator, _("edt_edad"));

	edt_nick = new wxTextCtrl(this, ID_EDT_NICK, _(""), wxPoint(144, 151), wxSize(183, 28), 0, wxDefaultValidator, _("edt_nick"));

	edit_nombre = new wxTextCtrl(this, ID_EDIT_NOMBRE, _(""), wxPoint(141, 107), wxSize(188, 26), 0, wxDefaultValidator, _("edit_nombre"));

	btn_ok = new wxButton(this, ID_BTN_OK, _("Ok"), wxPoint(202, 331), wxSize(72, 30), 0, wxDefaultValidator, _("btn_ok"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Sexo:"), wxPoint(235, 205), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Edad:"), wxPoint(79, 204), wxDefaultSize, 0, _("WxStaticText3"));

	Nickname = new wxStaticText(this, ID_NICKNAME, _("Nickname:"), wxPoint(76, 153), wxDefaultSize, 0, _("Nickname"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Nombre:"), wxPoint(78, 104), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Datos de la persona que quiere crear"), wxPoint(77, 61), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, _("Persona"), wxPoint(16, 11), wxSize(434, 397));

	SetTitle(_("add_person_dialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,474,460);
	Center();
	
	////GUI Items Creation End
}

void add_person_dialog::OnClose(wxCloseEvent& /*event*/)
{
    was_closed = true;
	Destroy();
}

/*
 * add_person_dialogActivate
 */
void add_person_dialog::add_person_dialogActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * WxButton1Click
 */
void add_person_dialog::WxButton1Click(wxCommandEvent& event)
{
    
	this->EndModal(1);	
	
	
}

/*
 * edt_sexoUpdated
 */
void add_person_dialog::edt_sexoUpdated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * btn_hobbiesClick
 */


/*
 * add_person_dialogDropFiles
 */
void add_person_dialog::add_person_dialogDropFiles(wxDropFilesEvent& event)
{
	// insert your code here
}
