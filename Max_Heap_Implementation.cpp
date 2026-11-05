#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{

public :
    vector<int>v;

    void push(int val)
    {
        v.push_back(val);
        int cur_idx = v.size() - 1;
        while(cur_idx != 0)
        {
            int par_idx = (cur_idx - 1) / 2;
            if(v[par_idx] < v[cur_idx])
            {
                swap(v[par_idx],v[cur_idx]);
                cur_idx = par_idx;
            }
            else
            {

                break;
            }
        }
    }

    void printHeap()
    {
        for(auto res : v)
        {
            cout << res << " ";
        }
        cout << endl;
    }

    bool empty()
    {
        return v.empty();
    }

    int size()
    {
        return v.size();
    }

    int top()
    {
        return v.front();
    }

    void pop()
    {
        v[0] = v.back();
        v.pop_back();

        int cur_idx = 0;
        int last_idx = v.size() - 1;
        while(true)
        {
            int left_idx = (cur_idx * 2) + 1;
            int right_idx = (cur_idx * 2) + 2;

            if(left_idx <= last_idx && right_idx > last_idx)
            {
                if(v[left_idx] > v[cur_idx])
                {
                    swap(v[left_idx],v[cur_idx]);
                    cur_idx = left_idx;
                }
                else
                {
                    break;
                }
            }
            else if(left_idx <= last_idx && right_idx <= last_idx)
            {
                if(v[left_idx] >= v[right_idx] && v[left_idx] > v[cur_idx])
                {
                    swap(v[left_idx],v[cur_idx]);
                    cur_idx = left_idx;
                }
                else if(v[right_idx] >= v[left_idx] && v[right_idx] > v[cur_idx])
                {
                    swap(v[right_idx],v[cur_idx]);
                    cur_idx = right_idx;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    MaxHeap mhp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        mhp.push(val);
    }

//    mhp.printHeap();
//    mhp.pop();
//    mhp.printHeap();
//    mhp.pop();
//    mhp.printHeap();
//    mhp.pop();
//    mhp.printHeap();
//    if(!mhp.empty())
//    {
//        mhp.pop();
//        mhp.printHeap();
//    }

    cout << mhp.top() << endl;
    if(!mhp.empty())
    {
        mhp.pop();
        cout << mhp.top() << endl;
    }
    if(!mhp.empty())
    {
        mhp.pop();
        cout << mhp.top() << endl;
    }
    if(!mhp.empty())
    {
        mhp.pop();
        cout << mhp.top() << endl;
    }
    return 0;
}
