#include <iostream>
#include <cassert>

using namespace std;

struct Node
{
    Node(int item)
    {
        _item = item;
        _next = nullptr;
    }
    int _item;
    Node* _next;
};

class Queue
{
    private:
    Node* _head;
    Node* _tail;

    public:
    Queue()
    {
        _head=nullptr;
        _tail=nullptr;
        cout << "Queue CTOR. Empty Queue"<<endl;
    }

    ~Queue()
    {
        Node* current = _head;
        Node* existed_node;
        while(current != nullptr)
        {
            existed_node = current;
            current = current->_next;
            delete existed_node;
        }
    }

    bool isEmpty()
    {
        if(_head == nullptr)
            return true;
        else
            return false;
    }

    void enqueue(int item)
    {
        Node* node = new Node(item);
        if(isEmpty())
        {
            _head = node;
            _tail = node;
        }
        else
        {
            _tail->_next = node;
            _tail = node;
        }
        cout << "Enqueued " << item << endl;
    }

    void dequeue()
    {
        assert(!isEmpty() && "Queue is Empty");
        int _value = _head->_item;
        _head = _head->_next;
        cout << "Dequeued from head (" << _value << ")" << endl;
    }

    void print()
    {
        Node* current = _head;
        while(current != nullptr)
        {
            cout << current->_item << " <- ";
            current = current->_next;
        }
        cout << "(nullptr)" << endl;
    }
};

int main()
{
    cout << "Beginning a Queue Tutorial!" << endl;
    Queue queue;
    queue.print();
    queue.enqueue(1);
    queue.print();
    queue.enqueue(2);
    queue.print();
    queue.enqueue(3);
    queue.print();
    queue.dequeue();
    queue.print();
    return 0;
}
