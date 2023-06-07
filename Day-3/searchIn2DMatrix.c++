#include <bits/stdc++.h>
using namespace std;

bool optimalSolution(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int left = 0;
    int right = (n * m) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mat[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (mat[mid / m][mid % m] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
    // tc-> o(log(n*m))
    // sc -> o(1)
}
bool bruteForce(vector<vector<int>> &mat, int target)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == target)
            {
                return true;
                break;
            }
        }
    }
    return false;
    // tc-> o{n^2}
    // sc -> o{1}
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int target = 8;
    // int ans = optimalSolution(matrix,target);
    int ans = bruteForce(matrix, target);

    cout << "ans  " << ans;
}
