#include "SimulationTest.cpp"
#include "OptionsViewTest.cpp"
#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <exception>

int mainTest()
{
    puts("Entered unit testing controller");
    CppUnit::TestResult controller;
    CppUnit::TestResultCollector result;
	CppUnit::TextTestProgressListener progress;
   	controller.addListener(&progress); 
    controller.addListener(&result);

    CppUnit::TestRunner runner;
    SimulationTest * simTest = new SimulationTest();
    OptionsViewTest * optTest = new OptionsViewTest();

    runner.addTest(simTest->suite());
    runner.addTest(optTest->suite());

    puts("Starting unit testing suite");
    try
    {
    	//std::cout << "Running " << testPath;
    	runner.run(controller);
    	CppUnit::CompilerOutputter outputter(&result,std::cout);
        outputter.write();
    }
    catch(int e)
    {
        std::cerr << "\n\nError: " << e << "\tUnit test failed\n\n";
	return -1;
    }
    catch(...)
    {
        std::cerr << "\n\nUnit test failed\n\n";
	return -1;
    }

    puts("\n\nTest completed, exiting...");
    return 0;
}
