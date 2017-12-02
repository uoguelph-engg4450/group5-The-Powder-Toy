#include "SimulationTest.cpp"
#include "OptionsViewTest.cpp"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"

/* Put the functions inside the PowderToySDL.cpp main()
   I can't fix the makefile to compile this without scons
  -Tianyue
int main ()
{
    CppUnit::TestRunner runner;
    SimulationTest * simTest = new SimulationTest();
    OptionsViewTest * optTest = new OptionsViewTest();

    runner.addTest(simTest->suite());
    runner.addTest(optTest->suite());

    CppUnit::TestResult result;
    runner.run(result);

    delete simTest;
    delete optTest;
    return 0;
}*/
