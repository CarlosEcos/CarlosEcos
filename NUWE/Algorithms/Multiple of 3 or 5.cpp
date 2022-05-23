#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1000 - 1;
	int a = n/3, b = n/5, c = n/15;
	int ans = 3*a*(a+1)/2 + 5*b*(b+1)/2 - 15*c*(c+1)/2;
	cout << ans;
	return 0;
}
