#include "FileHandler.h"
#include <fstream>

void FileHandler::saveBinary(const std::string& filename, const BST& tree) {
    // Implementacja zapisu binarnego
}

void FileHandler::loadBinary(const std::string& filename, BST& tree) {
    // Implementacja odczytu binarnego
}

void FileHandler::loadFromTextFile(const std::string& filename, BST& tree) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        tree.add(value);
    }
}
