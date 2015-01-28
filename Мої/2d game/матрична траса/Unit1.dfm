object Form1: TForm1
  Left = 192
  Top = 124
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
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Button5: TButton
    Left = 816
    Top = 16
    Width = 75
    Height = 25
    Caption = 'S++'
    TabOrder = 0
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 816
    Top = 48
    Width = 75
    Height = 25
    Caption = 'S--'
    TabOrder = 1
    OnClick = Button6Click
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 696
    Top = 24
  end
end
