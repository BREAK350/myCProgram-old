object Form1: TForm1
  Left = 203
  Top = 137
  Width = 928
  Height = 481
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 16
    Top = 8
    Width = 449
    Height = 385
  end
  object Panel1: TPanel
    Left = 480
    Top = 8
    Width = 217
    Height = 193
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 115
      Height = 13
      Caption = #1056#1086#1079#1087#1086#1083#1086#1078#1077#1085#1085#1103' '#1086#1073#39#1108#1082#1090#1072
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 40
      Height = 13
      Caption = #1055#1086#1079#1080#1094#1110#1103
    end
    object Label3: TLabel
      Left = 88
      Top = 40
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object Label4: TLabel
      Left = 128
      Top = 40
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object Label5: TLabel
      Left = 168
      Top = 40
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object Label6: TLabel
      Left = 16
      Top = 88
      Width = 43
      Height = 13
      Caption = #1055#1086#1074#1086#1088#1086#1090
    end
    object Label7: TLabel
      Left = 16
      Top = 120
      Width = 46
      Height = 13
      Caption = #1052#1072#1089#1096#1090#1072#1073
    end
    object Edit1: TEdit
      Left = 80
      Top = 56
      Width = 33
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit2: TEdit
      Left = 120
      Top = 56
      Width = 33
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Edit3: TEdit
      Left = 160
      Top = 56
      Width = 33
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object Edit4: TEdit
      Left = 80
      Top = 88
      Width = 33
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object Edit5: TEdit
      Left = 120
      Top = 88
      Width = 33
      Height = 21
      TabOrder = 4
      Text = '0'
    end
    object Edit6: TEdit
      Left = 160
      Top = 88
      Width = 33
      Height = 21
      TabOrder = 5
      Text = '0'
    end
    object Edit7: TEdit
      Left = 80
      Top = 120
      Width = 33
      Height = 21
      TabOrder = 6
      Text = '1'
    end
    object Edit8: TEdit
      Left = 120
      Top = 120
      Width = 33
      Height = 21
      TabOrder = 7
      Text = '1'
    end
    object Edit9: TEdit
      Left = 160
      Top = 120
      Width = 33
      Height = 21
      TabOrder = 8
      Text = '1'
    end
    object Button1: TButton
      Left = 64
      Top = 152
      Width = 75
      Height = 25
      Caption = #1044#1086#1073#1088#1077
      TabOrder = 9
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 480
    Top = 208
    Width = 177
    Height = 81
    TabOrder = 1
    object Label8: TLabel
      Left = 48
      Top = 8
      Width = 65
      Height = 13
      Caption = #1044#1083#1103' '#1087#1088#1086#1077#1082#1094#1110#1111
    end
    object Edit10: TEdit
      Left = 16
      Top = 40
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit11: TEdit
      Left = 64
      Top = 40
      Width = 41
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Edit12: TEdit
      Left = 112
      Top = 40
      Width = 41
      Height = 21
      TabOrder = 2
      Text = '0'
    end
  end
  object Memo1: TMemo
    Left = 480
    Top = 296
    Width = 217
    Height = 97
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
    end
    object N2: TMenuItem
      Caption = #1054#1073#39#1108#1082#1090
      object N3: TMenuItem
        Caption = #1058#1077#1090#1088#1072#1077#1076#1088
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1050#1091#1073
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1054#1082#1090#1072#1077#1076#1088
        OnClick = N5Click
      end
      object N20: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080'...'
      end
    end
    object N6: TMenuItem
      Caption = #1055#1088#1086#1077#1082#1094#1110#1103
      object N7: TMenuItem
        Caption = #1055#1072#1088#1072#1083#1077#1083#1100#1085#1110
        object N8: TMenuItem
          Caption = #1054#1088#1090#1086#1075#1088#1072#1092#1110#1095#1085#1072
          object XoY1: TMenuItem
            Caption = #1053#1072' XoY'
            OnClick = XoY1Click
          end
          object XoZ1: TMenuItem
            Caption = #1053#1072' XoZ'
            OnClick = XoZ1Click
          end
          object YoZ1: TMenuItem
            Caption = #1053#1072' YoZ'
            OnClick = YoZ1Click
          end
        end
        object N9: TMenuItem
          Caption = #1040#1082#1089#1086#1085#1086#1084#1077#1090#1088#1080#1095#1085#1072
          object N11: TMenuItem
            Caption = #1044#1080#1084#1077#1090#1088#1080#1095#1085#1072
            OnClick = N11Click
          end
          object N12: TMenuItem
            Caption = #1030#1079#1086#1084#1077#1090#1088#1080#1095#1085#1072
            OnClick = N12Click
          end
          object N13: TMenuItem
            Caption = #1058#1088#1080#1084#1077#1090#1088#1080#1095#1085#1072
            OnClick = N13Click
          end
        end
        object N10: TMenuItem
          Caption = #1050#1086#1089#1086#1082#1091#1090#1085#1072
          object N14: TMenuItem
            Caption = #1050#1072#1074#1072#1083#1100#1108
            OnClick = N14Click
          end
          object N15: TMenuItem
            Caption = #1050#1072#1073#1110#1085#1077#1090#1085#1072
            OnClick = N15Click
          end
        end
      end
      object N16: TMenuItem
        Caption = #1055#1077#1088#1089#1087#1077#1082#1090#1080#1074#1085#1110
        object N17: TMenuItem
          Caption = #1054#1076#1085#1086#1090#1086#1095#1082#1086#1074#1072
          OnClick = N17Click
        end
        object N18: TMenuItem
          Caption = #1044#1074#1086#1090#1086#1095#1082#1086#1074#1072
          OnClick = N18Click
        end
        object N19: TMenuItem
          Caption = #1058#1088#1080#1090#1086#1095#1082#1086#1074#1072
          OnClick = N19Click
        end
      end
    end
  end
end
