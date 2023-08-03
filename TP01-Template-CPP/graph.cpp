#include "graph.hpp"
#include <iostream>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f

// Construtor do grafo original
Graph::Graph(int num_vertices) {
    this->numVertices = num_vertices;
    adjList.resize(numVertices);
}

// Adiciona os vértices de origem, destino e o peso da aresta na lista de adjacencia (e faz o 
// inverso porque o grafo é não direcionado)
void Graph::addEdge(int origin, int destiny, int distance){
    adjList[origin].push_back(make_pair(destiny, distance));
    adjList[destiny].push_back(make_pair(origin, distance));
}

// Cria a lista de adjacencia do grafo bipartido a partir do grafo original, 
void Graph::newGraph(){
        adjListBipartite.resize(numVertices*2);
        for (int u = 0; u < numVertices; u++) {
            for (auto e : adjList[u]) {
                int v = e.first;
                int w = e.second;
                adjListBipartite[2*u].push_back(make_pair(2*v+1, w)); // (u0, v1)
                adjListBipartite[2*u+1].push_back(make_pair(2*v, w)); // (u1, v0)
                adjListBipartite[2*v].push_back(make_pair(2*u+1, w)); // (v0, u1)
                adjListBipartite[2*v+1].push_back(make_pair(2*u, w)); // (v1, u0)
            }
    }
}

int Graph::dijkstra(int destino) {
    // Cria um vetor de distâncias e um vetor de visitados
    vector<int> dist(numVertices*2, INF);
    vector<bool> visitado(numVertices*2, false);

    // Define a distância da origem para si mesmo como 0
    dist[0] = 0;

    // Cria uma fila de prioridades para armazenar os vértices a serem visitados
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Adiciona a origem à fila de prioridades
    pq.push(make_pair(dist[0], 0));

    while (!pq.empty()) {
        // Remove o vértice com menor distância da fila de prioridades
        int u = pq.top().second;
        pq.pop();

        // Se o vértice removido não foi visitado ainda, é marcado como visitado e a distância 
        // para seus vizinhos é atualizada
        if (!visitado[u]) {
            visitado[u] = true;
            for (auto i = adjListBipartite[u].begin(); i != adjListBipartite[u].end(); i++) {
                int v = i->first;
                int peso = i->second;
                if (dist[v] > dist[u] + peso) {
                    dist[v] = dist[u] + peso;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    return dist[destino];
}