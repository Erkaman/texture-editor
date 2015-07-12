#pragma once

#include "arg_view.hpp"

class ColourArg;
class wxStaticBitmap;

class ColourArgView : public ArgView {

private:
    wxButton* m_colorButton;
    wxStaticBitmap* m_colorBitmap;

    ColourArg* m_model;

public:

    ColourArgView(EditorPanel* parent, ColourArg* model);

    void OnButton(const wxEvent& evt);

    void UpdateBitmap(bool notifyGraph);
};
