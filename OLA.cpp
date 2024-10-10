#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int totalCarCoverage(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Sort intervals by the start time
    sort(intervals.begin(), intervals.end());
    
    int totalLength = 0;
    int currentStart = intervals[0].first;
    int currentEnd = intervals[0].second;
    
    // Traverse through the sorted intervals and merge them
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= currentEnd) {
            // Overlapping intervals, extend the current end if necessary
            currentEnd = max(currentEnd, intervals[i].second);
        } else {
            // Non-overlapping interval, add the previous interval's length
            totalLength += (currentEnd - currentStart);
            // Move to the next interval
            currentStart = intervals[i].first;
            currentEnd = intervals[i].second;
        }
    }
    
    // Add the last merged interval
    totalLength += (currentEnd - currentStart)+1;
    
    return totalLength;
}

int main() {
    vector<pair<int, int>> intervals = {{4, 7}, {-1, 5}, {3, 6}};
    
    int result = totalCarCoverage(intervals);
    cout << "Total time covered by cars on the road: " << result << endl;

    return 0;
}
