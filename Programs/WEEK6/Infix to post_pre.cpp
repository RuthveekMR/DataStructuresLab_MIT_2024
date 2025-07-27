#include <iostream>
using namespace std;
int flag=0;
class Stack
{
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
            char peek()
            {
                return arr[top];
            }
            void pop()
            {
                if(top<0)
                {
                    cout<<"Cannot be Popped as Stack is Empty"<<endl;
                }
                else
                    arr[top--];
            }
            bool isEmpty()
            {
                if(top<0)
                    return true;
                else
                    return false;
            }
};
int prec(char z)
{
        if (z == '/' || z == '*')
                return 2;
        else if (z == '-' || z == '+')
                return 1;
        else
                return 0;
}
void postfix(char arr[], int x)
{
        class Stack s;
        char post[100];
        int index = 0;
        for (int i = 0; i < x; i++)
        {
                if (arr[i] == '(')
                {
                        s.push(arr[i]);
                }
                else if (arr[i] == '/' || arr[i] == '*' || arr[i] == '+' || arr[i] == '-')
                {
                        while (prec(arr[i]) <= prec(s.peek()))
                        {
                                post[index++] = s.peek();
                                s.pop();
                        }
                        s.push(arr[i]);
                }
                else if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9'))
                {
                        post[index++] = arr[i];
                }
                else if (arr[i] == ')')
                {
                        while (s.peek() != '(')
                        {
                                post[index++] = s.peek();
                                s.pop();
                        }
                        s.pop();
                }
        }
        while (!s.isEmpty())
        {
                post[index++] = s.peek();
                s.pop();
        }
        char pre1[100];
        int i=0;
        if(flag==1)
        {
            x=index;
            while(index!=0)
            {
                pre1[i++]=post[--index];
            }
            for(int i=0;i<x;i++)
                post[i]=pre1[i];
            index=i;
        }
        post[index] = '\0';
        cout<<post<< '\n';
        flag=1;
}

void prefix(char arr[], int x)
{
        char pre[100];
        int i=0;
        while(x!=0)
        {
            x--;
            if(arr[x]==')')
            {
                pre[i++]='(';
            }
            else if(arr[x]=='(')
            {
                pre[i++]=')';
            }
            else
                pre[i++]=arr[x];
        }
        pre[i]='\0';
        postfix(pre,i);
}


int main()
{
        char infix[100];
        int i = 0;
        cout << "Enter an infix expression:" << endl;
        cin >> infix;
        while (infix[i] != '\0')
        {
                i++;
        }
        cout<<"Postfix Expression:";
        postfix(infix, i);
        cout<<"Prefix Expression:";
        prefix(infix,i);
        return 0;
}
