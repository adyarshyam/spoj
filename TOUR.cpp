#include<bits/stdc++.h>

using namespace std;

struct Node {
  vector<int> out;
  vector<bool> reachable_set;
  vector<int> new_set;
  int reachable_count = 0;
  string tos() {
  	string x;
  	x = "out=";
  	for (const auto& o : out) {
  		x = x + to_string(o);
  	}
  	x += "\nreachable_set=";
  	for (const auto& o : reachable_set) {
  		x = x + to_string(o);
  	}
  	x += "\n";
  	return x;
  }
};

string PrintGraph(vector<Node>& graph) {
	string s;
	for (int i = 0; i < graph.size(); ++i) {
		s += ("Node " + to_string(i) + ": " + graph[i].tos() + "\n");
	}
	return s;
 }

int GetAllReachableCount(vector<Node>* graph) {
  const int n = graph->size();
  for (auto& node : *graph) {
    node.reachable_set = vector<bool>(false, n);
    node.new_set.clear();
    for (const auto& nbr : node.out) {
      node.reachable_set[nbr] = true;
      ++node.reachable_count;
      node.new_set.push_back(nbr);
    }
  }
  cout << PrintGraph(*graph);
  for (int i = 0; i < n; i++) {
    for (auto& node : *graph) {
      if (node.reachable_count == n) continue;
      vector<int> new_set;
      for (const auto& new_nbr : node.new_set) {
        for (const auto more_nbr : (*graph)[new_nbr].out) {
          if (!node.reachable_set[more_nbr]) {
            node.reachable_set[more_nbr] = true;
            ++node.reachable_count;
            new_set.push_back(more_nbr);
          }
        }
      }
      std::swap(node.new_set, new_set);
    }
  }
  int count = 0;
  for (auto& node : *graph) {
    if (node.reachable_count == n) {
      ++count;
    }
  }
  return count;
}

int main() {
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; ++i) {
    int n;
    cin >> n;
    vector<Node> graph(n);
    for (int j = 0; j < n; j++) {
      int nbr_cnt;
      cin >> nbr_cnt;
      for (int k = 0; k < nbr_cnt; ++k) {
        int nbr;
        cin >> nbr;
        graph[nbr-1].out.push_back(j);
      }
    }
    cout << GetAllReachableCount(&graph);
  }
  return 0;
}
