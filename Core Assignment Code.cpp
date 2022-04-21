#include <iostream>

using namespace std;

class base{
    public:
    int value;

    base(int val){
        value = val;
    }

    base operator*(base B){
        return base(B.value * value);
    }

    base operator+(base B){
        return base(B.value + value);
    }

    base operator-(base B){
        return base(B.value - value );
    }

    int val(char c)
    {
        if (c >= '0' && c <= '9')
            return (int)c - '0';
        else
            return (int)c - 'A' + 10;
    }
    
    // Function to convert a number from given base 'b'
    // to decimal
    int toDeci(char *str, int base)
    {
        int len = strlen(str);
        int power = 1; // Initialize power of base
        int num = 0;  // Initialize result
        int i;
    
        // Decimal equivalent is str[len-1]*1 +
        // str[len-2]*base + str[len-3]*(base^2) + ...
        for (i = len - 1; i >= 0; i--)
        {
            // A digit in input number must be
            // less than number's base
            if (val(str[i]) >= base)
            {
            printf("Invalid Number");
            return -1;
            }
    
            num += val(str[i]) * power;
            power = power * base;
        }
    
        return num;
    }

        char reVal(int num)
    {
        if (num >= 0 && num <= 9)
            return (char)(num + '0');
        else
            return (char)(num - 10 + 'A');
    }
    
    // Utility function to reverse a string
    void strev(char *str)
    {
        int len = strlen(str);
        int i;
        for (i = 0; i < len/2; i++)
        {
            char temp = str[i];
            str[i] = str[len-i-1];
            str[len-i-1] = temp;
        }
    }
    
    // Function to convert a given decimal number
    // to a base 'base' and
    char* fromDeci(char res[], int base, int inputNum)
    {
        int index = 0;  // Initialize index of result
    
        // Convert input number is given base by repeatedly
        // dividing it by base and taking remainder
        while (inputNum > 0)
        {
            res[index++] = reVal(inputNum % base);
            inputNum /= base;
        }
        res[index] = '\0';
    
        // Reverse the result
        strev(res);
    
        return res;
    }

};

class binary  : public base{
    
    binary(int val) : base (val) {

    };

    
    void setValue (string val){
        value = stoi(val, 0, 2)
    };

    string getValue (){
        return 
    }


};

int main(){
    
    base a = base(5); //101
    base b = base(6); //110
    base c = a * b; //111 -> 7
    cout << (int)c.value << endl;
    return 0;
}
