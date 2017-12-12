#include "simulation/Elements.h" 
//#TPT-Directive ElementClass Element_GENS PT_GENS 185 
Element_GENS::Element_GENS() 
{} 
 
//#TPT-Directive ElementHeader Element_GENS static int update(UPDATE_FUNC_ARGS) 
int Element_GENS::update(UPDATE_FUNC_ARGS) 
{ 
    int r, rx, ry, rt, rd = parts[i].tmp2; 
    if (rd > 25) parts[i].tmp2 = rd = 25; 
 
    for (rx=-rd; rx<rd+1; rx++) 
        for (ry=-rd; ry<rd+1; ry++) 
            if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES && (rx || ry)) 
            { 
                r = pmap[y+ry][x+rx]; 
                if(!r) 
                    r = sim->photons[y+ry][x+rx]; 
                if(!r) 
                    continue; 
                if (parts[r>>8].life > parts[i].temp-273.15) 
                    parts[i].life = 1; 
            } 
 
    if (parts[i].life) 
    { 
        parts[i].life = 0; 
        for (rx=-2; rx<3; rx++) 
            for (ry=-2; ry<3; ry++) 
                if (BOUNDS_CHECK && (rx || ry)) 
                { 
                    r = pmap[y+ry][x+rx]; 
                    if (!r) 
                        continue; 
                    rt = r&0xFF; 
                    if (sim->parts_avg(i,r>>8,PT_INSL) != PT_INSL) 
                    { 
                        if ((sim->elements[rt].Properties&PROP_CONDUCTS) && !(rt==PT_WATR||rt==PT_SLTW||rt==PT_NTCT||rt==PT_PTCT||rt==PT_INWR) && parts[r>>8].life==0) 
                        { 
                            parts[r>>8].life = 4; 
                            parts[r>>8].ctype = rt; 
                            sim->part_change_type(r>>8,x+rx,y+ry,PT_SPRK); 
                        } 
                    } 
                } 
    } 
    return 0; 
 
} 
 
 
Element_GENS::~Element_GENS() {} 
