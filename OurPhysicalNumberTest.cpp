/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   
    PhysicalNumber km(7, Unit::KM);
    PhysicalNumber m(500, Unit::M);
    PhysicalNumber cm(20, Unit::CM);
    PhysicalNumber sec(360, Unit::SEC);
    PhysicalNumber min(45, Unit::MIN);
    PhysicalNumber hour(1, Unit::HOUR);
    PhysicalNumber g(1000, Unit::G);
    PhysicalNumber ton(20, Unit::TON);
    PhysicalNumber kg(8, Unit::KG);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//distance units
    .setname("Compatible dimensions")
    .CHECK_OUTPUT(km-m, "6.5[km]")
    .CHECK_OUTPUT(km+km , "14[km]")
    .CHECK_OUTPUT((m-=km), "-6500[m]")
    .CHECK_OUTPUT((km+=m) , "7.5[km]")
    .CHECK_OUTPUT(++cm , "21[cm]")
    .CHECK_OUTPUT(--km , "6.5[km]")
 
    .CHECK_EQUAL (m==km, false)
    .CHECK_EQUAL (cm==cm , true)
    .CHECK_EQUAL (km!=cm , true)
    .CHECK_EQUAL (km!=km , true)
    .CHECK_EQUAL (m<km, true)
    .CHECK_EQUAL (m<cm , false)
    .CHECK_EQUAL (m>cm , true)
    .CHECK_EQUAL (m>km, false)
    .CHECK_EQUAL (m<=m , true)
    .CHECK_EQUAL (m<=hour , true)
    .CHECK_EQUAL (m<=cm , false)
    .CHECK_EQUAL (m>=m , true)
    .CHECK_EQUAL (m>=cm ,true)
    .CHECK_EQUAL (m>=km , false)



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  //time units-
    .CHECK_OUTPUT(hour+min, "1.45[hour]")
    .CHECK_OUTPUT((min+=sec), "51[min]")
    .CHECK_OUTPUT(min, "51[min]")
    .CHECK_OUTPUT(min-sec, "45[min]")
    .CHECK_OUTPUT((min-=sec) , "45[min]")
    .CHECK_OUTPUT(--min, "44[min]")
    .CHECK_OUTPUT(++hour, "2[hour]")    

    .CHECK_EQUAL (min<hour, true)
    .CHECK_EQUAL (hour<sec ,false)
    .CHECK_EQUAL (min>sec ,true)
    .CHECK_EQUAL (sec>min, false)
    .CHECK_EQUAL(sec<=sec , true)
    .CHECK_EQUAL(sec <= hour, true)
    .CHECK_EQUAL(hour <= min , false)
    .CHECK_EQUAL(min>=min , true)
    .CHECK_EQUAL(min>=sec , true)
    .CHECK_EQUAL(min>=hour , false)
    .CHECK_EQUAL(sec==sec , true)
    .CHECK_EQUAL(sec==min , false)
    .CHECK_EQUAL(hour!=hour , true)
    .CHECK_EQUAL (hour!=min, true)
 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    
    //mass units-
    .CHECK_OUTPUT(g+kg,"9000[g]")
    .CHECK_OUTPUT(ton-kg , "19.992[ton]")
    .CHECK_OUTPUT(ton, "20[ton]")
    .CHECK_OUTPUT(++kg, "9[kg]")
    .CHECK_OUTPUT(kg-g, "8[kg]")
    .CHECK_OUTPUT(--ton, "19[ton]")
    .CHECK_OUTPUT((kg+=g), "10[kg]")
    .CHECK_OUTPUT((kg-=g), "9[kg]")
    
    .CHECK_EQUAL (ton>kg, true)
    .CHECK_EQUAL (g<kg, true)
    .CHECK_EQUAL (ton<g, false)
    .CHECK_EQUAL (g>kg, false)
    .CHECK_EQUAL (g>=g , true)
    .CHECK_EQUAL (g>=kg , false)
    .CHECK_EQUAL (kg>=g , true)
    .CHECK_EQUAL (kg<=kg , true)
    .CHECK_EQUAL (kg<=ton , true)
    .CHECK_EQUAL (kg<=g , false)
    .CHECK_EQUAL (ton!=g, true)
    .CHECK_EQUAL (g!=g , false)
    .CHECK_EQUAL (kg==kg, true)
    .CHECK_EQUAL (g==kg, false)


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//stream

    .CHECK_OK (istringstream("9[kg]") >> kg)
    .CHECK_OK (istringstream("44[nin]") >> min)
    .CHECK_OK (istringstream("21[cm]") >> cm)


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    // Throws : 
.setname("Incompatible dimensions")

.CHECK_THROWS(hour+ton)
.CHECK_THROWS(ton+hour)
.CHECK_THROWS(min-cm)
.CHECK_THROWS(cm-min)
.CHECK_THROWS(m+=sec)
.CHECK_THROWS(sec+=m)
.CHECK_THROWS(ton-=km)
.CHECK_THROWS(km-=ton)
.CHECK_THROWS(m==sec)
.CHECK_THROWS(sec==m)
.CHECK_THROWS(ton!=min)
.CHECK_THROWS(min!=ton)
.CHECK_THROWS(hour<cm)
.CHECK_THROWS(cm<hour)
.CHECK_THROWS(m<=g)
.CHECK_THROWS(g<=m)
.CHECK_THROWS(min>km)
.CHECK_THROWS(km>min)
.CHECK_THROWS(sec>=ton)
.CHECK_THROWS(ton>=sec)


  .CHECK_THROWS(istringstream("200[g") >> m)
  .CHECK_THROWS(istringstream("0.2[]") >> km)
  .CHECK_THROWS(istringstream("200g]") >> km)
  .CHECK_THROWS(istringstream("0.2[kg]") >> hour)

    .setname("...")
      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
