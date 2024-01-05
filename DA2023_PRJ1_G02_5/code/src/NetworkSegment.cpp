#include "../include/NetworkSegment.h"

NetworkSegment::NetworkSegment(string  stationA, string  stationB, const double& capacity, const SERVICE_ENUM& service) :
                               stationA(std::move(stationA)), stationB(std::move(stationB)), capacity(capacity), service(service) {}

string NetworkSegment::getStationA() const {
    return stationA;
}

string NetworkSegment::getStationB() const {
    return stationB;
}

int NetworkSegment::getCapacity() const {
    return capacity;
}

SERVICE_ENUM NetworkSegment::getService() const {
    return service;
}

bool NetworkSegment::operator==(const NetworkSegment &other) {
    return (stationA == other.stationA && stationB == other.stationB);
}