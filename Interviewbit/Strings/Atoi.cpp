/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions: Q1. Does string contain whitespace characters before the number?
A. Yes 

Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. 

Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. 

Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.
*/

int Solution::atoi(const string A) {
    
    long long num=0,s=0;
    int n=A.size();
    int flag=1;
    int sign=1;
    int prev=0;
    while(s<n){
        if(A[s]>='0'&&A[s]<='9'){
            int tnum=A[s]-'0';
            num=num*10+tnum;
            if(num>INT_MAX&&sign==1){
                return INT_MAX;
            }else if(num>INT_MAX&&sign==-1){
                return INT_MIN;
            }
            prev=num;
            flag=0;
            
        }else if(A[s]=='-'&&flag){
            sign=-1;
        }else if(A[s]=='+'&&flag){
            sign=1;
        }else{
            break;
        }
        s++;
    }
    if(sign==-1){
        num=-num;
    }
    return num;
}
