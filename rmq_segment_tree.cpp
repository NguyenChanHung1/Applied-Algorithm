// Partial 2/4

#include <bits/stdc++.h>
using namespace std;

int A[10000001], T[100000000];
int n,m;

void construct_segment(int l, int r, int node=0){
    if(l > r) return;
    if(l == r){
        T[node] = A[l];
        return;
    }
    int m = (l+r)/2;
    construct_segment(l,m,2*node+1);
    construct_segment(m+1,r,2*node+2);
    T[node] = min(T[2*node+1], T[2*node+2]);
}

int rmq(int si, int sl, int sr, int l, int r){
    if(sl >= l && sr <= r){
        return T[si];
    }
    if(sr < l || sl > r){
        return INT_MAX;
    }
    int mid = (sl+sr)/2;
    return min(
        rmq(2*si+1,sl,mid,l,r), rmq(2*si+2,mid+1,sr,l,r)
    );
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) A[i] = 0;
    for (int i=0; i<n; i++)
        cin >> A[i];

    construct_segment(0,n-1);

    cin >> m;
    int sum_ = 0;
    for (int i=0; i<m; i++){
        int l,r;
        cin >> l >> r;
        if(l > r)
            sum_ += 0;
        else
            sum_ += rmq(0,0,n-1,l,r);
    }

    cout << sum_;

    return 0;
}