#include "sculptor.h"
#include <iostream>

int main() {
    Sculptor escultura(51, 100, 51);

    escultura.setColor(1.0, 1.0, 1.0, 0.0);
    escultura.putEllipsoid(25, 99, 25, 20, 50, 20);
    escultura.cutEllipsoid(25, 99, 25, 18, 46, 18);
    escultura.putEllipsoid(25, 0, 25, 20, 50, 20);
    escultura.cutEllipsoid(25, 0, 25, 18, 46, 18);

    escultura.setColor(0.59, 0.29, 0.0, 1.0);
    escultura.putEllipsoid(25, 1, 25, 25, 1, 25);
    escultura.putEllipsoid(25, 0, 25, 25, 1, 25);
    escultura.cutVoxel(25, 2, 25);
    escultura.putEllipsoid(25, 99, 25, 25, 1, 25);
    escultura.putEllipsoid(25, 98, 25, 25, 1, 25);
    escultura.cutVoxel(25, 97, 25);

    escultura.writeOFF("saida.off");
    return 0;
}