#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool issol=false;
        vector<int> validSequence(string word1, string word2) {
            vector<int> ans;
            map<int,vector<int>> store;
            for(int i=0; i< word1.size(); i++)
            {
                store[word1[i]-'a'].push_back(i);
            }

            unordered_map<unordered_map<bool

            return ans;
        }
       
    };