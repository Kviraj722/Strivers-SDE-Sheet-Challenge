#include <bits/stdc++.h>
using namespace std;
void findcomB(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (candidates[ind] <= target)
    {
        ds.push_back(candidates[ind]);
        findcomB(ind, target - candidates[ind], candidates, ans, ds);
        ds.pop_back();
    }

    findcomB(ind + 1, target, candidates, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;

    findcomB(0, target, candidates, ans, ds);
    return ans;
}
int main()
{
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}