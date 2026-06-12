#ifndef VOXEL_H
#define VOXEL_H

struct Voxel {
    float r, g, b; // Cores [0, 1]
    float a;       // Transparência [0, 1]
    bool show;     // Incluído ou não
};

#endif