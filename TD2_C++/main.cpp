#include "ex.h"

using namespace std;

int main() {
    vector<int> z = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    LinearSearch linearSearch;
    JumpSearch jumpSearch;
    BinarySearch binarySearch;

    int target = 10;

    int linearResult = linearSearch.search(z, target);
    linearSearch.displaySearchResults(cout, target, linearResult);

    int jumpResult = jumpSearch.search(z, target);
    jumpSearch.displaySearchResults(cout, target, jumpResult);

    int binaryResult = binarySearch.search(z, target);
    binarySearch.displaySearchResults(cout, target, binaryResult);

    return 0;
}

