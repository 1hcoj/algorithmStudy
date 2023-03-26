#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void daijkstra() {
	vector<vector<pair<int, int>>> graph;
	const long long INF = INT64_MAX;
	int n, m, x, v1, v2, w;
	cin >> n >> m >> x;
	graph = vector<vector<pair<int, int>>>(n + 1);
	vector<long long> distance(n + 1, INF);
	distance[x] = 0;

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({ v2,w });
	}

	vector<bool> visited(n + 1, false);

	priority_queue<pair<int, int>> q;
	q.push({ 0,x });
	int a, b;
	while (!q.empty()) {
		a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;

		for (auto u : graph[a]) {
			b = u.first; w = u.second;
			if (distance[b] > distance[a] + w) {
				distance[b] = distance[a] + w;
				q.push({ -distance[b],b });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		long long d = distance[i];
		if (d != INF) cout << d << '\n';
		else cout << "INF" << '\n';
	}
}