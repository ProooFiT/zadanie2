#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

/**
 * @class BST
 * @brief Klasa implementująca drzewo binarne poszukiwań (Binary Search Tree).
 * 
 * Klasa `BST` pozwala na dodawanie, usuwanie, wyszukiwanie elementów,
 * a także zapisywanie drzewa do pliku tekstowego i wyświetlanie jego zawartości w różnych porządkach.
 */
class BST {
private:
    /**
     * @struct Node
     * @brief Struktura reprezentująca pojedynczy węzeł drzewa.
     */
    struct Node {
        int value;      /**< Wartość przechowywana w węźle */
        Node* left;     /**< Wskaźnik na lewy poddrzewo */
        Node* right;    /**< Wskaźnik na prawy poddrzewo */

        /**
         * @brief Konstruktor dla struktury Node.
         * @param val Wartość do przechowywania w węźle.
         */
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root; /**< Wskaźnik na korzeń drzewa */

    // Prywatne metody pomocnicze
    /**
     * @brief Rekurencyjnie dodaje nowy węzeł z podaną wartością do drzewa.
     * @param node Aktualny węzeł.
     * @param value Wartość do dodania.
     * @return Nowy korzeń drzewa po dodaniu elementu.
     */
    Node* add(Node* node, int value);

    /**
     * @brief Rekurencyjnie usuwa węzeł z drzewa.
     * @param node Aktualny węzeł.
     * @param value Wartość do usunięcia.
     * @return Nowy korzeń drzewa po usunięciu elementu.
     */
    Node* remove(Node* node, int value);

    /**
     * @brief Rekurencyjnie usuwa wszystkie węzły w drzewie.
     * @param node Aktualny węzeł.
     */
    void clear(Node* node);

    /**
     * @brief Rekurencyjnie znajduje ścieżkę do elementu.
     * @param node Aktualny węzeł.
     * @param value Wartość do znalezienia.
     * @param path Wektor przechowujący ścieżkę do elementu.
     * @return True, jeśli element został znaleziony; False w przeciwnym razie.
     */
    bool findPath(Node* node, int value, std::vector<int>& path) const;

    /**
     * @brief Wyświetla drzewo w porządku preorder.
     * @param node Aktualny węzeł.
     */
    void printPreorder(Node* node) const;

    /**
     * @brief Wyświetla drzewo w porządku inorder.
     * @param node Aktualny węzeł.
     */
    void printInorder(Node* node) const;

    /**
     * @brief Wyświetla drzewo w porządku postorder.
     * @param node Aktualny węzeł.
     */
    void printPostorder(Node* node) const;

    /**
     * @brief Rekurencyjnie zapisuje drzewo do pliku tekstowego w porządku preorder.
     * @param node Aktualny węzeł.
     * @param out Strumień wyjściowy do pliku.
     */
    void saveToTextFile(Node* node, std::ostream& out) const;

public:
    /**
     * @brief Konstruktor domyślny inicjalizujący drzewo jako puste.
     */
    BST();

    /**
     * @brief Destruktor, który usuwa całe drzewo.
     */
    ~BST();
    
    /**
     * @brief Dodaje nowy element do drzewa.
     * @param value Wartość do dodania.
     */
    void add(int value);

    /**
     * @brief Usuwa element z drzewa.
     * @param value Wartość do usunięcia.
     */
    void remove(int value);

    /**
     * @brief Usuwa wszystkie elementy z drzewa.
     */
    void clear();

    /**
     * @brief Znajduje ścieżkę do podanej wartości w drzewie.
     * @param value Wartość do znalezienia.
     * @param path Wektor przechowujący ścieżkę do elementu.
     * @return True, jeśli element został znaleziony; False w przeciwnym razie.
     */
    bool findPath(int value, std::vector<int>& path) const;

    /**
     * @brief Wyświetla zawartość drzewa w określonym porządku.
     * @param orderType Typ porządku (1 - preorder, 2 - inorder, 3 - postorder).
     */
    void display(int orderType) const;

    /**
     * @brief Zapisuje drzewo do pliku tekstowego.
     * @param filename Nazwa pliku, do którego zapisane zostanie drzewo.
     */
    void saveToTextFile(const std::string& filename) const;
};

#endif // BST_H
