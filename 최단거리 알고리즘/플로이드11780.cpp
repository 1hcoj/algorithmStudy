#include <iostream>
#include <vector>

using namespace std;

void floyd11780() {
	int n, m, v1, v2, w;
	const long long INF = INT64_MAX;
	cin >> n >> m;
	vector<vector<long long>> distance(n + 1, vector<long long>(n + 1, INF));
	// 플로이드 2 핵심 3차원 행렬
	vector<vector<vector<int>>> route(n + 1, vector<vector<int >> (n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { if (i == j) distance[i][j] = 0; }
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		distance[v1][v2] = (distance[v1][v2] > w) ? w : distance[v1][v2];
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (distance[i][k] == INF || distance[k][j] == INF) continue;
				if (distance[i][j] > (distance[i][k] + distance[k][j])) {
					distance[i][j] = distance[i][k] + distance[k][j];
					route[i][j].clear();
					for (int r : route[i][k]) {
						route[i][j].push_back(r);
					}
					route[i][j].push_back(k);
					/* i ~ k  사이의 노드만 생각하고 k ~ j 사이의 노드는 생각 못함*/
					for (int r : route[k][j]) {
						route[i][j].push_back(r);
					}

				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ((distance[i][j] != INF) ? distance[i][j] : 0) << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || distance[i][j] == INF) cout << 0 << '\n';
			else {
				cout << 2 + route[i][j].size() << ' ' << i << ' ';
				for (int r : route[i][j]) {
					cout << r << ' ';
				}
				cout << j << '\n';
			}
		}
	}
}