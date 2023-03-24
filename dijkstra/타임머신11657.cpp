#include <iostream>
#include <vector>
using namespace std;

int bellman_ford() {
	int n, m;
	cin >> n >> m;
	vector<long long> distance(n + 1);
	const long long INF = INT64_MAX / 2;
	vector<pair<pair<int, int>, int>>  edges;
	int start, end, cost;

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		edges.push_back({ { start,end }, cost });
	}

	for (int i = 2; i <= n; i++) {
		distance[i] = INF;
	}

	for (int i = 1; i <= n; i++) {
		int a, b, w;
		for (auto edge : edges) {
			a = edge.first.first;
			b = edge.first.second;
			w = edge.second;
			if (distance[a] == INF) continue;  // 오류 내용
			if (distance[b] > distance[a] + w) {
				distance[b] = distance[a] + w;
				if (i == n) {
					cout << -1 << endl;
					return 0;
				}
			}
		}

	}
	for (int i = 2; i <= n; i++) {
		cout << ((distance[i] != INF) ? distance[i] : -1) << endl;
	}
}