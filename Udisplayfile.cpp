//---------------------------------------------------------------------------

#pragma hdrstop

#include "Udisplayfile.h"
#include "Uponto.h"
#include "Upoligono.h"
#include "Ujanela.h"
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta)
{

    canvas->Brush->Color = clSilver;
    canvas->FillRect(Rect(0, 0, 500, 500));

    canvas->Pen->Color = clBlack;
    canvas->Pen->Width = 3;

    // desenha eixo vertical
    //	canvas->MoveTo(250,0);
    //	canvas->LineTo(250,500);

    double xx = mundo.yMax;

    for (int i = 0; i < poligonos.size(); i++)
    {
        if (i > 1)
        {
            canvas->Pen->Color = clBlue;
        }
        if (poligonos[i].tipo == 'A')
        {
            // canvas->Pen->Color = clRed;
            canvas->Pen->Width = 6;
        }
        else
        {
            canvas->Pen->Width = 3;
        }
        poligonos[i].desenha(canvas, mundo, vp, tipoReta);
    }
}

void DisplayFile::mostra(TListBox *listbox)
{

    listbox->Clear();

    for (int i = 0; i < poligonos.size(); i++)
    {

        poligonos[i].mostra(listbox);
    }
}

void DisplayFile::rotaciona3DDisplay(Janela mundo, Janela vp, double teta, int indice, boolean homogenea, int eixo)
{
    double x, y, z, Xce, Yce, Zce;
	Xce = poligonos[indice].PontoCentralX();
    Yce = poligonos[indice].PontoCentralY();
    Zce = poligonos[indice].PontoCentralZ();

    for (int j = 0; j < poligonos[indice].pontos.size(); j++)
	{
		x = poligonos[indice].pontos[j].x;
        y = poligonos[indice].pontos[j].y;
        z = poligonos[indice].pontos[j].z;
		poligonos[indice].rotacao3D(teta, &poligonos[indice].pontos[j].x, &poligonos[indice].pontos[j].y, &poligonos[indice].pontos[j].z, Xce, Yce, Zce, homogenea, eixo);
	}
}

void DisplayFile::transloca3DDisplay(Janela mundo, Janela vp,double auxX,double auxY,double auxZ, int indice,boolean homogenea)
{
 double x,y,z;
 for(int j = 0; j < poligonos[indice].pontos.size(); j++){
    x = poligonos[indice].pontos[j].x;
    y = poligonos[indice].pontos[j].y;
    z = poligonos[indice].pontos[j].z;
	poligonos[indice].translada3D(auxX, auxY, auxZ, &x, &y, &z, homogenea);

    poligonos[indice].pontos[j].x = x;
	poligonos[indice].pontos[j].y = y;
    poligonos[indice].pontos[j].z = z;
   }

}

void DisplayFile::escalona3DDisplay(Janela mundo, Janela vp,double auxX,double auxY,double auxZ, int indice,boolean homogenea)
{
 double x,y,z,Xce,Yce,Zce;

  Xce=poligonos[indice].PontoCentralX();
  Yce=poligonos[indice].PontoCentralY();
  Zce=poligonos[indice].PontoCentralZ();

   for(int j = 0; j < poligonos[indice].pontos.size(); j++){
        x = poligonos[indice].pontos[j].x;
        y = poligonos[indice].pontos[j].y;
        z = poligonos[indice].pontos[j].z;
		poligonos[indice].escalona3D(mundo,vp,auxX, auxY, auxZ, &poligonos[indice].pontos[j].x, &poligonos[indice].pontos[j].y, &poligonos[indice].pontos[j].z, Xce,Yce,Zce, homogenea);

   }
}
