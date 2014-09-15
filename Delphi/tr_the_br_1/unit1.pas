unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Menus, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    Timer1: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;
  schet: integer;
implementation

uses Unit2;

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
{функция запускает процесс тренировки}
begin
  Timer1.interval := strtoint(Form2.Edit1.text); {включаем нужную скорость}
  Timer1.Enabled := True;
  schet := 0;
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
{функция открывает меню настройки}
begin
  Form2.show();
end;

procedure TForm1.Timer1Timer(Sender: TObject);
{функция обновляет данные формы (процесс тренировки)}
begin
  schet := schet + 1;
  Label1.caption := inttostr(random(1000));
  if schet = strtoint(Form2.Edit2.text) then Timer1.Enabled := False;
end;

end.

