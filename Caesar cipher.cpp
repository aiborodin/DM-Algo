#include <iostream>
using namespace std;

const int ABCSize = 26;

const char low_ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char high_ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string cipher(string input_s,int shift);

int main() {
    
    string input_s;
    int shift;
    
    cout << "If you want to cipher - press '1'\nIf you want to decipher - press '2'\nIf you want to exit - press enter\n";
    
    char a = cin.get();
    
    switch (a) {
            
        case '1': {
            
            cout << "\nPlease enter your string => ";
            cin.ignore();
            getline(cin,input_s);
            
            cout << "Please enter shift => ";
            cin >> shift;
            
            string output_s("");
            
            for (unsigned i = 0; i < input_s.length(); i++)
            {
                
                for(int j = 0; j < ABCSize; j++)
                {
                    if (input_s[i] == low_ch[j])
                    {
                        j += shift;
                        while (j >= ABCSize) j -= ABCSize;
                        while (j < 0) j += ABCSize;
                        output_s += low_ch[j];
                        break;
                    }
                    else if (input_s[i] == high_ch[j])
                    {
                        j += shift;
                        while (j >= ABCSize) j -= ABCSize;
                        while (j < 0) j += ABCSize;
                        output_s += high_ch[j];
                        break;
                    }
                }
            }
            cout << output_s;
            
            break;
        }
            
        case '2': {
            
            cout << "\nPlease enter your string => ";
            cin.ignore();
            getline(cin,input_s);
            
            for (int shift = 1; shift < ABCSize; shift++) {
                
                string output_s("");
                
                for (unsigned i = 0; i < input_s.length(); i++)
                {
                    
                    for(int j = 0; j < ABCSize; j++)
                    {
                        if (input_s[i] == low_ch[j])
                        {
                            j += shift;
                            while (j >= ABCSize) j -= ABCSize;
                            while (j < 0) j += ABCSize;
                            output_s += low_ch[j];
                            break;
                        }
                        else if (input_s[i] == high_ch[j])
                        {
                            j += shift;
                            while (j >= ABCSize) j -= ABCSize;
                            while (j < 0) j += ABCSize;
                            output_s += high_ch[j];
                            break;
                        }
                    }
                }
                cout << output_s;
                
                cout << "\nIf decoding is done - press '1', to continue - press enter\n";
                
                char b = cin.get();
                
                switch (b) {
                    case '1': {
                        exit(0);
                        break; }
                        
                    default: continue;
                        break;
                }
            }
        }
            
        default: exit(0);
            break;
    }
    
    cout << '\n';
    
    return 0;
}
