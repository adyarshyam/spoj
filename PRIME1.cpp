#include<bits/stdc++.h>
#include <math.h> 

using namespace std;

#define ll long long

void PrintPrimes(ll m, ll n) {
	ll m_p = (m-1)/2;
	ll n_p = n/2 + 1;
	vector<bool> is_prime(n_p - m_p, true);
	for (ll i = 1; i < sqrt(n_p/2) + 1; ++i) {
		for (ll j = std::max(i, (m_p-i)/(2*i+1)); j < n_p; ++j) {
			const ll sieve = i+j+2*i*j;
			if (sieve < m_p) continue;
			if (sieve >= n_p) break;
			is_prime[sieve - m_p] = false;
		}
	}
	if (m <= 2) cout << "2\n";
	for (ll i = m_p; i < n_p; ++i) {
		ll x = 2*i+1;
		if (x == 1) continue;
		if (x < m) continue;
		if (x > n) break;
		if (is_prime[i - m_p]) cout << x << "\n";
	}
    cout << "\n";
}

int main() {
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; ++i) {
    ll n, m;
    cin >> m >> n;
    if (m>n) {
    	std::swap(m, n);
    }
    PrintPrimes(m,n);
  }
  return 0;
}
