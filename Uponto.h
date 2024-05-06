//---------------------------------------------------------------------------

#ifndef UpontoH
#define UpontoH
#include "Ujanela.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Ponto{
  public:
	double x;
	double y;
	double z;

	Ponto();
	Ponto(double nx, double ny);
	Ponto(double nx, double ny, double nz);

	int xW2Vp(Janela mundo, Janela vp);

	int yW2Vp(Janela mundo, Janela vp);

	void translacao(double dx, double dy);

	void escalonamento(double escalonador);

	void reflexao(double dx, double dy);

	int regionCode(Janela clip);

	AnsiString mostraPonto();
};

#endif
