// Exercise 4: Implement a sorted linked-list - header file
//

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

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
        Node* _root;

};
#endif

