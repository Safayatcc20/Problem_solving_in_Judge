#include <bits/stdc++.h>
using namespace std;
void decrypt(int row, int col, string &key, map<char, int> &mp, 
    vector<vector<char>> &v, string &cipher){
    map<char, vector<char>> smp;
    string nkey = key;
    int k = 0;
    sort(nkey.begin(), nkey.end());
    int len = cipher.size();

    for (int i = 0; i < col; i++){
        for (int j = 1; j < row; j++){
            smp[nkey[i]].push_back(cipher[k]);
            k++;
        }
    }
    cout << "Plaintext: ";
    int kk = 0;
    for (int i = 0; i < row - 1; i++){
        for (int j = 0; j < col; j++){
            if (smp[key[j]][kk] == '*') continue;
            cout << smp[key[j]][kk];
        }
        kk++;
    }
    cout << endl;
}

int32_t main()
{
    string plain, key,cipher = "";
    cin >> plain >> key;
    int col = key.size(),row = plain.size();
    row = (col + row - 1) / col+1;
    vector<vector<char>> v(row, vector<char>(col));
    int k = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (i == 0) v[i][j] = key[j];
            else if (k < plain.size()){
                    v[i][j] = plain[k];
                    k++;
            }
            else v[i][j] = '*';
            
        }
    }
    map<char, int> mp;
    for (int i = 0; i < col; i++) mp[v[0][i]] = i;
    cout << "Cipher Text: " ;
    for (auto &x : mp){
        for (int i = 1; i < row; i++){
            cout << v[i][x.second];
            cipher += v[i][x.second];
        }
    }
    cout << endl;
    decrypt(row, col, key, mp, v, cipher);
}