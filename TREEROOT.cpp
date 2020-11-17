#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int result = 0;
        for(int i = 0; i < n; i++) {
            int j, k;
            cin >> j >> k;
            result += j - k;
        }
        cout << result << endl;
    }
    return 0;
}
