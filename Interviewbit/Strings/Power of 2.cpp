/*
Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1
*/

int check(string s){

    string ss="";
    int l=0;
    int tmp=s[0]-'0';
    while(tmp<2){
        tmp=tmp*10+(s[++l]-'0');
    }

    while(l<s.size()){
        ss+=(tmp/2)+'0';
        tmp=(tmp%2)*10+s[++l]-'0';
    }

    int sn=ss.size();
    int ck=ss[sn-1]-'0';
    
    if(ck%2==1&&sn==1){
        if(stoi(ss)!=1){
            return 0;
        }else{
            return 1;
        }
    }else if(ck%2==1&&sn>1){
        return 0;
    }
    
    if(!check(ss)){
        return 0;
    }
    return 1;
}

  

int Solution::power(string A) {
    if(A.size()==1&&A[0]=='1'){
        return 0;
    }
    if(check(A)){
        return 1;
    }
    return 0;
}
