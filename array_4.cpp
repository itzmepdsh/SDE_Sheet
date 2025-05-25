#include<bits/stdc++.h>

//Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> pr;
        for(int i=0;i<n;i++){
            pr.push_back({nums[i],i});
        }
        sort(pr.begin(),pr.end());
        int i=0,j=n-1;
        while(i<j){
            int sum = pr[i][0]+pr[j][0];
            if(sum == target){
                return {pr[i][1],pr[j][1]};
            }else if(sum < target){
                i++;
            }else{
                j--;
            }
        }
        return {-1,-1};
    }
};

//Four Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;
                int k=j+1,l=n-1;
                int lastk = INT_MIN, lastl = INT_MIN;
                while(k<l){
                    long long sum = 0;
                    sum += (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target){
                        if(nums[k] != lastk){
                            res.push_back({nums[i],nums[j],nums[k],nums[l]});
                            lastk = nums[k];
                            lastl = nums[l];
                        }
                        k++;l--;
                    }
                    else if(sum < target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return res;
    }
};

//Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int l = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int c = 1;
                int v = it;
                while (st.find(v + 1) != st.end()) {
                    v = v + 1;
                    c += 1;
                }
                l = max(l, c);
            }
        }
        return l;

        // int n = nums.size();
        // if(n==0)return 0;

        // int mx = *max_element(nums.begin(),nums.end());
        // int mn = *min_element(nums.begin(),nums.end());

        // if(mn < 0){
        //     int to_add = abs(mn);
        //     for(int i=0;i<n;i++){
        //         nums[i] += to_add;
        //     }
        //     mx += to_add;
        // }
        // long long int sz = (mn < 0) ? mx+abs(mn)+1 : mx+1;
        // vector<int> flag(sz,-1);

        // for(int num : nums){
        //     if(mn < 0){
        //         flag[num+abs(mn)] = 0;
        //     }else{
        //         flag[num] = 0;
        //     }
        // }

        // for(int num : nums){
        //     int idx = (mn < 0) ? num+abs(mn) : num;
        //     if(idx > 0 && flag[idx-1] != -1){
        //         flag[idx] = 1;
        //     }
        // }

        // int mxlen = 1;
        // for(int num : nums){
        //     int idx = (mn<0) ? num+abs(mn) : num;
        //     if(flag[idx] == 0){
        //         int cnt = 1;
        //         idx++;
        //         while(idx < sz && flag[idx] == 1){
        //             cnt++;idx++;
        //         }
        //         mxlen = max(mxlen,cnt);
        //     }
        // }

        // return mxlen;

        // int n = nums.size();
        // if(n==0)return 0;
        // unordered_map<int,bool> mp;
        // for(int num : nums){
        //     mp[num] = true;
        // }
        // for(int num : nums){
        //     if(mp.find(num-1) != mp.end())
        //         mp[num] = false;
        // }
        // int maxlen = 1;
        // for(int num : nums){
        //     if(mp[num] == true){
        //         int cnt = 0,seq = num;
        //         while(mp.find(seq) != mp.end()){
        //             cnt++;
        //             seq++;
        //         }
        //         maxlen = max(maxlen,cnt);
        //     }
        // }
        // return maxlen;
    }
};

//Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp,last_pos;
        int n = s.length();
        if(n==0)return 0;
        int i=0,j=0;
        int mxlen = 0,curlen = 0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]] > 1){
                mxlen = max(mxlen,curlen);
                for(int k=i;k<=last_pos[s[j]];k++){
                    mp[s[k]]--;
                }
                i=last_pos[s[j]]+1;
                curlen = j-i;
            }
            curlen++;
            last_pos[s[j]] = j;
            j++;
        }
        return max(mxlen,curlen);
    }
};

//Longest Subarray with sum k (negative numbers included)
class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
        unordered_map<int, int> mp;
        int n=nums.size();
        int len = 0;
        mp[0] = 0;
        int cursum = 0;
        for(int i=0;i<n;i++){
            cursum += nums[i];
            if(mp.find(cursum) == mp.end())
                mp[cursum] = i;
            if(mp.find(cursum-k) != mp.end()){
                int curlen = (cursum-k==0) ? i+1 : i-mp[cursum-k];
                len = max(len,curlen);
            }
        }
        return len;
    }
};

//Count number of subarrays with XOR k
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curval = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        long long int cnt = 0;
        for(int num : nums){
            curval ^= num;
            if(mp.count(curval)){
                cnt += mp[curval];
            }
            mp[curval]++;
        }
        return cnt;
    }
};