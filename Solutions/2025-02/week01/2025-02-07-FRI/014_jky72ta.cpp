#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

#include <cstring>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>

int powerSum(int X, int N) {
    int answer = 0;
    set<int> st;
    using pr = pair<int, int>;
    priority_queue<pr, vector<pr>, greater<pr>> pq; 
    for (int i = 1; i < X; ++i)
    {
        int sq = pow(i, N);
        if (sq > X)
            break ;
        st.insert(sq);
    }
    
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        pr p = pq.top();
        pq.pop();
        
        for (set<int>::iterator it = st.upper_bound(p.second); it != st.end(); ++it)
        {
            int newN = p.first + *it;
            if (newN >= X)
            {
                if (newN == X)
                {
                    answer = answer + 1; 
                    continue ;
                }
                break ;
            }
            else
            {
                pq.push(make_pair(newN, *it));
            }
        }
    }
    
    return (answer);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

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
