#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <set>

#include "Csv.hpp"
#include "Design.hpp"
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;

class Manager {
public:
    Manager();

    void mainLoop();
    static void loadGraphFromCsv(Graph &graph, const bool& isToyGraph, const string &nodesCsvPath, const string &edgesCsvPath);
private:
    bool graphsLoaded = false;

    Graph toyGraphShipping;
    Graph toyGraphStadiums;
    Graph toyGraphTourism;
    Graph realGraph1;
    Graph realGraph2;
    Graph realGraph3;
    Graph edges_25;
    Graph edges_50;
    Graph edges_75;
    Graph edges_100;
    Graph edges_200;
    Graph edges_300;
    Graph edges_400;
    Graph edges_500;
    Graph edges_600;
    Graph edges_700;
    Graph edges_800;
    Graph edges_900;

    static void cinReset();
    static void goBackToMenu();
    static void goBackToTriangularMenu();
    void backTracking();
    static void backTrackingSingleGraph(const Graph& graph);
    void loadGraphs();
    void triangularApproximationSingleGraphFullyConnected(Graph& graph);
    void triangularApproximationSingleGraphNotFullyConnected(Graph& graph);

    static void loadGraphFromCsv(Graph &graph, const bool& isToyGraph, const bool& isExtraFullyConnectedGraph, const bool& isRealGraph, const string &nodesCsvPath, const string &edgesCsvPath);
};
