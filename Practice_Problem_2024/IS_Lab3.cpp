#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long mod = 99244353; // 10^9
int bin_power(int a, int n, int mod)
{
  int ans = 1 % mod;
  while (n)
  {
    if (n & 1)
      ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
int gcd(int x, int y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}
int calculate_d(int e, int phin)
{
  for (int i = 2; i < phin; i++)
  {
    if ((i * e) % phin == 1)
    {
      return i;
    }
  }
  return -1;
}

vector<int> encrypt(string plaintext, int e, int n)
{
  vector<int> encrypted;
  for (char ch : plaintext)
  {
    int cipher = bin_power((int)ch, e, n);
    encrypted.push_back(cipher);
  }
  return encrypted;
}
string decrypt(vector<int> ciphertext, int d, int n)
{
  string decrypted;
  for (int val : ciphertext)
  {
    decrypted += (char)(bin_power(val, d, n));
  }
  return decrypted;
}
int32_t main(){
  string plaintext;
  cin >> plaintext;
  int p = 0 , q = 0 ;
  vector<int>prime;
  for(int i= 2; i <= 100; i++){
    bool f = true;
    for(int j = 2 ; j * j <= i;j++){
      if(i % j == 0) {
        f = false; break;
      }
    }
    if(f) prime.push_back(i);
  }
  for(auto &x:prime){
    bool f= false;
    for(int j = prime.size()-1;j >= 0; j--){
      if(x != prime[j] and x * prime[j] <= 200){
        p = x , q = prime[j];
        f = true;
        break;
      }
    }
    if(f) break;
  }
  cout << "Selected Prime P = " << p << " q= "<< q << "where p * q <= 200"<<endl;

  int e = 0, d = 0, n = p * q;
  int phin = (p - 1) * (q - 1);
  for (int i = 2; i < phin; i++){
    if (gcd(i, phin) == 1){
      e = i;
      break;
    }
  }
  d = calculate_d(e, phin);

  cout << "Public key: e = " << e << ", n = " << n << endl;
  cout << "Private key: d = " << d << ", n = " << n << endl;
  cout << "Phi_n = " << phin << endl;

  vector<int> encrypted = encrypt(plaintext, e, n);
  cout << "Encrypted message: ";
  for (int val : encrypted)
    cout << val << " ";
  cout << endl;

  string decrypted = decrypt(encrypted, d, n);
  cout << "Decrypted message: " << decrypted << endl;
}
