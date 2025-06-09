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
