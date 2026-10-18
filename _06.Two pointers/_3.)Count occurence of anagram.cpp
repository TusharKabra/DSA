https://www.geeksforgeeks.org/count-occurrences-of-anagrams/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:


	int search(string pat, string txt) 
	{
	    int w=pat.size();
	    int n=txt.size();
	    int c=0;
	    vector<int>text(30,0);
	    vector<int>word(30,0);
	    
	    //Iterating over the word length
	    int i;
	    for(i=0;i<w;i++)
	    {
	        text[txt[i]-'a']++;
	        word[pat[i]-'a']++;
	    }
	    if(word==text)
	    c++;
	    
	    while(i<n)
	    {
	        text[txt[i-w]-'a']--;
	        text[txt[i]-'a']++;
	        if(word==text)
	        c++;
	        
	        i++;
	    }
	    return c;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends