#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


#include <deque>

void Merge(deque<int> &arr, deque<int> &arrLeft, deque<int> &arrRight, long& num)
{
    arr.clear();
    while (!arrLeft.empty() && !arrRight.empty())
    {
        int left = arrLeft.front();
        int right = arrRight.front();
        if (left <= right)
        {
            arr.push_back(left);
            arrLeft.pop_front();
        }
        else
        {
            arr.push_back(right);
            num = num + arrLeft.size();
            arrRight.pop_front();
        }
    }
    
    while (!arrLeft.empty())
    {
        arr.push_back(arrLeft.front());
        arrLeft.pop_front();
    }
    
    while (!arrRight.empty())
    {
        arr.push_back(arrRight.front());
        arrRight.pop_front();
    }
}

void MergeSort(deque<int>& arr, long& num)
{
    if (arr.size() == 1)
    {
        return ;
    }

    long sz = arr.size();
    long mid = sz / 2;
    deque<int> arrLeft(arr.begin(), arr.begin() + mid);
    deque<int> arrRight(arr.begin() + mid, arr.end());

    MergeSort(arrLeft, num);
    MergeSort(arrRight, num);

    Merge(arr, arrLeft, arrRight, num);
}


long countInversions(vector<int> arr) {
    long num = 0;
    deque<int> deq(arr.begin(), arr.end());
    MergeSort(deq, num);
    return (num);
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
