#include <bits/stdc++.h>
using namespace std;

int optimalSol(vector<int> arr, int n, int k)
{
    int left = 0, right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += arr[right];
    }
}

int main()
{
    vector<int> arr = [ 1, 2, 3, 1, 1, 1, 1, 4, 2, 3 ];
    int n = arr.size();
    int k = 6;
    int ans = optimalSol(arr, n, k);
    cout << "ans " << endl;
}