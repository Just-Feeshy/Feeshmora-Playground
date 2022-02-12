#pragma once

#ifndef FILE_ASSETS_INCLUDED
#define FILE_ASSETS_INCLUDED

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace FileAssets {
    std::string getTXT(const std::string &path) {
        std::ifstream getFile(path);

        if(!getFile.is_open()) {
            throw std::runtime_error("Can't locate file: " + path);
        }

        std::stringstream string_S;

        string_S << getFile.rdbuf();
        getFile.close();
        return string_S.str();
    }

    bool exist(const std::string &path) {
        std::ifstream getFile(path);

        if(!getFile.is_open()) {
            return false;
        }

        getFile.close();
        return true;
    }   
};
#endif