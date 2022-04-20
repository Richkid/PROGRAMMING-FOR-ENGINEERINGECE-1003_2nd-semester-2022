#include <iostream>

using namespace std;

class numbers{
    public:
    unsigned char value;

    numbers(unsigned char val){
        value = val;
    }

    numbers operator*(numbers B){
        return numbers(B.value & value);
    }

    numbers operator+(numbers B){
        return numbers(B.value | value);
    }

    numbers operator-(numbers B){
        return numbers(B.value | ((~value) | 1));
    }
};

class binary  : public numbers{
    unsigned char num = 0xfaaa; //hex
    unsigned char num = 0ofaaa;
    unsigned char num = 0b101001;

};

int main(){
    
    numbers a = numbers(5); //101
    numbers b = numbers(6); //110
    numbers c = a * b; //111 -> 7
    cout << (int)c.value << endl;
    return 0;
}
