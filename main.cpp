#include "sculptor.h"
#include <iostream>

int main() {
    // Inicializa a matriz 3D com tamanho 50x50x50
    Sculptor escultura(50, 50, 50);

    // Cria uma base grande (Caixa) - Cor: Cinzento
    escultura.setColor(0.5, 0.5, 0.5, 1.0);
    escultura.putBox(0, 49, 0, 9, 0, 49);

    // Corta o centro da base para fazer uma piscina
    escultura.cutBox(5, 44, 5, 9, 5, 44);

    // Cria uma esfera no centro - Cor: Azul
    escultura.setColor(0.0, 0.0, 1.0, 1.0);
    escultura.putSphere(25, 15, 25, 8);

    // Corta o interior da esfera para a tornar oca
    escultura.cutSphere(25, 15, 25, 5);

    // Adiciona um elipsoide a "flutuar" no topo - Cor: Vermelho
    escultura.setColor(1.0, 0.0, 0.0, 1.0);
    escultura.putEllipsoid(25, 35, 25, 15, 5, 10);
    
    // Corta o centro do elipsoide
    escultura.cutEllipsoid(25, 35, 25, 5, 5, 15);

    // Adiciona um pilar central - Cor: Verde
    escultura.setColor(0.0, 1.0, 0.0, 1.0);
    escultura.putBox(22, 28, 10, 30, 22, 28);

    // Exporta a escultura construída
    escultura.writeOFF("saida.off");

    return 0;
}