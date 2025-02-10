#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Partition(vector<int>& v, int left, int right)
{
    int pivot = v[left];
    vector<int> leftPart, rightPart;

    for (int i = left + 1; i <= right; i++)
    {
        if (v[i] <= pivot)
            leftPart.push_back(v[i]);
        else
            rightPart.push_back(v[i]);
    }

    int pivotIndex = left + leftPart.size();


    int index = left;
    for (int num : leftPart) v[index++] = num;
    v[index++] = pivot;
    for (int num : rightPart) v[index++] = num;

    return pivotIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
    if (left < right)
    {
        int partition = Partition(v, left, right);

        QuickSort(v, left, partition - 1);
        QuickSort(v, partition + 1, right);

        for (int i = left; i <= right; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v;
    int N;
    cin >> N;

    while (N--)
    {
        int iInput;
        cin >> iInput;
        v.push_back(iInput);
    }

    QuickSort(v, 0, v.size() - 1);
    return 0;
}
