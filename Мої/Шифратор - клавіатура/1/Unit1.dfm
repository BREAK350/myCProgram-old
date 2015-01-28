object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1064#1080#1092#1088#1072#1090#1086#1088
  ClientHeight = 360
  ClientWidth = 507
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -17
  Font.Name = 'Tahoma'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object Memo1: TMemo
    Left = 32
    Top = 32
    Width = 217
    Height = 249
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Memo2: TMemo
    Left = 256
    Top = 32
    Width = 217
    Height = 249
    TabOrder = 1
    OnChange = Memo2Change
  end
  object ComboBox1: TComboBox
    Left = 64
    Top = 301
    Width = 145
    Height = 28
    Style = csOwnerDrawFixed
    ItemHeight = 22
    ItemIndex = 0
    TabOrder = 2
    Text = #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
    OnChange = ComboBox1Change
    Items.Strings = (
      #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
      #1059#1082#1088#1072#1111#1085#1089#1100#1082#1072
      #1056#1086#1089#1110#1081#1089#1100#1082#1072)
  end
  object ComboBox2: TComboBox
    Left = 288
    Top = 301
    Width = 145
    Height = 28
    Style = csOwnerDrawFixed
    ItemHeight = 22
    ItemIndex = 0
    TabOrder = 3
    Text = #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
    OnChange = ComboBox2Change
    Items.Strings = (
      #1040#1085#1075#1083#1110#1081#1089#1100#1082#1072
      #1059#1082#1088#1072#1111#1085#1089#1100#1082#1072
      #1056#1086#1089#1110#1081#1089#1100#1082#1072)
  end
end
