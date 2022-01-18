#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>
#include <vector>

#define Swiss_Franc_rate 1.04;
#define British_Pounds_rate 0.84;
#define Japanese_Yen_rate 130.02;
#define American_Dollar_rate 1.14;
#define Euros_rate 1.00; 
#define Polish_zloti_rate 4.53;
#define Danish_Crown_rate 7.44;
#define Swedish_Crown_rate 10.28;

void printlist(vector <string> myVector){
    for(vector<string>::iterator i = v.begin(); i != v.end(); i++){
        cout << *i << "\n";
    }
    cout << "\n";
}

int main(){
    
    vector<string> currencyList;
    currencyList.push("Swiss Franc");
    currencyList.push("British Pound");
    currencyList.push("Japanese Yen");
    currencyList.push("Americand Dolar");
    currencyList.push("European Euro");
    currencyList.push("Polish zloti");
    currencyList.push("Danish Crown");
    currencyList.push("Swedish Crown");


    cout<<"Welcome to the currency convertor \n";
    printvector(currencyList);

}