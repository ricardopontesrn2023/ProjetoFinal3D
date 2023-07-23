#include "PutVoxel.h"
#include <iostream>

PutVoxel::PutVoxel(int x0, int y0, int z0, float r, float g, float b, float a)
{
    this->x = x0;
    this->y = y0;
    this->z = z0;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutVoxel::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    s.putVoxel(x, y, z);
}