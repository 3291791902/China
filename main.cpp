#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
namespace China {
	typedef long long LL;
	struct Group {
		LL m;
		LL a;
	};
	LL gcd(LL a, LL b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
	LL lcm(LL a, LL b) {
		return a * b / gcd(a, b);
	}
	LL exgcd(LL a, LL b, LL& x, LL& y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		LL r = exgcd(b, a % b, x, y);
		LL temp = x;
		x = y;
		y = temp - (a / b) * y;
		return r;
	}
	LL getAnswer(vector<Group>vec) {
		LL x = 0, M = 1;
		bool OK = true;
		int n = vec.size();
		for (int i = 0; i < n; i++) {
			LL temp = vec[i].a - x;
			LL x1, y1;
			LL r = exgcd(M, vec[i].m, x1, y1);
			if (abs(temp) % r != 0) {
				OK = false;
				break;
			}
			x1 = x1 * temp / r;
			x += x1 * M;
			M = lcm(M, vec[i].m);
		}
		if (OK) {
			x = (x % M + M) % M;
			return x;
		}
		else {
			return -1;
		}
	}
};
int main() {
	using namespace China;
	while (true) {
		vector<Group>vec;
		int n;
		cin >> n;
		vec.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i].m >> vec[i].a;
		}
		LL ans = getAnswer(vec);
		if (ans == -1) {
			cout << "No Answer" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
