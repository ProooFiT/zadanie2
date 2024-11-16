#include "FileHandler.h"
#include <fstream>

/**
 * @brief Zapisuje drzewo binarne do pliku binarnego.
 * 
 * @param filename Nazwa pliku, do którego zapisane zostanie drzewo.
 * @param tree Obiekt drzewa binarnego (BST), który ma być zapisany.
 */
void FileHandler::saveBinary(const std::string& filename, const BST& tree) {
    // Implementacja zapisu binarnego
}

/**
 * @brief Odczytuje drzewo binarne z pliku binarnego.
 * 
 * @param filename Nazwa pliku, z którego drzewo zostanie odczytane.
 * @param tree Obiekt drzewa binarnego (BST), do którego wczytane zostaną dane.
 */
void FileHandler::loadBinary(const std::string& filename, BST& tree) {
    // Implementacja odczytu binarnego
}

/**
 * @brief Wczytuje drzewo binarne z pliku tekstowego.
 * 
 * @param filename Nazwa pliku tekstowego, z którego wczytywane będą dane.
 * @param tree Obiekt drzewa binarnego (BST), do którego wczytane zostaną wartości.
 * 
 * @details Funkcja otwiera plik tekstowy i odczytuje z niego kolejne liczby całkowite,
 *          które następnie są dodawane do drzewa binarnego.
 */
void FileHandler::loadFromTextFile(const std::string& filename, BST& tree) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        tree.add(value);
    }
}
