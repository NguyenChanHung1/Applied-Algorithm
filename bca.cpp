#include <bits/stdc++.h>
using namespace std;

int m,n,k;
vector<int> T[50];
int x[50] = {0}, load[50] = {0};
bool conflict[50][50] = {0};
int bound = INT_MAX;  // minimal max-load among all teachers

void input(){
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        int t; cin >> t;
        for(int j=1; j<=t; j++){
            int c; cin >> c;
            T[c].push_back(i);
        }
    }
    cin >> k;
    for(int i=1; i<=k; i++){
        int c1,c2; cin >> c1 >> c2;
        conflict[c1][c2] = 1;
        conflict[c2][c1] = 1;
    }
}

bool check(int t, int c){// O(n)
    for(int i=1; i<c; i++){
        if(x[i]==t && conflict[c][i]==1)
            return 0;   // == false if there's a conflict
    }
    return 1;   // == true if no conflict
}

int max_load(){
    int max_ = 0;
    for (int i=1; i<=m; i++)
        max_ = (max_ < load[i] ? load[i] : max_);
    return max_;
}

void Try(int i=1){// i=subject
    if(i > n){// O(m)
        bound = min(bound, max_load());
        return;
    }

    for(int t=0; t<T[i].size(); t++){//O(m^2+n...)
        x[i] = T[i][t];
        load[x[i]]++;
        if(bound <= max_load() || !check(x[i],i)){// O(m+n)
            load[x[i]]--;
            continue;
        }
        Try(i+1);
        load[x[i]]--;
    }
    
}

int main(){
    input();
    Try();
    cout << bound;
    return 0;
}