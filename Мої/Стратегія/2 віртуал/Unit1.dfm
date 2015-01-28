object Form1: TForm1
  Left = 192
  Top = 124
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 792
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
  end
  object TrackBar1: TTrackBar
    Left = 624
    Top = 24
    Width = 150
    Height = 45
    Max = 100
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 10
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object TrackBar2: TTrackBar
    Left = 728
    Top = 72
    Width = 150
    Height = 45
    Max = 800
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 2
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar2Change
  end
  object TrackBar3: TTrackBar
    Left = 728
    Top = 128
    Width = 150
    Height = 45
    Max = 800
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar3Change
  end
  object Edit1: TEdit
    Left = 632
    Top = 64
    Width = 89
    Height = 33
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 632
    Top = 120
    Width = 89
    Height = 41
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 632
    Top = 176
    Width = 89
    Height = 41
    TabOrder = 6
  end
  object PopupMenu1: TPopupMenu
    Left = 8
    Top = 8
    object GOCITY1: TMenuItem
      Caption = 'GO_CITY'
      OnClick = GOCITY1Click
    end
    object GOCOMMANDER1: TMenuItem
      Caption = 'GO_COMMANDER'
      OnClick = GOCOMMANDER1Click
    end
    object MOVETO1: TMenuItem
      Caption = 'MOVETO'
      OnClick = MOVETO1Click
    end
  end
end
