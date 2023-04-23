//#include <bits/stdc++.h>
//#include <string>
//
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	string s, res = "", res1 = "",n1 = "";
//	s = "0123456789abcdefghijklmnopqrstuvwxyz";
//	int a, b;
//	long long n;
//	cin >> a >> b >> n;
//	if (a!=10){
//		n1 = to_string(n);
//		n = stoll(n1,nullptr, a);
//	}
//	while (n > 0){
//		long long r;
//		r = n%b;
//		res.push_back(s[r]);
//		n/=b;}
//	for (int i=(res.size() - 1); i >= 0; --i){
//		res1.push_back(res[i]);}
//	cout << res1;	
//		
//	}
//	
//	long long n, l, r;
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	vector<int> a(n);
//	vector<int> b(n);
//	for (long long i=0; i<n; ++i){
//		cin >> a[i];
//	}
//	while (cin >> l >> r){
//		if (l==0 or r==0){
//			break;
//		}
//		for (long long i=(l-1); i<=(r-1); ++i){
//			b[n-i-1] = a[i];
//		}
//		
//	}
//	for (long long i=0; i<b.size(); ++i){
//		if (i == (b.size()-1)){
//			cout << b[i];
//		}
//		else{
//			cout << b[i] << " ";
//		}
//	}
//}
//	

#include <bits/stdc++.h>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	
//	string s, res = "", res1 = "",n1 = "";
//	s = "0123456789abcdefghijklmnopqrstuvwxyz";
//	int a, b;
//	long long n;
//	cin >> a >> b >> n;
//	if (a!=10){
//		n1 = to_string(n);
//		n = stoll(n1,nullptr, a);
//	}
//	while (n > 0){
//		long long r;
//		r = n%b;
//		res.push_back(s[r]);
//		n/=b;}
//	for (int i=(res.size() - 1); i >= 0; --i){
//		res1.push_back(res[i]);}
//	cout << res1;	
//		
//	}

	
	long long n, l, r, k;
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(10000);
	
	for (long long i=0; i<n; ++i){
		cin >> a[i];
	}
	
	k = 0;
	while (1==1){
		cin >> l >> r;
		a[k] = l;
		a[k+1] = r;
		if (a[k] == 0){
			break;
		}
		k += 2;
	}
	

	
	for (long long i=0; i < c.size(); i+=2){
		l = c[i];
		r = c[i+1];
		if (l==0 or r==0){
			break;
		}
		for (long long i=(l-1); i<=(r-1); ++i){
			b[n-i-1] = a[i];
		}
		
	}
	
	for (long long i=0; i<b.size(); ++i){
		if (i == (b.size()-1)){
			cout << b[i];
		}
		else{
			cout << b[i] << " ";
		}
	}
}



