#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long int A,B,q1,r,d;
    long int a,b,c,a1,b1,R,q[50],P[50],i=0,j=0,con,x;
    
    // Ax + By = C
    
    cout<<"Please enter A: ";
    cin>>a;
    cout<<"Please enter B: ";
    cin>>b;
    cout <<"Please enter C: ";
    cin>>c;
    
    if (a<0) {
        a=-1*a;
        b=-1*b;
        c=-1*c;
    }
    
    A = a;
    B = b;
    
    // 1-st euclidean algorythm
    
    if (A!=0 && B!=0)
    {
        while (B!=0)
        {
            q1=A/B;
            r=A-q1*B;
            A=B;
            B=r;
        }
        
        d=abs(A);
        
        // Checking the equation for divisibiloity
        
        if (d!=1) {
            
            if (c%d==0) {
                a=a/d;
                b=b/d;
                c=c/d;
            }
            
            else {
                cout << "\nThe equation has no solutions!\n"<<endl;
                exit(0);
            }
            
        }
        
    }
    
    else {
        cout << "\nPlease enter A!=0 or B!=0 values!\n" << endl;
        exit(0);
    }
    
    // Searching for solutions
    
    a1=a;
    b1=b;

    // 2-nd euclidean algorythm
    
    a=abs(a);
    b=abs(b);
    
    while (b%a!=0) {
        R=b%a;
        q[i]=(b-R)/a;
        b=a;
        a=R;
        i++;
    }
    
    con=i;
    
    P[0]=0;
    P[1]=1;
    i=0;
    
    for (j=2; j-2<=con; j++) {
        P[j]=P[j-1]*q[i]+P[j-2];
        i++;
    }
    
    x=P[j-2]*pow(-1, con)*c;
    
    // Printing general solution
    
    if (b1<0) {
        cout << "\nX = "<<x<<b1<<"t"<<endl;
        cout << "Y = "<<(c-a1*x)/b1<<"-"<<a1<<"t"<<endl<<'\n';
    }
    
    else {
        cout << "\nX = "<<x<<"+"<<b1<<"t"<<endl;
        cout << "Y = "<<(c-a1*x)/b1<<"-"<<a1<<"t"<<endl<<'\n';
    }
    
    return 0;
}
