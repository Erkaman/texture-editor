#pragma once

#include <wx/string.h>

class Arg;

class Node {

public:

    /*
      TYPEDEFS
     */
    typedef Arg** const_iterator;

private:

    wxString m_nameLabelString;

    size_t m_numArgs;

    int m_index;
    const_iterator itCend;

protected:

    Arg** m_args;


public:

    Node(const wxString& nameLabelString, const size_t numArgs, const int index);
    virtual ~Node();

    wxString GetNameLabelString()const;

    int GetIndex()const;

    /*
     */
    const_iterator cbegin();
    const_iterator cend();

};
