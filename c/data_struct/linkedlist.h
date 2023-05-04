struct LinkedList;
typedef struct LinkedList* Node;
Node createNode(int value);
Node addNode(Node root, int value);
Node addNodeSorted(Node root, int value);
Node removeNode(Node root, int value);
void printLinkedList(Node root);
