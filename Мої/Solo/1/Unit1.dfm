object Main: TMain
  Left = 217
  Top = 128
  BorderStyle = bsSingle
  Caption = #1057#1086#1083#1086' 1.5.2'
  ClientHeight = 297
  ClientWidth = 771
  Color = clGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  Menu = MainMenu1
  OldCreateOrder = False
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 24
  object Message: TLabel
    Left = 232
    Top = 256
    Width = 163
    Height = 24
    Caption = #1059#1088#1086#1082' '#1079#1072#1074#1077#1088#1096#1077#1085#1086
    Visible = False
  end
  object Progress: TCGauge
    Left = 600
    Top = 24
    Width = 137
    Height = 225
    Kind = gkVerticalBar
  end
  object Field: TMemo
    Left = 32
    Top = 24
    Width = 561
    Height = 225
    BorderStyle = bsNone
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    OnClick = FieldClick
    OnDblClick = FieldClick
    OnKeyPress = FieldKeyPress
  end
  object Options: TPanel
    Left = 113
    Top = 0
    Width = 481
    Height = 289
    Color = clGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Visible = False
    object LeftHand: TGroupBox
      Left = 32
      Top = 8
      Width = 201
      Height = 153
      Caption = #1051#1110#1074#1072' '#1088#1091#1082#1072
      TabOrder = 0
      object Finger0: TCheckBox
        Left = 16
        Top = 32
        Width = 153
        Height = 17
        Caption = #1084#1110#1079#1080#1085#1077#1094#1100
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object Finger1: TCheckBox
        Left = 16
        Top = 56
        Width = 145
        Height = 17
        Caption = #1073#1077#1079#1110#1084#1077#1085#1085#1080#1081
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object Finger2: TCheckBox
        Left = 16
        Top = 80
        Width = 169
        Height = 17
        Caption = #1089#1077#1088#1077#1076#1085#1110#1081
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object Finger3: TCheckBox
        Left = 16
        Top = 104
        Width = 169
        Height = 17
        Caption = #1074#1082#1072#1079#1110#1074#1085#1080#1081
        Checked = True
        State = cbChecked
        TabOrder = 3
      end
      object Finger4: TCheckBox
        Left = 16
        Top = 128
        Width = 169
        Height = 17
        Caption = #1074#1077#1083#1080#1082#1080#1081
        Checked = True
        Enabled = False
        State = cbChecked
        TabOrder = 4
      end
    end
    object RightHand: TGroupBox
      Left = 248
      Top = 8
      Width = 201
      Height = 153
      Caption = #1055#1088#1072#1074#1072' '#1088#1091#1082#1072
      TabOrder = 1
      object Finger5: TCheckBox
        Left = 16
        Top = 32
        Width = 161
        Height = 17
        Caption = #1084#1110#1079#1080#1085#1077#1094#1100
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object Finger6: TCheckBox
        Left = 16
        Top = 56
        Width = 169
        Height = 17
        Caption = #1073#1077#1079#1110#1084#1077#1085#1085#1080#1081
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object Finger7: TCheckBox
        Left = 16
        Top = 80
        Width = 169
        Height = 17
        Caption = #1089#1077#1088#1077#1076#1085#1110#1081
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object Finger8: TCheckBox
        Left = 16
        Top = 104
        Width = 169
        Height = 17
        Caption = #1074#1082#1072#1079#1110#1074#1085#1080#1081
        Checked = True
        State = cbChecked
        TabOrder = 3
      end
      object Finger9: TCheckBox
        Left = 16
        Top = 128
        Width = 177
        Height = 17
        Caption = #1074#1077#1083#1080#1082#1080#1081
        Checked = True
        Enabled = False
        State = cbChecked
        TabOrder = 4
      end
    end
    object OptionsOK: TBitBtn
      Left = 192
      Top = 248
      Width = 97
      Height = 33
      Caption = 'OK'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 2
      OnClick = OptionsOKClick
    end
    object GroupBoxAdditionally: TGroupBox
      Left = 32
      Top = 168
      Width = 417
      Height = 73
      Caption = #1044#1086#1076#1072#1090#1082#1086#1074#1086
      TabOrder = 3
      object CheckBoxBigSymbol: TCheckBox
        Left = 16
        Top = 40
        Width = 169
        Height = 17
        Caption = #1074#1077#1083#1080#1082#1110' '#1083#1110#1090#1077#1088#1080
        TabOrder = 0
      end
      object CheckBoxDigit: TCheckBox
        Left = 264
        Top = 40
        Width = 97
        Height = 17
        Caption = #1094#1080#1092#1088#1080
        Enabled = False
        TabOrder = 1
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 8
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N2: TMenuItem
        Caption = #1047#1072#1074#1072#1085#1090#1072#1078#1080#1090#1080' '#1091#1088#1086#1082
        OnClick = N2Click
      end
      object N6: TMenuItem
        Caption = #1047#1072#1074#1072#1085#1090#1072#1078#1080#1090#1080' '#1091#1088#1086#1082#1080
        OnClick = N6Click
      end
      object N9: TMenuItem
        Caption = #1043#1077#1085#1077#1088#1091#1074#1072#1090#1080' '#1074#1080#1087#1072#1076#1082#1086#1074#1086
        OnClick = N9Click
      end
    end
    object NLanguage: TMenuItem
      Caption = #1052#1086#1074#1072'('#1059#1082#1088#1072#1111#1085#1089#1100#1082#1072')'
      Checked = True
      object NLanguageEnglish: TMenuItem
        Caption = #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
        OnClick = NLanguageEnglishClick
      end
      object NLanguageUkrainian: TMenuItem
        Caption = #1059#1082#1088#1072#1111#1085#1089#1100#1082#1072
        OnClick = NLanguageUkrainianClick
      end
    end
    object N7: TMenuItem
      Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1080
      OnClick = N7Click
    end
    object N8: TMenuItem
      Caption = #1042#1080#1082#1083#1102#1095#1080#1090#1080' '#1090#1072#1081#1084#1077#1088
      OnClick = N8Click
    end
    object N10: TMenuItem
      Caption = #1058#1088#1077#1085#1091#1074#1072#1090#1080'...'
      OnClick = N10Click
    end
    object N3: TMenuItem
      Caption = #1057#1082#1110#1085#1095#1077#1085#1085#1080#1081' '#1090#1077#1082#1089#1090
      OnClick = N3Click
    end
    object N4: TMenuItem
      Caption = #1041#1077#1079' '#1082#1083#1072#1074#1110#1072#1090#1091#1088#1080
      OnClick = N4Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 40
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 72
  end
end
