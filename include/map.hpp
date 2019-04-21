#ifndef SBE201_WORDCOUNT_MAPS_MAP_HPP
#define SBE201_WORDCOUNT_MAPS_MAP_HPP

#include <string>
#include <iostream>

namespace map
{

template <typename K, typename V>
struct MapNode
{
    MapNode(const K &k)
    {
        key = k;
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    K key;
    V value;
    MapNode *left;
    MapNode *right;
};

template <typename K, typename V>
struct Map
{
private:
    MapNode<K, V> *map;

public:
    Map()
    {
        map = nullptr;
    }
    bool isEmpty() const
    {
        return (map == nullptr);
    }

    bool isLeaf() const
    {
        return (map->left == nullptr && map->right == nullptr);
    }

    V size() const
    {
        return size(map);
    }

    bool find(K key) const
    {
        return find(map, key);
    }

    void insert(K key) const
    {
        insert(map, key);
    }

    MapNode<K, V> *minNode() const
    {
        return minNode(map);
    }

    void remove(K key)
    {
        remove(map, key);
    }

    V &value(K key)
    {
        return value(map, key);
    }

    void clear()
    {
        clear(map);
    }

    void printAll() const
    {
        printAll(map);
    }

private:
    static V size(const MapNode<K, V> *map)
    {
        if (map == nullptr)
        {
            return 0;
        }
        else
        {
            return (1 + size(map->left) + size(map->right));
        }
    }

    static bool find(const MapNode<K, V> *map, K key)
    {
        if (map == nullptr)
        {
            return false;
        }
        else if (map->key == key)
        {
            return true;
        }
        else if (key < map->key)
        {
            return find(map->left, key);
        }
        else
        {
            return find(map->right, key);
        }
    }

    static void insert(MapNode<K, V> *&map, K key)
    {
        if (map == nullptr)
        {
            map = new MapNode<K, V>(key);
        }
        else if (key < map->key)
        {
            insert(map->left, key);
        }
        else
        {
            insert(map->right, key);
        }
    }

    static MapNode<K, V> *minNode(MapNode<K, V> *map)
    {
        MapNode<K, V> *current = map;
        while (map->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    static void remove(MapNode<K, V> *&map, K key)
    {
        if (map == nullptr)
        {
            return;
        }
        if (key == map->key)
        {
            remove(map->left, key);
        }
        else if (key < map->key)
        {
            remove(map->left, key);
        }
        else
        {
            remove(map->right, key);
        }
    }

    static void removeNode(MapNode<K, V> *&map)
    {
        if (map->left != nullptr && map->right != nullptr)
        {
            MapNode<K, V> *minRight = minNode(map->right);
            map->data = minRight->data;
            remove(map->right, minRight->data);
        }
        else
        {
            MapNode<K, V> *discard = map;
            if (map->left == nullptr && map->right == nullptr)
            {
                map = nullptr;
            }
            else if (map->left != nullptr)
            {
                map = map->left;
            }
            else
            {
                map = map->right;
            }
            delete discard;
        }
    }
    static V &value(MapNode<K, V> *&map, K key)
    {
        if (map != nullptr)
        {
            MapNode<K, V> *current = map;
            if (current->key == key)
            {
                return current->value;
            }
            else if (key < current->key)
            {
                return value(current->left, key);
            }
            else
            {
                return value(current->right, key);
            }
        }
        else
        {
            insert(map, key);
            return map->value;
        }
    }
    static void clear(MapNode<K, V> *&map)
    {
        clear(map->left);
        clear(map->right);
        delete map;
        map = nullptr;
    }

    static void printAll(const MapNode<K, V> *map)
    {
        if (map)
        {
            printAll(map->left);
            std::cout << map->key << ":" << map->value << std::endl;
            printAll(map->right);
        }
    }
};
} // namespace map

#endif //SBE201_WORDCOUNT_MAPS_MAP_HPP
