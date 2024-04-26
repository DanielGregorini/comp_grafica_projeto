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




};
#endif
