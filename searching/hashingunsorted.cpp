#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<int, int> findPairWithSum(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> numMap; // Map to store number and its index

    for (int i = 0; i < arr.size(); ++i) {
        int complement = targetSum - arr[i];
        if (numMap.find(complement) != numMap.end()) {
            // Found the pair
            return {complement, arr[i]};
        }
        // Store current number and its index
        numMap[arr[i]] = i;
    }

    // If no pair found
    return {-1, -1};
}

int main() {
    vector<int> arr = {3, 5, 2, 8, 11, 7};
    int targetSum = 10;

    pair<int, int> result = findPairWithSum(arr, targetSum);

    if (result.first != -1 && result.second != -1) {
        cout << "Pair with sum " << targetSum << ": " << result.first << " and " << result.second << endl;
    } else {
        cout << "No such pair found" << endl;
    }

    return 0;
}
