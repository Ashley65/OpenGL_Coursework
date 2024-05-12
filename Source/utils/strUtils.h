//
// Created by NigelWork on 07/05/2024.
//

#ifndef OPENGLCOURSEWORK_STRUTILS_H
#define OPENGLCOURSEWORK_STRUTILS_H

#include <vector>
#include <cstdint>
#include <string>
#include <sstream>

namespace strUtils{
    std::vector<uint32_t> tokenize(const std::string& str, const char token){
        std::vector<uint32_t> result;

        std::stringstream ss(str);
        std::string item;
        while (std::getline(ss, item, token)) {
           if (!item.empty()) {
               result.push_back(std::stoul(item));
           }

        }
        return result;
    }
}

#endif //OPENGLCOURSEWORK_STRUTILS_H
