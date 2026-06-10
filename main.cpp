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

    escultura.putBox(1, 3, 2 ,98, 24, 26);
    escultura.putBox(24, 26, 2 ,98, 1, 3);
    escultura.putBox(47, 49, 2 ,98, 24, 26);
    escultura.putBox(24, 26, 2 ,98, 47, 49);

    escultura.setColor(1.0, 0.0, 0.0, 1.0);
    escultura.putSphere(25, 63, 25, 10);
    escultura.putVoxel(25, 2, 25);

    escultura.cutBox(26, 50, 0, 100, 0, 24);

    escultura.writeOFF("saida.off");
    return 0;
}

//Sculptor
//setColor
//putEllipsoid
//cutEllipsoid
//cutVoxel
//putBox
//putSphere
//cutBox