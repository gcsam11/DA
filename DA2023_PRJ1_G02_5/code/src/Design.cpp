#include "../include/Design.h"

void Design::displayMenu() {
    cout << "\n+----------------------------------------------+\n"
            "|          __  __ ______ _   _ _    _          |\n"
            "|         |  \\/  |  ____| \\ | | |  | |         |\n"
            "|         | \\  / | |__  |  \\| | |  | |         |\n"
            "|         | |\\/| |  __| | . ` | |  | |         |\n"
            "|         | |  | | |____| |\\  | |__| |         |\n"
            "|         |_|  |_|______|_| \\_|\\____/          |\n"
            "|                                              |\n"
            "+----------------------------------------------+\n"
            "| [1] Max Trains Between 2 Stations            |\n"
            "| [2] Busiest Pairs of Stations                |\n"
            "| [3] Busiest Districts And Municipalities     |\n"
            "| [4] Max Simultaneous Trains To A Station     |\n"
            "| [5] Max Trains Between 2 Stations w/ Min Cost|\n"
            "| [6] Max Trains in a generated Subgraph       |\n"
            "| [7] Top-k Affected Stations in Subgraph      |\n"
            "| [Q] - Quit                                   |\n"
            "|______________________________________________|";

    cout << "\nSelect option and press ENTER: ";
}

void Design::keyError(){
    cout << "\n+---------------+\n"
            "| Invalid Input |\n"
            "+---------------+\n";
}

void Design::back() {
    string op;
    cout << "\nPress [V] to go back to Main Menu:";
    cin >> op;
    while (op != "V" && op != "v") {
        keyError();
        cout << "\nPress [V] to go back to Main Menu:";
        cin >> op;
    }
}

/**
 * Temporal complexity O(k).
 * @param countFails is a vector of pairs that counts how many edges have been removed from a vertex's adjacency list in a newly generated subgraph.
 * @param k is an integer that comes from user input to determine how many stations will be printed.
 */
void Design::DrawTopKFails(vector<pair<string, int>> countFails, int k) {
    cout << "\n" << "STATION" << " | " << "EDGES REMOVED";
    for(int i = 0; i < k; i++){
        cout << "\n" << countFails[i].first << " | " << countFails[i].second;
    }

    cout << "\n";
}