#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int suffix[n];

    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> suffix(n);

    suffix[n - 1] = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i - 1] + v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }

    return 0;
}

*/
