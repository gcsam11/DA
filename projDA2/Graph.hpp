#pragma once

#include <vector>
#include <limits>
#include "Algorithms.hpp"

#define INFINITY_FLOAT numeric_limits<float>::max()

using namespace std;

struct Node {
    int index = -1;
    double longitude = INFINITY_FLOAT, latitude = INFINITY_FLOAT;
};

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

class Graph {
    public:
        Graph();
        explicit Graph(const int& _numOfNodes);

        [[nodiscard]] int getNumOfNodes() const;
        [[nodiscard]] vector<Node> getNodes() const;
        [[nodiscard]] vector<vector<float>> getAdjMatrix() const;

        void resizeStructures(const int& _numOfNodes);

        void addNode(const Node& node);
        void addEdge(const int& nodeA, const int& nodeB, const float& distance);

        vector<vector<float>> primFullyConnected(int s, vector<bool> &visited);
        vector<vector<float>> primNotFullyConnected(int s, vector<bool> &visited);
        double calcPathValue(vector<int> path);

private:
        int numOfNodes {};
        vector<Node> nodes;
        vector<vector<float>> adjMatrix;
};
