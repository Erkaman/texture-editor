#pragma once

#include <wx/string.h>

class Arg;

class Node {

public:

    /*
      TYPEDEFS
     */
    typedef Arg** iterator;

private:

    wxString m_nameLabelString;

    size_t m_numArgs;

    int m_index;
    iterator itEnd;

protected:

    Arg** m_args;


public:

    Node(const wxString& nameLabelString, const size_t numArgs, const int index);
    virtual ~Node();

    wxString GetNameLabelString()const;

    int GetIndex()const;

    /*
     */
    iterator begin();
    iterator end();

};
