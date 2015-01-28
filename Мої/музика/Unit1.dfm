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
  object MediaPlayer1: TMediaPlayer
    Left = 88
    Top = 136
    Width = 253
    Height = 30
    FileName = 'D:\'#1056#1054#1047#1042#1040#1043#1048'\'#1087#1088#1086#1075#1088#1072#1084#1080' '#1057'++\'#1052#1086#1111'\'#1084#1091#1079#1080#1082#1072'\2.mp4'
    TabOrder = 0
  end
  object ScrollBar1: TScrollBar
    Left = 136
    Top = 48
    Width = 121
    Height = 33
    PageSize = 0
    TabOrder = 1
  end
  object TrackBar1: TTrackBar
    Left = 88
    Top = 168
    Width = 257
    Height = 45
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 2
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object Button1: TButton
    Left = 416
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = Button1Click
  end
  object DateTimePicker1: TDateTimePicker
    Left = 640
    Top = 40
    Width = 186
    Height = 21
    CalAlignment = dtaLeft
    Date = 41101.4514104745
    Time = 41101.4514104745
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 4
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 592
    Top = 32
  end
end
