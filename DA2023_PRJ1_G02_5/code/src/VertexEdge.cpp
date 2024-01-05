#include "../include/VertexEdge.h"

/************************* Vertex  **************************/

Vertex::Vertex(Station station): station(std::move(station)) {}

/**
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge * Vertex::addEdge(Vertex *d, const int& capacity, const SERVICE_ENUM& service, double w) {
    auto newEdge = new Edge(this, d, capacity, service, w);
    adj.push_back(newEdge);
    //residual edges are not incoming edges
    if (capacity != 0) {
        d->incoming.push_back(newEdge);
        d->indegree += 1;
    }
    return newEdge;
}

/**
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex::removeEdge(const string& destStation) {
    for (auto it = adj.begin(); it != adj.end(); it++) {
        Edge *edge = *it;
        Vertex *dest = edge->getDest();
        if (dest->getName() == destStation) {
            adj.erase(it);
            // Also remove the corresponding edge from the incoming list
            for(auto it2 = dest->incoming.begin(); it2 != dest->incoming.end(); it2++) {
                Edge* edge1 = *it2;
                Vertex *src = edge1->getOrig();
                if (src->getName() == this->getName()) {
                    dest->incoming.erase(it2);
                    break;
                }
            }
            for(auto it3 = dest->adj.begin(); it3 != dest->adj.end(); it3++) {
                Edge* edge2 = *it3;
                Vertex *dest1 = edge2->getDest();
                if (dest1->getName() == this->getName()) {
                    dest->adj.erase(it3);
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

string Vertex::getName() const {
    return station.getName();
}

string Vertex::getDistrict() const {
    return station.getDistrict();
}

string Vertex::getMunicipality() const {
    return station.getMunicipality();
}

string Vertex::getTownship() const {
    return station.getTownship();
}

string Vertex::getLine() const {
    return station.getLine();
}

vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}

void Vertex::setStation(Station _station) {
    this->station = move(_station);
}

void Vertex::setVisited(bool _visited) {
    this->visited = _visited;
}

void Vertex::setProcesssing(bool _processing) {
    this->processing = _processing;
}

void Vertex::setIndegree(unsigned int _indegree) {
    this->indegree = _indegree;
}

void Vertex::setDist(double _dist) {
    this->dist = _dist;
}

void Vertex::setPath(Edge *_path) {
    this->path = _path;
}


/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, const int& capacity, const SERVICE_ENUM& service, double w) :
           orig(orig), dest(dest), segment(orig->getName(), dest->getName(), capacity, service), weight(w) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

int Edge::getCapacity() const {
    return segment.getCapacity();
}

SERVICE_ENUM Edge::getService() const {
    return segment.getService();
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

int Edge::getFlow() const {
    return flow;
}

int Edge::remainingCapacity() const {
    return segment.getCapacity() - flow;
}

void Edge::augment(int bottleneck) {
    flow += bottleneck;
    reverse->flow -= bottleneck;
}

void Edge::setSelected(bool _selected) {
    this->selected = _selected;
}

void Edge::setReverse(Edge *_reverse) {
    this->reverse = _reverse;
}

void Edge::setFlow(double _flow) {
    this->flow = _flow;
}

void Edge::setWeight(double _weight) {
    this->weight = _weight;
}