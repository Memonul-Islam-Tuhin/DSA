#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int flag = 0;
//    for(int i = 0; i < n - 1; i++)
//    {
//        if(arr[i] < arr[i + 1])
//        {
//            flag = 1;
//            break;
//        }
//    }

    vector<int>v(n);

    sort(v.begin(),v.end(), greater<int>());

    int des_order_sort = 1;

    for(int i = 0; i < n; i++)
    {
        if(v[i] != arr[i])
        {

            des_order_sort = 0;
            break;
        }
    }


    if(flag == 1)
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not sorted" << endl;
    }

    return 0;
}
