#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

using pr = pair<int , string>;

using unset = unordered_set<string>;

const string ans = "123456780";

void CheckAndPush(unset& m, queue<pr> &que, string& s, int zPos, int c1, int c2, int c3, int len)
{
    if (!(zPos == c1 || zPos == c2 || zPos == c3))
    {
        swap(s[zPos], s[zPos + len]);
        if (m.find(s) == m.end())
        {
            que.push({zPos + len, s});
            m.insert(s);
        }
        swap(s[zPos], s[zPos + len]);
    }
}

int findAnswer(queue<pr> &que)
{
    int round = 0;

    unset m;
    m.insert(que.front().second);
    while (!que.empty())
    {
        int count = que.size();
        for (int i = 0; i < count; ++i)
        {
            pr v = que.front();
            que.pop();

            if (v.second == ans)
                return (round);
            
            CheckAndPush(m, que, v.second, v.first, 0, 3, 6, -1);
            CheckAndPush(m, que, v.second, v.first, 2, 5, 8, 1);
            CheckAndPush(m, que, v.second, v.first, 0, 1, 2, -3);
            CheckAndPush(m, que, v.second, v.first, 6, 7, 8, 3);
        }
        round = round + 1;
    }
    return (-1);
}

int main()
{
    string numbers = "";
    for (int i = 0; i < 9; ++i) {
        char num;
        cin >> num;
        numbers += num;
    }
    queue<pr> que;
    for (int idx = 0; idx < 9; ++idx)
    {
        if (numbers[idx] == '0')
        {
            que.push(make_pair(idx, numbers));
            break ;
        }     
    }
    cout << findAnswer(que) << endl;
    return (0);
}