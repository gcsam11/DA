#pragma once

#include <iostream>
#include <vector>
#include "Station.h"

using namespace std;

class Design{
public:
    static void displayMenu();
    static void keyError();
    static void back();
    static void DrawTopKFails(vector<pair<string, int>> countFails, int k);
};