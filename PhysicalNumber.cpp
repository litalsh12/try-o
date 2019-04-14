
#include <iostream>
#include <sstream>
#include <stdexcept>
using std::cout, std::endl, std::boolalpha, std::istringstream;
#include "PhysicalNumber.h"
#include "Unit.h"
using ariel::PhysicalNumber, ariel::Unit;
     ariel::PhysicalNumber::PhysicalNumber(double n,Unit _unit){
     this->num=n;
     this->_unit=_unit;
     }
        ariel::PhysicalNumber::PhysicalNumber(){
     this->num=NULL;
     this->_unit=null;
     }
     ariel::PhysicalNumber::~PhysicalNumber(){
    }
 

     bool theSameDim(Unit a,Unit b){
       //Unit a=this->_unit;
       if((a<=3&&b>3)||(b<=3&&a>3)||(a<=6&&b>6)||(b<=6&&a>6)){
         throw std::invalid_argument("the unit are not at the same dim");
       }else
       {
         return true;
       }
     }
  
     /*double ariel::change( PhysicalNumber a,PhysicalNumber b){
            Unit unitA=a.getUnit();
            Unit unitB=b.getUnit();
            //PhysicalNumber temp=PhysicalNumber();
            if(unitA==1){//unitA=cm
              if(unitB==2){//unitB=m
                //temp.setUnit(ariel::CM);
              //  temp.setNum(b.getNum()*100);
                return b.getNum()*100;
              }
              else if(unitB==3){//unitB=km
               // temp.setUnit(ariel::CM);
               // temp.setNum(b.getNum()*100000);
                return b.getNum()*100000;
              }
            }
            if(unitA==2){//unitA=m
                   if(unitB==1){//unitB=cm
              //  temp.setUnit(ariel::M);
            //    temp.setNum(b.getNum()/100);
                return b.getNum()/100;
              }
              else if(unitB==3){//unitB=km
               // temp.setUnit(ariel::M);
              //  temp.setNum(b.getNum()*1000);
                return b.getNum()*1000;
              } 
            }
              if(unitA==3){//unitA=km
                   if(unitB==1){//unitB=cm
              //  temp.setUnit(ariel::KM);
                //temp.setNum(b.getNum()/100000);
                return b.getNum()/100000;
              }
              else if(unitB==2){//unitB=m
               // temp.setUnit(ariel::KM);
              //  temp.setNum(b.getNum()/1000);
                return b.getNum()/1000;
              }
            }
            return 0;
     }*/
        PhysicalNumber ariel::change( PhysicalNumber a,PhysicalNumber b){
            Unit unitA=a.getUnit();
            Unit unitB=b.getUnit();
            PhysicalNumber temp=PhysicalNumber();
            if(unitA==unitB){
              return b;
            }
            if(unitA==1){//unitA=cm
              if(unitB==2){//unitB=m
                temp.setUnit(ariel::CM);
                temp.setNum(b.getNum()*100);
                return temp;
              }
              else if(unitB==3){//unitB=km
                temp.setUnit(ariel::CM);
                temp.setNum(b.getNum()*100000);
                return temp;
              }
            }
            if(unitA==2){//unitA=m
                   if(unitB==1){//unitB=cm
                temp.setUnit(ariel::M);
                temp.setNum(b.getNum()/100);
                return temp;
              }
              else if(unitB==3){//unitB=km
                temp.setUnit(ariel::M);
                temp.setNum(b.getNum()*1000);
                return temp;
              } 
            }
              if(unitA==3){//unitA=km
                   if(unitB==1){//unitB=cm
                temp.setUnit(ariel::KM);
                temp.setNum(b.getNum()/100000);
                return temp;
              }
              else if(unitB==2){//unitB=m
                temp.setUnit(ariel::KM);
                temp.setNum(b.getNum()/1000);
                return temp;
              }
            }
            if(unitA==4){//unitA=sec
                   if(unitB==5){//unitB=min
                temp.setUnit(ariel::SEC);
                temp.setNum(b.getNum()*60);
                return temp;
              }
              else if(unitB==6){//unitB=hour
                temp.setUnit(ariel::SEC);
                temp.setNum(b.getNum()*360);
                return temp;
              }
            }
             if(unitA==5){//unitA=min
                   if(unitB==4){//unitB=sec
                temp.setUnit(ariel::MIN);
                temp.setNum(b.getNum()/60);
                return temp;
              }
              else if(unitB==6){//unitB=hour
                temp.setUnit(ariel::MIN);
                temp.setNum(b.getNum()*60);
                return temp;
              }
            }
             if(unitA==6){//unitA=hour
                   if(unitB==4){//unitB=sec
                temp.setUnit(ariel::HOUR);
                temp.setNum(b.getNum()/360);
                return temp;
              }
              else if(unitB==5){//unitB=min
                temp.setUnit(ariel::HOUR);
                temp.setNum(b.getNum()/60);
                return temp;
              }
            }
             if(unitA==7){//unitA=gram
                   if(unitB==8){//unitB=kg
                temp.setUnit(ariel::G);
                temp.setNum(b.getNum()*1000);
                return temp;
              }
              else if(unitB==9){//unitB=ton
                temp.setUnit(ariel::G);
                temp.setNum(b.getNum()*1000*1000);
                return temp;
              }
            }
              if(unitA==8){//unitA=kg
                if(unitB==7){//unitB=gram
                temp.setUnit(ariel::KG);
                temp.setNum(b.getNum()/1000);
                return temp;
              }
              else if(unitB==9){//unitB=ton
                temp.setUnit(ariel::KG);
                temp.setNum(b.getNum()*1000);
                return temp;
              }
            }
              if(unitA==9){//unitA=ton
                if(unitB==7){//unitB=gram
                temp.setUnit(ariel::TON);
                temp.setNum(b.getNum()/1000/1000);
                return temp;
              }
              else if(unitB==8){//unitB=kg
                temp.setUnit(ariel::TON);
                temp.setNum(b.getNum()/1000);
                return temp;
              }
            }
throw std::invalid_argument("the unit are not at the same dim");

     }
     
     ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& right){
       if(theSameDim(this->_unit,right._unit)){
        PhysicalNumber ans= ariel::change(*this,right);
        ans.setNum(ans.getNum()+this->getNum());
                return      ans;

       }
       return  *this;
     }
     
     ariel::PhysicalNumber ariel::PhysicalNumber::operator+= (const PhysicalNumber& right){
              if(theSameDim(this->_unit,right._unit)){
                 PhysicalNumber temp= ariel::change(*this,right);
                 this->setNum(this->getNum()+temp.getNum());
              }
       return      *this;
     }
     ariel::PhysicalNumber ariel::PhysicalNumber::operator+ (){
       if((this->getNum())<0){
         this->setNum(this->getNum()*-1);
       }
       return      *this;
     }
     ariel::PhysicalNumber ariel::PhysicalNumber::operator- (const PhysicalNumber& right){
                if(theSameDim(this->_unit,right._unit)){
        PhysicalNumber ans= ariel::change(*this,right);
        ans.setNum(ans.getNum()-this->getNum());
                return      ans;

       }
       return  *this;
     }
     ariel::PhysicalNumber ariel::PhysicalNumber::operator-= (const PhysicalNumber& right){
                 if(theSameDim(this->_unit,right._unit)){
                 PhysicalNumber temp= ariel::change(*this,right);
                 this->setNum(this->getNum()-temp.getNum());
              }
       return      *this;
     }
    ariel::PhysicalNumber ariel::PhysicalNumber::operator-(){
         this->setNum(this->getNum()*-1);
       
       return      *this;
       }


     //compare operators
     bool ariel::PhysicalNumber::operator>(const PhysicalNumber& right){
            if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num>ans.num)
                return true;
              }
       return      false;
     }
     bool ariel::PhysicalNumber::operator>=(const PhysicalNumber& right){
            if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num>=ans.num)
                return true;
              }
       return      false;
     }
     bool ariel::PhysicalNumber::operator<(const PhysicalNumber& right){
            if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num<ans.num)
                return true;
              }
       return      false;
     }
     bool ariel::PhysicalNumber::operator<=(const PhysicalNumber& right){
            if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num<=ans.num)
                return true;
              }
       return      false;
     }
     bool ariel::PhysicalNumber::operator==(const PhysicalNumber& right){
            if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num==ans.num)
                return true;
              }
       return      false;
     }
    bool ariel::PhysicalNumber::operator!=(const PhysicalNumber& right){
         if(theSameDim(this->_unit,right._unit)){
              PhysicalNumber ans= ariel::change(*this,right);
              if(this->num!=ans.num)
                return true;
              }
       return      false;
     }
     //
const PhysicalNumber ariel::PhysicalNumber::operator++(int) {
PhysicalNumber ans=*this;
this->num ++ ;
return ans;
}
const PhysicalNumber ariel::PhysicalNumber::operator--(int) { 
PhysicalNumber ans=*this;
this->num -- ;
return ans;
}
    ariel::PhysicalNumber& ariel::PhysicalNumber::operator--(){
      this->setNum(this->getNum()-1);
       return      *this;
     }
    ariel::PhysicalNumber& ariel::PhysicalNumber::operator++(){
     this->setNum(this->getNum()+1);
       return      *this;
     }
     //
     istream& ariel::operator>> (istream & is,PhysicalNumber& n){
      return is;

     }
     ostream& ariel::operator<<(ostream & os,const PhysicalNumber& f){
    string output ="";
    switch (f._unit){
        case 1: output= "cm";break;
        case 2: output= "m";break;
        case 3: output= "km";break;
        case 4: output= "sec";break;
        case 5: output= "min";break;
        case 6: output= "hour";break;
        case 7: output= "g";break;
        case 8: output= "kg";break;
        case 9: output= "ton";break;
        default: throw invalid_argument("error");
    }
     return os << f.num << "[" << output <<"]";
    }
  

