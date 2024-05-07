object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 638
  ClientWidth = 1114
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Scaled = False
  TextHeight = 15
  object LBVP: TLabel
    Left = 8
    Top = 533
    Width = 27
    Height = 15
    Caption = 'LBVP'
  end
  object LBMUNDO: TLabel
    Left = 448
    Top = 534
    Width = 58
    Height = 15
    Caption = 'LBMUNDO'
  end
  object POLIGONOS: TLabel
    Left = 514
    Top = 25
    Width = 66
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'POLIGONOS'
  end
  object PONTOS: TLabel
    Left = 514
    Top = 178
    Width = 45
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'PONTOS'
  end
  object Label1: TLabel
    Left = 579
    Top = 322
    Width = 27
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'xMin'
  end
  object Label3: TLabel
    Left = 578
    Top = 426
    Width = 27
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'yMin'
  end
  object Label4: TLabel
    Left = 576
    Top = 372
    Width = 29
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'xMax'
  end
  object Label5: TLabel
    Left = 576
    Top = 475
    Width = 29
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'yMax'
  end
  object Label6: TLabel
    Left = 300
    Top = 80
    Width = 34
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Label6'
  end
  object Label7: TLabel
    Left = 800
    Top = 9
    Width = 7
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'X'
  end
  object Y: TLabel
    Left = 800
    Top = 58
    Width = 7
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Y'
  end
  object Label8: TLabel
    Left = 958
    Top = 290
    Width = 36
    Height = 15
    Caption = 'Curvas'
  end
  object Label9: TLabel
    Left = 775
    Top = 500
    Width = 7
    Height = 15
    Caption = 'X'
  end
  object Label10: TLabel
    Left = 775
    Top = 527
    Width = 7
    Height = 15
    Caption = 'Y'
  end
  object Label11: TLabel
    Left = 775
    Top = 550
    Width = 7
    Height = 15
    Caption = 'Z'
  end
  object Label2: TLabel
    Left = 980
    Top = 451
    Width = 14
    Height = 15
    Caption = '3D'
  end
  object Panel1: TPanel
    Left = 5
    Top = 26
    Width = 502
    Height = 502
    Caption = 'Panel1'
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = 2
      ExplicitTop = -17
    end
  end
  object Button1: TButton
    Left = 544
    Top = 522
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Atualiza Mundo'
    TabOrder = 1
    OnClick = Button1Click
  end
  object LBPOLIGONOS: TListBox
    Left = 514
    Top = 41
    Width = 151
    Height = 121
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ItemHeight = 15
    TabOrder = 2
    OnClick = LBPOLIGONOSClick
  end
  object LBPONTOS: TListBox
    Left = 514
    Top = 193
    Width = 151
    Height = 121
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ItemHeight = 15
    TabOrder = 3
  end
  object Button2: TButton
    Left = 673
    Top = 35
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Iniciar Poligono'
    TabOrder = 4
    OnClick = Button2Click
  end
  object edXMin: TEdit
    Left = 514
    Top = 337
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 5
    Text = '-250'
  end
  object edYMin: TEdit
    Left = 514
    Top = 441
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 6
    Text = '-250'
  end
  object edXMax: TEdit
    Left = 514
    Top = 387
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 7
    Text = '250'
  end
  object edYMax: TEdit
    Left = 514
    Top = 491
    Width = 151
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 8
    Text = '250'
  end
  object TopButton: TButton
    Left = 753
    Top = 197
    Width = 55
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '^'
    TabOrder = 9
    OnClick = TopButtonClick
  end
  object RightButton: TButton
    Left = 816
    Top = 236
    Width = 55
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '>'
    TabOrder = 10
    OnClick = RightButtonClick
  end
  object LowButton: TButton
    Left = 753
    Top = 236
    Width = 55
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #8595
    TabOrder = 11
    OnClick = LowButtonClick
  end
  object LeftButton: TButton
    Left = 690
    Top = 236
    Width = 55
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '<'
    TabOrder = 12
    OnClick = LeftButtonClick
  end
  object ZoomInButton: TButton
    Left = 816
    Top = 197
    Width = 55
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '+'
    TabOrder = 13
    OnClick = ZoomInButtonClick
  end
  object ZoomOutButton: TButton
    Left = 690
    Top = 197
    Width = 56
    Height = 32
    Caption = '-'
    TabOrder = 14
    OnClick = ZoomOutButtonClick
  end
  object rgTipoReta: TRadioGroup
    Left = 690
    Top = 275
    Width = 152
    Height = 131
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Tipo de reta'
    ItemIndex = 0
    Items.Strings = (
      'LineTo'
      'DDA'
      'Bresenham')
    TabOrder = 15
  end
  object edx: TEdit
    Left = 794
    Top = 27
    Width = 77
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 16
    Text = '0'
  end
  object edy: TEdit
    Left = 792
    Top = 77
    Width = 77
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 17
    Text = '0'
  end
  object Translação: TButton
    Left = 788
    Top = 108
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Transla'#231#227'o'
    TabOrder = 18
    OnClick = TranslaçãoClick
  end
  object anguloRotacao: TEdit
    Left = 942
    Top = 4
    Width = 43
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 19
    Text = '0'
  end
  object Button4: TButton
    Left = 917
    Top = 35
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rodar'
    TabOrder = 20
    OnClick = Button4Click
  end
  object escalonamento_edit: TEdit
    Left = 1040
    Top = 4
    Width = 47
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 21
    Text = '0'
  end
  object escalonamento_button: TButton
    Left = 1019
    Top = 35
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Escalonar'
    TabOrder = 22
    OnClick = escalonamento_buttonClick
  end
  object radio_reflexao: TRadioGroup
    Left = 917
    Top = 113
    Width = 171
    Height = 131
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Reflex'#227'o'
    ItemIndex = 2
    Items.Strings = (
      'X'
      'Y'
      'X e Y')
    TabOrder = 23
  end
  object reflexao_button: TButton
    Left = 958
    Top = 252
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Reflex'#227'o'
    TabOrder = 24
    OnClick = reflexao_buttonClick
  end
  object rodar_eixo_button: TButton
    Left = 917
    Top = 74
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rodar no Eixo'
    TabOrder = 25
    OnClick = rodar_eixo_buttonClick
  end
  object inicar_circ_button: TButton
    Left = 672
    Top = 73
    Width = 95
    Height = 32
    Caption = 'Inicar Circunf.'
    TabOrder = 26
    OnClick = inicar_circ_buttonClick
  end
  object casteljau_button: TButton
    Left = 891
    Top = 312
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Casteljau'
    TabOrder = 27
    OnClick = casteljau_buttonClick
  end
  object hermite_button: TButton
    Left = 890
    Top = 351
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Hermite'
    TabOrder = 28
    OnClick = hermite_buttonClick
  end
  object Button5: TButton
    Left = 993
    Top = 312
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Bezier'
    TabOrder = 29
    OnClick = Button5Click
  end
  object btnBspline: TButton
    Left = 993
    Top = 351
    Width = 94
    Height = 31
    Cursor = crHandPoint
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'B-Spline'
    TabOrder = 30
    OnClick = btnBsplineClick
  end
  object btnForwardBezier: TButton
    Left = 890
    Top = 389
    Width = 96
    Height = 32
    Cursor = crHandPoint
    Caption = 'Forward Bezier'
    TabOrder = 31
    OnClick = btnForwardBezierClick
  end
  object Button6: TButton
    Left = 544
    Top = 560
    Width = 94
    Height = 32
    Caption = 'Clipping'
    TabOrder = 32
    OnClick = Button6Click
  end
  object TranslacaoHomogeniaButton: TButton
    Left = 775
    Top = 146
    Width = 129
    Height = 33
    Caption = 'Transla'#231#227'o Homogenia'
    TabOrder = 33
    OnClick = TranslacaoHomogeniaButtonClick
  end
  object bt3D: TButton
    Left = 877
    Top = 472
    Width = 108
    Height = 33
    Caption = 'Novo Poligono 3D'
    TabOrder = 34
    OnClick = bt3DClick
  end
  object TipoPoligono3D: TRadioGroup
    Left = 751
    Top = 413
    Width = 120
    Height = 81
    Caption = 'Poligono 3D'
    Items.Strings = (
      'Cubo centro'
      'Cubo'
      'Piramide centro'
      'Piramide')
    TabOrder = 35
  end
  object tipoEixo3D: TRadioGroup
    Left = 672
    Top = 413
    Width = 73
    Height = 81
    Caption = 'Eixo'
    ItemIndex = 0
    Items.Strings = (
      'X'
      'Y'
      'Z'
      'XYZ')
    TabOrder = 36
  end
  object btRotaciona3D: TButton
    Left = 877
    Top = 546
    Width = 107
    Height = 34
    Caption = 'Rotaciona 3D'
    TabOrder = 37
    OnClick = btRotaciona3DClick
  end
  object btEscalona3D: TButton
    Left = 990
    Top = 511
    Width = 97
    Height = 33
    Caption = 'Escalona 3D'
    TabOrder = 38
    OnClick = btEscalona3DClick
  end
  object btTranslada3D: TButton
    Left = 991
    Top = 472
    Width = 97
    Height = 33
    Caption = 'Transla'#231#227'o 3D'
    TabOrder = 39
    OnClick = btTranslada3DClick
  end
  object rgTipoTransformacao: TRadioGroup
    Left = 672
    Top = 500
    Width = 97
    Height = 81
    Caption = 'Transforma'#231#227'o'
    ItemIndex = 0
    Items.Strings = (
      'Normal'
      'Homogenea')
    TabOrder = 40
  end
  object EditX3D: TEdit
    Left = 788
    Top = 500
    Width = 65
    Height = 23
    TabOrder = 41
    Text = '0'
  end
  object EditY3D: TEdit
    Left = 788
    Top = 523
    Width = 65
    Height = 23
    TabOrder = 42
    Text = '0'
  end
  object EditZ3D: TEdit
    Left = 788
    Top = 548
    Width = 65
    Height = 23
    TabOrder = 43
    Text = '0'
  end
  object editDRodar: TEdit
    Left = 903
    Top = 516
    Width = 43
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 44
    Text = '0'
  end
end
