/* *******************************************************
 * Filename		:	Cluster.cpp
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	Implementation file for the Cluster class
 * ******************************************************/

#include "Cluster.h"
#include <iomanip>

 // Constructor for Cluster class
Cluster::Cluster(int clusterID, double x, double y)
    : Location(x, y), clusterID(clusterID) {}

// Destructor for Cluster class
Cluster::~Cluster() {}

// Get the ID of the cluster
int Cluster::getClusterID() const {
    return clusterID;
}

// Get the samples vector in the cluster
const std::vector<Sample*>& Cluster::getSamples() const {
    return samples;
}

// Add a sample to the cluster
void Cluster::addSample(Sample* sample) {
    samples.push_back(sample);
    updateCenter(); // Update the center when adding a sample
}

// Remove a sample from the cluster based on its index
void Cluster::removeSample(int index) {
    // Use remove_if with a lambda function to find and remove the sample
    std::vector<Sample*>::iterator it = std::remove_if(samples.begin(), samples.end(), [index](Sample* s) {
        return s->getIndex() == index;
        });
    // Erase the removed samples from the vector
    samples.erase(it, samples.end());
    updateCenter(); // Update the center after removing a sample
}

// Update the center position of the cluster based on its samples
void Cluster::updateCenter() {
    if (!samples.empty()) {
        double sumX = 0.0;
        double sumY = 0.0;

        // Calculate the sum of x and y coordinates of all samples in the cluster
        for (const Sample* sample : samples) {
            sumX += sample->getX();
            sumY += sample->getY();
        }

        // Update the center coordinates based on the average of sample coordinates
        setX(sumX / samples.size());
        setY(sumY / samples.size());
    }
}
