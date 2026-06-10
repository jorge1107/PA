#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica {
public:
    // Destrutor virtual é essencial para não vazar memória nas subclasses
    virtual ~FiguraGeometrica() {}
    
    // Método puramente virtual que obriga as filhas a implementarem
    virtual void draw(Sculptor &t) = 0;
};

#endif