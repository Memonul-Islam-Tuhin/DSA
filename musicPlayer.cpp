#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<string>playList;
//    while(true)
//    {
//        string song;
//        cin >> song;
//        if(song == "stop")
//        {
//            break;
//        }
//
//        playList.push_back(song);
//    }

    string song;
    while(cin >> song && song != "stop")
    {
        playList.push_back(song);
    }

    int query;
    cin >> query;
    auto current = playList.begin();
    while(query--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "play")
        {
            string songName;
            cin >> songName;
            auto isFound = find(playList.begin(), playList.end(), songName);
            if(isFound != playList.end())
            {
                cout << "playing " << *isFound << endl;
                current = isFound;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }
        else if(cmd == "right")
        {
            if(next(current) != playList.end())
            {
                current = next(current);
                cout << "playing " << *current << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }
        else if(cmd == "left")
        {
            //  auto it = prev(current);
            if(current == playList.begin())
            {
                cout << "Not Found" << " ";
            }
            else
            {
                current = prev(current);
                cout << "playing " << *current << endl;
            }
        }
    }
    return 0;
}
