#include "colour_arg_view.hpp"

#include "colour_arg.hpp"

#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/clrpicker.h>

ColourArgView::ColourArgView(EditorPanel* parent, ColourArg* model): ArgView(parent), m_model(model) {

    /*
      First layout the widgets.
     */


    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_colorButton = new wxColourPickerCtrl(this, wxID_ANY, model->GetValue());

	//new wxButton(this, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    //  m_colorBitmap =new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(-1, -1), wxBORDER_DOUBLE);

    hbox->Add(m_colorButton, 1, wxALL, 5);
//    hbox->Add(m_colorBitmap, 1, wxALL, 5);

    hbox->SetSizeHints(this);

    this->SetSizer(hbox);
    this->Layout();

    /*
      Setup event handling
     */

    Bind(wxEVT_COLOURPICKER_CHANGED, &ColourArgView::OnColorUpdate, this);

    /*
      Next initialize the text field.
     */
}

void ColourArgView::UpdateModel(bool notifyGraph) {

    m_model->SetValue(m_colorButton->GetColour());

    if(notifyGraph ) {
	OnArgUpdate();
    }
}

void ColourArgView::OnColorUpdate(const wxColourPickerEvent& evt) {
    UpdateModel(true);
}
