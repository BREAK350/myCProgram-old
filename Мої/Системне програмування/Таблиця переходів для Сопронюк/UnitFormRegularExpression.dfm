object FormRegularExpression: TFormRegularExpression
  Left = 98
  Top = 0
  Caption = 'FormRegularExpression'
  ClientHeight = 597
  ClientWidth = 829
  Color = clBtnFace
  Constraints.MaxHeight = 635
  Constraints.MaxWidth = 845
  Constraints.MinHeight = 635
  Constraints.MinWidth = 845
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clBlue
  Font.Height = -16
  Font.Name = 'Lucida Console'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 252
    Height = 21
    Caption = 'Regular expression'
    Font.Charset = RUSSIAN_CHARSET
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
    TabOrder = 0
    Text = '(10|01|111)*0(10*1)*'
    OnChange = RegularExpChange
  end
  object BitBtnCreate: TBitBtn
    Left = 680
    Top = 40
    Width = 129
    Height = 33
    Caption = 'Create'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 1
    OnClick = BitBtnCreateClick
  end
  object RadioButtonUndetermined: TRadioButton
    Left = 24
    Top = 96
    Width = 226
    Height = 17
    Caption = 'Undetermined'
    Checked = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    TabStop = True
    OnClick = RadioButtonUndeterminedClick
  end
  object RadioButtonDetermined: TRadioButton
    Left = 256
    Top = 96
    Width = 193
    Height = 17
    Caption = 'Determined'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = RadioButtonDeterminedClick
  end
  object RadioButtonMinimized: TRadioButton
    Left = 447
    Top = 96
    Width = 187
    Height = 17
    Caption = 'Minimized'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -19
    Font.Name = 'Lucida Console'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = RadioButtonMinimizedClick
  end
  object Table: TStringGrid
    Left = 16
    Top = 144
    Width = 793
    Height = 433
    DefaultColWidth = 70
    DefaultRowHeight = 30
    TabOrder = 5
  end
  object BitBtnCheck: TBitBtn
    Left = 632
    Top = 88
    Width = 129
    Height = 33
    Caption = 'Check'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 6
    OnClick = BitBtnCheckClick
  end
  object BitBtnHelp: TBitBtn
    Left = 776
    Top = 88
    Width = 33
    Height = 33
    Caption = '?'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 7
    OnClick = BitBtnHelpClick
  end
  object cmbLanguage: TComboBox
    Left = 680
    Top = 7
    Width = 129
    Height = 26
    Style = csOwnerDrawFixed
    ItemHeight = 20
    ItemIndex = 0
    TabOrder = 8
    Text = 'English'
    OnChange = cmbLanguageChange
    Items.Strings = (
      'English'
      #1059#1082#1088#1072#1111#1085#1089#1100#1082#1072)
  end
end
