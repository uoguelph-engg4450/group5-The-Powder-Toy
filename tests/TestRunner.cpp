#include "SimulationTest.cpp"
#include "OptionsViewTest.cpp"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"

public: 
int main ()
{
    CppUnit::TextUi:TestRunner runner;
    runner.addTest(SimulationTestSuite::suite());
    //runner.addTest(OptionsViewTestSuite::suite());
    runner.run();
    return 0;
}