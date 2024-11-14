#include "BST.h"
#include "FileHandler.h"
#include <iostream>

int main() {
    BST tree;
    int choice, value;
    std::string filename;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj drogi do elementu\n";
        std::cout << "5. Wyswietl drzewo\n";
        std::cout << "6. Zapisz drzewo do pliku tekstowego\n";
        std::cout << "7. Zapisz do pliku binarnego\n";
        std::cout << "8. Wczytaj z pliku binarnego\n";
        std::cout << "9. Wczytaj z pliku tekstowego\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj wartosc: ";
                std::cin >> value;
                tree.add(value);
                break;
            case 2:
                std::cout << "Podaj wartosc do usuniecia: ";
                std::cin >> value;
                tree.remove(value);
                break;
            case 3:
                tree.clear();
                std::cout << "Drzewo usuniete.\n";
                break;
            case 4:
                std::cout << "Podaj wartosc do znalezienia: ";
                std::cin >> value;
                std::vector<int> path;
                if (tree.findPath(value, path)) {
                    std::cout << "Droga: ";
                    for (int v : path) std::cout << v << " ";
                    std::cout << "\n";
                } else {
                    std::cout << "Element nie znaleziony.\n";
                }
                break;
            case 5:
                std::cout << "Wybierz porzadek (1-preorder, 2-inorder, 3-postorder): ";
                std::cin >> value;
                tree.display(value);
                break;
            case 6:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                tree.saveToTextFile(filename);
                break;
            case 7:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::saveBinary(filename, tree);
                break;
            case 8:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::loadBinary(filename, tree);
                break;
            case 9:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::loadFromTextFile(filename, tree);
                break;
            case 0:
                return 0;
            default:
                std::cout << "Nieprawidlowa opcja!\n";
                break;
        }
    }
}
