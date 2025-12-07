 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
// Linear Diophantine Equation ax + by = c;
// if c % gcd( a , b)  == 0 then solution exist otherwise not
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// Euler totient function for single call
int phi(int n){
  int ans = n;
  for(int i = 2; i * i <= n ;i++){ 
   if(n % i == 0){
       ans /= i;
       ans *= (i-1);
       while(n % i== 0) n/= i;
   }
  }
  if(n > 1) ans /= n , ans *= (n - 1);
  return ans;
}
//Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int>phai(1e7+10);
void init(){
// here check the problem requirement
     int maxn = 1e7+10;
     for(int i = 1; i <= maxn; i++){
       phai[i] = i;
     }
     for(int i = 2; i<= maxn; i++){
       if(phai[i] == i){
         for(int j = i; j <= maxn; j+=i){
           phai[j]/=i; phai[j] *= (i-1);
         }
       }
     }
     // here is the prefix sum of phai function
     // for(int i = 1; i <= maxn; i++){
     //     phai[i] += phai[i-1];
     // }
}
int dist2(int ax, int ay, int bx, int by) {
    return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
}

int dot(int ax, int ay, int bx, int by) {
    return ax * bx + ay * by;
}

bool isRectangle(vector<pair<int, int>> &pts) {
    auto A = pts[0], B = pts[1], C = pts[2], D = pts[3];
    int ABx = B.first - A.first, ABy = B.second - A.second;
    int BCx = C.first - B.first, BCy = C.second - B.second;
    int CDx = D.first - C.first, CDy = D.second - C.second;
    int DAx = A.first - D.first, DAy = A.second - D.second;

    return dot(ABx, ABy, BCx, BCy) == 0 &&
           dot(BCx, BCy, CDx, CDy) == 0 &&
           dot(CDx, CDy, DAx, DAy) == 0 &&
           dot(DAx, DAy, ABx, ABy) == 0 &&
           dist2(A.first, A.second, B.first, B.second) > 0;
}

bool isSquare(vector<pair<int, int>> &pts) {
    if (!isRectangle(pts)) return false;
    int d1 = dist2(pts[0].first, pts[0].second, pts[1].first, pts[1].second);
    int d2 = dist2(pts[1].first, pts[1].second, pts[2].first, pts[2].second);
    return d1 == d2;
}

void solve() {
    vector<pair<int, int>> points(8);
    for (int i = 0; i < 8; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    vector<int> indices(8);
    for (int i = 0; i < 8; ++i)
        for (int j = i + 1; j < 8; ++j)
            for (int k = j + 1; k < 8; ++k)
                for (int l = k + 1; l < 8; ++l) {
                    vector<int> square_idx = {i, j, k, l};
                    vector<int> rect_idx;

                    for (int m = 0; m < 8; ++m) {
                        if (m != i && m != j && m != k && m != l) {
                            rect_idx.push_back(m);
                        }
                    }

                    vector<pair<int, int>> square_pts, rect_pts;
                    for (int idx : square_idx) square_pts.push_back(points[idx]);
                    for (int idx : rect_idx) rect_pts.push_back(points[idx]);

                    sort(square_pts.begin(), square_pts.end());
                    sort(rect_pts.begin(), rect_pts.end());

                    do {
                        if (isSquare(square_pts)) {
                            do {
                                if (isRectangle(rect_pts)) {
                                    ha;
                                    for (int idx : square_idx) cout << idx + 1 << " ";
                                    cout << sad;
                                    for (int idx : rect_idx) cout << idx + 1 << " ";
                                    cout << sad;
                                    return;
                                }
                            } while (next_permutation(rect_pts.begin(), rect_pts.end()));
                        }
                    } while (next_permutation(square_pts.begin(), square_pts.end()));
                }

    na;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}