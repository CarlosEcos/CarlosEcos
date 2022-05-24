#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define all(s) s.begin(),s.end()
using namespace std;

const int N = 1E6+5;

bool primes[N];
int pot[7];
vi digits;

void init(){
	pot[0] = 1;
	for(int i = 1; i < 7; i++){
		pot[i] = 10*pot[i-1];
	} 
	for(int i = 2; i < N; i++) primes[i] = 1;
	for(int i = 2; i*i < N; i++){
		if(!primes[i]) continue;
		for(int j = 2*i; j < N; j+=i) primes[j] = 0;
	}
}

bool circular(int p){
	digits.clear();
	while(p > 0){
		digits.pb(p%10);
		p /= 10;
	}
	int l = digits.size();
	for(int i = 0; i < l; i++){
		int c = 0;
		for(int j = 0; j < l; j++){
			c += digits[(i+j)%l]*pot[j];
		}
		if(!primes[c]) return false;
	}
	return true;
}

int main() {
	init();
	vi sol;
	circular(97);
	for(int i = 2; i <= 1e6; i++){
		if(!primes[i]) continue;
		if(circular(i)) sol.pb(i);
	}
	cout << "Number of circular primes: " << sol.size() << endl;
	cout << "Circular primes" << endl;
	for(auto x:sol) cout << x << endl; 
	return 0;
}

/*
Number of circular primes: 55
Circular primes
2
3
5
7
11
13
17
31
37
71
73
79
97
113
131
197
199
311
337
373
719
733
919
971
991
1193
1931
3119
3779
7793
7937
9311
9377
11939
19391
19937
37199
39119
71993
91193
93719
93911
99371
193939
199933
319993
331999
391939
393919
919393
933199
939193
939391
993319
999331 
*/
