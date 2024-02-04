/* *******************************************************
 * Filename		:	KMeans.h
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	KMeans Class Implementation
 * ******************************************************/
#include "KMeans.h"
#include <fstream>
#include <algorithm>
#include "matplotlibcpp.h"
#include "Cluster.h"
#include <vector>
#include <memory>
#include <numeric>

namespace plt = matplotlibcpp;

// Constructor for the KMeans class
KMeans::KMeans(int K) : K(K) {}

// Destructor for the KMeans class
KMeans::~KMeans() {
    // Deallocate memory for sample objects
    for (Sample* sample : samples) {
        delete sample;
    }
}


// Read samples from a file and store them in the 'samples' vector
void KMeans::readSamplesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file: " + filename);
    }

    double x, y;
    // Read sample data from the file and create Sample objects
    for (int i = 0; i < 40; ++i) {
        file >> x >> y;
        samples.push_back(new Sample(i, x, y));
    }

    file.close();
}

// Getter method to retrieve the value of K
int KMeans::getK() const {
    return K;
}

// Getter method to retrieve the vector of sample pointers
const std::vector<Sample*>& KMeans::getSamples() const {
    return samples;
}


// Randomly assign initial clusters to the samples
// Randomly assign initial clusters to the samples
void KMeans::setRandomInitialClusters() {
    // Create clusters based on initial samples
    for (int i = 0; i < K; ++i) {
        clusters.emplace_back(i, samples[i]->getX(), samples[i]->getY());
    }

    // Randomly assign each sample to a cluster
    for (Sample* sample : samples) {
        int clusterID = rand() % K;
        sample->setClusterID(clusterID);
        clusters[clusterID].addSample(sample);
    }
}

// Execute the K-Means algorithm with a maximum number of iterations
void KMeans::runKMeans(int maxIterations) {
    // Iterate for the specified number of times
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // Update the clusters for each sample
        updateSamplesClusters();
        // Update the centers of each cluster
        updateClusterCenters();
    }
}


// Update the clusters to which each sample belongs
// Update the clusters to which each sample belongs
void KMeans::updateSamplesClusters() {
    for (Sample* sample : samples) {
        // Variables are created to store the closest cluster ID and distance of each sample
        double minDistance = std::numeric_limits<double>::max();
        int closestClusterID = -1;

        // Iterating through all clusters to find the cluster each sample is closest to
        for (const Cluster& cluster : clusters) {
            double distance = calculateDistance(*sample, cluster);
            if (distance < minDistance) { // If this cluster is closer than the previous closest one,
                minDistance = distance;
                closestClusterID = cluster.getClusterID();
            }
        }

        // If the sample is closer to a different cluster than its current one,
        if (sample->getClusterID() != closestClusterID) {
            clusters[sample->getClusterID()].removeSample(sample->getIndex());
            sample->setClusterID(closestClusterID);
            clusters[closestClusterID].addSample(sample);
        }
    }
}


// Update the centers of all clusters based on their samples
void KMeans::updateClusterCenters() {
    for (Cluster& cluster : clusters) {
        cluster.updateCenter();
    }
}

// Calculate the distance between a sample and a cluster's center
double KMeans::calculateDistance(const Sample& sample, const Cluster& cluster) {
    double dx = sample.getX() - cluster.getX();
    double dy = sample.getY() - cluster.getY();
    return sqrt(dx * dx + dy * dy);
}

// Print the details of each cluster and its samples to the console
// Print the details of each cluster and its samples to the console
void KMeans::printClusters() const {
    // Sort samples within clusters for a clearer output
    sortSamplesInClusters();

    // Display information for each cluster
    for (const Cluster& cluster : clusters) {
        std::cout << "Cluster " << cluster.getClusterID() + 1 << " Center: (" << cluster.getX() << ", " << cluster.getY() << ")\n";

        std::cout << "Samples:\n";

        // Display details of each sample in the cluster
        for (const Sample* sample : cluster.getSamples()) {
            std::cout << "  " << *sample << "\n";
        }

        std::cout << "\n";
    }
}


// Plot the clusters and their samples using matplotlib
// Plot the clusters and their samples using matplotlib
void KMeans::plotClusters() const {
    plt::clf();

    // Plot each cluster's samples with different markers and colors
    for (const Cluster& cluster : clusters) {
        std::vector<Sample*> sortedSamples = cluster.getSamples();
        std::vector<double> x, y;
        for (const Sample* sample : sortedSamples) {
            x.push_back(sample->getX());
            y.push_back(sample->getY());
        }

        // Write sample numbers near the points
        for (size_t i = 0; i < sortedSamples.size(); ++i) {
            plt::text(x[i], y[i], std::to_string(sortedSamples[i]->getIndex() + 1));
        }
        plt::scatter(x, y, 35, { {"label", "Samples in Cluster " + std::to_string(cluster.getClusterID() + 1)} });

        // Cluster centers
        std::vector<double> center_x = { cluster.getX() };
        std::vector<double> center_y = { cluster.getY() };

        // Plot cluster centers with the same color as the cluster
        std::string cluster_color = "C" + std::to_string(cluster.getClusterID()); // Use cluster color
        plt::scatter(center_x, center_y, 100, { {"color", cluster_color}, {"marker", "x"}, {"label", "Cluster " + std::to_string(cluster.getClusterID() + 1)} });
    }

    // Include the value of K in the plot title
    plt::title("K-Means Clustering (K=" + std::to_string(getK()) + ")");

    plt::xlabel("X-axis"); // Label for X-axis
    plt::ylabel("Y-axis"); // Label for Y-axis

    plt::legend(); // Display Label

    plt::show(); // Display the plot
}






// Write the details of each sample to a file
void KMeans::writeSamplesToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
        return;
    }

    // Write sample details (including cluster information) to the file
    for (const Sample* sample : samples) {
        sample->writeToFile(filename, sample->getClusterID(), sample->getIndex());
    }

    outFile.close();
}

// Sort samples within clusters based on their indices
void KMeans::sortSamplesInClusters() const {

    for (auto& cluster : clusters) {
        // Store samples within the cluster in a non-const vector to sort
        std::vector<Sample*> nonConstSamples(cluster.getSamples().begin(), cluster.getSamples().end());

        // Sort samples in ascending order based on their indices
        std::sort(nonConstSamples.begin(), nonConstSamples.end(),
            [](const Sample* a, const Sample* b) {
                return a->getIndex() < b->getIndex();
            });

        // Reinsert the sorted samples back into the cluster
        const_cast<std::vector<Sample*>&>(cluster.getSamples()) = nonConstSamples;
    }
}

