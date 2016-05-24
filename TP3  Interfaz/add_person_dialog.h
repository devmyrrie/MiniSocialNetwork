///-----------------------------------------------------------------
///
/// @file      add_person_dialog.h
/// @author    administrador
/// Created:   23/10/2013 10:14:50 a.m.
/// @section   DESCRIPTION
///            add_person_dialog class declaration
///
///------------------------------------------------------------------

#ifndef __ADD_PERSON_DIALOG_H__
#define __ADD_PERSON_DIALOG_H__

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
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
////Header Include End

////Dialog Style Start
#undef add_person_dialog_STYLE
#define add_person_dialog_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class add_person_dialog : public wxDialog
{
    friend class Project1Frm;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		add_person_dialog(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("add_person_dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = add_person_dialog_STYLE);
		virtual ~add_person_dialog();
		void add_person_dialogActivate(wxActivateEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void edt_sexoUpdated(wxCommandEvent& event);
		void btn_hobbiesClick(wxCommandEvent& event);
		void add_person_dialogDropFiles(wxDropFilesEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *edt_hobbies;
		wxStaticText *WxStaticText5;
		wxTextCtrl *edt_sexo;
		wxTextCtrl *edt_edad;
		wxTextCtrl *edt_nick;
		wxTextCtrl *edit_nombre;
		wxButton *btn_ok;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *Nickname;
		wxStaticText *WxStaticText2;
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
			ID_EDT_HOBBIES = 1096,
			ID_WXSTATICTEXT5 = 1095,
			ID_EDT_SEXO = 1094,
			ID_EDT_EDAD = 1093,
			ID_EDT_NICK = 1092,
			ID_EDIT_NOMBRE = 1091,
			ID_BTN_OK = 1090,
			ID_WXSTATICTEXT4 = 1089,
			ID_WXSTATICTEXT3 = 1088,
			ID_NICKNAME = 1087,
			ID_WXSTATICTEXT2 = 1086,
			ID_WXSTATICTEXT1 = 1085,
			ID_WXSTATICBOX1 = 1018,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        bool was_closed;
};

#endif
