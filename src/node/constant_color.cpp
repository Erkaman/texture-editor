#include "constant_color.hpp"

#include "arg/colour_arg.hpp"
#include "arg/int_arg.hpp"

ConstantColor::ConstantColor(const int index): Pattern(wxT("Constant Color"), 1,index)  {

    // fill it with controls.
    m_args[0] = new IntArg(5, 0, 10);

}
