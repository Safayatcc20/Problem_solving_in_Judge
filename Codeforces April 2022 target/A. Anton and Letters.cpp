#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    //if we get space character so that string will continue to foreward due to we use getline function.....
    getline(cin , s);
    sort(s.begin(), s.end());// using sort function
    //without library function for string sort;
    for(long long i = 0; i < s.size(); i++){
        for(long long j = 0 ; j < s.size(); j++){
            if(s[i] < s[j]){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    long long cnt = 0;
    char rep = '0';
    for(long long i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(s[i] != rep){
                cnt++;
                rep = s[i];
                //cout << s[i] << " ";
            }
        }
    }
    cout << cnt << "\n";
}
