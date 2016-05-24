///-----------------------------------------------------------------
///
/// @file      Project1Frm.cpp
/// @author    Joel
/// Created:   22/10/2013 08:25:16 p.m.
/// @section   DESCRIPTION
///            Project1Frm class implementation
///
///------------------------------------------------------------------

#include "Project1Frm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include "person.h"
//----------------------------------------------------------------------------
// Project1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Project1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Project1Frm::OnClose)
	EVT_ACTIVATE(Project1Frm::Project1FrmActivate0)
	EVT_BUTTON(ID_BTN_9,Project1Frm::btn_9Click)
	EVT_BUTTON(ID_BTN_11,Project1Frm::btn_11Click)
	EVT_BUTTON(ID_BTN_12,Project1Frm::btn_12Click)
	EVT_BUTTON(ID_BTN_10,Project1Frm::btn_10Click)
	EVT_BUTTON(ID_BTN_8,Project1Frm::btn_8Click)
	EVT_BUTTON(ID_BTN_7,Project1Frm::btn_7Click)
	EVT_BUTTON(ID_BTN_GUARDAR,Project1Frm::btn_guardarClick)
	EVT_BUTTON(ID_BTN_5,Project1Frm::btn_5Click)
	EVT_BUTTON(ID_BTN_4,Project1Frm::btn_4Click)
	EVT_BUTTON(ID_BTN_3,Project1Frm::btn_3Click)
	EVT_BUTTON(ID_BTN_2,Project1Frm::btn_2Click)
	EVT_BUTTON(ID_BTN_1,Project1Frm::btn_1Click)
	
	EVT_UPDATE_UI(ID_WXNOTEBOOKPAGE1,Project1Frm::WxNoteBookPage1UpdateUI)
	
	EVT_NOTEBOOK_PAGE_CHANGED(ID_NTBK,Project1Frm::WxNotebook1PageChanged0)
END_EVENT_TABLE()
////Event Table End

Project1Frm::Project1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Project1Frm::~Project1Frm()
{
}

void Project1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	ntbk = new wxNotebook(this, ID_NTBK, wxPoint(51, 60), wxSize(399, 300), wxNB_DEFAULT);
	ntbk->SetBackgroundColour(wxColour(78,63,53));

	WxNoteBookPage1 = new wxPanel(ntbk, ID_WXNOTEBOOKPAGE1, wxPoint(4, 26), wxSize(391, 270));
	WxNoteBookPage1->SetBackgroundColour(wxColour(209,203,186));
	ntbk->AddPage(WxNoteBookPage1, _("General"));

	btn_1 = new wxButton(WxNoteBookPage1, ID_BTN_1, _("Ok"), wxPoint(186, 56), wxSize(22, 17), 0, wxDefaultValidator, _("btn_1"));

	btn_2 = new wxButton(WxNoteBookPage1, ID_BTN_2, _("Ok"), wxPoint(186, 86), wxSize(22, 17), 0, wxDefaultValidator, _("btn_2"));

	btn_3 = new wxButton(WxNoteBookPage1, ID_BTN_3, _("Ok"), wxPoint(186, 119), wxSize(22, 17), 0, wxDefaultValidator, _("btn_3"));

	btn_4 = new wxButton(WxNoteBookPage1, ID_BTN_4, _("Ok"), wxPoint(187, 150), wxSize(22, 17), 0, wxDefaultValidator, _("btn_4"));

	btn_5 = new wxButton(WxNoteBookPage1, ID_BTN_5, _("Ok"), wxPoint(187, 178), wxSize(22, 17), 0, wxDefaultValidator, _("btn_5"));

	WxStaticText2 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT2, _("¿Que desea realizar?"), wxPoint(119, 12), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxStaticText3 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT3, _("1. Cargar base de datos"), wxPoint(27, 55), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText4 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT4, _("2. Agregar persona a la red"), wxPoint(27, 86), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText5 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT5, _("3. Eliminar persona de la red"), wxPoint(27, 119), wxDefaultSize, 0, _("WxStaticText5"));

	WxStaticText6 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT6, _("4. Agregar relación"), wxPoint(27, 149), wxDefaultSize, 0, _("WxStaticText6"));

	WxStaticText7 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT7, _("5. Eliminar relación"), wxPoint(28, 177), wxDefaultSize, 0, _("WxStaticText7"));

	btn_guardar = new wxButton(WxNoteBookPage1, ID_BTN_GUARDAR, _("Guardar datos de la red"), wxPoint(232, 117), wxSize(152, 38), 0, wxDefaultValidator, _("btn_guardar"));

	WxNoteBookPage2 = new wxPanel(ntbk, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(391, 270));
	WxNoteBookPage2->SetBackgroundColour(wxColour(209,203,186));
	ntbk->AddPage(WxNoteBookPage2, _("Consultar"));

	WxStaticText9 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT9, _("¿Que desea consultar?"), wxPoint(119, 12), wxDefaultSize, 0, _("WxStaticText9"));
	WxStaticText9->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	btn_7 = new wxButton(WxNoteBookPage2, ID_BTN_7, _("Ok"), wxPoint(297, 57), wxSize(22, 17), 0, wxDefaultValidator, _("btn_7"));

	WxStaticText10 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT10, _("1. Ver los amigos de una persona"), wxPoint(26, 55), wxDefaultSize, 0, _("WxStaticText10"));

	WxStaticText11 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT11, _("2. Verificar persona en la red"), wxPoint(27, 86), wxDefaultSize, 0, _("WxStaticText11"));

	WxStaticText12 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT12, _("3. Ver amigos en común de dos personas"), wxPoint(27, 118), wxDefaultSize, 0, _("WxStaticText12"));

	WxStaticText13 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT13, _("4. Verificar amistad entre dos personas"), wxPoint(27, 149), wxDefaultSize, 0, _("WxStaticText13"));

	WxStaticText14 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT14, _("5. Mostrar personas en la red"), wxPoint(27, 177), wxDefaultSize, 0, _("WxStaticText14"));

	WxStaticText15 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT15, _("6. Ver información de una persona"), wxPoint(28, 213), wxDefaultSize, 0, _("WxStaticText15"));

	btn_8 = new wxButton(WxNoteBookPage2, ID_BTN_8, _("Ok"), wxPoint(299, 85), wxSize(22, 17), 0, wxDefaultValidator, _("btn_8"));

	btn_10 = new wxButton(WxNoteBookPage2, ID_BTN_10, _("Ok"), wxPoint(299, 148), wxSize(22, 17), 0, wxDefaultValidator, _("btn_10"));

	WxButton4 = new wxButton(WxNoteBookPage2, ID_WXBUTTON4, _("WxButton4"), wxPoint(464, 177), wxSize(22, 17), 0, wxDefaultValidator, _("WxButton4"));

	btn_12 = new wxButton(WxNoteBookPage2, ID_BTN_12, _("Ok"), wxPoint(300, 214), wxSize(22, 17), 0, wxDefaultValidator, _("btn_12"));

	btn_11 = new wxButton(WxNoteBookPage2, ID_BTN_11, _("Ok"), wxPoint(300, 178), wxSize(22, 17), 0, wxDefaultValidator, _("btn_11"));

	btn_9 = new wxButton(WxNoteBookPage2, ID_BTN_9, _("Ok"), wxPoint(300, 120), wxSize(22, 18), 0, wxDefaultValidator, _("btn_9"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Red Social"), wxPoint(52, 14), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	SetTitle(_(" "));
	SetIcon(wxNullIcon);
	SetSize(8,8,510,416);
	Center();
	
	////GUI Items Creation End
	ya_guardo =true;
	
	
	
	
	
}

void Project1Frm::OnClose(wxCloseEvent& event)
{
    if ( event.CanVeto() &&  ya_guardo==false)
    {
        if ( wxMessageBox("Vas a cerrar el programa y no has guardado la base de datos!  ¿continuar?",
                          "Please confirm",
                          wxICON_QUESTION | wxYES_NO) != wxYES )
        {
            event.Veto();
           return;
        } 
        
    }
	Destroy();
}

/*
 * WxEdit1Updated
 */
void Project1Frm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxNotebook1PageChanged
 */
void Project1Frm::WxNotebook1PageChanged(wxNotebookEvent& event)
{
	// insert your code here
}

/*
 * WxNotebook1PageChanged0
 */
void Project1Frm::WxNotebook1PageChanged0(wxNotebookEvent& event)
{
	// insert your code here
}

/*
 * WxNoteBookPage1UpdateUI
 */
void Project1Frm::WxNoteBookPage1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
}

/*
 * Project1FrmActivate
 */
void Project1Frm::Project1FrmActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * WxListBox1Selected
 */
void Project1Frm::WxListBox1Selected(wxCommandEvent& event)
{
	// insert your code here
}


/*
 * Project1FrmActivate0
 */
void Project1Frm::Project1FrmActivate0(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * WxButton2Click
 */
void Project1Frm::WxButton2Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * btn_1Click
 */
void Project1Frm::btn_1Click(wxCommandEvent& event)
{
     data.wipe_out();
     ifstream in("data_base.dat",  ios::in);
     int i = 2;
       bool ok =false;
    if(in.is_open())
    {
      
     
        while(!in.eof())
        {
        ok=true;
            if(i%2 ==0) //Si no estamos en el bloque de amigos
            {
                person human;
                in>>(human);                
                (data.add_vertex(human));
                 
            }
            else
            {
                string x = "";//Lo hago solamente para pasar al siguiente bloque de informacion
                getline(in,x);
            }
            ++i;

        }
    }
    in.seekg(0, ios::beg);
   
   if(in.is_open() && ok ==true){
         person human;
        in>>(human);
        while(!in.eof())
        {
            graph<person>::graph_data::iterator iter = data.data.begin();
            graph<person>::graph_data::iterator fin = data.data.end();

            while(iter != fin)
            {
                string friends= "";
                getline(in,friends);
                if( friends!= "*")   //Si si existen amigos
                {
                    char* fr = new char [friends.length() +1];
                    strcpy(fr,friends.c_str());
                    char* ptr = strtok(fr, ",");
                    while(ptr!= NULL)
                    {
                        person dst;
                        dst.set_nickname(ptr);
                        person src=(iter->first);
                        data.add_adjacency(src,dst);
                        ptr=strtok(NULL,",");
                    }
                    delete fr;
                }
                person human;
                in>>(human);
                ++iter;
            }
        }
        wxMessageBox("Se cargaron los datos correctamente", _("Load succesful"));
        
        }else{
             wxMessageBox("No se  cargaron los datos correctamente, talvez no exista el archivo (?)", _("Failed"));
             
            }
        
       ya_guardo=true;
     
}

/*
 * btn_2Click
 */
void Project1Frm::btn_2Click(wxCommandEvent& event)
{
     person x;
     add_person_dialog  temp(this);
     temp.ShowModal();
     if(temp.was_closed != true){
            string_auxiliar = temp.edit_nombre->GetValue();
     x.set_fullname(string_auxiliar);
     
     string_auxiliar = temp.edt_nick->GetValue();
     x.set_nickname(string_auxiliar);
     
       
       wxString wedad=temp.edt_edad->GetValue();
       int edad = wxAtoi(wedad);     
       x.set_age(edad);
       
       string_auxiliar =temp.edt_hobbies->GetValue();
      
        char* fr = new char [10];
        fr[10]='\0';
        strcpy(fr,string_auxiliar.c_str());      
        char* ptr = strtok(fr, ",");
        int i = 0;
        while(ptr!= NULL && i <10)
        {
            
            hobbies[i] = ptr;            
            ptr=strtok(NULL,",");
            ++i;
        }
         x.set_hobbies(hobbies);
        
       string_auxiliar = temp.edt_sexo->GetValue();
        bool sex=true;
        char sex2='f';
        sex2=string_auxiliar[0];
        if(sex2 == 'M' || sex2 == 'm')
        {
            sex=false;
    
        }
        x.set_sex(sex);
        data.add_vertex(x);
    
     ya_guardo=false;
       wxMessageBox("Persona unida a la red!", _("Red"));
            
            }
     
     
    
}
/*
 * btn_3Click
 */
void Project1Frm::btn_3Click(wxCommandEvent& event)
{
        eliminar_dialog temp(this);
        temp.ShowModal();
        
        if(temp.was_closed !=true){
            string_auxiliar = temp.edt_eliminar->GetValue();
        person x;
        x.set_nickname(string_auxiliar);
        data.remove_vertex(x);
         ya_guardo=false;
           wxMessageBox("Persona eliminada", _("Eliminar"));
            
            }
        
}

/*
 * btn_4Click
 */
void Project1Frm::btn_4Click(wxCommandEvent& event)
{
	dos_personas_dialog temp(this);
	temp.ShowModal();
	if(temp.was_closed !=true){
        person x;
    	string_auxiliar = temp.edt_1->GetValue();
    	x.set_nickname(string_auxiliar);
    	
    	person y;
    	string_auxiliar=  temp.edt_2->GetValue();
    	y.set_nickname(string_auxiliar);
    	
    	data.add_adjacency(x,y);	
    	 ya_guardo=false;
    	wxMessageBox("Relación creada", _("Relación"));
        
        }
	
}

/*
 * btn_5Click
 */
void Project1Frm::btn_5Click(wxCommandEvent& event)
{
   dos_personas_dialog temp(this);
   temp.ShowModal();
   
   if(temp.was_closed !=true){
        person x;
    	string_auxiliar = temp.edt_1->GetValue();
    	x.set_nickname(string_auxiliar);
    	
    	person y;
    	string_auxiliar=  temp.edt_2->GetValue();
    	y.set_nickname(string_auxiliar);
    	data.remove_adjacency(x,y);
    	 ya_guardo=false;
     wxMessageBox("Se elimino la relación", _("Saving..."));
        
        }
    


}

/*
 * btn_6Click
 */
void Project1Frm::btn_6Click(wxCommandEvent& event)
{
    

}

/*
 * btn_7Click
 */
void Project1Frm::btn_7Click(wxCommandEvent& event)
{
    imprimir_amigos_dialog temp(this);
	temp.ShowModal();
	
	if(temp.was_closed !=true){
        person x;
    	string_auxiliar = temp.edt_fr->GetValue();
    	x.set_nickname(string_auxiliar);
    	wxString s;
    	s= data.print_friends(x);
    	wxMessageBox(s, _("Los amigos"));
        }
	
}

/*
 * btn_8Click
 */
void Project1Frm::btn_8Click(wxCommandEvent& event)
{
        eliminar_dialog temp(this);//AUNQUE NO ES ELIMINAR, USA LO MISMO, MAS TARDE SE CAMBIARA EL NOMBRE A UNO AMS GENERICOS, COMO "PERSONA"
        temp.ShowModal();
        if(temp.was_closed !=true){
            string_auxiliar = temp.edt_eliminar->GetValue();
            person x;
            x.set_nickname(string_auxiliar);
            wxString s = "No esta en la red";
            if(data.exist_in_net(x)){
                s="Si esta  en la  red";           
                
                }
            wxMessageBox(s, _("¿Esta en al red?"));
            
            }
       
	
}

/*
 * btn_10Click
 */
void Project1Frm::btn_10Click(wxCommandEvent& event)
{
	//verifica amistad
	
	dos_personas_dialog temp(this);
	temp.ShowModal();
	
	if(temp.was_closed !=true){
        	person x;
    	string_auxiliar = temp.edt_1->GetValue();
    	x.set_nickname(string_auxiliar);
    	
    	person y;
    	string_auxiliar=  temp.edt_2->GetValue();
    	y.set_nickname(string_auxiliar);
    	
    	wxString esta = "No son amigos";
    	bool son = false;
    	if(data.are_related(x,y)){
            son=true;
            esta= "Si son amigos";        
            }
    	wxMessageBox(esta, _("¿Son amigos?"));
            }
	

}

/*
 * btn_11Click
 */
void Project1Frm::btn_11Click(wxCommandEvent& event)
{
	 wxString m  =data.print_people_in_net();
    wxMessageBox(m, _("Red social"));
}

/*
 * btn_12Click
 */
void Project1Frm::btn_12Click(wxCommandEvent& event)
{
	    eliminar_dialog temp(this);//AUNQUE NO ES ELIMINAR, USA LO MISMO, MAS TARDE SE CAMBIARA EL NOMBRE A UNO AMS GENERICOS, COMO "PERSONA"
        temp.ShowModal();
         if(temp.was_closed !=true){
            string_auxiliar = temp.edt_eliminar->GetValue();
            person x;
            x.set_nickname(string_auxiliar);
            wxString s;
            s = data.consult(x);
            wxMessageBox(s, _("Info"));
            }
       
	
	
	
}

/*
 * btn_guardarClick
 */
void Project1Frm::btn_guardarClick(wxCommandEvent& event)
{
	
	  if(data.is_empty_() == false)
    {
        ofstream data_base_out("data_base.dat",  ios::out |ios::trunc);
        graph<person>::graph_data::iterator iter1 = data.data.begin();
        graph<person>::graph_data::iterator fin= data.data.end();

        while(iter1!=fin)
        {
            data_base_out<< (iter1->first);
            graph<person>::friends::iterator iter2 = iter1->second.begin();
            graph<person>::friends::iterator fin2=iter1->second.end();


            if(iter2!=fin2)
            {
                while( iter2!=fin2)
                {
                    data_base_out<<iter2->first.get_nickname();
                    ++iter2;
                    if(iter2 != fin2) //++iter2 != fin2
                    {
                        data_base_out<<",";//separa por comas
                    }
                }
            }
            else
            {
                data_base_out<<"*";//Si no tiene amigos pone un asterisco

            }
            ++iter1;
            if( iter1!= fin)
            {
                data_base_out<<endl;
            }
        }
        data_base_out.close();
        ya_guardo=true;
       	wxMessageBox("Se guardo los datos correctamente", _("Saving..."));
    }
    else{
        
        wxMessageBox("No se  guardo los datos , lista vacia", _("Saving..."));
        }

	
}

/*
 * btn_9Click
 */
void Project1Frm::btn_9Click(wxCommandEvent& event)
{
    dos_personas_dialog temp(this);
	temp.ShowModal();
	if(temp.was_closed !=true){
        wxString s;
    	person x;
    	string_auxiliar = temp.edt_1->GetValue();
    	x.set_nickname(string_auxiliar);
    	
    	person y;
    	string_auxiliar=  temp.edt_2->GetValue();
    	y.set_nickname(string_auxiliar);
    	
    	s= data.print_mutual_friends(x,y);
    	wxMessageBox(s, _("Amgos en comun:"));
        
        }
	
	
}

/*
 * WxToolButton1Click
 */
void Project1Frm::WxToolButton1Click(wxCommandEvent& event)
{
	// insert your code here
}
