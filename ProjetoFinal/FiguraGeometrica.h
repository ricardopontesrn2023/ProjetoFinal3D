/* Observação: O método virtual void draw recebe, 
como parâmetro em nosso código, um objeto da classe Sculptor.
*/
#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Sculptor.h"

class FiguraGeometrica // superclasse, todas as outras irão herdar ela
{
    protected:
        float r, g, b, a; // irá armazenar as cores que estão sendo trabalhadas atualmente
    public:
        FiguraGeometrica(){}
        virtual ~FiguraGeometrica(){}
        virtual void draw(Sculptor &s)=0; // metodo virtual puro, aponta para o metodo draw das outras classes
};

#endif // FIGURAGEOMETRICA_H