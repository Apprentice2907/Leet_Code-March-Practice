// Claude helped 

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        
        int L = INT_MAX, R = INT_MIN;
        for(int i = 0; i < n; i++){
            int xi;
            cin >> xi;
            if(xi < L) L = xi;
            if(xi > R) R = xi;
        }
        
        if(s <= L){
            cout << R - s << "\n";
        } else if(s >= R){
            cout << s - L << "\n";
        } else {
            int left_first = (s - L) + (R - L);
            int right_first = (R - s) + (R - L);
            cout << min(left_first, right_first) << "\n";
        }
    }
    return 0;
}