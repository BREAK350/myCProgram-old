object Form1: TForm1
  Left = 202
  Top = 127
  Caption = 'Create Labirynt'
  ClientHeight = 450
  ClientWidth = 400
  Color = clBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlue
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 24
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 289
    Height = 241
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 40
      Top = 88
      Width = 23
      Height = 24
      Caption = 'P='
    end
    object Label2: TLabel
      Left = 40
      Top = 120
      Width = 25
      Height = 24
      Caption = 'N='
    end
    object Label3: TLabel
      Left = 40
      Top = 152
      Width = 27
      Height = 24
      Caption = 'M='
    end
    object RadioButton1: TRadioButton
      Left = 32
      Top = 24
      Width = 201
      Height = 17
      Caption = #1059' '#1076#1086#1076#1072#1090#1085#1102' '#1089#1090#1086#1088#1086#1085#1091
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 32
      Top = 48
      Width = 201
      Height = 17
      Caption = #1059' '#1074#1110#1076#39#1108#1084#1085#1091' '#1089#1090#1086#1088#1086#1085#1091
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 72
      Top = 88
      Width = 121
      Height = 32
      TabOrder = 2
    end
    object Edit2: TEdit
      Left = 72
      Top = 120
      Width = 121
      Height = 32
      TabOrder = 3
    end
    object Edit3: TEdit
      Left = 72
      Top = 152
      Width = 121
      Height = 32
      TabOrder = 4
    end
    object BitBtn1: TBitBtn
      Left = 104
      Top = 192
      Width = 89
      Height = 33
      Caption = 'OK'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 5
      OnClick = BitBtn1Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N10: TMenuItem
        Caption = #1053#1086#1074#1080#1081
        OnClick = N10Click
      end
      object N11: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = N11Click
      end
      object N12: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082' ..'
        OnClick = N12Click
      end
      object N13: TMenuItem
        Caption = #1042#1080#1093#1110#1076
        OnClick = N13Click
      end
    end
    object N2: TMenuItem
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
      object N8: TMenuItem
        Caption = #1042#1080#1073#1088#1072#1090#1080' '#1076#1083#1103' '#1076#1086#1076#1072#1074#1072#1085#1085#1103
        object N9: TMenuItem
          Caption = #1055#1086#1095#1072#1090#1086#1082' '#1083#1072#1073#1110#1088#1080#1085#1090#1091
          OnClick = N9Click
        end
        object N18: TMenuItem
          Caption = #1050#1110#1085#1077#1094#1100' '#1083#1072#1073#1110#1088#1080#1085#1090#1091
          OnClick = N18Click
        end
        object N19: TMenuItem
          Caption = #1044#1086#1088#1086#1075#1091
          OnClick = N19Click
        end
        object N20: TMenuItem
          Caption = #1057#1090#1110#1085#1091
          OnClick = N20Click
        end
        object N14: TMenuItem
          Caption = #1053#1072#1087#1086#1083#1086#1074#1080#1085#1091' '#1089#1090#1110#1085#1091
          OnClick = N14Click
        end
        object N16: TMenuItem
          Caption = #1057#1093#1086#1076#1080' '#1076#1083#1103' '#1087#1110#1076#1081#1086#1084#1091
          OnClick = N16Click
        end
        object N17: TMenuItem
          Caption = #1089#1093#1086#1076#1080' '#1076#1083#1103' '#1089#1087#1091#1089#1082#1091
          OnClick = N17Click
        end
      end
      object N15: TMenuItem
        Caption = #1047#1072#1076#1072#1090#1080' '#1088#1086#1079#1084#1110#1088#1080' '#1083#1072#1073#1110#1088#1080#1085#1090#1091
        OnClick = N15Click
      end
    end
    object N3: TMenuItem
      Caption = #1042#1080#1076
      object N4: TMenuItem
        Caption = #1047#1084#1077#1085#1096#1080#1090#1080'(Pixel)'
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1047#1073#1110#1083#1100#1096#1080#1090#1080'(Pixel)'
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1047#1084#1077#1085#1096#1080#1090#1080'('#1050#1074#1072#1076#1088#1072#1090#1080')'
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1047#1073#1110#1083#1100#1096#1080#1090#1080'('#1082#1074#1072#1076#1088#1072#1090#1080')'
        OnClick = N7Click
      end
      object N7750501: TMenuItem
        Caption = '7'#1093'7, 50'#1093'50'
        OnClick = N7750501Click
      end
      object N10x1035x351: TMenuItem
        Caption = '11x11, 35x35'
        OnClick = N10x1035x351Click
      end
      object N21x2125x251: TMenuItem
        Caption = '21x21, 25x25'
        OnClick = N21x2125x251Click
      end
      object N49x4910x101: TMenuItem
        Caption = '49x49, 10x10'
        OnClick = N49x4910x101Click
      end
    end
    object N21: TMenuItem
      Caption = #1057#1090#1080#1083#1100
      object N22: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1080
        OnClick = N22Click
      end
      object N23: TMenuItem
        Caption = #1042#1080#1082#1083#1102#1095#1080#1090#1080
        OnClick = N23Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 48
    Top = 16
  end
  object OpenDialog1: TOpenDialog
    Left = 88
    Top = 16
  end
end
