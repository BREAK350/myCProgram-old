object Form1: TForm1
  Left = 193
  Top = 124
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Answer: TPanel
    Left = 0
    Top = 80
    Width = 345
    Height = 233
    TabOrder = 1
    object Memo3: TMemo
      Left = 16
      Top = 16
      Width = 313
      Height = 105
      Lines.Strings = (
        #1042#1110#1076#1087#1086#1074#1110#1076#1100'...')
      TabOrder = 0
    end
    object RadioButton1: TRadioButton
      Left = 24
      Top = 136
      Width = 113
      Height = 17
      Caption = #1055#1088#1072#1074#1080#1083#1100#1085#1072
      TabOrder = 1
    end
    object RadioButton2: TRadioButton
      Left = 24
      Top = 160
      Width = 113
      Height = 17
      Caption = #1053#1077' '#1087#1088#1072#1074#1080#1083#1100#1085#1072
      TabOrder = 2
    end
    object Button4: TButton
      Left = 112
      Top = 192
      Width = 105
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 3
      OnClick = Button4Click
    end
  end
  object Test: TPanel
    Left = 0
    Top = 0
    Width = 441
    Height = 369
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Memo1: TMemo
      Left = 24
      Top = 80
      Width = 393
      Height = 241
      ReadOnly = True
      TabOrder = 0
    end
    object Button1: TButton
      Left = 24
      Top = 328
      Width = 137
      Height = 25
      Caption = #1044#1086#1076#1072#1090#1080' '#1074#1110#1076#1087#1086#1074#1110#1076#1100
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 336
      Top = 328
      Width = 81
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 2
    end
    object Button3: TButton
      Left = 168
      Top = 328
      Width = 161
      Height = 25
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080' '#1074#1110#1076#1087#1086#1074#1110#1076#1100
      TabOrder = 3
    end
    object Memo2: TMemo
      Left = 24
      Top = 16
      Width = 393
      Height = 57
      Lines.Strings = (
        #1055#1080#1090#1072#1085#1085#1103'...')
      TabOrder = 4
    end
  end
  object MainMenu1: TMainMenu
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
    end
    object N2: TMenuItem
      Caption = #1058#1077#1089#1090
      object N3: TMenuItem
        Caption = #1044#1086#1076#1072#1090#1080' '#1087#1080#1090#1072#1085#1085#1103
      end
    end
  end
  object AnswerTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = AnswerTimerTimer
    Left = 456
    Top = 8
  end
end
