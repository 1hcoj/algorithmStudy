#include <iostream>
#include <vector>
#include<queue>
#include<cmath>
#include<string>
#define ll long long
#define INF 10000000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node, edge;
	ll graph[101][101];
	string graph_route[101][101];
	
	fill(&graph_route[0][0], &graph_route[100][101], " ");
	fill(&graph[0][0], &graph[100][101], INF);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		ll start, end, value;
		cin >> start >> end >> value;
		graph[start][end] = min(graph[start][end], value);
		graph_route[start][end] = to_string(start) + to_string(end);
	}

	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (i == j)continue;
			for (int z = 1; z <= node; z++) {
				if (z == i || z == j)continue;
				if (graph[i][j] > graph[i][z] + graph[z][j]) {
					graph[i][j] = graph[i][z] + graph[z][j];
					graph_route[i][j] = graph_route[i][z];
					graph_route[i][j].erase(graph_route[i][j].length() - 1, 1);
					graph_route[i][j] += graph_route[z][j];
				}
			}
		}
	}
	for (int i = node; i >= 1; i--) {
		for (int j = node; j >= 1; j--) {
			if (i == j)continue;
			for (int z = 1; z <= node; z++) {
				if (z == i || z == j)continue;
				if (graph[i][j] > graph[i][z] + graph[z][j]) {
					graph[i][j] = graph[i][z] + graph[z][j];
					graph_route[i][j] = graph_route[i][z];
					graph_route[i][j].erase(graph_route[i][j].length() - 1, 1);
					graph_route[i][j] += graph_route[z][j];
				}
			}
		}
	}
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (graph[i][j] == INF) {
				cout << "0" << " ";
			}
			else {
				cout << graph[i][j] << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			if (graph_route[i][j].length() > 1) {
				cout << graph_route[i][j].length() << " ";
				for (int z = 0; z < graph_route[i][j].length(); z++) {
					cout << graph_route[i][j][z] << " ";
				}
				cout << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
	}
}