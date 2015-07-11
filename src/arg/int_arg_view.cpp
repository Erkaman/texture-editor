#include "int_arg_view.hpp"

#include <stdio.h>

IntArgView::IntArgView(wxWindow *parent, const wxPoint& pos, IntArg* model): ArgView(parent, pos), m_model(model) {

    printf("create int view\n");

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_minusButton = new wxButton(this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    m_plusButton = new wxButton(this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );

    hbox->Add(m_minusButton, 1, wxALL, 5);
    hbox->Add(m_plusButton, 1, wxALL, 5);
    hbox->SetSizeHints(this);


    this->SetSizer(hbox);

}
