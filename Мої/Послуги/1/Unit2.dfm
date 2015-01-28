object FormNaturalGas: TFormNaturalGas
  Left = 387
  Top = 123
  BorderStyle = bsDialog
  Caption = #1055#1088#1080#1088#1086#1076#1085#1080#1081' '#1075#1072#1079
  ClientHeight = 388
  ClientWidth = 557
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object LabelPersonalAccount: TLabel
    Left = 40
    Top = 24
    Width = 192
    Height = 24
    Caption = #1054#1089#1086#1073#1086#1074#1080#1081' '#1088#1072#1093#1091#1085#1086#1082' '#8470
  end
  object LabelBy: TLabel
    Left = 40
    Top = 64
    Width = 20
    Height = 24
    Caption = #1079#1072
  end
  object LabelMonth: TLabel
    Left = 264
    Top = 64
    Width = 59
    Height = 24
    Caption = #1084#1110#1089#1103#1094#1100
  end
  object LabelYear: TLabel
    Left = 456
    Top = 64
    Width = 40
    Height = 24
    Caption = #1088#1086#1082#1091
  end
  object LabelNameAndAddress: TLabel
    Left = 184
    Top = 152
    Width = 131
    Height = 24
    Caption = '('#1055'.'#1030'.'#1041'., '#1072#1076#1088#1077#1089#1072')'
  end
  object LabelGasDate: TLabel
    Left = 40
    Top = 192
    Width = 235
    Height = 24
    Caption = #1055#1086#1082#1072#1079#1080' '#1083#1110#1095#1080#1083#1100#1085#1080#1082#1072' ('#1084'.'#1082#1091#1073'.)'
  end
  object LabelTerminal: TLabel
    Left = 40
    Top = 232
    Width = 79
    Height = 24
    Caption = #1082#1110#1085#1094#1077#1074#1080#1081
  end
  object LabelInitial: TLabel
    Left = 136
    Top = 232
    Width = 105
    Height = 24
    Caption = #1087#1086#1095#1072#1090#1082#1086#1074#1080#1081
  end
  object LabelDifference: TLabel
    Left = 256
    Top = 232
    Width = 68
    Height = 24
    Caption = #1088#1110#1079#1085#1080#1094#1103
  end
  object LabelPrice: TLabel
    Left = 336
    Top = 232
    Width = 95
    Height = 24
    Caption = #1094#1110#1085#1072' '#1079#1072' '#1082#1091#1073
  end
  object LabelSum: TLabel
    Left = 448
    Top = 232
    Width = 81
    Height = 24
    Caption = #1057#1091#1084#1072' '#1075#1088#1085
  end
  object EditPersonalAccount: TEdit
    Left = 248
    Top = 16
    Width = 121
    Height = 32
    ReadOnly = True
    TabOrder = 0
  end
  object EditNameAndAddress: TEdit
    Left = 40
    Top = 112
    Width = 457
    Height = 32
    ReadOnly = True
    TabOrder = 1
    Text = #1064#1091#1090#1072#1082' '#1051'.'#1052'. '#1055#1091#1096#1082#1110#1085#1072', 22'
  end
  object EditTerminal: TEdit
    Left = 40
    Top = 272
    Width = 89
    Height = 32
    TabOrder = 2
  end
  object EditInitial: TEdit
    Left = 144
    Top = 272
    Width = 89
    Height = 32
    TabOrder = 3
  end
  object EditDifference: TEdit
    Left = 248
    Top = 272
    Width = 89
    Height = 32
    TabOrder = 4
  end
  object EditPrice: TEdit
    Left = 344
    Top = 272
    Width = 89
    Height = 32
    TabOrder = 5
    Text = '0,7254'
  end
  object EditSum: TEdit
    Left = 440
    Top = 272
    Width = 89
    Height = 32
    ReadOnly = True
    TabOrder = 6
  end
  object ButtonOK: TButton
    Left = 432
    Top = 336
    Width = 113
    Height = 33
    Caption = #1044#1086#1073#1088#1077
    TabOrder = 7
    OnClick = ButtonOKClick
  end
  object EditMonth: TEdit
    Left = 72
    Top = 64
    Width = 177
    Height = 32
    ReadOnly = True
    TabOrder = 8
  end
  object EditYear: TEdit
    Left = 336
    Top = 64
    Width = 113
    Height = 32
    ReadOnly = True
    TabOrder = 9
  end
end
