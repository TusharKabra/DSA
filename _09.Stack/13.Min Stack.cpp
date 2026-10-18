 
https://leetcode.com/problems/min-stack/


Basically Use {value, min value till that time} as a pair

class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(st.empty())
            st.push({val,val});
        else
            st.push({val,min(val,st.top().second)});
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
    }
};


};
==================================================================================