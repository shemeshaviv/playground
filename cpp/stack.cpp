#include <iostream>
#include <cassert>

using namespace std;

struct Node
{
    Node(int newItem)
    {
        _item = newItem;
    }
    int _item;
    Node* _next;
};

class Stack
{
    private:
    Node* _top;
    public:
    Stack()
    {
        cout << "CTOR - Empty stack" << endl;
        _top = nullptr;
    }

    ~Stack()
    {
        Node* current = _top;
        Node* node_to_delete;
        while(current != nullptr)
        {
            node_to_delete = current;
            current = current->_next;
            delete node_to_delete;
        }
    }

    bool isEmpty()
    {
        return (_top == nullptr)? true: false;
    }

    void push(int newItem)
    {
        Node* newNode = new Node(newItem);
        if(isEmpty())
            _top = newNode;
        else
        {
            Node* oldTop = _top;
            _top = newNode;
            _top->_next = oldTop;
        }
        cout << "Pushed item " << newItem << endl;
    }

    int pop()
    {
       Node* poped;
       assert(!isEmpty() && "Stack is empty");
       poped = _top;
       _top = _top->_next;
       return poped->_item;
    }

    void print()
    {
        cout << "(top) -> ";
        Node* current = _top;
        while(current != nullptr)
        {
            cout << current->_item << " -> ";
            current = current->_next;
        }
        cout << "(bottom)" << endl;
    }

};

int main()
{
    cout << "Stack tutorial" << endl;
    Stack stack;
    stack.push(1);
    stack.print();
    stack.push(2);
    stack.print();
    stack.push(3);
    stack.print();
    cout << "Poped the top: " << stack.pop() << endl;
    stack.print();
    return 0;
}
