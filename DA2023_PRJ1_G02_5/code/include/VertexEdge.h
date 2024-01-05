#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <utility>

#include "Station.h"
#include "NetworkSegment.h"

using namespace std;

class Edge;

#define INF numeric_limits<int>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    explicit Vertex(Station station);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;
    vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    vector<Edge *> getIncoming() const;

    void setStation(Station _station);
    void setVisited(bool _visited);
    void setProcesssing(bool _processing);
    void setIndegree(unsigned int _indegree);
    void setDist(double _dist);
    void setPath(Edge *_path);
    Edge * addEdge(Vertex *d, const int& capacity, const SERVICE_ENUM& service, double w);
    bool removeEdge(const string& destStation);

protected:
    Station station;              // station the vertex represents
    vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree = 0; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, const int& capacity, const SERVICE_ENUM& service, double w);

    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    int getCapacity() const;
    SERVICE_ENUM getService() const;
    Edge *getReverse() const;
    int getFlow() const;
    int remainingCapacity() const;
    void augment(int bottleneck);

    void setSelected(bool _selected);
    void setReverse(Edge *_reverse);
    void setFlow(double _flow);
    void setWeight(double _weight);
protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    NetworkSegment segment; // segment object that actually holds the

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    int flow = 0; // for flow-related problems
};