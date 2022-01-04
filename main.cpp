#include <bits/stdc++.h>
#include <fstream>

using namespace std;
class Solution {
   public:
   static bool cmp(string s1, string s2){
      return s1.size() < s2.size();
   }
   int longestStrChain(vector<string>& words) {
      unordered_map <string, int> dp;
      int n = words.size();
      sort(words.begin(), words.end(), cmp);
      int ret = 0;
      for(int i = 0; i < n; i++){
         int best = 0;
         for(int j = 0; j < words[i].size(); j++){
            string word = words[i].substr(0, j) +
            words[i].substr(j + 1);
            best = max(best, dp[word] + 1);
         }
         dp[words[i]] = best;
         ret = max(ret, dp[words[i]]);
      }
      return ret;
   }
};


main(){
   vector<string> v = {"a","b","ba","bca","bda","bdca"};
   Solution ob;
   cout << (ob.longestStrChain(v));
}