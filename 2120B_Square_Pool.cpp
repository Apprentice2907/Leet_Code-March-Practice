// My approach but claude coded

#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int count = 0;
        for(int i = 0; i < n; i++){
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            long long tx = (dx == 1) ? (s - x) % s : x % s;
            long long ty = (dy == 1) ? (s - y) % s : y % s;
            
            if(tx == ty) count++;
        }
        cout << count << "\n";
    }
    return 0;
}