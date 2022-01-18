#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<iterator>
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
void printList1(map<int, Currency>& myList){
  map<int, Currency>::iterator it;
  for(it = myList.begin();it != myList.end();it++){
    cout<<it->first <<": "<<it->second.getName()<<endl;
  }
  cout<< "\n0: Stop the program\n\n";
}

void readValue(const string& str, int& i,map<int, Currency>& myList){
  bool usable =false;
  do{
    string::const_iterator it= str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    if( !str.empty() && it == str.end()){
      i = stoi(str);
      if (i>=0 && i<=8){
        usable=true;
      }
      else{
        cout<<"Inapropiate value";
        printList1(myList);
      }
    }
    else{
      cout<<"Inapropiate value";
      printList1(myList);
    }
  }while(!usable);

}

int main(){
    
  map<int, Currency> my_map{{1,Currency(1.00,"European Euro")}};
  my_map[2] = Currency(1.04,"Swiss Franc");
  my_map[3] = Currency(0.84,"British Pounds");
  my_map[4] = Currency(130.02,"Japanese Yen");
  my_map[5] = Currency(1.14,"American Dolar");
  my_map[6] = Currency(4.53,"Polish Zloti");
  my_map[7] = Currency(7.44,"Danish Crown");
  my_map[8] = Currency(10.28,"Sewedish Crown");
  
  cout << "Welcome to the currency conversor.\n Please select a currency\n\n";
  string values = "";
  int values2;
  bool programa(false);
  while(!programa){
    printList1(my_map);
    cin >>values;
    readValue(values, values2,my_map );
    switch(values2){
      default: break;
    }
  }

}
