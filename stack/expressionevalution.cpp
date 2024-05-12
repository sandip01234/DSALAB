#include <iostream>
#include <stack>
#include <cmath> 

using namespace std;

int postfixEvaluation(string s) {
    stack<int> st; // Use a stack of ints to hold integers
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') { // Correct range for digits
            st.push(s[i] - '0'); // Convert char digit to int
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            switch (s[i]) {
                case '+': 
                st.push(op1 + op2);
                 break;
                case '-':
                 st.push(op1 - op2);
                  break;
                case '*':
                 st.push(op1 * op2); 
                 break;
                case '/': 
                st.push(op1 / op2);
                 break;
                case '^': // Correctly handle the power operation
                    st.push(pow(op1, op2)); break;
                default: // Handle unexpected characters
                    cout << "Unexpected character encountered: " << s[i] << endl;
                    return -1; // Return an error code or handle error appropriately
            }
        }
    }
    if (!st.empty()) {
        return st.top();
    } else {
        cout << "Error: Stack is empty after evaluation." << endl;
        return -1; // Error condition
    }
}

int main() {
    cout << postfixEvaluation("46+2/5*7+") << endl; // A correct postfix expression example
    return 0;
}
