#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
 
    string n;
    std::getline(std::cin, n);
    int N = stoi(n);
    string s;
    std::getline(std::cin, s);
    stringstream ss(s);
    std::vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        int num;
        ss >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
