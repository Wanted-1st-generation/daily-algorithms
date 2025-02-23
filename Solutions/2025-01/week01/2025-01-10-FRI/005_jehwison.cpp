#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

// DFS �Լ�
int dfs(int node, std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    std::stack<int> s;
    s.push(node);
    visited[node] = true;
    int size = 0;

    // ������ ������� ���� ������ Ž��
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        size++;

        // ���� ���� ����� �̿� ������ Ž��
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    return size;
}

// �ּ� ��� ��� �Լ�
long long minCostCalculate(int n, int c_lib, int c_road, std::vector<std::vector<int>>& roads) {
    // ������ �Ǽ� ����� ���� ���� ��뺸�� �� ���ų� ���� ��� ��� ���ÿ� ������ �Ǽ�
    if (c_lib <= c_road) {
        return (long long)n * c_lib;
    }

    // �׷��� �ʱ�ȭ
    // ���� ��ȣ�� 1���� ���� -> ũ�� n+1
    std::vector<std::vector<int>> graph(n + 1);
    for (auto& road : roads) {
        // ���� ���� �߰�
        graph[road[0]].push_back(road[1]);
        // ����� �߰�
        graph[road[1]].push_back(road[0]);
    }

    // �湮 �迭 �ʱ�ȭ
    std::vector<bool> visited(n + 1, false);
    long long total_cost = 0;

    // ��� ���ø� �湮�ϸ� ���� ��� Ž��
    for (int city = 1; city <= n; ++city) {
        if (!visited[city]) {
            // ���ο� ���� ��� �߰� �� ���� ����� ũ�� ���
            int component_size = dfs(city, graph, visited);
            // �ּ� ��� ���
            total_cost += (long long)c_lib + (long long)(component_size - 1) * c_road;
        }
    }

    return total_cost;
}

int main(void) {
    int query;
    // ���� �� �Է�
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
