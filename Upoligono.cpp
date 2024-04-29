//---------------------------------------------------------------------------
#include "Uponto.h"

#pragma hdrstop
#include "Math.h"
#include "Upoligono.h"
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Poligono::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta) {
	int xvp, yvp;

	int x, y, x1, y1, x2, y2;

    switch (tipoReta) {
		case 0: //toline
			for (int i = 0; i < pontos.size(); i++) {
				xvp = pontos[i].xW2Vp(mundo, vp);
				yvp = pontos[i].yW2Vp(mundo, vp);
				if (i == 0) {
                    canvas->MoveTo(xvp, yvp);
                } else {
                    canvas->LineTo(xvp, yvp);
                }
            }
			break;

		case 1: // DDA
            for (unsigned int i = 1; i < pontos.size(); i++)
                {
						x1 = pontos[i - 1].xW2Vp(mundo, vp);
						y1 = pontos[i - 1].yW2Vp(mundo, vp);
						x2 = pontos[i].xW2Vp(mundo, vp);
						y2 = pontos[i].yW2Vp(mundo, vp);

                        drawDDA(canvas, x1, y1, x2, y2);
				}
			break;

		case 2: // Bresenham
            for (unsigned int i = 1; i < pontos.size(); i++)
                {
						x1 = pontos[i - 1].xW2Vp(mundo, vp);
                        y1 = pontos[i - 1].yW2Vp(mundo, vp);
						x2 = pontos[i].xW2Vp(mundo, vp);
						y2 = pontos[i].yW2Vp(mundo, vp);

                        drawBresenham(canvas, x1, y1, x2, y2);
				}
            break;

        default:
            // Handle invalid tipoReta value
            break;
    }
}

void Poligono::drawDDA(TCanvas *canvas, int x1, int y1, int x2, int y2)
{
		#define SIGN(x) ((x) < 0 ? (-1) : (1))
		#define ABS(x) ((x) < 0 ? (-x) : (x))
		#define FLOOR(x) ((x) < 0 ? ((x) - (int)(x) != 0 ? ((int)(x) - 1) : ((int)(x))) : (int)(x))
		int length;
        float x, y, deltay, deltax;

        if (ABS((x2 - x1)) >= ABS((y2 - y1)))
                length = ABS((x2 - x1));
		else
                length = ABS((y2 - y1));

        deltax = (float)(x2 - x1) / (float)length;
        deltay = (float)(y2 - y1) / (float)length;
        x = x1 + 0.5 * SIGN(deltax);
        y = y1 + 0.5 * SIGN(deltay);

        for (int i = 0; i < length; i++)
        {
                canvas->Pixels[x][y] = clBlue;
                x += deltax;
                y += deltay;
        }
}

void Poligono::drawBresenham(TCanvas *canvas, int x1, int y1, int x2, int y2)
{
		#define SIGN(x) ((x) < 0 ? (-1) : (1))
		#define ABS(x) ((x) < 0 ? (-x) : (x))
		#define FALSE 0
		#define TRUE 1
        int x, dx, y, dy, deltax, deltay, interchange, tmp, signalx, signaly;
        double erro;

        int i = pontos.size();

        if (i > 1)
        {
                erro = 0;
                for (int j = 0; j < i - 1; j++)
				{
                        deltax = ABS((x2 - x1));
                        deltay = ABS((y2 - y1));
                        signalx = SIGN((x2 - x1));
                        signaly = SIGN((y2 - y1));

                        x = x1;
                        y = y1;

                        if (signalx < 0)
                        {
                                x -= 1;
                        }
                        if (signaly < 0)
                        {
                                y -= 1;
                        }

                        interchange = FALSE;
                        if (deltay > deltax)
                        {
                                tmp = deltax;
                                deltax = deltay;
                                deltay = tmp;
                                interchange = TRUE;
                        }
                        erro = 2 * deltay - deltax;

                        for (i = 0; i < deltax; i++)
                        {
                                canvas->Pixels[x][y] = clBlack;

                                while (erro >= 0)
                                {
                                        if (interchange)
                                        {
                                                x = x + signalx;
                                        }
                                        else
                                        {
                                                y = y + signaly;
                                        }
                                        erro = erro - 2 * deltax;
                                } // encerra while
                                if (interchange)
                                {
                                        y = y + signaly;
                                }
                                else
                                {
                                        x = x + signalx;
                                }
                                erro = erro + 2 * deltay;
						}
				}
		}
}

void Poligono::circunferencia(Ponto aux, double r)
{
		Ponto centro = aux;

		pontos.clear();

		for (int i = 0; i <= 360; i++)
		{
				aux.x = r * cos(i * (M_PI / 180)) + centro.x;
				aux.y = r * sin(i * (M_PI / 180)) + centro.y;
				pontos.push_back(aux);
		}
}


void Poligono::mostra(TListBox *listbox){

    listbox->Items->Add(IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size()));

}

void Poligono::mostraPontos(TListBox *listbox){

	listbox->Items->Clear();

	for (int i = 0; i < pontos.size(); i++) {

		listbox->Items->Add(pontos[i].mostraPonto());

	}

}

void Poligono::translacao(double dx, double dy, bool homogenia) {
	if (homogenia) {

		double translacao[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {dx, dy, 1}
        };
        double resultado[3];

        for (int i = 0; i < pontos.size(); i++) {
			double ponto[3] = {pontos[i].x, pontos[i].y, 1};

			resultado[0] = ponto[0] * translacao[0][0] + ponto[1] * translacao[1][0] + ponto[2] * translacao[2][0];
			resultado[1] = ponto[0] * translacao[0][1] + ponto[1] * translacao[1][1] + ponto[2] * translacao[2][1];
			resultado[2] = ponto[0] * translacao[0][2] + ponto[1] * translacao[1][2] + ponto[2] * translacao[2][2];

            pontos[i].x = resultado[0];
            pontos[i].y = resultado[1];
        }
    } else {

        for (int i = 0; i < pontos.size(); i++) {
			pontos[i].translacao(dx, dy);
        }
    }
}



void Poligono::escalonamento(double escalonador)  {
	//multiplica as coordenas de todos os pontos pelo escalonador
	for(int i = 0; i < pontos.size(); i++){
		 pontos[i].escalonamento(escalonador);
	}

}

void Poligono::reflexao(int opcao) {

	// Assume que não há reflexão se não for uma das opções
	double dx = 1.0;
	double dy = 1.0;

	if (opcao == 0) {
		dx = -1.0;
		dy = 1.0;
	} else if (opcao == 1) {
		dx = 1.0;
		dy = -1.0;
	} else if (opcao == 2) {
		dx = -1.0;
		dy = -1.0;
	}

	for (auto& ponto : pontos) {
		ponto.reflexao(dx, dy);
	}
}

void Poligono::rotacionar(TCanvas* canvas, Janela mundo, Janela vp,
	int tipoReta, double teta){

	std::vector<std::vector<double> > MRotacao = { { cos(teta), sin(teta), 0 },
		{ -sin(teta), cos(teta), 0 }, { 0, 0, 1 } };
	double centroX = 0.0, centroY = 0.0;
	for (int i = 0; i < pontos.size(); i++) {
		centroX += pontos[i].x;
		centroY += pontos[i].y;
	}

	centroX /= pontos.size();
	centroY /= pontos.size();

	for (int i = 0; i < pontos.size(); i++) {
		double x = pontos[i].x - centroX;
		double y = pontos[i].y - centroY;

		double novoX = MRotacao[0][0] * x + MRotacao[0][1] * y;
		double novoY = MRotacao[1][0] * x + MRotacao[1][1] * y;

		pontos[i].x = novoX + centroX;
		pontos[i].y = novoY + centroY;
	}


	desenha(canvas, mundo, vp, tipoReta);
}

void Poligono::rotacionarCentro(TCanvas* canvas, Janela mundo, Janela vp,
	int tipoReta, double teta){

	std::vector<std::vector<double> > MRotacao = { { cos(teta), sin(teta), 0 },
		{ -sin(teta), cos(teta), 0 }, { 0, 0, 1 } };

	double centroX = 0.0, centroY = 0.0;

	for (int i = 0; i < pontos.size(); i++) {
		double x = pontos[i].x - centroX;
		double y = pontos[i].y - centroY;

		double novoX = MRotacao[0][0] * x + MRotacao[0][1] * y;
		double novoY = MRotacao[1][0] * x + MRotacao[1][1] * y;

		pontos[i].x = novoX + centroX;
		pontos[i].y = novoY + centroY;
	}


	desenha(canvas, mundo, vp, tipoReta);
}

//-------------------------------------------------------//
//CURVAS

void Poligono::casteljau(Ponto p1, Ponto p2, Ponto p3, double limite)
{
		double mxP12, myP12, mxP23, myP23;
        double distancia;

        mxP12 = (p1.x + p2.x) / 2;
        myP12 = (p1.y + p2.y) / 2;

        mxP23 = (p2.x + p3.x) / 2;
        myP23 = (p2.y + p3.y) / 2;

        Ponto nP1(mxP12, myP12);
        Ponto nP2(mxP23, myP23);
        Ponto nP3((mxP12 + mxP23) / 2, (myP12 + myP23) / 2);

        distancia = (double)sqrt(((mxP12 - mxP23) * (mxP12 - mxP23)) + ((myP12 - myP23) * (myP12 - myP23)));

        if (distancia > limite)
        {
                casteljau(p1, nP1, nP3, limite);
                casteljau(nP3, nP2, p3, limite);
        }
        else
        {
                pontos.push_back(nP3);
		}
}

void Poligono::hermite(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
		double xT;
		double yT;
		Ponto aux, r1, r4;

		r1.x = p2.x - p1.x;
		r1.y = p2.y - p1.y;

		r4.x = p4.x - p3.x;
		r4.y = p4.y - p3.y;

		for (double t = 0; t < 1; t += (double)0.01)
		{

				xT = p1.x * (2 * t * t * t - 3 * t * t + 1) + p4.x * (-2 * t * t * t + 3 * t * t) + r1.x * (t * t * t - 2 * t * t + t) + r4.x * (t * t * t - t * t);
				yT = p1.y * (2 * t * t * t - 3 * t * t + 1) + p4.y * (-2 * t * t * t + 3 * t * t) + r1.y * (t * t * t - 2 * t * t + t) + r4.y * (t * t * t - t * t);

				aux.x = xT;
				aux.y = yT;
				pontos.push_back(aux);
		}
}


void Poligono::bezier(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
    double xT;
    double yT;
	Ponto aux;

    for (double t = 0; t < 1; t += (double)0.01) {
        xT = (double)(p1.x * (pow(1 - t, 3)) + p2.x * 3 * t * (pow(1 - t, 2)) +
                      3 * t * t * p3.x * (1 - t) + t * t * t * p4.x);
        yT = (double)(p1.y * (pow(1 - t, 3)) + p2.y * 3 * t * (pow(1 - t, 2)) +
					  3 * t * t * p3.y * (1 - t) + t * t * t * p4.y);
        aux.x = xT;
        aux.y = yT;
        pontos.push_back(aux);
    }
}

void Poligono::bSpline(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
		Poligono auxPol;
		double xT, yT;
		Ponto aux;

		for (double t = 0; t < 1; t += (double)0.01)
		{
				xT = p1.x + 4 * p2.x + p3.x - p1.x * t * t * t + 3 * p2.x * t * t * t - 3 * p3.x * t * t * t + p4.x * t * t * t + 3 * p1.x * t * t - 6 * p2.x * t * t + 3 * p3.x * t * t - 3 * p1.x * t + 3 * p3.x * t;
				yT = p1.y + 4 * p2.y + p3.y - p1.y * t * t * t + 3 * p2.y * t * t * t - 3 * p3.y * t * t * t + p4.y * t * t * t + 3 * p1.y * t * t - 6 * p2.y * t * t + 3 * p3.y * t * t - 3 * p1.y * t + 3 * p3.y * t;

				aux.x = xT / 6;
                aux.y = yT / 6;
				pontos.push_back(aux);
		}
}

void Poligono::fwdDifferences(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
        Ponto aux;
        double delta1 = (double)(1 / 100.0);
        double delta2 = (double)(pow((double)delta1, 2));
        double delta3 = (double)(pow((double)delta1, 3));

        double MatrizBezier[4][4] = {{-1, 3, -3, 1},
                                     {3, -6, 3, 0},
                                     {-3, 3, 0, 0},
                                     {1, 0, 0, 0}};

        double mPtsX[4][1] = {{p1.x},
                              {p2.x},
                              {p3.x},
                              {p4.x}};

        double mPtsY[4][1] = {{p1.y},
                              {p2.y},
                              {p3.y},
                              {p4.y}};

        double matrizX[4][4] = {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};

        double matrizY[4][4] = {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};

		for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 1; j++)
                {
                        for (int k = 0; k < 4; k++)
                        {
                                matrizX[i][j] += MatrizBezier[i][k] * mPtsX[k][j];
                        }
                }
        }


        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 1; j++)
                {
                        for (int k = 0; k < 4; k++)
                        {
                                matrizY[i][j] += MatrizBezier[i][k] * mPtsY[k][j];
                        }
                }
        }

        double matrizDx[4][1];
        double matrizDy[4][1];



        matrizDx[0][0] = matrizX[3][0];
        matrizDx[1][0] = matrizX[0][0] * delta3 + matrizX[1][0] * delta2 + matrizX[2][0] * delta1;
        matrizDx[2][0] = 6 * matrizX[0][0] * delta3 + 2 * matrizX[1][0] * delta2;


        matrizDy[0][0] = matrizY[3][0];
        matrizDy[1][0] = matrizY[0][0] * delta3 + matrizY[1][0] * delta2 + matrizY[2][0] * delta1;
        matrizDy[2][0] = 6 * matrizY[0][0] * delta3 + 2 * matrizY[1][0] * delta2;
        matrizDy[3][0] = 6 * matrizY[0][0] * delta3;



        for (double t = 0; t < 100; t++)
        {
                matrizDx[0][0] += matrizDx[1][0];
                matrizDx[1][0] += matrizDx[2][0];
                matrizDx[2][0] += matrizDx[3][0];

                matrizDy[0][0] += matrizDy[1][0];
                matrizDy[1][0] += matrizDy[2][0];
                matrizDy[2][0] += matrizDy[3][0];

                aux.x = matrizDx[0][0];
                aux.y = matrizDy[0][0];
                pontos.push_back(aux);
        }
}

// CLIPPING
//---------------------------------------------------------------------------------------------------------------------------------------------
Ponto Poligono::novoPonto(Ponto aux, double x, double y)
{
        Ponto pto = aux;
        pto.x = x;
        pto.y = y;
		return pto;
}

Poligono Poligono::clipping(Janela clip, int nPol)
{
        Poligono poligono;
		Ponto auxPon;

        int clipPonto1, clipPonto2;
        double inclinacao, tang, yEsq, yDir, xTopo, xFundo;

        for (int i = 1; i < pontos.size(); i++)
        {
                Ponto aux;
                clipPonto1 = pontos[i - 1].regionCode(clip);
                clipPonto2 = pontos[i].regionCode(clip);

                tang = (pontos[i].y - pontos[i - 1].y) / ((pontos[i].x - pontos[i - 1].x) == 0 ? (double)0.01 : (pontos[i].x - pontos[i - 1].x));

                if (tang == 0)
                {
                        inclinacao = (double)0.001;
                }
                else
                {
                        inclinacao = tang;
                }

                if (((clipPonto1 == 0) || (clipPonto2 == 0)) && clipPonto1 != clipPonto2)
                {
                        int ind = clipPonto1 < clipPonto2 ? i : i - 1;
                        yEsq = inclinacao * (clip.xMin - pontos[ind].x) + pontos[ind].y;
                        yDir = inclinacao * (clip.xMax - pontos[ind].x) + pontos[ind].y;
                        xTopo = pontos[ind].x + 1 / (inclinacao == 0 ? (double)0.01 : inclinacao) * (clip.yMax - pontos[ind].y);
                        xFundo = pontos[ind].x + 1 / (inclinacao == 0 ? (double)0.01 : inclinacao) * (clip.yMin - pontos[ind].y);

                        switch (clipPonto1 < clipPonto2 ? clipPonto2 : clipPonto1)
                        {
                        case 1:
                                aux = novoPonto(aux, clip.xMin, yEsq);
                                break;
                        case 2:
                                aux = novoPonto(aux, clip.xMax, yDir);
                                break;
                        case 4:
                                aux = novoPonto(aux, xFundo, clip.yMin);
                                break;
                        case 5:
                                aux = yEsq > clip.yMin ? novoPonto(aux, clip.xMin, yEsq) : novoPonto(aux, xFundo, clip.yMin);
                                break;
                        case 6:
                                aux = xFundo < clip.xMax ? novoPonto(aux, xFundo, clip.yMin) : novoPonto(aux, clip.xMax, yDir);
                                break;
                        case 8:
                                aux = novoPonto(aux, xTopo, clip.yMax);
                                break;
                        case 9:
                                aux = yEsq < clip.yMax ? novoPonto(aux, clip.xMin, yEsq) : novoPonto(aux, xTopo, clip.yMax);
                                break;
                        case 10:
                                aux = yDir < clip.yMax ? novoPonto(aux, clip.xMax, yDir) : novoPonto(aux, xTopo, clip.yMax);
                                break;
                        }

                        if (clipPonto1 < clipPonto2)
                        {

                                poligono.pontos.push_back(Ponto(pontos[i - 1].x - 1, pontos[i - 1].y - 1));
                                poligono.pontos.push_back(Ponto(aux.x - 1, aux.y - 1));
                        }
                        else
                        {

                                poligono.pontos.push_back(Ponto(aux.x - 1, aux.y - 1));
                                poligono.pontos.push_back(Ponto(pontos[i].x - 1, pontos[i].y - 1));
                        }
                }
                else if ((clipPonto1 == clipPonto2) && clipPonto2 == 0)
                {

                        poligono.pontos.push_back(Ponto(pontos[i - 1].x - 1, pontos[i - 1].y - 1));
                        poligono.pontos.push_back(Ponto(pontos[i].x - 1, pontos[i].y - 1));
                }
                // PARCIALMENTE
                else if ((clipPonto1 != clipPonto2) && ((clipPonto1 & clipPonto2) == 0))
                {
                        Ponto aux;
                        for (int j = i - 1; j <= i; j++)
                        {
                                // CALCULO DE INTERSEC��ES
                                yEsq = inclinacao * (clip.xMin - pontos[j].x) + pontos[j].y;
                                yDir = inclinacao * (clip.xMax - pontos[j].x) + pontos[j].y;
                                xTopo = pontos[j].x + 1 / inclinacao * (clip.yMax - pontos[j].y);
                                xFundo = pontos[j].x + 1 / inclinacao * (clip.yMin - pontos[j].y);

                                switch (j == i ? clipPonto2 : clipPonto1)
                                {
                                case 1:
                                        if (yEsq >= clip.yMin && yEsq <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMin, yEsq);
                                        break;
                                case 2:
                                        if (yDir >= clip.yMin && yDir <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMax, yDir);
                                        break;
                                case 4:
                                        if (xFundo >= clip.xMin && xFundo <= clip.xMax)
                                                aux = novoPonto(aux, xFundo, clip.yMin);
                                        break;
                                case 5:
                                        if (xFundo >= clip.xMin && xFundo <= clip.xMax)
                                                aux = novoPonto(aux, xFundo, clip.yMin);
                                        else if (yEsq >= clip.yMin && yEsq <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMin, yEsq);
                                        break;
                                case 6:
                                        if (xFundo >= clip.xMin && xFundo <= clip.xMax)
                                                aux = novoPonto(aux, xFundo, clip.yMin);
                                        else if (yDir >= clip.yMin && yDir <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMax, yDir);
                                        break;
                                case 8:
                                        if (xTopo >= clip.xMin && xTopo <= clip.xMax)
                                                aux = novoPonto(aux, xTopo, clip.yMax);
                                        break;
                                case 9:
                                        if (xTopo >= clip.xMin && xTopo <= clip.xMax)
                                                aux = novoPonto(aux, xTopo, clip.yMax);
                                        else if (yEsq >= clip.yMin && yEsq <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMin, yEsq);
                                        break;
                                case 10:
                                        if (xTopo >= clip.xMin && xTopo <= clip.xMax)
                                                aux = novoPonto(aux, xTopo, clip.yMax);
                                        else if (yDir >= clip.yMin && yDir <= clip.yMax)
                                                aux = novoPonto(aux, clip.xMax, yDir);
                                        break;
                                }
                                if (aux.x == aux.y && aux.x == 0)
                                        break;
                                else
                                        poligono.pontos.push_back(aux);
                        }
                }
        }
        return poligono;
}
