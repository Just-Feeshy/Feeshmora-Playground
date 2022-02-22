#pragma once

#include "ShaderFragments.h"

const std::string ShaderFragments::getVersion() {
    return "#version 330 core\n\n";
}

const std::string ShaderFragments::setMaximumLights() {
    return "#define MAXIMUM_POINTLIGHTS 1\n";
}