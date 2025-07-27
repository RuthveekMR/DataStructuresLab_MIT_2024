#include<iostream>
using namespace std;
class employee
{
        int emp_no;
        char emp_name[20];
        float basic;
        float DA;
        float IT;
        float net_sal;
        float gross_salary;
        public:
        void read()
        {
                cout<<"Enter your Employee number:"<<endl;
                cin>>emp_no;
                cout<<"Enter your Name:"<<endl;
                cin>>emp_name;
                fflush(stdin);
                cout<<"Enter you Basic Salary:"<<endl;
                cin>>basic;
        }
        void compute()
        {
                DA=(12*basic)/100;
                gross_salary=DA+basic;
                IT=(18*gross_salary)/100;
                net_sal=gross_salary-IT;
        }
       void display()
        {
                cout<<"DA="<<DA<<endl;
                cout<<"Gross Salary="<<gross_salary<<endl;
                cout<<"IT="<<IT<<endl;
                cout<<"Net Salary="<<net_sal<<endl;
        }
};
int main()
{
        employee e1[10];
        int i,n;
        cout<<"Enter the number of employees:";
        cin>>n;
        for (i=1;i<=n;i++)
        {
                e1[i].read();
                e1[i].compute();
                e1[i].display();
        }
        return 0;
}
