#include<iostream>
using namespace std;
#define MAX 100
class Stack
{
        private:
                int top;
                char arr[MAX];
        public:
                Stack()
                {
                        top=-1;
                }
                void push(char x)
                {
                        if(top>=MAX-1)
                        {
                                cout<<x<<" cannot be Pushed as Stack is Full"<<endl;
                                return;
                        }
                        else
                        {
                                arr[++top]=x;
                        }
                }
                char pop()
                {
                        if(top<0)
                        {
                                cout<<"Cannot be Popped as Stack is Empty"<<endl;
                                return 0;
                        }
                        else
                                return arr[top--];
                }
                int peek()
                {
                        if(top<0)
                        {
                                cout<<"No Top as Stack is Empty"<<endl;
                                return 0;
                        }
                        else
                                return arr[top];
                }
                bool isFull()
                {
                        if(top==MAX-1)
                                return true;
                        else
                                return false;
                }
                bool isEmpty()
                {
                        if(top<0)
                                return true;
                        else
                                return false;
                }
};

int main()
{
    char a[100];
    cout << "Enter the expression:" << endl;
    cin >> a;
    Stack s;
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            s.push(a[i]);
        }
        else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            if ((s.peek() == '(' && a[i] == ')') || (s.peek() == '{' && a[i] == '}') || (s.peek() == '[' && a[i] == ']'))
            {
                s.pop();
            }
            else
            {
                cout << "Parentheses Matching Failed" << endl;
                return 0;
            }
        }
        i++;
    }

    if (s.isEmpty())
        cout << "Parentheses Matching is Successful" << endl;
    else
        cout << "Parentheses Matching Failed" << endl;

    return 0;
}

