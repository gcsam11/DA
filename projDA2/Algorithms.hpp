#pragma once

#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <random>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "Graph.hpp"

using namespace std;

class Algorithms {
    public:
        static void backtrackingTsp(const vector<vector<float>>& distances, vector<bool>& visited, vector<int>& solution, vector<int>& currTour,
                                    const int& currPos, const int& n, const int& count, const float& currCost, float& solCost);

        static vector<int> customTspHeuristic(const vector<vector<float>>& distances, const float& clusteringEpsilon, const int& clusteringMinPts, float& cost);

        static void dfs(int u, vector<vector<float>> &adjMatrix, vector<bool> &visited, vector<int> &preorder);

        static double haversineDistance(double lat1, double lon1, double lat2, double lon2);

        static vector<vector<int>> clusteringDBSCAN(const vector<vector<float>>& distances, const float& epsilon, const int& minPts, vector<int>& outliers);

        static vector<int> nearestNeighborTSP(const int& initialCity, const vector<vector<float>>& distances, float& tourCost, const vector<int>& cluster = {});

        static void twoOpt(vector<int>& tour, float& cost, const vector<vector<float>>& distances);

        static vector<int> multiStartTwoOptNearestNeighbor(float& cost, const vector<vector<float>>& distances, const int& numOfStarts, const vector<int>& cluster = {});

        static vector<int> findClustersRepresentatives(const vector<vector<int>>& clusters, const vector<vector<float>>& distances);

        static void clusteringCalibrator(const vector<vector<float>>& distances, const int& minPtsFirst, const int& minPtsLast, const int& minPtsIncrement, const int& epsilonFirst, const int& epsilonLast, const int& epsilonIncrement);

        static double getClusteringScore(const vector<vector<int>>& clusters);

        static vector<vector<int>> getClosePointsList(const vector<vector<float>>& distances, const float& epsilon);

        static void expandCluster(const vector<vector<int>>& closePointsList, vector<int>& cluster, const int& cityIndex, const int& minPts, vector<bool>& visited);

        static int findNearestNeighbor(const int& city, const vector<vector<float>>& distances, vector<bool>& visited, const vector<int>& cluster);

        static vector<int> generateRandomNonRepeatingInts(int max, int count);

        static int getClusterRepresentative(const vector<int>& cluster, const vector<vector<float>>& distances);

private:
        static constexpr double PI = 3.14159265358979323846;
        static constexpr double EARTH_RADIUS = 6371000.0; //In meters

        static constexpr double toRadians(double degrees);

};
