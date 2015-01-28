object Form1: TForm1
  Left = 193
  Top = 124
  BorderStyle = bsDialog
  Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088
  ClientHeight = 318
  ClientWidth = 435
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object Label1: TLabel
    Left = 32
    Top = 32
    Width = 374
    Height = 29
    Caption = #1043#1077#1085#1077#1088#1072#1094#1110#1103' '#1089#1082#1110#1085#1095#1077#1085#1085#1080#1093' '#1072#1074#1090#1086#1084#1072#1090#1110#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 64
    Top = 80
    Width = 176
    Height = 24
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1072#1074#1090#1086#1084#1072#1090#1110#1074
  end
  object Label3: TLabel
    Left = 64
    Top = 120
    Width = 206
    Height = 24
    Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072' '#1076#1086#1074#1078#1080#1085#1072
  end
  object Label4: TLabel
    Left = 64
    Top = 152
    Width = 180
    Height = 24
    Caption = #1088#1077#1075#1091#1083#1103#1088#1085#1086#1075#1086' '#1074#1080#1088#1072#1079#1091
  end
  object EditCount: TEdit
    Left = 312
    Top = 80
    Width = 73
    Height = 32
    TabOrder = 0
    Text = '1'
  end
  object EditMaxLength: TEdit
    Left = 312
    Top = 136
    Width = 73
    Height = 32
    TabOrder = 1
    Text = '5'
  end
  object ButtonSaveHTML: TButton
    Left = 56
    Top = 200
    Width = 193
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082' HTML'
    TabOrder = 2
    OnClick = ButtonSaveHTMLClick
  end
  object ButtonSaveWord: TButton
    Left = 56
    Top = 248
    Width = 193
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082' Word'
    TabOrder = 3
    OnClick = ButtonSaveWordClick
  end
  object SaveDialog: TSaveDialog
    Left = 24
    Top = 72
  end
end
