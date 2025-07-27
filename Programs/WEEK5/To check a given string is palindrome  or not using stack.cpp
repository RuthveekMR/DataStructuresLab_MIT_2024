#include<iostream>

using namespace std;

class Stack
{
    private:
            int top;
            char arr[100];
    public:
            Stack()
            {
                top=-1;
            }
            void push(char x)
            {
                if(top>=99)
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
    char a[100],b[100];
    cout<<"Enter string to check if it is a palindrome:"<<endl;
    cin>>a;
    Stack s;
    int i=0;
    while(a[i]!='\0')
    {
        s.push(a[i++]);
    }
    i=0;
    while(!s.isEmpty())
    {
        b[i++]=s.pop();
    }
    b[i]='\0';
    i=0;
    while(a[i]!='\0')
    {
        if(a[i]!=b[i])
        {
            cout<<a<<" is not a palindrome"<<endl;
            return 0;
        }
        i++;
    }
    cout<<a<<" is a palindrome"<<endl;
    return 0;
}
