#include<bits/stdc++.h>
#include<vector>

//Permutations
class Solution {
public:

    void f(vector<int>& nums, int n, vector<vector<int>>& res, int i){
        //base case
        if(i==n){
            res.push_back(nums);
            return;
        }
        //recursive case
        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            f(nums,n,res,i+1);
            swap(nums[j],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        f(nums,n,res,0);
        return res;
    }
};

