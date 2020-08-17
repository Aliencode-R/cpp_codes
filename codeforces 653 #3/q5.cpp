#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100005] = {0};
ll cnt[100005] = {0};
ll sum[100005] = {0};

int main() {
	ll n; cin >> n;

	for(ll i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]] ++;
	}
	for(ll i = 2; i < 100005; i++) {
		for(ll j = i; j < 100005; j+=i) {
			sum[i] += cnt[j];
		}
	}
	ll q;
	cin >> q;
	while(q--) {
		ll qi; cin >> qi;
		cout << sum[qi] << endl;
	}
	// for(int i = 0; i < 1000; i++) {
	// 	if(sum[i] != 0) {
	// 		cout << i << " " << sum[i] << endl;
 	// 	}
	// }
	return 0;
}