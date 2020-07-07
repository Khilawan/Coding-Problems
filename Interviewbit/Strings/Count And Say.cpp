/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/

string Solution::countAndSay(int A) {
    if(A==0){
        return "";
    }else if(A==1){
        return "1";
    }
    string prev="1";
    int count=0;
    char ch;
    for(int i=1;i<A;i++){
        ch=prev[0];
        count=1;
        string s="";
        for(int j=1;j<=prev.size();j++){
            if(prev[j]==prev[j-1]){
                count++;
            }else{
                s+=to_string(count);
                s+=ch;
                ch=prev[j];
                count=1;
            }
        }
        prev=s;
    }
    return prev;
}
