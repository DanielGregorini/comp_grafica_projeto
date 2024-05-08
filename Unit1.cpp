//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Uponto.h"
#include "Ujanela.h"
#include "Upoligono.h"
#include "Udisplayfile.h"
#include "Math.h"
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Ponto aux;
Poligono pol;
DisplayFile display;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);
Janela clipper(-125, -125, 125, 125);
bool cria_clip = false;

bool inicia = false;
bool inicia_circunferencia = false;

int contId = 0;

double xVp2Mundo(int xVp, Janela mundo, Janela vp)
{
    return ((xVp - vp.xMin) / (vp.xMax - vp.xMin)) * (mundo.xMax - mundo.xMin) + mundo.xMin;
}

double yVp2Mundo(int yVp, Janela mundo, Janela vp)
{
    return (1 - (yVp - vp.yMin) / (vp.yMax - vp.yMin)) * (mundo.yMax - mundo.yMin) + mundo.yMin;
}
/*
void atualizaMundo::TForm1(){

}
*/
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
    /*
     Form1->Image1->Canvas->Brush->Color = clSilver;
     Form1->Image1->Canvas->FillRect(Rect(0,0,500,500));

     Form1->Image1->Canvas->Pen->Color = clBlack;
     Form1->Image1->Canvas->Pen->Width = 3;

     //desenha eixo vertical
     Form1->Image1->Canvas->MoveTo(250,0);
     Form1->Image1->Canvas->LineTo(250,500);
     */

    // 1 forma
    // aux.x = xVp2Mundo(250, mundo, vp);
    // aux.y = yVp2Mundo(0, mundo, vp);

    // 2 forma
    // aux.x = 0;
    // aux.y = mundo.yMax;

    // 3 forma

    // eixo vertical
    pol.id = contId++;
    pol.tipo = 'E';
    pol.pontos.push_back(Ponto(0, mundo.yMax));
    pol.pontos.push_back(Ponto(0, mundo.yMin));

    display.poligonos.push_back(pol);
    pol.pontos.clear();

    // desenha eixo horizontal
    // Form1->Image1->Canvas->MoveTo(0,250);
    // Form1->Image1->Canvas->LineTo(500,250);

    pol.id = contId++;
    pol.tipo = 'E';
    pol.pontos.push_back(Ponto(mundo.xMin, 0));
    pol.pontos.push_back(Ponto(mundo.yMax, 0));

    display.poligonos.push_back(pol);
    pol.pontos.clear();

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    display.mostra(Form1->LBPOLIGONOS);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
                                        int Y)
{
    double xW, yW;
    LBVP->Caption = "( " + IntToStr(X) + ", " + IntToStr(Y) + ")";
    xW = xVp2Mundo(X, mundo, vp);
    yW = yVp2Mundo(Y, mundo, vp);
    LBMUNDO->Caption = "( " + FloatToStr(xW) + ", " + FloatToStr(yW) + ")";
}
//---------------------------------------------------------------------------

//atualizar mundo
void __fastcall TForm1::Button1Click(TObject *Sender)
{ /*
 int x, y;
  Ponto aa(0,0);
 x = aa.xW2Vp(mundo, vp);
 y = aa.yW2Vp(mundo, vp);
 ShowMessage(IntToStr(x) + IntToStr(y));

 LBPOLIGONOS->Items->Clear();
 LBPOLIGONOS->Items->Add(Ponto(10,10).mostraPonto());     */

    mundo.xMin = StrToFloat(edXMin->Text);

    mundo.yMin = StrToFloat(edYMin->Text);

    mundo.xMax = StrToFloat(edXMax->Text);
    mundo.yMax = StrToFloat(edYMax->Text);

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

// deixa vazio, coloquei sem querer

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
                                        int X, int Y)
{
    double xW, yW;

    if (inicia_circunferencia)
    {
        inicia = false;

        if (Button == mbLeft)
        {
            xW = xVp2Mundo(X, mundo, vp);
            yW = yVp2Mundo(Y, mundo, vp);
            // Poligono::circunferencia(Ponto aux, int r)

            pol.pontos.push_back(Ponto(xW, yW));
            pol.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

            if (pol.pontos.size() >= 2)
            {
                pol.id = contId++;
                pol.tipo = 'C';
                display.poligonos.push_back(pol);

                // a distancia entre o ponto central e o ultimo ponto
                double r = sqrt((pol.pontos[1].x - pol.pontos[0].x) * (pol.pontos[1].x - pol.pontos[0].x) +
                                (pol.pontos[1].y - pol.pontos[0].y) * (pol.pontos[1].y - pol.pontos[0].y));

                pol.pontos.clear();

                // ultimo poligono adicionado
                Poligono aux = display.poligonos[display.poligonos.size() - 1];

                // cria todos os pontos da circuferencia para desenhar depois
                display.poligonos[display.poligonos.size() - 1].circunferencia(aux.pontos[1], r);

                inicia = false;
                inicia_circunferencia = false;

                display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
                display.mostra(Form1->LBPOLIGONOS);
            }
        }
    }

    if (inicia)
    {

        if (Button == mbLeft)
        {
            xW = xVp2Mundo(X, mundo, vp);
            yW = yVp2Mundo(Y, mundo, vp);

            pol.pontos.push_back(Ponto(xW, yW));
            pol.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        if (Button == mbRight)
        {
            pol.id = contId++;
            pol.tipo = 'N';
            display.poligonos.push_back(pol);
            pol.pontos.clear();
            inicia = false;
            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
            display.mostra(Form1->LBPOLIGONOS);
        }
    }
}
//---------------------------------------------------------------------------

//inicar poligono
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    inicia = true;
}
//---------------------------------------------------------------------------

//cima
void __fastcall TForm1::TopButtonClick(TObject *Sender)
{
	mundo.yMin += 10;
    mundo.yMax += 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edYMin->Text = FloatToStr(mundo.yMin);
    edYMax->Text = FloatToStr(mundo.yMax);
}
//---------------------------------------------------------------------------

//baixo
void __fastcall TForm1::LowButtonClick(TObject *Sender)
{
    mundo.yMin -= 10;
    mundo.yMax -= 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edYMin->Text = FloatToStr(mundo.yMin);
    edYMax->Text = FloatToStr(mundo.yMax);
}
//--------------------------------------------------------------

//direita
void __fastcall TForm1::RightButtonClick(TObject *Sender)
{
	mundo.xMin += 10;
    mundo.xMax += 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edXMin->Text = FloatToStr(mundo.xMin);
    edXMax->Text = FloatToStr(mundo.xMax);
}
//---------------------------------------------------------------------------

//esquerda
void __fastcall TForm1::LeftButtonClick(TObject *Sender)
{
	mundo.xMin -= 10;
    mundo.xMax -= 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edXMin->Text = FloatToStr(mundo.xMin);
    edXMax->Text = FloatToStr(mundo.xMax);
}
//---------------------------------------------------------------------------

//zoom in
void __fastcall TForm1::ZoomInButtonClick(TObject *Sender)
{
	mundo.xMin += 10;
    mundo.xMax -= 10;
    mundo.yMin += 10;
    mundo.yMax -= 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edXMin->Text = FloatToStr(mundo.xMin);
    edXMax->Text = FloatToStr(mundo.xMax);
    edYMin->Text = FloatToStr(mundo.yMin);
    edYMax->Text = FloatToStr(mundo.yMax);
}
//---------------------------------------------------------------------------

//zoom out
void __fastcall TForm1::ZoomOutButtonClick(TObject *Sender)
{
	mundo.xMin -= 10;
    mundo.xMax += 10;
    mundo.yMin -= 10;
    mundo.yMax += 10;

    display.poligonos[0].pontos[0].y = mundo.yMax;
    display.poligonos[0].pontos[1].y = mundo.yMin;
    display.poligonos[1].pontos[0].x = mundo.xMin;
    display.poligonos[1].pontos[1].x = mundo.xMax;

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

    edXMin->Text = FloatToStr(mundo.xMin);
    edXMax->Text = FloatToStr(mundo.xMax);
    edYMin->Text = FloatToStr(mundo.yMin);
    edYMax->Text = FloatToStr(mundo.yMax);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//translacao
void __fastcall TForm1::TranslaçãoClick(TObject *Sender)
{
	double dx, dy;

    dx = StrToFloat(edx->Text);
    dy = StrToFloat(edy->Text);

    if (LBPOLIGONOS->ItemIndex != -1)
    {
        display.poligonos[LBPOLIGONOS->ItemIndex].translacao(dx, dy, false);
    }
    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

// rodar ao redor do centro
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	// anguloRotacao
    double angulo_graus, angulo_radius;
    angulo_graus = StrToFloat(anguloRotacao->Text);

    angulo_radius = angulo_graus * (M_PI / 180);
    if (LBPOLIGONOS->ItemIndex != -1)
    {
        display.poligonos[LBPOLIGONOS->ItemIndex].rotacionar(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex, angulo_radius);
    }

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//escalonar
void __fastcall TForm1::escalonamento_buttonClick(TObject *Sender)
{
	double escalonador;

    escalonador = StrToFloat(escalonamento_edit->Text);

    if (LBPOLIGONOS->ItemIndex != -1)
    {
        display.poligonos[LBPOLIGONOS->ItemIndex].escalonamento(escalonador);
    }

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//reflexao
void __fastcall TForm1::reflexao_buttonClick(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        int tipoReflexao = radio_reflexao->ItemIndex;

        display.poligonos[LBPOLIGONOS->ItemIndex].reflexao(tipoReflexao);
        display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LBPOLIGONOSClick(TObject *Sender)
{
    if (LBPOLIGONOS->ItemIndex != -1)
    {
        LBPONTOS->Items->Clear();
        int tipoReflexao = radio_reflexao->ItemIndex;
        // LBPONTOS
        display.poligonos[LBPOLIGONOS->ItemIndex].mostraPontos(Form1->LBPONTOS);
    }
}
//---------------------------------------------------------------------------

//rodar no eixo
void __fastcall TForm1::rodar_eixo_buttonClick(TObject *Sender)
{
	// anguloRotacao
    double angulo_graus, angulo_radius;
    angulo_graus = StrToFloat(anguloRotacao->Text);

    angulo_radius = angulo_graus * (M_PI / 180);
    if (LBPOLIGONOS->ItemIndex != -1)
    {
        display.poligonos[LBPOLIGONOS->ItemIndex].rotacionarCentro(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex, angulo_radius);
    }

    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//iniciar circuferencia
void __fastcall TForm1::inicar_circ_buttonClick(TObject *Sender)
{
	inicia_circunferencia = true;
}
//---------------------------------------------------------------------------


//Casteljau
void __fastcall TForm1::casteljau_buttonClick(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        if (display.poligonos[LBPOLIGONOS->ItemIndex].pontos.size() == 3)
        {

			pol = display.poligonos[LBPOLIGONOS->ItemIndex];

            Poligono pol_aux;

            pol_aux.casteljau(pol.pontos[0], pol.pontos[1], pol.pontos[2], 0.1);

            // pol.pontos.pop_front();

			pol_aux.tipo = 'D';
			display.poligonos.push_back(pol_aux);
            pol.pontos.clear();

            display.mostra(Form1->LBPOLIGONOS);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        else
        {
            ShowMessage("Selecione um poligono com 3 pontos");
        }
    }
}
//---------------------------------------------------------------------------

//Hermite
void __fastcall TForm1::hermite_buttonClick(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        if (display.poligonos[LBPOLIGONOS->ItemIndex].pontos.size() == 4)
        {

            pol = display.poligonos[LBPOLIGONOS->ItemIndex];
            Poligono pol_aux;

            pol_aux.hermite(pol.pontos[0], pol.pontos[1], pol.pontos[2], pol.pontos[3]);

            pol = pol_aux;

            pol.tipo = 'B';
            pol.pontos.pop_back();
            // pol.pontos.pop_front();

            display.poligonos.push_back(pol);
            pol.pontos.clear();

            display.mostra(Form1->LBPOLIGONOS);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        else
        {
            ShowMessage("Selecione um poligono com 4 pontos");
        }
    }
}
//---------------------------------------------------------------------------

//belier
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        if (display.poligonos[LBPOLIGONOS->ItemIndex].pontos.size() == 4)
        {

            pol = display.poligonos[LBPOLIGONOS->ItemIndex];

            Poligono pol_aux;

            pol_aux.bezier(pol.pontos[0], pol.pontos[1], pol.pontos[2], pol.pontos[3]);

            pol = pol_aux;
            pol.tipo = 'B';

            display.poligonos.push_back(pol);
			pol.pontos.clear();

            display.mostra(Form1->LBPOLIGONOS);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        else
        {
            ShowMessage("Selecione um poligono com 4 pontos");
        }
    }
}
//---------------------------------------------------------------------------

//B-Spline
void __fastcall TForm1::btnBsplineClick(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        if (display.poligonos[LBPOLIGONOS->ItemIndex].pontos.size() == 4)
        {

            pol = display.poligonos[LBPOLIGONOS->ItemIndex];

            Poligono pol_aux;

            pol_aux.bSpline(pol.pontos[0], pol.pontos[1], pol.pontos[2], pol.pontos[3]);

            pol = pol_aux;
            pol.tipo = 'B';

            display.poligonos.push_back(pol);
            pol.pontos.clear();

            display.mostra(Form1->LBPOLIGONOS);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        else
        {
            ShowMessage("Selecione um poligono com 4 pontos");
        }
    }
    //---------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------//

//Forward Bezier
void __fastcall TForm1::btnForwardBezierClick(TObject *Sender)
{
	if (LBPOLIGONOS->ItemIndex != -1)
    {
        if (display.poligonos[LBPOLIGONOS->ItemIndex].pontos.size() == 4)
        {

            pol = display.poligonos[LBPOLIGONOS->ItemIndex];

            Poligono pol_aux;

            pol_aux.fwdDifferences(pol.pontos[0], pol.pontos[1], pol.pontos[2], pol.pontos[3]);

            pol = pol_aux;
            pol.tipo = 'B';

            display.poligonos.push_back(pol);
            pol.pontos.clear();

            display.mostra(Form1->LBPOLIGONOS);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        }
        else
        {
            ShowMessage("Selecione um poligono com 4 pontos");
        }
    }

}

//----------clipping
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    if (cria_clip == false)
    {
        pol.pontos.clear();
        pol.pontos.push_back(Ponto(clipper.xMin, clipper.yMax));
        pol.pontos.push_back(Ponto(clipper.xMax, clipper.yMax));
        pol.pontos.push_back(Ponto(clipper.xMax, clipper.xMin));
        pol.pontos.push_back(Ponto(clipper.xMin, clipper.yMin));
        pol.pontos.push_back(Ponto(clipper.xMin, clipper.yMax));

        pol.tipo = 'C';
        pol.id = contId++;

        display.poligonos.push_back(pol);

        pol.pontos.clear();

        display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        cria_clip = true;
    }

    int max = display.poligonos.size();

    for (int i = 2; i <= max; i++)
    {
        if ((display.poligonos[i].tipo != 'C') && (display.poligonos[i].tipo != 'A'))
        {
            Poligono pol_aux;

            pol_aux = display.poligonos[i].clipping(clipper, display.poligonos.size());
            pol_aux.tipo = 'A';
            pol_aux.id = contId++;
            display.poligonos.push_back(pol_aux);
            pol_aux.pontos.clear();
        }
    }

    // display.mostra(lbPoligonos);
    display.mostra(Form1->LBPOLIGONOS);
    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//translacao homogenia
void __fastcall TForm1::TranslacaoHomogeniaButtonClick(TObject *Sender)
{
	double dx, dy;

    dx = StrToFloat(edx->Text);
    dy = StrToFloat(edy->Text);

    if (LBPOLIGONOS->ItemIndex != -1)
    {
        display.poligonos[LBPOLIGONOS->ItemIndex].translacao(dx, dy, true);
    }
    display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

//novo poligono 3d
void __fastcall TForm1::bt3DClick(TObject *Sender)
{
	FILE *file;
    int k, auxInt;
    Ponto aux;
    Poligono pol;

    switch (TipoPoligono3D->ItemIndex)
    {
    case 0:
        file = fopen("../../3DCubo.txt", "r");
        break;
    case 1:
        file = fopen("../../3DCubo2.txt", "r");
        break;
    case 2:
        file = fopen("../../3DPiramide.txt", "r");
        break;
    case 3:
        file = fopen("../../3DPiramide2.txt", "r");
        break;
    default:
        ShowMessage("Escolha um Poligono 3D!");
    }

    if (TipoPoligono3D->ItemIndex != -1)
    {
        fscanf(file, "%d", &k);

        for (int i = 0; i < k; i++)
        {

            fscanf(file, "%d", &auxInt);
            aux.x = auxInt;
            fscanf(file, "%d", &auxInt);
            aux.y = auxInt;
            fscanf(file, "%d", &auxInt);
            aux.z = auxInt;
            pol.pontos.push_back(aux);
        }

        pol.tipo = '3';
        pol.mostra(Form1->LBPOLIGONOS);
        pol.id = contId++;
        display.poligonos.push_back(pol);
        pol.pontos.clear();

        display.mostra(Form1->LBPOLIGONOS);

        display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        fclose(file);
    }
}
//---------------------------------------------------------------------------

//rotaiona 3d
void __fastcall TForm1::btRotaciona3DClick(TObject *Sender)
{
	double graus;
	graus = StrToFloat(editDRodar->Text);

    if (LBPOLIGONOS->ItemIndex >= 0)
    {
        if (tipoEixo3D->ItemIndex == 3)
        {
            display.rotaciona3DDisplay(mundo, vp, graus, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex, 0);
            display.rotaciona3DDisplay(mundo, vp, graus, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex, 1);
            display.rotaciona3DDisplay(mundo, vp, graus, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex, 2);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
            display.poligonos[LBPOLIGONOS->ItemIndex].mostra(LBPONTOS);
        }
        else
        {
            display.rotaciona3DDisplay(mundo, vp, graus, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex, tipoEixo3D->ItemIndex);

            display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
            display.poligonos[LBPOLIGONOS->ItemIndex].mostra(LBPONTOS);
        }
    }
    else
        ShowMessage("Escolha um Poligono!");
    ;
}
//---------------------------------------------------------------------------

//translacao 3d
void __fastcall TForm1::btTranslada3DClick(TObject *Sender)
{
	double dx, dy, dz;
    dx = StrToFloat(EditX3D->Text);
    dy = StrToFloat(EditY3D->Text);
    dz = StrToFloat(EditZ3D->Text);

    if (LBPOLIGONOS->ItemIndex >= 0)
    {
        display.transloca3DDisplay(mundo, vp, dx, dy, dz, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex);

        display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        display.poligonos[LBPOLIGONOS->ItemIndex].mostra(LBPONTOS);
    }
    else
        ShowMessage("Escolha um Poligono!");
}
//---------------------------------------------------------------------------


//escalona 3d
void __fastcall TForm1::btEscalona3DClick(TObject *Sender)
{
	double dx, dy, dz;
    dx = StrToFloat(EditX3D->Text);
    dy = StrToFloat(EditY3D->Text);
    dz = StrToFloat(EditZ3D->Text);

    if (LBPOLIGONOS->ItemIndex >= 0)
    {
        display.escalona3DDisplay(mundo, vp, dx, dy, dz, LBPOLIGONOS->ItemIndex, rgTipoTransformacao->ItemIndex);

        display.desenha(Form1->Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
        display.poligonos[LBPOLIGONOS->ItemIndex].mostra(LBPONTOS);
    }
    else
        ShowMessage("Escolha um Poligono!");
}
//---------------------------------------------------------------------------

