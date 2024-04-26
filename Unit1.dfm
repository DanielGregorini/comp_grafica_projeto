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
    Left = 17
    Top = 564
    Width = 27
    Height = 15
    Caption = 'LBVP'
  end
  object LBMUNDO: TLabel
    Left = 460
    Top = 564
    Width = 58
    Height = 15
    Caption = 'LBMUNDO'
  end
  object POLIGONOS: TLabel
    Left = 528
    Top = 9
    Width = 66
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'POLIGONOS'
  end
  object PONTOS: TLabel
    Left = 528
    Top = 165
    Width = 45
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'PONTOS'
  end
  object Label1: TLabel
    Left = 593
    Top = 317
    Width = 27
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'xMin'
  end
  object Label2: TLabel
    Left = 100
    Top = 540
    Width = 34
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 592
    Top = 421
    Width = 27
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'yMin'
  end
  object Label4: TLabel
    Left = 590
    Top = 367
    Width = 29
    Height = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'xMax'
  end
  object Label5: TLabel
    Left = 590
    Top = 470
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
    Left = 814
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
    Left = 814
    Top = 65
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
    Top = 329
    Width = 36
    Height = 15
    Caption = 'Curvas'
  end
  object Panel1: TPanel
    Left = 16
    Top = 56
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
      ExplicitTop = -29
    end
  end
  object Button1: TButton
    Left = 558
    Top = 517
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
    Left = 528
    Top = 32
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
    Left = 525
    Top = 188
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
    Left = 687
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
    Left = 528
    Top = 332
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
    Left = 528
    Top = 436
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
    Left = 528
    Top = 382
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
    Left = 528
    Top = 486
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
    Left = 758
    Top = 188
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
    Left = 821
    Top = 227
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
    Left = 758
    Top = 227
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
    Left = 695
    Top = 227
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
    Left = 695
    Top = 274
    Width = 70
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '+'
    TabOrder = 13
    OnClick = ZoomInButtonClick
  end
  object ZoomOutButton: TButton
    Left = 806
    Top = 272
    Width = 70
    Height = 37
    Caption = '-'
    TabOrder = 14
    OnClick = ZoomOutButtonClick
  end
  object Button3: TButton
    Left = 687
    Top = 122
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Fazer linha'
    TabOrder = 15
    OnClick = Button3Click
  end
  object rgTipoReta: TRadioGroup
    Left = 695
    Top = 325
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
    TabOrder = 16
  end
  object edx: TEdit
    Left = 806
    Top = 34
    Width = 77
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 17
    Text = '0'
  end
  object edy: TEdit
    Left = 806
    Top = 91
    Width = 77
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 18
    Text = '0'
  end
  object Translação: TButton
    Left = 806
    Top = 122
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Transla'#231#227'o'
    TabOrder = 19
    OnClick = TranslaçãoClick
  end
  object anguloRotacao: TEdit
    Left = 942
    Top = 27
    Width = 43
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 20
    Text = '0'
  end
  object Button4: TButton
    Left = 917
    Top = 58
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rodar'
    TabOrder = 21
    OnClick = Button4Click
  end
  object escalonamento_edit: TEdit
    Left = 1040
    Top = 27
    Width = 47
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 22
    Text = '0'
  end
  object escalonamento_button: TButton
    Left = 1019
    Top = 58
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Escalonar'
    TabOrder = 23
    OnClick = escalonamento_buttonClick
  end
  object radio_reflexao: TRadioGroup
    Left = 917
    Top = 136
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
    TabOrder = 24
  end
  object reflexao_button: TButton
    Left = 958
    Top = 272
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Reflex'#227'o'
    TabOrder = 25
    OnClick = reflexao_buttonClick
  end
  object rodar_eixo_button: TButton
    Left = 917
    Top = 97
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Rodar no Eixo'
    TabOrder = 26
    OnClick = rodar_eixo_buttonClick
  end
  object inicar_circ_button: TButton
    Left = 686
    Top = 73
    Width = 95
    Height = 32
    Caption = 'Inicar Circunf.'
    TabOrder = 27
    OnClick = inicar_circ_buttonClick
  end
  object casteljau_button: TButton
    Left = 891
    Top = 351
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Casteljau'
    TabOrder = 28
    OnClick = casteljau_buttonClick
  end
  object hermite_button: TButton
    Left = 890
    Top = 390
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Hermite'
    TabOrder = 29
    OnClick = hermite_buttonClick
  end
  object Button5: TButton
    Left = 993
    Top = 351
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'Bezier'
    TabOrder = 30
    OnClick = Button5Click
  end
  object btnBspline: TButton
    Left = 993
    Top = 390
    Width = 94
    Height = 31
    Cursor = crHandPoint
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'B-Spline'
    TabOrder = 31
    OnClick = btnBsplineClick
  end
  object btnForwardBezier: TButton
    Left = 890
    Top = 428
    Width = 96
    Height = 32
    Cursor = crHandPoint
    Caption = 'Forward Bezier'
    TabOrder = 32
    OnClick = btnForwardBezierClick
  end
end
