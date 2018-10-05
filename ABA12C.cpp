#include<bits/stdc++.h>
#include <math.h> 

using namespace std;

#define MAX_P 10000001

void printvec(const vector<int>& vec) {
	cout << "Vector of size " << vec.size() << ": ";
	for (const auto& i : vec) cout << i << " ";
	cout << "\n";
}

int GetAppleCost(int n, vector<int>prices) {
	const int k = prices.size();
	vector<int> min_price_for_kgs = prices;  // 0 index -> 1kg and so on.
	for (int bag = 1; bag < n; ++bag) {
		int kg = 0;
		for (const int price : prices) {
			++kg;
			if (price == MAX_P) continue;
			for (int idx = 0; idx < k; ++idx) {
				int new_wt = idx + 1 + kg;
				if (new_wt > k) break;
				min_price_for_kgs[new_wt-1] = min(min_price_for_kgs[new_wt-1], price + min_price_for_kgs[idx]);
			}
		}
	}
	if (min_price_for_kgs[k - 1] < MAX_P) {
		return min_price_for_kgs[k - 1];
	}
	return -1;
}

int main() {
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; ++i) {
    int n, k;
    cin >> n >> k;
    vector<int> prices(k);
    for (auto& price : prices) {
    	cin >> price;
    	if (price == -1) {
    		price = MAX_P;
    	}
    }
    cout << GetAppleCost(n, prices) << "\n";
  }
  return 0;
}
