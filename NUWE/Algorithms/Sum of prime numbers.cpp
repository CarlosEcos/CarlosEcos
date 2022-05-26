#include <bits/stdc++.h>
using namespace std;

const int N = 1E6;
bool primes[N];

int main() {
	long long ans = 0;
	for(int i = 2; i < N; i++) primes[i] = 1;
	for(int i = 2; i*i < N; i++){
		if(!primes[i]) continue;
		for(int j = 2*i; j < N; j+=i) primes[j] = 0;
	}
	for(int i = 2; i < N; i++){
		if(primes[i]) ans += i;
	}
	cout << "Sum of the primes: " << ans;
	return 0;
}

// Sum of primes: 37550402023
