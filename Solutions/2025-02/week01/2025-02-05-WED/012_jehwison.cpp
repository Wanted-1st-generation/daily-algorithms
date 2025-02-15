#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void maxInSubarrays(int arr[], int n, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        maxInSubarrays(arr, n, k);
    }

    return 0;
}

