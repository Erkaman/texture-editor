#include "constant_color.hpp"

#include "arg/colour_arg.hpp"
#include "arg/int_arg.hpp"

ConstantColor::ConstantColor(const int index): Pattern(wxT("Constant Color"), 2,index)  {

    // fill it with controls.
    m_args[0] = new IntArg(wxT("Arg1"),5, 0, 10);

    m_args[1] = new IntArg(wxT("Arg2"),5, 0, 10);

}
