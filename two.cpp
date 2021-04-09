#include<bits/stdc++.h>
using namespace std;

 vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string, int> word_count;
        int sLen = s.length(), dictSize = words.size(), wLen = words[0].size(), i , j;
        vector<int> v;
        string word;

            for(i=0; i < dictSize; ++i) 
            word_count[words[i]]++; // count of words

        for(i = 0; i < sLen-dictSize*wLen+1; ++i)
        {
            unordered_map<string,int> check_count;
            for(j = 0; j < dictSize; ++j) //start from position i and check the following sequence;
            {
                word = s.substr(i+j*wLen, wLen);
                if(word_count[word]) 
                    { 
                    check_count[word]++;
                        if(check_count[word]> word_count[word]) 
                        break;  
                    }
                else 
                    break;
            }
            if(j == dictSize) 
            v.push_back(i); //all words are covered exactly;
        }
        return v;
    }
    
int main()
{
    string s="barfoothefoobarman";
    vector<string>words{"foo","bar"};
    vector<int> v=findSubstring(s,words);

    for(int i:v)
        cout<<i<<" ";
}