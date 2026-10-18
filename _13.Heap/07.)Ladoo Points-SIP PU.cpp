https://www.hackerrank.com/contests/sip-prep-1/challenges/laddoo-points/problem
 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
//sort(arr, arr + n, greater<int>()); 
//cout<<fixed<<setprecision(20)<<(double)(result)<<endl;
 
 
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll mod =((ll)(1e9)+7);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>ans(n,{0,0});
        
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            ans[i].first=x-1;
            
        }
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            ans[i].second=x;
            
        }
 
        sort(ans.begin(),ans.end()); //time,happ
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ans[i].first<<" "<<ans[i].second<<endl;
        // }
 
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;//happ,time
        ll timer=-1;
        ll happ=0;
        for(int i=0;i<n;i++)
        {
            pq.push({ans[i].second,ans[i].first});
            timer++;
            happ=(happ%mod+ans[i].second%mod)%mod;
            if(timer>ans[i].first)
            {
                ll x=pq.top().first;
                pq.pop();
                happ=happ-x;
                timer--;
                
            }
            
        }
        cout<<happ<<endl;
    }
}
 
        
        