#include <bits.stdc++.h>
using namespace std;

int optimal(vector<int> &nums)
{
    int currLen = 1;
    int maxLen = 0;
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
            continue;
        if (nums[i - 1] + 1 == nums[i])
        {
            currLen++;
        }
        else
        {
            if (maxLen < currLen)
                maxLen = currLen;
            currLen = 1;
        }
    }
    maxLen = max(maxLen, currLen);
    return maxLen;
    // tc -> o(n)
}

int main()
{
    vector<int> arr{100, 200, 1, 2, 3, 4};
    int lon = optimal(arr);
    cout << "Ans -> " << lon << endl;
}