#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

// DFS 함수
int dfs(int node, std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    std::stack<int> s;
    s.push(node);
    visited[node] = true;
    int size = 0;

    // 스택이 비어있지 않을 때까지 탐색
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        size++;

        // 현재 노드와 연결된 이웃 노드들을 탐색
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    return size;
}

// 최소 비용 계산 함수
long long minCostCalculate(int n, int c_lib, int c_road, std::vector<std::vector<int>>& roads) {
    // 도서관 건설 비용이 도로 보수 비용보다 더 적거나 같은 경우 모든 도시에 도서관 건설
    if (c_lib <= c_road) {
        return (long long)n * c_lib;
    }

    // 그래프 초기화
    // 도시 번호는 1부터 시작 -> 크기 n+1
    std::vector<std::vector<int>> graph(n + 1);
    for (auto& road : roads) {
        // 도로 정보 추가
        graph[road[0]].push_back(road[1]);
        // 양방향 추가
        graph[road[1]].push_back(road[0]);
    }

    // 방문 배열 초기화
    std::vector<bool> visited(n + 1, false);
    long long total_cost = 0;

    // 모든 도시를 방문하며 연결 요소 탐색
    for (int city = 1; city <= n; ++city) {
        if (!visited[city]) {
            // 새로운 연결 요소 발견 시 연결 요소의 크기 계산
            int component_size = dfs(city, graph, visited);
            // 최소 비용 계산
            total_cost += (long long)c_lib + (long long)(component_size - 1) * c_road;
        }
    }

    return total_cost;
}

int main(void) {
    int query;
    // 쿼리 수 입력
    std::cin >> query;

    while (query--) {
        int n, m, c_lib, c_road;
        std::cin >> n >> m >> c_lib >> c_road;

        std::vector<std::vector<int>> roads(m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            roads[i] = { u, v };
        }

        std::cout << minCostCalculate(n, c_lib, c_road, roads) << std::endl;
    }

    return 0;
}
