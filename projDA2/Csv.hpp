#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class CsvLine {
    public:
        explicit CsvLine(const string &line);
        CsvLine(const CsvLine& other);

        CsvLine& operator=(const CsvLine& other);
        bool operator== (const CsvLine& other) const;

        [[nodiscard]] string getString(int col) const;
        [[nodiscard]] int getInt(int col) const;
        [[nodiscard]] float getFloat(int col) const;
        [[nodiscard]] double getDouble(int col) const;

    private:
        vector<string> values;

        void parse(const string& line);
};

class CsvReader {
    public:
        static vector<CsvLine> readCsvFile(const string& fileName, bool hasHeader = false);
};
