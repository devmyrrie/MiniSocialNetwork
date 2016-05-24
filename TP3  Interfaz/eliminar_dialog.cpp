///-----------------------------------------------------------------
///
/// @file      eliminar_dialog.cpp
/// @author    user
/// Created:   10/23/2013 3:24:38 PM
/// @section   DESCRIPTION
///            eliminar_dialog class implementation
///
///------------------------------------------------------------------

#include "eliminar_dialog.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// eliminar_dialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(eliminar_dialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(eliminar_dialog::OnClose)
	EVT_BUTTON(ID_BTN_ELIMINAROK,eliminar_dialog::btn_eliminarOkClick)
END_EVENT_TABLE()
////Event Table End

eliminar_dialog::eliminar_dialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    was_closed = false;
	CreateGUIControls();
}

eliminar_dialog::~eliminar_dialog()
{
} 

void eliminar_dialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	btn_eliminarOk = new wxButton(this, ID_BTN_ELIMINAROK, _("Ok"), wxPoint(95, 111), wxSize(86, 40), 0, wxDefaultValidator, _("btn_eliminarOk"));

	edt_eliminar = new wxTextCtrl(this, ID_EDT_ELIMINAR, _(""), wxPoint(47, 75), wxSize(191, 26), 0, wxDefaultValidator, _("edt_eliminar"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Ingrese el nickname de la persona :"), wxPoint(51, 42), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, _(" "), wxPoint(11, 13), wxSize(263, 191));

	SetTitle(_("New Dialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,305,255);
	Center();
	
	////GUI Items Creation End
}

void eliminar_dialog::OnClose(wxCloseEvent& /*event*/)
{
    was_closed = true;
	Destroy();
}

/*
 * btn_eliminarOkClick
 */
void eliminar_dialog::btn_eliminarOkClick(wxCommandEvent& event)
{
	this->EndModal(1);
}
