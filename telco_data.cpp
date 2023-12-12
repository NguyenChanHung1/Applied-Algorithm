#include <bits/stdc++.h>
using namespace std;

map<string,int> number_of_calls, call_duration;

bool isNumber(string number){
    if(number.length() != 10)
        return false;
    for(int i=0; i<10; i++){
        if(number[i] < '0' || number[i] > '9')
            return false;
    }
    return true;
}

int process_time(string ft, string et){
    int f = 3600 * (((ft[0] - '0') * 10 + (ft[1] - '0'))) + 
             60 * (((ft[3] - '0') * 10 + (ft[4] - '0'))) + 
             (ft[6] - '0') * 10 + (ft[7] - '0');
    int e = 3600 * (((et[0] - '0') * 10 + (et[1] - '0'))) + 
             60 * (((et[3] - '0') * 10 + (et[4] - '0'))) + 
             (et[6] - '0') * 10 + (et[7] - '0');
    return e-f;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool incorrectNumber = true;
    int totalcalls = 0;
    do{
        fflush(stdin);
        string fn, tn, d, ft, et;
        cin >> s;
        if(s[0] == '#')
            break;
        else{
            cin >> fn >> tn >> d >> ft >> et;
            if(!isNumber(fn) || !isNumber(tn)){
                incorrectNumber = false;
                continue;
            }
            number_of_calls[fn]++;
            call_duration[fn] += process_time(ft,et);
            ++totalcalls;
        }
    }
    while(1);

    do{
        fflush(stdin);
        string s;
        cin >> s;
        if(s[0] == '#') break;
        if(s[0] == '?'){
            if(s == "?check_phone_number")
                cout << incorrectNumber << endl;
            if(s == "?number_calls_from"){
                string num;
                cin >> num;
                cout << number_of_calls[num] << endl;
            }
            if(s == "?number_total_calls")
                cout << totalcalls << endl;
            if(s == "?count_time_calls_from"){
                string num; cin >> num;
                cout << call_duration[num] << endl;
            }
        }
    }
    while(1);

    return 0;
}