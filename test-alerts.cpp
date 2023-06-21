#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

BatteryCharacter batterychar[3] = { (PASSIVE_COOLING,"ABC Corp"), (HI_ACTIVE_COOLING,"XYZ Corp"), (MED_ACTIVE_COOLING,"123 Corp") };
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

TEST_CASE("Classify Temperature Breach for Hi Active Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for Hi Active Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 25) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for Med Active Cooling TOO_LOW temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -4) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for Med Active Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for Med Active Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 25) == NORMAL);
}

TEST_CASE("Negative test case for Passive Cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -2) != NORMAL);
}

TEST_CASE("Negative test case for Hi Active Cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 35) != TOO_HIGH);
}

TEST_CASE("Negative test case for Med Active Cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 45) != TOO_LOW);
}

TEST_CASE("Test case for check and Alert") {
  checkAndAlert(TO_CONTROLLER, batterychar[0],10);
}
