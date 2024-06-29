#include <bits/stdc++.h>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

string addString(const string& a, const string& b) {
    string res;
    int s1 = a.size(), s2 = b.size(),dig,carry = 0,i = 0, j = 0;
    while (i < s1 && j < s2) {
        int dig = carry + (a[i++] - '0') + (b[j++] - '0');
        res.push_back((dig % 10 + '0'));
        carry = dig / 10;
    }
    while (i < s1) {
        int dig = carry + (a[i++] - '0');
        res.push_back((dig % 10 + '0'));
        carry = dig / 10;
    }
    while (j < s2) {
        int dig = carry + (b[j++] - '0');
        res.push_back((dig % 10 + '0'));
        carry = dig / 10;
    }
    if (carry > 0)res.push_back((carry + '0'));
    
    return res;
}

int main() {
    string a = "123";
    string b = "01145";

    const int iterations = 500000;
    auto total_duration = chrono::nanoseconds::zero();

    for (int i = 0; i < iterations; ++i) {
        auto start = chrono::high_resolution_clock::now();
        string result = addString(a, b);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        total_duration += duration;
    }

    
    auto average_duration = total_duration / iterations;
    cout << "Average time taken: " << average_duration.count() << " nanoseconds" << endl;

    cout<<addString(a,b)<<endl;


    return 0;
}
