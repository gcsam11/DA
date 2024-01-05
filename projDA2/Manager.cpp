#include "Manager.hpp"

using namespace std;

Manager::Manager() = default;

/**
 * Function to return to the menu.
 * Temporal complexity undefined, because the function presents an infinite loop that only ends with an user input.
 */
void Manager::goBackToMenu() {
    string input;

    while (input != "V" && input != "v") {
        cinReset();
        cout << "\nPress v or V to go back to the Main Menu: ";
        cin >> input;
    }
    cinReset();
}

/**
 * Function to return to the Triangular Approximation menu.
 * Temporal complexity undefined, because the function presents an infinite loop that only ends with an user input.
 */
void Manager::goBackToTriangularMenu() {
    string input;

    while (input != "V" && input != "v") {
        cinReset();
        cout << "\nPress v or V to go back to the Main Menu: ";
        cin >> input;
    }
    cinReset();

    Design::drawTriangularApproximation();
}

void Manager::cinReset() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Function to process menu inputs.
 * Temporal complexity undefined, because the function presents an infinite loop that only ends with an user input.
 */
void Manager::mainLoop() {
    while (true) {
        Design::displayMenu({"LOAD GRAPHS", "GOAL 1", "GOAL 2", "GOAL 3"});

        string optionStr;
        int optionInt;

        cout << "\nChoose an option and press ENTER: ";
        cin >> optionStr;

        if (optionStr == "q" or optionStr == "Q")
            break;

        try {
            optionInt = stoi(optionStr);
        } catch (const invalid_argument& e) {
            cout << "\nYOU CAN NOT INPUT TEXT OTHER THAN 'q' or 'Q'" << endl;
            cinReset();
            continue;
        }

        switch (optionInt) {
            case 1:
                if (graphsLoaded) {
                    cout << "\nTHE GRAPHS ARE ALREADY LOADED" << endl;
                    continue;
                }

                loadGraphs();

                goBackToMenu();

                break;
            case 2:
                if (!graphsLoaded) {
                    cout << "\nTHE GRAPHS MUST BE LOADED BEFORE RUNNING THE ALGORITHMS" << endl;
                    continue;
                }

                backTracking();

                goBackToMenu();

                break;
            case 3:
                if (!graphsLoaded) {
                    cout << "\nTHE GRAPHS MUST BE LOADED BEFORE RUNNING THE ALGORITHMS" << endl;
                    continue;
                }

                Design::drawTriangularApproximation();

                while(true){
                    string optionStr2;
                    int optionInt2;

                    cout << "\nChoose an option and press ENTER: ";
                    cin >> optionStr2;

                    if (optionStr2 == "v" or optionStr2 == "V")
                        break;

                    try {
                        optionInt2 = stoi(optionStr2);
                    } catch (const invalid_argument& e) {
                        cout << "\nYOU CAN NOT INPUT TEXT OTHER THAN 'v' or 'V'" << endl;
                        cinReset();
                        continue;
                    }

                    switch(optionInt2){
                        case 1:
                            cout << "\nSTADIUMS GRAPH" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(toyGraphStadiums);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 2:
                            cout << "\nTOURISM GRAPH" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(toyGraphTourism);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 3:
                            cout << "\nREAL GRAPH 1" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphNotFullyConnected(realGraph1);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 4:
                            cout << "\nREAL GRAPH 2" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphNotFullyConnected(realGraph2);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 5:
                            cout << "\nREAL GRAPH 3" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphNotFullyConnected(realGraph3);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 6:
                            cout << "\nEDGES 25" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_25);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 7:
                            cout << "\nEDGES 50" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_50);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 8:
                            cout << "\nEDGES 75" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_75);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 9:
                            cout << "\nEDGES 100" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_100);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 10:
                            cout << "\nEDGES 200" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_200);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 11:
                            cout << "\nEDGES 300" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_300);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 12:
                            cout << "\nEDGES 400" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_400);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 13:
                            cout << "\nEDGES 500" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_500);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 14:
                            cout << "\nEDGES 600" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_600);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 15:
                            cout << "\nEDGES 700" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_700);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 16:
                            cout << "\nEDGES 800" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_800);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        case 17:
                            cout << "\nEDGES 900" << endl;
                            cout << string(80, '-') << endl;
                            triangularApproximationSingleGraphFullyConnected(edges_900);
                            cout << string(80, '-') << endl;
                            goBackToTriangularMenu();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 4:
                if (!graphsLoaded) {
                    cout << "\nTHE GRAPHS MUST BE LOADED BEFORE RUNNING THE ALGORITHMS" << endl;
                    continue;
                }

                goBackToMenu();

                break;

            default:
                cout << "\nYOU CAN ONLY PICK A NUMBER BETWEEN 1 AND 4" << endl;
                cinReset();

                break;
        }
    }
}

/**
* Function whose only purpose is to call the function loadGraphFromCsv().
* Temporal complexity O(1).
*/
void Manager::loadGraphs() {
    cout << "\nWARNING, THE REAL WORLD GRAPHS ARE VERY LARGE AND TAKE SOME TIME TO FINISH LOADING" << endl;

    cout << "\nLoading Toy Graph shipping..." << endl;
    loadGraphFromCsv(toyGraphShipping, true, false, false, "", "../graphs_data/Toy-Graphs/shipping.csv");
    cout << "Toy Graph shipping loaded." << endl;

    cout << "\nLoading Toy Graph stadiums..." << endl;
    loadGraphFromCsv(toyGraphStadiums, true, false, false,"", "../graphs_data/Toy-Graphs/stadiums.csv");
    cout << "Toy Graph stadiums loaded." << endl;

    cout << "\nLoading Toy Graph tourism..." << endl;
    loadGraphFromCsv(toyGraphTourism, true, false, false,"", "../graphs_data/Toy-Graphs/tourism.csv");
    cout << "Toy Graph tourism loaded." << endl;

    cout << "\nLoading Real World Graph 1..." << endl;
    loadGraphFromCsv(realGraph1, false, false, true, "../graphs_data/Real-world Graphs/graph1/nodes.csv", "../graphs_data/Real-world Graphs/graph1/edges.csv");
    cout << "Real World Graph 1 loaded." << endl;

    cout << "\nLoading Real World Graph 2..." << endl;
    loadGraphFromCsv(realGraph2, false, false, true, "../graphs_data/Real-world Graphs/graph2/nodes.csv", "../graphs_data/Real-world Graphs/graph2/edges.csv");
    cout << "Real World Graph 2 loaded." << endl;

    cout << "\nLoading Real World Graph 3..." << endl;
    loadGraphFromCsv(realGraph3, false, false, true, "../graphs_data/Real-world Graphs/graph3/nodes.csv", "../graphs_data/Real-world Graphs/graph3/edges.csv");
    cout << "Real World Graph 3 loaded." << endl;

    cout << "\nLoading Edges_25..." << endl;
    loadGraphFromCsv(edges_25, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_25.csv");
    cout << "Edges_25 loaded." << endl;

    cout << "\nLoading Edges_50..." << endl;
    loadGraphFromCsv(edges_50, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_50.csv");
    cout << "Edges_50 loaded." << endl;

    cout << "\nLoading Edges_75..." << endl;
    loadGraphFromCsv(edges_75, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_75.csv");
    cout << "Edges_75 loaded." << endl;

    cout << "\nLoading Edges_100..." << endl;
    loadGraphFromCsv(edges_100, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_100.csv");
    cout << "Edges_100 loaded." << endl;

    cout << "\nLoading Edges_200..." << endl;
    loadGraphFromCsv(edges_200, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_200.csv");
    cout << "Edges_200 loaded." << endl;

    cout << "\nLoading Edges_300..." << endl;
    loadGraphFromCsv(edges_300, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_300.csv");
    cout << "Edges_300 loaded." << endl;

    cout << "\nLoading Edges_400..." << endl;
    loadGraphFromCsv(edges_400, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_400.csv");
    cout << "Edges_400 loaded." << endl;

    cout << "\nLoading Edges_500..." << endl;
    loadGraphFromCsv(edges_500, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_500.csv");
    cout << "Edges_500 loaded." << endl;

    cout << "\nLoading Edges_600..." << endl;
    loadGraphFromCsv(edges_600, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_600.csv");
    cout << "Edges_600 loaded." << endl;

    cout << "\nLoading Edges_700..." << endl;
    loadGraphFromCsv(edges_700, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_700.csv");
    cout << "Edges_700 loaded." << endl;

    cout << "\nLoading Edges_800..." << endl;
    loadGraphFromCsv(edges_800, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_800.csv");
    cout << "Edges_800 loaded." << endl;

    cout << "\nLoading Edges_900..." << endl;
    loadGraphFromCsv(edges_900, false, true, false, "", "../graphs_data/Extra_Fully_Connected_Graphs/edges_900.csv");
    cout << "Edges_900 loaded." << endl;

    graphsLoaded = true;
}

/**
* Function reads the csv files that store the nodes and edges, and stores them in the graph parameter.
* Temporal complexity O(V + E).
* @param graph holds all the nodes and the edges that will be read from their corresponding files.
* @param isToyGraph bool to check if the graph is a toy graph, and if so, make use of a specific method to read it.
* @param isExtraFullyConnectedGraph bool to check if the graph is an extra fully connected graph, make use of a specific method to read it.
* @param isRealGraph bool to check if the graph is a real graph, make use of a specific method to read it.
* @param nodesCsvPath string that holds the path to the node's csv file.
* @param edgesCsvPath string that holds the path to the edge's csv file.
*/
void Manager::loadGraphFromCsv(Graph &graph, const bool& isToyGraph, const bool& isExtraFullyConnectedGraph, const bool& isRealGraph, const string &nodesCsvPath, const string &edgesCsvPath) {
    if(isExtraFullyConnectedGraph){
        vector<CsvLine> edgeLines = CsvReader::readCsvFile(edgesCsvPath, false);
        set<int> nodeSet;

        for (const CsvLine& edgeLine : edgeLines) {
            nodeSet.insert(edgeLine.getInt(0));
            nodeSet.insert(edgeLine.getInt(1));
        }

        int numOfNodes = nodeSet.size();
        graph.resizeStructures(numOfNodes);

        for (const int& nodeIndex : nodeSet) {
            graph.addNode({nodeIndex});
        }

        for (const CsvLine& edgeLine : edgeLines) {
            int nodeA = edgeLine.getInt(0);
            int nodeB = edgeLine.getInt(1);
            float distance = edgeLine.getFloat(2);

            graph.addEdge(nodeA, nodeB, distance);
        }
    }

    if (isToyGraph) {
        vector<CsvLine> edgeLines = CsvReader::readCsvFile(edgesCsvPath, true);
        set<int> nodeSet;

        for (const CsvLine& edgeLine : edgeLines) {
            nodeSet.insert(edgeLine.getInt(0));
            nodeSet.insert(edgeLine.getInt(1));
        }

        int numOfNodes = nodeSet.size();
        graph.resizeStructures(numOfNodes);

        for (const int& nodeIndex : nodeSet) {
            graph.addNode({nodeIndex});
        }

        for (const CsvLine& edgeLine : edgeLines) {
            int nodeA = edgeLine.getInt(0);
            int nodeB = edgeLine.getInt(1);
            float distance = edgeLine.getFloat(2);

            graph.addEdge(nodeA, nodeB, distance);
        }
    }

    if(isRealGraph) {
        vector<CsvLine> edgeLines = CsvReader::readCsvFile(edgesCsvPath, true);
        vector<CsvLine> nodeLines = CsvReader::readCsvFile(nodesCsvPath, true);

        int numOfNodes = nodeLines.size();
        graph.resizeStructures(numOfNodes);

        for (const CsvLine& nodeLine : nodeLines) {
            graph.addNode({nodeLine.getInt(0), nodeLine.getDouble(1), nodeLine.getDouble(2)});
        }

        for (const CsvLine& edgeLine : edgeLines) {
            int nodeA = edgeLine.getInt(0);
            int nodeB = edgeLine.getInt(1);
            float distance = edgeLine.getFloat(2);

            graph.addEdge(nodeA, nodeB, distance);
        }
    }
}

/**
* Function whose only purpose is to call the function backTrackingSingleGraph().
* Temporal complexity O(1).
*/
void Manager::backTracking() {
    cout << "\nBACKTRACKING ALGORITHM" << endl;
    cout << "\nComplexity: O(n!), where n is the number of nodes" << endl;

    cout << "\nSHIPPING GRAPH" << endl;
    cout << string(80, '-') << endl;
    backTrackingSingleGraph(toyGraphShipping);
    cout << string(80, '-') << endl;

    cout << "\nSTADIUMS GRAPH" << endl;
    cout << string(80, '-') << endl;
    backTrackingSingleGraph(toyGraphStadiums);
    cout << string(80, '-') << endl;

    cout << "\nTOURISM GRAPH" << endl;
    cout << string(80, '-') << endl;
    backTrackingSingleGraph(toyGraphTourism);
    cout << string(80, '-') << endl;
}

/**
* Function calls backtrackingTsp() and prints the path received from that function.
* Temporal complexity O(n!).
* @param graph holds all the nodes and edges that belong to the graph.
*/
void Manager::backTrackingSingleGraph(const Graph &graph) {
    vector<int> solutionPath;
    vector<int> currPath;
    vector<bool> visited (graph.getNumOfNodes());

    solutionPath.reserve(graph.getNumOfNodes() - 1);
    currPath.reserve(graph.getNumOfNodes() - 1);

    visited[0] = true;

    float tourLength = INFINITY_FLOAT;

    using chrono::high_resolution_clock;
    using chrono::duration;
    using chrono::milliseconds;

    auto start = high_resolution_clock::now();
    Algorithms::backtrackingTsp(graph.getAdjMatrix(), visited, solutionPath, currPath, 0, graph.getNumOfNodes(), 1, 0, tourLength);
    auto end = high_resolution_clock::now();

    duration<double, milli> msExecTime = end - start;

    cout << "Solution: 0->";
    for (const int& node : solutionPath) {
        cout << node << "->";
    }
    cout << "0" << endl;

    cout << "\nTour Length: " << tourLength << " meters" << endl;

    cout << "\nExecution Time: " << msExecTime.count() << " ms" << endl;
}

/**
* Function calls the function primFullyConnected() to create the mst, then calls the function dsf() to create a path and to finish calls the function calcPathValue() to see the distance traveled in the path created by the dsf() function.
* Temporal complexity
* @param graph holds all the nodes and edges that belong to the graph.
*/
void Manager::triangularApproximationSingleGraphFullyConnected(Graph &graph) {
    vector<int> solutionPath;
    vector<vector<float>> currPath;
    vector<bool> visited (graph.getNumOfNodes());
    double mst_cost;

    currPath.resize(graph.getNumOfNodes());

    for (vector<float>& row : currPath) {
        row.resize(graph.getNumOfNodes(), INFINITY_FLOAT);
    }

    solutionPath.reserve(graph.getNumOfNodes());

    using chrono::high_resolution_clock;
    using chrono::duration;
    using chrono::milliseconds;

    auto start = high_resolution_clock::now();

    currPath = graph.primFullyConnected(0, visited);

    for(int i = 0; i < visited.size(); i++){visited[i] = false;}

    Algorithms::dfs(0, currPath, visited, solutionPath);

    mst_cost = graph.calcPathValue(solutionPath);

    auto end = high_resolution_clock::now();

    duration<double, milli> msExecTime = end - start;

    for (const int& node : solutionPath) {
        cout << node << "->";
    }

    cout << "0" << endl;

    cout << "\nTour Length: " << mst_cost << " meters" << endl;

    cout << "\nExecution Time: " << msExecTime.count() << " ms" << endl;
}

/**
* Function calls the function primNotFullyConnected() to create the mst, then calls the function dsf() to create a path and to finish calls the function calcPathValue() to see the distance traveled in the path created by the dsf() function.
* Temporal complexity
* @param graph holds all the nodes and edges that belong to the graph.
*/
void Manager::triangularApproximationSingleGraphNotFullyConnected(Graph &graph) {
    vector<int> solutionPath;
    vector<vector<float>> currPath;
    vector<bool> visited (graph.getNumOfNodes());
    double mst_cost;

    currPath.resize(graph.getNumOfNodes());

    for (vector<float>& row : currPath) {
        row.resize(graph.getNumOfNodes(), INFINITY_FLOAT);
    }

    solutionPath.reserve(graph.getNumOfNodes());

    using chrono::high_resolution_clock;
    using chrono::duration;
    using chrono::milliseconds;

    auto start = high_resolution_clock::now();

    currPath = graph.primNotFullyConnected(0, visited);

    for(int i = 0; i < visited.size(); i++){visited[i] = false;}

    Algorithms::dfs(0, currPath, visited, solutionPath);

    mst_cost = graph.calcPathValue(solutionPath);

    auto end = high_resolution_clock::now();

    duration<double, milli> msExecTime = end - start;

    for (const int& node : solutionPath) {
        cout << node << "->";
    }

    cout << "0" << endl;

    cout << "\nTour Length: " << mst_cost << " meters" << endl;

    cout << "\nExecution Time: " << msExecTime.count() << " ms" << endl;
}
