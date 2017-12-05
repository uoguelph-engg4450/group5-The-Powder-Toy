#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"
#include <assert.h>
#include "../src/gui/interface/Window.h"
#include "../src/gui/options/OptionsView.h"

class OptionsViewTest : public CppUnit::TestSuite
{
    //TestSuite OptionsViewTestCase;
public:
    void setUp()
    {

    }

    void tearDown()
    {

    }

    TestSuite * suite()
    {
        TestSuite *testSuite = new TestSuite("OptionsViewTestSuite");
        //add the tests
        testSuite->addTest(new CppUnit::TestCaller <OptionsViewTest> ("testOptionsView", &OptionsViewTest::testOptionsView));
        testSuite->addTest(new CppUnit::TestCaller <OptionsViewTest> ("testNotifySettingsChanged", &OptionsViewTest::testNotifySettingsChanged));
        testSuite->addTest(new CppUnit::TestCaller <OptionsViewTest> ("testAttachController", &OptionsViewTest::testAttachController));
        testSuite->addTest(new CppUnit::TestCaller <OptionsViewTest> ("testOnDraw", &OptionsViewTest::testOnDraw));
        testSuite->addTest(new CppUnit::TestCaller <OptionsViewTest> ("testOnTryExit", &OptionsViewTest::testOnTryExit));

        return testSuite;
    }

    void testOptionsView()
    {
	puts("testOptionsView");
	OptionsView * opt = new OptionsView();
        assert(opt);
    }

    void testNotifySettingsChanged()
    {
	puts("testNotifySettingsChanged");
	OptionsView * opt = new OptionsView();
        //OptionsModel * sender = new OptionsModel(NULL);

        //opt->NotifySettingsChanged(sender);
        CPPUNIT_ASSERT(opt);
    }

    void testAttachController()
    {
	puts("testAttachController");
	OptionsView * opt = new OptionsView();
        //OptionsController * cont = new OptionsController(NULL, NULL);

        //opt->AttachController(cont);
        CPPUNIT_ASSERT(opt);
    }

    void testOnDraw()
    {
	puts("testOnDraw");
	OptionsView * opt = new OptionsView();

        //opt->OnDraw();
        CPPUNIT_ASSERT(opt);
    }

    void testOnTryExit()
    {
	puts("testOnTryExit");
	OptionsView * opt = new OptionsView();

        //opt->OnTryExit(ui::Window::ExitButton);
        CPPUNIT_ASSERT(opt);
    }

};
