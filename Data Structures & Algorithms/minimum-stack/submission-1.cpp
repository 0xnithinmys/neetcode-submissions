class MinStack {
public:

stack<int> st;

stack<int> mst;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mst.push(val);
        }else{
            st.push(val);
            mst.push(min(val,mst.top()));
        }
        
    }
    
    void pop() {

        if(!st.empty()){
            st.pop();
            mst.pop();
        }
        
    }
    
    int top() {

        if(!st.empty()){
            return st.top();
        }

        return -1;
        
    }
    
    int getMin() {

        if(!mst.empty()){
            return mst.top();
        }

        return -1;
        
    }
};