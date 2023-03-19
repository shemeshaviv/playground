// Exercise 5: Implement a linked-list with smart-pointers
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include "linkedlist2.h"

using namespace std;

struct Node
{
    Node(int i): item{i}, next{nullptr}
    {
         cout << "//Node C'tor initialized with " << i << endl;
    }
    int item;
    shared_ptr<Node> next;
};

LinkedList::LinkedList() : _root{nullptr}
{
    cout << "//Default C'tor\n";
}

LinkedList::LinkedList(int i) : _root{new Node{i}}
{
    cout << "//LinkedList C'tor initalized with " << i << endl;
}

LinkedList::~LinkedList()
{
    cout << "//Destructing item" << endl;
}

void LinkedList::addItem(int new_value)
{
    shared_ptr<Node> node = make_shared<Node>(new_value);
    node->next = _root;
    _root = node;
}

void LinkedList::print()
{
    shared_ptr<Node> current = _root;
    while (current != nullptr)
    {
        cout << current->item << " -> ";
        current = current->next;
    }
    cout << "(nullptr)\n";
}

bool LinkedList::exists(int i)
{
    shared_ptr<Node> current = _root;
    while (current != nullptr)
    {
        if (current->item == i) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::removeItem(int i)
{
    while(_root!=nullptr and _root->item == i)   // item is the first one or several items in the beginning of the list
    {
        shared_ptr<Node> old_root = _root;
        _root = _root->next;
        //delete old_root;
    }
    shared_ptr<Node> current = _root;
    shared_ptr<Node> previous = current;
    while (current != nullptr)
    {
        if (current->item == i)
        {
            previous->next = current->next;
            //delete current;
            current = previous->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

int main()
{
    cout << "\n====================== PART I: Adding items to linked-list ======================\n";
    LinkedList ll1;
    ll1.print();
    ll1.addItem(7);
    ll1.print();
    ll1.addItem(4);
    ll1.print();
    ll1.addItem(11);
    ll1.print();
    ll1.addItem(10);
    ll1.print();
    ll1.addItem(15);
    ll1.print();     // output should be: 4 -> 7 -> 10 -> 11 -> 15 -> (nullptr)

    cout << "\n====================== PART II: Checking if items exists  ======================\n";
    vector<int> numbers = {4,8,10,15};
    for(int number : numbers) {
        if (ll1.exists(number)) {
            cout << "Item " << number <<" exists!\n";
        }
        else {
            cout << "Item "<<number << " doesn't exists!\n";
        }
    }

    cout << "\n====================== PART III: Removing items  ======================\n";
    cout << "Removing 11\n";
    ll1.removeItem(11);
    ll1.print();   // output should be: 4 -> 7 -> 10 -> 15 -> (nullptr)
    cout << "Removing 4\n";
    ll1.removeItem(4);
    ll1.print();   // output should be: 7 -> 10 -> 15 -> (nullptr)
    cout << "Removing 15\n";
    ll1.removeItem(15);
    ll1.print();   // output should be: 7 -> 10 -> (nullptr)

    cout << "\n====================== PART IV: Adding repeating items  ======================\n";
    LinkedList ll2{2};
    ll2.print();     // output should be: 2 -> (nullptr)
    ll2.addItem(3);
    ll2.print();     // output should be: 2 -> 3 -> (nullptr)
    ll2.addItem(1);
    ll2.print();     // output should be: 1 -> 2 -> 3 -> (nullptr)
    ll2.addItem(2);  // Test repeating item
    ll2.print();     // output should be: 1 -> 2 -> 2 -> 3 -> (nullptr)
    cout << "Removing 2\n";
    ll2.removeItem(2);
    ll2.print();     // output should be: 1 -> 3 -> (nullptr)

    cout << "\n====================== PART V: Adding and deleting a single item in the list  ======================\n";
    LinkedList ll3;
    ll3.addItem(8);
    ll3.removeItem(8);

    cout << "\n====================== PART VI: Deleting the first repetative item in the list  ======================\n";
    LinkedList ll4;
    ll4.addItem(10);
    ll4.addItem(10);
    ll4.addItem(20);
    ll4.addItem(30);
    ll4.print();
    ll4.removeItem(10);
    ll4.print();

    cout << "\n====================== PART VII: Trying to remove items that doesn't exist in the list  ======================\n";
    cout << "Removing 15\n";
    ll4.removeItem(15);
    ll4.print();

    cout << "Removing 25\n";
    ll4.removeItem(25);
    ll4.print();

    cout << "\n====================== PART VIII: Trying to remove from an empty list  ======================\n";
    LinkedList ll5;
    ll5.removeItem(7);
    return 0;
}

