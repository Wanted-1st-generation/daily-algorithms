#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> v;
    v.reserve(N);

    while (N--)
    {
        int input;
        cin >> input;

        v.push_back(input);
    }
    sort(v.begin(), v.end());

    for (auto iter : v)
    {
        cout << iter << " ";
    }

    return 0;
}
