https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

Print the 1st negative no of each window size of k. If no negative no, then print 0 for that window.

------------------------------------------------------------------------------------------
BASIC STEPS:
INITIALISE POINTERS
WHILE(J<SIZE)

1.)DO THE CALCULATION
2.)If size of window less than k, then update j
3.)If size of window equal to K, then update the answer,and slide the window ahead.

-------------------------------------------------------------------------------------------

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
    int i=0;
    int j=0;
    deque<long long>dq;
    vector<long long>ans;
    while(j<N)
    {
        if(A[j]<0)
        dq.push_back(j);
        
        if(j-i+1<K)
        {
            j++;
        }
        else if(j-i+1==K)
        {
            if(dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                while(!dq.empty()&&dq.front()<j-K+1)
                {
                    dq.pop_front();
                }
                if(!dq.empty())
                {
                    ans.push_back(A[dq.front()]);
                }
                else
                ans.push_back(0);
            }
            j++;
            i++;
        }
    }
    return ans;
                                                 
 }