#include<iostream>
using namespace std;
int main()
{
        int n;
        cout<<"Enter the order of your diagonal matrix:\n";
        cin>>n;
        int a[n],b[n][n],i,j,index;
        cout<<"Enter "<<n<<" diagonal elements:\n";
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(i==j)
                                cin>>b[i][j];
                        else
                                b[i][j]=0;
                }
        }
        cout<<"\nThe entered 2D matrix:\n";
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<b[i][j]<<"\t";
                }
                cout<<"\n";
        }
        cout<<"The mapped 1D list:"<<endl;
        for(int i=0;i<n;i++)
        {
                a[i]=b[i][i];
                cout<<a[i]<<"\t";
        }
        cout<<"\nEnter the row and column for retrieval:"<<endl;
        cin>>i>>j;
        if(i==j)
                cout<<"Located at index "<<i<<" in the 1-D array.";
        else
                cout<<"Invalid Input";
        return 0;
}
