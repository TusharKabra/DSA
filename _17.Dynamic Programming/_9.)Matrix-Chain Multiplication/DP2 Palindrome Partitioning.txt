Given a string, a partitioning of the string is a palindrome partitioning if every substring 
of the partition is a palindrome.
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, 
minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. 
If a string is a palindrome, then minimum 0 cuts are needed.
If a string of length n containing all different characters, then minimum n-1 cuts are needed. 


//Recursion
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

//initial value of i=0 and j=n-1. We can begin from i=0 unlike MCM 
//where we had to use i-1 and then the index would have become negative

int minPalPartion(string String, int i, int j)
{
    if( i >= j || isPalindrome(String, i, j) )    //since string with 1 character also pallindrome so equality
      return 0;   //partitioning not needed for pallindrome string
	  
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
      count = minPalPartion(String, i, k) +
        minPalPartion(String, k + 1, j) + 1;
  
      ans = min(ans, count);
    }
    return ans;
}