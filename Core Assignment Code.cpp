/*
Domonic Homphery 1207771
Richard Clarke 0904223
Tiffany Salmon   200261 
C++ End of course code 
Lect: Dr Chambers 
4/20/2022


*/



#include <iostream>

using namespace std;

class base{
    public:
    int value;

    base(int val){
        value = val;
    }

    base(){
        int value = 0; 
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

    long ConvertTo10(const string& input, int base)
    {
        if(base < 2 || base > 36)
            return 0;
        
        bool isNegative = (input[0] == '-');    

        int startIndex = input.length()-1;
        int endIndex   = isNegative ? 1 : 0;
        
        long value = 0;
        int digitValue = 1;
        
        for(int i = startIndex; i >= endIndex; --i)
        {
            char c = input[i];
            
            // Uppercase it - NOTE: could be done with std::toupper
            if(c >= 'a' && c <= 'z')
                c -= ('a' - 'A');
            
            // Convert char to int value - NOTE: could be done with std::atoi
            // 0-9
            if(c >= '0' && c <= '9')
                c -= '0';
            // A-Z
            else
                c = c - 'A' + 10;
            
            if(c >= base)
                return 0;
            
            // Get the base 10 value of this digit    
            value += c * digitValue;
            
            // Each digit has value base^digit position - NOTE: this avoids pow
            digitValue *= base;
        }
        
        if(isNegative)
            value *= -1;
        
        return value;
    }

    // Convert base 10 to arbitrary base
    // - Base must be between 2 and 36
    // - If base is invalid, returns "0"
    // - NOTE: this whole function could be done with itoa
    string ConvertFrom10(long value, int base)
    {
        if(base < 2 || base > 36)
            return "0";
        
        bool isNegative = (value < 0);
        if(isNegative)
            value *= -1;
        
        // NOTE: it's probably possible to reserve string based on value
        string output;
        
        do
        {
            char digit = value % base;
        
            // Convert to appropriate base character
            // 0-9
            if(digit < 10)
                digit += '0';
            // A-Z
            else
                digit = digit + 'A' - 10;
            
            // Append digit to string (in reverse order)
            output += digit;
            
            value /= base;
            
        } while (value > 0);
        
        if(isNegative)
            output += '-';
        
        // Reverse the string - NOTE: could be done with std::reverse
        int len = output.size() - 1;
        for(int i = 0; i < len; ++i)
        {
            // Swap characters - NOTE: Could be done with std::swap
            char temp = output[i];
            output[i] = output[len-i];
            output[len-i] = temp;
        }
        
        return output;

        
    }

    // Convert from one base to another
    string ConvertBase(const string& input, int baseFrom, int baseTo)
    {
        // NOTE: There is probably a more efficient way to convert between two bases.
        //       This however is easy to understand and debug.
        return ConvertFrom10(ConvertTo10(input, baseFrom), baseTo);
    }

    void setValue(string val, string mode){
        if (mode == "binary"){
            this->value =  stoi(ConvertBase(val, 2, 10));
        }
        else if (mode == "octal"){
            this->value =  stoi(ConvertBase(val, 8, 10));
        }
        else if (mode == "decimal"){
            this->value =  stoi(ConvertBase(val, 10, 10));
        }
        else if (mode == "hexadecimal"){
            this->value =  stoi(ConvertBase(val, 16, 10));
        }
    }

    string getValue(string mode){
        if (mode == "binary"){
            return ConvertBase(to_string(this->value), 10, 2);
        }
        else if (mode == "octal"){
            return ConvertBase(to_string(this->value), 10, 8);
        }
        else if (mode == "decimal"){
            return ConvertBase(to_string(this->value), 10, 10);
        }
        else if (mode == "hexadecimal"){
            return ConvertBase(to_string(this->value), 10, 16);
        }

        return "";
    }

};

class binary  : public base{
    
    public:
    binary(string val) {
        int num = stoi(ConvertBase(val, 2, 10));
        this->value = num;
    }

    binary(base val) {
        int num = val.value;
        this->value = num;
    }

    void setVal(string val){
        setValue(val, "binary");
    }

    string getVal(){
        return getValue("binary");
    }
    


};

class octal  : public base{
    
    public:
    octal(string val) {
        int num = stoi(ConvertBase(val, 8, 10));
        this->value = num;
    }

    octal(base val) {
        int num = val.value;
        this->value = num;
    }

    void setVal(string val){
        setValue(val, "octal");
    }

    string getVal(){
        return getValue("octal");
    }

};

class decimal  : public base{
    
    public:
    decimal(string val) {
        int num = stoi(ConvertBase(val, 10, 10));
        this->value = num;
    }

    decimal(base val) {
        int num = val.value;
        this->value = num;
    }

    void setVal(string val){
        setValue(val, "decimal");
    }

    string getVal(){
        return getValue("decimal");
    }

};

class hexadecimal  : public base{
    
    public:
    hexadecimal(string val) {
        int num = stoi(ConvertBase(val, 16, 10));
        this->value = num;
    }

    hexadecimal(base val) {
        int num = val.value;
        this->value = num;
    }

    void setVal(string val){
        setValue(val, "hexadecimal");
    }

    string getVal(){
        return getValue("hexadecimal");
    }

};

int main(){
    
    //binary a = binary("01"); //101
    //octal b = octal("4567"); //110
   // decimal c = decimal("6789");
   // hexadecimal d = hexadecimal("ef");
    
   // binary r = a + b;
    
    //binary c = a + b; //111 -> 7
   // cout << r.getVal() << endl;

   base numx, numy, numr;

    int operation;
   cout << "Please enter the correpsonding number for operation: \n  1 => addition \n 2 => multiplication \n 3 => subtraction" << endl;
   cin >> operation;
   while (operation < 1 || operation > 3){
       cin >> operation;
   }

    cout << "please enter two numbers of serperated by space of either type binary, octal, decimal, hexadacimal" << endl;
    cout << "to denote a base number put the prefrix first before value" << endl;
    cout << "binary : 0b ---> eg: 0b101001" << endl;
    cout << "octal : 0o ---> eg: 0o3627" << endl;
    cout << "decimal : 0d  ---> eg: 0d6789" << endl;
    cout << "binary : 0x ---> eg: 0xaf3c" << endl;
    string x , y = "";
    cin >> x >> y;

    int xlevel = 0, ylevel = 0;
    if (x.substr(0,2) == "0b"){
        xlevel = 1;
        numx = binary(x);
    }
    else if (x.substr(0,2) == "0o"){
        xlevel = 2;
        numx = octal(x);
    }
    else if (x.substr(0,2) == "0d"){
        xlevel = 3;
        numx = decimal(x);
    }
    else if (x.substr(0,2) == "0x"){
        xlevel = 4;
        numx = hexadecimal(x);
    }

    if (y.substr(0,2) == "0b"){
        ylevel = 1;
        numy = binary(y);
    }
    else if (y.substr(0,2) == "0o"){
        ylevel = 2;
        numy = octal(y);
    }
    else if (y.substr(0,2) == "0d"){
        ylevel = 3;
        numy = decimal(y);
    }
    else if (y.substr(0,2) == "0x"){
        ylevel = 4;
        numy = hexadecimal(y);
    }

    int rlevel;
    if (xlevel > ylevel){
        rlevel = xlevel;
    }
    else{
        rlevel = ylevel;
    }


    string lvl = "";
    if (rlevel == 1){
        lvl = "binary";
    }
    else if (rlevel == 2){
        lvl = "octal";
    }
    else if (rlevel == 3){
        lvl = "decimal";
    }
    else if (rlevel == 4){
        lvl = "hexadecimal";
    }

    if (operation == 1){
        if (rlevel == 1){
            binary res = numx + numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 2){
            octal res = numx + numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 3){
            decimal res = numx + numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 4){
            hexadecimal res = numx + numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
    }
    else if (operation == 2){
        if (rlevel == 1){
            binary res = numx * numy;
           cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 2){
            octal res = numx * numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 3){
            decimal res = numx * numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 4){
            hexadecimal res = numx * numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
    }
    else if (operation == 3){
        if (rlevel == 1){
            binary res = numx - numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 2){
            octal res = numx - numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 3){
            decimal res = numx - numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
        else if (rlevel == 4){
            hexadecimal res = numx - numy;
            cout << "the resultant value is  " << lvl << " " << res.getVal() << endl;
        }
    }

    
    

    return 0;
}
