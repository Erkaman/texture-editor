#include "constant_color.hpp"

#include "arg/colour_arg.hpp"

ConstantColor::ConstantColor(): Pattern(wxT("Constant Color"), 1)  {

    // fill it with controls.
    m_args[0] = new ColourArg();

}
