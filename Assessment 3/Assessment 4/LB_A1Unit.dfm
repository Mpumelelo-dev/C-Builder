object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 299
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblCountNumbers: TLabel
    Left = 199
    Top = 104
    Width = 9
    Height = 21
    Caption = '0'
    Font.Charset = ANSI_CHARSET
    Font.Color = clGreen
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object lstNumbers: TListBox
    Left = 40
    Top = 32
    Width = 121
    Height = 251
    ItemHeight = 13
    TabOrder = 0
  end
  object btnGenerate: TButton
    Left = 167
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Generate'
    TabOrder = 1
    OnClick = btnGenerateClick
  end
  object btnDeleteAll: TButton
    Left = 167
    Top = 258
    Width = 75
    Height = 25
    Caption = 'Delete All'
    TabOrder = 2
    OnClick = btnDeleteAllClick
  end
  object btnDeleteSel: TButton
    Left = 167
    Top = 227
    Width = 90
    Height = 25
    Caption = 'Delete Selected'
    TabOrder = 3
    OnClick = btnDeleteSelClick
  end
  object btnSort: TButton
    Left = 167
    Top = 156
    Width = 75
    Height = 25
    Caption = 'Sort Numbers'
    TabOrder = 4
    OnClick = btnSortClick
  end
  object btnDeleteRandomly: TButton
    Left = 167
    Top = 196
    Width = 90
    Height = 25
    Caption = 'Delete Randomly'
    TabOrder = 5
    OnClick = btnDeleteRandomlyClick
  end
end
