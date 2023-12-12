#include <bits/stdc++.h>
using namespace std;

int n,M,a[1000001]={0},x[1000001]={0},solution=0;

int lhs(){// compute left hand side --> O(n)
    int s = 0;
    for(int i=1;i<=n;i++)
        s += (a[i] * x[i]);
    return s;
}

void Try(int i=1){
    if(i>n){
        return;
    }
    for(int j=1;j<=M-n+1;j++){
        x[i] = j;
        int left = lhs();
        if(left > M){
            x[i] = 0;
            return;
        }
        if(left == M && i==n){
            solution++;
        }
        if(left < M){
            Try(i+1);
        }
        x[i]=0;
    }
}

int main(){
    cin >> n >> M;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    Try();
    cout << solution;
    return 0;
}