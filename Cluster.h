/* *******************************************************
 * Filename		:	Cluster.h
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	Header file for the Cluster class
 * ******************************************************/

#pragma once

#include "Location.h"
#include <iostream>
#include <vector>
#include <memory> 
#include "Sample.h"

 // Cluster class representing a cluster with its associated samples
class Cluster : public Location {
private:
    int clusterID;                    // The ID of the cluster
    std::vector<Sample*> samples;     // Collection of samples in the cluster

public:
    // Constructor for Cluster
    Cluster(int clusterID, double x, double y);

    // Destructor for Cluster
    ~Cluster();

    // Get the ID of the cluster
    int getClusterID() const;

    // Get the samples in the cluster
    const std::vector<Sample*>& getSamples() const;

    // Add a sample to the cluster
    void addSample(Sample* sample);

    // Remove a sample from the cluster based on its index
    void removeSample(int index);

    // Update the center position of the cluster based on its samples
    void updateCenter();
};
