#include "node.hpp"


Node::Node(const wxString& nameLabelString): m_nameLabelString(nameLabelString) {

}

wxString Node::GetNameLabelString() {
    return m_nameLabelString;
}
