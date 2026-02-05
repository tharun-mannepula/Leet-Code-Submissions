class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else if (value >= mini) {
            st.push(value);
        } else {
            st.push(2LL * value - mini);  // encoded value
            mini = value;
        }
    }

    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < mini) {                  // encoded case
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long x = st.top();
        if (x >= mini) return (int)x;    // ✅ FIXED
        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};
