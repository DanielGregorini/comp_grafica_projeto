//---------------------------------------------------------------------------

#ifndef UdisplayfileH
#define UdisplayfileH
#include "Uponto.h"
#include "Upoligono.h"
#include "Ujanela.h"
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class DisplayFile{
	public:
		std::vector <Poligono> poligonos;

		void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);

		void mostra(TListBox *ListBox);

		//TRANSFORMA??ES 3D
        void rotaciona3DDisplay(Janela mundo, Janela vp,double teta, int indice,boolean homogenea,int eixo);
        void escalona3DDisplay(Janela mundo, Janela vp,double auxX,double auxY,double auxZ, int indice,boolean homogenea);
		void transloca3DDisplay(Janela mundo, Janela vp,double auxX,double auxY,double auxZ, int indice,boolean homogenea);
};
#endif
