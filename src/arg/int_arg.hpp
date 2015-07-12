#pragma once

#include "arg.hpp"

#include <wx/string.h>

class EditorPanel;

class IntArg : public Arg{

private:

    int m_val;
    const int m_min;
    const int m_max;
    const int m_step;

public:

    IntArg( const wxString& argName, const int val, const int min, int max, int step = 1);

    wxString ToString()const;
    int GetVal()const;
    void SetVal(const int val);

    void Increase();
    void Decrease();

    ArgView* CreateView(EditorPanel *parent) override;

};
