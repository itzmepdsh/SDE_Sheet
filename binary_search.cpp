#include<bits/stdc++.h>
using namespace std;

//Find the element that appears once in a sorted array, and the rest element appears twice
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1;
        int res = -1;
        while(s<=e){
            int mid = (s+e)>>1;
            if(mid == 0 || mid == n-1){
                return nums[mid];
            }
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }else if(nums[mid] == nums[mid+1]){
                if(mid%2 == 0)
                    s=mid+1;
                else
                    e=mid-1;
            }else{
                if(mid%2 == 0)
                    e=mid-1;
                else
                    s=mid+1;
            }
        }
        return -1;
    }
};

//Search in rotated sorted array
class Solution {
public:
    int binary_search(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = (s+e)>>1;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = 0;
        int s=0,e=n-1;
        while(s<=e){
            int mid = (s+e)>>1;
            if(nums[mid] < nums[0]){
                pivot = mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        cout<<pivot<<endl;
        int idx = binary_search(nums,target,0,pivot-1);
        return (idx==-1) ? binary_search(nums,target,pivot,n-1) : idx;
    }
};

//Allocate minimum number of pages
class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int k ,long long mid){
        int numOfStudents = 1;
        long long int cur_pages = arr[0];
        for(int i=1;i<n;i++){
            cur_pages += arr[i];
            if(cur_pages > mid){
                numOfStudents++;
                cur_pages = arr[i];
            }
        }
        return numOfStudents <= k;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k)return -1;
        long long l = *max_element(arr.begin(),arr.end());
        long long u=0;
        for(int pages : arr){
            u += pages;
        }
        int res = -1;
        while(l<=u){
            long long mid = (l+u)>>1;
            if(isPossible(arr,n,k,mid)){
                res = (int)mid;
                u=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};

//Median of row-wise sorted matrix
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int ttl = m*n;
        int mn = INT_MAX,mx = INT_MIN;
        for(int i=0;i<m;i++){
            mn = min(mn,mat[i][0]);
            mx = max(mx,mat[i][n-1]);
        }
        int l = mn, h = mx;
        while(l <= h){
            int mid = (l+h)>>1;
            int numOfElements = 0;
            for(int i=0;i<m;i++){
                vector<int> row = mat[i];
                int cnt = upper_bound(row.begin(),row.end(),mid)-row.begin();
                numOfElements += cnt;
            }
            if(numOfElements <= ttl/2)l = mid+1;
            else h = mid-1;
        }
        return l;
    }
};

//kth element of the 2 sorted array
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
        if(n>m)return kthElement(b,a,k);
        int s=max(0,k-m),e=min(k,n);
        while(s<=e){
            int cnt1 = (s+e)>>1;
            int cnt2 = k-cnt1;
            int l1 = (cnt1==0)?INT_MIN:a[cnt1-1];
            int r1 = (cnt1==n)?INT_MAX:a[cnt1];
            int l2 = (cnt2==0)?INT_MIN:b[cnt2-1];
            int r2 = (cnt2==m)?INT_MAX:b[cnt2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }else if(l1 > r2){
                e = cnt1-1;
            }else{
                s = cnt1+1;
            }
        }
        return -1;
    }
};

//Median of two sorted array
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m)return findMedianSortedArrays(nums2,nums1);
        int ttl = n+m;
        int half = (ttl+1)/2;
        int l=0,h=n;
        while(l<=h){
            int cnt1 = (l+h)>>1;
            int cnt2 = half-cnt1;
            int l1 = (cnt1 == 0)? INT_MIN : nums1[cnt1-1];
            int r1 = (cnt1 == n)? INT_MAX : nums1[cnt1];
            int l2 = (cnt2 == 0)? INT_MIN : nums2[cnt2-1];
            int r2 = (cnt2 == m)? INT_MAX : nums2[cnt2];

            if(l1 <= r2 && l2 <= r1){
                if(ttl%2 == 0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                return (double)(max(l1,l2));
            }else if(l1 > r2){
                h = cnt1-1;
            }else{
                l = cnt1+1;
            }
        }
        return 0.0;
    }
};

//nth root of integer
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int s=0, e=m;
        int root;
        while(s<=e){
            int mid = (s+e)>>1;
            if(pow(mid,n) <= m){
                root = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        if(pow(root,n) != m)return -1;
        return root;
    }
};

//Aggresive Cows
class Solution {
  public:

    bool canPlaceCows(vector<int>& stalls, int k, int mid, int n){
        int numOfCows = 1;
        int curgap = 0;
        for(int i=1;i<n;i++){
            curgap += (stalls[i]-stalls[i-1]);
            if(curgap >= mid){
                numOfCows++;
                curgap = 0;
            }
        }
        return (numOfCows >= k);
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int lb = INT_MAX, ub = stalls[n-1]-stalls[0];
        for(int i=1;i<n;i++){
            lb = min(lb,stalls[i]-stalls[i-1]);
        }
        int res = -1;
        while(lb <= ub){
            int mid = (lb+ub)>>1;
            if(canPlaceCows(stalls,k,mid,n)){
                res = mid;
                lb = mid+1;
            }else{
                ub = mid-1;
            }
        }
        return res;
    }
};

