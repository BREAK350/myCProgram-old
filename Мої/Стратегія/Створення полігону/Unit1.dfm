object Form1: TForm1
  Left = 203
  Top = 131
  Width = 868
  Height = 529
  Caption = 'Form1'
  Color = clWhite
  Constraints.MinHeight = 400
  Constraints.MinWidth = 600
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
    Left = 596
    Top = 0
    Width = 256
    Height = 471
    Align = alRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 96
      Width = 118
      Height = 20
      Caption = #1055#1086#1090#1086#1095#1085#1072' '#1090#1086#1095#1082#1072':'
    end
    object Label2: TLabel
      Left = 24
      Top = 120
      Width = 7
      Height = 20
      Caption = 'x'
    end
    object Label3: TLabel
      Left = 24
      Top = 152
      Width = 7
      Height = 20
      Caption = 'y'
    end
    object Label4: TLabel
      Left = 120
      Top = 24
      Width = 7
      Height = 20
      Caption = 'x'
    end
    object Label5: TLabel
      Left = 120
      Top = 56
      Width = 7
      Height = 20
      Caption = 'y'
    end
    object Label6: TLabel
      Left = 160
      Top = 96
      Width = 48
      Height = 20
      Caption = 'Label6'
    end
    object Label7: TLabel
      Left = 24
      Top = 192
      Width = 70
      Height = 20
      Caption = #1052#1072#1089#1096#1090#1072#1073
    end
    object Button1: TButton
      Left = 24
      Top = 24
      Width = 75
      Height = 25
      Caption = #1055#1077#1085#1079#1077#1083#1100
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 24
      Top = 56
      Width = 75
      Height = 25
      Caption = #1054#1083#1110#1074#1077#1094#1100
      TabOrder = 1
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 40
      Top = 120
      Width = 57
      Height = 28
      TabOrder = 2
      Text = '0'
    end
    object Edit2: TEdit
      Left = 40
      Top = 152
      Width = 57
      Height = 28
      TabOrder = 3
      Text = '0'
    end
    object Button3: TButton
      Left = 112
      Top = 120
      Width = 75
      Height = 25
      Caption = #1047#1084#1110#1085#1080#1090#1080
      TabOrder = 4
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 24
      Top = 232
      Width = 161
      Height = 25
      Caption = #1042#1074#1077#1088#1093' '#1087#1086' '#1084#1072#1089#1080#1074#1091
      TabOrder = 5
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 24
      Top = 264
      Width = 161
      Height = 25
      Caption = #1042#1085#1080#1079' '#1087#1086' '#1084#1072#1089#1080#1074#1091
      TabOrder = 6
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 24
      Top = 296
      Width = 89
      Height = 25
      Caption = #1042#1080#1076#1072#1083#1080#1090#1080
      TabOrder = 7
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 112
      Top = 152
      Width = 75
      Height = 25
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 8
      OnClick = Button7Click
    end
    object Edit3: TEdit
      Left = 136
      Top = 24
      Width = 49
      Height = 28
      TabOrder = 9
      Text = '0'
    end
    object Edit4: TEdit
      Left = 136
      Top = 56
      Width = 49
      Height = 28
      TabOrder = 10
      Text = '0'
    end
    object Button8: TButton
      Left = 192
      Top = 24
      Width = 41
      Height = 57
      Caption = 'OK'
      TabOrder = 11
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 200
      Top = 120
      Width = 33
      Height = 25
      Caption = '-x'
      TabOrder = 12
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 200
      Top = 152
      Width = 33
      Height = 25
      Caption = '-y'
      TabOrder = 13
      OnClick = Button10Click
    end
    object Edit5: TEdit
      Left = 104
      Top = 192
      Width = 81
      Height = 28
      TabOrder = 14
      Text = '1'
    end
    object Button11: TButton
      Left = 192
      Top = 192
      Width = 41
      Height = 25
      Caption = 'OK'
      TabOrder = 15
      OnClick = Button11Click
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 8
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 48
    Top = 8
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080' '#1087#1088#1086#1077#1082#1090
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1087#1088#1086#1077#1082#1090
        OnClick = N4Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 88
    Top = 8
  end
  object OpenDialog1: TOpenDialog
    Left = 128
    Top = 8
  end
end
