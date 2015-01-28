object Form1: TForm1
  Left = 192
  Top = 124
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 145
    Height = 121
    TabOrder = 0
    object Button1: TButton
      Left = 56
      Top = 16
      Width = 33
      Height = 25
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button4: TButton
      Left = 56
      Top = 80
      Width = 33
      Height = 25
      TabOrder = 1
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 96
      Top = 48
      Width = 33
      Height = 25
      TabOrder = 2
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 16
      Top = 48
      Width = 33
      Height = 25
      TabOrder = 3
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 96
      Top = 80
      Width = 33
      Height = 25
      Caption = '->'
      TabOrder = 4
      OnClick = Button7Click
    end
    object Button2: TButton
      Left = 16
      Top = 80
      Width = 33
      Height = 25
      Caption = '0'
      TabOrder = 5
      OnClick = Button2Click
    end
  end
  object Panel2: TPanel
    Left = 152
    Top = 8
    Width = 177
    Height = 41
    TabOrder = 1
  end
  object MainMenu1: TMainMenu
    Left = 352
    Top = 16
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N2: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080' '#1089#1083#1086#1074#1085#1080#1082
        OnClick = N2Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 416
    Top = 16
  end
end
