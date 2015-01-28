object Form1: TForm1
  Left = 192
  Top = 124
  Width = 928
  Height = 480
  Caption = #1058#1072#1085#1082#1080
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 217
    Height = 201
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    object Label10: TLabel
      Left = 80
      Top = 16
      Width = 44
      Height = 20
      Caption = #1058#1072#1085#1082#1080
    end
    object ComboBox1: TComboBox
      Left = 32
      Top = 48
      Width = 145
      Height = 28
      ItemHeight = 20
      TabOrder = 0
      Text = #1030#1075#1088#1086#1082
      Items.Strings = (
        '0'
        '1'
        '2'
        '3'
        '4'
        '5')
    end
    object ComboBox2: TComboBox
      Left = 32
      Top = 88
      Width = 145
      Height = 28
      ItemHeight = 20
      TabOrder = 1
      Text = #1050#1086#1084#1087#39#1102#1090#1077#1088
      Items.Strings = (
        '0'
        '1'
        '2'
        '3'
        '4'
        '5')
    end
    object Button2: TButton
      Left = 32
      Top = 136
      Width = 145
      Height = 33
      Caption = #1043#1088#1072
      TabOrder = 2
      OnClick = Button2Click
    end
  end
  object MediaPlayer1: TMediaPlayer
    Left = 392
    Top = 16
    Width = 253
    Height = 30
    AutoOpen = True
    FileName = 'awp1.wav'
    Visible = False
    TabOrder = 2
  end
  object MediaPlayer2: TMediaPlayer
    Left = 392
    Top = 48
    Width = 253
    Height = 30
    AutoOpen = True
    FileName = 'awp2.wav'
    Visible = False
    TabOrder = 3
  end
  object MediaPlayer3: TMediaPlayer
    Left = 392
    Top = 80
    Width = 253
    Height = 30
    AutoOpen = True
    FileName = 'awp3.wav'
    Visible = False
    TabOrder = 4
  end
  object MediaPlayer4: TMediaPlayer
    Left = 392
    Top = 112
    Width = 253
    Height = 30
    AutoOpen = True
    FileName = 'awp4.wav'
    Visible = False
    TabOrder = 5
  end
  object MediaPlayer5: TMediaPlayer
    Left = 392
    Top = 144
    Width = 253
    Height = 30
    AutoOpen = True
    FileName = 'awp5.wav'
    Visible = False
    TabOrder = 6
  end
  object Panel1: TPanel
    Left = 72
    Top = 8
    Width = 289
    Height = 393
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 16
      Top = 8
      Width = 35
      Height = 20
      Caption = #1058#1072#1085#1082
    end
    object Label2: TLabel
      Left = 24
      Top = 40
      Width = 63
      Height = 20
      Caption = #1052#1110#1094#1085#1110#1089#1090#1100
    end
    object Label3: TLabel
      Left = 24
      Top = 72
      Width = 71
      Height = 20
      Caption = #1064#1074#1080#1076#1082#1110#1090#1100
    end
    object Label4: TLabel
      Left = 24
      Top = 104
      Width = 132
      Height = 20
      Caption = #1057#1082#1086#1088#1086#1089#1090#1088#1110#1083#1100#1085#1110#1089#1090#1100
    end
    object Label5: TLabel
      Left = 16
      Top = 176
      Width = 58
      Height = 20
      Caption = #1057#1085#1072#1088#1103#1076
    end
    object Label6: TLabel
      Left = 24
      Top = 208
      Width = 86
      Height = 20
      Caption = #1055#1086#1090#1091#1078#1085#1110#1089#1090#1100
    end
    object Label7: TLabel
      Left = 48
      Top = 240
      Width = 23
      Height = 20
      Caption = #1074#1110#1076
    end
    object Label8: TLabel
      Left = 176
      Top = 240
      Width = 20
      Height = 20
      Caption = #1076#1086
    end
    object Label9: TLabel
      Left = 32
      Top = 280
      Width = 71
      Height = 20
      Caption = #1064#1074#1080#1076#1082#1110#1090#1100
    end
    object Label11: TLabel
      Left = 24
      Top = 136
      Width = 131
      Height = 20
      Caption = #1054#1073#1077#1088#1090#1072#1085#1085#1103' '#1073#1072#1096#1085#1110
    end
    object Edit1: TEdit
      Left = 184
      Top = 40
      Width = 81
      Height = 28
      TabOrder = 0
      Text = '100'
    end
    object Edit2: TEdit
      Left = 184
      Top = 72
      Width = 81
      Height = 28
      TabOrder = 1
      Text = '3'
    end
    object Edit3: TEdit
      Left = 184
      Top = 104
      Width = 81
      Height = 28
      TabOrder = 2
      Text = '25'
    end
    object Edit4: TEdit
      Left = 88
      Top = 240
      Width = 57
      Height = 28
      TabOrder = 3
      Text = '10'
    end
    object Edit5: TEdit
      Left = 208
      Top = 240
      Width = 57
      Height = 28
      TabOrder = 4
      Text = '30'
    end
    object Edit6: TEdit
      Left = 184
      Top = 280
      Width = 81
      Height = 28
      TabOrder = 5
      Text = '45'
    end
    object Button1: TButton
      Left = 80
      Top = 328
      Width = 137
      Height = 33
      Caption = #1047#1073#1077#1088#1077#1075#1090#1080
      TabOrder = 6
      OnClick = Button1Click
    end
    object Edit7: TEdit
      Left = 184
      Top = 136
      Width = 81
      Height = 28
      TabOrder = 7
      Text = '5'
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 48
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 48
    Top = 8
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072' '#1075#1088#1072
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1053#1072#1083#1072#1096#1090#1091#1074#1072#1085#1085#1103
      OnClick = N2Click
    end
    object N3: TMenuItem
      Caption = #1064#1074#1080#1076#1082#1110#1090#1100
      object N181: TMenuItem
        Caption = '*1/8'
        OnClick = N181Click
      end
      object N141: TMenuItem
        Caption = '*1/4'
        OnClick = N141Click
      end
      object N121: TMenuItem
        Caption = '*1/2'
        OnClick = N121Click
      end
      object N111: TMenuItem
        Caption = '*1'
        OnClick = N111Click
      end
      object N22: TMenuItem
        Caption = '*2'
        OnClick = N22Click
      end
      object N32: TMenuItem
        Caption = '*4'
        OnClick = N32Click
      end
    end
    object N4: TMenuItem
      Caption = #1058#1088#1072#1089#1072
      object N5: TMenuItem
        Caption = #1055#1088#1103#1084#1086#1082#1091#1090#1085#1080#1082
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1042#1110#1089#1110#1084#1082#1072
        OnClick = N6Click
      end
      object N8: TMenuItem
        Caption = #1043#1086#1088#1080#1079#1086#1085#1090#1072#1083#1100#1085#1072' "'#1053'"'
        OnClick = N8Click
      end
    end
    object N7: TMenuItem
      Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
      OnClick = N7Click
    end
  end
end
