#include <iostream>
#include <vector>

using namespace std;

void floyd11404() {
	int n, m, v1, v2, w;
	const long long INF = INT64_MAX;
	cin >> n >> m;
	vector<vector<long long>> distance(n + 1, vector<long long>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { if (i == j) distance[i][j] = 0; }
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		distance[v1][v2] = (distance[v1][v2] > w) ? w : distance[v1][v2];
		//distance[v2][v1] = (distance[v2][v1] > w) ? w : distance[v2][v1]; 방향 확인 잘 하기
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (distance[i][k] == INF || distance[k][j] == INF) continue;
				distance[i][j] = (distance[i][j] > (distance[i][k] + distance[k][j])) ? (distance[i][k] + distance[k][j]) : distance[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ((distance[i][j] != INF) ? distance[i][j] : 0) << ' ';
		}
		cout << '\n';
	}
}