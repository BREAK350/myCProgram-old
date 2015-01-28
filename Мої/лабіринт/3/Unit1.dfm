object Form1: TForm1
  Left = 193
  Top = 124
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 330
  ClientWidth = 350
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 24
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 48
    Top = 8
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N2: TMenuItem
        Caption = #1053#1086#1074#1072' '#1075#1088#1072
      end
      object N4: TMenuItem
        Caption = #1047#1072#1085#1086#1074#1086
        OnClick = N4Click
      end
      object N3: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1080' '#1082#1072#1088#1090#1091
        OnClick = N3Click
      end
    end
    object N5: TMenuItem
      Caption = #1057#1090#1080#1083#1100
      object N6: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1080
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1042#1080#1082#1083#1102#1095#1080#1090#1080
        OnClick = N7Click
      end
    end
  end
end
