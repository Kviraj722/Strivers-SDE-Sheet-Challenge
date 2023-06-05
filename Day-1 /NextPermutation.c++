#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1]){
            ind=i;
            break;
        }
    }
    if (ind == -1) {
      reverse(permutation.begin(), permutation.end());
      return permutation;
    }
    for(int i=n-1;i>=0;i--)    {
        if (permutation[i] > permutation[ind]){
            swap(permutation[ind], permutation[i]);
            break;
      }
    }
    sort(permutation.begin()+ind+1,permutation.end());
    return permutation;
    // TC -> O(3N)
    //SC -> O(1)
}

int main(){
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    int n = A.size();
    vector<int> ans = nextPermutation(A,n);
    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}

//The one thing you can do is, next_permutation(arr,arr+3); is a in-built function of C++ STL 