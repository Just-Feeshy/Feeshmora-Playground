#pragma once

#include "ShaderFragments.h"

const std::string ShaderFragments::getVersion() {
    const std::string jsonStuff = FileAssets::getTXT("Assets/config/version.json");
    const char* jsonCharPtr = jsonStuff.c_str();
    
    rapidjson::Document doc;
    doc.Parse(jsonCharPtr);

    const rapidjson::Value& value = doc["version"]["GLSL"];
    
    return "#version " + std::to_string(value.GetInt()) + " core\n\n";

    //return "#version 330 core\n\n";
}

const std::string ShaderFragments::setMaximumLights(const int p, const int s, const int d) {
    return "#define MAXIMUM_POINTLIGHTS " + std::to_string(p) + "\n";
}