#include<iostream>
using namespace std;
struct poly
{
        int coeff;
        int exp;
};
void getpoly(poly array[],int size)
{
        for(int i=1;i<=size;i++)
        {
                cout<<"Enter the coefficient and exponent of term "<<i<<", respectively:"<<endl;
                cin>>array[i].coeff>>array[i].exp;
        }
}
void displaypoly(poly array[],int size)
{
        for(int i=0;i<=size;i++)
        {
                cout<<array[i].coeff<<"\t"<<array[i].exp<<"\n";
        }
}
void addition(poly arr1[],int size1,poly arr2[], int size2)
{
        poly arr3[20];
        int i=1,j=1,k=1;
        while(i<=size1 && j<=size2)
        {
                if(arr1[i].exp>arr2[j].exp)
                {
                        arr3[k].exp=arr1[i].exp;
                        arr3[k].coeff=arr1[i].coeff;
                        i++;
                        k++;
                }
                else if(arr1[i].exp<arr2[j].exp)
                {
                        arr3[k].exp=arr2[j].exp;
                        arr3[k].coeff=arr2[j].coeff;
                        j++;
                        k++;
                }
                else if(arr1[i].exp==arr2[j].exp)
                {
                        arr3[k].exp=arr1[i].exp;
                        arr3[k].coeff=arr1[i].coeff+arr2[j].coeff;
                        i++;
                        j++;
                        k++;
                }
        }
        while(i<=size1)
        {
                arr3[k].exp=arr1[i].exp;
                arr3[k].coeff=arr1[i].coeff;
                k++;
                i++;
        }
        while(j<=size2)
        {
                arr3[k].exp=arr2[j].exp;
                arr3[k].coeff=arr2[j].coeff;
                j++;
                k++;
        }
        arr3[0].coeff=k-1;
        arr3[0].exp=0;
        cout<<"Result after addition of the 2 polynomials:"<<endl;
        for(int i=0;i<k;i++)
        {
                cout<<arr3[i].coeff<<"\t"<<arr3[i].exp<<"\n";
        }
}
int main()
{
        int x,y;
        cout<<"Enter the no of terms in polynomial 1 and 2, respectively"<<endl;
        cin>>x>>y;
        struct poly p1[x+1],p2[y+1];
        p1[0].coeff=x,p2[0].coeff=y;
        cout<<"Enter the details of Polynomial 1:"<<endl;
        getpoly(p1,x);
        cout<<"Enter the details of polynomial 2:"<<endl;
        getpoly(p2,y);
        cout<<"Polynomial 1:"<<endl;
        displaypoly(p1,x);
        cout<<"Polynomial 2:"<<endl;
        displaypoly(p2,y);
        addition(p1,x,p2,y);
        return 0;
}
