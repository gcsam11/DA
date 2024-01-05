#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include "CsvLine.h"

using namespace std;

class CsvReader {
public:
    CsvReader();

    static vector<CsvLine> read(const string& fileName, bool hasHeader = false);
};