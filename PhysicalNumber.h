#pragma once
#include <iostream>
#include "Unit.h"

using namespace std;

namespace ariel{
class PhysicalNumber{
   private:
   Unit _unit;
   double num;
  
  public:
     PhysicalNumber(double n,Unit _unit);
     PhysicalNumber();
     ~PhysicalNumber();
     //math operators
      PhysicalNumber operator+ (const PhysicalNumber& right);
      PhysicalNumber operator+= (const PhysicalNumber& right);
      PhysicalNumber operator+();
      PhysicalNumber operator- (const PhysicalNumber& right);
      PhysicalNumber operator-= (const PhysicalNumber& right);
      PhysicalNumber operator-();
     //compare operators
      bool operator> (const PhysicalNumber& right);
      bool operator>= (const PhysicalNumber& right);
      bool operator< (const PhysicalNumber& right);
      bool operator<= (const PhysicalNumber& right);
      bool operator== (const PhysicalNumber& right);
      bool operator!= (const PhysicalNumber& right);

      PhysicalNumber& operator--();
      PhysicalNumber& operator++();
      const PhysicalNumber operator++(int); //[V]
      const PhysicalNumber operator--(int); 
      
     //
///////////////////////////////////////
	Unit getUnit(){
return this->_unit;
}
double getNum(){
return this->num;
}
void setNum(double n){
this->num=n;
}
void setUnit(Unit u){
this->_unit=u;
}
      friend bool theSameDim(Unit a,Unit b);
///////////////////////////////////////
     friend istream& operator >> (istream & is,PhysicalNumber& f);
     friend ostream& operator<<(ostream & os,const PhysicalNumber& f);

    };
    PhysicalNumber change( PhysicalNumber a,PhysicalNumber b);
    istream& operator >> (istream & is,PhysicalNumber& f);
    ostream& operator<<(ostream & os,const PhysicalNumber& f);

};
