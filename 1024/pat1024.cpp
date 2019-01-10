#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int str2int(string s);
int main(int argc, char const *argv[])
{
    string str;
    int pos_E , num_pow, dec_length;
    cin >> str;
    pos_E = str.find('E');
    string str_int = str.substr(1,pos_E-1);
    dec_length = pos_E - str.find('.') - 1;
    str_int = str_int.erase(str_int.find("."),1);
    string str_pow = str.substr(pos_E+2);
    num_pow = str2int(str_pow);

    if (str.at(pos_E+1) == '-')
    {

        while (num_pow > 1)
        {
            str_int = "0" + str_int;
            num_pow--;
        }   

        str_int = "0." + str_int;
    }
    else
    {
        int sub = num_pow - dec_length;
        if (sub >= 0)
        {
            string a(sub,'0');
            str_int = str_int + a;
        }
        else
        {
            int length_int = str_int.length();
            
            str_int.insert(str_int.begin()+length_int+sub,'.');
        }
    }
    if (str.at(0) == '-')
        str_int = '-' + str_int; 
    cout << str_int << endl;
    
    return 0;
}

int str2int(string s)
{
    int sum = 0;
    for (unsigned int i = 0; i < s.length(); i++)
        sum = sum*10 + s.at(i) - '0';
    return sum;
}