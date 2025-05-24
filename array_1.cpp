#include<bits/stdc++.h>

//set matrix zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isfirstcol = false, isfirstrow = false;
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0){
                isfirstcol = true;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j] == 0){
                isfirstrow = true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j] == 0){
                for(int i=1;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isfirstcol){
            for(int i=0;i<m;i++)matrix[i][0] = 0;
        }
        if(isfirstrow){
            for(int j=0;j<n;j++)matrix[0][j] = 0;
        }
    }
};

//Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<=i;j++){
                row.push_back(((i-j+1)*row.back())/j);
            }
            res.push_back(row);
        }
        return res;
    }
};

//Next Permutation 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot_idx = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot_idx = i;
                break;
            }
        }
        if(pivot_idx == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        int just_greater_idx = -1;
        int ele = INT_MAX;
        for(int j=pivot_idx+1;j<n;j++){
            if(nums[j] > nums[pivot_idx]){
                ele = min(ele,nums[j]);
                just_greater_idx = j;
            }
        }
        swap(nums[pivot_idx],nums[just_greater_idx]);
        //cout<<pivot_idx<<endl;
        sort(nums.begin()+pivot_idx+1,nums.end());
        return ;
    }
};

//Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int cursum = nums[0], maxsum =nums[0];
        for(int i=1;i<n;i++){
            cursum = max(cursum+nums[i],nums[i]);
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};

//Sort 0s, 1s and 2s
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0,m=0,h=n-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};

//Buy and sell stocks
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            profit = max(profit,prices[i]-mn);
            mn = min(mn,prices[i]);
        }
        return profit;
    }
};