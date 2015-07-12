#pragma once

class wxWindow;

class ArgView;


/*
  "Arg" stands for "Argument"
 */
class Arg {

public:

    Arg();

    virtual ArgView* CreateView(wxWindow *parent) = 0;
};
