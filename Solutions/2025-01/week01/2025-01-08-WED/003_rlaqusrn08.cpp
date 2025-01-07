#include <iostream>

using namespace std;

int arr[1001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
