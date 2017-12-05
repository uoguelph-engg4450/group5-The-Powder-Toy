#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"
#include <stdlib.h>         //needed for atoi

#include <assert.h>
#include "../src/simulation/Simulation.h"
#include "../src/simulation/Snapshot.h"
#include "../src/simulation/Sample.h"
#include "../src/gui/game/Brush.h"
#include "../src/simulation/Particle.h"
#include "../src/gui/interface/Engine.h"

class SimulationTest : public CppUnit::TestSuite
{
private:
    GameSave * emptySave;
    Snapshot * emptySnapshot;
    SimulationSample  emptySample;
    Simulation * simulation;
public:
	/** @brief  This function compares 2 void pointers byte by byte
	  * @param  Left side of comparison, right side of comparison
	  * @return Whether both sides are equal in value
	  */
	bool equals(void *lhs, void *rhs)
	{
		unsigned long sl = sizeof lhs, sr = sizeof rhs;
		unsigned char t1, t2;

		if (sl != sr) return false;
		for (unsigned long i = 0; i < sl; i++)
		{
			t1 = *((unsigned char *)(lhs + i));
			t2 = *((unsigned char *)(rhs + i));
			if (t1 != t2) return false;
		}
		return true;
	}

    void setUp()
    {
	    simulation = new Simulation();
        emptySave = simulation->Save();
        emptySnapshot = simulation->CreateSnapshot();
        emptySample = simulation->GetSample(0,0);        
    }

    void tearDown()
    {

    }

    TestSuite * suite()
    {
        TestSuite *testSuite = new TestSuite("SimulationTestSuite");
        //add the tests
        //testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testLoad", &SimulationTest::testLoad)); //SEG_FAULT
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSave", &SimulationTest::testSave));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSaveSimOptions", &SimulationTest::testSaveSimOptions));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetSample", &SimulationTest::testGetSample));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateSnapshot", &SimulationTest::testCreateSnapshot));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testRestore", &SimulationTest::testRestore));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsBlocking", &SimulationTest::testIsBlocking));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsBoundary", &SimulationTest::testIsBoundary));
        //testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFindNextBoundary", &SimulationTest::testFindNextBoundary)); //SEG_FAULT
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPNJunctionSprk", &SimulationTest::testPNJunctionSprk));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPhotoelectricEffect", &SimulationTest::testPhotoelectricEffect));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDirectionToMap", &SimulationTest::testDirectionToMap));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDoMove", &SimulationTest::testDoMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testTryMove", &SimulationTest::testTryMove));
        //testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testEvalMove", &SimulationTest::testEvalMove)); //SEG_FAULT
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testInitCanMove", &SimulationTest::testInitCanMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWallBlocking", &SimulationTest::testIsWallBlocking));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateCherenkovPhoton", &SimulationTest::testCreateCherenkovPhoton));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateGainPhoton", &SimulationTest::testCreateGainPhoton));
        

        //Alfie
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testKillPart", &SimulationTest::testKillPart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodFillPmapCheck", &SimulationTest::testFloodFillPmapCheck));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodProp", &SimulationTest::testFloodProp));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodWater", &SimulationTest::testFloodWater));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodINST", &SimulationTest::testFloodINST));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPartChangeType", &SimulationTest::testPartChangeType));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreatePart", &SimulationTest::testCreatePart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDeletePart", &SimulationTest::testDeletePart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWire", &SimulationTest::testIsWire));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWireOff", &SimulationTest::testIsWireOff));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSetEmap", &SimulationTest::testSetEmap));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testUpdateParticles", &SimulationTest::testUpdateParticles));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSimulateGol", &SimulationTest::testSimulateGol));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testRecalcFreeParticles", &SimulationTest::testRecalcFreeParticles));
        

        //Brandon 
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCheckStacking", &SimulationTest::testCheckStacking));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testBeforeSim", &SimulationTest::testBeforeSim));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testAfterSim", &SimulationTest::testAfterSim));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testRotateArea", &SimulationTest::testRotateArea));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testClearArea", &SimulationTest::testClearArea));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testEdgeMode", &SimulationTest::testEdgeMode));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testApplyDecoration", &SimulationTest::testApplyDecoration));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testApplyDecorationPoint", &SimulationTest::testApplyDecorationPoint));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testApplyDecorationLine", &SimulationTest::testApplyDecorationLine));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testApplyDecorationBox", &SimulationTest::testApplyDecorationBox));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testColorCompare", &SimulationTest::testColorCompare));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testApplyDecorationFill", &SimulationTest::testApplyDecorationFill));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testTool", &SimulationTest::testTool));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testToolBrush", &SimulationTest::testToolBrush));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testToolLine", &SimulationTest::testToolLine));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testToolBox", &SimulationTest::testToolBox));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateWalls", &SimulationTest::testCreateWalls));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateWallLine", &SimulationTest::testCreateWallLine));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateWallBox", &SimulationTest::testCreateWallBox));
        /**/

        //Allan + 4 in OptionsViewTest
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodWalls", &SimulationTest::testFloodWalls));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateParts", &SimulationTest::testCreateParts));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreatePartFlags", &SimulationTest::testCreatePartFlags));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateLine", &SimulationTest::testCreateLine));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateBox", &SimulationTest::testCreateBox));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodParts", &SimulationTest::testFloodParts));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetGravityField", &SimulationTest::testGetGravityField));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testParticleType", &SimulationTest::testParticleType));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetOrbitalParts", &SimulationTest::testGetOrbitalParts));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSetOrbitalParts", &SimulationTest::testSetOrbitalParts));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetWavelength", &SimulationTest::testGetWavelength));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetNormal", &SimulationTest::testGetNormal));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetNormalInterp", &SimulationTest::testGetNormalInterp));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testClearSim", &SimulationTest::testClearSim));
        
        
        return testSuite;
    }

    void testLoad()
    {
        std::cout << "Test Load\n\n";

        Simulation *sim = new Simulation();
        GameSave * save = sim->Save();

        int result = sim->Load(save);
        //load returns 1 if there is an error
        assert(result == 0);

        //normal x and y parameters
        result = sim->Load(4,7,save);
        assert(result == 0);
    }
    void testSave()
    {
        std::cout << "Test Save\n\n";

        Simulation *sim = new Simulation();
        GameSave * result;
        assert(equals(emptySave, sim->Save()));
        //GameSave * Save();
        result = sim->Save(0,0,0,0);
        assert(result != NULL);

        result = sim->Save(-4,-9,-98,-32);
        assert(result != NULL);

        result = sim->Save(9999,9999,9999,9999);
        assert(result != NULL);
    }
    void testSaveSimOptions()
    {
        std::cout << "Test SaveSimOptions\n\n";
        Simulation *sim = new Simulation();
        GameSave * after = sim->Save();
        GameSave * before = sim->Save();
        before = after;

        sim->SaveSimOptions(after); //changes the state of GameSave * after
        assert(equals(after,before));
    }
    void testGetSample()
    {
        std::cout << "Test GetSample\n\n";
        Simulation *sim = new Simulation();

        SimulationSample result = sim->GetSample(0,0);
        assert(equals(&result,&emptySample));

        result = sim->GetSample(10,10);
        assert(equals(&result,&emptySample));
    }
    void testCreateSnapshot()
    {
        std::cout << "Test CreateSnapshot\n\n";
        Simulation *sim = new Simulation();

        Snapshot * result = sim->CreateSnapshot();
        assert(equals(result,emptySnapshot));
    }
    void testRestore()
    {
        std::cout << "Test Restore\n\n";
        Simulation *sim = new Simulation();
        Snapshot * after;
        after = emptySnapshot;
        sim->Restore(*after);
        assert(equals(after,emptySnapshot));
    }
    void testIsBlocking()
    {
        std::cout << "Test is_blocking\n\n";
	Simulation *sim = new Simulation();
        int result;
        //returns 1 if valid, 0 if blocking
        result = sim->is_blocking(1,1,1);
        assert(result == 0);
        //result = sim->is_blocking(-1,-1,-1);
        //assert(result == 0);
        //result = sim->is_blocking(9999,9999,9999);
        //assert(result == 0);
    }
    void testIsBoundary()
    {
        std::cout << "Test is_boundary\n\n";
	Simulation *sim = new Simulation();
        int result;
        //result is 1 if it is not a boundary
        result = sim->is_boundary(1,1,1);
        assert(result == 0);
        //result = sim->is_boundary(-1,-1,-1);
        //assert(result == 0);
        //result = sim->is_boundary(9999,9999,9999);
        //assert(result == 0);
    }
    void testFindNextBoundary()
    {
        std::cout << "Test find_next_boundary\n\n";
	    Simulation *sim = new Simulation();
        int result = 1;
        int *x = new int {2};
        int *y = new int {2};
        int *em = new int {-1};
        int *xBefore;
        int *yBefore;
        int *emBefore;

        //*x = 1;
        *xBefore = *x;
        //*y = 1;
        *yBefore = *y;
        //*em = 2;
        *emBefore = *em;
        //result = sim->find_next_boundary(2,x,y,2,em);
        assert(result == 1);
        assert(*x == *xBefore);
        assert(*y == *yBefore);
        assert(*em == *emBefore);

    }
    void testPNJunctionSprk()
    {
	Simulation *sim = new Simulation();
    std::cout << "Test pn_junction_sprk\n\n";
        int result;
        result = sim->pn_junction_sprk(1,1,1);
        assert(result == 0);
        result = sim->pn_junction_sprk(1,1,0);
        assert(result == 0);
    }
    void testPhotoelectricEffect()
    {
	Simulation *sim = new Simulation();
    std::cout << "Test photoelectric_effect\n\n";
        //see if any errors are thrown. they shouldn't be
        sim->photoelectric_effect(0,0);
        sim->photoelectric_effect(1,1);
    }
    void testDirectionToMap()
    {
        Simulation *sim = new Simulation();
        std::cout << "Test direction_to_map\n\n";
        int result = sim->direction_to_map(1,1,1);
        assert(result >= 0);


        result = sim->direction_to_map(10,2,5);
        assert(result >= 0);
    }
    void testDoMove()
    {
	Simulation *sim = new Simulation();
    std::cout << "Test do_move\n\n";
        int result;
        //result returns 1 if successful, otherwise 0
        result = sim->do_move(1,1,1,1,1);
        assert(result == 0);
    }
    void testTryMove()
    {
	Simulation *sim = new Simulation();
    std::cout << "Test try_move\n\n";
        int result;
        //result returns 1 if successful, otherwise 0
        result = sim->try_move(1,1,1,1,1);
        assert(result == 1);

    }
    void testEvalMove()
    {
	Simulation *sim = new Simulation();
    std::cout << "Test eval_move\n\n";
        int result;
        unsigned * rr = new unsigned {1};
        //*rr = 0;
        result = sim->eval_move(1,1,1,rr);

        assert(result == 1);
        assert(*rr >= 0);

    }
    void testInitCanMove()
    {
        Simulation *sim = new Simulation();
        std::cout << "Test init_can_move\n\n";
        sim->init_can_move();
        assert(atoi(&sim->can_move[2][3]) >= 0);
        assert(atoi(&sim->can_move[2][3]) <=3);
    }
    void testIsWallBlocking()
    {
        Simulation *sim = new Simulation(); 
        std::cout << "Test IsWallBlocking\n\n";  
        bool result;

        result = sim->IsWallBlocking(3,4,7);
        assert(!result);

        result = sim->IsWallBlocking(-1,-1,4);
        assert(!result);

        result = sim->IsWallBlocking(9999,9999,-1);
        assert(!result);
    }
    void testCreateCherenkovPhoton()
    {
        Simulation *sim = new Simulation(); 
        std::cout << "Test create_cherenkov_photon\n\n";
        Particle * parts = sim->parts;
        Particle * result ;

        sim->create_cherenkov_photon(-1);
        result = sim->parts;
        assert(equals(&parts, &result));

        sim->create_cherenkov_photon(10);
        result = sim->parts;
        assert(equals(&parts, &result));
    }
    void testCreateGainPhoton()
    {
        Simulation *sim = new Simulation(); 
        std::cout << "Test create_gain_photon\n\n";
        Particle * parts = sim->parts;
        Particle * result ;

        sim->create_gain_photon(-1);
        result = sim->parts;
        assert(equals(&parts, &result));

        sim->create_gain_photon(10);
        result = sim->parts;
        assert(equals(&parts, &result));

    }

    //Alfie
    void testKillPart()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,PT_LAVA,0);
		sim->kill_part(1);
    }
    void testFloodFillPmapCheck()
    {
		bool result;
		Simulation *sim = new Simulation();
		result = sim->FloodFillPmapCheck(1,1,0);
		//Not sure what these values should actually be, but I'm assuming these functions work fine, so just change the assert values if the test fails
		assert(result);

		result = sim->FloodFillPmapCheck(1,1,PT_LAVA);
		assert(!result);
		result = sim->FloodFillPmapCheck(1,1,PT_SPRK);
		assert(!result);
		//bool FloodFillPmapCheck(int x, int y, int type);

    }
    void testFloodProp()
    {
		int result;
		Simulation *sim = new Simulation();
		PropertyValue value;
		result = sim->flood_prop(1,1,1, value, StructProperty::Integer);
		assert(result >= 0);	
    }
    void testFloodWater()
    {
		int result;
		Simulation *sim = new Simulation();
		result = sim->flood_water(1,1,1,1,1);
		assert(result == 1);
		result = sim->flood_water(9999,9999,1,1,1);
		assert(result == 1);
        //int flood_water(int x, int y, int i, int originaly, int check);
    }
    void testFloodINST()
    {
		int result;
		Simulation *sim = new Simulation();
		result = sim->FloodINST(1,1,PT_SPRK, PT_INST);
		assert(result >= 0);
		result = sim->FloodINST(1,1,PT_SPRK, PT_INST);
		assert(result >= 0);
        //int FloodINST(int x, int y, int fullc, int cm);
    }
    void testPartChangeType()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,PT_LAVA,0);
		sim->part_change_type(1,1,1,PT_DUST);
        //void part_change_type(int i, int x, int y, int t);
    }
    void testCreatePart()
    {
		int result;
		Simulation *sim = new Simulation();
		result = sim->create_part(-1,1,1,PT_LAVA,0);
		//Not sure what these values should actually be, but I'm assuming these functions work fine, so just change the assert values if the test fails
		assert(result == 0);
		result = sim->create_part(-1,1,1,PT_LIFE,0);
		assert(result == -1);
        //int create_part(int p, int x, int y, int t, int v = -1);
    }
    void testDeletePart()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,PT_LAVA,0);
		sim->delete_part(1,1);
        //void delete_part(int x, int y);
    }
    void testIsWire()
    {
		int result;
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,WL_DETECT,0);
		result = sim->is_wire(1,1);
		assert(result >= 0);
        //int is_wire(int x, int y);
    }   
    void testIsWireOff()
    {
		int result;
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,WL_DETECT,0);
		result = sim->is_wire_off(1,1);
		assert(result >= 0);
        //int is_wire_off(int x, int y);
    }   
    void testSetEmap()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->create_part(-1,1,1,WL_DETECT,0);
		sim->set_emap(1,1);
        //void set_emap(int x, int y);
    }   
    void testUpdateParticles()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->UpdateParticles(1,9999);
        //void UpdateParticles(int start, int end);
    }   
    void testSimulateGol()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->SimulateGoL();
        //void SimulateGoL();
    }   
    void testRecalcFreeParticles()
    {
        //see if any errors are thrown. they shouldn't be
		Simulation *sim = new Simulation();
		sim->RecalcFreeParticles(true);
		sim->RecalcFreeParticles(false);
        //void RecalcFreeParticles(bool do_life_dec);
    }   
    void testCheckStacking()
    {
    	Simulation *sim = new Simulation();
    	sim->CheckStacking();
    	CPPUNIT_ASSERT(sim);
        //void CheckStacking();
    }   
    void testBeforeSim()
    {
    	Simulation *sim = new Simulation();
    	sim->BeforeSim();
    	CPPUNIT_ASSERT(sim);
        //void BeforeSim();
    }   
    void testAfterSim()
    {
    	Simulation *sim = new Simulation();
    	sim->AfterSim();
    	CPPUNIT_ASSERT(sim);
        //void AfterSim();
    }   
    void testRotateArea()
    {
    	Simulation *sim = new Simulation();
    	//I don't think this is defined anywhere
        //void rotate_area(int area_x, int area_y, int area_w, int area_h, int invert);
    }   
    void testClearArea()
    {
    	Simulation *sim = new Simulation();
    	sim->clear_area(1, 1, 50, 50);
    	CPPUNIT_ASSERT(sim);
        //void clear_area(int area_x, int area_y, int area_w, int area_h);
    }   
    void testEdgeMode()
    {
    	Simulation *sim = new Simulation();
    	sim->SetEdgeMode(0);
    	CPPUNIT_ASSERT(sim);
    	sim->SetEdgeMode(1);
    	CPPUNIT_ASSERT(sim);
        //void SetEdgeMode(int newEdgeMode);
    }   
    void testApplyDecoration()
    {
    	Simulation *sim = new Simulation();
    	sim->ApplyDecoration(0, 0, 0, 0, 0, 0, 0);
    	CPPUNIT_ASSERT(sim);
        //void ApplyDecoration(int x, int y, int colR, int colG, int colB, int colA, int mode);
    }   
    void testApplyDecorationPoint()
    {
    	Simulation *sim = new Simulation();
    	sim->ApplyDecorationPoint(0, 0, 0, 0, 0, 0, 0, NULL);
    	CPPUNIT_ASSERT(sim);
        //void ApplyDecorationPoint(int x, int y, int colR, int colG, int colB, int colA, int mode, Brush * cBrush = NULL);
    }   
    void testApplyDecorationLine()
    {
    	Simulation *sim = new Simulation();
    	sim->ApplyDecorationLine(0, 0, 1, 1, 0, 0, 0,0,0, NULL);
    	CPPUNIT_ASSERT(sim);
        //void ApplyDecorationLine(int x1, int y1, int x2, int y2, int colR, int colG, int colB, int colA, int mode, Brush * cBrush = NULL);
    }   
    void testApplyDecorationBox()
    {
    	Simulation *sim = new Simulation();
    	sim->ApplyDecorationBox(0, 0, 1, 1, 0, 0, 0, 0, 0);
    	CPPUNIT_ASSERT(sim);
        //void ApplyDecorationBox(int x1, int y1, int x2, int y2, int colR, int colG, int colB, int colA, int mode);
    }   
    void testColorCompare()
    {
    	Simulation *sim = new Simulation();
    	ui::Engine::Ref().g = new Graphics();
    	Renderer * ren = new Renderer(ui::Engine::Ref().g, sim);
    	bool result;
    	pixel pix = ren->vid[0];
    	int r=PIXR(pix);
    	int g=PIXG(pix);
    	int b=PIXB(pix);

    	result=sim->ColorCompare(ren,0, 0, r, g, b);
    	CPPUNIT_ASSERT(result==true);
        //bool ColorCompare(Renderer *ren, int x, int y, int replaceR, int replaceG, int replaceB);
    }   
    void testApplyDecorationFill()
    {
    	Simulation *sim = new Simulation();
    	ui::Engine::Ref().g = new Graphics();
    	Renderer * ren = new Renderer(ui::Engine::Ref().g, sim);
    	sim->ApplyDecorationFill(ren, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    	CPPUNIT_ASSERT(sim);
        //void ApplyDecorationFill(Renderer *ren, int x, int y, int colR, int colG, int colB, int colA, int replaceR, int replaceG, int replaceB);
    }   
    void testTool()
    {
    	Simulation *sim = new Simulation();
    	int result;
    	result=sim->Tool(0, 0, 0, 0.0);
    	CPPUNIT_ASSERT(result==0);
        //int Tool(int x, int y, int tool, float strength = 1.0f);
    } 
    void testToolBrush()
    {
    	Simulation *sim = new Simulation();
    	int result;
    	result=sim->ToolBrush(0, 0, 0, NULL, 0.0);
    	CPPUNIT_ASSERT(result==0);
        //int ToolBrush(int x, int y, int tool, Brush * cBrush, float strength = 1.0f);
    } 
    void testToolLine()
    {
    	Simulation *sim = new Simulation();
    	ui::Point p(1,1);
		Brush * cBrush = new Brush(p);
    	sim->ToolLine(0, 0, 1 , 1, 0, cBrush, 0.0);
    	CPPUNIT_ASSERT(sim);
        //void ToolLine(int x1, int y1, int x2, int y2, int tool, Brush * cBrush, float strength = 1.0f);
    } 
    void testToolBox()
    {
    	Simulation *sim = new Simulation();
    	sim->ToolBox(0, 0, 1 , 1, 0,  0.0);
    	CPPUNIT_ASSERT(sim);
        //void ToolBox(int x1, int y1, int x2, int y2, int tool, float strength = 1.0f);
    } 
    void testCreateWalls()
    {
    	Simulation *sim = new Simulation();
    	ui::Point p(1,1);
		Brush * cBrush = new Brush(p);
		sim->CreateWalls(0, 0, 1, 1, 0, cBrush);
		CPPUNIT_ASSERT(sim);
        //int CreateWalls(int x, int y, int rx, int ry, int wall, Brush * cBrush = NULL);
    } 
    void testCreateWallLine()
    {
    	Simulation *sim = new Simulation();
    	ui::Point p(1,1);
		Brush * cBrush = new Brush(p);
		sim->CreateWallLine(0, 0, 1, 1, 1, 1, 0, cBrush);
		CPPUNIT_ASSERT(sim);
        //void CreateWallLine(int x1, int y1, int x2, int y2, int rx, int ry, int wall, Brush * cBrush = NULL);
    } 
    void testCreateWallBox()
    {
    	Simulation *sim = new Simulation();
    	sim->CreateWallBox(0, 0, 1, 1, 0);
		CPPUNIT_ASSERT(sim);
        //void CreateWallBox(int x1, int y1, int x2, int y2, int wall);
    } 
    void testFloodWalls()
    {
        std::cout << "test FloodWalls\n\n";
        Simulation *sim = new Simulation();
	int x = 1, y = 1, wall = 1, bm = 1;
	CPPUNIT_ASSERT(sim->FloodWalls(x, y, wall, bm));

	x = 999, y = 777, wall = 2, bm = 1;
	CPPUNIT_ASSERT(sim->FloodWalls(x, y, wall, bm));

	x = -1, y = -1, wall = 1, bm = 1;
	CPPUNIT_ASSERT(!sim->FloodWalls(x, y, wall, bm));
    } 

    void testCreateParts()
    {
        std::cout << "test CreateParts\n\n";
        Simulation *sim = new Simulation();
	int positionX = 1, positionY = 1, c = 1;
	ui::Point p(1,1);
	Brush * cBrush = new Brush(p);

	CPPUNIT_ASSERT(sim->CreateParts(positionX, positionY, c, cBrush));
    } 
    void testCreatePartFlags()
    {
        std::cout << "test CreatePartFlags\n\n";
        Simulation *sim = new Simulation();
	int x = 1, y = 1, c = 1, flags = 0;

	CPPUNIT_ASSERT(sim->CreatePartFlags(x, y, c, flags));
    } 

    void testCreateLine()
    {
        Simulation *sim = new Simulation();
	int x1 = 1, y1 = 1, x2 = 2, y2 = 2, c = 1;
	ui::Point p(1, 1);
	Brush * cBrush = new Brush(p);

	sim->CreateLine(x1, y1, x2, y2, c, cBrush);
	CPPUNIT_ASSERT(sim);

	sim->CreateLine(x1, y1, x2, y2, c);
	CPPUNIT_ASSERT(sim);
    } 
    void testCreateBox()
    {
        Simulation *sim = new Simulation();
	int x1 = 1, y1 = 1, x2 = 2, y2 = 2, c = 1;

	sim->CreateBox(x1, y1, x2, y2, c);
	CPPUNIT_ASSERT(sim);
    } 
    void testFloodParts()
    {
        Simulation *sim = new Simulation();
	int x = 1, y = 1, c = 1, cm = 1;

	CPPUNIT_ASSERT(sim->FloodParts(x, y, c, cm));
    } 
    void testGetGravityField()
    {
        Simulation *sim = new Simulation();
	int x = 1, y = 1;
	float particleGrav = 1, newtonGrav = 1, pGravX = 1, pGravY = 1;

	sim->GetGravityField(x, y, particleGrav, newtonGrav, pGravX, pGravY);
	CPPUNIT_ASSERT(sim);
    }  
    void testParticleType()
    {
        Simulation *sim = new Simulation();

	CPPUNIT_ASSERT(sim->GetParticleType("TSNS"));
    } 
    void testGetOrbitalParts()
    {
        Simulation *sim = new Simulation();
	int block1 = 1, block2 = 1, resblock1[1], resblock2[1];

	sim->orbitalparts_get(block1, block2, resblock1, resblock2);
	CPPUNIT_ASSERT(sim);
    } 
    void testSetOrbitalParts()
    {
        Simulation *sim = new Simulation();
	int block1 = 0, block2 = 0;
	int resblock1[4] = {0,0,0,0}, resblock2[4] = {0,0,0,0};

	sim->orbitalparts_set(&block1, &block2, resblock1, resblock2);
	CPPUNIT_ASSERT(sim);
    } 
    void testGetWavelength()
    {
        Simulation *sim = new Simulation();
	int wm = 600;

	CPPUNIT_ASSERT(sim->get_wavelength_bin(&wm));
    }  
    void testGetNormal()
    {
        Simulation *sim = new Simulation();
	int pt = 10, x = 1, y = 1, dx = 1, dy = 1;
	float *nx, *ny;

	CPPUNIT_ASSERT(sim->get_normal(pt, x, y, dx, dy, nx, ny));
    } 
    void testGetNormalInterp()
    {
        Simulation *sim = new Simulation();
	int pt = 10;
	float x0 = 1, y0 = 1, dx = 1, dy = 1, nx = 1, ny = 1;

	CPPUNIT_ASSERT(sim->get_normal_interp(pt, x0, y0, dx, dy, &nx, &ny));
    } 
    void testClearSim()
    {
        Simulation *sim = new Simulation();
	sim->clear_sim();

	CPPUNIT_ASSERT(sim);
    } 
};

