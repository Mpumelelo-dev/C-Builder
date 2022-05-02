object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 579
  ClientWidth = 984
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
    Left = 384
    Top = 8
    Width = 57
    Height = 24
    Caption = 'Label1'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Trebuchet MS'
    Font.Style = []
    ParentFont = False
  end
  object dbgrdRangers: TDBGrid
    Left = 136
    Top = 38
    Width = 681
    Height = 401
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object btnInsert: TButton
    Left = 144
    Top = 464
    Width = 177
    Height = 25
    Caption = 'Create a new record'
    TabOrder = 1
    OnClick = btnInsertClick
  end
  object btnUpdate: TButton
    Left = 400
    Top = 464
    Width = 177
    Height = 25
    Caption = 'Update a record'
    TabOrder = 2
    OnClick = btnUpdateClick
  end
  object btnDel: TButton
    Left = 640
    Top = 464
    Width = 177
    Height = 25
    Caption = 'Delete a record'
    TabOrder = 3
    OnClick = btnDelClick
  end
  object edtName: TEdit
    Left = 832
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object edtSurname: TEdit
    Left = 832
    Top = 107
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object edtReportCamp: TEdit
    Left = 832
    Top = 195
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object DateTimePicker1: TDateTimePicker
    Left = 832
    Top = 136
    Width = 121
    Height = 21
    Date = 44517.000000000000000000
    Time = 0.689519571758864900
    TabOrder = 7
  end
  object cmbRanks: TComboBox
    Left = 832
    Top = 163
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'cmbRanks'
    Items.Strings = (
      'Recruit'
      'Field'
      'Park'
      'Section'
      'Senior')
  end
end
