/* *******************************************************
 * Filename     : Location.cpp
 * Author       : Muhammet Mert KUÞ
 * Date         : 05.01.2024
 * Description  : Implementation file for the Location class
 * ******************************************************/

#include "Location.h"
#include <cmath>
#include <fstream>
#include <iostream>

 // Constructor initializing Location with given x and y coordinates
Location::Location(double x, double y) : x(x), y(y) {}

// Copy constructor
Location::Location(const Location& other) : x(other.x), y(other.y) {}

// Destructor
Location::~Location() {}

// Assignment operator for assigning one Location object to another
Location& Location::operator=(const Location& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Setter function to set a new x-coordinate for the location
void Location::setX(double newX) {
    x = newX;
}

// Setter function to set a new y-coordinate for the location
void Location::setY(double newY) {
    y = newY;
}

// Getter function to retrieve the x-coordinate of the location
double Location::getX() const {
    return x;
}

// Getter function to retrieve the y-coordinate of the location
double Location::getY() const {
    return y;
}

// Function to calculate the distance between this Location and another Location
double Location::calculateDistance(const Location& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    // Euclidean distance formula: sqrt((x2 - x1)^2 + (y2 - y1)^2)
    return sqrt(dx * dx + dy * dy);
}

// Function to write Location details to a file, including cluster ID and sample number
void Location::writeToFile(const std::string& filename, int clusterID, int sampleNumber) const {
    std::ofstream outFile(filename, std::ios_base::app);  // Open the file in append mode
    if (!outFile.is_open()) {
        // Display an error message if the file cannot be opened
        std::cerr << "Error: Unable to open the file for writing: " << filename << std::endl;
        return;
    }

    outFile << "Sample Number: " << sampleNumber + 1 << "\n"; // Write sample number
    outFile << "X Coordinate: " << getX() << "\n"; // Write x-coordinate
    outFile << "Y Coordinate: " << getY() << "\n"; // Write y-coordinate
    outFile << "Cluster ID: " << clusterID + 1 << "\n\n";  // Write cluster ID

    outFile.close();  // Close the file
}
