/* *******************************************************
 * Filename		:	Sample.h
 * Author		:	Muhammet Mert KUÞ
 * Date			:	05.01.2024
 * Description	:	Sample Class Header
 * ******************************************************/
#pragma once
#include "Location.h"
#include <iostream>

class Sample : public Location {
private:
    int index; // Index of the sample
    int clusterID; // ID of the cluster to which the sample belongs

public:
    // Constructor that initializes a Sample with an index and x, y coordinates
    Sample(int index, double x, double y);

    // Destructor
    ~Sample();

    // Getter function to retrieve the index of the sample
    int getIndex() const;

    // Getter function to retrieve the cluster ID of the sample
    int getClusterID() const;

    // Setter function to set the cluster ID of the sample
    void setClusterID(int id);

    // Function to calculate the distance between this Sample and another Sample
    double getDistance(const Sample& other) const;

    // Operator overload for comparison between Samples based on their index
    bool operator<(const Sample& other) const;

    // Friend function to overload the << operator for outputting Sample details
    friend std::ostream& operator<<(std::ostream& os, const Sample& sample);
};
