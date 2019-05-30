#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,b,A,B,q,r;
    
    cout<<"Please input A: ";
    cin>>a;
    cout<<"Please input B: ";
    cin>>b;
    
    if (a!=0 && b!=0)
    {
        A=a;
        B=b;
        
        // a = b * q + r
        
        while (b!=0)
        {
            q=a/b;
            r=a-q*b;
            a=b;
            b=r;
        }
        
        cout << "\nLCD => " << a << endl;
        cout << "LCM => " << (A*B)/a << endl;
    }
    
    else cout << "\nPlease enter A!=0 or B!=0 values!" << endl;
    
    
    return 0;
}
