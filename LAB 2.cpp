#include <bits/stdc++.h>
using namespace std;

class Stack{
    char arr[100000];
    int mx, topInd;

public:
    Stack()
    : mx(100000), topInd(-1) {}

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
