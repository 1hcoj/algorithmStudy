#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> q;
int n,v1, v2;
const long long INF = 9876543;

void dijk(int x,vector<long long> & dist) {
	vector<bool> visited(n + 1, false);
	q.push({ 0,x });
	dist[x] = 0;
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (pair<int, int> e : graph[a]) {
			int b = e.first; int w = e.second;
			if (dist[b] > dist[a] + w) {
				dist[b] = dist[a] + w;
				q.push({ -dist[b],b });
			}
		}
	}
}
int main() {
	int m, w;
	cin >> n >> m;
	graph = vector<vector<pair<int, int>>>(n + 1);
	vector<vector<long long>> distList(2,vector<long long>(n+1,INF));
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w; 
		graph[v1].push_back({ v2,w });
		graph[v2].push_back({ v1,w });
	}
	cin >> v1 >> v2;
	dijk(v1, distList[0]);
	dijk(v2, distList[1]);
	long long one_v1, v1_v2, v1_n, one_v2, v2_v1, v2_n;
	one_v1 = distList[0][1]; v1_v2 = distList[0][v2]; v1_n = distList[0][n];
	one_v2 = distList[1][1]; v2_v1 = distList[1][v1]; v2_n = distList[1][n];
	long long distV1 = one_v1 + v1_v2 + v2_n;
	long long distV2 = one_v2 + v2_v1 + v1_n;

	if (distV1 >= INF && distV2 >= INF) cout << -1;
	else cout << ((distV1 > distV2) ? distV2 : distV1);
}