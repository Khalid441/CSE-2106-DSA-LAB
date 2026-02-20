/*

**Problem Statement:**
You are given a single-line string that contains normal text mixed with arithmetic expressions. 
Each arithmetic expression is written in infix notation and is enclosed inside curly braces `{ }`.

**Your task is to:**
1. Extract all infix expressions enclosed inside `{ }`.  
2. Convert each extracted infix expression into prefix notation using a stack-based algorithm. Use separate functions for each operation.  
3. Display:  
   - The total number of expressions found  
   - The extracted infix expressions  
   - Their corresponding prefix expressions  

---

**Input Example:**
```
Compute {A+B*C} and then evaluate {(X+Y)*(P-Q)} before printing {K/L-M}.
```

**Output Example:**
- Total Expressions Found: 3  
- Extracted Infix Expressions:  
  1. A+B*C  
  2. (X+Y)*(P-Q)  
  3. K/L-M  

- Corresponding Prefix Expressions:  
  1. +A*BC  
  2. *+XY-PQ  
  3. -/KLM  

---
*/



#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
public:
    int top;
    T a[10000];
    Stack()
    {
        top=-1;
    }
    bool emp()
    {
        return top==-1;
    }
    void push(T v)
    {
        a[++top]=v;
    }
    T pop()
    {
        return a[top--];
    }
    T top_val()
    {
        return a[top];
    }
};
int priority(char x)
{

    if(x=='^')
        return 3;
    if(x=='*'||x=='/')
        return 2;
    if(x=='+'|| x=='-')
        return 1;
    else
        return 0;

}
string infixtopostfix(string infix)
{
    Stack<char>st;
    string postfix="";
    for(int i=0; i<infix.size(); i++)
    {
        if(isalnum(infix[i]))
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='(')
        {
            st.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!st.emp()&& st.top_val()!='(')

                postfix+=st.pop();
                st.pop();
        }
        else
        {
            while(!st.emp()&&priority(st.top_val())>=priority(infix[i]))
                postfix+=st.pop();
            st.push(infix[i]);
        }
    }
    while(!st.emp())
    {
        postfix+=st.pop();
    }
    return postfix;
}
string infixtoprefix(string infix)
{
    reverse(infix.begin(),infix.end());
    for(int i=0; i<infix.size(); i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    string postfix=infixtopostfix(infix);
    reverse(postfix.begin(),postfix.end());
    return postfix;
}

int main()

{
    string infix;
    getline(cin,infix);
    int flag=0;
    int cnt=0;
    string es="";
    for(int i=0; i<infix.size(); i++)
    {
        if(infix[i]=='{')
        {
            flag=1;
            cnt++;
            continue;
        }
        if(flag)
        {
            if(infix[i]=='}')
            { cout<<cnt<<endl<<"Extracted -> "<<es<<endl;
                string prefix=infixtoprefix(es);
                cout<<"Prefix -> "<<prefix<<endl<<endl;
                flag=0;
                es="";
                continue;
            }
            es+=infix[i];
        }
    }
    cout<<"Total Count : "<<cnt<<endl;


}
