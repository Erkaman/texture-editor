#include "int_arg_view.hpp"

#include "int_arg.hpp"

#include <stdio.h>

#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>

wxTextValidator GetIntValidator() {
    // make a validator that only accepts integers for the text control.
    wxTextValidator validator(wxFILTER_INCLUDE_CHAR_LIST);
    wxArrayString list;


    wxString valid_chars(wxT(" 0123456789-"));
    size_t len = valid_chars.Length();

    for (size_t i=0; i<len; i++)
	list.Add(wxString(valid_chars.GetChar(i)));

    validator.SetIncludes(list);

    return validator;
}


IntArgView::IntArgView(EditorPanel* parent, IntArg* model): ArgView(parent), m_model(model) {

    /*
      First layout the widgets.
     */

    wxTextValidator intValidator = GetIntValidator();

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_minusButton = new wxButton(this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    m_intTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), wxTE_PROCESS_ENTER, intValidator);
    m_plusButton = new wxButton(this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );

    hbox->Add(m_minusButton, 1, wxALL, 5);
    hbox->Add(m_intTextCtrl, 2, wxALL, 5);
    hbox->Add(m_plusButton, 1, wxALL, 5);
    hbox->SetSizeHints(this);

    this->SetSizer(hbox);
    this->Layout();

    /*
      Setup event handling
     */


    Bind(wxEVT_BUTTON, &IntArgView::OnButton, this);
    Bind(wxEVT_TEXT_ENTER, &IntArgView::OnTextEnter, this);


    /*
      Next initialize the text field.
     */

    UpdateTextCtrl(false);
}

void IntArgView::UpdateTextCtrl(bool notifyGraph) {
    m_intTextCtrl->Clear();
    *m_intTextCtrl << m_model->GetVal();

    if(notifyGraph ) {
	OnArgUpdate();

    }
    // NOTIFY GRAPH THAT IT SHOULD BE REBUILT.
}

void IntArgView::OnButton(const wxEvent& evt) {

    if(evt.GetEventObject() == m_minusButton) {
	m_model->Decrease();
	UpdateTextCtrl(true);
    } else if(evt.GetEventObject() == m_plusButton) {
	m_model->Increase();
	UpdateTextCtrl(true);
    }
}

void IntArgView::OnTextEnter(const wxEvent&) {

    long l;
    if(m_intTextCtrl->GetValue().ToLong(&l)) {
	int i = (int)l;

	m_model->SetVal(i);
	UpdateTextCtrl(true);

    } else {
	// reset to old number
	UpdateTextCtrl(false);
    }

}
