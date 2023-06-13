#include <bits/stdc++.h>

using namespace std;
void solve(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(0, nums, ds, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    printAns(ans);
    return 0;
}