#include "../include/CsvReader.h"

CsvReader::CsvReader() = default;

vector<CsvLine> CsvReader::read(const string &fileName, bool hasHeader) {
    ifstream inputFile;
    vector<CsvLine> lines;

    inputFile.open(fileName);

    string tempLine;
    if (hasHeader) getline(inputFile, tempLine);

    while (getline(inputFile, tempLine)) {
        CsvLine csvLine;
        csvLine.parse(tempLine);
        lines.push_back(csvLine);
    }

    return lines;
}