#pragma once

#include <wx/colour.h>

#include "arg.hpp"

class ColourArg : public Arg{

private:

    wxColour m_colour;

public:

    ColourArg(const wxString& argName);

};
