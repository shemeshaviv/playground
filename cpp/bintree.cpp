#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int _data;
    Node* _left;
    Node* _right;

    Node(int i) : _data{i}, _left{nullptr}, _right{nullptr}
    {
        cout << "Adding new node with data = " << i << endl;
    }
};

class BinaryTree
{
    private:
    Node* _root;

    public:
    BinaryTree() : _root{nullptr}
    {
    }

    BinaryTree(vector<int> vec) : _root{nullptr}
    {
        for(int i : vec)
            addNode(i);
    }

    ~BinaryTree()
    {
    }

    Node* addNode(Node* current,int data)
    {

        if(current == nullptr)
            return new Node(data);
        else // Traveling to the correct sub-tree location
        {
            if(data < current->_data)
                current->_left=addNode(current->_left, data);
            else
                current->_right=addNode(current->_right, data);
        }
        return current;
    }

    void addNode(int data)
    {
        _root = addNode(_root, data);
    }

    void traverseInorder(Node* current)
    {
        if(current==nullptr)
            return;
        traverseInorder(current->_left);
        cout << current->_data << " ";
        traverseInorder(current->_right);
    }

    void traverseInorder()
    {
        cout << "Traversing inorder: " << endl;
        traverseInorder(_root);
        cout << endl;
    }

    // Here is a different non-recursive method to insert a node to the proper location on the binary tree
    void addNodeNonRecursive(int data)
    {
        Node* newNode = new Node(data);
        if(_root == nullptr)
        {
            _root = newNode;
        }
        else
        {
            Node* parent;
            Node* current;
            current = _root;
            while(true)
            {
                parent = current;
                if(data < current->_data)
                {
                    current=current->_left;
                    if(current == nullptr)
                    {
                        parent->_left=newNode;
                        return;
                    }
                }
                else   // data >= current->_data
                {
                    current=current->_right;
                    if(current == nullptr)
                    {
                        parent->_right=newNode;
                        return;
                    }
                }
            }
        }
    }
};


int main()
{
    vector<int> vec = {50,25,75,12,37,43,30};
    BinaryTree tree(vec);
    tree.traverseInorder();
    return 0;
}
