/* *******************************************************
 * Filename    : main.cpp
 * Author      : Muhammet Mert KUÞ
 * Date        : 05.01.2024
 * Description : Main Program for K-Means Clustering
 * ******************************************************/

#include "Location.h"
#include "KMeans.h"
#include <ctime>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    try {
        // K-Means parameters
        int K = 5; // Number of clusters
        int maxIterations = 1000; // Maximum iterations for K-Means algorithm

        // Create an instance of the KMeans class
        KMeans kmeans(K);

        // Read samples from file
        kmeans.readSamplesFromFile("40.txt");

        // Assign random clusters to samples
        kmeans.setRandomInitialClusters();

        // Run K-Means algorithm
        kmeans.runKMeans(maxIterations);

        // Write the results to an output file
        kmeans.writeSamplesToFile("output.txt");

        // Print details of each cluster and its samples to the console
        kmeans.printClusters();

        // Plot clusters using Matplotlib
        kmeans.plotClusters();
    }
    catch (const std::exception& e) {
        // Handle exceptions and print an error message
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
