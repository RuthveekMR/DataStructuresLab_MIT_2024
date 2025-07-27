#include<iostream>
using namespace std;
int factorial(int number)
{
        if(number==0||number==1)
                return 1;
        else
                return number*factorial(number-1);
}
int main()
{
        int n,fact;
        cout<<"Enter number:"<<endl;
        cin>>n;
        if(n>=0)
        {
                fact=factorial(n);
                cout<<"Factorial of "<<n<<" = "<<fact<<endl;
        }
        else
                cout<<"Invalid Input"<<endl;
        return 0;
}
