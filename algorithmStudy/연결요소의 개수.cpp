#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph2;

void dfs(int v, vector<bool>& visited) {
	visited[v] = true;
	for (int v1 : graph2[v]) {
		if (!visited[v1]) dfs(v1, visited);
	}
}
int notmain() {
	int n, m;
	cin >> n >> m;

	graph2 = vector<vector<int>>(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			count++;
			dfs(i, visited);
		}
	}
	cout << count << endl;
	return 1;
}