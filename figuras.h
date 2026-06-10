#ifndef FIGURAS_H
#define FIGURAS_H

#include "figura_geometrica.h"

class PutVoxel : public FiguraGeometrica {
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel() {}
    void draw(Sculptor &t);
};

class CutVoxel : public FiguraGeometrica {
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel() {}
    void draw(Sculptor &t);
};

class PutBox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~PutBox() {}
    void draw(Sculptor &t);
};

class CutBox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox() {}
    void draw(Sculptor &t);
};

class PutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~PutSphere() {}
    void draw(Sculptor &t);
};

class CutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere() {}
    void draw(Sculptor &t);
};

class PutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutEllipsoid() {}
    void draw(Sculptor &t);
};

class CutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid() {}
    void draw(Sculptor &t);
};

#endif