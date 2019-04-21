#ifndef SBE201_WORDCOUNT_MAPS_SET_HPP
#define SBE201_WORDCOUNT_MAPS_SET_HPP

#include "bst.hpp"

namespace set
{

template <typename T>
using BST = bst::BST<T>;
template <typename T>
using BSTNode = bst::BSTNode<T>;

template <typename T>
struct Set
{
private:
    BST<T> wSet;

public:
    bool isEmpty() const
    {
        return wSet.isEmpty();
    }

    int size() const
    {
        return wSet.size();
    }

    bool contains(const T &item)
    {
        return wSet.find(item);
    }

    void remove(const T &to_remove)
    {
        wSet.remove(to_remove);
    }

    void add(const T new_item)
    {
        if (!contains(new_item))
        {
            wSet.insert(new_item);
        }
    }

    void printAll() const
    {
        wSet.inorder();
    }

    BST<T> *populate(BST<T> s2) const
    {
        return populate(wSet, s2);
    }

    BST<T> *union_(const BST<T> s2)
    {
        BST<T> *s3;
        populate(wSet, s3);
        populate(s2, s3);
        return s3;
    }

    BST<T> *intersect(const BST<T> s2)
    {
        BST<T> *s3;
        if (wSet.data == s2.data)
        {
            s3.add(wSet.data);
        }
        wSet.left->intersect(s2.left);
        wSet.right->intersect(s2.right);
        return s3;
    }

    bool equals(const BST<T> s2)
    {
        if (!wSet.size() == s2.size())
        {
            return false;
        }
        return (wSet.data == s2.data) && (wSet.left->equals(s2.left)) && (wSet.right->equals(s2.right));
    }

private:
    static BST<T> *populate(const BST<T> *s1, BST<T> s2)
    {
        s2.add(s1.data);
        populate(s1.left, s2);
        populate(s1.right, s2);
        return s2;
    }
};
} // namespace set
#endif //SBE201_WORDCOUNT_MAPS_Set_HPP
