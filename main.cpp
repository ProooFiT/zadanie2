/**
 * @file main.cpp
 * @brief Program zarządzający drzewem binarnym przy użyciu klasy BST oraz FileHandler.
 * 
 * Program pozwala na dodawanie, usuwanie elementów, wyszukiwanie ścieżki do elementu,
 * wyświetlanie drzewa oraz zapis i odczyt drzewa z plików tekstowych i binarnych.
 */

#include "BST.h"
#include "FileHandler.h"
#include <iostream>

/**
 * @brief Funkcja główna programu.
 * 
 * Wyświetla menu z opcjami zarządzania drzewem binarnym:
 * - Dodawanie elementów
 * - Usuwanie elementów
 * - Wyszukiwanie ścieżki do elementu
 * - Wyświetlanie drzewa w różnych porządkach (preorder, inorder, postorder)
 * - Zapisywanie i odczytywanie drzewa z plików tekstowych i binarnych
 * 
 * @return Zwraca 0 po zakończeniu działania programu.
 */
int main() {
    BST tree;
    int choice, value;
    std::string filename;

    while (true) {
        // Wyświetlenie menu
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
            case 1: {
                /** 
                 * @brief Dodawanie elementu do drzewa.
                 */
                std::cout << "Podaj wartosc: ";
                std::cin >> value;
                tree.add(value);
                break;
            }
            case 2: {
                /** 
                 * @brief Usuwanie elementu z drzewa.
                 */
                std::cout << "Podaj wartosc do usuniecia: ";
                std::cin >> value;
                tree.remove(value);
                break;
            }
            case 3: {
                /** 
                 * @brief Usunięcie całego drzewa.
                 */
                tree.clear();
                std::cout << "Drzewo usuniete.\n";
                break;
            }
            case 4: {
                /** 
                 * @brief Wyszukiwanie ścieżki do elementu w drzewie.
                 */
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
            }
            case 5: {
                /** 
                 * @brief Wyświetlanie drzewa w wybranym porządku.
                 */
                std::cout << "Wybierz porzadek (1-preorder, 2-inorder, 3-postorder): ";
                std::cin >> value;
                tree.display(value);
                break;
            }
            case 6: {
                /** 
                 * @brief Zapis drzewa do pliku tekstowego.
                 */
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                tree.saveToTextFile(filename);
                break;
            }
            case 7: {
                /** 
                 * @brief Zapis drzewa do pliku binarnego.
                 */
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::saveBinary(filename, tree);
                break;
            }
            case 8: {
                /** 
                 * @brief Wczytanie drzewa z pliku binarnego.
                 */
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::loadBinary(filename, tree);
                break;
            }
            case 9: {
                /** 
                 * @brief Wczytanie drzewa z pliku tekstowego.
                 */
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> filename;
                FileHandler::loadFromTextFile(filename, tree);
                break;
            }
            case 0:
                /**
                 * @brief Wyjście z programu.
                 */
                return 0;
            default:
                /**
                 * @brief Obsługa nieprawidłowej opcji menu.
                 */
                std::cout << "Nieprawidlowa opcja!\n";
                break;
        }
    }
}
