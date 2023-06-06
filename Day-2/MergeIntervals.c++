#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int> > mergeIntervals;
        if(intervals.size() == 0) return mergeIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval = intervals[0];
        for(auto it : intervals){
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1],tempInterval[1]);
            }else{
                mergeIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergeIntervals.push_back(tempInterval);
        return mergeIntervals;
}

int main() {
    vector<vector<int>> arr = {{1,4},{4,5}};
    vector<vector<int>> ans = mergeIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}