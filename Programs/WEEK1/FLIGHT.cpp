#include<iostream>
using namespace std;
class flight
{
        int flight_no;
        char destination[20];
        float fuel=13.2,fu;
        float distance;
        float calculate_fuel(float dist)
        {
                if(distance<=1000)
                        fuel=500;
                else if(distance>1000 && distance<=2000)
                        fuel=1100;
                else if(distance>2000)
                        fuel=2200;
                return fuel;
        }
        public:
        void information_entry()
        {
                cout<<"Enter Flight Number:"<<endl;
                cin>>flight_no;
                cout<<"Enter Destination"<<endl;
                cin>>destination;
                cout<<"Distance:"<<endl;
                cin>>distance;
                fu=calculate_fuel(distance);
        }
        void display_info()
        {
                cout<<"Your Flight Details are given below:";
                cout<<"\nFlight Number="<<flight_no;
                cout<<"\nDestination="<<destination;
                cout<<"\nDistance(in km)="<<distance;
                cout<<"\nFuel(in l)="<<fu;
        }
};
int main()
{
        flight f;
        f.information_entry();
        f.display_info();
        return 0;
}
