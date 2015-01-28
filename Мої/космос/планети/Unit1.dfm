object Form1: TForm1
  Left = 328
  Top = 187
  Caption = 'Form1'
  ClientHeight = 442
  ClientWidth = 912
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 39
    Top = 32
    Width = 25
    Height = 25
    Caption = '>'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 32
    Width = 25
    Height = 25
    Caption = '<'
    TabOrder = 1
    OnClick = Button2Click
  end
  object TrackBar1: TTrackBar
    Left = 136
    Top = 8
    Width = 681
    Height = 45
    Max = 100
    Min = 1
    Position = 1
    TabOrder = 2
    OnChange = TrackBar1Change
  end
  object Edit1: TEdit
    Left = 823
    Top = 8
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 3
    Text = '1'
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 24
    Top = 136
  end
end
