#pragma once

#include "arg_view.hpp"

class wxTextCtrl;

class IntArg;

class IntArgView : public ArgView {

private:
    wxButton* m_minusButton;
    wxButton* m_plusButton;

    wxTextCtrl* m_intTextCtrl;

    IntArg* m_model;

public:

    IntArgView(EditorPanel* parent, IntArg* model);

    void UpdateTextCtrl(bool notifyGraph);

    void OnButton(const wxEvent& evt);
    void OnTextEnter(const wxEvent&);

};
