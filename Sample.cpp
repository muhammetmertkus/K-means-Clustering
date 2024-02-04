/* *******************************************************
 * Filename		:	Sample.h
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	LineDetection Class Implementation
 * ******************************************************/
#include "Sample.h"
#include <iomanip>
// Sample class constructor
Sample::Sample(int index, double x, double y)
    : Location(x, y), index(index - 1), clusterID(-1) {}

// Sample class destructor
Sample::~Sample() {}

// Get the index of the sample
int Sample::getIndex() const {
    return index + 1;
}

// Get the cluster ID of the sample
int Sample::getClusterID() const {
    return clusterID;
}

// Set the cluster ID of the sample
void Sample::setClusterID(int id) {
    clusterID = id;
}

// Overloaded less-than operator for comparing sample indexes
bool Sample::operator<(const Sample& other) const {
    return getIndex() < other.getIndex();
}

// Get the distance between this sample and another sample
double Sample::getDistance(const Sample& other) const {
    return Location::calculateDistance(other);
}

// Overloaded stream insertion operator to print sample information
std::ostream& operator<<(std::ostream& os, const Sample& sample) {
    os << std::setw(3) << "Sample " << std::setw(3) << std::left << sample.getIndex() + 1 << ": ("
        << std::setw(8) << sample.getX() << ", " << std::setw(8) << sample.getY() << ") Cluster: " << sample.getClusterID() + 1;
    return os;
}
