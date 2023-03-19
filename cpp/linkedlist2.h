// Exercise 5: Implement a linked-list with smart-pointers - header file
//
#include <memory>
#ifndef __LINKEDLIST2_H__
#define __LINKEDLIST2_H__

struct Node;

class LinkedList
{
    public:
        LinkedList();
        LinkedList(int i);
        ~LinkedList();
        void addItem(int new_value);
        void print();
        bool exists(int i);
        void removeItem(int i);
    private:
        std::shared_ptr<Node> _root;

};
#endif

