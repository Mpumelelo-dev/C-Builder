object frmDBConcepts: TfrmDBConcepts
  Left = 0
  Top = 0
  Caption = 'frmDBConcepts'
  ClientHeight = 450
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 108
    Width = 60
    Height = 13
    Caption = 'Ranger data'
  end
  object Label2: TLabel
    Left = 177
    Top = 299
    Width = 74
    Height = 13
    Caption = 'Date appointed'
  end
  object Label3: TLabel
    Left = 176
    Top = 256
    Width = 42
    Height = 13
    Caption = 'Surname'
  end
  object Label4: TLabel
    Left = 176
    Top = 379
    Width = 74
    Height = 13
    Caption = 'Date appointed'
  end
  object Label5: TLabel
    Left = 176
    Top = 339
    Width = 42
    Height = 13
    Caption = 'Surname'
  end
  object Label6: TLabel
    Left = 135
    Top = 419
    Width = 35
    Height = 13
    Caption = 'Sort on'
  end
  object grdRanger: TDBGrid
    Left = 8
    Top = 127
    Width = 568
    Height = 120
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object btnShowData: TButton
    Left = 64
    Top = 25
    Width = 106
    Height = 25
    Caption = 'Show Rangers'
    TabOrder = 1
    OnClick = btnShowDataClick
  end
  object btnFirst: TButton
    Left = 64
    Top = 71
    Width = 75
    Height = 25
    Caption = '<<'
    TabOrder = 2
    OnClick = btnFirstClick
  end
  object btnPrevious: TButton
    Left = 176
    Top = 71
    Width = 75
    Height = 25
    Caption = '<'
    TabOrder = 3
    OnClick = btnPreviousClick
  end
  object btnLast: TButton
    Left = 448
    Top = 71
    Width = 75
    Height = 25
    Caption = '>>'
    TabOrder = 4
    OnClick = btnLastClick
  end
  object btnNext: TButton
    Left = 304
    Top = 71
    Width = 75
    Height = 25
    Caption = '>'
    TabOrder = 5
    OnClick = btnNextClick
  end
  object DBEdit1: TDBEdit
    Left = 274
    Top = 253
    Width = 121
    Height = 21
    DataSource = DMod.dsRanger
    TabOrder = 6
  end
  object DBEdit2: TDBEdit
    Left = 274
    Top = 296
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object btnDispDBEdits: TButton
    Left = 64
    Top = 256
    Width = 106
    Height = 25
    Caption = 'Display in DBEdits'
    TabOrder = 8
    OnClick = btnDispDBEditsClick
  end
  object btnDispEdits: TButton
    Left = 72
    Top = 336
    Width = 98
    Height = 25
    Caption = 'Display in Edits'
    TabOrder = 9
    OnClick = btnDispEditsClick
  end
  object Edit1: TEdit
    Left = 272
    Top = 336
    Width = 121
    Height = 21
    TabOrder = 10
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 272
    Top = 376
    Width = 121
    Height = 21
    TabOrder = 11
    Text = 'Edit2'
  end
  object cmbSort: TComboBox
    Left = 176
    Top = 421
    Width = 217
    Height = 21
    ItemIndex = 0
    TabOrder = 12
    Text = 'Surname'
    OnChange = cmbSortChange
    Items.Strings = (
      'Surname'
      'Appointed'
      'RangerID')
  end
end
