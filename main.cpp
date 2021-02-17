//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write your code here
class Parasite {
private:
  double reproductionRate{0.0};
  double resistance {0.0};
public:
  double getReproductionRate() { return reproductionRate; }
  double getResistance() { return resistance; }
  void reproduce() { reproductionRate += 0.1; }
  void survive() { resistance += 0.05; }
};

class Animal {
private:
  double immunity {0.0};
  unsigned int parasite {1000};
public:
  double getImmunity() {return immunity; }
  unsigned int getParasiteNumber() { return parasite; }
  void takeDrug() {
    immunity += 0.07;
    parasite -= 100;
  }

};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
#include <cmath>

bool equal(double x, double y, double epsilon = 0.01) {
   return fabs(x - y) < epsilon;
}

TEST_CASE( "Simulation" ) {
    SECTION( "Parasite-Fields" ) {
        Parasite p;
        REQUIRE( equal(p.getResistance(), 0.0) );
        REQUIRE( equal(p.getReproductionRate(), 0.0) );
    }
    SECTION( "Parasite-Methods" ) {
        Parasite p;
        REQUIRE( equal(p.getReproductionRate(), 0.0) );
        p.reproduce();
        p.reproduce();
        REQUIRE( equal(p.getReproductionRate(), 0.2) );
        REQUIRE( equal(p.getResistance(), 0.0) );
        p.survive();
        p.survive();
        p.survive();
        REQUIRE( equal(p.getResistance(),  0.15) );
    }
    SECTION( "Animal-Fields" ) {
        Animal p;
        REQUIRE( equal(p.getImmunity(), 0.0) );
        REQUIRE( equal(p.getParasiteNumber(), 1000) );
    }
    SECTION( "Animal-Methods" ) {
        Animal a;
        REQUIRE( equal(a.getImmunity(), 0.0) );
        REQUIRE( equal(a.getParasiteNumber(), 1000) );
        a.takeDrug();
        a.takeDrug();
        REQUIRE( equal(a.getImmunity(), 0.14) );
        REQUIRE( equal(a.getParasiteNumber(), 800) );
    }
}
//------------------------------
