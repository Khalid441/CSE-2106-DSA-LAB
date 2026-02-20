/*Problem Statement : Write a function that determines if a string containing the characters '(', ')', '{', '}', '[' and ']' is valid.
A string is considered valid if every opening bracket has a corresponding closing bracket of the same type
 and if they are closed in the correct order (i.e., the most recently opened bracket must be closed first).

Examples:
- "()" → true
- "(){}[]" → true
- "(]" → false
- "([)]" → false
- "{[]}" → true
*/

#include <bits/stdc++.h>
using namespace std;

class Stack{
    char arr[1000];
    int mx, topInd;

public:
    Stack()
    : mx(1000), topInd(-1) {}

    void push(char val) {
        if(topInd == mx - 1) {
            return;
        }

        arr[++topInd] = val;
    }

    void pop() {
        if(isEmpty()) {
            return;
        }

        -- topInd;
    }

    char top() {
        if(isEmpty()) {
            return '\0';
        }

        return arr[topInd];
    }

    bool isEmpty() {
        return (topInd == -1);
    }
};

int main() {
    string s;

    while(cin >> s) {
        Stack stc;
        bool ans = true;
        for(auto& ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                stc.push(ch);
            }
            else {
                if(stc.isEmpty()) {
                    ans = false;
                    break;
                }

                char last = stc.top();

                if(last == '(' && ch == ')') {
                    stc.pop();
                    continue;
                }

                if(last == '{' && ch == '}') {
                    stc.pop();
                    continue;
                }

                if(last == '[' && ch == ']') {
                    stc.pop();
                    continue;
                }

                ans = false;
                break;
            }
        }

        if(!stc.isEmpty()) {
            ans = false;
        }

        cout << (ans ? "true\n" : "false\n");
    }
}
