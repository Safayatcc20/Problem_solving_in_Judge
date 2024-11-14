/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define INT_SIZE 32
long long t = 1;
struct Node
{
	int value; 
	Node *arr[2];
};

Node *newNode()
{
	Node *temp = new Node;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(Node *root, int pre_xor)
{
	Node *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		bool val = pre_xor & (1<<i);
		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}
	temp->value = pre_xor;
}

int query(Node *root, int pre_xor)
{
	Node *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		bool val = pre_xor & (1<<i);

		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre_xor^(temp->value);
}

int maxXOR(vector<int>&arr, int n)
{
	Node *root = newNode();
	insert(root, 0);
	int result = INT_MIN, pre_xor =0;

	for (int i=0; i<n; i++)
	{
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);

		result = max(result, query(root, pre_xor));
	}
	return result;
}
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    int ans = 0, chk = v[0];
    cout << maxXOR(v , n) << sad;
}
int main()
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