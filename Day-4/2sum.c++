#include <bits/stdc++.h>
using namespace std;
vector<int> bruteForce(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
vector<int> better(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}


string optimal(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
    //this approach is only and only for this veriation, If we want to return index, better would be the perfect solution
}

int main()
{
    int n = 5, target = 14;
    vector<int> arr = {2, 6, 5, 8, 11};
    // string result = bruteForce(n, arr, target);
    string result = better(n, arr, target);
    
    cout << result << endl;
    return 0;
}