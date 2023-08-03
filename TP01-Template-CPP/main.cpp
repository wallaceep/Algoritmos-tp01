#include <iostream>
#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    int numCity, numRoad, originCity, destinyCity, distance, dijkstra;

    // leitura do numero de vertices e arestas
    cin >> numCity >> numRoad;

    // Inicializa o grafo com a matriz de adjacencia do tamanho da quantidade de vértices
    Graph graph(numCity);

    // Armazena no grafo original os vértices de origem, destino e peso das arestas,
    // desde que a aresta entre os vértices seja par
    for(int i=0; i<numRoad; i++){
        cin >> originCity >> destinyCity >> distance;
        originCity--; destinyCity--;
        if(distance % 2 == 0)
            graph.addEdge(originCity, destinyCity, distance);
    }

    // Constrói um novo grafo bipartido a partir do original
    graph.newGraph();

    // Roda o dijsktra no grafo bipartido e recebe o valor da distancia de menor peso
    dijkstra = graph.dijkstra(2*numCity-2);

    // Se a distancia de menor peso existe, é impressa, senão, é impresso "-1"
    if (dijkstra == INF)
        cout << "-1" << endl;
    else
        cout << dijkstra << endl;

    return 0;
}