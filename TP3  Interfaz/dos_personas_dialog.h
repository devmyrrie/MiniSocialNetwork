///-----------------------------------------------------------------
///
/// @file      dos_personas_dialog.h
/// @author    user
/// Created:   10/24/2013 12:12:31 PM
/// @section   DESCRIPTION
///            dos_personas_dialog class declaration
///
///------------------------------------------------------------------

#ifndef __DOS_PERSONAS_DIALOG_H__
#define __DOS_PERSONAS_DIALOG_H__

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
#undef dos_personas_dialog_STYLE
#define dos_personas_dialog_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class dos_personas_dialog : public wxDialog
{
    friend class Project1Frm;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		dos_personas_dialog(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("dos_personas_dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = dos_personas_dialog_STYLE);
		virtual ~dos_personas_dialog();
		void btn_okClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *btn_ok;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxTextCtrl *edt_2;
		wxTextCtrl *edt_1;
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
			ID_BTN_OK = 1028,
			ID_WXSTATICTEXT3 = 1027,
			ID_WXSTATICTEXT2 = 1026,
			ID_EDT_2 = 1025,
			ID_EDT_1 = 1024,
			ID_WXSTATICTEXT1 = 1023,
			ID_WXSTATICBOX1 = 1007,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		bool was_closed;
};

#endif
