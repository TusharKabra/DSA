https://codeforces.com/contest/1526/problem/C2 

You start with 0 health and you will walk from left to right, 
from first potion to the last one. At each potion, you may 
choose to drink it or ignore it. You must ensure that your 
health is always non-negative.

What is the largest number of potions you can drink?

Example
input
6
4 -4 1 -3 1 -3

output
5
Note
For the sample, you can drink 5 potions by taking potions 1, 3, 4, 5 and 6. 
It is not possible to drink all 6 potions because your health will go negative 
at some point
------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	long long S = 0;
	
	for(int i = 1;i <= n;i++){
		long long x; cin >> x;
		S += x;
		pq.push(x);
		
		while(S < 0){
			S -= pq.top();
			pq.pop();
		}
	}
	
	cout << (int) pq.size();
}