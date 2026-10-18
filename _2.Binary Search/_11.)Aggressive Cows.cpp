https://www.spoj.com/problems/AGGRCOW/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//sort(arr, arr + n, greater<int>()); 
//cout<<fixed<<setprecision(20)<<(double)(result)<<endl;



 
bool search(ll arr[],int mid,int c,int n)
{
           
    int prev=-1;
            
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            prev=arr[i];
            c--;
        }
        
                
        else if(i!=0)
        {
            if(abs(arr[i]-prev)>=mid)
            {
                c--;
                prev=arr[i];
                if(c==0)
                return true;
            }
        }
    }
    
    return false;
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll arr[1000001];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int start=1;
        int end=arr[n-1]-arr[0];    //VERY IMPORTANT STEP
        int ans=1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(search(arr,mid,c,n))
            {
                ans=mid;
                start=mid+1;
            }
            
            else
            end=mid-1;
        }
        cout<<ans<<endl;
        
    }
}

            