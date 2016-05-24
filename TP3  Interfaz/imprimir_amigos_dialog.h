///-----------------------------------------------------------------
///
/// @file      imprimir_amigos_dialog.h
/// @author    Joel
/// Created:   23/10/2013 06:46:49 p.m.
/// @section   DESCRIPTION
///            imprimir_amigos_dialog class declaration
///
///------------------------------------------------------------------

#ifndef __IMPRIMIR_AMIGOS_DIALOG_H__
#define __IMPRIMIR_AMIGOS_DIALOG_H__

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
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
////Header Include End

////Dialog Style Start
#undef imprimir_amigos_dialog_STYLE
#define imprimir_amigos_dialog_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class imprimir_amigos_dialog : public wxDialog
{
    friend class Project1Frm;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		imprimir_amigos_dialog(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("imprimir_amigos_dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = imprimir_amigos_dialog_STYLE);
		virtual ~imprimir_amigos_dialog();
		void btn_okClick(wxCommandEvent& event);
		void edt_frUpdated(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText1;
		wxButton *btn_ok;
		wxTextCtrl *edt_fr;
		wxStaticBox *dd;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT1 = 1010,
			ID_BTN_OK = 1009,
			ID_EDT_FR = 1008,
			ID_DD = 1007,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		bool was_closed;
};

#endif
