#include <bits/stdc++.h>
using namespace std;

class BigInt{
    string number;

    void simplify(){
        string s = this->number;
        while(s.size() > 1){
            if(s[0] == '0'){
                s = s.substr(1);
            }
            else{
                break;
            }
        }
        this->number = s;
    }

  public:   
    void assign(string s){
    	this->number = s;
    }

    bool operator<=(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
    	string s1 = this->number;
    	string s2 = b1.number;
    	int n1 = s1.size();
    	int n2 = s2.size();
        if(n1 < n2){
        	return true;
        }
        else if(n1 > n2) {
        	return false;
        }
        else{
        	for(int i=0;i<n1;i++){
        		int num1 = int(s1[i]-48);
        		int num2 = int(s2[i]-48);
        		if(num1 > num2){
        			return false;
        		}
        		else if(num1 < num2){
        			return true;
        		}
        	}
        	return true;
        }
    }

    bool operator>=(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        string s1 = this->number;
    	string s2 = b1.number;
    	int n1 = s1.size();
    	int n2 = s2.size();
        if(n1 > n2){
        	return true;
        }
        else if(n1 < n2){
        	return false;
        }
        else{
        	for(int i=0;i<n1;i++){
        		int num1 = int(s1[i]-48);
        		int num2 = int(s2[i]-48);
        		if(num1 < num2){
        			return false;
        		}
        		else if(num1 > num2){
        			return true;
        		}
        	}
        	return true;
        }
    }

    bool operator==(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        string s1 = this->number;
    	string s2 = b1.number;
    	int n1 = s1.size();
    	int n2 = s2.size();
        if(n1 == n2){
        	for(int i=0;i<n1;i++){
        		int num1 = int(s1[i]-48);
        		int num2 = int(s2[i]-48);
        		if(num1 > num2 || num1 < num2){
        			return false;
        		}
        	}
        	return true;
        }
        else{
        	return false;
        }
    }

    bool operator<(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
    	string s1 = this->number;
    	string s2 = b1.number;
    	int n1 = s1.size();
    	int n2 = s2.size();
        if(n1 < n2){
        	return true;
        }
        else if(n1 > n2){
        	return false;
        }
        else{
        	for(int i=0;i<n1;i++){
        		int num1 = int((this->number)[i]-48);
        		int num2 = int(b.number[i]-48);
        		if(num1 < num2){
        			return true;
        		}
        		else if(num1 > num2){
        			return false;
        		}
        	}
        	return false;
        }
    }

    bool operator>(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
    	string s1 = this->number;
    	string s2 = b1.number;
    	int n1 = s1.size();
    	int n2 = s2.size();
        if(n1 > n2){
        	return true;
        }
        else if(n1 < n2){
        	return false;
        }
        else{
        	for(int i=0;i<n1;i++){
        		int num1 = int(s1[i]-48);
        		int num2 = int(s2[i]-48);
        		if(num1 > num2){
        			return true;
        		}
        		else if(num1 < num2){
        			return false;
        		}
        	}
        	return false;
        }
    }

    BigInt operator+(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        BigInt ans;
        string sum;
        string s1 = this->number;
        string s2 = b1.number;
        int n1 = s1.size();
        int n2 = s2.size();
        int carry = 0;
        int i = n1-1, j = n2-1;
        while(i>=0 && j>=0){
            int curr_sum = (s1[i]-'0') + (s2[j]-'0') + carry;
            carry = curr_sum/10;
            curr_sum %= 10;
            sum = char(curr_sum+48) + sum; 
            i--;
            j--;
        }
        while(i>=0){
            int curr_sum = (s1[i]-'0') + carry;
            carry = curr_sum/10;
            curr_sum %= 10;
            sum = char(curr_sum+48) + sum; 
            i--;
        }
        while(j>=0){
            int curr_sum = (s2[j]-'0') + carry;
            carry = curr_sum/10;
            curr_sum %= 10;
            sum = char(curr_sum+48) + sum; 
            j--;
        }
        if(carry == 1){
            sum = "1" + sum;
        }
        ans.number = sum;
        return ans;
    }

    BigInt operator-(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        BigInt ans;
        string diff;
        string s1 = this->number;
        string s2 = b1.number;
        int n1 = s1.size();
        int n2 = s2.size();
        int borrow = 0;
        int i = n1-1, j = n2-1;
        while(i>=0 && j>=0){
            int minuend = (s1[i]-'0') - borrow;
            int subtrahend = s2[j]-'0';
            borrow = 0;
            if(minuend < subtrahend){
                minuend += 10;
                borrow = 1;
            }
            int curr_diff = minuend - subtrahend;
            diff = char(curr_diff+48) + diff;
            i--;
            j--;
        }
        while(i>=0){
            int curr_diff = (s1[i]-'0') - borrow;
            borrow = 0;
            diff = char(curr_diff+48) + diff;
            i--;
        }
        ans.number = diff;
        return ans;
    }

    BigInt operator*(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        BigInt ans;
        string s1 = this->number;
        string s2 = b1.number;
        int n1 = s1.size();
        int n2 = s2.size();
        int j = n2-1;
        while(j >= 0){
            int i = n1-1;
            int carry = 0;
            string product;
            while(i >= 0){
                int curr_pro = (s1[i]-'0') * (s2[j]-'0') + carry;
                carry = curr_pro/10;
                curr_pro %= 10;
                product = char(curr_pro+48) + product;
                i--;
            }
            if(carry != 0){
                product = char(carry+48) + product;
            }
            for(int k=n2-1;k>j;k--){
                product += '0';
            }
            BigInt temp;
            temp.number = product;
            ans += temp; 
            j--;
        }
        return ans;
    }

    BigInt operator/(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        BigInt ans;
        if(b1.number == "0"){
            ans.number = "undefined";
            return ans;
        }
        if(*this < b1){
            ans.number = "0";
            return ans;
        }
        string s1 = this->number;
        int n1 = s1.size();
        BigInt curr;
        int i = 1;
        curr.assign(s1.substr(0,i));
        while(curr < b1){
            i++;
            curr.assign(s1.substr(0,i));
        }
        while(i < n1){
            BigInt q;
            q.assign("1");
            while(b1 * q <= curr){
                ++q;
            }
            --q;
            BigInt temp;
            temp.assign("10");
            ans = ans * temp + q;
            BigInt product = b1 * q;
            curr -= product;
            curr.number += s1[i++];
            curr.simplify();
        }
        if(i == n1){
            BigInt q;
            q.assign("1");
            while(b1 * q <= curr){
                ++q;
            }
            --q;
            BigInt temp;
            temp.assign("10");
            ans = ans * temp + q;
        }
        return ans;
    }

    BigInt operator%(BigInt const &b){
        BigInt b1 = b;
        simplify();
        b1.simplify();
        if(b.number == "0"){
            BigInt ans;
            ans.number = "undefined";
            return ans;
        }
        BigInt temp = (*this)/b1;
        BigInt ans = (*this) - (temp * b1);
        return ans;
    }

    void operator=(BigInt const &b){
    	this->number = b.number;
    }

    void operator+=(BigInt const &b){
    	*this = *this + b; 
    }

    void operator-=(BigInt const &b){
    	*this = *this - b;
    }

    void operator*=(BigInt const &b){
    	*this = *this * b;
    }

    void operator/=(BigInt const &b){
    	*this = *this / b;
    }

    void operator%=(BigInt const &b){
    	*this = *this % b;
    }

    BigInt& operator++(){
    	BigInt temp;
    	temp.number = "1";
    	*this += temp;
    	return *this;
    }

    BigInt operator++(int){
    	BigInt org, temp;
    	temp.number = "1";
    	org = *this;
    	*this += temp;
    	return org;
    }

    BigInt& operator--(){
    	BigInt temp;
    	temp.number = "1";
    	*this -= temp;
    	return *this;
    }

    BigInt operator--(int){
    	BigInt org, temp;
    	temp.number = "1";
    	org = *this;
    	*this -= temp;
    	return org;
    }

    void print(){
        simplify();
    	cout <<this->number;
    }
};