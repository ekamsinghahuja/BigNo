#include <bits/stdc++.h>
using namespace std;

class BigInteger {
private:
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



public:
    string data;
    bool isNeg;

    BigInteger(string& s) {
        if (s[0] == '-'){
            this->isNeg = true; 
            this->data = s.substr(1); 
        } 
        else{
            this->isNeg = false;
            this->data = s;
        }
        reverse(data.begin(),data.end());
    }
    bool isNegative(){
        return isNeg;
    }

    BigInteger operator+(BigInteger& other){
        if(this->isNegative != other.isNegative){
            string result = addStrings(this->data, other.data);
            if (this->isNegative)result = result + '-';
            return BigInteger(result);
        }
        else{
            if()
            string result = 

            
        }
    }




    
};

int main(){
    string num1 = "-123456789";
    BigInteger bigInt1(num1);

    string num2 = "987654321";
    BigInteger bigInt2(num2);

    cout << "bigInt1: " << (bigInt1.isNeg ? "-" : "") << bigInt1.data << endl;
    cout << "bigInt2: " << (bigInt2.isNeg ? "-" : "") << bigInt2.data << endl;

    return 0;
    
}