///-----------------------------------------------------------------
///
/// @file      imprimir_amigos_dialog.cpp
/// @author    Joel
/// Created:   23/10/2013 06:46:49 p.m.
/// @section   DESCRIPTION
///            imprimir_amigos_dialog class implementation
///
///------------------------------------------------------------------

#include "imprimir_amigos_dialog.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// imprimir_amigos_dialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(imprimir_amigos_dialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(imprimir_amigos_dialog::OnClose)
	EVT_BUTTON(ID_BTN_OK,imprimir_amigos_dialog::btn_okClick)
	
	EVT_TEXT(ID_EDT_FR,imprimir_amigos_dialog::edt_frUpdated)
END_EVENT_TABLE()
////Event Table End

imprimir_amigos_dialog::imprimir_amigos_dialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    was_closed=false;
	CreateGUIControls();
}

imprimir_amigos_dialog::~imprimir_amigos_dialog()
{
} 

void imprimir_amigos_dialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Ingrese el nombre de la persona para ver sus amigos: "), wxPoint(27, 38), wxDefaultSize, 0, _("WxStaticText1"));

	btn_ok = new wxButton(this, ID_BTN_OK, _("Ok"), wxPoint(113, 134), wxSize(60, 39), 0, wxDefaultValidator, _("btn_ok"));

	edt_fr = new wxTextCtrl(this, ID_EDT_FR, _(""), wxPoint(52, 86), wxSize(198, 27), 0, wxDefaultValidator, _("edt_fr"));

	dd = new wxStaticBox(this, ID_DD, _(""), wxPoint(13, 14), wxSize(287, 196));

	SetTitle(_("Amigos"));
	SetIcon(wxNullIcon);
	SetSize(17,8,336,284);
	Center();
	
	////GUI Items Creation End
}

void imprimir_amigos_dialog::OnClose(wxCloseEvent& /*event*/)
{
    was_closed=true;
	Destroy();
}

/*
 * btn_okClick
 */
void imprimir_amigos_dialog::btn_okClick(wxCommandEvent& event)
{
	this->EndModal(1);
}

/*
 * edt_frUpdated
 */
void imprimir_amigos_dialog::edt_frUpdated(wxCommandEvent& event)
{
	// insert your code here
}
