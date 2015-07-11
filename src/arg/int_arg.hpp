#pragma once

#include "arg.hpp"

class IntArg : public Arg{

private:

    int m_val;
    int m_min;
    int m_max;

public:

    IntArg( const int val, const int min, int max);

    ArgView* CreateView(wxWindow *parent, const wxPoint& pos) override;

};
