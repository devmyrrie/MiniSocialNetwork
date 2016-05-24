///-----------------------------------------------------------------
///
/// @file      Project1Frm.h
/// @author    Joel
/// Created:   22/10/2013 08:25:16 p.m.
/// @section   DESCRIPTION
///            Project1Frm class declaration
///
///------------------------------------------------------------------

#ifndef __PROJECT1FRM_H__
#define __PROJECT1FRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/notebook.h>
////Header Include End
#include "graph.h"
#include "add_person_dialog.h"
#include "eliminar_dialog.h"
#include "imprimir_amigos_dialog.h"
#include "dos_personas_dialog.h"
////Dialog Style Start
#undef Project1Frm_STYLE
#define Project1Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Project1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
        bool ya_guardo;
        string hobbies[10];
        string string_auxiliar;
		Project1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Project1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Project1Frm_STYLE);
		virtual ~Project1Frm();
		void WxEdit1Updated(wxCommandEvent& event);
		void WxNotebook1PageChanged(wxNotebookEvent& event);
		void WxNotebook1PageChanged0(wxNotebookEvent& event);
		void WxNoteBookPage1UpdateUI(wxUpdateUIEvent& event);
		void Project1FrmActivate(wxActivateEvent& event);
		void WxListBox1Selected(wxCommandEvent& event);
		void btn_3Click(wxCommandEvent& event);
		void Project1FrmActivate0(wxActivateEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void btn_1Click(wxCommandEvent& event);
		void btn_2Click(wxCommandEvent& event);
		void btn_4Click(wxCommandEvent& event);
		void btn_5Click(wxCommandEvent& event);
		void btn_6Click(wxCommandEvent& event);
		void btn_7Click(wxCommandEvent& event);
		void btn_8Click(wxCommandEvent& event);
		void btn_10Click(wxCommandEvent& event);
		void btn_11Click(wxCommandEvent& event);
		void btn_12Click(wxCommandEvent& event);
		void btn_guardarClick(wxCommandEvent& event);
		void btn_9Click(wxCommandEvent& event);
		void WxToolButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText1;
		wxButton *btn_9;
		wxButton *btn_11;
		wxButton *btn_12;
		wxButton *WxButton4;
		wxButton *btn_10;
		wxButton *btn_8;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxButton *btn_7;
		wxStaticText *WxStaticText9;
		wxPanel *WxNoteBookPage2;
		wxButton *btn_guardar;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxButton *btn_5;
		wxButton *btn_4;
		wxButton *btn_3;
		wxButton *btn_2;
		wxButton *btn_1;
		wxPanel *WxNoteBookPage1;
		wxNotebook *ntbk;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT1 = 1009,
			ID_BTN_9 = 1042,
			ID_BTN_11 = 1040,
			ID_BTN_12 = 1039,
			ID_WXBUTTON4 = 1038,
			ID_BTN_10 = 1037,
			ID_BTN_8 = 1035,
			ID_WXSTATICTEXT15 = 1034,
			ID_WXSTATICTEXT14 = 1033,
			ID_WXSTATICTEXT13 = 1032,
			ID_WXSTATICTEXT12 = 1031,
			ID_WXSTATICTEXT11 = 1030,
			ID_WXSTATICTEXT10 = 1028,
			ID_BTN_7 = 1027,
			ID_WXSTATICTEXT9 = 1026,
			ID_WXNOTEBOOKPAGE2 = 1006,
			ID_BTN_GUARDAR = 1041,
			ID_WXSTATICTEXT7 = 1023,
			ID_WXSTATICTEXT6 = 1022,
			ID_WXSTATICTEXT5 = 1021,
			ID_WXSTATICTEXT4 = 1020,
			ID_WXSTATICTEXT3 = 1019,
			ID_WXSTATICTEXT2 = 1018,
			ID_BTN_5 = 1012,
			ID_BTN_4 = 1011,
			ID_BTN_3 = 1010,
			ID_BTN_2 = 1008,
			ID_BTN_1 = 1007,
			ID_WXNOTEBOOKPAGE1 = 1005,
			ID_NTBK = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		graph<person> data;
};

#endif
