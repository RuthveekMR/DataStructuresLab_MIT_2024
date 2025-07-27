#include<iostream>
using namespace std;
class Stack
{
    int top;
    int arr[100];
    public:
            Stack()
            {
                top=-1;
            }
            void push(int x)
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
            int peek()
            {
                return arr[top];
            }
            int pop()
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
int length(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}
void post_eval(char a[])
{
    int n=length(a);
    Stack s;
    int x,y,z;
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&& a[i]<='9')
        {
            s.push(a[i]-'0');
        }
        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            y=s.pop();
            x=s.pop();
            switch(a[i])
            {
            case '+':
                z=x+y;
                break;
            case '-':
                z=x-y;
                break;
            case '*':
                z=x*y;
                break;
            case '/':
                z=x/y;
                break;
            }
            s.push(z);
        }
    }
    int result=s.pop();
    if(s.isEmpty())
        cout<<"Result="<<result<<endl;
    else
        cout<<"Invalid Postfix Expression"<<endl;
}
void pre_eval(char a[])
{
    int n=length(a);
    Stack t;
    int x,y,z;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>='0'&& a[i]<='9')
        {
            t.push(a[i]-'0');
        }
        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            x=t.pop();
            y=t.pop();
            switch(a[i])
            {
            case '+':
                z=x+y;
                break;
            case '-':
                z=x-y;
                break;
            case '*':
                z=x*y;
                break;
            case '/':
                z=x/y;
                break;
            }
            t.push(z);
        }
    }
    int result=t.pop();
    if(t.isEmpty())
        cout<<"Result="<<result<<endl;
    else
        cout<<"Invalid Prefix Expression"<<endl;
}
int main()
{
    char a[50],b[50];
    cout<<"Enter Postfix Expression:"<<endl;
    cin.getline(a,50,'$');
    post_eval(a);
    cout<<"Enter Prefix Expression:"<<endl;
    cin.getline(b,50,'$');
    pre_eval(b);
    return 0;
}
