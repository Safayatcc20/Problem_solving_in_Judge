//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define int long long int

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

main()
{
   while(1){
    long long  l , w;
        cin >> l >> w;
        vector<float>v;
        if( l == 0 && w == 0 ){ break;}
        /*
        int b = (l / 2) + 1;
        //cout << b << endl;
        for(double i  = (double)b ; i <=  l ; i=i+.01){
            double c = l  - i;

                double dis = sqrt(abs(c * c - i* i ));
                double final = w - dis;
                float ans = final + i + i;
                cout <<  i << " "<< ans << endl;
                v.push_back(ans);
        }
        sort(v.begin(),v.end());
        //cout << v.size() << endl;
        double aas = v[0];
        cout << fixed << setprecision(4) << aas << endl; */
        double dd = ( 5 * l * 1.0 ) / 8 * 2;
        double ans = w* 1.0 - (l / 2.0 ) + dd;
        cout << fixed << setprecision(4) << ans << endl;       
    }
}