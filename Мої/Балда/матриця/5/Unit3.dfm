object Form3: TForm3
  Left = 412
  Top = 198
  BorderStyle = bsDialog
  Caption = 'Form3'
  ClientHeight = 225
  ClientWidth = 387
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 24
    Top = 56
    Width = 148
    Height = 20
    Caption = #1055#1086#1095#1072#1090#1082#1086#1074#1077' '#1089#1083#1086#1074#1086
  end
  object Label2: TLabel
    Left = 24
    Top = 128
    Width = 65
    Height = 20
    Caption = #1064#1080#1088#1080#1085#1072
  end
  object Label3: TLabel
    Left = 208
    Top = 128
    Width = 62
    Height = 20
    Caption = #1042#1080#1089#1086#1090#1072
  end
  object Label4: TLabel
    Left = 24
    Top = 16
    Width = 146
    Height = 20
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1075#1088#1072#1074#1094#1110#1074
  end
  object Edit1: TEdit
    Left = 48
    Top = 88
    Width = 297
    Height = 28
    TabOrder = 0
    OnKeyDown = Edit1KeyDown
  end
  object Edit2: TEdit
    Left = 120
    Top = 128
    Width = 65
    Height = 28
    TabOrder = 1
    Text = '0'
  end
  object Edit3: TEdit
    Left = 280
    Top = 128
    Width = 65
    Height = 28
    TabOrder = 2
    Text = '0'
  end
  object Button1: TButton
    Left = 136
    Top = 184
    Width = 105
    Height = 25
    Caption = #1044#1086#1073#1088#1077
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit4: TEdit
    Left = 184
    Top = 16
    Width = 65
    Height = 28
    TabOrder = 4
    Text = '2'
  end
end
