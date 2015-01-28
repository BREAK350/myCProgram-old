object Check: TCheck
  Left = 671
  Top = 99
  BorderStyle = bsDialog
  Caption = 'Check'
  ClientHeight = 197
  ClientWidth = 586
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clBlue
  Font.Height = -19
  Font.Name = 'Lucida Console'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 120
    Height = 19
    Caption = 'Expression'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Result: TLabel
    Left = 24
    Top = 136
    Width = 84
    Height = 19
    Caption = 'Wait...'
  end
  object Expression: TEdit
    Left = 16
    Top = 48
    Width = 553
    Height = 27
    TabOrder = 0
    OnChange = ExpressionChange
  end
  object BitBtn1: TBitBtn
    Left = 224
    Top = 88
    Width = 137
    Height = 33
    Caption = 'Check'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object StepByStep: TCheckBox
    Left = 24
    Top = 96
    Width = 185
    Height = 17
    Caption = 'Step by step'
    TabOrder = 2
    OnClick = StepByStepClick
  end
end
