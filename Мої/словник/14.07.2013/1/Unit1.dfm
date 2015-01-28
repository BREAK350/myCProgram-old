object Dictionary: TDictionary
  Left = 229
  Top = 135
  BorderStyle = bsDialog
  Caption = #1057#1083#1086#1074#1085#1080#1082
  ClientHeight = 293
  ClientWidth = 819
  Color = clBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 20
  object SpeedButtonAdd: TSpeedButton
    Left = 16
    Top = 56
    Width = 153
    Height = 41
    Caption = #1044#1086#1076#1072#1090#1080
    OnClick = SpeedButtonAddClick
  end
  object SpeedButtonEdit: TSpeedButton
    Left = 16
    Top = 112
    Width = 153
    Height = 41
    Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
    OnClick = SpeedButtonEditClick
  end
  object SpeedButtonDelete: TSpeedButton
    Left = 16
    Top = 168
    Width = 153
    Height = 41
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080
    OnClick = SpeedButtonDeleteClick
  end
  object SpeedButtonSearch: TSpeedButton
    Left = 648
    Top = 56
    Width = 153
    Height = 41
    Caption = #1055#1086#1096#1091#1082
    OnClick = SpeedButtonSearchClick
  end
  object SpeedButtonNext: TSpeedButton
    Left = 648
    Top = 112
    Width = 153
    Height = 41
    Caption = #1053#1072#1089#1090#1091#1087#1085#1077
  end
  object SpeedButtonSettings: TSpeedButton
    Left = 648
    Top = 168
    Width = 153
    Height = 41
    Caption = #1053#1072#1083#1072#1096#1090#1091#1074#1072#1085#1085#1103
  end
  object RadioButtonEng: TRadioButton
    Left = 184
    Top = 64
    Width = 113
    Height = 17
    Caption = #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
    Checked = True
    Color = clBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    TabStop = True
  end
  object RadioButtonUkr: TRadioButton
    Left = 184
    Top = 120
    Width = 113
    Height = 17
    Caption = #1059#1082#1088#1072#1111#1085#1089#1100#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object English: TEdit
    Left = 304
    Top = 56
    Width = 329
    Height = 28
    TabOrder = 2
    OnClick = EnglishClick
    OnKeyPress = EnglishKeyPress
  end
  object Ukranian: TEdit
    Left = 304
    Top = 120
    Width = 329
    Height = 28
    TabOrder = 3
    OnClick = UkranianClick
    OnKeyPress = UkranianKeyPress
  end
  object Mess: TEdit
    Left = 184
    Top = 184
    Width = 449
    Height = 28
    ReadOnly = True
    TabOrder = 4
  end
end
