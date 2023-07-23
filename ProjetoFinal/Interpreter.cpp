#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "Sculptor.h"

using namespace std;

Interpreter::Interpreter()
{
    
}

vector<FiguraGeometrica *> Interpreter::analise(string filename){
    ifstream fin; 
    stringstream ss; 
    string s, token; 
    vector<FiguraGeometrica *> figs; 

    fin.open(filename.c_str()); // abrir o arquivo

    if (!fin.is_open()){ // verifica se houve erro na abertura do arquivo, se não estiver aberto ele notifica e encerra o processo
        cout << "Erro ao abrir o arquivo\n";
        exit(0);
    }

    cout << "Arquivo aberto!\n";

    while(fin.good()){ 
        getline(fin, s);
        if(fin.good()){ 
            ss.clear(); 
            ss.str(s); 
            ss >> token; 
            if(ss.good()){ 
                
                if(token.compare("dim") == 0){
                    ss >> dx >> dy >> dz;
                }


                else if(token.compare("putVoxel") == 0){
                    cout << "putvoxel\n";
                    int x_, y_, z_;
                    ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
                }

                else if(token.compare("cutVoxel") == 0){
                    cout << "cutVoxel\n";
                    int x_, y_, z_;
                    ss >> x_ >> y_ >> z_;
                    figs.push_back(new CutVoxel(x_, y_, z_));
                }

                else if(token.compare("putBox") == 0){
                    cout << "putBox\n";
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }

                else if(token.compare("cutBox") == 0){
                    cout << "cutBox\n";
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }

                else if(token.compare("putEllipsoid") == 0){
                    cout << "putEllipsoid\n";
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                }

                else if(token.compare("cutEllipsoid") == 0){
                    cout << "cutEllipsoid\n";
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
                }

                else if(token.compare("putSphere") == 0){
                    cout << "putSphere\n";
                    int xc, yc, zc, raio;
                    ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xc, yc, zc, raio, r, g, b, a));
                }

                else if(token.compare("cutSphere") == 0){
                    cout << "cutSphere\n";
                    int xc, yc, zc, raio;
                    ss >> xc >> yc >> zc >> raio;
                    figs.push_back(new CutSphere(xc, yc, zc, raio));
                }

                else{
                    fin.close();
                    cout << "\n token " << token << " nao definido\n";
                    exit(1);
                }
            }
        }
    }

    fin.close(); // fecha o arquivo
    return figs;
}

int Interpreter::getDX(){
    return dx;
}

int Interpreter::getDY(){
    return dy;
}

int Interpreter::getDZ(){
    return dz;
}