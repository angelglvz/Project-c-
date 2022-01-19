#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include <string>
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
    string getName()const{ return m_name;}
    double getValue()const{ return m_value;}
    
};



void printList1(map<string, Currency>& myList){
  cout << "Welcome to the currency conversor.\n Please select a currency\n\n";
  map<string, Currency>::iterator it;
  for(it = myList.begin();it != myList.end();it++){
    cout<<it->first <<": "<<it->second.getName()<<endl;
  }
  cout<< "\n0: Stop the program\n\n";
}

void printList2(map<string, Currency>& myList, string values){
  cout << "\n Please select a second currency currency\n\n";
  map<string, Currency>::iterator it;
  for(it = myList.begin();it != myList.end();it++){
    if(it->first != values )
      cout<<it->first <<": "<<it->second.getName()<<endl;
  }
  cout<< "\n0: Go to main\n\n";
}

int readValue( map<string, Currency> myList){
  bool usable =false;
  int devolver=0;

  do{
    string input;
    cin>> input;
    map<string, Currency>::iterator it;
    if(input =="0"){usable = true;}
    else{
      for(it = myList.begin();it!= myList.end(); it++){
        if(input == it->first){
          usable = true;
          devolver = stoi(input);
        }
      }
    }

    if(!usable){
      cout << "\nPlease select a valid input\n\n";
      printList1(myList);
    }
    
    
  }while(!usable);
  return devolver;

}
int readValue2( map<string, Currency> myList, string values){
  bool usable =false;
  int devolver=0;

  do{
    string input;
    cin>> input;
    map<string, Currency>::iterator it;
    if(input =="0"){usable = true;}
    else{
      for(it = myList.begin();it!= myList.end(); it++){
        if(input == it->first){
          if(input == values){
            cout << "That number is unavalable\n";
          }
          else{
            usable = true;
            devolver = stoi(input);
          }
          
        }
      }
    }

    if(!usable){
      cout << "\nPlease select a valid input\n\n";
      printList2(myList, values);
    }
    
    
  }while(!usable);
  return devolver;

}

bool isDouble(const string& str){
  char* end = nullptr;
  strtod(str.c_str(), &end);
  return end != str.c_str() && *end == '\0';
}

double readQuantity(){
  double devolver;
  bool usable(false);

  do{
    string input;
    cin>> input;
    if(!isDouble(input)){
      cout <<"Please select a valid Quantity\n\n";
    }
    else{
      devolver = stod(input);
      if(devolver <0){
        cout <<"Please select a positive number\n\n";
      }
      else{
        cout << "Valid quantity\n\n";
        usable = true;
      }
    }
    
    
  }while(!usable);
  return devolver;
}



double calculate(const string& values, const string & values2, const double& quantity, map<string, Currency> myList){
  double primer, segundo;
  map<string, Currency>::iterator it;
  for(it= myList.begin();it!= myList.end(); it++){
    if (it->first == values){primer=it->second.getValue();}
    if (it->first == values2){segundo=it->second.getValue();}
  }

  return quantity/primer*segundo;
}

int main(){
    
  map<string, Currency> my_map{{"1",Currency(1.00,"European Euro")},{"2",Currency(1.04,"Swiss Franc")},{"3",Currency(0.84,"British Pounds")},{"4",Currency(130.02,"Japanese Yen")},{"5",Currency(1.14,"American Dolar")},{"6",Currency(4.53,"Polish Zloti")},{"7",Currency(7.44,"Danish Crown")},{"8",Currency(10.28,"Sewedish Crown")}};
  
  
  int values, values2;
  bool mainMenu(false), secondMenu(false);
  double quantity;

  while(!mainMenu){
    mainMenu=false;
    secondMenu=false;
    printList1(my_map);
    values = readValue(my_map );
  
    switch(values){
      case 0: 
        mainMenu=true;
        break;

      default:
        cout<< "Selected value: "<<values<<"\nWhich is the currency: " << my_map[to_string(values)].getName()<<"\n\n";
        cout << "Select the quantity\n";
        quantity = readQuantity();

        while(!secondMenu){
          printList2(my_map,to_string(values));
          values2 = readValue2(my_map, to_string(values));

          switch(values2){
            case 0:
              secondMenu=true;
              break;
            default:
              cout << calculate(to_string(values), to_string(values2), quantity,my_map)<< endl;
              secondMenu=true;
          }
        }
        break;
    }
  }
  return 0;

}
