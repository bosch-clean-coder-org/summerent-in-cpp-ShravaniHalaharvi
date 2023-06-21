#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits1") {
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits2") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling TOO_LOW temperature") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -2) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for Hi Active Cooling TOO_LOW temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -3) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 25) == NORMAL);
}
