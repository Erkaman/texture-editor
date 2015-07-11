#include "node.hpp"


Node::Node(const wxString& nameLabelString, const size_t numArgs): m_nameLabelString(nameLabelString),m_numArgs(numArgs) {
    m_args = new Arg*[m_numArgs];
}

wxString Node::GetNameLabelString() {
    return m_nameLabelString;
}


Node::~Node() {
    delete [] m_args;
}
