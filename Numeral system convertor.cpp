#include "iostream"
#include "cmath"

using namespace std;

int main()
{
    long int N,n;
    int G,b,Num=0;
    
    cout << "Please enter your number => ";
    cin >> N;
    cout << "Please enter the scale of notation => ";
    cin >> G;
    
    n=N;
    
    // Проверка соответствия введённых чисел их системе счисления
    
    while (N>0)
    {
        b=N%10;
        
        if ((0 <= b) && (b < G)){
            N=N/10;
        }
        else {
            cout << "\nPlease enter correct number for your scale of notation!\n\n";
            exit(0);
        }
    }
    
    // Перевод в десятичную систему счисления
    
    for (int j=0; n>0; j++) {
        Num+=n%10*pow(G,j);
        n/=10;
    }
    
    // Перевод из десятичной в 'P' систему счисления
    
    int P;
    long int rez=0;
    
    cout << "\nPlease enter the system to convert into => ";
    cin >> P;
    
    for (int d=0; Num>0; d++) {
        rez += Num%P*pow(10, d);
        Num/=P;
    }
    
    cout << rez << " <= your number in " << P << "x system" <<'\n'<<endl;
    
    return 0;
}
