#include <iostream>
#include "bst.hpp"

using BSTString = bst::BST<std::string>;

int main()
{
    BSTString tree;

    tree.insert("Samy");
    tree.insert("Kareem");
    tree.insert("Toqa");
    tree.insert("Ahmed");
    tree.insert("Mohamed");
    tree.insert("Youmna");
    tree.insert("Wessam");
    tree.insert("Basma");
    tree.insert("Zyad");

    std::cout << "In-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    tree.inorder();
    std::cout << std::endl
              << std::endl;

    std::cout << "Pre-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    tree.preorder();
    std::cout << std::endl
              << std::endl;

    std::cout << "Post-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    tree.postorder();
    std::cout << std::endl
              << std::endl;

    std::cout << "Breadth first Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    tree.breadthFirst();
    std::cout << std::endl
              << std::endl;

    std::cout << "Find" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Find Samy:" << tree.find("Samy");
    std::cout << std::endl
              << std::endl;

    std::cout << "Find" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Find Sondos:" << tree.find("Sondos");
    std::cout << std::endl
              << std::endl;

    std::cout << "Size" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << tree.size();
    std::cout << std::endl
              << std::endl;

    std::cout << "Remove(Kareem)" << std::endl;
    std::cout << "==================" << std::endl;
    tree.remove("Kareem");
    std::cout << "Size:" << tree.size() << std::endl;
    std::cout << "BFT:";
    tree.breadthFirst();
    std::cout << std::endl
              << std::endl;

    std::cout << "Remove(Toqa)" << std::endl;
    std::cout << "==================" << std::endl;
    tree.remove("Toqa");
    std::cout << "Size:" << tree.size() << std::endl;
    std::cout << "BFT:";
    tree.breadthFirst();
    std::cout << std::endl
              << std::endl;
    return 0;
}