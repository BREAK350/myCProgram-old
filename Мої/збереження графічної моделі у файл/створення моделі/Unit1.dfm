object Form1: TForm1
  Left = 192
  Top = 124
  Width = 923
  Height = 575
  Caption = 'Form1'
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 437
    Width = 907
    Height = 100
    Align = alBottom
    Color = clNavy
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 101
      Height = 24
      Caption = #1050#1091#1088#1089#1086#1088'(0;0)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 32
      Width = 89
      Height = 24
      Caption = #1058#1086#1095#1082#1072'(0;0)'
    end
    object Label3: TLabel
      Left = 632
      Top = 8
      Width = 135
      Height = 24
      Caption = #1042#1089#1100#1086#1075#1086' '#1090#1086#1095#1086#1082' 0'
    end
    object Label4: TLabel
      Left = 368
      Top = 8
      Width = 37
      Height = 24
      Caption = '(0;0)'
    end
    object Label6: TLabel
      Left = 368
      Top = 32
      Width = 37
      Height = 24
      Caption = '(0;0)'
    end
    object Button1: TButton
      Left = 304
      Top = 8
      Width = 41
      Height = 25
      Caption = '<'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 464
      Top = 8
      Width = 41
      Height = 25
      Caption = '>'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button4: TButton
      Left = 8
      Top = 64
      Width = 89
      Height = 25
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 3
      OnClick = Button4Click
    end
    object Edit1: TEdit
      Left = 632
      Top = 64
      Width = 225
      Height = 32
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = '*.model'
    end
    object Button5: TButton
      Left = 304
      Top = 32
      Width = 41
      Height = 25
      Caption = '<'
      TabOrder = 5
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 464
      Top = 32
      Width = 41
      Height = 25
      Caption = '>'
      TabOrder = 6
      OnClick = Button6Click
    end
    object Button9: TButton
      Left = 184
      Top = 8
      Width = 33
      Height = 25
      Caption = 'X+'
      TabOrder = 9
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 144
      Top = 8
      Width = 33
      Height = 25
      Caption = 'X-'
      TabOrder = 10
      OnClick = Button10Click
    end
    object Button11: TButton
      Left = 632
      Top = 32
      Width = 225
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1091' '#1092#1072#1081#1083':'
      TabOrder = 11
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 224
      Top = 8
      Width = 73
      Height = 25
      Caption = '<=='
      TabOrder = 12
    end
    object Button8: TButton
      Left = 144
      Top = 32
      Width = 33
      Height = 25
      Caption = 'Y-'
      TabOrder = 8
      OnClick = Button8Click
    end
    object Button7: TButton
      Left = 184
      Top = 32
      Width = 33
      Height = 25
      Caption = 'Y+'
      TabOrder = 7
      OnClick = Button7Click
    end
    object Button13: TButton
      Left = 144
      Top = 56
      Width = 33
      Height = 25
      Caption = 'Z-'
      TabOrder = 13
    end
    object Button14: TButton
      Left = 184
      Top = 56
      Width = 33
      Height = 25
      Caption = 'Z+'
      TabOrder = 14
    end
    object Button15: TButton
      Left = 224
      Top = 32
      Width = 73
      Height = 25
      Caption = '<=='
      TabOrder = 15
    end
    object Button16: TButton
      Left = 224
      Top = 56
      Width = 73
      Height = 25
      Caption = 'OK'
      TabOrder = 16
    end
    object Button3: TButton
      Left = 304
      Top = 56
      Width = 201
      Height = 25
      Caption = #1047#39#1108#1076#1085#1072#1090#1080
      TabOrder = 2
      OnClick = Button3Click
    end
  end
end
