//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *LBVP;
	TLabel *LBMUNDO;
	TButton *Button1;
	TListBox *LBPOLIGONOS;
	TListBox *LBPONTOS;
	TLabel *POLIGONOS;
	TLabel *PONTOS;
	TButton *Button2;
	TEdit *edXMin;
	TEdit *edYMin;
	TEdit *edXMax;
	TEdit *edYMax;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *TopButton;
	TButton *RightButton;
	TButton *LowButton;
	TButton *LeftButton;
	TButton *ZoomInButton;
	TButton *ZoomOutButton;
	TRadioGroup *rgTipoReta;
	TEdit *edx;
	TEdit *edy;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Translação;
	TLabel *Y;
	TEdit *anguloRotacao;
	TButton *Button4;
	TEdit *escalonamento_edit;
	TButton *escalonamento_button;
	TRadioGroup *radio_reflexao;
	TButton *reflexao_button;
	TButton *rodar_eixo_button;
	TButton *inicar_circ_button;
	TButton *casteljau_button;
	TButton *hermite_button;
	TButton *Button5;
	TButton *btnBspline;
	TButton *btnForwardBezier;
	TLabel *Label8;
	TButton *Button6;
	TButton *TranslacaoHomogeniaButton;
	TButton *bt3D;
	TRadioGroup *TipoPoligono3D;
	TRadioGroup *tipoEixo3D;
	TButton *btRotaciona3D;
	TButton *btEscalona3D;
	TButton *btTranslada3D;
	TRadioGroup *rgTipoTransformacao;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *EditX3D;
	TEdit *EditY3D;
	TEdit *EditZ3D;
	TLabel *Label2;
	TEdit *editDRodar;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TopButtonClick(TObject *Sender);
	void __fastcall LowButtonClick(TObject *Sender);
	void __fastcall RightButtonClick(TObject *Sender);
	void __fastcall LeftButtonClick(TObject *Sender);
	void __fastcall ZoomInButtonClick(TObject *Sender);
	void __fastcall ZoomOutButtonClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall TranslaçãoClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall escalonamento_buttonClick(TObject *Sender);
	void __fastcall reflexao_buttonClick(TObject *Sender);
	void __fastcall LBPOLIGONOSClick(TObject *Sender);
	void __fastcall rodar_eixo_buttonClick(TObject *Sender);
	void __fastcall inicar_circ_buttonClick(TObject *Sender);
	void __fastcall casteljau_buttonClick(TObject *Sender);
	void __fastcall hermite_buttonClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall btnBsplineClick(TObject *Sender);
	void __fastcall btnForwardBezierClick(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall TranslacaoHomogeniaButtonClick(TObject *Sender);
	void __fastcall bt3DClick(TObject *Sender);
	void __fastcall btRotaciona3DClick(TObject *Sender);
	void __fastcall btTranslada3DClick(TObject *Sender);
	void __fastcall btEscalona3DClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	void atualizaMundo();
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
