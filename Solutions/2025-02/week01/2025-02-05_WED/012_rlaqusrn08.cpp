#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    if (n <= 0) return;

    deque<int> dq;
    int iMax = -1;
    for (int i = 0; i < k; i++)
    {
        dq.push_back(arr[i]);
        if (arr[i] > iMax) iMax = arr[i];
    }
    cout << iMax << ' ';

    for (int i = k; i < n; i++)
    {
        int iTemp = dq.front();
        dq.pop_front();
        dq.push_back(arr[i]);

        if (dq.back() > iMax)
        {
            iMax = dq.back();
        }
        else if (iTemp == iMax)
        {
            iMax = -1;
            for (auto iter : dq)
            {
                if (iter > iMax)
                {
                    iMax = iter;
                }
            }
        }
        cout << iMax << ' ';
    }

    cout << '\n';
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0;i < n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}