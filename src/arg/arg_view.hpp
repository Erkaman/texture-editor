#pragma once

#include <wx/panel.h>

class EditorPanel;

class ArgView : public wxPanel{

private:

    EditorPanel* m_parent;

public:

    ArgView(EditorPanel *parent);
    virtual ~ArgView() {}

    void OnArgUpdate();

};
