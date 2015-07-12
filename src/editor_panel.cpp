#include "editor_panel.hpp"
#include "node/node.hpp"

#include <stdio.h>

#include <wx/sizer.h>
#include <wx/stattext.h>

#include "arg/arg.hpp"
#include "arg/arg_view.hpp"

#include "main_frame.hpp"

class wxInt : public wxObject {
private:

    int m_val;

public:

    wxInt(const int val): m_val(val) {}

    operator int() {return m_val;}

//    friend bool operator==(const wxInt& a, int b);
};

EditorPanel::EditorPanel(wxPanel * parent, MainFrame* mainFrame)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	      wxSize(-1, -1), wxBORDER_SIMPLE), oldButton1(NULL),oldButton2(NULL), m_mainFrame(mainFrame), m_content(NULL){

}



void EditorPanel::ShowNode(Node* node) {

    /*
      Delete the old views.
    */
    if(m_content != NULL) {
	m_content->Clear(true);
    }

    m_currentNode = node;


    wxFlexGridSizer *fgs = new wxFlexGridSizer(node->GetNumArgs(), 2, 9, 25);

    m_content = new wxBoxSizer(wxHORIZONTAL);


    // new we add the new views.
    for(Node::iterator it = node->begin(); it != node->end(); ++it) {
	Arg* arg = *it;

	ArgView* argView = arg->CreateView(this);

	wxStaticText *labelText = new wxStaticText(this, wxID_ANY, arg->GetArgName(), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_VERTICAL);

	fgs->Add(labelText, 0, wxLEFT | wxALIGN_CENTER_VERTICAL);
	fgs->Add(argView, 0, wxLEFT | wxALIGN_CENTER_VERTICAL);

    }

    m_content->Add(fgs, 1, wxALL | wxEXPAND, 15);

    this->SetSizer(m_content);
    this->Layout();
}

void EditorPanel::OnEvent(wxEvent & evt) {
    printf("button down %d!\n", (int) *((wxInt *)evt.GetEventUserData()) );
}

void EditorPanel::OnArgUpdate() {
    m_mainFrame->UpdateNode(m_currentNode->GetIndex());
}
