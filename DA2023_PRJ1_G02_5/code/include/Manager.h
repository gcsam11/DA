#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <utility>
#include <set>

#include "../include/Graph.h"
#include "../include/CsvLine.h"
#include "../include/CsvReader.h"
#include "../include/Design.h"

using namespace std;

class Manager {
public:
    void run(bool isFlowGraph = false);
    void maxTrainsBetweenStations();
    void busiestPairsOfStations();
    void busiestMunisAndDist();
    void maxTrainsBetweenStationsWithMinCost();
    Graph generateSubGraph(vector<pair<string, int>> &countFails);
    void addFailCount(const string& start, const string& finish, vector<pair<string, int>> &countFails);
    static bool compare(const pair<string, int>& Start, const pair<string, int>& Finish);
    void maxSimultaneousTrainsToAStation();
    void prepareSubGraphMaxFlow(string &stationA, string &stationB);

private:
    static void cinReset();
    static string clearString(string str);
    void readStations();
    void readNetwork(bool isFlowGraph);
    void createNetworkGraph(bool isFlowGraph);
    void executionManager();

    Graph networkGraph;
    unordered_map<string, Station> stationsMap;
    unordered_map<string, unordered_map<string, vector<Station>>> districtMap;
};