#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> A;  // grid of binary numbers
vector<int> h;  // heights
int n,m;

long long max_area = 0;

void input(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        vector<int> row;
        for (int j=0; j<m; j++){
            int e;
            cin >> e;
            row.push_back(e);
        }
        A.push_back(row);
    }
}

long long compute(vector<int> h){
    int max_A_row = 0, area = 0;
    stack<int> s;   // stack storing the indices of the columns in A
    int i = 0;
    while(i < h.size()){
        if(s.empty() || h[i] >= h[s.top()]){
            s.push(i);
            i++;
        }
        // i stops increasing at a moment when h[i-1] > h[i]
        // then the loop switches to executing the else block to compute
        // After finish computing, or pop out till the stack is empty,
        // i continues to grow, and execute the else block again.
        // when i reaches the size of h, the function continues to execute 
        // next while loop if the stack is not empty.
        else {
            // pop value whose index stored in stack to compute the largest 
            // area
            int top_val = h[s.top()];
            s.pop();  
            
            if(!s.empty())
                area = top_val * (i - s.top() - 1);
            else
                area = top_val * i;
            max_A_row = area > max_A_row ? area : max_A_row;
        }
    }
    while(!s.empty()){
        //pop out the remaining element of stack to compute the largest area according to
        //the height of considering row.
        int top_val = h[s.top()];
        s.pop();  
        area = top_val * i;
        if(!s.empty())
            area = top_val * (i - s.top() - 1);
        else
            area = top_val * i;    
        max_A_row = area > max_A_row ? area : max_A_row;
    }
    return max_A_row;
}
void maxArea(){
    long long m_a = 0;

    for(int i=0; i<n; i++){
        // Compute the height vector h with respect to current row
        for(int j=0; j<m; j++){
            if(i == 0){
                h.push_back(A[i][j]);
            }
            else{
                if(A[i][j] == 0) h[j] = 0;
                else h[j] = h[j] + 1;
            }
        }
        
        // Compute the area with respect to the row traversed
        long long area = compute(h);
        m_a = (m_a > area ? m_a : area);
    }

    max_area = m_a;
}


int main() 
{ 
    input();
    maxArea();
    cout << max_area;
}