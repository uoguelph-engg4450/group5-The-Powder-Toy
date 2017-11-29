#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"


#include <assert.h>
#include "Simulation.h"
#include "Sample.h"

class SimulationTest : public CppUnit::TestSuite
{
private:
    GameSave * emptySave;
    Snapshot * emptySnapshot;
    SimulationSample  emptySample;
    Simulation * simulation;
public:
    void setup()
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
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testLoad", &SimulationTest::testLoad));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSave", &SimulationTest::testSave));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSaveSimOptions", &SimulationTest::testSaveSimOptions));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetSample", &SimulationTest::testGetSample));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateSnapshot", &SimulationTest::testCreateSnapshot));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testRestore", &SimulationTest::testRestore));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsBlocking", &SimulationTest::testIsBlocking));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsBoundary", &SimulationTest::testIsBoundary));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFindNextBoundary", &SimulationTest::testFindNextBoundary));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPNJunctionSprk", &SimulationTest::testPNJunctionSprk));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPhotoelectricEffect", &SimulationTest::testPhotoelectricEffect));


        //someone please look at directionToMap
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDirectionToMap", &SimulationTest::testDirectionToMap));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDoMove", &SimulationTest::testDoMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testTryMove", &SimulationTest::testTryMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testEvalMove", &SimulationTest::testEvalMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testInitCanMove", &SimulationTest::testInitCanMove));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWallBlocking", &SimulationTest::testIsWallBlocking));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateCherenkovPhoton", &SimulationTest::testCreateCherenkovPhoton));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateGainPhoton", &SimulationTest::testCreateGainPhoton));
        


        //Alfie
        /*testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testKillPart", &SimulationTest::testKillPart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodFillPmapCheck", &SimulationTest::testFloodFillPmapCheck));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodProp", &SimulationTest::testFloodProp));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodWater", &SimulationTest::testFloodWater));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodINST", &SimulationTest::testFloodINST));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDetach", &SimulationTest::testDetach));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPartChangeType", &SimulationTest::testPartChangeType));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreatePart", &SimulationTest::testCreatePart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testDeletePart", &SimulationTest::testDeletePart));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testGetSignPos", &SimulationTest::testGetSignPos));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWire", &SimulationTest::testIsWire));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testIsWireOff", &SimulationTest::testIsWireOff));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSetEmap", &SimulationTest::testSetEmap));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testPartsAvg", &SimulationTest::testPartsAvg));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCreateArc", &SimulationTest::testCreateArc));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testUpdateParticles", &SimulationTest::testUpdateParticles));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testSimulateGol", &SimulationTest::testSimulateGol));
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testRecalcFreeParticles", &SimulationTest::testRecalcFreeParticles));
        */

        //Brandon 
        /*testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testCheckStacking", &SimulationTest::testCheckStacking));
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
        */


        //Allan + 4 in OptionsViewTest
        /*testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testFloodWalls", &SimulationTest::testFloodWalls));
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
        testSuite->addTest(new CppUnit::TestCaller <SimulationTest> ("testClearSim", &SimulationTest::testClearSim));*/
        
        return testSuite;
    }

    void testLoad()
    {
        Simulation *sim = new Simulation();
        //load returns 1 if there is an error

        CPPUNIT_ASSERT_EQUAL(sim->Load(emptySave), 0);
        //normal x and y parameters
        CPPUNIT_ASSERT_EQUAL(sim->Load(4,7,emptySave), 0);
        //negative x and y parameters
        CPPUNIT_ASSERT_EQUAL(sim->Load(-4,-7,emptySave), 1);
        //very large x and y parameters
        CPPUNIT_ASSERT_EQUAL(sim->Load(4000,7000,emptySave), 1);
    }
    void testSave()
    {
        Simulation *sim = new Simulation();
        GameSave * result;
        assert(*emptySave == *sim->Save());
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
        Simulation *sim = new Simulation();
        GameSave * after = sim->Save();
        GameSave before = * after;

        sim->SaveSimOptions(after); //changes the state of GameSave * after
        assert(*after != before);
    }
    void testGetSample()
    {
        Simulation *sim = new Simulation();

        SimulationSample result = sim->GetSample(0,0);
        assert(result == emptySnapshot);

        result = sim->GetSample(10,10);
        assert(result != emptySnapshot);

        result = sim->GetSample(-20,-80);
        assert(result != emptySnapshot);

        result = sim->GetSample(9999,9999);
        assert(result != emptySnapshot);
    }
    void testCreateSnapshot()
    {
        Simulation *sim = new Simulation();

        Snapshot * result = sim->CreateSnapshot();
        assert(result != emptySnapshot);
        assert(*result != *emptySnapshot);
    }
    void testRestore()
    {
        Simulation *sim = new Simulation();
        Snapshot * after;
        *after = *emptySnapshot;
        sim->Restore(&after);
        assert(*after == *emptySnapshot);
    }
    void testIsBlocking()
    {
	Simulation *sim = new Simulation();
        int result;
        //returns 1 if valid, 0 if blocking
        result = sim->is_blocking(1,1,1);
        assert(result == 1);
        result = sim->is_blocking(-1,-1,-1);
        assert(result == 0);
        result = sim->is_blocking(9999,9999,9999);
        assert(result == 0);
    }
    void testIsBoundary()
    {
	Simulation *sim = new Simulation();
        int result;
        //result is 1 if it is not a boundary
        result = sim->is_boundary(1,1,1);
        assert(result == 1);
        result = sim->is_boundary(-1,-1,-1);
        assert(result == 0);
        result = sim->is_boundary(9999,9999,9999);
        assert(result == 0);
    }
    void testFindNextBoundary()
    {
	Simulation *sim = new Simulation();
        int result;
        int *x;
        int *y;
        int *em;
        int *xBefore;
        int *yBefore;
        int *emBefore;

        *x = 1;
        *xBefore = *x;
        *y = 1;
        *yBefore = *y;
        *em = 1;
        *emBefore = *em;
        result = sim->find_next_boundary(1,x,y,1,em);
        assert(result == 1);
        assert(*x != *xBefore);
        assert(*y != *yBefore);
        assert(*em != *emBefore);

        //invalid inputs, should return 0 with variables unchanged
        *x = -1;
        *xBefore = *x;
        *y = -1;
        *yBefore = *y;
        *em = -1;
        *emBefore = *em;
        result = sim->find_next_boundary(1,x,y,1,em);
        assert(result == 1);
        assert(*x == *xBefore);
        assert(*y == *yBefore);
        assert(*em == *emBefore);

    }
    void testPNJunctionSprk()
    {
	Simulation *sim = new Simulation();
        int result;
        result = sim->pn_junction_sprk(1,1,1);
        assert(result == 1);
        result = sim->pn_junction_sprk(1,1,0);
        assert(result == 0);
        result = sim->pn_junction_sprk(-1,-1,1);
        assert(result == 0);
    }
    void testPhotoelectricEffect()
    {
	Simulation *sim = new Simulation();
        //see if any errors are thrown. they shouldn't be
        sim->photoelectric_effect(0,0);
        sim->photoelectric_effect(1,1);
        sim->photoelectric_effect(9999,9999);
        sim->photoelectric_effect(-5,-92);
    }
    void testDirectionToMap()
    {
        /*can someone please look at this function? i don't understand the shifts*/
        assert(1);
        //unsigned result;
        //result = direction_to_map();
        //unsigned direction_to_map(float dx, float dy, int t);
    }
    void testDoMove()
    {
	Simulation *sim = new Simulation();
        int result;
        //result returns 1 if successful, otherwise 0
        result = sim->do_move(1,1,1,1,1);
        assert(result == 1);
        result = sim->do_move(-1,1,1,1,1);
        assert(result == 0);
        result = sim->do_move(1,-1,-1,1,1);
        assert(result == 0);
    }
    void testTryMove()
    {
	Simulation *sim = new Simulation();
        int result;
        //result returns 1 if successful, otherwise 0
        result = sim->try_move(1,1,1,1,1);
        assert(result == 1);
        result = sim->try_move(1,-1,-1,1,1);
        assert(result == 0);
        result = sim->try_move(1,1,1,-1,-1);
        assert(result == 0);
        result = sim->try_move(-1,1,1,1,1);
        assert(result == 0); 
    }
    void testEvalMove()
    {
	Simulation *sim = new Simulation();
        int result;
        unsigned * rr;
        *rr = 0;
        result = sim->eval_move(1,1,1,rr);
        assert(result == 1);
        assert(*rr != 0);

        *rr = 0;
        result = sim->eval_move(1,-3,-1,rr);
        assert(result == 0);
        assert(*rr != 0);

        *rr = 0;
        result = sim->eval_move(1,9999,9999,rr);
        assert(result == 0);
        assert(*rr != 0);
    }
    void testInitCanMove()
    {
       //void init_can_move(); 
    }
    void testIsWallBlocking()
    {
        //bool IsWallBlocking(int x, int y, int type);
    }
    void testCreateCherenkovPhoton()
    {
        //void create_cherenkov_photon(int pp);
    }
    void testCreateGainPhoton()
    {
        //void create_gain_photon(int pp);
    }
    void testKillPart()
    {
        //void kill_part(int i);
    }
    void testFloodFillPmapCheck()
    {
        //bool FloodFillPmapCheck(int x, int y, int type);
    }
    void testFloodProp()
    {
        //int flood_prop(int x, int y, size_t propoffset, PropertyValue propvalue, StructProperty::PropertyType proptype);
    }
    void testFloodWater()
    {
        //int flood_water(int x, int y, int i, int originaly, int check);
    }
    void testFloodINST()
    {
        //int FloodINST(int x, int y, int fullc, int cm);
    }
    void testDetach()
    {
        //void detach(int i);
    }
    void testPartChangeType()
    {
        //void part_change_type(int i, int x, int y, int t);
    }
    void testCreatePart()
    {
        //int create_part(int p, int x, int y, int t, int v = -1);
    }
    void testDeletePart()
    {
        //void delete_part(int x, int y);
    }
    void testGetSignPos()
    {
        //void get_sign_pos(int i, int *x0, int *y0, int *w, int *h);
    }
    void testIsWire()
    {
        //int is_wire(int x, int y);
    }   
    void testIsWireOff()
    {
        //int is_wire_off(int x, int y);
    }   
    void testSetEmap()
    {
        //void set_emap(int x, int y);
    }   
    void testPartsAvg()
    {
        //int parts_avg(int ci, int ni, int t);
    }   
    void testCreateArc()
    {
        //void create_arc(int sx, int sy, int dx, int dy, int midpoints, int variance, int type, int flags);
    }   
    void testUpdateParticles()
    {
        //void UpdateParticles(int start, int end);
    }   
    void testSimulateGol()
    {
        //void SimulateGoL();
    }   
    void testRecalcFreeParticles()
    {
        //void RecalcFreeParticles(bool do_life_dec);
    }   
    void testCheckStacking()
    {
        //void CheckStacking();
    }   
    void testBeforeSim()
    {
        //void BeforeSim();
    }   
    void testAfterSim()
    {
        //void AfterSim();
    }   
    void testRotateArea()
    {
        //void rotate_area(int area_x, int area_y, int area_w, int area_h, int invert);
    }   
    void testClearArea()
    {
        //void clear_area(int area_x, int area_y, int area_w, int area_h);
    }   
    void testEdgeMode()
    {
        //void SetEdgeMode(int newEdgeMode);
    }   
    void testApplyDecoration()
    {
        //void ApplyDecoration(int x, int y, int colR, int colG, int colB, int colA, int mode);
    }   
    void testApplyDecorationPoint()
    {
        //void ApplyDecorationPoint(int x, int y, int colR, int colG, int colB, int colA, int mode, Brush * cBrush = NULL);
    }   
    void testApplyDecorationLine()
    {
        //void ApplyDecorationLine(int x1, int y1, int x2, int y2, int colR, int colG, int colB, int colA, int mode, Brush * cBrush = NULL);
    }   
    void testApplyDecorationBox()
    {
        //void ApplyDecorationBox(int x1, int y1, int x2, int y2, int colR, int colG, int colB, int colA, int mode);
    }   
    void testColorCompare()
    {
        //bool ColorCompare(Renderer *ren, int x, int y, int replaceR, int replaceG, int replaceB);
    }   
    void testApplyDecorationFill()
    {
        //void ApplyDecorationFill(Renderer *ren, int x, int y, int colR, int colG, int colB, int colA, int replaceR, int replaceG, int replaceB);
    }   
    void testTool()
    {
        //int Tool(int x, int y, int tool, float strength = 1.0f);
    } 
    void testToolBrush()
    {
        //int ToolBrush(int x, int y, int tool, Brush * cBrush, float strength = 1.0f);
    } 
    void testToolLine()
    {
        //void ToolLine(int x1, int y1, int x2, int y2, int tool, Brush * cBrush, float strength = 1.0f);
    } 
    void testToolBox()
    {
        //void ToolBox(int x1, int y1, int x2, int y2, int tool, float strength = 1.0f);
    } 
    void testCreateWalls()
    {
        //int CreateWalls(int x, int y, int rx, int ry, int wall, Brush * cBrush = NULL);
    } 
    void testCreateWallLine()
    {
        //void CreateWallLine(int x1, int y1, int x2, int y2, int rx, int ry, int wall, Brush * cBrush = NULL);
    } 
    void testCreateWallBox()
    {
        //void CreateWallBox(int x1, int y1, int x2, int y2, int wall);
    } 
    void testFloodWalls()
    {
        //int FloodWalls(int x, int y, int wall, int bm);
    } 
    void testCreateParts()
    {
        //int CreateParts(int positionX, int positionY, int c, Brush * cBrush, int flags = -1);
    } 
    void testCreatePartFlags()
    {
        //int CreatePartFlags(int x, int y, int c, int flags);
    } 
    void testCreateLine()
    {
        //void CreateLine(int x1, int y1, int x2, int y2, int c, Brush * cBrush, int flags = -1);
        //void CreateLine(int x1, int y1, int x2, int y2, int c);
    } 
    void testCreateBox()
    {
        //void CreateBox(int x1, int y1, int x2, int y2, int c, int flags = -1);
    } 
    void testFloodParts()
    {
        //int FloodParts(int x, int y, int c, int cm, int flags = -1);
    } 
    void testGetGravityField()
    {
        //void GetGravityField(int x, int y, float particleGrav, float newtonGrav, float & pGravX, float & pGravY);
    }  
    void testParticleType()
    {
        //int GetParticleType(std::string type);
    } 
    void testGetOrbitalParts()
    {
        //void orbitalparts_get(int block1, int block2, int resblock1[], int resblock2[]);
    } 
    void testSetOrbitalParts()
    {
        // void orbitalparts_set(int *block1, int *block2, int resblock1[], int resblock2[]);
    } 
    void testGetWavelength()
    {
        //int get_wavelength_bin(int *wm);
    }  
    void testGetNormal()
    {
        //int get_normal(int pt, int x, int y, float dx, float dy, float *nx, float *ny);
    } 
    void testGetNormalInterp()
    {
        //int get_normal_interp(int pt, float x0, float y0, float dx, float dy, float *nx, float *ny);
    } 
    void testClearSim()
    {
        //void clear_sim();
    } 
};

