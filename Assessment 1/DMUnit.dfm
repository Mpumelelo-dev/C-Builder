object DMod: TDMod
  OldCreateOrder = False
  Height = 295
  Width = 425
  object ADOdsRanger: TADODataSet
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=F:\Exercise 2\\Exe' +
      'rcise 2\\AppFiles\\KrugerPark.mdb;Persist Security Info=False'
    CursorType = ctStatic
    Parameters = <>
    Left = 32
    Top = 96
  end
  object dsRanger: TDataSource
    DataSet = ADOdsRanger
    Left = 32
    Top = 160
  end
  object ADOConn: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=F:\Exercise 2\\Exe' +
      'rcise 2\\AppFiles\\KrugerPark.mdb;Persist Security Info=False'
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 40
    Top = 32
  end
end
