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
            if((a[i]-'0')-bow < 0){
                dig = (a[i++]-'0')+10-bow;
                res.push_back((dig+'0'));
                bow = 1; 
            }
            else{
                dig = (a[i++]-'0')-bow;
                res.push_back((dig+'0'));
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
    bool absGreaterThan(string& num1,string& num2) {
        if (num1.size() != num2.size()) {
            return num1.size() > num2.size();
        }
        int i=0;
        while(i<num1.size()&&num1[i]==num2[i]){
            i++;
        }
        if(i==0){
            return 0;
        }
        return num1[i] > num2[i];
    }
    bool isNegative(){
        return isNeg;
    }



public:
    string data;
    bool isNeg;

    BigInteger(string s) {
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
   

    BigInteger operator+(BigInteger& other){

        if(this->isNegative() == other.isNegative()){

            string result = addString(this->data, other.data);
            if (this->isNegative())result = result + '-';
            reverse(result.begin(),result.end());
            return BigInteger(result);
        }
        else{
            if(absGreaterThan(this->data,other.data)){
                string result = subString(this->data, other.data);
                if (this->isNegative())result = result + '-';
                reverse(result.begin(),result.end());
                return BigInteger(result);

            }
            else{
                
                string result = subString(other.data,this->data);
                if(other.isNegative())result = result + '-';
                reverse(result.begin(),result.end());
                return BigInteger(result);
            }
        }
    }




    
};

int main(){
    BigInteger a("-1211212212123");
    BigInteger b("-123666");
    BigInteger d("-123666");
    cout<<a.data<<" "<<b.data<<endl;
    BigInteger c = a+b+d;
    cout<<c.data<<endl;

   

   
    return 0;
    
}