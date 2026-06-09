#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <string>

// Estrutura do Voxel
struct Voxel {
    float r, g, b; // Cores (Red, Green, Blue)
    float a;       // Transparência (Alpha)
    bool show;     // Incluído (true) ou não (false)
};

class Sculptor {
private:
    Voxel ***v;       // Matriz 3D
    int nx, ny, nz;   // Dimensões em X, Y e Z
    float r, g, b, a; // Cor e transparência atuais de desenho
public:
    // Construtor
    Sculptor(int _nx, int _ny, int _nz);
    // Destrutor
    ~Sculptor();
    
    // Define a cor atual do desenho
    void setColor(float r, float g, float b, float a);
    
    // Ativa e desativa um único voxel
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    
    // Cria e remove uma caixa (paralelepípedo)
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    
    // Cria e remove uma esfera
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    
    // Cria e remove um elipsoide
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    
    // Exporta a escultura para o formato .OFF
    void writeOFF(const std::string filename);
};

#endif // SCULPTOR_H