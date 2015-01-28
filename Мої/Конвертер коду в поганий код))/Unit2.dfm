object Form2: TForm2
  Left = 293
  Top = 274
  BorderStyle = bsDialog
  Caption = 'Form2'
  ClientHeight = 327
  ClientWidth = 547
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -17
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 21
  object Label1: TLabel
    Left = 72
    Top = 271
    Width = 90
    Height = 21
    Caption = #1044#1086#1073#1088#1080#1081' '#1082#1086#1076
  end
  object Label3: TLabel
    Left = 384
    Top = 271
    Width = 97
    Height = 21
    Caption = #1055#1086#1075#1072#1085#1080#1081' '#1082#1086#1076
  end
  object Memo1: TMemo
    Left = 24
    Top = 16
    Width = 233
    Height = 249
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      '//--------------------'
      '------'
      'void main()'
      '{'
      '    int a=5,'
      '        b=4;'
      '    if(a>b)'
      '    {'
      '        return;'
      '    }'
      '}'
      '//--------------------'
      '------')
    ParentFont = False
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 288
    Top = 16
    Width = 233
    Height = 249
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      '//--------------------'
      '------ void main() { '
      'int a=5, b=4; if(a>b) '
      '{ return; } } '
      '//--------------------'
      '------')
    ParentFont = False
    TabOrder = 1
  end
  object Button1: TButton
    Left = 200
    Top = 271
    Width = 145
    Height = 33
    Caption = #1055#1077#1088#1077#1090#1074#1086#1088#1080#1090#1080
    TabOrder = 2
    OnClick = Button1Click
  end
  object od: TOpenDialog
    Left = 264
    Top = 128
  end
end
