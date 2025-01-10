#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

class City
{
public:
    // DFS로 도시탐색
    void dfs(int i, map<int, vector<int>>& neis, unordered_set<int>& visited) {
        //이미 방문했으면 return
        if (visited.find(i) != visited.end())
        {
            return;
        }
        //방문표시
        visited.insert(i);
        if (neis.find(i) != neis.end())
        {
            for (int& neighbor : neis[i])
            {
                //재귀법으로 연결도니 이웃도시 방문
                dfs(neighbor, neis, visited);
            }
        }
    }

public:
    City(int n, int c_lib, int c_road, vector<vector<int>> cities)
        : city_num(n), city_lib(c_lib), city_road(c_road), cities(cities) { }

    //최소비용계산 : 도서관 비용보다 적거나 같은경우 모든 도시 도서관 건설(case2)
    long mincost() {
        if (city_lib <= city_road)
        {
            return (long)city_num * city_lib;
        }

        //방문 도시 추적
        set<int> added;
        //도시 연결정보
        map<int, vector<int>> connect_map;

        for (const auto& city : cities)
        {
            //도로 정보 추가
            connect_map[city[0]].push_back(city[1]);
            connect_map[city[1]].push_back(city[0]);
        }

        //코스트 총합
        long cost_sum = 0;
        for (int i = 1; i <= city_num; ++i)
        {
            if (added.find(i) == added.end())
            {
                unordered_set<int> group;
                dfs(i, connect_map, group);

                cost_sum += city_lib;
                cost_sum += (long)(city_road * (group.size() - 1));

                for (auto node : group)
                {
                    added.insert(node);
                }
            }
        }

        return cost_sum;
    }

private:
    int city_num, city_lib, city_road; 
    vector<vector<int>> cities;
};

int main()
{
    int q;
    cout << "쿼리 수 입력: ";
    cin >> q;

    vector<long> results;

    for (int query = 0; query < q; ++query)
    {
        int n, m, c_lib, c_road;
        cout << "도시수, 도서관수, 도서관 코스트, 도로 코스트 입력\n";
        cin >> n >> m >> c_lib >> c_road;
        //도시목록
        vector<vector<int>> cities(m, vector<int>(2));
        for (int i = 0; i < m; ++i)
        {
            cin >> cities[i][0] >> cities[i][1];
        }
        //객체 생성 및 최소비용 계산
        City solver(n, c_lib, c_road, cities);
        results.push_back(solver.mincost());
    }
    // 결과 출력
    for (long result : results)
    {
        cout << result << endl;
    }

    return 0;
}
