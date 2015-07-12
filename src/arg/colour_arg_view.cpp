#include "colour_arg_view.hpp"

#include "colour_arg.hpp"

#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statbmp.h>

ColourArgView::ColourArgView(EditorPanel* parent, ColourArg* model): ArgView(parent), m_model(model) {

    /*
      First layout the widgets.
     */


    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_colorButton = new wxButton(this, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    m_colorBitmap =new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(-1, -1), wxBORDER_DOUBLE);

    hbox->Add(m_colorButton, 1, wxALL, 5);
    hbox->Add(m_colorBitmap, 1, wxALL, 5);

    hbox->SetSizeHints(this);

    this->SetSizer(hbox);
    this->Layout();

    /*
      Setup event handling
     */

    Bind(wxEVT_BUTTON, &ColourArgView::OnButton, this);

    /*
      Next initialize the text field.
     */

    UpdateBitmap(false);
}

void ColourArgView::UpdateBitmap(bool notifyGraph) {

    m_colorBitmap->SetBackgroundColour(m_model->GetValue());
    m_colorBitmap->ClearBackground();

    if(notifyGraph ) {
	OnArgUpdate();
    }
}

void ColourArgView::OnButton(const wxEvent& evt) {
    printf("button\n");

/*    if(evt.GetEventObject() == m_minusButton) {
	m_model->Decrease();
	UpdateTextCtrl(true);
    } else if(evt.GetEventObject() == m_plusButton) {
	m_model->Increase();
	UpdateTextCtrl(true);
	}*/
}
