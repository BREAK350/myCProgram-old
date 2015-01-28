object Form3: TForm3
  Left = 285
  Top = 89
  Caption = 'Form3'
  ClientHeight = 540
  ClientWidth = 787
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 23
  object Panel1: TPanel
    Left = 8
    Top = 71
    Width = 761
    Height = 442
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 48
      Width = 20
      Height = 23
      Caption = 'f='
    end
    object Label3: TLabel
      Left = 599
      Top = 48
      Width = 21
      Height = 23
      Caption = '->'
    end
    object StringGridF: TStringGrid
      Left = 33
      Top = 24
      Width = 560
      Height = 73
      ColCount = 3
      FixedCols = 0
      RowCount = 2
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 0
    end
    object ComboBoxFRight: TComboBox
      Left = 626
      Top = 45
      Width = 111
      Height = 31
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = 'max'
      Items.Strings = (
        'max'
        'min'
        'extr')
    end
    object StringGridRestrictionLeft: TStringGrid
      Left = 33
      Top = 103
      Width = 560
      Height = 226
      ColCount = 3
      FixedCols = 0
      RowCount = 2
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 2
    end
    object StringGridRestrictionSignedRight: TStringGrid
      Left = 599
      Top = 103
      Width = 138
      Height = 226
      ColCount = 2
      FixedCols = 0
      RowCount = 2
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 3
      OnClick = StringGridsClick
    end
    object StringGridAdditionalRestriction: TStringGrid
      Left = 33
      Top = 335
      Width = 560
      Height = 49
      ColCount = 3
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 4
      OnClick = StringGridsClick
    end
    object Button2: TButton
      Left = 647
      Top = 335
      Width = 42
      Height = 33
      Caption = '='
      TabOrder = 5
      OnClick = ButtonsClick
    end
    object Button3: TButton
      Left = 599
      Top = 335
      Width = 42
      Height = 33
      Caption = '<'
      TabOrder = 6
      OnClick = ButtonsClick
    end
    object Button4: TButton
      Left = 695
      Top = 335
      Width = 42
      Height = 33
      Caption = '>'
      TabOrder = 7
      OnClick = ButtonsClick
    end
    object Button5: TButton
      Left = 320
      Top = 398
      Width = 121
      Height = 33
      Caption = 'OK'
      TabOrder = 8
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 8
    Width = 761
    Height = 57
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 16
      Width = 27
      Height = 23
      Caption = 'N='
    end
    object Label4: TLabel
      Left = 232
      Top = 16
      Width = 72
      Height = 23
      Caption = 'variable:'
    end
    object Label5: TLabel
      Left = 120
      Top = 16
      Width = 29
      Height = 23
      Caption = 'M='
    end
    object Button1: TButton
      Left = 359
      Top = 12
      Width = 122
      Height = 33
      Caption = 'Create'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditN: TEdit
      Left = 41
      Top = 13
      Width = 64
      Height = 31
      TabOrder = 1
      Text = '3'
    end
    object EditVariable: TEdit
      Left = 310
      Top = 13
      Width = 27
      Height = 31
      MaxLength = 1
      TabOrder = 2
      Text = 'x'
    end
    object EditM: TEdit
      Left = 155
      Top = 13
      Width = 64
      Height = 31
      TabOrder = 3
      Text = '2'
    end
  end
end
