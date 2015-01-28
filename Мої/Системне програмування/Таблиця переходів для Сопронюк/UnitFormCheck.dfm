object FormCheck: TFormCheck
  Left = 663
  Top = 346
  Caption = 'FormCheck'
  ClientHeight = 197
  ClientWidth = 586
  Color = clBtnFace
  Constraints.MaxHeight = 235
  Constraints.MaxWidth = 602
  Constraints.MinHeight = 235
  Constraints.MinWidth = 602
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clBlue
  Font.Height = -16
  Font.Name = 'Lucida Console'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 120
    Height = 19
    Caption = 'Expression'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Result: TLabel
    Left = 24
    Top = 136
    Width = 77
    Height = 16
    Caption = 'Wait...'
  end
  object Expression: TEdit
    Left = 16
    Top = 48
    Width = 553
    Height = 24
    TabOrder = 0
    OnChange = ExpressionChange
  end
  object BitBtnCheck: TBitBtn
    Left = 224
    Top = 88
    Width = 145
    Height = 33
    Caption = 'Check'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 1
    OnClick = BitBtnCheckClick
  end
end
