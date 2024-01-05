#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Design {
public:
    static void displayMenu(const vector<string>& menuOptions);
    static void printTable(const vector<string>& rowHeaders, const vector<string>& colHeaders, const vector<vector<string>>& values);
    static void drawTriangularApproximation();
};
