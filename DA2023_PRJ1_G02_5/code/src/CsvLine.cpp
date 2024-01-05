#include "../include/CsvLine.h"

CsvLine::CsvLine() = default;

CsvLine::CsvLine(const CsvLine &other) {
    values = other.values;
}

void CsvLine::parse(const string &line, char delimiter) {
    stringstream inputLine(line);

    string dataPlaceholder;
    while (getline(inputLine, dataPlaceholder, delimiter)) {
        values.push_back(dataPlaceholder);
    }
}

string CsvLine::getString(int col) {
    return values[col];
}

int CsvLine::getInt(int col) {
    return stoi(values[col]);
}

SERVICE_ENUM CsvLine::getService(int col) {
    if (values[col] == "STANDARD") {
        return STANDARD;
    } else {
        return ALFA_PENDULAR;
    }
}

double CsvLine::getDouble(int col) {
    return stod(values[col]);
}

bool CsvLine::operator==(const CsvLine &other) const {
    return values == other.values;
}

CsvLine& CsvLine::operator=(const CsvLine &other) {
    values = other.values;
}

