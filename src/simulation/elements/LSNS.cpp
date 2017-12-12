#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_LSNS PT_LSNS 185
Element_LSNS::Element_LSNS()
{
	Identifier = "DEFAULT_PT_LSNS";
 	Name = "LSNS";
 	Colour = PIXPACK(0x336699);
 	MenuVisible = 1;
 	MenuSection = SC_SENSOR;
 	Enabled = 1;

 	Advection = 0.0f;
 	AirDrag = 0.00f * CFDS;
 	AirLoss = 0.96f;
 	Loss = 0.00f;
 	Collision = 0.0f;
 	Gravity = 0.0f;
 	Diffusion = 0.00f;
 	HotAir = 0.000f	* CFDS;
 	Falldown = 0;

 	Flammable = 0;
 	Explosive = 0;
 	Meltable = 0;
 	Hardness = 1;

 	Weight = 100;

 	Temperature = 4.0f + 273.15f;
 	HeatConduct = 0;
 	Description = "Life sensor, creates a spark when there's a nearby particle with a life higher than its temperature.";

 	Properties = TYPE_SOLID;

 	LowPressure = IPL;
 	LowPressureTransition = NT;
 	HighPressure = IPH;
 	HighPressureTransition = NT;
 	LowTemperature = ITL;
 	LowTemperatureTransition = NT;
 	HighTemperature = ITH;
 	HighTemperatureTransition = NT;

 	Update = &Element_LSNS::update;
}

//#TPT-Directive ElementHeader Element_LSNS static int update(UPDATE_FUNC_ARGS)
int Element_LSNS::update(UPDATE_FUNC_ARGS)
{
    Element_GENS::update(sim, i, x, y, surround_space, nt, parts, pmap);
	return 0;
}


Element_LSNS::~Element_LSNS() {}
