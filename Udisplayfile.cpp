//---------------------------------------------------------------------------

#pragma hdrstop

#include "Udisplayfile.h"
#include "Uponto.h"
#include "Upoligono.h"
#include "Ujanela.h"
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta){

	canvas->Brush->Color = clSilver;
	canvas->FillRect(Rect(0,0,500,500));

	canvas->Pen->Color = clBlack;
	canvas->Pen->Width = 3;

 //desenha eixo vertical
 //	canvas->MoveTo(250,0);
 //	canvas->LineTo(250,500);

 double xx = mundo.yMax;

  for(int i = 0; i < poligonos.size(); i++){
        if (i > 1){
			canvas->Pen->Color = clBlue;
		}
		if(poligonos[i].tipo == 'A'){
        		//canvas->Pen->Color = clRed;
				canvas->Pen->Width = 6;
        }
        else{
				canvas->Pen->Width = 3;
        }
		poligonos[i].desenha(canvas, mundo, vp, tipoReta);
	}


}

 void DisplayFile::mostra(TListBox *listbox){

	listbox->Clear();

    for (int i = 0; i < poligonos.size(); i++) {

	poligonos[i].mostra(listbox);

 }

 }


