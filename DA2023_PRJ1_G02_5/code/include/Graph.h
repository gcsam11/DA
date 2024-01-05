#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <climits>
#include <algorithm>
#include <unordered_map>

#include "VertexEdge.h"

using namespace std;

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const string& stationName) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const Station& station);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM& service, double w);
    void removeEdge(Vertex* start, Edge* finish);
    bool addBidirectionalEdge(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM& service, double w);
    bool addEdgeAndResidual(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM& service, double w);

    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;

    int maxFlow(const string &srcName, const string &sinkName);

    void printPath(const string &srcName, const string &sinkName, unordered_map<string, double> shortestDistances, unordered_map<string, string> parents);
    void printMaxFlow(const string &srcName, const string &sinkName, unordered_map<string, string> parents, unordered_map <string, int> edges_cap);
    void dijkstraModif(const string &srcName, const string &sinkName);

protected:
    vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const string& stationName) const;

    void resetFlow(const vector<Edge*>&);
    void resetVisitedAndPath();
    int maxFlowBfs(Vertex* src, Vertex* sink, vector<Edge*>& edgesToReset);
    //, const string &sinkName
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);