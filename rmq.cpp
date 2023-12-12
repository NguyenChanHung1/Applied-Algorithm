// Partial 3/4

#include <bits/stdc++.h> 
using namespace std;

vector<int> A;
int M[20][100001] = {-1}; // M[j,i] = id(from = i, length = 2^j)
int n,m;

void preprocess(){ // O(n logn)
    for (int i=0; i<n; i++) M[0][i] = i;
    for (int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)-1<n; i++){
            M[j][i] = (A[M[j-1][i]] < A[M[j-1][i+(1<<(j-1))]] 
                            ? M[j-1][i] : M[j][i] = M[j-1][i+(1<<(j-1))]);
        }
    }
}

int rmq(int l, int r){ // O(1)
    int len = r - l + 1;
    int k = 0;
    while((1<<(k+1)) <= len) k++;
    return (A[M[k][l]] <= A[M[k][r-(1<<k)+1]] ? M[k][l] : M[k][r-(1<<k)+1]);
}

int main(){// O(n logn + m)
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        int e;
        cin >> e;
        A.push_back(e);
    }
    preprocess();
    cin >> m;
    int sum_ = 0;
    for(int i=0; i<m; i++){// O(m)
        int l,r;
        cin >> l >> r;
        sum_ = sum_ + A[rmq(l,r)];
    }
    cout << sum_;
}