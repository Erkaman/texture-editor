#pragma once

#include <wx/string.h>

class Node {

private:

    wxString m_nameLabelString;

public:

    Node(const wxString& nameLabelString);
    virtual ~Node() {}

    wxString GetNameLabelString();
};
