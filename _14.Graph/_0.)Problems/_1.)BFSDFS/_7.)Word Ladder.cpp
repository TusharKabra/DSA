https://leetcode.com/problems/word-ladder/solution/


class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        
        unordered_set<string>st;   //SET GIVES TLE
        for(int i=0;i<wordList.size();i++)
        {
            st.insert(wordList[i]);
        }
        queue<string>q;
        q.push(beginWord);
        int count=1;
        // COUNT NUMBER OF WORDS TRANSFORMED
        while(!q.empty())
        {
            
            int size=q.size();
            
            // FOR ALL WORDS THIS ROUND
            for(int i=0;i<size;i++)
            {
                string x=q.front();
                st.erase(x);
                q.pop();
                
                // TRAVERSE CURRENT WORD
                for(int j=0;j<x.length();j++)
                {
                    char tmp=x[j];
                    
                    // CHANGE ONE LETTER AT A TIME 
                    for(char c='a';c<='z';c++)
                    {
                        x[j]=c;
                        
                        // WHEN NEXT WORD IS IN THE SET
                        if(st.find(x)!=st.end())
                        {
                            q.push(x);
                            
                            if(x==endWord)
                                return count+1;
                        }
                    }
                    
                    // HAVE TO UNDO FOR NEXT CHANGE OF LETTER
                    x[j]=tmp;
                }
            }
            // THIS ROUND ENDS WITH ONE LETTER CHANGED
            count++;
        }
        //THERE IS NO POSSIBLE WAY TO CONVERT SO RETURN 0
        return 0;
        
        
    }
};