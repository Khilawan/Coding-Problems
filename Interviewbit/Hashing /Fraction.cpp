/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
*/

string Solution::fractionToDecimal(int A, int B) {
    long long n=A,d=B;
    string res="";
    map<long long,long long>m;
    
    if(n==0){
        return "0";
    }
    
    res+=to_string(n/d);
    
    if(n%d==0){
        return res;
    }
    
    res+='.';
    
    for(long long r=n%d;r;r%=d){
        
        if(m.find(r)!=m.end()){
            res.insert(m[r],1,'(');
            res+=')';
            break;
        }
        m[r]=res.size();
        r*=10;
        res.push_back((r/d)+'0');
    }
    
    return res;
}