#pragma once

#include "arg_view.hpp"

class IntArg;

class IntArgView : public ArgView {

private:
    wxButton* m_minusButton;
    wxButton* m_plusButton;

    wxTextCtrl* m_intTextCtrl;

    IntArg* m_model;

public:

    IntArgView(wxWindow *parent, IntArg* model);

};
