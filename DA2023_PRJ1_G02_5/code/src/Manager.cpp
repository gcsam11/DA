#include "../include/Manager.h"

/**
 * Function to start up the program.
 * @param isFlowGraph bool to create a flow graph if true.
 */
void Manager::run(bool isFlowGraph) {
    createNetworkGraph(isFlowGraph);
    executionManager();
}

/**
 * Temporal complexity O(1).
 * Simple method to sort the vector of pairs.
 * @param Start represents a pair from the vector.
 * @param Finish represents another pair from the vector.
 * @return a boolean value that will be true if the int value in pair Start is bigger than the int value in pair Finish, and false otherwise.
 */
bool Manager::compare(const pair<string, int>& Start, const pair<string, int>& Finish) {
    return(Start.second > Finish.second);
}

/**
 * Function to process menu inputs.
 * Temporal complexity undefined, because the function presents an infinite loop that only ends with an user input.
 */
void Manager::executionManager() {
    while(true) {
        Design::displayMenu();
        Graph currSubGraph;
        string op;
        cin >> op;
        vector<pair<string, int>> countFails = {};
        if (op.length() != 1) {
            cinReset();
            Design::keyError();
            continue;
        }
        else if (op == "1") {
            cinReset();
            maxTrainsBetweenStations();
            Design::back();
        }
        else if (op == "2") {
            cinReset();
            busiestPairsOfStations();
            Design::back();
        }
        else if (op == "3") {
            cinReset();
            busiestMunisAndDist();
            Design::back();
        }
        else if (op == "4") {
            cinReset();
            maxSimultaneousTrainsToAStation();
            Design::back();
        }
        else if(op == "5"){
            cinReset();
            maxTrainsBetweenStationsWithMinCost();
            Design::back();
        }
        else if(op == "6"){
            string stationA, stationB;
            currSubGraph = generateSubGraph(countFails);
            cinReset();
            prepareSubGraphMaxFlow(stationA, stationB);
            int maxFlow = currSubGraph.maxFlow(stationA, stationB);
            cout << "\nTHE MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY TRAVEL BETWEEN " << stationA << " AND " << stationB << " IN THE GENERATED SUBGRAPH IS " << maxFlow << endl;
            Design::back();
        }
        else if(op == "7"){
            string number;
            int k;
            cinReset();
            cout << "\nPICK A NUMBER: ";
            getline(cin, number);
            k = stoi(number);
            generateSubGraph(countFails);
            sort(countFails.begin(), countFails.end(), compare);
            Design::DrawTopKFails(countFails, k);
            Design::back();
        }
        else if (op == "q" || op == "Q") { break; }
        else{
            Design::keyError();
        }
    }
}

void Manager::createNetworkGraph(bool isFlowGraph) {
    readStations();
    readNetwork(isFlowGraph);
}

void Manager::cinReset() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * This method will check if the string that came from the user input is correct and won't have trouble with our algorithms.
 * @param messy is the string from user input.
 * @return the string after being "cleaned".
 */
string Manager::clearString(string str) {
    static const std::unordered_map<char, char> accent_map = {
            {'Á', 'A'}, {'É', 'E'}, {'Í', 'I'}, {'Ó', 'O'}, {'Ú', 'U'},
            {'À', 'A'}, {'È', 'E'}, {'Ì', 'I'}, {'Ò', 'O'}, {'Ù', 'U'},
            {'Â', 'A'}, {'Ê', 'E'}, {'Î', 'I'}, {'Ô', 'O'}, {'Û', 'U'},
            {'Ã', 'A'}, {'Õ', 'O'},
            {'á', 'a'}, {'é', 'e'}, {'í', 'i'}, {'ó', 'o'}, {'ú', 'u'},
            {'à', 'a'}, {'è', 'e'}, {'ì', 'i'}, {'ò', 'o'}, {'ù', 'u'},
            {'â', 'a'}, {'ê', 'e'}, {'î', 'i'}, {'ô', 'o'}, {'û', 'u'},
            {'ã', 'a'}, {'õ', 'o'}
    };
    std::transform(str.begin(), str.end(), str.begin(), [](char c) {
        auto it = accent_map.find(c);
        return it != accent_map.end() ? it->second : c;
    });
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isalnum(c); }), str.end());
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
    return str;
}

/**
 * Reads the stations.csv file.
 * Temporal complexity O(n).
 */
void Manager::readStations() {
    for (CsvLine& line : CsvReader::read("../data/stations.csv", true)) {
        string name = line.getString(0), dist = line.getString(1), muni = line.getString(2);
        Station station = Station(name, dist, muni, line.getString(3), line.getString(4));
        networkGraph.addVertex(station);
        stationsMap.insert({clearString(name), station});

        if (districtMap.contains(dist)) {
            if (districtMap[dist].contains(muni)) {
                districtMap[dist][muni].push_back(station);
            } else {
                vector<Station> stations;
                stations.push_back(station);
                districtMap[dist].insert({muni, stations});
            }
        } else {
            vector<Station> stations;
            stations.push_back(station);
            unordered_map<string, vector<Station>> muniMap;
            muniMap.insert({muni, stations});
            districtMap.insert({dist, muniMap});
        }
    }
}

/**
 * Function to read the network.csv file and create the directed graph.
 * @param isFlowGraph is a boolean value that will tell the function if we need to draw a flow graph or not.
 */
void Manager::readNetwork(bool isFlowGraph) {
    if (isFlowGraph) {
        for (CsvLine& line : CsvReader::read("../data/network.csv", true)) {
            networkGraph.addEdgeAndResidual(line.getString(0), line.getString(1), line.getInt(2), line.getService(3), INF);
        }
    } else {
        for (CsvLine& line : CsvReader::read("../data/network.csv", true)) {
            networkGraph.addEdge(line.getString(0), line.getString(1), line.getInt(2), line.getService(3), INF);
        }
    }
}

/**
 * Receives input of 2 stations to calculate the maximum flow between them.
 * Temporal complexity undefined, because the function presents 2 infinite loops that only end when the user inputs 2 valid stations.
 */
void Manager::maxTrainsBetweenStations() {
    string stationA, stationB;

    while (true) {
        cout << "\nWRITE THE NAME OF THE FIRST STATION: ";

        std::getline(cin, stationA);

        if (stationsMap.count(clearString(stationA))) {
            stationA = stationsMap.at(clearString(stationA)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    while (true) {
        cout << "\nWRITE THE NAME OF THE SECOND STATION: ";

        std::getline(cin, stationB);

        if (stationsMap.count(clearString(stationB))) {
            stationB = stationsMap.at(clearString(stationB)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    int maxFlow = networkGraph.maxFlow(stationA, stationB);

    cout << "\nTHE MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY TRAVEL BETWEEN " << stationA << " AND " << stationB << " IS " << maxFlow << endl;
}

/**
 * Temporal complexity O(n^2 + V*E^2).
 * This method will calculate the maximum flow between every pair of stations and return the biggest one.
 */
void Manager::busiestPairsOfStations() {
    cout << "CURRENTLY COMPARING THE MAX-FLOW BETWEEN EVERY PAIR OF STATIONS. YOUR RESULTS WILL BE SHOWED SHORTLY :)\n" << endl;

    int largestMaxFlow = 0, currMaxFlow;
    vector<pair<Station, Station>> stationPairs;

    for (auto it1 = stationsMap.begin(); it1 != stationsMap.end(); it1++) {
        for (auto it2 = next(it1); it2 != stationsMap.end(); it2++) {
            currMaxFlow = networkGraph.maxFlow(it1->second.getName(), it2->second.getName()) + networkGraph.maxFlow(it2->second.getName(), it1->second.getName());

            if (currMaxFlow == largestMaxFlow) {
                stationPairs.emplace_back(it1->second, it2->second);
            } else if (currMaxFlow > largestMaxFlow) {
                stationPairs.clear();
                stationPairs.emplace_back(it1->second, it2->second);
                largestMaxFlow = currMaxFlow;
            }
        }
    }

    cout << "THE PAIR(S) OF STATIONS THAT REQUIRE THE MOST AMOUNT OF TRAINS, WHEN MAKING USE OF THE FULL NETWORK CAPACITY, IS(ARE):\n" << std::endl;
    for (const auto& stations : stationPairs) {
        cout << "[" << stations.first.getName() << ", " << stations.second.getName() << "]" << " WITH AN ADDED MAX-FLOW (TRAVELING BOTH WAYS) OF " << largestMaxFlow << endl;
    }
}

/**
 * Temporal complexity O(n^4 + V*E^2).
 * This method will calculate the Municipalities and Districts with the highest maximum flow.
 * It will also print the top 10 Districts and top 50 Municipalities.
 */
void Manager::busiestMunisAndDist() {
    multiset<pair<int, string>, greater<>> flowOfMunicipalities;
    multiset<pair<int, string>, greater<>> flowOfDistricts;

    for (const auto& district : districtMap) {
        int distFlow = 0;
        for (const auto& municipality : district.second) {
            int muniFlow = 0;
            vector<Station> muniStations = municipality.second;
            for (auto it1 = muniStations.begin(); it1 != muniStations.end(); it1++) {
                for (auto it2 = it1+1; it2 != muniStations.end(); it2++) {
                    muniFlow += networkGraph.maxFlow(it1->getName(), it2->getName());
                    muniFlow += networkGraph.maxFlow(it2->getName(), it1->getName());
                }
            }
            distFlow += muniFlow;
            flowOfMunicipalities.emplace(muniFlow, municipality.first);
        }
        flowOfDistricts.emplace(distFlow, district.first);
    }

    cout << "THE TOP 10 DISTRICTS WHERE RESOURCES SHOULD BE ALLOCATED BASED ON THEIR TRANSPORTATION NEEDS ARE:\n" << endl;

    int cnt1 = 0;
    for (const auto& flowDist : flowOfDistricts) {
        cout << flowDist.second << " | Flow: " << flowDist.first << endl;
        cnt1++;
        if (cnt1 == 10) break;
    }

    cout << "\nTHE TOP 50 MUNICIPALITIES WHERE RESOURCES SHOULD BE ALLOCATED BASED ON THEIR TRANSPORTATION NEEDS ARE:\n" << endl;

    int cnt2 = 0;
    for (const auto& flowMuni : flowOfMunicipalities) {
        cout << flowMuni.second << " | Flow: " << flowMuni.first << endl;
        cnt2++;
        if (cnt2 == 50) break;
    }
}

/**
 * Temporal complexity undefined, because the function presents 2 infinite loops that only end when the user inputs 2 valid stations.
 */
void Manager::maxTrainsBetweenStationsWithMinCost() {
    string stationA, stationB;

    while (true) {
        cout << "\nWRITE THE NAME OF THE FIRST STATION: ";

        std::getline(cin, stationA);

        if (stationsMap.count(clearString(stationA))) {
            stationA = stationsMap.at(clearString(stationA)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    while (true) {
        cout << "\nWRITE THE NAME OF THE SECOND STATION: ";

        std::getline(cin, stationB);

        if (stationsMap.count(clearString(stationB))) {
            stationB = stationsMap.at(clearString(stationB)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    networkGraph.dijkstraModif(stationA, stationB);
}

/**
 * This method calculates the maximum simultaneous trains that can arrive in a specified station that will be received from user input.
 * Temporal complexity undefined, because the function presents an infinite loop that only ends when the user inputs a valid station.
 */
void Manager::maxSimultaneousTrainsToAStation() {
    vector<Vertex*> sourceVertexes;
    string station;
    string clearStation;

    while (true) {
        cout << "\nWRITE THE NAME OF THE STATION YOU DESIRE: ";

        std::getline(cin, station);

        clearStation = clearString(station);
        if (stationsMap.count(clearStation)) {
            station = stationsMap.at(clearStation).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    for (Vertex* vertex : networkGraph.getVertexSet()) {
        if ((vertex->getIndegree() == 0) && (vertex->getName() != "START")) {
            sourceVertexes.push_back(vertex);
        }
    }

    networkGraph.addVertex(Station("START", "ETERNITY", "BEYOND", "START", "LINE OF INFINITY"));

    for (Vertex* sourceVertex : sourceVertexes) {
        networkGraph.addEdgeAndResidual("START", sourceVertex->getName(), INF, SERVICE_ENUM::STANDARD, INF);
    }

    int maxSimulTrains = networkGraph.maxFlow("START", station);
    if (maxSimulTrains == INF) maxSimulTrains = 0;

    cout << "\nTHE MAXIMUM AMOUNT OF TRAINS THAT CAN SIMULTANEOUSLY ARRIVE AT " << station << " IS " << maxSimulTrains << endl;

}

/**
 * Temporal complexity O(n^3).
 * This method will generate a subgraph by eliminating x random edges from y to y vertices (using rand() function).
 * @param countFails is a vector of pairs that counts how many edges have been removed from the adjacency list of a vertex, the latter represented as a string (name of the station).
 * @return a subgraph of the original graph.
 */
Graph Manager::generateSubGraph(vector<pair<string, int>> &countFails) {
    Graph subGraph = networkGraph;
    vector<Vertex*> aux = networkGraph.getVertexSet();
    pair<string, int> push;

    for(int i = 0; i < aux.size(); i++){
        push.first = aux[i]->getName();
        push.second = 0;
        countFails.push_back(push);
    }

    srand(time(NULL));

    int inbetween = rand() % subGraph.getVertexSet().size()/2;
    int count = 0, countEdge = 0, edgeN = 0;

    for(auto& help: subGraph.getVertexSet()){
        if(count == inbetween){
            edgeN = rand() % help->getAdj().size()/2 + 1;
            vector<Edge*> adj = help->getAdj();
            for(int j = 0; j < adj.size(); j++){
                if(countEdge == edgeN){
                    addFailCount(help->getName(), adj[j]->getDest()->getName(), countFails);
                    subGraph.removeEdge(help, adj[j]);
                    countEdge = 0;
                }
                countEdge++;
            }
            count = 0;
            continue;
        }
        count++;
    }

    return subGraph;
}

/**
 * Temporal complexity O(n)
 * This method adds to the start station and the finish station correspondent number if an edge is removed when generating a subgraph.
 * @param start represents the starting station of an edge.
 * @param finish represents the edge's destiny station.
 * @param countFails vector of pairs passed by reference so it can be updated and be used out of this method to print the results.
 */
void Manager::addFailCount(const string& start, const string& finish, vector<pair<string, int>> &countFails) {
    for(int i = 0; i < countFails.size(); i++){
        if(countFails[i].first == start || countFails[i].first == finish){
            countFails[i].second++;
        }
    }
}
/**
 * Temporal complexity undefined, because the function presents 2 infinite loops that only end when the user inputs 2 valid stations.
 * Method used to receive the input of two stations.
 * @param stationA is our starting station.
 * @param stationB is our destiny.
 */
void Manager::prepareSubGraphMaxFlow(string &stationA, string &stationB) {
    while (true) {
        cout << "\nWRITE THE NAME OF THE FIRST STATION: ";

        std::getline(cin, stationA);

        if (stationsMap.count(clearString(stationA))) {
            stationA = stationsMap.at(clearString(stationA)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }

    while (true) {
        cout << "\nWRITE THE NAME OF THE SECOND STATION: ";

        std::getline(cin, stationB);

        if (stationsMap.count(clearString(stationB))) {
            stationB = stationsMap.at(clearString(stationB)).getName();
            break;
        } else {
            cout << "THE STATION YOU CHOSE DOES NOT EXIST. PLEASE TRY AGAIN" << endl;
            continue;
        }
    }
}
