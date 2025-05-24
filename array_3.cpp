#include<bits/stdc++.h>

//Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};

//Pow(x,n)
class Solution {
public:
    double calPow(double x, long long int n){
        //base case
        if(n==1)
            return x;
        //recursive case
        double y = calPow(x,n/2);
        if(n%2 == 0){
            return y*y;
        }
        return y*y*x;
    }
    double myPow(double x, int n) {
       if(n==0)return 1;
       if(x==0 || x==1)
            return x;
        long long int p = (long long int)n;
        double val = calPow(abs(x),abs(p));
        if(x < 0 && p%2)val = -val;
        if(p < 0)val = 1/val;
        return val;
    }
};

//Majority Elements (more than n/2 times)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i] == ele)cnt++;
            else{
                cnt--;
            }
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};

//Majority Elements (more than n/3 times)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,cnt2=0, ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i] != ele2){
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i] != ele1){
                ele2 = nums[i];
                cnt2++;
            }else if(nums[i] == ele1)cnt1++;
            else if(nums[i] == ele2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i] == ele1)cnt1++;
            if(nums[i] == ele2)cnt2++;
        }
        if(cnt1 > n/3)res.push_back(ele1);
        if(cnt2 > n/3)res.push_back(ele2);
        return res;
    }
};

//Unique Grids
class Solution {
public:
    int calPath(int m, int n, vector<vector<int>>& storage){
        //base case
        if(m == 1 || n == 1)
            return storage[m][n] = 1;
        //recursive case
        if(storage[m][n] != -1)return storage[m][n];
        return storage[m][n] = calPath(m-1,n,storage) + calPath(m,n-1,storage);
    }
    int uniquePaths(int m, int n) {
        //using recursion
        vector<vector<int>> storage(m+1,vector<int>(n+1,-1));
        return calPath(m,n,storage);

        //using maths
        int d = m-1,r = n-1;
        long long int res = 1;
        if(d < r)swap(d,r);
        int i=1,j=d+1;
        while(j<=d+r){
            res *= j;
            res /= i;
            i++;j++;
        }
        return (int)res;

        //using bottom-up DP
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//Reverse Pairs
class Solution {
public:
    int merge(vector<int>& arr ,int i, int mid, int j){
        int cnt = 0;
        vector<int> temp(j-i+1);
        int k =0,a=i,b=mid;
        int y=mid;
        for(int x=i;x<mid;x++){
            while(y<=j && arr[x] > (long long)2*arr[y]){
                y++;
            }
            cnt += y-mid;
        }
        while(a<mid && b <=j){
            if(arr[a] <= arr[b]){
                temp[k] = arr[a];
                a++;
            }else{
                temp[k] = arr[b];
                b++;
            }
            k++;
        }
        while(a<mid){
            temp[k] = arr[a];
            a++;k++;
        }
        while(b<=j){
            temp[k] = arr[b];
            b++;k++;
        }
        k=0;
        for(int x=i;x<=j;x++){
            arr[x] = temp[k++];
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int i, int j){
        //base case
        if(i>=j)
            return 0;
            
        //recursive case
        int cnt = 0;
        int mid = (i+j)/2;
        cnt += mergeSort(arr,i,mid);
        cnt += mergeSort(arr,mid+1,j);
        cnt += merge(arr,i,mid+1,j);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};

