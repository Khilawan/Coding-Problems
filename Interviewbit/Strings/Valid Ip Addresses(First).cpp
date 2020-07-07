/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

int stoii(string s){
    if(s.size()==1){
        return s[0]-'0';
    }
    int num=0;
    for(int i=0;i<s.size();i++){
        int t=s[i]-'0';
        num=num*10+t;
    }
    return num;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string>res;
    int n=A.size();
    if(n>12){
        return res;
    }
    string s1="";
    string s2="";
    string s3="";
    string s4="";
    for(int z=0;z<=n-4;z++){
        s1+=A[z];
        int tmp1=stoii(s1);
        if(tmp1<0||tmp1>255&&s1.size()>3){
            break;
        }
        for(int i=z+1;i<=n-3;i++){
            s2+=A[i];
            int tmp2=stoii(s2);
            if(tmp2<0||tmp2>255||s2.size()>3){
                break;
            }
            for(int j=i+1;j<=n-2;j++){
                s3+=A[j];
                int tmp3=stoii(s3);
                if(tmp3<0||tmp3>255||s3.size()>3){
                    break;
                }
                for(int k=j+1;k<=n-1;k++){
                    s4+=A[k];
                    int tmp4=stoii(s4);
                    if(tmp4<0||tmp4>255||s4.size()>3){
                        break;
                    }
                    string str="";
                    str.append(s1);
                    str+='.';
                    str.append(s2);
                    str+='.';
                    str.append(s3);
                    str+='.';
                    str.append(s4);
                    
                    if(str.size()-3==A.size()){
                        //cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;
                        res.push_back(str);
                    }
                    if(s4[0]=='0'){
                        break;
                    }
                }
                s4="";
            
                if(s3[0]=='0'){
                    break;
                }
            }
           s3="";
           if(s2[0]=='0'){
                break;
            }
        }
        s2="";
        if(s1[0]=='0'){
            break;
        }
    }
    return res;
}
