#include "../include/Station.h"

Station::Station(string name, string dist, string muni,
                 string tnship, string line) :
                 name(move(name)), dist(move(dist)), muni(move(muni)), tnship(move(tnship)), line(move(line)) {}

string Station::getName() const {
    return name;
}

string Station::getDistrict() const {
    return dist;
}

string Station::getMunicipality() const {
    return muni;
}

string Station::getTownship() const {
    return tnship;
}

string Station::getLine() const {
    return line;
}

bool Station::operator==(const Station &other) const {
    return name == other.name;
}

bool Station::operator!=(const Station &other) const {
    return name != other.name;
}

bool Station::operator<(const Station &other) const {
    return name < other.name;
}

bool Station::operator>(const Station &other) const {
    return name > other.name;
}