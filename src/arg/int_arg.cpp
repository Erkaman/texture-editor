#include "int_arg.hpp"

#include "int_arg_view.hpp"

IntArg::IntArg(const wxString& argName,  const int val, const int min, int max, int step): Arg(argName),m_val(val), m_min(min), m_max(max), m_step(step) {

}

ArgView* IntArg::CreateView(EditorPanel* parent)  {
    return new IntArgView(parent, this);
}

wxString IntArg::ToString()const {
    return wxString::Format(wxT("%i"),m_val);
}


int IntArg::GetVal() const{
    return m_val;
}

void IntArg::Increase() {
    m_val += m_step;
}

void IntArg::Decrease() {
    m_val -= m_step;
}

void IntArg::SetVal(const int val)  {
    m_val = val;
}
