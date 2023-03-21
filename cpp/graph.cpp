#include <iostream>
#include <vector>
using namespace std;

int cycles = 0;

void addDirectedEdge(vector<int> graph[], int source, int dest)
{
    graph[source].push_back(dest);
}

void printGraph(vector<int> graph[], int SIZE)
{
    for(int i=0; i < SIZE; i++)
    {
       cout << "Node (" << i << ")->";
       for(int adj : graph[i])
           cout << "(" << adj << ")->";
       cout << "|" << endl;
    }
}

bool nodeWasTraversed(vector<int> &traversed, int verified_node)
{
    for(int existing_traversed_node : traversed)
       if(existing_traversed_node == verified_node)
           return true;
    return false;
}

void traverseGraph(vector<int> graph[], int root, vector<int> &traversed)
{
    cout << "> Adding (" << root << ") to traversed list" << endl;
    traversed.push_back(root);
    for(int adj : graph[root])
    {
        cout << "    Traveling to (" << adj << ")" << endl;
        if(nodeWasTraversed(traversed, adj))
        {
            cout << "        Adj " << adj << " was traversed. Increasing cycles" << endl;
            cycles++;
        }
        else
            traverseGraph(graph, adj, traversed);
    }
}

/***  Proposed graph:

      (0)->(1)->(2)->(4)->(5)
        \       |     | \  |
         --(3)<-+-----+  +-+
***/

int main()
{
    int N = 6;   // Amount of nodes
    vector<int> graph[N];
    addDirectedEdge(graph, 0, 1);   // (0)->(1)
    addDirectedEdge(graph, 1, 2);   // (1)->(2)
    addDirectedEdge(graph, 2, 3);   // (2)->(3)
    addDirectedEdge(graph, 2, 4);   // (2)->(3)->(4)
    addDirectedEdge(graph, 3, 0);   // (3)->(0)
    addDirectedEdge(graph, 4, 3);   // (4)->(3)
    addDirectedEdge(graph, 4, 5);   // (4)->(3)->(5)
    addDirectedEdge(graph, 5, 4);   // (5)->(4)
    cout << "Graph represented by adjacency list:" << endl;
    printGraph(graph, N);

    vector<int> traversed;

    traverseGraph(graph, 0, traversed);
    cout << "Amount of cycles in graph: " << cycles << endl;
    return 0;
}
