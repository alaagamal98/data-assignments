#ifndef SBE201_STACKS_QUEUES_ADT_HPP
#define SBE201_STACKS_QUEUES_ADT_HPP
#include <iostream>

namespace ADT
{
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T d, Node *nextt = nullptr)
    {
        data = d;
        next = nextt;
    }
};
template <typename T>
struct LL
{
private:
    Node<T> *head;

public:
    LL()
    {
        head = nullptr;
    }
    bool isEmpty() const
    {
        return (head == nullptr);
    }
    void insertFront(T data)
    {
        Node<T> *current;
        if (head == nullptr)
        {
            current = new Node<T>{data, nullptr};
        }
        else
        {
            current = new Node<T>{data, head};
        }
        head = current;
    }
    void insertBack(T data)
    {
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node<T>{data, nullptr};
    }
    void removeFront()
    {
        if (head != nullptr)
        {
            Node<T> *oldHead = head;
            head = head->next;
            delete oldHead;
        }
        else
        {
            return;
        }
    }
    void removeBack()
    {
        if (head != nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            Node<T> *current = head;
            delete current;
            head = nullptr;
        }
        else
        {
            Node<T> *current = head;
            Node<T> *previous;
            while (current->next != nullptr)
            {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            delete current;
        }
    }
    void removeNth(int index)
    {
        int count = 1;
        Node<T> *current = head;
        Node<T> *previous;
        while (count < index)
        {
            previous = current;
            current = current->next;
            ++count;
        }
        previous->next = nullptr;
        delete current;
    }
    T front() const
    {
        return head->data;
    }
    T back() const
    {
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->data;
    }
    T getNth(int index) const
    {
        int count = 1;
        Node<T> *current = head;
        while (count < index)
        {
            current = current->next;
            ++count;
        }
        return current->data;
    }
    int size() const
    {
        int count = 0;
        Node<T> *current = head;

        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
    void printAll() const
    {
        Node<T> *current = head;

        while (current != nullptr)
        {
            std::cout << current->data;
            current = current->next;
        }
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node<T> *oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }
};
template <typename T>
struct StackLL
{
private:
    Node<T> *front;

public:
    StackLL()
    {
        front = nullptr;
    }
    bool isEmpty() const
    {
        return (front == nullptr);
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data, front);
        front = newNode;
    }
    void pop()
    {
        if (front != nullptr)
        {
            Node<T> *oldFront = front;
            front = front->next;
            delete oldFront;
        }
        else
        {
            return;
        }
    }
    T frontt() const //I changed the function name to frontt instead of front because while compiling it conflicts with the node front.
    {
        return front->data;
    }
    int size() const
    {
        int count = 0;
        Node<T> *current = front;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
    void clear()
    {
        while (front != nullptr)
        {
            Node<T> *oldFront = front;
            front = front->next;
            delete oldFront;
        }
    }
};
template <typename T>
struct QueueLL
{
private:
    Node<T> *front;
    Node<T> *back;

public:
    QueueLL()
    {
        front = nullptr;
        back = nullptr;
    }
    bool isEmpty() const
    {
        return (back == nullptr);
    }
    void enqueue(T data)
    {
        if (back == nullptr)
        {
            back = new Node<T>(data, nullptr);
            front = back;
        }
        else
        {
            back->next = new Node<T>(data, nullptr);
            back = back->next;
        }
    }
    void dequeue()
    {
        if (back == nullptr)
        {
            return;
        }
        else
        {
            Node<T> *oldFront = front;
            front = front->next;
            delete oldFront;

            if( front == nullptr )
                back = nullptr;
        }
    }
    T frontt() const //I changed the function name to frontt instead of front because while compiling it conflicts with the node front.
    {
        return front->data;
    }
    int size() const
    {
        int count = 0;
        Node<T> *current = front;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
    void clear()
    {
        while (back != nullptr)
        {
            dequeue();
        }
    }
};

} // namespace ADT
#endif // SBE201_STACKS_QUEUES_DNA_HPP
