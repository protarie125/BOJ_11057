#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

constexpr auto mod = int{ 10'007 };

int solve(int n) {
	auto dp = vvi(n + 1, vi(10, 0));
	dp[0] = vi(10, 0);
	dp[1] = vi(10, 1);

	for (auto i = 2; i <= n; ++i) {
		for (auto j = 0; j < 10; ++j) {
			for (auto k = 0; k <= j; ++k) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}

	auto ret = int{ 0 };
	for (const auto& x : dp[n]) {
		ret += x;
		ret %= mod;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	const auto& ans = solve(n);
	cout << ans;

	return 0;
}