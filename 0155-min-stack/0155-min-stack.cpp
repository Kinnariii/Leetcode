class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        }
        else {
            if (value < mini) {
                long long encoding = 2LL * value - mini;
                st.push(encoding);
                mini = value;
            }
            else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            long long ele = st.top();
            st.pop();

            if (ele < mini) {
                mini = 2LL * mini - ele;
            }
        }
    }

    int top() {
        long long ele = st.top();

        if (ele < mini) {
            return (int)mini;
        }

        return (int)ele;
    }

    int getMin() {
        return (int)mini;
    }
};