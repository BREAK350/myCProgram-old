object FormRegularExpression: TFormRegularExpression
  Left = 203
  Top = 78
  Width = 845
  Height = 635
  Caption = 'Show'
  Color = clBtnFace
  Constraints.MaxHeight = 635
  Constraints.MaxWidth = 845
  Constraints.MinHeight = 635
  Constraints.MinWidth = 845
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Lucida Console'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 252
    Height = 21
    Caption = 'Regular expression'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -21
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object RegularExp: TEdit
    Left = 16
    Top = 48
    Width = 649
    Height = 24
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnChange = RegularExpChange
  end
  object Table: TStringGrid
    Left = 16
    Top = 144
    Width = 793
    Height = 433
    DefaultColWidth = 70
    DefaultRowHeight = 30
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goThumbTracking]
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 680
    Top = 40
    Width = 129
    Height = 33
    Caption = 'Create'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object Undetermined: TRadioButton
    Left = 24
    Top = 96
    Width = 177
    Height = 17
    Caption = 'Undetermined'
    Checked = True
    TabOrder = 3
    TabStop = True
    OnClick = UndeterminedClick
  end
  object Determined: TRadioButton
    Left = 208
    Top = 96
    Width = 153
    Height = 17
    Caption = 'Determined'
    TabOrder = 4
    OnClick = DeterminedClick
  end
  object Minimized: TRadioButton
    Left = 368
    Top = 96
    Width = 137
    Height = 17
    Caption = 'Minimized'
    TabOrder = 5
    OnClick = MinimizedClick
  end
  object BitBtnCheck: TBitBtn
    Left = 632
    Top = 88
    Width = 89
    Height = 33
    Caption = 'Check'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = BitBtnCheckClick
  end
  object BitBtn3: TBitBtn
    Left = 728
    Top = 88
    Width = 81
    Height = 33
    Caption = 'Help'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 536
    Top = 88
    Width = 89
    Height = 33
    Caption = 'Show'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = BitBtn4Click
  end
end
