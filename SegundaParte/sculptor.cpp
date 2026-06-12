#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx; ny = _ny; nz = _nz;
    r = 1.0; g = 1.0; b = 1.0; a = 1.0; // Cor padrão: Branco opaco
    
    // Alocação dinâmica da matriz 3D
    v = new Voxel**[nx];//X
    for(int i = 0; i < nx; i++) { //Y
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++) { //Z
            v[i][j] = new Voxel[nz];
            for(int k = 0; k < nz; k++) {
                v[i][j][k].show = false; // Começa vazio
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

Sculptor::~Sculptor() {
    // Libertação da memória alocada
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            delete[] v[i][j]; //Z
        }
        delete[] v[i]; //Y
    }
    delete[] v; //X
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for(int x = x0; x <= x1; x++) {
        for(int y = y0; y <= y1; y++) {
            for(int z = z0; z <= z1; z++) {
                putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for(int x = x0; x <= x1; x++) {
        for(int y = y0; y <= y1; y++) {
            for(int z = z0; z <= z1; z++) {
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    // Equação da esfera: (x - xc)^2 + (y - yc)^2 + (z - zc)^2 <= r^2
    for(int x = 0; x < nx; x++) {
        for(int y = 0; y < ny; y++) {
            for(int z = 0; z < nz; z++) {
                double dist = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);
                if(dist <= pow(radius, 2)) {
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for(int x = 0; x < nx; x++) {
        for(int y = 0; y < ny; y++) {
            for(int z = 0; z < nz; z++) {
                double dist = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);
                if(dist <= pow(radius, 2)) {
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    // Evita divisão por zero
    if (rx == 0 || ry == 0 || rz == 0) return; 

    // Equação do elipsoide: (x-xc)^2/rx^2 + (y-yc)^2/ry^2 + (z-zc)^2/rz^2 <= 1
    for(int x = 0; x < nx; x++) {
        for(int y = 0; y < ny; y++) {
            for(int z = 0; z < nz; z++) {
                double dist = pow((double)(x - xcenter) / rx, 2) + 
                              pow((double)(y - ycenter) / ry, 2) + 
                              pow((double)(z - zcenter) / rz, 2);
                if(dist <= 1.0) {
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    if (rx == 0 || ry == 0 || rz == 0) return;

    for(int x = 0; x < nx; x++) {
        for(int y = 0; y < ny; y++) {
            for(int z = 0; z < nz; z++) {
                double dist = pow((double)(x - xcenter) / rx, 2) + 
                              pow((double)(y - ycenter) / ry, 2) + 
                              pow((double)(z - zcenter) / rz, 2);
                if(dist <= 1.0) {
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout(filename);
    if(!fout.is_open()) {
        std::cerr << "Erro ao criar o arquivo: " << filename << std::endl;
        return;
    }

    int numVoxels = 0;
    // Conta os voxels ativos
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {
                    numVoxels++;
                }
            }
        }
    }

    // Escreve o cabeçalho OFF
    fout << "OFF\n";
    // Vértices, Faces, Arestas (Arestas podem ser 0, depois tentar fórmula de Euler para verificar V + F = A + 2)
    // 1 Voxel = 8 vértices e 6 faces
    fout << 8 * numVoxels << " " << 6 * numVoxels << " 0\n";

    // 1. Escrever coordenadas dos vértices
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {
                    // Centro do voxel em (i, j, k) e os 8 cantos
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" // 0
                         << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" // 1
                         << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" // 2
                         << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" // 3
                         << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n" // 4
                         << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" // 5
                         << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" // 6
                         << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";// 7
                }
            }
        }
    }

    fout << std::fixed << std::setprecision(2);
    // 2. Escrever a constituição das faces e respectivas cores
    int index = 0;
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {
                    float r = v[i][j][k].r;
                    float g = v[i][j][k].g;
                    float b = v[i][j][k].b;
                    float a = v[i][j][k].a;

                    // Formato: <n_vertices_na_face> <v1> <v2> ... <r> <g> <b> <a>
                    fout << "4 " << index + 0 << " " << index + 3 << " " << index + 2 << " " << index + 1 << " " << r << " " << g << " " << b << " " << a << "\n"
                         << "4 " << index + 4 << " " << index + 5 << " " << index + 6 << " " << index + 7 << " " << r << " " << g << " " << b << " " << a << "\n"
                         << "4 " << index + 0 << " " << index + 1 << " " << index + 5 << " " << index + 4 << " " << r << " " << g << " " << b << " " << a << "\n"
                         << "4 " << index + 0 << " " << index + 4 << " " << index + 7 << " " << index + 3 << " " << r << " " << g << " " << b << " " << a << "\n"
                         << "4 " << index + 3 << " " << index + 7 << " " << index + 6 << " " << index + 2 << " " << r << " " << g << " " << b << " " << a << "\n"
                         << "4 " << index + 1 << " " << index + 2 << " " << index + 6 << " " << index + 5 << " " << r << " " << g << " " << b << " " << a << "\n";
                    
                    index += 8; // Passa para os vértices do próximo voxel
                }
            }
        }
    }

    fout.close();
    std::cout << "Arquivo " << filename << " gerado com sucesso!" << std::endl;
}