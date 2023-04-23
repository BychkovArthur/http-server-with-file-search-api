#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, a, m, k, mod, sm = 0, cn = 1000000007;
	
	cin >> n >> a >> m >> k >> mod;
	vector<long long> cnt(mod);
	
	
	for (long long i = 0; i < n; ++i){
		cnt[a] ++;
		a = (a * m + k) % mod;	
	}

	
	long long i = 1;
	for (long long j = 0; j < mod; ++j){
		for (long long k = 0; k < cnt[j]; k ++){
			sm = sm + ((j * i) % cn) ;
			sm %= cn;
			i += 1; 
		}
		
		
	}
	cout << sm;
	
	
}