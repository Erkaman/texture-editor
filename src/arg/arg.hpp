#pragma once

class EditorPanel;

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

    virtual ArgView* CreateView(EditorPanel *parent) = 0;


    wxString GetArgName()const;
};
