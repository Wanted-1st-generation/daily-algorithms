#include <iostream>
#include <vector>

using namespace std;

int inversionCount = 0;

void mergeSort(vector<int>& arr);
void merge(vector<int>& arr, const vector<int>& leftHalf, const vector<int>& rightHalf);

void mergeSort(vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        vector<int> leftHalf(arr.begin(), arr.begin() + mid);
        vector<int> rightHalf(arr.begin() + mid, arr.end());

        mergeSort(leftHalf);
        mergeSort(rightHalf);
        merge(arr, leftHalf, rightHalf);
    }
}

void merge(vector<int>& arr, const vector<int>& leftHalf, const vector<int>& rightHalf) {
    int left = 0, right = 0, index = 0;
    int leftLength = leftHalf.size();
    int rightLength = rightHalf.size();

    while (left < leftLength && right < rightLength) {
        if (leftHalf[left] <= rightHalf[right]) {
            arr[index++] = leftHalf[left++];
        } else {
            arr[index++] = rightHalf[right++];
            inversionCount += leftLength - left;
        }
    }

    while (left < leftLength) {
        arr[index++] = leftHalf[left++];
    }

    while (right < rightLength) {
        arr[index++] = rightHalf[right++];
    }
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int lengthArray;
        cin >> lengthArray;
        vector<int> array(lengthArray);

        for (int i = 0; i < lengthArray; ++i) {
            cin >> array[i];
        }

        inversionCount = 0;
        mergeSort(array);

        cout << inversionCount << endl;
    }

    return 0;
}


