#include <bits/stdc++.h>
using namespace std;
    void rotate(vector<vector<int>>& matrix) {
        //Leetcode solution
        vector<vector<int>> grid=matrix;


        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[j][n-1-i]=grid[i][j]; 
        }
    }        
}
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    // code studio
    if(n==1 || m==1) return;
    int top = 0, bot = n-1, left = 0, right = m-1;
    while (top < bot && left < right) {
      int temp = mat[left][top];

      for (int i = top; i < bot; i++)
        mat[i][left] = mat[i + 1][left];

      for (int i = left; i < right; i++)
        mat[bot][i] = mat[bot][i + 1];

      for (int i = bot; i > top; i--)
        mat[i][right] = mat[i - 1][right];

      for (int i = right; i > left + 1; i--)
        mat[top][i] = mat[top][i - 1];

      mat[top][left + 1] = temp;
      top++, bot--, left++, right--;
    }
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int n = mat.size();
    int m = mat[0].size();

    rotateMatrix(mat,n,m);

    for(int i = 0; i<n;i++){
        for(int j = 0; j< m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}