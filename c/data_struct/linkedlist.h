struct NodeStruct;
struct LinkedListStruct;
typedef struct NodeStruct* Node;
typedef struct LinkedListStruct* LinkedList;
Node createNode(int value);
void addNode(LinkedList linkedlist, int value);
void addNodeSorted(LinkedList linkedlist, int value);
void removeNode(LinkedList linkedlist, int value);
void printLinkedList(LinkedList linkedlist);
