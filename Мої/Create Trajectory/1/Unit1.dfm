object MainForm: TMainForm
  Left = 192
  Top = 124
  Caption = 'MainForm'
  ClientHeight = 422
  ClientWidth = 912
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 0
    Width = 177
    Height = 225
    Caption = #1030#1085#1090#1077#1088#1092#1077#1081#1089
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 40
      Width = 58
      Height = 13
      Caption = #1062#1077#1085#1090#1088' '#1086#1089#1077#1081
    end
    object Label2: TLabel
      Left = 16
      Top = 96
      Width = 46
      Height = 13
      Caption = #1052#1072#1089#1096#1090#1072#1073
    end
    object Edit1: TEdit
      Left = 88
      Top = 24
      Width = 57
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit2: TEdit
      Left = 88
      Top = 48
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Edit3: TEdit
      Left = 88
      Top = 80
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object Edit4: TEdit
      Left = 88
      Top = 104
      Width = 57
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 136
      Width = 129
      Height = 17
      Caption = #1042#1110#1089#1100' OX '#1074#1087#1088#1072#1074#1086
      Checked = True
      State = cbChecked
      TabOrder = 4
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 160
      Width = 129
      Height = 17
      Caption = #1042#1110#1089#1100' OY '#1074#1074#1077#1088#1093
      TabOrder = 5
    end
    object Button1: TButton
      Left = 8
      Top = 184
      Width = 75
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 6
      OnClick = Button1Click
    end
    object Button4: TButton
      Left = 88
      Top = 184
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1080#1090#1080
      TabOrder = 7
      OnClick = Button4Click
    end
  end
  object gbSegment: TGroupBox
    Left = 8
    Top = 224
    Width = 161
    Height = 145
    Caption = #1042#1110#1076#1088#1110#1079#1086#1082
    TabOrder = 1
    Visible = False
    object Edit5: TEdit
      Left = 16
      Top = 24
      Width = 57
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit6: TEdit
      Left = 80
      Top = 24
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Edit7: TEdit
      Left = 16
      Top = 56
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object Edit8: TEdit
      Left = 80
      Top = 56
      Width = 57
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object Button2: TButton
      Left = 16
      Top = 96
      Width = 57
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 4
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 80
      Top = 96
      Width = 57
      Height = 25
      Caption = #1047#1072#1082#1088#1080#1090#1080
      TabOrder = 5
      OnClick = Button3Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = #1053#1086#1074#1080#1081'...'
      end
      object N2: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080'...'
        OnClick = N2Click
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      end
      object N5: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082'...'
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 56
    Top = 16
  end
end
