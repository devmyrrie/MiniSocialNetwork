///-----------------------------------------------------------------
///
/// @file      dos_personas_dialog.cpp
/// @author    user
/// Created:   10/24/2013 12:12:31 PM
/// @section   DESCRIPTION
///            dos_personas_dialog class implementation
///
///------------------------------------------------------------------

#include "dos_personas_dialog.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// dos_personas_dialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(dos_personas_dialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(dos_personas_dialog::OnClose)
	EVT_BUTTON(ID_BTN_OK,dos_personas_dialog::btn_okClick)
END_EVENT_TABLE()
////Event Table End

dos_personas_dialog::dos_personas_dialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    was_closed=false;
	CreateGUIControls();
}

dos_personas_dialog::~dos_personas_dialog()
{
} 

void dos_personas_dialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	btn_ok = new wxButton(this, ID_BTN_OK, _("Ok"), wxPoint(125, 197), wxSize(69, 44), 0, wxDefaultValidator, _("btn_ok"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("2."), wxPoint(32, 159), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("1."), wxPoint(34, 85), wxDefaultSize, 0, _("WxStaticText2"));

	edt_2 = new wxTextCtrl(this, ID_EDT_2, _(""), wxPoint(62, 149), wxSize(200, 28), 0, wxDefaultValidator, _("edt_2"));

	edt_1 = new wxTextCtrl(this, ID_EDT_1, _(""), wxPoint(61, 80), wxSize(201, 28), 0, wxDefaultValidator, _("edt_1"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Ingrese las dos personas: "), wxPoint(76, 41), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, _(""), wxPoint(12, 14), wxSize(283, 273));

	SetTitle(_("Red social"));
	SetIcon(wxNullIcon);
	SetSize(8,8,320,334);
	Center();
	
	////GUI Items Creation End
}

void dos_personas_dialog::OnClose(wxCloseEvent& /*event*/)
{
    was_closed=true;
	Destroy();
}

/*
 * btn_okClick
 */
void dos_personas_dialog::btn_okClick(wxCommandEvent& event)
{
this->EndModal(1);
}
