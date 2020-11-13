#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, x, y, a[100000], b[100000], valueA = 0, valueB = 0, total = 0;
    priority_queue<pair<int, int> > pq;
    cin>>n>>x>>y;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cin>>b[i];
    }
    for(int i=0; i<n; i++) {
        pq.push({ abs(a[i]-b[i]), i });
    }
    for(int i=0; i<n; i++) {
        valueA = a[pq.top().second];
        valueB = b[pq.top().second];
        if(x && y) {
            if(valueA > valueB) {
                total += valueA;
                x--;
            }
            else if(valueA < valueB) {
                total += valueB;
                y--;
            }
            else if(x > y) {
                total += valueA;
                x--;
            }
            else {
                total += valueB;
                y--;
            }
        }
        else if(x) {
            total += valueA;
            x--;
        }
        else {
            total += valueB;
            y--;
        }
        pq.pop();
    }
    cout<<total<<endl;

    return 0;
}
