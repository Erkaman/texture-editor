#include "int_arg_view.hpp"

#include <stdio.h>

#include <wx/sizer.h>
#include <wx/button.h>

IntArgView::IntArgView(wxWindow *parent, IntArg* model): ArgView(parent), m_model(model) {

    printf("create int view\n");

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_minusButton = new wxButton(this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    m_plusButton = new wxButton(this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );

    hbox->Add(m_minusButton, 1, wxALL, 5);
    hbox->Add(m_plusButton, 1, wxALL, 5);
    hbox->SetSizeHints(this);


    this->SetSizer(hbox);

    this->Layout();

}
