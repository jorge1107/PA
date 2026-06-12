#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figura_geometrica.h"

class CutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere() {}
    void draw(Sculptor &t);
};
#endif