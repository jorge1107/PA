#include "figuras.h"

// --- PUT e CUT VOXEL ---
PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {
    this->x = x; this->y = y; this->z = z;
    this->r = r; this->g = g; this->b = b; this->a = a;
}
void PutVoxel::draw(Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putVoxel(x, y, z);
}

CutVoxel::CutVoxel(int x, int y, int z) {
    this->x = x; this->y = y; this->z = z;
}
void CutVoxel::draw(Sculptor &t) {
    t.cutVoxel(x, y, z);
}

// --- PUT e CUT BOX ---
PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a) {
    this->x0 = x0; this->x1 = x1; this->y0 = y0; this->y1 = y1; this->z0 = z0; this->z1 = z1;
    this->r = r; this->g = g; this->b = b; this->a = a;
}
void PutBox::draw(Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putBox(x0, x1, y0, y1, z0, z1);
}

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    this->x0 = x0; this->x1 = x1; this->y0 = y0; this->y1 = y1; this->z0 = z0; this->z1 = z1;
}
void CutBox::draw(Sculptor &t) {
    t.cutBox(x0, x1, y0, y1, z0, z1);
}

// --- PUT e CUT SPHERE ---
PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) {
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter; this->radius = radius;
    this->r = r; this->g = g; this->b = b; this->a = a;
}
void PutSphere::draw(Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putSphere(xcenter, ycenter, zcenter, radius);
}

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter; this->radius = radius;
}
void CutSphere::draw(Sculptor &t) {
    t.cutSphere(xcenter, ycenter, zcenter, radius);
}

// --- PUT e CUT ELLIPSOID ---
PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a) {
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx = rx; this->ry = ry; this->rz = rz;
    this->r = r; this->g = g; this->b = b; this->a = a;
}
void PutEllipsoid::draw(Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx = rx; this->ry = ry; this->rz = rz;
}
void CutEllipsoid::draw(Sculptor &t) {
    t.cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}