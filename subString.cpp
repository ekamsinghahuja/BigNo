#include <bits/stdc++.h>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

string subString(string& a,string& b){
    
    string res;
    int s1 = a.size(), s2 = b.size(),dig,bow = 0,i = 0, j = 0;
    while(i<s1 && j<s2){
        if(a[i]-bow < b[j]){
            dig = (a[i++]-'0')+10-bow-(b[j++]-'0');
            res.push_back((dig+'0'));
            bow = 1; 
        }
        else{
            dig = (a[i++]-'0')-bow-(b[j++]-'0');           
            res.push_back((dig+'0'));
            bow = 0;
        }
    }
    while(i<s1){
        if(a[i]-bow < '0'){
            dig = (a[i++]-'0')+10-bow;
            res.push_back(dig);
            bow = 1; 
        }
        else{
            dig = (a[i++]-'0')-bow;
            res.push_back(dig);
            bow = 0;
        }
    }
    int ans_len = 0;

    for(int i=res.size()-1;i>=0;i--){
        if(res[i]!='0')break;
        ans_len++;
    }
    
    ans_len = res.size() - ans_len;
    if(ans_len==0)return "0";
    return res.substr(0,ans_len);
}

int main() {
    string a = "00000000003";
    string b = "00000000003";

    // const int iterations = 500000;
    // auto total_duration = chrono::nanoseconds::zero();

    // for (int i = 0; i < iterations; ++i) {
    //     auto start = chrono::high_resolution_clock::now();
    //     string result = subString(a, b);
    //     auto end = chrono::high_resolution_clock::now();
    //     auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    //     total_duration += duration;
    // }

    
    // auto average_duration = total_duration / iterations;
    // cout << "Average time taken: " << average_duration.count() << " nanoseconds" << endl;

    cout<<subString(a,b)<<endl;


    return 0;
}
