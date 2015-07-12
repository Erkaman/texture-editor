#pragma once

#include <wx/colour.h>

#include "arg.hpp"

class ColourArg : public Arg{

private:

    wxColour m_value;

public:

    ColourArg(const wxString& argName, const wxColour& value);

    wxColour GetValue() const;
    void SetValue(const wxColour& value);

    ArgView* CreateView(EditorPanel *parent) override;
};
