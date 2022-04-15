/*
University of Technology
End of Term Assignment
Lecturer: Dr Chambers.
Richard Clarke 0904223,
Domonic Humphrey 1207771,
Stephany
Project Dead line April 20, 2022

*/

#include<iostream>
#include<math.h>
using namespace std;


/*
Objective:
Binary , Octal , Decimal , Hexadecimal

Addition, Subtraction , Multiplication , Conversion from one system to another ?

Use overload operators
Carry out operations on objects of different classes

e.g Octal = Binary * Octal

*/

 void add();
 void subtract();
 void multiply();
 void divide();

 int num1, num2;
int main()
{

char option;
 cout<< " Enter the first Value: ";
 cin>>num1;
 cout<< " Enter the 2nd Value: ";
 cin>> num2;
 cout<<" +\t-\t*\t/"<< endl;   // this will give the user option
 cin>>option;
 switch (option)
 {
    case '+':
        add();
        break;
    case '_':
        subtract();
        break;
    case '*':
        multiply();
        break;
    case '/':
        divide();
        break;

    default:
        cout<< " invalid entry"<<endl;
 }


}
void add()
{
    int result;
    result = num1+num2;
    cout<<" Result of Addition: " << result << endl;
}

void subtract()
{
    int result;
    result = num1-num2;
    cout<<" Result of Addition: " << result << endl;
}

void multiply()
{
    int result;
    result = num1*num2;
    cout<<" Result of Addition: " << result << endl;

}

void divide()
{
    int result;
    result = num1/num2;
    cout<<" Result of Addition: " << result << endl;
}
