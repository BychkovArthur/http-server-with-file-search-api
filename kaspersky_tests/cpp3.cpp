#include <bits/stdc++.h>
 
// text
using namespace std;
 
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, gl_max_id = -1, gl_max_value = LONG_LONG_MIN, gl_min_id = -1, gl_min_value = LONG_LONG_MAX;
	cin >> n;
	vector <long long> a(n);
	vector <long long> mn(0);
	vector <long long> mx(0);
	
 	
	for(long long i = 0; i < n; ++i){
		cin >> a[i];
	}
	cout << '\n';
	
	if (n == 1){
 		cout << 1 << " "<< 1 << endl;
 		cout << 1 << " "<< 1 << endl;
 		cout << 1 << " "<< 1 << endl;
 		return 0;
	}
	
	
	
	if (n > 1){
	
	if (a[0] > a[1]){
		mx.push_back(1);
	}
	if (a[0] < a[1]){
		mn.push_back(1);
	}
}
	
	
	gl_max_value = max(a[0], a[n-1]);
	gl_min_value = min(a[0], a[n-1]);
	if (gl_max_value == a[0]){
		gl_max_id = 1;
	}
	else{
		gl_max_id = n;
	}
	
	if (gl_min_value == a[0]){
		gl_min_id = 1;
	}
	else{
		gl_min_id = n;
	}
	
	
	for (long long i = 1; i < n - 1; ++ i){
		if (a[i] > a[i-1] and a[i] > a[i+1]){
			mx.push_back(i+1);
			if (a[i] > gl_max_value){
				gl_max_value = a[i];
				gl_max_id = i+1;
			}	
		}
		
		if (a[i] < a[i-1] and a[i] < a[i+1]){
			mn.push_back(i+1);
			if (a[i] < gl_min_value){
				gl_min_value = a[i];
				gl_min_id = i+1;
			}
		}
	}
	
	if (n > 1){
	
	if (a[n-1] > a[n-2]){
		mx.push_back(n);
	}
	if (a[n-1] < a[n-2]){
		mn.push_back(n);
	}
}
	
	cout << mn.size() << " ";
	
	for (long long i = 0; i < mn.size(); ++i){
		cout << mn[i] << " ";
	}
	
	cout << endl;
	cout << mx.size() << " ";
//	cout << mx[0];
 
	for (long long j = 0; j < mx.size(); ++j){
		cout << mx[j] << " ";
	}
	
	cout << "\n" << gl_min_id << " " << gl_max_id;
	return 0;
	
}