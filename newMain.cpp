#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "sculptor.h"
#include "figura_geometrica.h"
#include "figuras.h"

int main() {
    // Tenta abrir o arquivo com o roteiro da escultura
    std::ifstream fin("roteiro.txt");
    if(!fin.is_open()){
        std::cerr << "Erro ao abrir o arquivo roteiro.txt!" << std::endl;
        return 1;
    }

    std::vector<FiguraGeometrica*> figuras;
    std::string linha;
    Sculptor *escultor = nullptr;

    // Lê o arquivo linha por linha
    while(std::getline(fin, linha)) {
        std::stringstream ss(linha);
        std::string comando;
        ss >> comando; // Lê a primeira palavra

        if(comando == "dim") {
            int nx, ny, nz;
            ss >> nx >> ny >> nz;
            escultor = new Sculptor(nx, ny, nz);
        }
        else if(comando == "putvoxel") {
            int x, y, z; float r, g, b, a;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }
        else if(comando == "cutvoxel") {
            int x, y, z;
            ss >> x >> y >> z;
            figuras.push_back(new CutVoxel(x, y, z));
        }
        else if(comando == "putbox") {
            int x0, x1, y0, y1, z0, z1; float r, g, b, a;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(comando == "cutbox") {
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(comando == "putsphere") {
            int xc, yc, zc, radius; float r, g, b, a;
            ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(xc, yc, zc, radius, r, g, b, a));
        }
        else if(comando == "cutsphere") {
            int xc, yc, zc, radius;
            ss >> xc >> yc >> zc >> radius;
            figuras.push_back(new CutSphere(xc, yc, zc, radius));
        }
        else if(comando == "putellipsoid") {
            int xc, yc, zc, rx, ry, rz; float r, g, b, a;
            ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
        }
        else if(comando == "cutellipsoid") {
            int xc, yc, zc, rx, ry, rz;
            ss >> xc >> yc >> zc >> rx >> ry >> rz;
            figuras.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
        }
    }

    // Se o escultor foi criado (comando 'dim' foi lido)
    if(escultor != nullptr) {
        // Polimorfismo em ação: 'draw' se comporta de forma diferente para cada tipo
        for(size_t i = 0; i < figuras.size(); i++) {
            figuras[i]->draw(*escultor);
        }
        escultor->writeOFF("saida_avancada.off");
        delete escultor;
    }

    // Libera a memória alocada dinamicamente para as figuras
    for(size_t i = 0; i < figuras.size(); i++) {
        delete figuras[i];
    }

    std::cout << "Arquivo gerado com sucesso via Estruturas Avancadas!" << std::endl;
    return 0;
}