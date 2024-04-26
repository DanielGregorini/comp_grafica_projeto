//---------------------------------------------------------------------------

#ifndef UpoligonoH
#define UpoligonoH
#include "Uponto.h"

#include "Uponto.h"
#include <vector>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class Poligono{
	public:
		int id;
		char tipo;
		std::vector<Ponto> pontos;

			//desenha e retas
			void desenha(TCanvas *canvas, Janela mundo, Janela vp, int típoReta);
			void drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2);
			void drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2);

			void mostra(TListBox *listbox);

			void mostraPontos(TListBox *listbox);
			void translacao(double dx, double dy);

			void escalonamento(double escalonador);

			void circunferencia(Ponto aux, double r);

			void rotacionar(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta, double teta);

			void reflexao(int opcao);

			 void rotacionarCentro(TCanvas* canvas, Janela mundo, Janela vp,
	int tipoReta, double teta);

	//curvas
	void casteljau(Ponto p1, Ponto p2, Ponto p3, double limite);

	void hermite(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void bezier(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void bSpline(Ponto p1, Ponto p2, Ponto p3, Ponto p4);
	void fwdDifferences(Ponto p1, Ponto p2, Ponto p3, Ponto p4);

};
#endif
