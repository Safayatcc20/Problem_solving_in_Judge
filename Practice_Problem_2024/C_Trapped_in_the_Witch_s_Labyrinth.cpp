 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
// Directions - up, down, left, right
const int DX[] = {-1, 1, 0, 0}; // U, D, L, R
const int DY[] = {0, 0, -1, 1}; // U, D, L, R
const char DIRS[] = {'U', 'D', 'L', 'R'};

bool inBounds(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, vector<string> &maze, vector<vector<int>> &visited, vector<vector<bool>> &trapped, int n, int m)
{
    vector<pair<int, int>> path;
    vector<pair<int, int>> stack = {{x, y}};

    while (!stack.empty())
    {
        int cx = stack.back().first;
        int cy = stack.back().second;
        stack.pop_back();

        if (visited[cx][cy] == 1)
        {
            bool is_cycle_trapped = true;
            while (!path.empty())
            {
                int px = path.back().first;
                int py = path.back().second;

                if ((px == 0 && maze[px][py] == 'U') ||
                    (py == 0 && maze[px][py] == 'L') ||
                    (py == m - 1 && maze[px][py] == 'R') ||
                    (px == n - 1 && maze[px][py] == 'D'))
                {
                    is_cycle_trapped = false;
                }

                if (is_cycle_trapped && trapped[px][py] == false)
                {
                    // cout <<px << " "<< py << " "<< x << " "<< y << endl;
                    trapped[px][py] = true;
                }

                path.pop_back();
            }
            return true;
        }

        if (visited[cx][cy] == 2)
        {
            continue;
        }

        visited[cx][cy] = 1;
        path.push_back({cx, cy});

        char dir = maze[cx][cy];

        if (dir == '?')
        {
            for (int i = 0; i < 4; ++i)
            {
                int nx = cx + DX[i];
                int ny = cy + DY[i];
                if (inBounds(nx, ny, n, m))
                {
                    if ((nx == 0 && maze[nx][ny] == 'U') ||
                    (ny == 0 && maze[nx][ny] == 'L') ||
                    (ny == m - 1 && maze[nx][ny] == 'R') ||
                    (nx == n - 1 && maze[nx][ny] == 'D'))
                {
                    continue;
                }
                    stack.push_back({nx, ny});
                }
            }
        }
        else
        {
            int nx = cx + DX[find(DIRS, DIRS + 4, dir) - DIRS];
            int ny = cy + DY[find(DIRS, DIRS + 4, dir) - DIRS];
            if (inBounds(nx, ny, n, m))
            {
                stack.push_back({nx, ny});
            }
        }
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));       // 0 = unvisited, 1 = visiting, 2 = processed
    vector<vector<bool>> trapped(n, vector<bool>(m, false)); // Keep track of trapped cells
    int trapped_cells = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] == 0)
            {
                if (dfs(i, j, maze, visited, trapped, n, m))
                {
                    trapped_cells++;
                    // cout << i << " "<< j << endl;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (trapped[i][j])
            {
                ans++;
                //cout << i << " "<< j << endl;
            }
        }
    }

    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}