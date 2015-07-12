#pragma once

class wxWindow;

#include <wx/string.h>

class ArgView;


/*
  "Arg" stands for "Argument"
 */
class Arg {

private:

    wxString m_argName;

public:

    Arg(const wxString& argName);

    virtual ArgView* CreateView(wxWindow *parent) = 0;


    wxString GetArgName()const;
};
