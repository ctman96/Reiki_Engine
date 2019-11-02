//
// Created by Cody on 10/31/2019.
//

#ifndef REIKI_FILEUTILS_HPP
#define REIKI_FILEUTILS_HPP

#include <fstream>
#include <sstream>

#include "../project_path.hpp"

#define project_path(name) PROJECT_SOURCE_DIR "./" name
#define shader_path(name) PROJECT_SOURCE_DIR "./src/shaders/" name
#define texture_path(name) PROJECT_SOURCE_DIR "./src/textures/" name

namespace Reiki {

    // TODO project path for relative imports
    static std::string read_file(const char* filepath) {
        std::ifstream f_is(filepath);
        if (!f_is.good()) {
            fprintf(stderr, "Failed to load file %s", filepath);
            return "";
        }

        std::stringstream f_ss;
        f_ss << f_is.rdbuf();
        std::string f_str = f_ss.str();
        return f_str;
    }

}

#endif //REIKI_FILEUTILS_HPP
