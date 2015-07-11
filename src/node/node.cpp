#include "node.hpp"


Node::Node(const wxString& nameLabelString, const size_t numArgs,const int index): m_nameLabelString(nameLabelString),m_numArgs(numArgs), m_index(index) {
    m_args = new Arg*[m_numArgs];
    itEnd = m_args + m_numArgs;
}

wxString Node::GetNameLabelString()const {
    return m_nameLabelString;
}


int Node::GetIndex()const {
    return m_index;
}

Node::~Node() {
    wxDELETEA(m_args);
}

Node::iterator Node::begin() {
    return m_args;
}

Node::iterator Node::end() {
    return itEnd;
}
