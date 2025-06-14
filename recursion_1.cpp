#include<bits/stdc++.h>

//kth permutation sequence
class Solution {
public:
    string res = "";
    void kthperm(string s, int k, int& cnt, int idx, int n){
        //base case
        if(idx == n || cnt == k){
            cnt++;
            if(cnt == k){
                res = s;
            }
            return;
        }
        //recursive case
        for(int j=idx;j<n;j++){
            swap(s[idx],s[j]);
            kthperm(s,k,cnt,idx+1,n);
        }
    }

    string getPermutation(int n, int k) {
        string s = "";
        for(char ch = '1';ch < '1'+n; ch++){
            s += ch;
        }
        int cnt = 0;
        kthperm(s,k,cnt,0,n);
        return res;
    }
};

//subsets
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int n, int i){
        //base case
        if(i==n){
            res.push_back(subset);
            return;
        }
        //recursive case
        solve(nums,subset,res,n,i+1);
        subset.push_back(nums[i]);
        solve(nums,subset,res,n,i+1);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        int n = nums.size();
        solve(nums,subset,res,n,0);
        return res;
    }
};

//subsets-2
class Solution {
public:
    void solve(vector<int>& nums, int n, vector<int> subset, vector<vector<int>>& res, int i){
        res.push_back(subset);
        
        //recursive case
        for(int j=i;j<n;j++){
            if(j>i && nums[j] == nums[j-1])
                continue;
            subset.push_back(nums[j]);
            solve(nums,n,subset,res,j+1);
            subset.pop_back(); //backtrack
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        solve(nums,n,subset,res,0);
        return res;
    }
};

//Combination Sum
class Solution {
public:
    void solve(vector<int>& nums, int n, int target, vector<int>& comb, vector<vector<int>>& res, int crsum, int idx){
        //base case
        if(crsum == target){
            res.push_back(comb);
            return;
        }
        if(crsum > target)
            return;
        //recursive case
        for(int j=idx;j<n;j++){
            comb.push_back(nums[j]);
            solve(nums, n, target, comb,res,crsum+nums[j],j);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> comb;
        vector<vector<int>> res;
        int crsum = 0;
        solve(nums,n,target,comb,res,crsum,0);
        return res;
    }
};

//Combination Sum-2 
class Solution {
public:
    void solve(vector<int> nums, int n, int target, int crsum, vector<int> comb, vector<vector<int>>& res, int idx){
        //base case
        if(crsum == target){
            res.push_back(comb);
            return;
        }
        if(crsum > target)
            return; 
        //recursive case
        for(int j=idx;j<n;j++){
            if(j>idx && nums[j] == nums[j-1])
                continue;
            comb.push_back(nums[j]);
            solve(nums,n,target,crsum+nums[j],comb,res,j+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int crsum = 0;
        vector<int> comb;
        vector<vector<int>> res;
        solve(nums,n,target,crsum,comb,res,0);
        return res;
    }
};

//Palindrome Partitioning
class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, int n, vector<string> part, vector<vector<string>>& res, int idx){
        //base case
        if(idx == n){
            res.push_back(part);
            return;
        }
        //recursive case
        for(int len=1;len<=n-idx;len++){
            string subs = s.substr(idx,len);
            if(isPalindrome(subs)){
                part.push_back(subs);
                solve(s,n,part,res,idx+len);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> part;
        vector<vector<string>> res;
        solve(s,n,part,res,0);
        return res;
    }
};

