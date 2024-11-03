#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace Echo {

    class FileSystem {
    public:
        static bool CreateDirectoryW(const std::string& path);
        static bool DeleteFileW(const std::string& filepath);
        static bool WriteFile(const std::string& filepath, const std::string& content);
        static std::string ReadFile(const std::string& filepath);
        static std::vector<std::string> ListFiles(const std::string& directory);
    };
}
