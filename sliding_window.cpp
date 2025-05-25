#include<bits/stdc++.h>

//Maximum Consecutive Ones
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int i=0,j=0;
        int mxlen=0,curlen = 0;
        int first_0 = -1;
        while(j<n){
            if(nums[j] == 0){
                cnt++;
                if(cnt == 1)first_0=j;
            }
            if(cnt > k){
                cnt--;
                i=first_0+1;
                first_0++;
                while(first_0 <= j && nums[first_0] != 0)
                    first_0++;
                mxlen = max(mxlen,curlen);
                curlen = j-i;
            }
            j++;
            curlen++;
        }
        return max(mxlen,curlen);
    }
};

//Fruits in the Basket
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int maxlen = 0,curlen=0;
        while(j<n){
            mp[fruits[j]] = j;
            if(mp.size() == 3){
                maxlen = max(maxlen,curlen);
                int mn_idx = INT_MAX, to_remove;
                for(auto pr : mp){
                    if(mn_idx > pr.second){
                        mn_idx = pr.second;
                        to_remove = pr.first;
                    }
                }
                mp.erase(to_remove);
                i = mn_idx+1;
                curlen = j-i;
            }
            curlen++;
            j++;
        }
        return max(maxlen,curlen);
    }
};

//Longest repeating character replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.length();
        int i=0,j=0;
        int mxlen = 0,curlen=0;
        int mx_freq = 0;
        while(j<n){
            int idx = s[j]-'A';
            freq[idx]++;
            if(freq[idx] > mx_freq){
                mx_freq = freq[idx];
            }
            if(curlen+1-mx_freq > k){
                mxlen = max(mxlen,curlen);
                while(curlen+1-mx_freq > k){
                    freq[s[i]-'A']--;
                    i++;
                    curlen--;
                    for(int i=0;i<26;i++){
                        mx_freq = max(freq[i],mx_freq);
                    }
                }
            }
            curlen++;
            j++;
        }
        return max(mxlen,curlen);
    }
};

//Binary Subarrays with sum
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cursum = 0, cnt = 0;
        int i=0,j=0;
        while(j<n){
            cursum += nums[j];
            while(cursum > goal){
                if(nums[i])cursum--;
                i++;
            }
            if(i<=j && cursum == goal){
                int prefix_0 = 0;
                int k =i;
                while(k<j && nums[k] == 0){
                    prefix_0++;
                    k++;
                }
                cnt += prefix_0 + 1;
            }
            j++;
        }
        return cnt;
    }
};

//Count number of nice subarrays
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd_idx;
        odd_idx.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]%2)
                odd_idx.push_back(i);
        }
        odd_idx.push_back(n);
        int i=1,j=k;//if k=0, we have to handle it separately
        int sz = odd_idx.size();
        int cnt = 0;
        if(sz < k+2)
            return 0;
        while(j<sz-1){
            int pre = odd_idx[i]-odd_idx[i-1];
            int suf = odd_idx[j+1]-odd_idx[j];
            cnt += pre*suf;
            i++;j++;
        }
        return cnt;
    }
};

//Maximum Points you can obtain from cards 
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ttl = 0;
        for(int num : nums)ttl += num;
        int len = n-k;
        int cursum = 0;
        int i=0,j=0;
        while(j<len){
            cursum += nums[j];
            j++;
        }
        int mn = cursum;
        while(j<n){
            cursum += nums[j]-nums[i];
            j++;i++;
            mn = min(mn,cursum);
        }
        return ttl-mn;
    }
};

//Number of substring containing all 3 chars
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int cnt = 0;
        int res = 0;
        int i=0,j=0,n = s.length();
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1)
                cnt++;
            while(cnt == 3){
                res += (n-j);
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == 0)
                    cnt--;
                i++;
            }
            j++;
        }
        return res;
    }
};