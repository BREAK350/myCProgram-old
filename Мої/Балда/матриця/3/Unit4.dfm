object Form4: TForm4
  Left = 192
  Top = 124
  BorderStyle = bsDialog
  Caption = 'Form4'
  ClientHeight = 113
  ClientWidth = 385
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
    Top = 16
    Width = 96
    Height = 20
    Caption = #1030#1084#39#1103' '#1075#1088#1072#1074#1094#1103
  end
  object Edit1: TEdit
    Left = 24
    Top = 48
    Width = 201
    Height = 28
    TabOrder = 0
    OnKeyDown = Edit1KeyDown
  end
  object Button1: TButton
    Left = 232
    Top = 48
    Width = 81
    Height = 25
    Caption = #1044#1086#1073#1088#1077
    TabOrder = 1
    OnClick = Button1Click
  end
end
