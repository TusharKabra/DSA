https://takeuforward.org/data-structure/minimum-insertions-deletions-to-convert-string-dp-30/

We need to tell the minimum operations required to convert str1 to str2.


HINT:
The easiest way is to remove all the characters of str1 and then insert all the characters of str2. 
In this way, we will convert str1 to str2 with ‘n+m’ operations. 
(Here n and m are the length of strings str1 and str2 respectively). 


Instead of removing all char, keep the LCS as it is. Let LCS length=k.
then 
No. of deletions saved=k
No. of insertions saved=k

Ans is thus n+m-2k;