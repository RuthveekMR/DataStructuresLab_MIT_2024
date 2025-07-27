#include<iostream>
using namespace std;
#define MAX 2
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
                                cout<<"Pushed "<<x<<" into Stack"<<endl;
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
        Stack s;
        s.push('c');
        s.push('d');
        s.push('e');
        cout<<"Top element of Stack="<<s.peek()<<endl;
        cout<<"Checking isFull():\n";
        if(s.isFull())
                cout<<"Yes, Stack is Full"<<endl;
        else
                cout<<"No, Stack is not Full"<<endl;
        cout<<"Elements of Stack:\n";
        while(!s.isEmpty())
                cout<<s.pop()<<"\t";
        cout<<endl;
        return 0;
}
