#include "cppunit/TestCase.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestAssert.h"

<<<<<<< HEAD
=======

#include <assert.h>
>>>>>>> aa40ad44f96aa903a13193157517510db8ce6207
#include "Simulation.h"

class SimulationTest : public CppUnit::TestSuite
{
private:
    GameSave * emptySave;
    Snapshot * emptySnapshot;
    SimulationSample * emptySample;
public:
    void setup()
    {
        emptySave = Save();
        emptySnapshot = CreateSnapshot();
        emptySample = GetSample(0,0);
    }

    void tearDown()
    {

    }

    TestSuite * suite()
    {
        TestSuite *testSuite = new TestSuite("SimulationTestSuite");
        //add the tests
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testLoad", &SimulationTestSuite::testLoad));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testSave", &SimulationTestSuite::testSave));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testSaveSimOptions", &SimulationTestSuite::testSaveSimOptions));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetSample", &SimulationTestSuite::testGetSample));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateSnapshot", &SimulationTestSuite::testCreateSnapshot));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testRestore", &SimulationTestSuite::testRestore));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testIsBlocking", &SimulationTestSuite::testIsBlocking));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testIsBoundary", &SimulationTestSuite::testIsBoundary));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFindNextBoundary", &SimulationTestSuite::testFindNextBoundary));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testPNJunctionSprk", &SimulationTestSuite::testPNJunctionSprk));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testPhotoelectricEffect", &SimulationTestSuite::testPhotoelectricEffect));


        //someone please look at directionToMap
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testDirectionToMap", &SimulationTestSuite::testDirectionToMap));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testDoMove", &SimulationTestSuite::testDoMove));
        /*testSuite->addTest(new TestCaller <SimulationTestSuite> ("testTryMove", &SimulationTestSuite::testTryMove));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testEvalMove", &SimulationTestSuite::testEvalMove));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testInitCanMove", &SimulationTestSuite::testInitCanMove));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testIsWallBlocking", &SimulationTestSuite::testIsWallBlocking));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateCherenkovPhoton", &SimulationTestSuite::testCreateCherenkovPhoton));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateGainPhoton", &SimulationTestSuite::testCreateGainPhoton));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testKillPart", &SimulationTestSuite::testKillPart));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodFillPmapCheck", &SimulationTestSuite::testFloodFillPmapCheck));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodProp", &SimulationTestSuite::testFloodProp));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodWater", &SimulationTestSuite::testFloodWater));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodINST", &SimulationTestSuite::testFloodINST));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testDetach", &SimulationTestSuite::testDetach));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testPartChangeType", &SimulationTestSuite::testPartChangeType));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreatePart", &SimulationTestSuite::testCreatePart));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testDeletePart", &SimulationTestSuite::testDeletePart));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetSignPos", &SimulationTestSuite::testGetSignPos));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testIsWire", &SimulationTestSuite::testIsWire));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testIsWireOff", &SimulationTestSuite::testIsWireOff));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testSetEmap", &SimulationTestSuite::testSetEmap));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testPartsAvg", &SimulationTestSuite::testPartsAvg));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateArc", &SimulationTestSuite::testCreateArc));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testUpdateParticles", &SimulationTestSuite::testUpdateParticles));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testSimulateGol", &SimulationTestSuite::testSimulateGol));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testRecalcFreeParticles", &SimulationTestSuite::testRecalcFreeParticles));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCheckStacking", &SimulationTestSuite::testCheckStacking));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testBeforeSim", &SimulationTestSuite::testBeforeSim));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testAfterSim", &SimulationTestSuite::testAfterSim));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testRotateArea", &SimulationTestSuite::testRotateArea));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testClearArea", &SimulationTestSuite::testClearArea));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testEdgeMode", &SimulationTestSuite::testEdgeMode));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testApplyDecoration", &SimulationTestSuite::testApplyDecoration));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testApplyDecorationPoint", &SimulationTestSuite::testApplyDecorationPoint));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testApplyDecorationLine", &SimulationTestSuite::testApplyDecorationLine));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testApplyDecorationBox", &SimulationTestSuite::testApplyDecorationBox));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testColorCompare", &SimulationTestSuite::testColorCompare));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testApplyDecorationFill", &SimulationTestSuite::testApplyDecorationFill));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testTool", &SimulationTestSuite::testTool));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testToolBrush", &SimulationTestSuite::testToolBrush));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testToolLine", &SimulationTestSuite::testToolLine));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testToolBox", &SimulationTestSuite::testToolBox));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateWalls", &SimulationTestSuite::testCreateWalls));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateWallLine", &SimulationTestSuite::testCreateWallLine));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateWallBox", &SimulationTestSuite::testCreateWallBox));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodWalls", &SimulationTestSuite::testFloodWalls));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateParts", &SimulationTestSuite::testCreateParts));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreatePartFlags", &SimulationTestSuite::testCreatePartFlags));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateLine", &SimulationTestSuite::testCreateLine));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testCreateBox", &SimulationTestSuite::testCreateBox));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testFloodParts", &SimulationTestSuite::testFloodParts));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetGravityField", &SimulationTestSuite::testGetGravityField));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testParticleType", &SimulationTestSuite::testParticleType));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetOrbitalParts", &SimulationTestSuite::testGetOrbitalParts));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testSetOrbitalParts", &SimulationTestSuite::testSetOrbitalParts));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetWavelength", &SimulationTestSuite::testGetWavelength));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetNormal", &SimulationTestSuite::testGetNormal));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testGetNormalInterp", &SimulationTestSuite::testGetNormalInterp));
        testSuite->addTest(new TestCaller <SimulationTestSuite> ("testClearSim", &SimulationTestSuite::testClearSim));*/
        
        return testSuite;
    }

    void testLoad()
    {
        //load returns 1 if there is an error

        assertEquals(Load(emptySave), 0);
        //normal x and y parameters
        assertEquals(Load(4,7,emptySave), 0);
        //negative x and y parameters
        assertEquals(Load(-4,-7,emptySave), 1);
        //very large x and y parameters
        assertEquals(Load(4000,7000,emptySave), 1);
    }
    void testSave()
    {
        GameSave * result;
        assert(*emptySave == *Save());
        //GameSave * Save();
        result = Save(0,0,0,0);
        assert(result != NULL);

        result = Save(-4,-9,-98,-32);
        assert(result != NULL);

        result = Save(9999,9999,9999,9999);
        assert(result != NULL);
    }
    void testSaveSimOptions()
    {
        GameSave * after = Save();
        GameSave before = * after;

        SaveSimOptions(after); //changes the state of GameSave * after
        assert(*after != before);
    }
    void testGetSample()
    {
        SimulationSample result = GetSample(0,0);
        assert(result == emptySnapshot);

        SimulationSample result = GetSample(10,10);
        assert(result != emptySnapshot);

        SimulationSample result = GetSample(-20,-80);
        assert(result != emptySnapshot);

        SimulationSample result = GetSample(9999,9999);
        assert(result != emptySnapshot);
    }
    void testCreateSnapshot()
    {
        Snapshot * result = CreateSnapshot();
        assert(result != emptySnapshot);
        assert(*result != *emptySnapshot);
    }
    void testRestore()
    {
        Snapshot * after;
        *after = *emptySnapshot;
        Restore(&after);
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
<<<<<<< HEAD
};
=======
}
>>>>>>> aa40ad44f96aa903a13193157517510db8ce6207
