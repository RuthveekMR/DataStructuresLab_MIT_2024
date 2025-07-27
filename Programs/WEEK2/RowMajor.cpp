#include<iostream>
using namespace std;
int main()
{
        int m,n,k=0;
        cout<<"Enter the number of rows and columns of your 2-D matrix:"<<endl;
        cin>>m>>n;
        int a[m][n],b[m*n];
        cout<<"Enter the elements:"<<endl;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                                cin>>a[i][j];
                }
        }
        cout<<"The entered 2-D matrix:"<<endl;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<a[i][j]<<"\t";
                }
                cout<<"\n";
        }
        cout<<"The Row Major array of the entered matrix"<<endl;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        b[k]=a[i][j];
                        k++;
                }
        }
        for(int i=0;i<k;i++)
                cout<<b[i]<<"\t";
return 0;
}
