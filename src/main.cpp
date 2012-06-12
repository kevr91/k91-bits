/* by Kevin Morris, calculates bit representations */
// C++ Program

#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long LBYTE;

// 2-bit sequence table for binary conversions
const LBYTE ul_bit_seq[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

// Make sure the binary string passed contains ONLY 1's and 0's
LBYTE get_decimal(string binary)
{
    LBYTE ldecimal = 0;
    for(int i = 7, x = 0; i >= 0; i--, x++)
    {
        if(binary[x] == '1')
            ldecimal = ldecimal + ul_bit_seq[i];
    }
    return ldecimal;
}

string get_binary(LBYTE in_decimal)
{
    string str_binary;
    for(int i = 7; i >= 0; i--)
    {
        //LBYTE leftover = in_decimal % ul_bit_seq[i];
        if((in_decimal / ul_bit_seq[i]) >= 1)
        {
            in_decimal = in_decimal - ul_bit_seq[i];
            str_binary = str_binary + "1";
        }
        else
            str_binary = str_binary + "0";
    }
    return str_binary;
}

void put_usage(const char *program_name)
{
    cout << "Usage: " << program_name << " <character>\n";
    cout << "(eg. `" << program_name << " A`)\n";
}

int main(int argc, char *argv[])
{
    cout << "k91-bits Bit Converter\n";
    cout << "Converts alpha characters to hex, decimal, and binary\n\n";

    if(argc < 2 || argc > 2)
    {
        put_usage(argv[0]);
        return 1;
    }
    else if(strlen(argv[1]) > 1)
    {
        put_usage(argv[0]);
        return 1;
    }
    LBYTE n_byte = argv[1][0];
    cout << "Alpha: " << char(n_byte) << '\n';

    cout.setf(ios::hex, ios::basefield);
    cout << "Hexadecimal: " << n_byte << '\n';
    cout.setf(ios::dec, ios::basefield);
    cout << "Decimal number: " << n_byte << '\n'; 
    cout << "Binary sequence: " << get_binary(n_byte) << '\n';

    cout << "Binary converted back to decimal (test): " << get_decimal(get_binary(n_byte)) << '\n';
    return 0;
}
