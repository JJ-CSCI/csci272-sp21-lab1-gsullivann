//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write your code here


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
