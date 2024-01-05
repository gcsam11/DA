#include "../include/Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/**
 * Temporal complexity O(V).
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const string& stationName) const {
    for (auto v : vertexSet)
        if (v->getName() == stationName)
            return v;
    return nullptr;
}

/**
 * Temporal complexity O(V).
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const string& stationName) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getName() == stationName)
            return i;
    return -1;
}
/**
 *  Temporal complexity O(V).
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const Station& station) {
    if (findVertex(station.getName()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(station));
    return true;
}

/**
 * Temporal complexity O(V).
 * Adds an edge to a graph (this), given the contents of the source and destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM& service, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, capacity, service, w);
    return true;
}

/**
 * Temporal complexity O(E).
 * Removes an edge from the Vertex's adjacency list.
 * @param start represents the vertex we want to remove the edge from.
 * @param finish represents the edge we want to remove.
 */
void Graph::removeEdge(Vertex *start, Edge *finish) {
    vector<Edge*> adj = start->getAdj();
    for(auto pop = adj.begin(); pop != adj.end(); pop++){
        if(*pop = finish){
            adj.erase(pop);
            pop--;
        }
    }
}

bool Graph::addBidirectionalEdge(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM& service, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, capacity, service, w);
    auto e2 = v2->addEdge(v1, capacity, service, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

// For max-flow problems
bool Graph::addEdgeAndResidual(const string &sourc, const string &dest, const int& capacity, const SERVICE_ENUM &service, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, capacity, service, w);
    auto e2 = v2->addEdge(v1, 0, service, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

/**
 * Temporal complexity O(V).
 * Resets every vertex's visited and path values.
 */
void Graph::resetVisitedAndPath() {
    for (Vertex* vertex : vertexSet) {
        vertex->setVisited(false);
        vertex->setPath(nullptr);
    }
}

/**
 * Temporal Complexity O(E).
 * Resets the edges flow and their reverses back to 0.
 * @param edges is a vector of Edges.
 */
void Graph::resetFlow(const vector<Edge*>& edges) {
    for (Edge* edge : edges) {
        edge->setFlow(0);
        edge->getReverse()->setFlow(0);
    }
}

/**
 * Temporal Complexity O(V*E^2)
 * @param srcName is the source, represented by the starting station's name.
 * @param sinkName is the sink, represented by the destiny station's name.
 * @return the max flow between the source and the sink.
 */
int Graph::maxFlow(const string &srcName, const string &sinkName) {
    Vertex* src = findVertex(srcName);
    Vertex* sink = findVertex(sinkName);
    vector<Edge*> usedEdges;
    int maxFlow = 0;
    int currFlow;

    do {
        resetVisitedAndPath();
        currFlow = maxFlowBfs(src, sink, usedEdges);
        maxFlow += currFlow;

    } while (currFlow != 0);

    resetFlow(usedEdges);

    return maxFlow;
}

/**
 * Temporal Complexity O(V + E).
 * @param src represents our source.
 * @param sink represents our sink.
 * @param edgesToReset is a vector of Edges that are going to be reset at some point in the function.
 * @return the current flow between the source and the sink.
 */
int Graph::maxFlowBfs(Vertex* src, Vertex* sink, vector<Edge*>& edgesToReset) {
    queue<Vertex*> q;
    src->setVisited(true);
    q.push(src);

    while (!q.empty()) {
        Vertex* currNode = q.front();
        q.pop();
        if (currNode == sink) break;

        for (Edge* edge : currNode->getAdj()) {
            int cap = edge->remainingCapacity();
            if (cap > 0 && !edge->getDest()->isVisited()) {
                edge->getDest()->setVisited(true);
                edge->getDest()->setPath(edge);
                q.push(edge->getDest());
            }
        }
    }

    if (sink->getPath() == nullptr) return 0;

    int bottleNeck = INF;
    for (Edge* edge = sink->getPath(); edge != nullptr; edge = edge->getOrig()->getPath()) {
        bottleNeck = min(bottleNeck, edge->remainingCapacity());
    }

    for (Edge* edge = sink->getPath(); edge != nullptr; edge = edge->getOrig()->getPath()) {
        edge->augment(bottleNeck);
        edgesToReset.push_back(edge);
    }

    return bottleNeck;
}

/**
 * Prints the minimum cost path between 2 stations.
 * @param srcName is our starting station.
 * @param sinkName is our finishing station.
 * @param shortestDistances stores the shortest distance of a station to the source.
 * @param parents stores the parent of a station as a string.
 */
void Graph::printPath(const string &srcName, const string &sinkName, unordered_map<string, double> shortestDistances, unordered_map<string, string> parents) {
    if (sinkName == srcName) {
        cout << "\n" << "Station\t\t\t\t\t Cost\n" << endl;
        cout << srcName << "\t\t\t\t\t" << 0 << endl;
        return;
    }
    printPath(srcName, parents[sinkName], shortestDistances, parents);
    cout << sinkName << "\t\t\t\t\t" << shortestDistances[sinkName] << endl;
}

/**
 * Temporal complexity O(n).
 * This method will calculate the maximum flow for the minimum cost path.
 * @param srcName is our starting station.
 * @param sinkName is our finishing station.
 * @param parents is a map storing each station's parent.
 * @param edges_cap is storing each edges capacity along with the end station of that edge.
 */
void Graph::printMaxFlow(const string &srcName, const string &sinkName, unordered_map<string, string> parents, unordered_map <string, int> edges_cap) {
    int maxFlow = INT_MAX;

    for (string curr = sinkName; curr != srcName; curr = parents[curr]) {
        if (edges_cap[curr] < maxFlow) {maxFlow = edges_cap[curr];}
    }
    cout << "\n" << "Max Flow of this path: " << maxFlow << endl;
}

/**
 * Temporal complexity O(V + E).
 * This modified Dijkstra's algorithm will calculate the path with the minimum cost between 2 stations.
 * @param srcName is the starting station.
 * @param sinkName is the ending station.
 */
void Graph::dijkstraModif(const string &srcName, const string &sinkName) {
    Vertex* src = findVertex(srcName);
    Vertex* sink = findVertex(sinkName);
    unordered_map<string, double> shortestDistances(vertexSet.size());
    unordered_map<string, string> parents(vertexSet.size());
    unordered_map<string, int> edges_cap;

    for (Vertex* vertex : vertexSet) {
        vertex->setDist(std::numeric_limits<double>::max());
        vertex->setVisited(false);
    }
    src->setDist(0);
    parents[src->getName()] = "";
    set<pair<double, Vertex*>> q;
    q.insert({0, src});
    while(!q.empty()) {
        auto tmp = q.begin();
        Vertex* u = tmp->second;
        q.erase(tmp);
        u->setVisited(true);
        shortestDistances[u->getName()] = u->getDist();
        if (u->getName() == sinkName) {break;}
        for (auto edge : u->getAdj()) {
            edge->setWeight((edge->getService() == STANDARD) ? 2 : 4);
            double cost = edge->getWeight();
            Vertex* v = edge->getDest();
            if (!v->isVisited() && u->getDist() + cost < v->getDist()) {
                q.erase({v->getDist(), v});
                v->setDist(u->getDist() + cost);
                q.insert({v->getDist(), v});
                parents[v->getName()] = u->getName();
                edges_cap[v->getName()] = edge->getCapacity();
            }
        }
    }
    printPath(src->getName(), sink->getName(), shortestDistances, parents);
    printMaxFlow(src->getName(), sink->getName(), parents, edges_cap);
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}