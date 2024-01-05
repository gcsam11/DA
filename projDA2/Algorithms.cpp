#include "Algorithms.hpp"

/**
* Function to convert degrees to radians.
* Temporal complexity O(1).
* @param degrees
* @return Returns a double value that is the conversion from to degrees to radians.
*/
constexpr double Algorithms::toRadians(double degrees) {
    return degrees * (PI / 180.0);
}

/**
* Function to calculate the distance between a pair of nodes.
* Temporal complexity O(1).
* @param lat1 double, receives the latitude from the node(1).
* @param lon1 double, receives the longitude from the node(1).
* @param lat2 double, receives the latitude from the node(2).
* @param lon2 double, receives the longitude from the node(2).
* @return Returns a double value that will be equal to the distance between the pair of nodes.
*/
double Algorithms::haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = toRadians(lat2 - lat1);
    double deltaLon = toRadians(lon2 - lon1);

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
               cos(toRadians(lat1)) * cos(toRadians(lat2)) *
               sin(deltaLon / 2) * sin(deltaLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = EARTH_RADIUS * c;
    return distance;
}
/**
* Function that performs backtracking through the graph and stores the best path in a vector.
* Temporal complexity O(n!).
* @param distances matrix that stores the distance between a pair of nodes.
* @param visited vector that for each node has a bool to check if it was already visited or not.
* @param solution vector that receives the final path.
* @param currTour vector that holds the path that the algorithm is traversing currently.
* @param currPos int that stores the index of the current node being visited.
* @param n int that receives the total number of nodes in the graph.
* @param count int keeps track of how many nodes have been traversed already.
* @param currCost float that holds the cost to traverse between the previous node and the current one.
* @param solCost float that stores the smallest cost.
*/
void Algorithms::backtrackingTsp(const vector<vector<float>>& distances, vector<bool>& visited, vector<int>& solution, vector<int>& currTour,
                                 const int& currPos, const int& n, const int& count, const float& currCost, float& solCost) {
    if ((count == n) && (distances[currPos][0] != INFINITY_FLOAT)) {
        float smallest = min(solCost, currCost + distances[currPos][0]);
        if (smallest < solCost) {
            solCost = smallest;
            solution = currTour;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distances[currPos][i] != INFINITY_FLOAT) {
            visited[i] = true;
            currTour.push_back(i);

            backtrackingTsp(distances, visited, solution, currTour, i, n, count + 1, currCost + distances[currPos][i], solCost);

            currTour.pop_back();
            visited[i] = false;
        }
    }
}

/**
 * This function finds the nearest neighbour to the city parameter.
 * Time Complexity O(N), where N is the size of cluster vector (or distances, if the cluster vector is empty).
 * @param city current place.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param visited vector that for each node has a bool to check if it was already visited or not.
 * @param cluster auxilary vector to reduce nearest neighbour search time.
 * @return Returns the nearest neighbour.
 */
int Algorithms::findNearestNeighbor(const int& city, const vector<vector<float>>& distances, vector<bool>& visited, const vector<int>& cluster) {
    int nearestNeighbor = -1;
    float shortestDistance = INFINITY_FLOAT;

    if (cluster.empty()) {
        for (int i = 0; i < distances.size(); i++) {
            if (i != city && !visited[i] && distances[city][i] < shortestDistance) {
                nearestNeighbor = i;
                shortestDistance = distances[city][i];
            }
        }
    } else {
        for (const int& index : cluster) {
            if (index != city && !visited[index] && distances[city][index] < shortestDistance) {
                nearestNeighbor = index;
                shortestDistance = distances[city][index];
            }
        }
    }

    return nearestNeighbor;
}

/**
 * This function returns the shortest path that starts and ends in the same city.
 * Time Complexity O(N^2), where N represents the number of cities in the cluster vector (or distances, if cluster is empty).
 * @param initialCity starting place.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param tourCost current cost of the path.
 * @param cluster auxilary vector to reduce nearest neighbour search time.
 * @return Returns a vector of cities that represent a path.
 */
vector<int> Algorithms::nearestNeighborTSP(const int& initialCity, const vector<vector<float>>& distances, float& tourCost, const vector<int>& cluster) {
    int numCities = cluster.empty() ? static_cast<int>(distances.size()) : static_cast<int>(cluster.size());
    vector<bool> visited(distances.size());
    vector<int> path;

    visited[initialCity] = true;
    path.push_back(initialCity);

    int currentCity = initialCity;
    while (path.size() < numCities) {
        int nearestNeighbor = findNearestNeighbor(currentCity, distances, visited, cluster);
        visited[nearestNeighbor] = true;
        path.push_back(nearestNeighbor);
        tourCost += distances[currentCity][nearestNeighbor];
        currentCity = nearestNeighbor;
    }

    tourCost += distances[currentCity][initialCity];
    path.push_back(initialCity);

    return path;
}

/**
 * Function to optimize edge distances.
 * Time Complexity O(N^2), where N is the size of the tour vector.
 * @param tour vector that
 * @param cost path cost.
 * @param distances matrix that stores the distance between a pair of nodes.
 */
void Algorithms::twoOpt(vector<int>& tour, float& cost, const vector<vector<float>>& distances) {
    int n = static_cast<int>(tour.size());

    int improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n - 1; j++) {
                int src1 = tour[i];
                int dest1 = tour[i+1];

                int src2 = tour[j];
                int dest2 = tour[j+1];

                float oldEdgeCost = distances[src1][dest1] + distances[src2][dest2];
                float newEdgeCost = distances[src1][src2] + distances[dest1][dest2];

                if (newEdgeCost < oldEdgeCost) {
                    improvement = true;
                    float costDiff = oldEdgeCost - newEdgeCost;
                    cost -= costDiff;
                    reverse(tour.begin() + (i + 1), (tour.begin() + j) + 1);
                }
            }
        }
    }
}

/**
 * This function returns a matrix with the closest vertices.
 * Time Complexity O(V*(V+E)), where V is the number of vertices and E the number of edges.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param epsilon represents a distance.
 * @param minPts minimum number of points.
 * @param outliers vector that stores non-visited vertices.
 * @return Returns auxilary matrix to reduce short times, by avoiding the use of the bigger adjacency matrix from the graph.
 */
vector<vector<int>> Algorithms::clusteringDBSCAN(const vector<vector<float>>& distances, const float& epsilon, const int& minPts, vector<int>& outliers) {
    vector<vector<int>> closePointsList = getClosePointsList(distances, epsilon);

    int numCities = static_cast<int>(closePointsList.size());
    vector<bool> visited(numCities);
    vector<vector<int>> clusters;

    for (int cityIndex = 0; cityIndex < numCities; cityIndex++) {
        bool isCorePoint = (closePointsList[cityIndex].size() >= minPts);
        if (!visited[cityIndex] && isCorePoint) {
            visited[cityIndex] = true;
            vector<int> cluster = {cityIndex};
            expandCluster(closePointsList, cluster, cityIndex, minPts, visited);
            clusters.push_back(cluster);
        }
    }

    for (int cityIndex = 0; cityIndex < numCities; cityIndex++) {
        if (!visited[cityIndex]) {
            outliers.push_back(cityIndex);
        }
    }

    return clusters;
}

/**
 * This function increases the size of the cluster vector.
 * Time Complexity O(V+E), where V is the number of vertices and E is the number of edges.
 * @param closePointsList matrix that contains the closest points to the city.
 * @param cluster vector that is going to be increased.
 * @param cityIndex current city.
 * @param minPts minimum number of points.
 * @param visited vector that for each node has a bool to check if it was already visited or not.
 */
void Algorithms::expandCluster(const vector<vector<int>>& closePointsList, vector<int>& cluster, const int& cityIndex, const int& minPts, vector<bool>& visited) {
    queue<int> neighbors;
    neighbors.push(cityIndex);

    while (!neighbors.empty()) {
        int currentCity = neighbors.front();
        neighbors.pop();

        vector<int> neighborCities = closePointsList[currentCity];
        bool isCorePoint = (neighborCities.size() >= minPts);

        if (isCorePoint) {
            for (const int& neighbor : neighborCities) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    cluster.push_back(neighbor);
                    neighbors.push(neighbor);
                }
            }
        }
    }
}

/**
 * This function returns a matrix with the closest neighbours within epsilon distance.
 * Time Complexity O(V^2), where V are the vertices of the graph.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param epsilon maximum distance allowed.
 * @return Returns a matrix with the neighbours that are below epsilon distance.
 */
vector<vector<int>> Algorithms::getClosePointsList(const vector<vector<float>>& distances, const float& epsilon) {
    int n = static_cast<int>(distances.size());
    vector<vector<int>> neighborsList(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distances[i][j] <= epsilon) {
                neighborsList[i].push_back(j);
                neighborsList[j].push_back(i);
            }
        }
    }

    return neighborsList;
}

/**
 * This function generates random non-repeating numbers.
 * @param max maximum number that can be generated.
 * @param count number count.
 * @return Returns a random number.
 */
vector<int> Algorithms::generateRandomNonRepeatingInts(int max, int count) {
    vector<int> numbers(max);
    iota(numbers.begin(), numbers.end(), 0);

    random_device rd;
    mt19937 generator(rd());

    shuffle(numbers.begin(), numbers.end(), generator);

    numbers.resize(count);

    return numbers;
}

/**
 * This function gets a random subset from the source vector with size n.
 * Time Complexity O(n).
 * @param source vector that we get the subset from.
 * @param n subset size.
 * @return Returns a subset from the source vector.
 */
vector<int> getRandomSubset(const vector<int>& source, const int& n) {
    random_device rd;
    mt19937 generator(rd());
    vector<int> subset;

    int size = static_cast<int>(source.size());

    if (n > size) {
        cerr << "Error: 'n' is greater than the size of vector 'a'.\n";
        return subset;
    }

    vector<int> indices(size);
    iota(indices.begin(), indices.end(), 0);

    shuffle(indices.begin(), indices.end(), generator);

    for (int i = 0; i < n; i++) {
        subset.push_back(source[indices[i]]);
    }

    return subset;
}

/**
 * This function filters the best path that generate from the various starting points.
 * Time Complexity O(N), where N is the size of the cluster (or distances, if cluster is empty).
 * @param cost current cost.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param numOfStarts number of starting points.
 * @param cluster matrix that stores the distance between a pair of nodes, shorter than distances to reduce search time.
 * @return Returns the best path.
 */
vector<int> Algorithms::multiStartTwoOptNearestNeighbor(float &cost, const vector<vector<float>> &distances, const int& numOfStarts, const vector<int>& cluster) {
    int max = static_cast<int>(distances.size());
    vector<int> startingPoints = cluster.empty() ? generateRandomNonRepeatingInts(max, numOfStarts) : getRandomSubset(cluster, numOfStarts);

    vector<float> solutionCosts;
    vector<vector<int>> tspSolutions;
    solutionCosts.reserve(numOfStarts);
    tspSolutions.reserve(numOfStarts);

    for (const int& startingPoint : startingPoints) {
        float solutionCost = 0;
        vector<int> tspSolution = nearestNeighborTSP(startingPoint, distances, solutionCost, cluster);

        solutionCosts.push_back(solutionCost);
        tspSolutions.push_back(tspSolution);
    }

    float bestCost = solutionCosts[0];
    vector<int> bestTour = tspSolutions[0];
    for (int i = 0; i < tspSolutions.size(); i++) {
        float currCost = solutionCosts[i];
        vector<int> currTour = tspSolutions[i];
        twoOpt(tspSolutions[i], currCost, distances);

        if (currCost < bestCost) {
            bestCost = currCost;
            bestTour = currTour;
        }
    }

    cost = bestCost;

    return bestTour;
}

/**
 * This function finds the index of the average distance in the matrix.
 * Time Complexity O(N^2), where N is the size of the cluster vector.
 * @param cluster matrix that stores the distance between a pair of nodes, shorter than distances to reduce search time.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @return Returns representative index of the average distance of the matrix.
 */
int Algorithms::getClusterRepresentative(const vector<int>& cluster, const vector<vector<float>>& distances) {
    int clusterSize = static_cast<int>(cluster.size());
    int representativeIndex = -1;
    float minAvgDistance = numeric_limits<float>::max();

    for (int i = 0; i < clusterSize; i++) {
        float totalDistance = 0.0;

        for (int j = 0; j < clusterSize; j++) {
            if (i != j) {
                totalDistance += distances[cluster[i]][cluster[j]];
            }
        }

        float avgDistance = totalDistance / (static_cast<float>(clusterSize) - 1);

        if (avgDistance < minAvgDistance) {
            minAvgDistance = avgDistance;
            representativeIndex = cluster[i];
        }
    }

    return representativeIndex;
}

/**
 * This function gets the multiple representative index of the cluster matrix.
 * Time Complexity O(N^3), where N is the size of the cluster vector.
 * @param clusters matrix that stores the distance between a pair of nodes, shorter than distances to reduce search time.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @return Returns a vector with the representatives of the cluster matrix.
 */
vector<int> Algorithms::findClustersRepresentatives(const vector<vector<int>> &clusters, const vector<vector<float>> &distances) {
    vector<int> clusterRepresentatives;
    for (const vector<int>& cluster : clusters) {
        int representative = getClusterRepresentative(cluster, distances);
        clusterRepresentatives.push_back(representative);
    }
    return clusterRepresentatives;
}

/**
 * This function finds the best score from the distances matrix.
 * Time Complexity O(V*(V+E) + N^2);
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param minPtsFirst minimum points of the first element.
 * @param minPtsLast minimum points of the last element.
 * @param minPtsIncrement minimum points increment.
 * @param epsilonFirst epsilon of the first element.
 * @param epsilonLast epsilon of the last element.
 * @param epsilonIncrement epsilon increment.
 */
void Algorithms::clusteringCalibrator(const vector<vector<float>>& distances, const int& minPtsFirst, const int& minPtsLast, const int& minPtsIncrement, const int& epsilonFirst, const int& epsilonLast, const int& epsilonIncrement) {
    double bestScore = std::numeric_limits<double>::lowest();
    int bestEpsilon;
    int bestMinPts;

    for (int i = epsilonFirst; i < epsilonLast; i += epsilonIncrement) {
        for (int j = minPtsFirst; j < minPtsLast; j += minPtsIncrement) {
            vector<int> outliers;
            vector<vector<int>> clusters = Algorithms::clusteringDBSCAN(distances, static_cast<float>(i), j, outliers);

            double score = getClusteringScore(clusters);

            if (score > bestScore) {
                bestScore = score;
                bestEpsilon = i;
                bestMinPts = j;
            }

            cout << i << " " << j << " " << score << endl;
        }
    }

    cout << "\nBest score: " << bestScore << ", best epsilon: " << bestEpsilon << ", best minPts: " << bestMinPts << endl;
}

/**
 * This function gets the Cluster's score.
 * Time Complexity O(N), where N is the cluster's size.
 * @param clusters matrix that stores the distance between a pair of nodes, shorter than the adjacency matrix to reduce search time.
 * @return Returns the score.
 */
double Algorithms::getClusteringScore(const vector<vector<int>>& clusters) {
    auto numClusters = static_cast<double>(clusters.size());

    double totalVertices = 0;
    for (const vector<int>& cluster : clusters) {
        totalVertices += static_cast<double>(cluster.size());
    }

    double score = totalVertices / numClusters;

    return score;
}

/**
 * This function finds the best path that starts and ends in the same vertex.
 * Time Complexity O(N^2), where N is the size of the cluster vector.
 * @param distances matrix that stores the distance between a pair of nodes.
 * @param clusteringEpsilon number that represents a distance.
 * @param clusteringMinPts number that represents the minimum points.
 * @param resultCost path cost.
 * @return Returns a vector with the best path.
 */
vector<int> Algorithms::customTspHeuristic(const vector<vector<float>> &distances, const float &clusteringEpsilon, const int &clusteringMinPts, float& resultCost) {
    vector<int> outliers;
    vector<vector<int>> clusters = Algorithms::clusteringDBSCAN(distances, clusteringEpsilon, clusteringMinPts, outliers);

    vector<float> clustersTspCosts;
    vector<vector<int>> clustersTspSolutions;
    for (const vector<int>& cluster : clusters) {
        float currCost = 0;
        vector<int> currSolution = Algorithms::multiStartTwoOptNearestNeighbor(currCost, distances, static_cast<int>(cluster.size()), cluster);

        clustersTspCosts.push_back(currCost);
        clustersTspSolutions.push_back(currSolution);
    }

    vector<int> clusterRepresentatives = Algorithms::findClustersRepresentatives(clusters, distances);
    unordered_map<int, int> representativesPosition;
    for (int i = 0; i < clusterRepresentatives.size(); i++) {
        representativesPosition[clusterRepresentatives[i]] = i;
    }

    vector<int> reducedTspInstance;
    reducedTspInstance.insert(reducedTspInstance.end(), make_move_iterator(clusterRepresentatives.begin()), make_move_iterator(clusterRepresentatives.end()));
    reducedTspInstance.insert(reducedTspInstance.end(), make_move_iterator(outliers.begin()), make_move_iterator(outliers.end()));

    float reducedTspInstanceCost = 0;
    vector<int> reducedTspInstanceSolution = Algorithms::multiStartTwoOptNearestNeighbor(reducedTspInstanceCost, distances, static_cast<int>(reducedTspInstance.size()),reducedTspInstance);

    float clusterCosts = 0;
    for (const float& cost : clustersTspCosts) {
        clusterCosts += cost;
    }

    int n = static_cast<int>(reducedTspInstanceSolution.size());
    float finalSolutionCost = 0;
    vector<int> finalSolution;
    finalSolution.reserve(n);

    int firstVertice = reducedTspInstanceSolution[0];
    bool firstIsCluster = representativesPosition.contains(firstVertice);
    if (firstIsCluster) {
        int clusterPos = representativesPosition[firstVertice];

        vector<int> clusterSol = clustersTspSolutions[clusterPos];
        int solSize = static_cast<int>(clusterSol.size());
        float clusterSolCost = clustersTspCosts[clusterPos];
        finalSolutionCost += (clusterSolCost - distances[clusterSol[solSize - 2]][clusterSol[solSize - 1]]);
        std::move(clusterSol.begin(), std::prev(clusterSol.end()), std::back_inserter(finalSolution));
    } else {
        finalSolution.push_back(firstVertice);
    }

    for (int i = 1; i < n; i++) {
        int currVertice = finalSolution.back();
        int nextVertice = reducedTspInstanceSolution[i];

        bool isCluster = representativesPosition.contains(nextVertice);
        if (isCluster) {
            int clusterPos = representativesPosition[nextVertice];

            vector<int> clusterSol = clustersTspSolutions[clusterPos];
            int solSize = static_cast<int>(clusterSol.size());
            float costToCluster = distances[currVertice][clusterSol[0]];
            float clusterSolCost = clustersTspCosts[clusterPos];

            finalSolutionCost += (costToCluster + (clusterSolCost - distances[clusterSol[solSize - 2]][clusterSol[solSize - 1]]));
            std::move(clusterSol.begin(), std::prev(clusterSol.end()), std::back_inserter(finalSolution));
        } else {
            finalSolutionCost += distances[currVertice][nextVertice];
            finalSolution.push_back(nextVertice);
        }
    }

    resultCost = finalSolutionCost;

    return finalSolution;
}

/**
* Function to traverse an mst in preorder and store the path in a vector.
* Temporal complexity O(n).
* @param u int that stores the index of the current node being visited.
* @param adjMatrix matrix that stores the distance between a pair nodes.
* @param visited vector that for each node has a bool to check if it was already visited or not.
* @param preorder vector to store the order in which the nodes are visited.
*/
void Algorithms::dfs(int u, vector<vector<float>> &adjMatrix, vector<bool> &visited, vector<int> &preorder) {
    visited[u] = true;
    preorder.push_back(u);
    for(int v = 1; v < adjMatrix[u].size(); v++){
        if(!visited[v] && (adjMatrix[u][v] != INFINITY_FLOAT)){
            dfs(v, adjMatrix, visited, preorder);
        }
    }
    return;
}
