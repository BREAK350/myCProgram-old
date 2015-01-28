object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 426
  ClientWidth = 662
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 8
    Top = 96
    Width = 320
    Height = 120
    DataSource = DataSource1
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Memo1: TMemo
    Left = 8
    Top = 232
    Width = 320
    Height = 145
    TabOrder = 1
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=EngUk' +
      'r'
    LoginPrompt = False
    Left = 96
    Top = 48
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 216
    Top = 48
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Translation'
    Left = 336
    Top = 48
    object ADOTable1id: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object ADOTable1idEngWord: TIntegerField
      FieldName = 'idEngWord'
    end
    object ADOTable1idUkrWord: TIntegerField
      FieldName = 'idUkrWord'
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 456
    Top = 192
    object new1: TMenuItem
      Caption = 'new...'
    end
    object delete1: TMenuItem
      Caption = 'delete...'
    end
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 488
    Top = 320
  end
end
