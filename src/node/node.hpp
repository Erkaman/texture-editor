#pragma once

#include <wx/string.h>

class Arg;

class Node {

private:

    wxString m_nameLabelString;

    size_t m_numArgs;

protected:

    Arg** m_args;


public:

    Node(const wxString& nameLabelString, const size_t numArgs);
    virtual ~Node();

    wxString GetNameLabelString();
};
