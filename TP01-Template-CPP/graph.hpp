#ifndef GRAPH_HPP
#define GRAPH_HPP

const int MAX = 1e3;

#include <vector>

using namespace std;

class Graph {
    public:
        Graph(int num_vertices);
        int numVertices;
        vector<vector<pair<int,int>>> adjList;
        vector<vector<pair<int,int>>> adjListBipartite;
        void addEdge(int origin, int destiny, int distance);
        void newGraph();
        int dijkstra(int x);
};

#endif // GRAPH_HPP