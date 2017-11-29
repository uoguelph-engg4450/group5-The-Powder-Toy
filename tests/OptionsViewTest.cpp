#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"

#include "OptionsView.h"

class OptionsViewTestCase : public CppUnit::TestSuite
{
    //TestSuite OptionsViewTestCase;
public:
    void setup()
    {

    }

    void tearDown()
    {

    }

    TestSuite * suite()
    {
        TestSuite *testSuite = new TestSuite("OptionsViewTestSuite");
        //add the tests
        /*testSuite->addTest(new TestCaller <OptionsViewTestSuite> ("testOptionsView", &OptionsViewTestSuite::testOptionsView));
        testSuite->addTest(new TestCaller <OptionsViewTestSuite> ("testNotifySettingsChanged", &OptionsViewTestSuite::testNotifySettingsChanged));
        testSuite->addTest(new TestCaller <OptionsViewTestSuite> ("testAttachController", &OptionsViewTestSuite::testAttachController));
        testSuite->addTest(new TestCaller <OptionsViewTestSuite> ("testOnDraw", &OptionsViewTestSuite::testOnDraw));
        testSuite->addTest(new TestCaller <OptionsViewTestSuite> ("testOnTryExit", &OptionsViewTestSuite::testOnTryExit));*/
        //....    

        return testSuite;
    }

    void testOptionsView()
    {
        //assertEquals(true, true);
        //OptionsView();
    }

    void testNotifySettingsChanged()
    {
        //assertEquals(true, true);
        //void NotifySettingsChanged(OptionsModel * sender);
    }

    void testAttachController()
    {
        //assertEquals(true, true);
        //void AttachController(OptionsController * c_);
    }

    void testOnDraw()
    {
        //assertEquals(true, true);
        //void OnDraw();
    }

    void testOnTryExit()
    {
        //assertEquals(true, true);
        //void OnTryExit(ExitMethod method);
    }

};