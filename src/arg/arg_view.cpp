#include "arg_view.hpp"

#include "editor_panel.hpp"

ArgView::ArgView(EditorPanel *parent):
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize , wxBORDER_NONE), m_parent(parent){

}

void ArgView::OnArgUpdate() {
    m_parent->OnArgUpdate();
}
