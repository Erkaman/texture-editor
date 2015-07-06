#include "left_panel.hpp"

LeftPanel::LeftPanel(wxPanel * parent)
           : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SIMPLE) {
  m_parent = parent;
}
