#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int num;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    for (int i = N - 1; i >= 0; --i)
    {
        cout << v[i] << " ";
    }

    return 0;
}