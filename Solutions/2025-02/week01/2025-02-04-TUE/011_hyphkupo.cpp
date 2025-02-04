#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    for (auto& i : v)
    {
        cout << i << " ";
    }

    return 0;
}