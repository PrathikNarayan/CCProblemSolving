#include <iostream>
using namespace std;

const long long MAX = 1ll << 32;

int main() {
    int t;
    cin >> t;
    for(long long n; cin >> n; cout << endl) {
        for(int i = 0; i < n + 1 - MAX % (n + 1); i++) {
            cout << MAX / (n + 1) << ' ';
        }
        for(int i = 0; i < MAX % (n + 1) - 1; i++) {
            cout << MAX / (n + 1) + 1 << ' ';
        }
    }
    return 0;
}
