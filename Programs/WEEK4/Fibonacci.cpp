#include<iostream>
using namespace std;
int fibonacci(int n)
{
        if(n==1)
                return 0;
        if(n==2)
                return 1;
        else
                return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
        int num,fib;
        cout<<"Enter number of terms:"<<endl;
        cin>>num;
        if(num>0)
        {
                cout<<"Fibonacci Series=";
                for(int i=1;i<=num;i++)
                {
                        fib=fibonacci(i);
                        cout<<fib<<"  ";
                }
        }
        else
                cout<<"Invalid Input";
        cout<<"\n";
        return 0;
}

