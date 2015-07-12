#include "int_arg.hpp"

#include "int_arg_view.hpp"

IntArg::IntArg(const wxString& argName,  const int val, const int min, int max): Arg(argName),m_val(val), m_min(min), m_max(max) {

}

ArgView* IntArg::CreateView(wxWindow *parent)  {
    return new IntArgView(parent, this);
}
