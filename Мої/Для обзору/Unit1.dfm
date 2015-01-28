object Form1: TForm1
  Left = 192
  Top = 124
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 249
    Height = 385
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 264
    Top = 8
    Width = 233
    Height = 201
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 33
      Height = 13
      Caption = 'Angle1'
    end
    object Label2: TLabel
      Left = 16
      Top = 48
      Width = 33
      Height = 13
      Caption = 'Angle2'
    end
    object Label3: TLabel
      Left = 16
      Top = 80
      Width = 27
      Height = 13
      Caption = 'Value'
    end
    object Label4: TLabel
      Left = 16
      Top = 112
      Width = 42
      Height = 13
      Caption = 'Distance'
    end
    object Edit1: TEdit
      Left = 88
      Top = 16
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 88
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 88
      Top = 80
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 88
      Top = 112
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Button1: TButton
      Left = 72
      Top = 152
      Width = 75
      Height = 25
      Caption = 'Add'
      TabOrder = 4
      OnClick = Button1Click
    end
  end
end
