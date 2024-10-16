#ifndef EX_H
#define EX_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class SearchingAlgorithm {
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparison;

public:
    SearchingAlgorithm(); 

    virtual int search(vector<int>& a, int p) = 0;

    void displaySearchResults(ostream& flux, int target, int result);
};

class LinearSearch : public SearchingAlgorithm {
public:
    int search(vector<int>& a, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(vector<int>& a, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(vector<int>& a, int target) override;
};

#endif
