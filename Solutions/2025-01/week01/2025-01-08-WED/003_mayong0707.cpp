#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n = 0;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}