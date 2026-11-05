#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Phitron is a programming learning platform. Phitron helps students learn programming, especially C programming, C++ programming, data structure, algorithm, and AI/ML.";
    string word;
    stringstream ss(str);
    map<string, int>mp;

    int count = 0;
    string max_find_word;
    while(ss >> word)
    {
        mp[word]++;
        if(mp[word] > count)
        {
            count = mp[word];
            max_find_word = word;
        }
    }


    //    for(auto it = mp.begin(); it != mp.end(); it++)
//    {
//        //  cout << it->first << " " << it->second << endl;
//        if(it->second > count)
//        {
//            count = it->second;
//            max_find_word = it->first;
//        }
//    }

    cout << max_find_word << " " << count << endl;
    return 0;
}
