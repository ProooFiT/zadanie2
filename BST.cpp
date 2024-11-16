#include "BST.h"
#include <fstream>

/**
 * @brief Konstruktor domyślny inicjalizujący drzewo jako puste.
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destruktor, który usuwa całe drzewo.
 */
BST::~BST() {
    clear();
}

/**
 * @brief Rekurencyjnie dodaje nowy węzeł z podaną wartością do drzewa.
 * 
 * @param node Aktualny węzeł.
 * @param value Wartość do dodania.
 * @return Nowy korzeń drzewa po dodaniu elementu.
 */
BST::Node* BST::add(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->value)
        node->left = add(node->left, value);
    else
        node->right = add(node->right, value);
    return node;
}

/**
 * @brief Dodaje nowy element do drzewa.
 * 
 * @param value Wartość do dodania.
 */
void BST::add(int value) {
    root = add(root, value);
}

/**
 * @brief Rekurencyjnie usuwa węzeł z drzewa.
 * 
 * @param node Aktualny węzeł.
 * @param value Wartość do usunięcia.
 * @return Nowy korzeń drzewa po usunięciu elementu.
 */
BST::Node* BST::remove(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->value)
        node->left = remove(node->left, value);
    else if (value > node->value)
        node->right = remove(node->right, value);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* successor = node->right;
        while (successor->left)
            successor = successor->left;
        node->value = successor->value;
        node->right = remove(node->right, successor->value);
    }
    return node;
}

/**
 * @brief Usuwa element z drzewa.
 * 
 * @param value Wartość do usunięcia.
 */
void BST::remove(int value) {
    root = remove(root, value);
}

/**
 * @brief Rekurencyjnie usuwa wszystkie węzły w drzewie.
 * 
 * @param node Aktualny węzeł.
 */
void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

/**
 * @brief Usuwa wszystkie elementy z drzewa.
 */
void BST::clear() {
    clear(root);
    root = nullptr;
}

/**
 * @brief Rekurencyjnie znajduje ścieżkę do elementu.
 * 
 * @param node Aktualny węzeł.
 * @param value Wartość do znalezienia.
 * @param path Wektor przechowujący ścieżkę do elementu.
 * @return True, jeśli element został znaleziony; False w przeciwnym razie.
 */
bool BST::findPath(Node* node, int value, std::vector<int>& path) const {
    if (!node) return false;
    path.push_back(node->value);
    if (node->value == value) return true;
    if ((node->left && findPath(node->left, value, path)) || 
        (node->right && findPath(node->right, value, path)))
        return true;
    path.pop_back();
    return false;
}

/**
 * @brief Znajduje ścieżkę do podanej wartości w drzewie.
 * 
 * @param value Wartość do znalezienia.
 * @param path Wektor przechowujący ścieżkę do elementu.
 * @return True, jeśli element został znaleziony; False w przeciwnym razie.
 */
bool BST::findPath(int value, std::vector<int>& path) const {
    path.clear();
    return findPath(root, value, path);
}

/**
 * @brief Wyświetla zawartość drzewa w określonym porządku.
 * 
 * @param orderType Typ porządku (1 - preorder, 2 - inorder, 3 - postorder).
 */
void BST::display(int orderType) const {
    if (orderType == 1)
        printPreorder(root);
    else if (orderType == 2)
        printInorder(root);
    else
        printPostorder(root);
    std::cout << std::endl;
}

/**
 * @brief Wyświetla drzewo w porządku preorder.
 * 
 * @param node Aktualny węzeł.
 */
void BST::printPreorder(Node* node) const {
    if (!node) return;
    std::cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

/**
 * @brief Wyświetla drzewo w porządku inorder.
 * 
 * @param node Aktualny węzeł.
 */
void BST::printInorder(Node* node) const {
    if (!node) return;
    printInorder(node->left);
    std::cout << node->value << " ";
    printInorder(node->right);
}

/**
 * @brief Wyświetla drzewo w porządku postorder.
 * 
 * @param node Aktualny węzeł.
 */
void BST::printPostorder(Node* node) const {
    if (!node) return;
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->value << " ";
}

/**
 * @brief Rekurencyjnie zapisuje drzewo do pliku tekstowego w porządku preorder.
 * 
 * @param node Aktualny węzeł.
 * @param out Strumień wyjściowy do pliku.
 */
void BST::saveToTextFile(Node* node, std::ostream& out) const {
    if (!node) return;
    out << node->value << " ";
    saveToTextFile(node->left, out);
    saveToTextFile(node->right, out);
}

/**
 * @brief Zapisuje drzewo do pliku tekstowego.
 * 
 * @param filename Nazwa pliku, do którego zapisane zostanie drzewo.
 */
void BST::saveToTextFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveToTextFile(root, file);
        file.close();
    }
}
