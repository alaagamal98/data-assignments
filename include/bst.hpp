#ifndef SBE201_WORDCOUNT_MAPS_BST_HPP
#define SBE201_WORDCOUNT_MAPS_BST_HPP

#include <iostream>
#include <string>
#include <queue>

namespace bst
{

template <typename T>
struct BSTNode
{
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
struct BST
{

private:
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    bool isEmpty() const
    {
        return (root == nullptr);
    }

    bool isLeaf() const
    {
        return (root->left == nullptr && root->right == nullptr);
    }

    int size() const
    {
        return size(root);
    }

    bool find(const T item) const
    {
        return find(root, item);
    }

    void insert(T item)
    {
        insert(root, item);
    }

    BSTNode<T> *minNode() const
    {
        return minNode(root);
    }

    void remove(T item)
    {
        remove(root, item);
    }

    void clear()
    {
        clear(root);
    }

    void preorder() const
    {
        preorder(root);
    }

    void inorder() const
    {
        inorder(root);
    }

    void postorder() const
    {
        postorder(root);
    }

    void breadthFirst() const
    {
        breadthFirst(root);
    }

private:
    static int size(const BSTNode<T> *const &root)
    {
        if (root)
        {
            return (1 + size(root->left) + size(root->right));
        }
        else
        {
            return 0;
        }
    }
    static bool find(const BSTNode<T> *const &root, const T item)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else if (item == root->data)
        {
            return true;
        }
        else if (item < root->data)
        {
            return find(root->left, item);
        }
        else
        {
            return find(root->right, item);
        }
    }
    static void insert(BSTNode<T> *&root, T item)
    {
        if (root == nullptr)
        {
            root = new BSTNode<T>{item};
        }
        else if (item < root->data)
        {
            insert(root->left, item);
        }
        else
        {
            insert(root->right, item);
        }
    }
    static BSTNode<T> *minNode(BSTNode<T> *&root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return root;
        }
        else
        {
            return minNode(root->left);
        }
    }

    static void remove(BSTNode<T> *&root, T &item)
    {
        if (root == nullptr)
        {
            return;
        }
        if (item == root->data)
        {
            removeNode(root);
        }

        else if (item < root->data)
        {
            remove(root->left, item);
        }
        else
        {
            remove(root->right, item);
        }
    }
    static void removeNode(BSTNode<T> *&root)
    {
        if (root->left != nullptr && root->right != nullptr)
        {
            BSTNode<T> *minRight = minNode(root->right);
            root->data = minRight->data;
            remove(root->right, minRight->data);
        }
        else
        {
            BSTNode<T> *discard = root;
            if (root->left == nullptr && root->right == nullptr)
            {
                root = nullptr;
            }
            else if (root->left != nullptr)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            delete discard;
        }
    }
    static void clear(BSTNode<T> *&root)
    {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }

    static void preorder(const BSTNode<T> *root)
    {
        if (root)
        {
            std::cout << "[" << root->data << "]";
            preorder(root->left);
            preorder(root->right);
        }
    }
    static void inorder(const BSTNode<T> *root)
    {
        if (root)
        {
            inorder(root->left);
            std::cout << "[" << root->data << "]";
            inorder(root->right);
        }
    }
    static void postorder(const BSTNode<T> *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << "[" << root->data << "]";
        }
    }
    static void breadthFirst(const BSTNode<T> *root)
    {
        const BSTNode<T> *current = root;
        std::queue<const BSTNode<T> *> queue;
        queue.push(current);
        while (!queue.empty())
        {
            current = queue.front();
            queue.pop();
            std::cout << "[" << current->data << "]";
            if (current->left)
            {
                queue.push(current->left);
            }
            if (current->right)
            {
                queue.push(current->right);
            }
        }
    }
};

} // namespace bst

#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP
