#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int arr[10001] = { 0 };

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int lt = 1;
    int rt = N;

    while (lt < rt)
    {
        int temp = arr[lt];
        arr[lt] = arr[rt];
        arr[rt] = temp;
        lt++;
        rt--;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
