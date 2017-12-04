#include "SimulationTest.cpp"
#include "OptionsViewTest.cpp"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"

int mainTest()
{
    puts("Entered unit testing controller");
    CppUnit::TestResult controller;
    CppUnit::TestResultCollector result;
    controller.addListener(&result);

    CppUnit::TestRunner runner;
    SimulationTest * simTest = new SimulationTest();
    OptionsViewTest * optTest = new OptionsViewTest();

    runner.addTest(simTest->suite());
    runner.addTest(optTest->suite());

    puts("Starting unit testing suite");
    try
    {
        runner.run(controller);
    }
    catch(...)
    {
        std::cerr << "\n\n!Unit test failed\n\n";
	return -1;
    }

    puts("\n\nTest completed, exiting...");
    return 0;
}
