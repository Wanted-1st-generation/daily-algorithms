#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct t_node
{
    int current;
    int next;
    int count = 1;
};

t_node &findNd(t_node *arr, int start)
{
    
    if(arr[start].next == arr[start].current)
        return arr[start];
    else
        return findNd(arr, arr[start].next);
}

void calcCount(t_node *arr, int start, int end) 
{
    t_node &st = findNd(arr, start);
    st.next = end;
    int count = st.count;
    while (arr[end].next != arr[end].current)
    {
        arr[end].count = arr[end].count + count;
        end = arr[end].next;
    }
    arr[end].count = arr[end].count + count;
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) 
{
    t_node arr[t_nodes + 1];
    for (int i = 0; i <= t_nodes; ++i)
    {
        arr[i].next = i;
        arr[i].current = i;
    }
    for (int i = 0; i < t_edges; ++i)
    {
        int start = t_from[i];
        int end = t_to[i];

        calcCount(arr, start, end);
    }
    int answer = 0;
    for (int i = 0; i < t_nodes; ++i)
    {
        if(!(arr[i].count & 1))
            answer = answer + 1;
    }
    return (answer - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

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
