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

//Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        int i=0;
        while(i<n){
            int strt = intervals[i][0];
            int end = intervals[i][1];
            while(i<n-1 && end >= intervals[i+1][0]){
                i++;
                end = max(end,intervals[i][1]);
            }
            res.push_back({strt,end});
            i++;
        }
        return res;
    }
};

//Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1,i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while(i>=0){
            nums1[k] = nums1[i];
            i--;k--;
        }

        while(j>=0){
            nums1[k] = nums2[j];
            j--;k--;
        }
    }
};

//Find the duplicate number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Floyd's Cycle Detection
        int slow = nums[0], fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)break;
        }
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

        //Negation Technique
        int n = nums.size();
        for(int i=0;i<n;i++){
            int idx = abs(nums[i]);
            if(nums[idx] < 0)return idx;
            nums[idx] = -nums[idx];
        } 
        return -1;
    }
};

// Repeat and Missing Number
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int miss,repeat;
        for(int i=0;i<n;i++){
            int idx = abs(arr[i])-1;
            if(arr[idx] < 0){
                repeat = idx+1;
            }else{
                arr[idx] = -arr[idx];
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i] > 0)
                miss = i+1;
        }
        return {repeat,miss};
    }
};

//Inversion Count of the Array
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>& arr ,int i, int mid, int j){
        int cnt = 0;
        vector<int> temp(j-i+1);
        int k =0,a=i,b=mid;
        while(a<mid && b <=j){
            if(arr[a] <= arr[b]){
                temp[k] = arr[a];
                a++;
            }else{
                temp[k] = arr[b];
                cnt += (mid-a);
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
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int cnt = mergeSort(arr,0,n-1);
        return cnt;
    }
};