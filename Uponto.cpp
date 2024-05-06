//---------------------------------------------------------------------------

#pragma hdrstop
#include "Uponto.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
Ponto::Ponto(){
  x = y =z = 0;
}

Ponto::Ponto(double nx, double ny){
	x = nx;
	y = ny;
	z = 0;
}

Ponto::Ponto(double nx, double ny, double nz){
	x = nx;
	y = ny;
	z = nz;
}

int xW2Vp(Janela mundo, Janela vp);
int yW2Vp(Janela mundo, Janela vp);

int Ponto::xW2Vp(Janela mundo, Janela vp){
	return ((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) * (vp.xMax - vp.xMin);
}

int Ponto::yW2Vp(Janela mundo, Janela vp){
	return ((1 - ((y - mundo.yMin) / (mundo.yMax - mundo.yMin))) * (vp.yMax - vp.yMin));
}

AnsiString Ponto::mostraPonto(){
		return "(" + FloatToStr(x) + " ; " + FloatToStr(y) + " ; " + FloatToStr(z) + ")";
}

void Ponto::translacao(double dx, double dy){
	 x += dx;
	 y += dy;
}

void Ponto::reflexao(double dx, double dy){
	 x = x * dx;
	 y = y * dy;
}

void Ponto::escalonamento(double escalonador){
	x = x * escalonador;
	y = y * escalonador;
}

int Ponto::regionCode(Janela clip)
{
    int cohen = 0;

	cohen += (x < clip.xMin) ? 1 : 0;
    cohen += (x > clip.xMax) ? 2 : 0;
    cohen += (y < clip.yMin) ? 4 : 0;
    cohen += (y > clip.yMax) ? 8 : 0;

	return cohen;
}
