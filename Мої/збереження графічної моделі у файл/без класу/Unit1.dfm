object Form1: TForm1
  Left = 189
  Top = 54
  Width = 1017
  Height = 659
  Caption = 'Form1'
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 200
    Height = 601
    Align = alLeft
    Color = clNavy
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 82
      Height = 16
      Caption = #1050#1091#1088#1089#1086#1088'(0;0;0)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 32
      Width = 75
      Height = 16
      Caption = #1058#1086#1095#1082#1072'(0;0;0)'
    end
    object Label3: TLabel
      Left = 8
      Top = 368
      Width = 96
      Height = 16
      Caption = #1042#1089#1100#1086#1075#1086' '#1090#1086#1095#1086#1082' 0'
    end
    object Label4: TLabel
      Left = 24
      Top = 240
      Width = 35
      Height = 16
      Caption = '(0;0;0)'
    end
    object Label6: TLabel
      Left = 24
      Top = 288
      Width = 35
      Height = 16
      Caption = '(0;0;0)'
    end
    object Label7: TLabel
      Left = 112
      Top = 104
      Width = 29
      Height = 16
      Caption = '+/-=1'
    end
    object Button1: TButton
      Left = 8
      Top = 208
      Width = 41
      Height = 25
      Caption = '<'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 48
      Top = 208
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
    object Button5: TButton
      Left = 8
      Top = 256
      Width = 41
      Height = 25
      Caption = '<'
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 48
      Top = 256
      Width = 41
      Height = 25
      Caption = '>'
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button9: TButton
      Left = 64
      Top = 128
      Width = 33
      Height = 25
      Caption = 'X+'
      TabOrder = 8
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 8
      Top = 128
      Width = 33
      Height = 25
      Caption = 'X-'
      TabOrder = 9
      OnClick = Button10Click
    end
    object Button8: TButton
      Left = 8
      Top = 152
      Width = 33
      Height = 25
      Caption = 'Y-'
      TabOrder = 7
      OnClick = Button8Click
    end
    object Button7: TButton
      Left = 64
      Top = 152
      Width = 33
      Height = 25
      Caption = 'Y+'
      TabOrder = 6
      OnClick = Button7Click
    end
    object Button13: TButton
      Left = 8
      Top = 176
      Width = 33
      Height = 25
      Caption = 'Z-'
      TabOrder = 10
      OnClick = Button13Click
    end
    object Button14: TButton
      Left = 64
      Top = 176
      Width = 33
      Height = 25
      Caption = 'Z+'
      TabOrder = 11
      OnClick = Button14Click
    end
    object Button3: TButton
      Left = 8
      Top = 304
      Width = 89
      Height = 25
      Caption = #1047#39#1108#1076#1085#1072#1090#1080
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button17: TButton
      Left = 8
      Top = 336
      Width = 89
      Height = 25
      Caption = #1042#1080#1076#1072#1083#1080#1090#1080
      TabOrder = 12
      OnClick = Button17Click
    end
    object Button18: TButton
      Left = 56
      Top = 96
      Width = 41
      Height = 25
      Caption = '*10'
      TabOrder = 13
      OnClick = Button18Click
    end
    object Button19: TButton
      Left = 8
      Top = 96
      Width = 41
      Height = 25
      Caption = '/10'
      TabOrder = 14
      OnClick = Button19Click
    end
  end
  object Panel2: TPanel
    Left = 801
    Top = 0
    Width = 200
    Height = 601
    Align = alRight
    Color = clNavy
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label5: TLabel
      Left = 8
      Top = 8
      Width = 126
      Height = 16
      Caption = #1058#1086#1095#1082#1072' '#1086#1073#1079#1086#1088#1091'(0;0;0)'
    end
    object Button11: TButton
      Left = 16
      Top = 32
      Width = 25
      Height = 25
      Caption = 'x-'
      TabOrder = 0
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 40
      Top = 32
      Width = 25
      Height = 25
      Caption = 'x+'
      TabOrder = 1
      OnClick = Button12Click
    end
    object Button15: TButton
      Left = 64
      Top = 32
      Width = 25
      Height = 25
      Caption = 'y-'
      TabOrder = 2
      OnClick = Button15Click
    end
    object Button16: TButton
      Left = 88
      Top = 32
      Width = 25
      Height = 25
      Caption = 'y+'
      TabOrder = 3
      OnClick = Button16Click
    end
    object Button20: TButton
      Left = 112
      Top = 32
      Width = 25
      Height = 25
      Caption = 'z-'
      TabOrder = 4
      OnClick = Button20Click
    end
    object Button21: TButton
      Left = 136
      Top = 32
      Width = 25
      Height = 25
      Caption = 'z+'
      TabOrder = 5
      OnClick = Button21Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 200
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      OnClick = N1Click
      object N2: TMenuItem
        Caption = #1053#1086#1074#1072' '#1084#1086#1076#1077#1083#1100
      end
      object N3: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      end
      object N5: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082'...'
        OnClick = N5Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    FileName = 
      'D:\'#1056#1086#1079#1074#1072#1075#1080'\'#1087#1088#1086#1075#1088#1072#1084#1080' '#1057'++\'#1052#1086#1111'\'#1079#1073#1077#1088#1077#1078#1077#1085#1085#1103' '#1075#1088#1072#1092#1110#1095#1085#1086#1111' '#1084#1086#1076#1077#1083#1110' '#1091' '#1092#1072#1081#1083'\'#1073 +
      #1077#1079' '#1082#1083#1072#1089#1091'\CreateModel.~cpp'
    FilterIndex = 0
    Left = 232
  end
  object SaveDialog1: TSaveDialog
    Left = 264
  end
end
