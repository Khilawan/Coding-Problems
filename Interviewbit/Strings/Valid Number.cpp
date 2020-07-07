/*
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

1. Is 1u ( which may be a representation for unsigned integers valid?
    For this problem, no.

2. Is 0.1e10 valid?
    Yes

3. -01.1e-10?
    Yes

4. Hexadecimal numbers like 0xFF?
    Not for the purpose of this problem

5. 3. (. not followed by a digit)?
    No

6. Can exponent have decimal numbers? 3e0.1?
    Not for this problem.

7. Is 1f ( floating point number with f as prefix ) valid?
    Not for this problem.

8. How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
    Not for this problem.

9. How about integers preceded by 00 or 0? like 008?
    Yes for this problem
*/

int Solution::isNumber(const string A) {
    int s=0,n=A.size();
    int flag=0;
    int sign=0;
    int dig=0;
    int fdig=0;
    int l=n-1;
    while(l>=0){
        if(A[l]==' '){
            --n;
        }else{
            break;
        }
        l--;
    }
    for(;s<n;s++){
        if(fdig==0&&A[s]==' '){
            continue;
        }
        if(A[s]<='9'&&A[s]>='0'){
            dig=1;
            fdig=1;
            continue;
        }else if(A[s]=='.'){
            if(flag){
                return 0;
            }
            flag=1;
            dig=0;
        }else if(A[s]=='e'){
            if(flag&&dig==0){
                return 0;
            }
            sign=0;
            flag=1;
            dig=0;
        }else if(A[s]=='-'||A[s]=='+'){
            if(sign){
                return 0;
            }
            sign=1;
            dig=0;
        }else{
            return 0;
        }
    }
    if(dig!=1){
        return 0;
    }
    return 1;
}
