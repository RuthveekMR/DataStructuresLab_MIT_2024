#include<iostream>
using namespace std;
int GCD(int num1, int num2)
{
        if(num1==0)
                return num2;
        else if(num2==0)
                return num1;
        else
                return GCD(num2,num1%num2);
}
int main()
{
        int n1,n2,gcd,temp;
        cout<<"Enter two positive integers to find its GCD:"<<endl;
        cin>>n1>>n2;
        if(n1<n2)
        {
                temp=n1;
                n1=n2;
                n2=temp;
        }
        gcd=GCD(n1,n2);
        cout<<"GCD of "<<n1<<" and "<<n2<<" = "<<gcd<<endl;
        return 0;
}
