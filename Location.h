/* *******************************************************
 * Filename     : Location.h
 * Author       : Muhammet Mert KUÞ
 * Date         : 05.01.2024
 * Description  : Header file for the Location class
 * ******************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Location {
private:
    double x; // X-coordinate of the location
    double y; // Y-coordinate of the location

public:
    // Constructor initializing the Location with given x and y coordinates
    Location(double x, double y);

    // Copy constructor
    Location(const Location& other);

    // Destructor
    ~Location();

    // Assignment operator for assigning one Location object to another
    Location& operator=(const Location& other);

    // Getter functions to retrieve x and y coordinates
    double getX() const;
    double getY() const;

    // Setter functions to set new x and y coordinates
    void setX(double newX);
    void setY(double newY);

    // Function to calculate the distance between this Location and another Location
    double calculateDistance(const Location& other) const;

    // Function to write Location details to a file, including cluster ID and sample number
    void writeToFile(const std::string& filename, int clusterID, int sampleNumber) const;
};
