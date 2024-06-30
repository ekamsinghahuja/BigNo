#include <bits/stdc++.h>
using namespace std;

class BigInteger {

public:

    string data;
    bool isNeg;

private:
    string addString(const string& a, const string& b) const {
        string res;
        int s1 = a.size(), s2 = b.size(), dig, carry = 0, i = 0, j = 0;
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
        if (carry > 0) res.push_back((carry + '0'));
        return res;
    }
    string subString(const string& a, const string& b) const {
        string res;
        int s1 = a.size(), s2 = b.size(), dig, bow = 0, i = 0, j = 0;
        while (i < s1 && j < s2) {
            if (a[i] - bow < b[j]) {
                dig = (a[i++] - '0') + 10 - bow - (b[j++] - '0');
                res.push_back((dig + '0'));
                bow = 1;
            } else {
                dig = (a[i++] - '0') - bow - (b[j++] - '0');
                res.push_back((dig + '0'));
                bow = 0;
            }
        }
        while (i < s1) {
            if ((a[i] - '0') - bow < 0) {
                dig = (a[i++] - '0') + 10 - bow;
                res.push_back((dig + '0'));
                bow = 1;
            } else {
                dig = (a[i++] - '0') - bow;
                res.push_back((dig + '0'));
                bow = 0;
            }
        }
        int ans_len = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] != '0') break;
            ans_len++;
        }
        ans_len = res.size() - ans_len;
        if (ans_len == 0) return "0";
        return res.substr(0, ans_len);
    }
    bool absGreaterThan(const string& num1, const string& num2) const {
        if (num1.size() != num2.size()) {
            return num1.size() > num2.size();
        }
        int i = num1.size() - 1;
        while (i >= 0 && num1[i] == num2[i]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        return num1[i] > num2[i];
    }
    bool isNegative() const {
        return isNeg;
    }

public:
    BigInteger(string s, bool rev_true = false) {
        if (rev_true) {
            int ss = s.size();
            if (s[ss - 1] == '-') {
                this->isNeg = true;
                this->data = s.substr(0, ss - 1);
            } else {
                this->isNeg = false;
                this->data = s;
            }
        } else {
            if (s[0] == '-') {
                this->isNeg = true;
                this->data = s.substr(1);
            } else {
                this->isNeg = false;
                this->data = s;
            }
            reverse(data.begin(), data.end());
        }
    }
    BigInteger() : data("0"), isNeg(false) {}

    BigInteger operator+(const BigInteger& other) const {
        if (this->isNegative() == other.isNegative()) {
            string result = addString(this->data, other.data);
            if (this->isNegative()) result = result + '-';
            return BigInteger(result, true);
        } else {
            if (absGreaterThan(this->data, other.data)) {
                string result = subString(this->data, other.data);
                if (this->isNegative()) result = result + '-';
                return BigInteger(result, true);
            } else {
                string result = subString(other.data, this->data);
                if (other.isNegative()) result = result + '-';
                return BigInteger(result, true);
            }
        }
    }
    BigInteger operator-(const BigInteger& other) const {
        if (this->isNegative() != other.isNegative()) {
            string result = addString(this->data, other.data);
            if (this->isNegative()) result = result + '-';
            return BigInteger(result, true);
        } else {
            if (absGreaterThan(this->data, other.data)) {
                string result = subString(this->data, other.data);
                if (this->isNegative()) result = result + '-';
                return BigInteger(result, true);
            } else {
                string result = subString(other.data, this->data);
                if (!other.isNegative()) result = result + '-';
                return BigInteger(result, true);
            }
        }
    }
    BigInteger operator*(const BigInteger& other) const {
        int sign = (this->isNeg == other.isNeg) ? 1 : -1;
        string result(this->data.size() + other.data.size(), '0');

        for (int i = 0; i < this->data.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.data.size(); ++j) {
                int sum = (result[i + j] - '0') + (this->data[i] - '0') * (other.data[j] - '0') + carry;
                result[i + j] = (sum % 10) + '0';
                carry = sum / 10;
            }
            result[i + other.data.size()] += carry;
        }

        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        if (sign == -1) result.push_back('-');

        return BigInteger(result, true);
    }

    BigInteger& operator++() {
        BigInteger one("1");
        *this = *this + one;
        return *this;
    }
    BigInteger operator++(int) {
        BigInteger temp = *this;
        ++(*this);
        return temp;
    }
    BigInteger& operator--() {
        BigInteger one("-1");
        *this = *this + one;
        return *this;
    }
    BigInteger operator--(int) {
        BigInteger temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const BigInteger& other) const {
        return this->isNeg == other.isNeg && this->data == other.data;
    }
    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }
    bool operator<(const BigInteger& other) const {
        if (this->isNeg != other.isNeg) {
            return this->isNeg;
        }
        if (this->data.size() != other.data.size()) {
            return this->isNeg ? this->data.size() > other.data.size() : this->data.size() < other.data.size();
        }
        for (int i = this->data.size() - 1; i >= 0; --i) {
            if (this->data[i] != other.data[i]) {
                return this->isNeg ? this->data[i] > other.data[i] : this->data[i] < other.data[i];
            }
        }
        return false;
    }
    bool operator<=(const BigInteger& other) const {
        return *this < other || *this == other;
    }
    bool operator>(const BigInteger& other) const {
        return !(*this <= other);
    }
    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    BigInteger& operator+=(const BigInteger& other) {
        *this = *this + other;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        if (bi.isNeg) os << '-';
        for (int i = bi.data.size() - 1; i >= 0; --i) {
            os << bi.data[i];
        }
        return os;
    }
    friend istream& operator>>(istream& is, BigInteger& bi) {
        string input;
        is >> input;
        bi = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger c("2");
    BigInteger d("22222");
    c = c*c*c*c*c*c*c;
    
    cout << c << endl;
    return 0;
}
