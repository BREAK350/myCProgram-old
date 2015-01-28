object FormAnimation: TFormAnimation
  Left = 13
  Top = 14
  Width = 1316
  Height = 700
  Caption = 'FormAnimation'
  Color = clBtnFace
  Constraints.MaxHeight = 700
  Constraints.MaxWidth = 1316
  Constraints.MinHeight = 700
  Constraints.MinWidth = 1300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlue
  Font.Height = -12
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 457
    Height = 33
    TabOrder = 0
    object ButtonStart: TButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 0
      OnClick = ButtonStartClick
    end
    object EditRegularExpression: TEdit
      Left = 80
      Top = 2
      Width = 369
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = 'RegularExpression'
    end
  end
end
