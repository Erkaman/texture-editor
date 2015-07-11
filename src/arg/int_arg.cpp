#include "int_arg.hpp"

#include "int_arg_view.hpp"

IntArg::IntArg( const int val, const int min, int max): m_val(val), m_min(min), m_max(max) {

}

ArgView* IntArg::CreateView(wxWindow *parent, const wxPoint& pos)  {
    return new IntArgView(parent, pos, this);
}
