#include <bits/stdc++.h>
using namespace std;


void quickSort(vector <int> &arr) {
    int len = arr.size();

    vector<int> v_l;
    vector<int> v_r;
    int pivot = arr[0];
    for (int i = 1; i < len; ++i)
    {
        if (pivot > arr[i])
        {
            v_l.push_back(arr[i]);
        }
        else
        {
            v_r.push_back(arr[i]);
        }
    }

    if (!v_l.empty() && v_l.size() != 1)
    {
        quickSort(v_l);
        for (int c : v_l)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    if (!v_r.empty() && v_r.size() != 1)
    {
        quickSort(v_r);
        for (int c : v_r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    v_l.push_back(arr[0]);
    v_l.insert(v_l.end(), v_r.begin(), v_r.end());
    arr = v_l;
}




int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);
    for (int c : arr)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}