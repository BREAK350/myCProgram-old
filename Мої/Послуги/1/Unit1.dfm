object FormMainMenu: TFormMainMenu
  Left = 459
  Top = 124
  BorderStyle = bsDialog
  Caption = #1056#1086#1079#1088#1072#1093#1091#1085#1082#1086#1074#1072' '#1082#1085#1080#1078#1082#1072
  ClientHeight = 217
  ClientWidth = 422
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object ButtonNaturalGas: TButton
    Left = 96
    Top = 48
    Width = 225
    Height = 49
    Caption = #1055#1088#1080#1088#1086#1076#1085#1080#1081' '#1075#1072#1079
    TabOrder = 0
    OnClick = ButtonNaturalGasClick
  end
  object ButtonWaterWaste: TButton
    Left = 96
    Top = 104
    Width = 225
    Height = 49
    Caption = #1042#1086#1076#1072' + '#1089#1084#1110#1090#1090#1103
    TabOrder = 1
  end
end
