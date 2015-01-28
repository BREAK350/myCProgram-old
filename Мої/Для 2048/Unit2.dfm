object Form2: TForm2
  Left = 732
  Top = 165
  BorderStyle = bsDialog
  Caption = 'Form2'
  ClientHeight = 282
  ClientWidth = 239
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 67
    Width = 66
    Height = 13
    Caption = #1058#1072#1081#1084#1077#1088', '#1084#1089#1077#1082
  end
  object Label2: TLabel
    Left = 32
    Top = 126
    Width = 26
    Height = 13
    Caption = #1042#1083#1110#1074#1086
  end
  object Label3: TLabel
    Left = 32
    Top = 99
    Width = 36
    Height = 13
    Caption = #1042#1087#1088#1072#1074#1086
  end
  object Label4: TLabel
    Left = 33
    Top = 152
    Width = 30
    Height = 13
    Caption = #1042#1074#1077#1088#1093
  end
  object Label5: TLabel
    Left = 32
    Top = 179
    Width = 23
    Height = 13
    Caption = #1042#1085#1080#1079
  end
  object Label6: TLabel
    Left = 24
    Top = 27
    Width = 39
    Height = 13
    Caption = 'HANDLE'
  end
  object OK: TButton
    Left = 120
    Top = 219
    Width = 81
    Height = 25
    Caption = 'Start'
    TabOrder = 1
    OnClick = OKClick
  end
  object Edit1: TEdit
    Left = 120
    Top = 64
    Width = 81
    Height = 21
    TabOrder = 0
    Text = '1000'
  end
  object Edit2: TEdit
    Left = 120
    Top = 123
    Width = 81
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object Edit3: TEdit
    Left = 120
    Top = 96
    Width = 81
    Height = 21
    TabOrder = 3
    Text = '1'
  end
  object Edit4: TEdit
    Left = 120
    Top = 149
    Width = 81
    Height = 21
    TabOrder = 4
    Text = '0'
  end
  object Edit5: TEdit
    Left = 120
    Top = 176
    Width = 81
    Height = 21
    TabOrder = 5
    Text = '1'
  end
  object Button1: TButton
    Left = 32
    Top = 219
    Width = 82
    Height = 25
    Caption = 'Stop'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Edit6: TEdit
    Left = 80
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '002A04F0'
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 80
    Top = 176
  end
end
