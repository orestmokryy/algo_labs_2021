#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
   static bool cmp(string s1, string s2)
   {
      return s1.size() < s2.size();
   }
   int longestWordChain(vector<string> &words)
   {
      unordered_map<string, int> dp;
      int lenght = words.size();
      sort(words.begin(), words.end(), cmp);
      int chain = 0;
      for (int i = 0; i < lenght; i++)
      {
         int best = 0;
         for (int j = 0; j < words[i].size(); j++)
         {
            string word = words[i].substr(0, j) +
                          words[i].substr(j + 1);
            best = max(best, dp[word] + 1);
         }
         dp[words[i]] = best;
         chain = max(chain, dp[words[i]]);
      }
      return chain;
   }
};

int read(vector<string>& v)
{
   std::ifstream myfile;
   myfile.open("data.txt");
   std::string myline;
   if (myfile.is_open())
   {
      while (myfile)
      { 
         std::getline(myfile, myline);
         v.push_back(myline);
      }
   }
   else
   {
      std::cout << "Couldn't open file\n";
   }
   return 0;
}
main()
{
   vector<string> v;
   Solution ob;
   read(v);
   std::cout << "The longest word chain found:";
   std::cout << (ob.longestWordChain(v));
}