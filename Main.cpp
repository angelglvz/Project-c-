#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include <map>
using namespace std;

class Currency{
  private:
    double m_value;
    string m_name;
  public: 
    Currency(double value = 1.00, string name = ""):m_value(value), m_name(name){}
    ~Currency(){
    }
    friend ostream& operator<<(ostream& out, const Currency& c1);
    string getName()const{ return m_name;}
    double getValue()const{ return m_value;}
    
};

ostream& operator<<(ostream& out, const Currency& c1){
    out << c1.m_name << "value related to Euro is: " << c1.m_value <<"\n";
    return out;
}

int main(){
    
    map<string, Currency> my_map{{"1",Currency(1.00,"European Euro")}};
    my_map["2"] = Currency(1.04,"Swiss Franc");
    my_map["3"] = Currency(0.84,"British Pounds");
    my_map["4"] = Currency(130.02,"Japanese Yen");
    my_map["5"] = Currency(1.14,"American Dolar");
    my_map["6"] = Currency(4.53,"Polish Zloti");
    my_map["7"] = Currency(7.44,"Danish Crown");
    my_map["8"] = Currency(10.28,"Sewedish Crown");
    
    cout << "Welcome to the currency conversor.\n Please select a currency\n";
    

}
