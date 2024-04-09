#ifndef UTILS_IO_H
#define UTILS_IO_H
#include "pch.h"

namespace vlux {
inline std::vector<char> read_file(const std::filesystem::path& filename) {
    if (!std::filesystem::exists(filename)) {
        throw std::runtime_error(fmt::format("file: {} does not exist", filename.string()));
    }
    auto file = std::ifstream(filename, std::ios::ate | std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    const auto file_size = static_cast<size_t>(file.tellg());
    auto buffer = std::vector<char>(file_size);
    file.seekg(0);
    file.read(buffer.data(), file_size);
    file.close();

    return buffer;
}
}  // namespace vlux

#endif