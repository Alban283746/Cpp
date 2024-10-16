#include "ex.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparison = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(ostream& os, int target, int result) {
    totalSearch++;
    if (result == -1) {
        os << "Element " << target << " not found.\n";
    } else {
        totalComparisons += numberComparisons;
        averageComparison = static_cast<double>(totalComparisons) / totalSearch;
        
        os << "Element " << target << " found at index " << result << ".\n";
        os << "Total comparisons: " << totalComparisons << "\n";
        os << "Average comparisons per search: " << averageComparison << "\n";
    }
}

int LinearSearch::search(vector<int>& a, int target) {
    numberComparisons = 0;
    for (size_t i = 0; i < a.size(); i++) {
        numberComparisons++;
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int JumpSearch::search(vector<int>& a, int target) {
    numberComparisons = 0;
    int n = a.size();
    int step = sqrt(n);
    int prev = 0;

    while (a[min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        numberComparisons++;
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int BinarySearch::search(vector<int>& a, int target) {
    numberComparisons = 0;
    int left = 0, right = a.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
