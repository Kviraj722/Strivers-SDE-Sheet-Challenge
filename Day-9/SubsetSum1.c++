#include <bits/stdc++.h>

using namespace std;

void solve(int ind, int sum, vector<int> &arr, vector<int> &ans, int N)
{
    if (ind == N)
    {
        ans.push_back(sum);
        return;
    }

    solve(ind + 1, sum + arr[ind], arr, ans, N);
    solve(ind + 1, sum, arr, ans, N);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    solve(0, 0, arr, ans, N);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr{3, 1, 2};

    vector<int> ans = subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}