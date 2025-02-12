#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>

int GenerateHash(int key) {
    key ^= (key >> 16);
    return key;
}

template<typename KeyType, typename ValueType>
class Pair
{
    friend class HashTable;

    public :
        Pair()
            : key(), value()
        {
        }
        Pair(KeyType key, ValueType value)
            : key(key), value(value)
        {
        }
        bool operator==(const Pair<KeyType, ValueType>& other)
        {
            return (key = other.key && value == other.value);
        }
        bool operator!=(const Pair<KeyType, ValueType>& other)
        {
            return (key != other.key || value != other.value);
        }
    private :
        KeyType key;

        ValueType value;
};

class HashTable {
    using Entry = Pair<int, int>;
    
    public:
        HashTable(){};

        ~HashTable(){};
        
        void Add(int key, int value)
        {
            int BucketIndex = GenerateHash(key) % this->bucketCount;
            auto &position = this->table[BucketIndex];

            for (int ix = 0; ix < (int)position.size(); ++ix)
            {
                if (position[ix].key == key && position[ix].value == value)
                        return ;
            }

            position.push_back(Entry(key, value));
        }

        bool Find(int key, int &outValue)
        {
            int bucketIndex = GenerateHash(key) % bucketCount;
            auto &position = table[bucketIndex];

            if (position.size() == 0)
                return false;
            for (int ix = 0; ix < (int)position.size(); ++ix)
            {
                if (position[ix].key == key)
                {
                    outValue = position[ix].value;
                    return true;
                }
            }
            return (false);
        }

        bool DeOtherFind(int key, int value, int &outValue)
        {
            int bucketIndex = GenerateHash(key) % bucketCount;
            auto &position = table[bucketIndex];

            for (int ix = 0; ix < (int)position.size(); ++ix)
            {
                if (position[ix].key == key)
                {
                    if (position[ix].value == value)
                    {
                        continue ;
                    }
                    outValue = position[ix].value;
                    return true;
                }
            }
            return (false);
        }

        int &operator[](int key)
        {
            int bucketIndex = GenerateHash(key) % bucketCount;
            auto &position = table[bucketIndex];

            for (int ix = 0; ix < (int)position.size(); ++ix)
            {
                if (position[ix].key == key)
                {
                    return (position[ix].value);
                }
            }

            position.push_back(Entry(key, 0));
            return position.back().value;
        }

    private:
        static const int bucketCount = 1000037;
        std::vector<Entry> table[bucketCount];
};

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

void whatFlavors(vector<int> cost, int money) {
    HashTable hTable;
    for (size_t i = 0; i < cost.size(); ++i)
    {
        hTable.Add(cost[i], i + 1);
    }
    for (int i : cost)
    {
        if (hTable[i] > 0 && hTable[money - i] > 0)
        {
            int a = hTable[i];
            int b = 0;
            if (money - i == i)
            {
                if (hTable.DeOtherFind(i, a, b))
                {
                    cout << min(a, b) << " " << max(a, b) << endl;
                    return ;
                }
            }
            else
            {
                b = hTable[money - i];
                cout << min(a, b) << " " << max(a, b) << endl;
                return ;
            }
        }
    }

}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));
        
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
