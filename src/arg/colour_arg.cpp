#include "colour_arg.hpp"

#include "colour_arg_view.hpp"

ColourArg::ColourArg(const wxString& argName, const wxColour& value): Arg(argName), m_value(value) {
}

ArgView* ColourArg::CreateView(EditorPanel *parent) {
   return new ColourArgView(parent, this);
}

wxColour ColourArg::GetValue() const {
    return m_value;
}
