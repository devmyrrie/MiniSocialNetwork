///-----------------------------------------------------------------
///
/// @file      hobbies_dialog.h
/// @author    user
/// Created:   10/23/2013 12:40:20 PM
/// @section   DESCRIPTION
///            hobbies_dialog class declaration
///
///------------------------------------------------------------------

#ifndef __HOBBIES_DIALOG_H__
#define __HOBBIES_DIALOG_H__

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
#include <wx/statbox.h>
#include <wx/stattext.h>
////Header Include End

////Dialog Style Start
#undef hobbies_dialog_STYLE
#define hobbies_dialog_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class hobbies_dialog : public wxDialog
{
    friend class add_person_dialog;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		hobbies_dialog(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("hobbies_dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = hobbies_dialog_STYLE);
		virtual ~hobbies_dialog();
		void btn_hobbiesOkClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *edt_hobbies4;
		wxTextCtrl *edt_hobbies3;
		wxButton *btn_hobbiesOk;
		wxTextCtrl *edt_hobbies10;
		wxTextCtrl *edt_hobbies9;
		wxTextCtrl *edt_hobbies8;
		wxTextCtrl *edt_hobbies7;
		wxTextCtrl *edt_hobbies6;
		wxStaticBox *box_hobbies2;
		wxTextCtrl *edt_hobbies5;
		wxTextCtrl *edt_hobbies2;
		wxTextCtrl *edt_hobbies1;
		wxStaticBox *box_hobbies;
		wxStaticText *static_hpbboes_txt;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_EDT_HOBBIES4 = 1026,
			ID_EDT_HOBBIES3 = 1025,
			ID_BTN_HOBBIESOK = 1024,
			ID_EDT_HOBBIES10 = 1023,
			ID_EDT_HOBBIES9 = 1022,
			ID_EDT_HOBBIES8 = 1021,
			ID_EDT_HOBBIES7 = 1020,
			ID_EDT_HOBBIES6 = 1019,
			ID_BOX_HOBBIES2 = 1018,
			ID_EDT_HOBBIES5 = 1012,
			ID_EDT_HOBBIES2 = 1009,
			ID_EDT_HOBBIES1 = 1008,
			ID_BOX_HOBBIES = 1002,
			ID_STATIC_HPBBOES_TXT = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
