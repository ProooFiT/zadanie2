#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BST.h"
#include <string>

/**
 * @class FileHandler
 * @brief Klasa odpowiedzialna za operacje na plikach dla drzewa binarnego (BST).
 * 
 * Klasa `FileHandler` zawiera metody do zapisu i odczytu drzewa binarnego 
 * zarówno z plików binarnych, jak i tekstowych.
 */
class FileHandler {
public:

    /**
     * @brief Zapisuje drzewo binarne do pliku binarnego.
     * 
     * @param filename Nazwa pliku, do którego zapisane zostanie drzewo.
     * @param tree Obiekt drzewa binarnego (BST), który ma być zapisany.
     */
    static void saveBinary(const std::string& filename, const BST& tree);

    /**
     * @brief Odczytuje drzewo binarne z pliku binarnego.
     * 
     * @param filename Nazwa pliku, z którego drzewo zostanie odczytane.
     * @param tree Obiekt drzewa binarnego (BST), do którego wczytane zostaną dane.
     */
    static void loadBinary(const std::string& filename, BST& tree);

    /**
     * @brief Wczytuje drzewo binarne z pliku tekstowego.
     * 
     * @param filename Nazwa pliku tekstowego, z którego wczytywane będą dane.
     * @param tree Obiekt drzewa binarnego (BST), do którego wczytane zostaną wartości.
     * 
     * @details Funkcja otwiera plik tekstowy i odczytuje z niego kolejne liczby całkowite,
     *          które następnie są dodawane do drzewa binarnego.
     */
    static void loadFromTextFile(const std::string& filename, BST& tree);
};

#endif // FILEHANDLER_H
