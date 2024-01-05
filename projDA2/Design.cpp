#include "Design.hpp"

void Design::displayMenu(const vector<string>& menuOptions) {
    int rowTotalWidth = 46;
    int rowOptionWidth = 44;

    cout << "\n+" << string(rowTotalWidth, '-') << "+\n";

    cout << "|          __  __ ______ _   _ _    _          |\n"
            "|         |  \\/  |  ____| \\ | | |  | |         |\n"
            "|         | \\  / | |__  |  \\| | |  | |         |\n"
            "|         | |\\/| |  __| | . ` | |  | |         |\n"
            "|         | |  | | |____| |\\  | |__| |         |\n"
            "|         |_|  |_|______|_| \\_|\\____/          |\n"
            "|                                              |\n";

    cout << "+" << string(rowTotalWidth, '-') << "+" << endl;

    for (int i = 0; i < menuOptions.size(); ++i) {
        string numberOption = "[" + to_string((i + 1)) + "] ";
        string textOption = menuOptions[i];
        int rowTextWidth = rowOptionWidth - numberOption.size();

        if (textOption.size() > rowTextWidth) {
            textOption = textOption.substr(0, rowTextWidth);
        }
        cout << "| " << numberOption << textOption << string(rowTextWidth - textOption.size(), ' ') << " |" << endl;
    }

    cout << "| "<< "[Q] Quit" << string(rowOptionWidth - 8, ' ') << " |" << endl;
    cout << "+" << string(rowTotalWidth, '-') << "+";
}

void Design::printTable(const vector<string>& rowHeaders, const vector<string>& colHeaders, const vector<vector<string>>& values) {
    int cellWidth = 10;
    cout << left << setw(cellWidth) << " ";
    for (const auto& colHeader : colHeaders) {
        cout << left << setw(cellWidth) << colHeader;
    }
    cout << endl;
    for (int i = 0; i < rowHeaders.size(); ++i) {
        cout << left << setw(cellWidth) << rowHeaders[i];
        for (int j = 0; j < colHeaders.size(); ++j) {
            if (i < values.size() && j < values[i].size()) {
                cout << left << setw(cellWidth) << values[i][j];
            } else {
                cout << left << setw(cellWidth) << " ";
            }
        }
        cout << endl;
    }
}

void Design::drawTriangularApproximation() {
    cout << "\n+----------------------------------------------+\n"
            "|          __  __ ______ _   _ _    _          |\n"
            "|         |  \\/  |  ____| \\ | | |  | |         |\n"
            "|         | \\  / | |__  |  \\| | |  | |         |\n"
            "|         | |\\/| |  __| | . ` | |  | |         |\n"
            "|         | |  | | |____| |\\  | |__| |         |\n"
            "|         |_|  |_|______|_| \\_|\\____/          |\n"
            "|                                              |\n"
            "+----------------------------------------------+\n"
            "| [1] - Stadiums Graph                         |\n"
            "| [2] - Tourism Graph                          |\n"
            "| [3] - Real Graph 1                           |\n"
            "| [4] - Real Graph 2                           |\n"
            "| [5] - Real Graph 3                           |\n"
            "| [6] - Edges 25                               |\n"
            "| [7] - Edges 50                               |\n"
            "| [8] - Edges 75                               |\n"
            "| [9] - Edges 100                              |\n"
            "| [10] - Edges 200                             |\n"
            "| [11] - Edges 300                             |\n"
            "| [12] - Edges 400                             |\n"
            "| [13] - Edges 500                             |\n"
            "| [14] - Edges 600                             |\n"
            "| [15] - Edges 700                             |\n"
            "| [16] - Edges 800                             |\n"
            "| [17] - Edges 900                             |\n"
            "| [V] - Go Back                                |\n"
            "|______________________________________________|";

}