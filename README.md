# K-Means Clustering Implementation

This repository contains the source code and implementation details for the K-Means clustering method, developed as part of the lab final assignment for the Object-Oriented Programming I course during the 2023-2024 Fall semester.

## Project Overview

The goal of this project was to design a class hierarchy to implement the K-Means clustering algorithm. The implementation includes the following key classes:

- **Sample:**
  - Represents an individual data point with an index, cluster ID, and features (x and y coordinates).
  - Provides methods for accessing and modifying sample attributes.

- **Cluster:**
  - Represents a cluster with a unique cluster ID.
  - Contains a collection of samples belonging to the cluster.
  - Provides methods for adding and removing samples, calculating cluster center, and other cluster-related operations.

- **KMeans:**
  - Implements the K-Means clustering algorithm, utilizing the Sample and Cluster classes.
  - Includes methods for clustering samples, updating cluster assignments, and calculating cluster centers.
  - Facilitates interaction with the dataset and manages the clustering process.

- **Location:**
  - A specialized class representing the coordinates (x and y) of a point.
  - Includes methods for manipulating and accessing the location attributes.

## Dependencies

- **Matplot Library:**
  - Matplot library is needed to obtain graphical results. You can find the library [here]
(https://matplotlib-cpp.readthedocs.io/en/latest/).

## Implementation Details

- **Private Data Members:**
  - All data members in each class are private, ensuring encapsulation.

- **Constructors and Destructors:**
  - Each class contains constructors and destructors for proper initialization and resource management.

- **Validation and Exception Handling:**
  - Robust data validation and exception handling mechanisms are implemented where necessary.

- **Get and Set Functions:**
  - Appropriate get and set functions are provided for accessing and modifying class attributes.

- **File Handling:**
  - Functions for reading data from the "40.txt" file and other relevant file operations are implemented.

- **Utility Functions:**
  - Utility functions are included for K-means clustering calculations and other operations.

## Usage

1. Clone the repository.
2. Compile the source code using a C++ compiler.
3. Execute the compiled program in the console.



## Additional Information

- The implementation adheres to object-oriented programming principles, including encapsulation, composition, inheritance, and exception handling.

Feel free to explore the code and reach out for any questions or feedback!
