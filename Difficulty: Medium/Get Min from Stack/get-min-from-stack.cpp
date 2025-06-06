class Solution {
  public:
    stack<int> st;
    int min_val;
    Solution() {
        // code here
        min_val = INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st.empty()){
            min_val = x;
            st.push(x);
        }
        else{
            if(x>min_val) st.push(x);
            
            else{
                st.push(2*x-min_val);
                min_val = x;
            }
        }
        
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        if(st.empty()) return ;
        
        int x= st.top();
        st.pop();
        if(x<min_val){
            min_val = (2*min_val)-(x);
            
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()) return -1;
        
        int x = st.top();
        if(x<min_val){
            return min_val;
        }
        else{
            return x;
        }
    }
        

    // Finds min_valimum element of Stack
    int getMin() {
        // code here
        if(st.empty()) return -1;
        return min_val;
    }
};