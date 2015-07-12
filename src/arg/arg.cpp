#include "arg.hpp"

Arg::Arg(const wxString& argName): m_argName(argName) {

}

wxString Arg::GetArgName()const {
    return m_argName;
}
