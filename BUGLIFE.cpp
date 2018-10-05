#include<bits/stdc++.h>

using namespace std;

struct Node {
  vector<int> out;
  bool is_male;
};

bool IsBipartite(vector<Node>* graph) {
	const int n = graph->size();
	queue<int> bfs_q;
	vector<bool> visited(n);
	vector<bool> is_male(n);
	for (int start_node = 0; start_node < n; ++start_node) {
		if (visited[start_node]) {
			continue;
		}
		bfs_q.push(start_node);
		is_male[start_node] = true;
		visited[start_node] = true;
		while (!bfs_q.empty()) {
			auto curr_node = bfs_q.front();
			bfs_q.pop();
			for (const auto& nbr_idx : (*graph)[curr_node].out) {
				if (visited[nbr_idx]) {
					if (is_male[nbr_idx] == is_male[curr_node]) {
						return false;
					}
				} else {
					visited[nbr_idx] = true;
					is_male[nbr_idx] = !is_male[curr_node];
					bfs_q.push(nbr_idx);
				}
			}
		}
	}
	return true;
}

int main() {
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; ++i) {
    int n, m;
    cin >> n >> m;
    vector<Node> graph(n);
    for (int edge = 0; edge < m; edge++) {
      int start, end;
      cin >> start >> end;
      graph[start-1].out.push_back(end-1);
      graph[end-1].out.push_back(start-1);
    }
    cout << "Scenario #" << i+1 << ":\n";
    cout << (IsBipartite(&graph) ? "No s" : "S") << "uspicious bugs found!\n";
  }
  return 0;
}
