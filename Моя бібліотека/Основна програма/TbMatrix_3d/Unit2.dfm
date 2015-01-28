object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 336
  ClientWidth = 803
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 336
    Top = 8
    Width = 457
    Height = 321
    OnClick = Image1Click
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 321
    Height = 89
    ColCount = 3
    DefaultColWidth = 100
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 103
    Width = 75
    Height = 25
    Caption = '0'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 134
    Width = 75
    Height = 25
    Caption = '1'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 165
    Width = 75
    Height = 25
    Caption = '2'
    TabOrder = 3
    OnClick = Button3Click
  end
end
