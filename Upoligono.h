//---------------------------------------------------------------------------

#ifndef UpoligonoH
#define UpoligonoH
#include "Uponto.h"
#include "Ujanela.h"
#include "Uponto.h"
#include <vector>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class Poligono{
	public:
		int id;
		char tipo;
		std::vector<Ponto> pontos;


	double PontoCentralX();
	double PontoCentralY();
	double PontoCentralZ();

	//desenha e retas
	void desenha(TCanvas *canvas, Janela mundo, Janela vp, int t�poReta);
	void drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2);
	void drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2);

	void mostra(TListBox *listbox);

	void mostraPontos(TListBox *listbox);
	void translacao(double dx, double dy, bool homogenia);


	//   transformacoes
	void escalonamento(double escalonador);
	void circunferencia(Ponto aux, double r);
	void rotacionar(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta, double teta);
	void reflexao(int opcao);

	//3D
	void translada3D(double x, double y, double z, double *px, double *py, double *pz, boolean homogenea);
	void escalona3D(Janela mundo,Janela vp,double x, double y, double z, double *px, double *py, double *pz, double Xc, double Yc, double Zc, boolean homogenea);
	void rotacao3D(double teta, double *px, double *py, double *pz, double Xc, double Yc,double Zc, boolean homogenea, int eixo);

	void rotacionarCentro(TCanvas* canvas, Janela mundo, Janela vp,
	int tipoReta, double teta);

	//curvas
	void casteljau(Ponto p1, Ponto p2, Ponto p3, double limite);

	void hermite(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void bezier(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void bSpline(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void fwdDifferences(Ponto p1, Ponto p2, Ponto p3, Ponto p4);

	//clipping
    Poligono clipping(Janela clip, int nPol);
	Ponto novoPonto(Ponto aux, double x, double y);

};
#endif
