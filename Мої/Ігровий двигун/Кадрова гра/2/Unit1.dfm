object Form1: TForm1
  Left = 193
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
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 8
    Top = 24
    object Load1: TMenuItem
      Caption = 'Load'
      OnClick = Load1Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'txt||bmp'
    Left = 56
    Top = 24
  end
end
