#pragma once

#ifndef FRAGMENT_PIECES_INCLUDED
#define FRAGMENT_PIECES_INCLUDED

#include "../../Libraries/json.hpp"
#include "../../Util/FileAssets.hpp"

#include <iostream>

struct ShaderFragments {
    static const std::string getVersion();
    static const std::string setMaximumLights(const int p, const int s, const int d);
};
#endif