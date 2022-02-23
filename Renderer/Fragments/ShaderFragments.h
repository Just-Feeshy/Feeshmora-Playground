#pragma once

#ifndef FRAGMENT_PIECES_INCLUDED
#define FRAGMENT_PIECES_INCLUDED

#include "../../Libraries/json.hpp"

#include <string>

struct ShaderFragments {
    static const std::string getVersion();
    static const std::string setMaximumLights();
};
#endif