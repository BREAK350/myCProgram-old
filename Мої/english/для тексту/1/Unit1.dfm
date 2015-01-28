object Form1: TForm1
  Left = 192
  Top = 124
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 408
  ClientWidth = 1011
  Color = clBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlue
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 24
  object Memo1: TMemo
    Left = 16
    Top = 16
    Width = 785
    Height = 265
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Lines.Strings = (
      #1055#1088#1086#1073#1085#1080#1081' '#1090#1077#1082#1089#1090'...('#1072#1085#1075#1083#1110#1081#1089#1100#1082#1080#1081' '#1090#1077#1082#1089#1090')')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnMouseMove = Memo1MouseMove
  end
  object Memo2: TMemo
    Left = 16
    Top = 296
    Width = 881
    Height = 89
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Lines.Strings = (
      #1055#1088#1086#1073#1085#1080#1081' '#1090#1077#1082#1089#1090'...('#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095' '#1074#1074#1086#1076#1080#1090#1100' '#1072#1085#1075#1083' '#1090#1077#1082#1089#1090' '#1076#1083#1103' '#1087#1077#1088#1077#1074#1110#1088#1082#1080')')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    OnMouseMove = Memo2MouseMove
  end
  object Button1: TButton
    Left = 904
    Top = 296
    Width = 89
    Height = 41
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
    OnMouseMove = Button1MouseMove
  end
  object Button2: TButton
    Left = 904
    Top = 344
    Width = 89
    Height = 41
    Caption = #1057#1090#1077#1088#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
    OnMouseMove = Button2MouseMove
  end
  object Memo3: TMemo
    Left = 816
    Top = 16
    Width = 177
    Height = 217
    Lines.Strings = (
      #1055#1110#1076#1089#1082#1072#1079#1082#1080'...')
    ScrollBars = ssVertical
    TabOrder = 4
    OnMouseMove = Memo3MouseMove
  end
  object Button3: TButton
    Left = 824
    Top = 240
    Width = 161
    Height = 41
    Caption = #1054#1085#1086#1074#1080#1090#1080
    TabOrder = 5
    OnClick = Button3Click
    OnMouseMove = Button3MouseMove
  end
  object MainMenu1: TMainMenu
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1053#1086#1074#1080#1081
      end
      object N3: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      end
    end
    object N5: TMenuItem
      Caption = #1056#1077#1078#1080#1084
      object N6: TMenuItem
        Caption = #1059#1074#1077#1089#1100' '#1090#1077#1082#1089#1090
      end
      object N7: TMenuItem
        Caption = #1054#1076#1085#1077' '#1088#1077#1095#1077#1085#1085#1103
        object N8: TMenuItem
          Caption = #1062#1110#1083#1082#1086#1084
        end
        object N9: TMenuItem
          Caption = #1041#1077#1079' '#1076#1077#1103#1082#1080#1093' '#1089#1083#1110#1074
        end
        object N10: TMenuItem
          Caption = #1055#1086#1083#1086#1074#1080#1085#1072
        end
        object N11: TMenuItem
          Caption = #1047' '#1087#1077#1088#1077#1084#1110#1096#1077#1085#1080#1084#1080' '#1089#1083#1086#1074#1072#1084#1080
        end
      end
      object N12: TMenuItem
        Caption = #1064#1088#1080#1092#1090
        object N13: TMenuItem
          Caption = #1047#1073#1110#1083#1100#1096#1080#1090#1080
          OnClick = N13Click
        end
        object N14: TMenuItem
          Caption = #1047#1084#1077#1085#1096#1080#1090#1080
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 40
  end
end
