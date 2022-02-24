#pragma once

#include "ShaderFragments.h"

const std::string ShaderFragments::getVersion() {
    const std::string jsonStuff = FileAssets::getTXT("Assets/config/version.json");
    const char* jsonCharPtr = jsonStuff.c_str();
    
    rapidjson::Document doc;
    doc.Parse(jsonCharPtr);

    const rapidjson::Value& value = doc["version"]["GLSL"];
    
    return "#version " + std::string(value.GetString()) + " core\n\n";
}

const std::string ShaderFragments::setMaximumLights() {
    const std::string jsonStuff = FileAssets::getTXT("Assets/config/maximum.json");
    const char* jsonCharPtr = jsonStuff.c_str();

    rapidjson::Document doc;
    doc.Parse(jsonCharPtr);

    const rapidjson::Value& value = doc["point_lights"];
    
    return "#define MAXIMUM_POINTLIGHTS " + std::string(value.GetString()) + "\n";
}