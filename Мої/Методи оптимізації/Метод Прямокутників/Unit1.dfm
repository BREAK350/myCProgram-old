object MainForm: TMainForm
  Left = 244
  Top = 110
  BorderStyle = bsDialog
  Caption = #1052#1077#1090#1086#1076#1080' '#1086#1087#1090#1080#1084#1110#1079#1072#1094#1110#1111
  ClientHeight = 519
  ClientWidth = 857
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object PanelTools: TPanel
    Left = 232
    Top = 383
    Width = 617
    Height = 129
    TabOrder = 3
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 617
      Height = 129
      TabOrder = 1
      Visible = False
      object Button1: TButton
        Left = 16
        Top = 8
        Width = 185
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1087#1110#1074#1085#1110#1095#1085#1086'-'#1079#1072#1093#1110#1076#1085#1086#1075#1086' '#1082#1091#1090#1072
        TabOrder = 0
      end
      object Button2: TButton
        Left = 207
        Top = 8
        Width = 202
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1084#1110#1085#1110#1084#1072#1083#1100#1085#1086#1111' '#1074#1072#1088#1090#1086#1089#1090#1110
        TabOrder = 1
      end
      object Button3: TButton
        Left = 16
        Top = 39
        Width = 185
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1087#1086#1076#1074#1110#1081#1085#1086#1111' '#1087#1077#1088#1077#1074#1072#1075#1080
        TabOrder = 2
      end
      object Button4: TButton
        Left = 207
        Top = 39
        Width = 202
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1060#1086#1075#1077#1083#1103
        TabOrder = 3
      end
    end
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 617
      Height = 129
      TabOrder = 0
      Visible = False
      object ButtonChoose: TButton
        Left = 8
        Top = 8
        Width = 137
        Height = 25
        Caption = #1042#1080#1073#1088#1072#1090#1080' '#1103#1082' '#1087#1088#1086#1074#1110#1076#1085#1080#1081
        TabOrder = 0
        OnClick = ButtonChooseClick
      end
    end
  end
  object PanelMatrix: TPanel
    Left = 232
    Top = 8
    Width = 617
    Height = 369
    TabOrder = 0
    object LabelRows: TLabel
      Left = 8
      Top = 338
      Width = 82
      Height = 13
      Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1088#1103#1076#1082#1110#1074
    end
    object LabelCols: TLabel
      Left = 135
      Top = 338
      Width = 92
      Height = 13
      Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1089#1090#1086#1074#1087#1094#1110#1074
    end
    object LabelMatrix: TLabel
      Left = 16
      Top = 8
      Width = 78
      Height = 13
      Caption = #1052#1072#1090#1088#1080#1094#1103' '#1076#1072#1085#1080#1093
    end
    object EditRows: TEdit
      Left = 96
      Top = 335
      Width = 33
      Height = 21
      TabOrder = 0
      Text = '3'
    end
    object EditCols: TEdit
      Left = 233
      Top = 335
      Width = 33
      Height = 21
      TabOrder = 1
      Text = '3'
    end
    object ButtonCreate: TButton
      Left = 456
      Top = 332
      Width = 153
      Height = 28
      Caption = #1057#1090#1074#1086#1088#1080#1090#1080
      TabOrder = 2
      OnClick = ButtonCreateClick
    end
    object CheckBoxCreateWithDelete: TCheckBox
      Left = 272
      Top = 337
      Width = 170
      Height = 17
      Caption = #1057#1090#1074#1086#1088#1080#1090#1080' '#1079' '#1074#1080#1076#1072#1083#1077#1085#1085#1103#1084' '#1076#1072#1085#1080#1093
      TabOrder = 3
    end
    object StringGridMatrix: TStringGrid
      Left = 8
      Top = 32
      Width = 601
      Height = 294
      ColCount = 4
      FixedCols = 0
      RowCount = 4
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 4
      OnGetEditText = StringGridMatrixGetEditText
      RowHeights = (
        24
        24
        24
        24)
    end
  end
  object PanelMenu: TPanel
    Left = 8
    Top = 8
    Width = 218
    Height = 249
    TabOrder = 1
    object LabelMenu: TLabel
      Left = 8
      Top = 13
      Width = 29
      Height = 13
      Caption = #1052#1077#1085#1102
    end
    object ScrollBoxMenu: TScrollBox
      Left = 7
      Top = 32
      Width = 202
      Height = 209
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
      object BitBtn2: TBitBtn
        Left = 3
        Top = 34
        Width = 192
        Height = 55
        Caption = #1052#1077#1090#1086#1076#1080' '#1087#1086#1073#1091#1076#1086#1074#1080' '#1087#1086#1095#1072#1090#1082#1086#1074#1080#1093' '#1086#1087#1088#1086#1088#1085#1080#1093' '#1087#1083#1072#1085#1110#1074' '#1090#1088#1072#1085#1089#1087#1086#1088#1090#1085#1086#1111' '#1079#1072#1076#1072#1095#1110
        DoubleBuffered = True
        ParentDoubleBuffered = False
        TabOrder = 0
        WordWrap = True
        OnClick = BitBtn2Click
      end
      object BitBtn1: TBitBtn
        Left = 3
        Top = 3
        Width = 192
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1087#1088#1103#1084#1086#1082#1091#1090#1085#1080#1082#1110#1074
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 1
        OnClick = BitBtn1Click
      end
      object BitBtn3: TBitBtn
        Left = 3
        Top = 95
        Width = 192
        Height = 25
        Caption = #1052#1077#1090#1086#1076' '#1087#1086#1090#1077#1085#1094#1110#1072#1083#1110#1074
        DoubleBuffered = True
        ParentDoubleBuffered = False
        TabOrder = 2
        OnClick = BitBtn3Click
      end
    end
  end
  object PanelDescription: TPanel
    Left = 7
    Top = 263
    Width = 219
    Height = 249
    TabOrder = 2
    object LabelDescription: TLabel
      Left = 9
      Top = 13
      Width = 25
      Height = 13
      Caption = #1054#1087#1080#1089
    end
    object MemoDescription: TMemo
      Left = 8
      Top = 32
      Width = 202
      Height = 209
      TabOrder = 0
    end
  end
end
