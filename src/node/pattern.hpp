#pragma once

#include "node.hpp"

class Pattern : public Node{

public:

    Pattern(const wxString& nameLabelString, const size_t numArgs);
    virtual ~Pattern() {}


};
