#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> optimalSolution(vector<vector<int>> &matrix, int n, int m) {

    int col0 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // marking i-th row:
                matrix[i][0] = 0;

                // marking j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    //  Marking with 0 and avoiding first row and first column:
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
    // TC -> O(2*(N*M))
    // SC -> O(1);
}
vector<vector<int>> betterSolution(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; 
    int col[m] = {0}; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
    //TC -> O(2*(N*M))
    //SC -> O(N) + O(M)
}
void rowMark(vector<vector<int>> &matrix, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void colMark(vector<vector<int>> &matrix, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
vector<vector<int>> convertedMatrix(vector<vector<int>> &matrix, int n, int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                rowMark(matrix, n, m, i);
                colMark(matrix, n, m, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
    //TC -> O(n^3);
    // SC -> O(1);
}
int main(){
    vector<vector<int> > matrix = { {1,1,1},
                                    {1,0,1},
                                    {1,1,1}}
    int n = matrix.size();
    int m = matrix[0].size()
    
    // vector<vector<int>> result = convertedMatrix(matrix, n, m);
    // vector<vector<int>> result = betterSolution(matrix, n, m);
    vector<vector<int>> result = optimalSolution(matrix, n, m);


        for (auto it : result) {
            for (auto ele : it) {
                cout << ele << " ";
            }
        cout << "n";
    }
    return 0;
}