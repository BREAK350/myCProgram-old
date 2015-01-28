object Form1: TForm1
  Left = 202
  Top = 44
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 567
  ClientWidth = 925
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  PixelsPerInch = 96
  TextHeight = 24
  object Label1: TLabel
    Left = 8
    Top = 40
    Width = 105
    Height = 24
    Caption = #1042#1072#1096#1077' '#1089#1083#1086#1074#1086
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 76
    Height = 24
    Caption = #1043#1088#1072#1074#1077#1094#1100
  end
  object Label3: TLabel
    Left = 128
    Top = 8
    Width = 76
    Height = 24
    Caption = #1043#1088#1072#1074#1077#1094#1100
  end
  object Edit2: TEdit
    Left = 128
    Top = 40
    Width = 153
    Height = 32
    TabOrder = 0
    OnKeyDown = Edit2KeyDown
  end
  object Memo1: TMemo
    Left = 16
    Top = 80
    Width = 185
    Height = 361
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    Left = 224
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N4: TMenuItem
        Caption = #1047#1072#1085#1086#1074#1086
        OnClick = N4Click
      end
      object N3: TMenuItem
        Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
        OnClick = N3Click
      end
      object N6: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = N6Click
      end
      object N5: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
        OnClick = N5Click
      end
    end
    object N2: TMenuItem
      Caption = #1054#1087#1094#1110#1111
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 256
  end
  object OpenDialog1: TOpenDialog
    Left = 288
  end
end
