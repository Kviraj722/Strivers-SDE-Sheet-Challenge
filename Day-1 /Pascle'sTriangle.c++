#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangleOptimal(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void printPascalTriangleOptimal(int n) {
    long long ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
int pascalTriangle(int r, int c) {

    int element = nCr(r - 1, c - 1);
    return element;
    //printing the entire row
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    TC -> O(n*r)
    }
    cout << "n";
    //TC -> O(c)

}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    // int n = 5;
    // printPascalTriangleOptimal(n);
    // return 0;
    return 0;
}
        