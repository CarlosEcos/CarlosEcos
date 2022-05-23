#include <bits/stdc++.h>
#define pb push_back
#define all(s) s.begin(),s.end()
using namespace std;

vector <int> squares;
vector<vector<int>> sols;

void init(){
	for(int i = 1; i <= 1000; i++)
	squares.pb(i*i);
}

int index (int a, int b){
	int x = lower_bound(all(squares), a*a + b*b) - squares.begin();
	return x+1;
}

int nro_sols(int p){
	int cnt = 0, c;
	for (int a = 1; a < p/2; a++){
		for (int b = 1; b <= a; b++){
			c = index(a,b);
			if((squares[c-1] == (a*a + b*b)) && a+b+c == p) cnt++;
		}
	}
	return cnt;
}

int main() {
	init();
	int n = 120;
	int ans = 0, p = 0, curr = 0, c;
	for(int i = 1; i <= n; i++){
		curr = nro_sols(i);
		if(curr > ans) p = i;
		ans = max(ans, curr);
	}
	cout << "El valor de p para el cual existe el máximo nro de soluciones: " << p << endl;
	cout << "Nro máximo de soluciones: "<< ans << endl;
	cout << "Soluciones\n";
	for (int a = 1; a < p/2; a++){
		for (int b = 1; b <= a; b++){
			c = index(a,b);
			if((squares[c-1] == (a*a + b*b)) && a+b+c == p){
				vector <int> v = {b,a,c};
				sols.pb(v);
			}
		}
	}
	sort(all(sols));
	for(auto v : sols) cout << v[0] << " " << v[1] << " " << v[2] << endl;
	
}
