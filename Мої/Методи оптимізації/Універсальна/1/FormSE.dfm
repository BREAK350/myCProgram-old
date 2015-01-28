object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1050#1074#1072#1076#1088#1072#1090#1085#1077' '#1088#1110#1074#1085#1103#1085#1085#1103
  ClientHeight = 197
  ClientWidth = 324
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 80
    Top = 8
    Width = 160
    Height = 23
    Caption = 'ax^2 + bx + c = 0'
  end
  object Label2: TLabel
    Left = 83
    Top = 37
    Width = 30
    Height = 23
    Caption = 'a ='
  end
  object Label3: TLabel
    Left = 82
    Top = 77
    Width = 31
    Height = 23
    Caption = 'b ='
  end
  object Label4: TLabel
    Left = 84
    Top = 114
    Width = 29
    Height = 23
    Caption = 'c ='
  end
  object EditA: TEdit
    Left = 119
    Top = 37
    Width = 121
    Height = 31
    TabOrder = 0
    Text = '0'
  end
  object EditB: TEdit
    Left = 119
    Top = 74
    Width = 121
    Height = 31
    TabOrder = 1
    Text = '0'
  end
  object EditC: TEdit
    Left = 119
    Top = 111
    Width = 121
    Height = 31
    TabOrder = 2
    Text = '0'
  end
  object Button1: TButton
    Left = 84
    Top = 148
    Width = 156
    Height = 33
    Caption = #1056#1086#1079#1074#39#1103#1079#1072#1090#1080
    TabOrder = 3
    OnClick = Button1Click
  end
end
