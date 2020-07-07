/*
Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

string Solution::intToRoman(int A) {
    string s="";
    while(A){
        if(A/1000){
            A-=1000;
            s+='M';
        }else if(A/100){
            if(A/100==9){
                s.append("CM");
                A-=900;
            }else if(A/100==4){
                s.append("CD");
                A-=400;
            }else if(A/500==1){
                s.append("D");
                A-=500;
            }else{
                s.append("C");
                A-=100;
            }
        }else if(A/10){
            if(A/10==9){
                s.append("XC");
                A-=90;
            }else if(A/10==4){
                s.append("XL");
                A-=40;
            }else if(A/50==1){
                s.append("L");
                A-=50;
            }else{
                s.append("X");
                A-=10;
            }
        }else{
            if(A%10==9){
                s.append("IX");
                A-=9;
            }else if(A%10==4){
                s.append("IV");
                A-=4;
            }else if(A/5==1){
                s.append("V");
                A-=5;
            }else{
                s.append("I");
                A-=1;
            }
        }
    }
    return s;
}
