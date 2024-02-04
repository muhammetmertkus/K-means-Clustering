/* *******************************************************
 * Filename		:	Sample.h
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	Sample Class Header
 * ******************************************************/#pragma once
#include "Sample.h"
#include <vector>
#include "Cluster.h"
#include <algorithm>
#include <iostream>

// The KMeans class encapsulates the KMeans algorithm for grouping samples into clusters.
class KMeans {
private:
    int K;  // Private member variable representing the number of clusters.
    std::vector<Sample*> samples;  // Vector holding pointers to samples.
    std::vector<Cluster> clusters;  // Vector holding clusters.
    int getK() const;  // Private helper function returning the number of clusters.

public:
    KMeans(int K);  // Constructor for the KMeans class.
    ~KMeans();  // Destructor for the KMeans class.

    // Function to read samples from a file.
    void readSamplesFromFile(const std::string& filename);

    // Function to set random initial clusters.
    void setRandomInitialClusters();

    // Function to execute the KMeans algorithm.
    void runKMeans(int maxIterations);

    // Function to update which cluster each sample belongs to.
    void updateSamplesClusters();

    // Function to update cluster centers.
    void updateClusterCenters();

    // Function to calculate how far a sample is from a cluster.
    double calculateDistance(const Sample& sample, const Cluster& cluster);

    // Function to print clusters to the console.
    void printClusters() const;

    // Function to plot clusters.
    void plotClusters() const;

    // Function to write samples to a file.
    void writeSamplesToFile(const std::string& filename) const;

    // Function to sort samples within clusters.
    void sortSamplesInClusters() const;

    // Function to return the vector of sample pointers.
    const std::vector<Sample*>& getSamples() const;
};
