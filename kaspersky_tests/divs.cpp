#include <bits./stdc++.h>
 
using namespace std;
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, m, div = 2, cnt = 1, pr;
	cin >> n;
	
	map<long long, long long> mp2;
	
	for (long long i = 0; i < n; ++i){
		map<long long, long long> mp;
		cin >> m;
		div = 2;
		while (m > 1){
			if (m % div == 0){
				if (mp.count(div) > 0){
					mp[div] += 1;
					m /= div;
				}else{
				mp[div] = 1;
				m /= div;
				}
//				cout << div << " " << mp[div] << endl;
			}else{
				div += 1;
			}
			
		}
		
		for (auto i : mp){
			if (mp2.count(i.first) > 0){
				mp2[i.first] = max(mp2[i.first], i.second);
			}else{
				mp2[i.first] = i.second;
			}
//			cout << "HERE" << i.first << endl;
		}
		
	}
	
	for (auto i : mp2){
		pr = 1;
		cout << i.first << " " << i.second << endl;
		for (long long j = 0; j < i.second; ++j){
			pr *= i.first;
		}
		cnt *= pr;
//		if (i.second > 1){
//			cnt /= i.first;
//		}
//		cout << i.first << i.second << endl;
	}
	cout << cnt;
}