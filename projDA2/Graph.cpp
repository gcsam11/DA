#include "Graph.hpp"

Graph::Graph() = default;

Graph::Graph(const int& _numOfNodes) : numOfNodes(_numOfNodes) {
    resizeStructures(_numOfNodes);
}

int Graph::getNumOfNodes() const {
    return numOfNodes;
}

vector<vector<float>> Graph::getAdjMatrix() const {
    return adjMatrix;
}

vector<Node> Graph::getNodes() const {
    return nodes;
}

void Graph::resizeStructures(const int &_numOfNodes) {
    numOfNodes = _numOfNodes;

    nodes.reserve(_numOfNodes);

    adjMatrix.resize(_numOfNodes);

    for (vector<float>& row : adjMatrix) {
        row.resize(_numOfNodes, INFINITY_FLOAT);
    }
}

/**
 * Function adds an edge to a graph, given the source and destination nodes, and the distance between them.
 * Temporal complexity O(1).
 */
void Graph::addEdge(const int& nodeA, const int& nodeB, const float& distance) {
    adjMatrix[nodeA][nodeB] = distance;
    adjMatrix[nodeB][nodeA] = distance;
}

/**
 * Function adds a node with a given content or info (in) to a graph (this).
 * Temporal complexity O(1).
 */
void Graph::addNode(const Node &node) {
    nodes.push_back(node);
}
  
/**
* Function creates a minimum spanning tree for graphs that are not fully connected.
* Temporal complexity O((V+E)*log(V)).
* @param s int that stores the index of the current node being visited.
* @param visited vector that for each node has a bool to check if it was already visited or not.
* @return Returns matrix of distances between pair of nodes of the minimum spanning tree.
*/
vector<vector<float>> Graph::primNotFullyConnected(int s, vector<bool> &visited) {
    vector<vector<float>> newAdjMatrix;

    newAdjMatrix.resize(getNumOfNodes());

    for (vector<float>& row : newAdjMatrix) {
        row.resize(getNumOfNodes(), INFINITY_FLOAT);
    }
    visited[s] = true;
    priority_queue<Edge> pq;
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (i != s) {
            if(adjMatrix[s][i] == INFINITY_FLOAT){pq.push(Edge(s, i, Algorithms::haversineDistance(nodes[s].latitude, nodes[s].longitude, nodes[i].latitude, nodes[i].longitude)));}
            else{pq.push(Edge(s, i, adjMatrix[s][i]));}
        }
    }
    int mst_cost = 0;
    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (visited[e.v]) continue;
        visited[e.v] = true;
        mst_cost += e.w;
        newAdjMatrix[e.u][e.v] = e.w; newAdjMatrix[e.v][e.u] = e.w;
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (!visited[i]){
                if(adjMatrix[e.v][i] == INFINITY_FLOAT){pq.push(Edge(e.v, i, Algorithms::haversineDistance(nodes[e.v].latitude, nodes[e.v].longitude, nodes[i].latitude, nodes[i].longitude)));}
                else{pq.push(Edge(e.v, i, adjMatrix[e.v][i]));}
            }
        }
    }
    return newAdjMatrix;
}

/**
* Function creates a minimum spanning tree for fully connected graphs.
* Temporal complexity O((V+E)*log(V)).
* @param s int that stores the index of the current node being visited.
* @param visited vector that for each node has a bool to check if it was already visited or not.
* @return Returns matrix of distances between pair of nodes of the minimum spanning tree.
*/
vector<vector<float>> Graph::primFullyConnected(int s, vector<bool> &visited) {
    vector<vector<float>> newAdjMatrix;

    newAdjMatrix.resize(getNumOfNodes());

    for (vector<float>& row : newAdjMatrix) {
        row.resize(getNumOfNodes(), INFINITY_FLOAT);
    }


    visited[s] = true;
    priority_queue<Edge> pq;
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (i != s) {
            if(adjMatrix[s][i] == INFINITY_FLOAT){continue;}
            else{pq.push(Edge(s, i, adjMatrix[s][i]));}
        }
    }

    double mst_cost = 0;
    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (visited[e.v]) continue;
        visited[e.v] = true;
        mst_cost += e.w;
        newAdjMatrix[e.u][e.v] = e.w; newAdjMatrix[e.v][e.u] = e.w;
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (!visited[i]){
                if(adjMatrix[e.v][i] == INFINITY_FLOAT){continue;}
                else{pq.push(Edge(e.v, i, adjMatrix[e.v][i]));}
            }
        }
    }
    return newAdjMatrix;
}

/**
* Function calculates the distance travelled in the path received.
* Temporal complexity O(n).
* @param path vector which holds the path traversed in preorder of the previously created minimum spanning tree.
* @return Returns the distance traveled while traversing the path given.
*/
double Graph::calcPathValue(vector<int> path) {
    double mst_cost = 0.0;
    for(int i = 0; i < path.size() - 1; i++){
        if(adjMatrix[path[i]][path[i+1]] == INFINITY_FLOAT){mst_cost += Algorithms::haversineDistance(nodes[path[i]].latitude, nodes[path[i]].longitude, nodes[path[i+1]].latitude, nodes[path[i+1]].longitude);}
        else{mst_cost += adjMatrix[path[i]][path[i+1]];}
    }

    if(adjMatrix[0][path.back()] == INFINITY_FLOAT){mst_cost += Algorithms::haversineDistance(nodes[0].latitude, nodes[0].longitude, nodes[path.back()].latitude, nodes[path.back()].longitude);}
    else{mst_cost += adjMatrix[0][path.back()];}

    return mst_cost;
}
