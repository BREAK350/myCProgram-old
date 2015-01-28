object Form1: TForm1
  Left = 199
  Top = 135
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object Button1: TButton
    Left = 0
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 144
    Top = 24
    Width = 161
    Height = 97
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 61
      Height = 24
      Caption = #1056#1086#1079#1084#1110#1088
    end
    object Edit1: TEdit
      Left = 72
      Top = 24
      Width = 73
      Height = 32
      TabOrder = 0
    end
    object Button2: TButton
      Left = 8
      Top = 56
      Width = 137
      Height = 25
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Edit2: TEdit
    Left = 432
    Top = 8
    Width = 121
    Height = 32
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 24
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
    end
    object N2: TMenuItem
      Caption = #1054#1087#1094#1110#1111
      object N3: TMenuItem
        Caption = #1047#1084#1110#1085#1080#1090#1080' '#1096#1088#1080#1092#1090
        OnClick = N3Click
      end
    end
  end
end
