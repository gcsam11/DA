#pragma once

#include <string>
#include <utility>

using namespace std;

class Station {
public:
    Station(string  name, string  dist, string  muni, string  tnship, string  line);

    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;

    bool operator==(const Station& other) const ;
    bool operator!=(const Station& other) const ;
    bool operator<(const Station& other) const ;
    bool operator>(const Station& other) const ;
private:
    string name;
    string dist;
    string muni;
    string tnship;
    string line;
};