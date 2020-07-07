/*
Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/

int Solution::romanToInt(string A) {
    int num=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='M'){
            num+=1000;
        }else if(A[i]=='D'){
            num+=500;
        }else if(A[i]=='C'){
            if(A[i+1]=='M'){
                num+=900;
                i++;
            }else if(A[i+1]=='D'){
                num+=400;
                i++;
            }else{
                num+=100;
            }
        }else if(A[i]=='L'){
            num+=50;
        }else if(A[i]=='X'){
            if(A[i+1]=='C'){
                num+=90;
                i++;
            }else if(A[i+1]=='L'){
                num+=40;
                i++;
            }else{
                num+=10;
            }
        }else if(A[i]=='V'){
            num+=5;
        }else if(A[i]=='I'){
            if(A[i+1]=='V'){
                num+=4;
                i++;
            }else if(A[i+1]=='X'){
                num+=9;
                i++;
            }else{
                num+=1;
            }
        }
    }
    return num;
}
