object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 527
  ClientWidth = 820
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object WebBrowser1: TWebBrowser
    Left = 0
    Top = 0
    Width = 424
    Height = 486
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 393
    ExplicitHeight = 377
    ControlData = {
      4C000000D22B00003B3200000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object Memo1: TMemo
    Left = 424
    Top = 0
    Width = 396
    Height = 486
    Align = alRight
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
    Visible = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 486
    Width = 820
    Height = 41
    Align = alBottom
    TabOrder = 2
    OnResize = Panel1Resize
    object Button1: TButton
      Left = 8
      Top = 8
      Width = 129
      Height = 25
      Caption = #1053#1072#1089#1090#1091#1087#1085#1080#1081' '#1082#1088#1086#1082
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 88
    Top = 16
    object N2: TMenuItem
      Caption = #1042#1080#1093#1110#1076#1085#1080#1081' '#1082#1086#1076
      OnClick = N2Click
    end
  end
end
