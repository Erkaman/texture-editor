#include "main_frame.hpp"

#include "left_panel.hpp"
#include "right_panel.hpp"

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}


MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(890, 650))
{
    m_parent = new wxPanel(this, wxID_ANY);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
	    wxCommandEventHandler(MainFrame::OnExit));


    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_lp = new LeftPanel(m_parent);
    m_rp = new RightPanel(m_parent);

    hbox->Add(m_lp, 3, wxEXPAND | wxALL, 0);
    hbox->Add(m_rp, 1, wxEXPAND | wxALL, 0);

    m_parent->SetSizer(hbox);

    this->Centre();
}
