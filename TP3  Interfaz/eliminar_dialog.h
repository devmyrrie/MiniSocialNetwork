///-----------------------------------------------------------------
///
/// @file      eliminar_dialog.h
/// @author    user
/// Created:   10/23/2013 3:24:38 PM
/// @section   DESCRIPTION
///            eliminar_dialog class declaration
///
///------------------------------------------------------------------

#ifndef __ELIMINAR_DIALOG_H__
#define __ELIMINAR_DIALOG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
////Header Include End

////Dialog Style Start
#undef eliminar_dialog_STYLE
#define eliminar_dialog_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class eliminar_dialog : public wxDialog
{
    friend class Project1Frm;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		eliminar_dialog(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("eliminar_dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = eliminar_dialog_STYLE);
		virtual ~eliminar_dialog();
		void btn_eliminarOkClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *btn_eliminarOk;
		wxTextCtrl *edt_eliminar;
		wxStaticText *WxStaticText1;
		wxStaticBox *WxStaticBox1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_BTN_ELIMINAROK = 1010,
			ID_EDT_ELIMINAR = 1009,
			ID_WXSTATICTEXT1 = 1008,
			ID_WXSTATICBOX1 = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        bool was_closed;
};

#endif
