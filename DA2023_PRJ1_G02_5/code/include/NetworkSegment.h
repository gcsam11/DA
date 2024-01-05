#pragma once

#include <string>
#include <utility>

using namespace std;

enum SERVICE_ENUM {
    STANDARD,
    ALFA_PENDULAR
};

class NetworkSegment {
public:
    NetworkSegment(string  stationA, string  stationB, const double& capacity, const SERVICE_ENUM& service);

    string getStationA() const;
    string getStationB() const;
    int getCapacity() const;
    SERVICE_ENUM getService() const;

    bool operator==(const NetworkSegment& other);
private:
    string stationA;
    string stationB;
    int capacity;
    SERVICE_ENUM service;
};