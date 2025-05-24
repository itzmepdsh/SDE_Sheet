#include<bits/stdc++.h>

//rotate matrix
class Solution {
public:

    void getTranspose(vector<vector<int>>& matrix, int n){
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void reverseRowWise(vector<vector<int>>& matrix, int n){
        for(int i=0;i<n;i++){
            int l=0,h=n-1;
            while(l<h){
                swap(matrix[i][l],matrix[i][h]);
                l++;h--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        getTranspose(matrix,n);
        reverseRowWise(matrix,n);
    }
};

