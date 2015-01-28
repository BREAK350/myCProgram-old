object Form1: TForm1
  Left = 198
  Top = 127
  Width = 928
  Height = 500
  Caption = 'Form1'
  Color = clWhite
  Constraints.MinHeight = 500
  Constraints.MinWidth = 900
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
  object Panel2: TPanel
    Left = 0
    Top = 208
    Width = 193
    Height = 153
    Color = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    object Label8: TLabel
      Left = 8
      Top = 32
      Width = 46
      Height = 16
      Caption = #1042#1086#1075#1086#1085#1100
    end
    object LabelFire: TLabel
      Left = 72
      Top = 32
      Width = 22
      Height = 16
      Caption = #1074#1086#1075
    end
    object Label10: TLabel
      Left = 8
      Top = 56
      Width = 33
      Height = 16
      Caption = #1042#1086#1076#1072
    end
    object LabelWater: TLabel
      Left = 72
      Top = 56
      Width = 24
      Height = 16
      Caption = #1074#1086#1076
    end
    object Label12: TLabel
      Left = 8
      Top = 81
      Width = 41
      Height = 16
      Caption = #1047#1077#1084#1083#1103
    end
    object LabelEarth: TLabel
      Left = 72
      Top = 80
      Width = 25
      Height = 16
      Caption = #1079#1077#1084
    end
    object Label14: TLabel
      Left = 8
      Top = 104
      Width = 51
      Height = 16
      Caption = #1055#1086#1074#1110#1090#1088#1103
    end
    object LabelAir: TLabel
      Left = 72
      Top = 104
      Width = 24
      Height = 16
      Caption = #1087#1086#1074
    end
    object Label21: TLabel
      Left = 72
      Top = 8
      Width = 23
      Height = 16
      Caption = #1090#1080#1087
    end
    object Button7: TButton
      Left = 56
      Top = 128
      Width = 75
      Height = 17
      Caption = #1047#1072#1082#1088#1080#1090#1080
      TabOrder = 0
    end
  end
  object PanelInfo: TPanel
    Left = 0
    Top = 1
    Width = 265
    Height = 208
    Color = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 28
      Height = 16
      Caption = #1042#1086#1111#1085
    end
    object LabelName: TLabel
      Left = 128
      Top = 16
      Width = 22
      Height = 16
      Caption = #1030#1084#39#1103
    end
    object Label3: TLabel
      Left = 8
      Top = 40
      Width = 96
      Height = 16
      Caption = #1056#1086#1079#1090#1072#1096#1091#1074#1072#1085#1085#1103
    end
    object LabelXY: TLabel
      Left = 128
      Top = 40
      Width = 31
      Height = 16
      Caption = #1082#1086#1088#1080
    end
    object Label5: TLabel
      Left = 8
      Top = 64
      Width = 42
      Height = 16
      Caption = #1046#1080#1090#1090#1103
    end
    object LabelLife: TLabel
      Left = 128
      Top = 64
      Width = 22
      Height = 16
      Caption = #1078'/'#1078
    end
    object Label7: TLabel
      Left = 8
      Top = 88
      Width = 42
      Height = 16
      Caption = #1040#1090#1072#1082#1072':'
    end
    object Label16: TLabel
      Left = 8
      Top = 136
      Width = 45
      Height = 16
      Caption = #1047#1072#1093#1080#1089#1090
    end
    object Label17: TLabel
      Left = 24
      Top = 112
      Width = 64
      Height = 16
      Caption = #1044#1072#1083#1100#1085#1110#1089#1090#1100
    end
    object LabelAttackRadius: TLabel
      Left = 128
      Top = 112
      Width = 114
      Height = 16
      Caption = 'LabelAttackRadius'
    end
    object Label19: TLabel
      Left = 8
      Top = 160
      Width = 115
      Height = 16
      Caption = #1044#1072#1083#1100#1085#1110#1089#1090#1100' '#1093#1086#1076#1110#1085#1085#1103
    end
    object LabelWalkingRadius: TLabel
      Left = 136
      Top = 160
      Width = 14
      Height = 16
      Caption = #1076#1093
    end
    object ButtonAttack: TButton
      Left = 128
      Top = 88
      Width = 75
      Height = 17
      Caption = #1055#1086#1082#1072#1079#1072#1090#1080
      TabOrder = 0
    end
    object ButtonProtection: TButton
      Left = 128
      Top = 136
      Width = 75
      Height = 17
      Caption = #1055#1086#1082#1072#1079#1072#1090#1080
      TabOrder = 1
    end
    object ButtonClose: TButton
      Left = 88
      Top = 184
      Width = 75
      Height = 17
      Caption = #1047#1072#1082#1088#1080#1090#1080
      TabOrder = 2
      OnClick = ButtonCloseClick
    end
  end
  object Button9: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 17
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080
    TabOrder = 2
    Visible = False
    OnClick = Button9Click
  end
  object MainMenu1: TMainMenu
    Left = 96
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = N2Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 136
  end
end
