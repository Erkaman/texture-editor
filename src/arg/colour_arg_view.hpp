#pragma once

#include "arg_view.hpp"

class ColourArg;
class wxStaticBitmap;
class wxColourPickerCtrl;
class wxColourPickerEvent;

class ColourArgView : public ArgView {

private:
    wxColourPickerCtrl* m_colorButton;

    ColourArg* m_model;

public:

    ColourArgView(EditorPanel* parent, ColourArg* model);

    void OnColorUpdate(const wxColourPickerEvent& evt);

    void UpdateModel(bool notifyGraph);
};
