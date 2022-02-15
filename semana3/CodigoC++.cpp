/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <fstream>

double f(double x, int pote){

double newx = -1* pow(x, pote);

return exp( newx );

}

double df_Central(double x1, double x2, int pote, double paso_){

double fxh = f(x1, pote);

double fhx = f(x2, pote);

double res = (fxh - fhx )/(2*paso_);

return res;

}

int main(){

double a = f(2.2, 2);

double limsup = 20;

double liminf = -20;

double paso = 0.01;

int limite = abs((limsup-liminf)/paso) + 1;

std::cout<<limite<<std::endl;

double MiLista[limite] = {};

for (int i = 0; i < limite; i++)

{

MiLista[i] = liminf + (i*paso);

}

std::ofstream *File; // Creamos o definimos nuestro apuntador

File = new std::ofstream[1]; // Reservamos memoria

File[0].open( "MisDatosDerivadaCentral.txt", std::ofstream::trunc ); // Abrir y dejar listo para escribir

for(int i = 0; i < limite ; i++){

double respuesta = df_Central(MiLista[i]+paso, MiLista[i]-paso, 2, paso);

File[0] << MiLista[i] << " " << respuesta << std::endl;

}

std::cout << File << std::endl;

return 0;

}
