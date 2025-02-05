#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> d;

    int maxNum = 0;

    for (int i = 0; i < k; ++i)
    {
        d.push_back(arr[i]);
        maxNum = max(maxNum, d[i]);
    }
    cout << maxNum << " ";

    int idx = k;
    while (idx < n)
    {
        int frnt = d.front();
        d.pop_front();
        d.push_back(arr[idx]);

        maxNum = max(maxNum, d[k - 1]);

        if (maxNum == frnt)
        {
            maxNum = d[0];
            for (int i : d)
            {
                maxNum = max(maxNum, i);
            }
        }

        cout << maxNum << " ";
        ++idx;
    }
    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}