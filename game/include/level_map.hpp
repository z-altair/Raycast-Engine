#pragma once
#include <filesystem>

class Engine;

namespace fs = std::filesystem;

class LevelMap{
    LevelMap(Engine *eng, fs::path file);
};