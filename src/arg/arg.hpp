#pragma once

#include <wx/wx.h>

class ArgView;


/*
  "Arg" stands for "Argument"
 */
class Arg {

public:

    Arg();

    virtual ArgView* CreateView(wxWindow *parent, const wxPoint& pos) = 0;
};
