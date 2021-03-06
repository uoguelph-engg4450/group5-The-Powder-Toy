#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"
#include <assert.h>

#include "../src/gui/game/GameModel.h"
#include "../src/gui/interface/Window.h"
#include "../src/gui/options/OptionsView.h"
#include "../src/gui/options/OptionsController.h"
#include "../src/Controller.h"

class OptionsViewTest : public CppUnit::TestSuite {
    //TestSuite OptionsViewTestCase;
public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    TestSuite* suite()
    {
        TestSuite* testSuite = new TestSuite("OptionsViewTestSuite");
        //add the tests
        testSuite->addTest(new CppUnit::TestCaller<OptionsViewTest>("testOptionsView", &OptionsViewTest::testOptionsView));
        testSuite->addTest(new CppUnit::TestCaller<OptionsViewTest>("testNotifySettingsChanged", &OptionsViewTest::testNotifySettingsChanged));
        testSuite->addTest(new CppUnit::TestCaller<OptionsViewTest>("testAttachController", &OptionsViewTest::testAttachController));
        testSuite->addTest(new CppUnit::TestCaller<OptionsViewTest>("testOnDraw", &OptionsViewTest::testOnDraw));
        testSuite->addTest(new CppUnit::TestCaller<OptionsViewTest>("testOnTryExit", &OptionsViewTest::testOnTryExit));

        return testSuite;
    }

    void testOptionsView()
    {
        std::cout << "Test OptionsView\n\n";
        OptionsView* opt = new OptionsView();
        assert(opt);
    }

    void testNotifySettingsChanged()
    {
        std::cout << "Test NotifySettingsChanged\n\n";
        OptionsView* opt = new OptionsView();
        GameModel* mod = new GameModel();
        OptionsModel* sender = new OptionsModel(mod);

        opt->NotifySettingsChanged(sender);
        CPPUNIT_ASSERT(opt);
    }

    void testAttachController()
    {
        std::cout << "Test AttachController\n\n";
        OptionsView* opt = new OptionsView();
        GameModel* mod = new GameModel();
        ControllerCallback* call = new ControllerCallback();
        OptionsController* cont = new OptionsController(mod, call);

        opt->AttachController(cont);
        CPPUNIT_ASSERT(opt);
    }

    void testOnDraw()
    {
        std::cout << "Test OnDraw\n\n";
        OptionsView* opt = new OptionsView();

        opt->OnDraw();
        CPPUNIT_ASSERT(opt);
    }

    void testOnTryExit()
    {
        std::cout << "Test OnTryExit\n\n";
        OptionsView* opt = new OptionsView();
        GameModel* mod = new GameModel();
        ControllerCallback* call = new ControllerCallback();
        OptionsController* cont = new OptionsController(mod, call);

        opt->AttachController(cont);
        opt->OnTryExit(ui::Window::ExitButton);
        CPPUNIT_ASSERT(opt);
    }
};
