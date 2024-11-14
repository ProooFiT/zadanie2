#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BST.h"
#include <string>

class FileHandler {
public:
    static void saveBinary(const std::string& filename, const BST& tree);
    static void loadBinary(const std::string& filename, BST& tree);
    static void loadFromTextFile(const std::string& filename, BST& tree);
};

#endif
