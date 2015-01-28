object Form1: TForm1
  Left = 143
  Top = 32
  BorderStyle = bsDialog
  Caption = 'Form1'
  ClientHeight = 620
  ClientWidth = 1131
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 624
    Top = 48
    Width = 57
    Height = 13
    Caption = #1050#1091#1088#1089#1086#1088'(0;0)'
  end
  object Label2: TLabel
    Left = 712
    Top = 48
    Width = 76
    Height = 13
    Caption = #1042#1089#1100#1086#1075#1086' '#1090#1086#1095#1086#1082' 0'
  end
  object Label3: TLabel
    Left = 848
    Top = 48
    Width = 70
    Height = 13
    Caption = #1042#1089#1100#1086#1075#1086' '#1083#1110#1085#1110#1081' 0'
  end
  object Button1: TButton
    Left = 624
    Top = 16
    Width = 89
    Height = 25
    Caption = #1053#1086#1074#1072' '#1076#1077#1090#1072#1083#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 720
    Top = 16
    Width = 75
    Height = 25
    Caption = #1042#1110#1076#1082#1088#1080#1090#1080
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 800
    Top = 16
    Width = 75
    Height = 25
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    TabOrder = 2
    OnClick = Button3Click
  end
  object Panel1: TPanel
    Left = 624
    Top = 72
    Width = 473
    Height = 121
    Enabled = False
    TabOrder = 3
    object Label4: TLabel
      Left = 280
      Top = 8
      Width = 8
      Height = 13
      Caption = 'R'
    end
    object Label5: TLabel
      Left = 280
      Top = 40
      Width = 8
      Height = 13
      Caption = 'G'
    end
    object Label6: TLabel
      Left = 280
      Top = 72
      Width = 7
      Height = 13
      Caption = 'B'
    end
    object Button4: TButton
      Left = 6
      Top = 8
      Width = 75
      Height = 25
      Caption = #1058#1086#1095#1082#1072
      TabOrder = 0
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 86
      Top = 8
      Width = 75
      Height = 25
      Caption = #1051#1110#1085#1110#1103
      TabOrder = 1
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 168
      Top = 8
      Width = 75
      Height = 25
      Caption = #1051#1072#1084#1072#1085#1072
      TabOrder = 2
      OnClick = Button6Click
    end
    object UpDown1: TUpDown
      Left = 256
      Top = 8
      Width = 17
      Height = 25
      Min = 0
      Position = 0
      TabOrder = 3
      Wrap = False
      OnClick = UpDown1Click
    end
    object Edit1: TEdit
      Left = 296
      Top = 8
      Width = 33
      Height = 21
      TabOrder = 4
      Text = '0'
    end
    object UpDown2: TUpDown
      Left = 256
      Top = 40
      Width = 17
      Height = 25
      Min = 0
      Position = 0
      TabOrder = 5
      Wrap = False
      OnClick = UpDown2Click
    end
    object UpDown3: TUpDown
      Left = 256
      Top = 72
      Width = 17
      Height = 25
      Min = 0
      Position = 0
      TabOrder = 6
      Wrap = False
      OnClick = UpDown3Click
    end
    object Edit2: TEdit
      Left = 296
      Top = 40
      Width = 33
      Height = 21
      TabOrder = 7
      Text = '0'
    end
    object Edit3: TEdit
      Left = 296
      Top = 72
      Width = 33
      Height = 21
      TabOrder = 8
      Text = '0'
    end
    object Panel3: TPanel
      Left = 336
      Top = 8
      Width = 57
      Height = 89
      Caption = #1050#1086#1083#1110#1088
      TabOrder = 9
    end
  end
  object Panel2: TPanel
    Left = 624
    Top = 200
    Width = 473
    Height = 153
    TabOrder = 4
    object Label7: TLabel
      Left = 32
      Top = 8
      Width = 27
      Height = 13
      Caption = 'Alpha'
    end
    object Label8: TLabel
      Left = 40
      Top = 40
      Width = 7
      Height = 13
      Caption = 'S'
    end
    object UpDown4: TUpDown
      Left = 8
      Top = 8
      Width = 17
      Height = 25
      Min = 0
      Position = 0
      TabOrder = 0
      Wrap = False
      OnClick = UpDown4Click
    end
    object Edit4: TEdit
      Left = 64
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Button11: TButton
      Left = 112
      Top = 8
      Width = 25
      Height = 25
      Caption = 'OK'
      TabOrder = 2
      OnClick = Button11Click
    end
    object UpDown5: TUpDown
      Left = 8
      Top = 40
      Width = 17
      Height = 25
      Min = 0
      Position = 0
      TabOrder = 3
      Wrap = False
      OnClick = UpDown5Click
    end
    object Edit5: TEdit
      Left = 64
      Top = 40
      Width = 41
      Height = 21
      TabOrder = 4
      Text = '1'
    end
    object Button7: TButton
      Left = 112
      Top = 40
      Width = 25
      Height = 25
      Caption = 'OK'
      TabOrder = 5
      OnClick = Button7Click
    end
  end
  object Timer1: TTimer
    Interval = 10
    Left = 96
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Left = 128
    Top = 8
  end
  object OpenDialog1: TOpenDialog
    Left = 160
    Top = 8
  end
end
