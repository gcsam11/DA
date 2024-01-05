#include <iostream>
#include "Csv.hpp"

CsvLine::CsvLine(const string &line) {
    parse(line);
}

CsvLine::CsvLine(const CsvLine &other) {
    values = other.values;
}

CsvLine &CsvLine::operator=(const CsvLine &other) = default;

bool CsvLine::operator==(const CsvLine &other) const {
    return values == other.values;
}

string CsvLine::getString(int col) const {
    return values[col];
}

int CsvLine::getInt(int col) const {
    return stoi(values[col]);
}

float CsvLine::getFloat(int col) const {
    return stof(values[col]);
}

double CsvLine::getDouble(int col) const {
    return stod(values[col]);
}

void CsvLine::parse(const string &line) {
    stringstream inputLine(line);

    string value;
    while (getline(inputLine, value, ',')) {
        values.push_back(value);
    }
}

vector<CsvLine> CsvReader::readCsvFile(const string &fileName, bool hasHeader) {
    ifstream inputFile;
    vector<CsvLine> CsvLines;

    inputFile.open(fileName);

    string line;
    if (hasHeader) getline(inputFile, line);

    while (getline(inputFile, line)) {
        CsvLine csvLine(line);
        CsvLines.push_back(csvLine);
    }

    return CsvLines;
}
