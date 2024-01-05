#pragma once

#include <string>
#include <vector>
#include <sstream>

#include "NetworkSegment.h"

using namespace std;

class CsvLine {
public:
    CsvLine();
    CsvLine(const CsvLine& other);

    void parse(const string& line, char delimiter = ',');

    string getString(int col);
    int getInt(int col);
    double getDouble(int col);
    SERVICE_ENUM getService(int col);

    bool operator== (const CsvLine& other) const;
    CsvLine& operator=(const CsvLine& other);
private:
    vector<string> values;
};