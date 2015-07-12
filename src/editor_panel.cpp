#include "editor_panel.hpp"
#include "node/node.hpp"

#include <stdio.h>

#include "arg/arg.hpp"

#include "arg/arg_view.hpp"


class wxInt : public wxObject {
private:

    int m_val;

public:

    wxInt(const int val): m_val(val) {}

    operator int() {return m_val;}

//    friend bool operator==(const wxInt& a, int b);
};

EditorPanel::EditorPanel(wxPanel * parent)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
		 wxSize(-1, -1), wxBORDER_SIMPLE), oldButton1(NULL),oldButton2(NULL){

}



void EditorPanel::ShowNode(Node* node) {

    /*
      Delete the old views.
     */

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // new we add the new views.
    for(Node::iterator it = node->begin(); it != node->end(); ++it) {
	Arg* arg = *it;

	ArgView* argView = arg->CreateView(this/*,  wxPoint(20, 20) */);

	vbox->Add(argView, 1, wxALL, 5);
    }

    this->SetSizer(vbox);


/*    static int i = 20;

    if(oldButton1 != NULL) {
//	printf("remove button\n");
	oldButton1->Destroy();
//	oldButton2->Destroy();
    }

    oldButton1 = new wxButton(this, wxID_ANY, wxString::Format(wxT("button %i"),i), wxPoint(20, i));
//    oldButton2 = new wxButton(this, wxID_ANY, wxString::Format(wxT("button %i"),i), wxPoint(70, i));


    Bind(wxEVT_BUTTON, &EditorPanel::OnEvent, this, wxID_ANY,wxID_ANY, new wxInt(i));
//    Bind(wxEVT_BUTTON, &EditorPanel::OnEvent, this, wxID_ANY,wxID_ANY, new wxInt(i+3));


i += 40;*/

//    printf("index. %d\n", node->GetIndex());
}

void EditorPanel::OnEvent(wxEvent & evt) {
    printf("button down %d!\n", (int) *((wxInt *)evt.GetEventUserData()) );
}
