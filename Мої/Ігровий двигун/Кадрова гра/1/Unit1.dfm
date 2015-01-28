object Form1: TForm1
  Left = 192
  Top = 116
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 128
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Load'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 32
    Top = 56
    Width = 249
    Height = 329
    TabOrder = 2
  end
end
