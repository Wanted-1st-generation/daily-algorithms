#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
 
 int Merge(vector<int>& array,
    vector<int>& leftArray, int leftArrayLength,
    vector<int>& rightArray, int rightArrayLength)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = 0;
    int cnt = 0;

    while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergedIndex] = leftArray[leftIndex];
            ++leftIndex;
        }
        else
        {
            cnt += (leftArrayLength - leftIndex);
            array[mergedIndex] = rightArray[rightIndex];
            ++rightIndex;
        }

        ++mergedIndex;
    }

    while (leftIndex < leftArrayLength)
    {
        array[mergedIndex] = leftArray[leftIndex];
        ++mergedIndex;
        ++leftIndex;
    }

    while (rightIndex < rightArrayLength)
    {
        array[mergedIndex] = rightArray[rightIndex];
        ++mergedIndex;
        ++rightIndex;
    }
    
    return cnt;
}

int MergeSort(vector<int>& array, int length)
{
    int cnt = 0;
    
    if (length <= 1) return cnt;

    int mid = length / 2;

    vector<int> leftArray;
    vector<int> rightArray;

    for (int i = 0; i < mid; ++i)
    {
        leftArray.emplace_back(array[i]);
    }
    
    for (int i = mid; i < (int)array.size(); ++i)
    {
        rightArray.emplace_back(array[i]);
    }
    
    cnt += MergeSort(leftArray, mid);
    cnt += MergeSort(rightArray, length - mid);
    cnt += Merge(array, leftArray, mid, rightArray, length - mid);
    
    return cnt;
}

long countInversions(vector<int>& arr) {
    return MergeSort(arr, (int)arr.size());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}