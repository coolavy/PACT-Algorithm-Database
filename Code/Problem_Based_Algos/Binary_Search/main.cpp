// Author: coolavy
// Language: C++
// Date: 12/6/2025

#include "bits/stdc++.h"
using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // to avoid overflow
        if (arr[mid] == target) { // target found
            return true;
        } else if (arr[mid] < target) { // right half
            low = mid + 1;
        } else { // left half
            high = mid - 1;
        }
    }

    return false;
}