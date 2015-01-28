object Form1: TForm1
  Left = 204
  Top = 128
  BorderStyle = bsSingle
  Caption = #1057#1083#1086#1074#1085#1080#1082
  ClientHeight = 208
  ClientWidth = 460
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 160
    Top = 24
    Width = 121
    Height = 20
    Caption = #1044#1086#1076#1072#1090#1080' '#1089#1083#1086#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 88
    Width = 105
    Height = 16
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1089#1083#1110#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 176
    Top = 88
    Width = 11
    Height = 20
    Caption = '0'
  end
  object fname: TLabel
    Left = 48
    Top = 112
    Width = 97
    Height = 16
    Caption = #1041#1077#1079' '#1085#1072#1079#1074#1080'.txt'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 48
    Top = 56
    Width = 361
    Height = 28
    TabOrder = 0
    OnKeyDown = Edit1KeyDown
  end
  object Edit2: TEdit
    Left = 48
    Top = 144
    Width = 361
    Height = 28
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 8
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N2: TMenuItem
        Caption = #1054#1073#39#1108#1076#1085#1072#1090#1080' '#1079' '#1092#1072#1081#1083#1086#1084'...'
        OnClick = N2Click
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
        OnClick = N4Click
      end
      object N3: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082'...'
        OnClick = N3Click
      end
      object N5: TMenuItem
        Caption = #1042#1080#1093#1110#1076
        OnClick = N5Click
      end
    end
    object N6: TMenuItem
      Caption = #1054#1087#1094#1110#1111
      object N7: TMenuItem
        Caption = #1055#1077#1088#1077#1074#1110#1088#1082#1072' '#1089#1083#1110#1074': '#1074#1082#1083
        OnClick = N7Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 56
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Left = 8
    Top = 40
  end
end
