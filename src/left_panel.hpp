#include <wx/wx.h>
#include <wx/panel.h>

class LeftPanel : public wxPanel
{
public:
    LeftPanel(wxPanel *parent);

    wxPanel *m_parent;
};
