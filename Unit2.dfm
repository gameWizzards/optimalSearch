object Form2: TForm2
  Left = 0
  Top = 0
  ActiveControl = Button1
  Caption = 'Form2'
  ClientHeight = 508
  ClientWidth = 835
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 192
    Width = 809
    Height = 308
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 64
    Top = 64
    Width = 161
    Height = 41
    Caption = #1055#1086#1096#1091#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 138
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1074#1091#1079#1083#1110#1074
    OnClick = Edit1Click
  end
  object Edit2: TEdit
    Left = 152
    Top = 24
    Width = 137
    Height = 22
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = #1055#1086#1088#1103#1076#1086#1082' '#1074#1091#1079#1083#1072
    OnClick = Edit2Click
  end
  object StringGrid1: TStringGrid
    Left = 295
    Top = 24
    Width = 522
    Height = 151
    ColCount = 8
    ScrollBars = ssVertical
    TabOrder = 4
    RowHeights = (
      24
      24
      24
      24
      24)
  end
  object CheckBox1: TCheckBox
    Left = 48
    Top = 158
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    TabOrder = 5
    Visible = False
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 151
    Top = 158
    Width = 97
    Height = 17
    Caption = 'CheckBox2'
    TabOrder = 6
    Visible = False
    OnClick = CheckBox2Click
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 120
    Width = 281
    Height = 21
    HelpType = htKeyword
    Style = csDropDownList
    TabOrder = 7
    TextHint = #1042#1080#1073#1077#1088#1110#1090#1100' '#1086#1076#1080#1085' '#1110#1079' '#1079#1072#1087#1088#1086#1087#1086#1085#1086#1074#1072#1085#1080#1093' '#1074#1072#1088#1110#1072#1085#1090#1110#1074
    OnChange = ComboBox1Change
    Items.Strings = (
      #1064#1091#1082#1072#1090#1080' '#1090#1110#1083#1100#1082#1080' '#1079#1072#1076#1072#1085#1091' '#1084#1077#1088#1077#1078#1091
      #1055#1086#1096#1091#1082' '#1087#1110#1076#1086#1087#1090#1080#1084#1072#1083#1100#1085#1080#1093' '#1074' '#1073#1110#1083#1100#1096#1091' '#1089#1090#1086#1088#1086#1085#1091
      #1055#1086#1096#1091#1082' '#1087#1110#1076#1086#1087#1090#1080#1084#1072#1083#1100#1085#1080#1093' '#1074' '#1084#1077#1085#1096#1091' '#1089#1090#1086#1088#1086#1085#1091
      #1064#1091#1082#1072#1090#1080' '#1091#1089#1110' '#1087#1110#1076#1086#1087#1090#1080#1084#1072#1083#1100#1085#1110' '#1084#1077#1088#1077#1078#1110)
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.xls'
    FileName = 'data'
    Filter = 'Excel|*.xls'
    Left = 40
  end
  object MainMenu1: TMainMenu
    Left = 8
    object N1: TMenuItem
      Caption = #1055#1088#1086' '#1087#1088#1086#1075#1088#1072#1084#1091
      OnClick = N1Click
    end
    object ExporttoExcel1: TMenuItem
      Caption = 'Export'
      object ExporttoExcel2: TMenuItem
        Caption = 'Export to Excel'
        OnClick = ExporttoExcel2Click
      end
      object Exporttotxt1: TMenuItem
        Caption = 'Export to txt'
        OnClick = Exporttotxt1Click
      end
    end
    object N2: TMenuItem
      Caption = #1042#1080#1093#1110#1076
      OnClick = N2Click
    end
  end
  object SaveTextFileDialog1: TSaveTextFileDialog
    DefaultExt = '.txt'
    Filter = 'TXT|*.txt'
    Left = 72
  end
end