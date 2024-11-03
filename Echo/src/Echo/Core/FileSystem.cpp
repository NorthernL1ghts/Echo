#include "FileSystem.h"
#include <fstream>
#include <iostream>

namespace Echo {

    bool FileSystem::CreateDirectoryW(const std::string& path) {
        return std::filesystem::create_directory(path);
    }

    bool FileSystem::DeleteFileW(const std::string& filepath) {
        return std::filesystem::remove(filepath);
    }

    bool FileSystem::WriteFile(const std::string& filepath, const std::string& content) {
        std::ofstream file(filepath);
        if (!file) {
            return false;
        }
        file << content;
        return true;
    }

    std::string FileSystem::ReadFile(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file) {
            return "";
        }
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;
    }

    std::vector<std::string> FileSystem::ListFiles(const std::string& directory) {
        std::vector<std::string> files;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            files.push_back(entry.path().string());
        }
        return files;
    }
}
