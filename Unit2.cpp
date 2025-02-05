//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "cmath"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	this->max = 2;
	setlocale( LC_ALL, "Ukrainian" );

}

void TForm2::start_calc(long int count, int order){

  r = order/2;//��������� ������ �������
  a = pow(count,(float)1/r);//���������� ����� � ����� ���������
  d_max = a; //�������� �������� � ���(������� ������� ����� ���� ��� �������)
  a = a-d_max;// ��������� ������� ����� ������� � �����
  if(a == 0){// ���� ������� ���� �� ��� �������� ��������
	for(int i=0; i<r; i++)
	  number[i] = d_max;// ���������� � �������


  }
  else// ����� ��������� �� ������ �����, ������� ����������� ���������
  {
    a = count;
    for(int i=0, b=count; i<r; i++)
	{
      a = pow(b,(float)1/(r-i));//������� ���������� ����� � ������ ���������(��� ������ ������� ����� �������� 1 �������� ������ ���������)
      max = 2;//������������� ����������� ���������� ����� 2 ��� ���������
      for(;max<a;)// ���� ��� ���������� ���� ����� ������� ����� �� ���� ����� 2^N, ���� ����� ������ ������
      {
        min = max;   //���������� ������ �������
        max = max*2; //�������� ������ ��� ��������� �� 2, ������� �������
      }
	  number[i] = min;// �������� ��������� ���������, � ������������ ��� ��� ��� ������� ���������
      number[i+1] = max;
      min = a-min;// ������� ��������� �� ������� ����� � ���������� ����� ����� �
      max = max-a;// ������� ��������� �� �������� ����� � ���������� ����� ����� �
      if(min>max)//���������� ���������, � ���������� ����� ������
		number[i] = number[i+1];//������������� ��������� �������� �� 1 �������, 2-� � �.�.
      b = b/number[i];//�������� �� ���������� ����� �������� ���
      number[i+1] = b;//������������ ��� ��� ��������� ���� �����
    }
  }
  if(flag_pair_value == false){
	  number[r] = 2;
	  number_nodes = number_nodes*2;
	  node_order++;
	  r++;
  }
  //���� ������� ���������� �������� � ������
  for(int i=1;i<r;i++)
  {
	max = number[i-1];
	if(max>number[i])
    {
	  number[i-1] = number[i];
      number[i] = max;
	  i=0;
	}
  }
};
//---------------------------------------------------------------------------
void TForm2::find_sub_system(long int num, int order){
	for(int i = 0;;i++){
		order--;
	if(order>3)    //������ ���� ������� 4 � ������
	{   //---------------------------------
		a = (float)order/2;
		if(a != (int)a)
		{                                  //�������� �� ��������
			order--;
			num = num/2;
			flag_pair_value = false;
		}
		else
		{
			flag_pair_value = true;
		}//--------------------------------
		start_calc(num, order);
		a = number[0];
		for(int i=1; i<r; i++)             //������ ���������
			if(number[i]>a)
				a = number[i];
		//---------------------------------
		if(flag_pair_value)
		{
			d_max = 2*num/a;         //��������� �� 2 � ���������� � ����� ��������
		}                            //���� ������� �� - �����������
		else
		{
			d_max = 4*num/a;        //��� �������� - �� 4 - ���� �����
		}
		//---------------------------------
		if(d_max == child_bisection)  //���� ������ ��� �������� ������ ��������
		{
			str = IntToStr(number[0]);
			for(int i=1; i<r; i++)
			str = str + "*" + IntToStr(number[i]);
			Form2->Memo1->Lines->Add("");
			if(!flag_pair_value)
			{
				order++;
				num = num*2;
			}
			Form2->Memo1->Lines->Add("ϳ� ����������� ������ ������������ ����� � �������� ����� d = " + IntToStr(order) + " � �������� - " +  str + " �����");
			calc_metrik(num, order);
		}
		else
		{
			if(i == 0)
			{
			Form2->Memo1->Lines->Add("ϳ� ���������� ������� �� ��������.");
			}
			break;
		}

	}
	else
	{
		if(i == 0)
		{
			Form2->Memo1->Lines->Add("ϳ� ���������� ������� �� ��������");
		}
		break;
	}
	}
}

 int value = 0; //��� ���������� ���� ���� ��� ������� ����
//---------------------------------------------------------------------------
void TForm2::calc_metrik(__int64 num, int order){
  if (conf == 0){
	   addCell(0, 0, "_");


	if (ComboBox1->ItemIndex == 3)
		addCell(0, 1, "ó������");
	else
	   addCell(0, 1, "������");

	   addCell(1, 0, "N");
	   addCell(2, 0, "d");
	   addCell(3, 0, "I");
	   addCell(4, 0, "D");
	   addCell(5, 0, "B");
	   addCell(6, 0, "W");
	   addCell(7, 0, "P");

	   conf++;
	   StringGrid1->RowCount += 1;
  }else {
	   addCell(0, conf+1, "O" + IntToStr(conf));
	   conf++;
	   StringGrid1->RowCount += 1;
  }



   //����������� ������� ��'����
   d_max = num*order/2;

   Memo1->Lines->Add("ʳ������ ��'���� (���������� �������) I = " + IntToStr(d_max));

   addCell(N, conf, IntToStr(num));   //�-���  �����
   addCell(d, conf, IntToStr(order)); //������� �����
   addCell(I, conf, IntToStr(d_max)); //�-��� ��'����

   //����������� ������������ ������
   d_max = 0;
   for(int i=0; i<r; i++)
	   d_max = d_max+number[i]/2;

   Memo1->Lines->Add("������������ ������ (����������� �������� �������� ���������� �� ������� ���������� �������) D = " + IntToStr(d_max));
   addCell(D, conf, IntToStr(d_max));

   //����������� ������ �������
   a = number[0];
   for(int i=1; i<r; i++)
	  if(number[i]>a)
		 a = number[i];
   d_max = 2*num/a;

   Memo1->Lines->Add("������ ������� (��������� ������� ��'���� �� ����� ���������� �����) B = " + IntToStr(d_max));
   addCell(B, conf, d_max);

   //����������� ���������� �������
   d_max = num * ((7*order) - 3);

   Memo1->Lines->Add("���������� ������� (������ ��������) I = " + IntToStr(d_max));
   
   addCell(W, conf, IntToStr(d_max));

  if (conf == 1) { // ��� ������ �����
	  value = d_max;
	  addCell(P, conf, "100%");
  } else{          //�� ��������
	float proc = ((float)(d_max)/(float)(value))*100;
	addCell(P, conf, IntToStr((int)proc) + "%");

	//TODO �����
  }
}
 boolean upper_optim = false;
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender){
   //���������� �����-����------------------------------------------------------
	conf = 0;
	for(int i=0;i<StringGrid1->ColCount;i++) //�������� ����
		for(int j=0; j<StringGrid1->RowCount;j++)
			StringGrid1->Cells[i][j] = "";

	 if (ComboBox1->ItemIndex == -1) {
		ShowMessage("������� ���� �� �������������� ������� ������!");
		return;
	}

	//�������� � ������ ��������
	number_nodes = StrToInt(Form2->Edit1->Text);//���������� �����

	if(ComboBox1->ItemIndex != 3){
		node_order   = StrToInt(Form2->Edit2->Text);//������� ����

		if(number_nodes>pow(2,20) || node_order<4 || node_order>20)
		{   // �������� �� ��������� ���������
			ShowMessage("������� ���� �������� ����������� ���� ��������� ���������� �����. �������������, �� ������� ���� ����� ��������� ���� �����: ������� ����� �� ����� ����� 2^20, ������� ����� �� ��������� ����� 20 �� �� ����� ����� 4");
			return;
		}

		//������� �� ��� �������� ���������� ����� ��� ������� �������
		if(number_nodes < pow(4,(node_order/2))){
			ShowMessage("��� ������� ����������� ����� ���� �� �� �����! ��� ������� �������� ������� ����� ��� �������� �� �������.");
			return;
		}
	} else if (number_nodes>pow(2,20)){
		// �������� �� ��������� ���������
		ShowMessage("������� ���� �������� ����������� ���� ��������� ���������� �����. �������������, �� ������� ���� ����� ��������� ���� �����: ������� ����� �� ����� ����� 2^20, ������� ����� �� ��������� ����� 20 �� �� ����� ����� 4");
		return;
	}


	a = number_nodes;  //�������� �� �������������� � ���� ����� 2^N
	int count = 0;
	for(;a>=2;){        // ����� ���������� ������� - a && !(a & (a - 1));
		a = a/2;        // �� ��� ����� �����
		count++;
	}
	if(a != 1){
		for(;max<number_nodes;){
			min = max;
			max = max*2;
		}
		CheckBox1->Visible = true;
		CheckBox2->Visible = true;

		CheckBox1->Caption = min;
		CheckBox2->Caption = max;

		ShowMessage("������������� ����� ����� N=2^n! ������� ���� �� ���� ��������������� �������.");
		return;
	}else{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
	}
//---------------------------------------------����� ��������

	if (ComboBox1->ItemIndex == 3) {   //�� ������������
		node_order = count;
	}

	//��������� ������ ��� ������� ������ �� ���� ��������������
	child_bisection = number_nodes/4;
	//----�������� ������� ���� �� ��������
	a = (float)node_order/2;
	if(a != (int)a){
		node_order--;
		number_nodes = number_nodes/2;
		flag_pair_value = false;
	}else{
		flag_pair_value = true;
	}//------------------------------------

	if(flag_pair_value){
		if(count != node_order)
			Form2->Memo1->Lines->Add("������ �� ���������� ������������ ��� ������� ����� d = " +  IntToStr(count));
		else 
			Form2->Memo1->Lines->Add("������ �� ���������� ������������ d = " +  IntToStr(count));
	}else{
		if(count != node_order+1)
			Form2->Memo1->Lines->Add("������ �� ���������� ������������ ��� ������� ����� d = " +  IntToStr(count));
		else 
			Form2->Memo1->Lines->Add("������ �� ���������� ������������ d = " +  IntToStr(count));

	}

	//������ �������� (������ - number[], r, a)
		start_calc(number_nodes, node_order);  //���� ������ �� �������� �������� as is
											   //���� ��� - �� �� 1 ������� ������
	//��������� ������ � ������ ����
	str = IntToStr(number[0]);
		for(int i=1; i<r; i++)
			str = str + "*" + IntToStr(number[i]);

	if (ComboBox1->ItemIndex == 0 || ComboBox1->ItemIndex == 2 || ComboBox1->ItemIndex == 1) {
		//������ ������ ��� ������������ �����
		Memo1->Lines->Add("");
		Memo1->Lines->Add("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
		Memo1->Lines->Add("������ ��������� - N = " +  Form2->Edit1->Text + " d = " + Form2->Edit2->Text );

		Memo1->Lines->Add("�������� ������������ ����� - " +  str + " �����");
		calc_metrik(number_nodes, node_order);  //������� ��������

	}

	if (ComboBox1->ItemIndex == 1) {
		find_sub_upper(number_nodes, node_order);
	}
	if (ComboBox1->ItemIndex == 2) {
		find_sub_system(number_nodes, node_order);
	}
	if (ComboBox1->ItemIndex == 3) {

		Memo1->Lines->Add("");
		Memo1->Lines->Add("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
		Memo1->Lines->Add("������ ��������� - N = " +  Form2->Edit1->Text);

		Memo1->Lines->Add("ó��������� ������������ ����� - " +  str + " �����");
		calc_metrik(number_nodes, node_order);  //������� ��������

		find_sub_system(number_nodes, node_order);
	}

}
//---------------------------------------------------------------------------


void TForm2::find_sub_upper(long int num, int order){
for(int i = 0, c = 0;;i++){
	order++;
	if(order<20)    //������ ���� ������� 20 � ������
	{   //---------------------------------
		a = (float)order/2;
		if(a != (int)a)
		{                                  //������� �� ��������
			order--;
			num = num/2;
			flag_pair_value = false;
		}
		else
		{
			flag_pair_value = true;
		}//--------------------------------
		start_calc(num, order);
		a = number[0];
		for(int i=1; i<r; i++)             //������ ���������
			if(number[i]>a)
				a = number[i];
		//---------------------------------
		if(flag_pair_value)
		{
			d_max = 2*num/a;         //��������� �� 2 � ���������� � ����� ��������
		}                            //���� ������� �� - �����������
		else
		{
			d_max = 4*num/a;        //��� �������� - �� 4 - ���� �����
		}
		
		if(d_max <= child_bisection || d_max == child_bisection*2)  //���� ������ ��� �������� ������ ��������
		{
			if(d_max == child_bisection*2)
				c++;
			if (c == 2) {
				break;
			}
			str = IntToStr(number[0]);
			for(int i=1; i<r; i++)
				str = str + "*" + IntToStr(number[i]);
			Form2->Memo1->Lines->Add("");
			if(!flag_pair_value)
			{
				order++;
				num = num*2;
			}
			Form2->Memo1->Lines->Add("ϳ� ����������� ������ ������������ ����� � �������� ����� d = " + IntToStr(order) + " � �������� - " +  str + " �����");

			if (d_max >= child_bisection)
				calc_metrik(num, order);
		} else if (i == 0){
			Form2->Memo1->Lines->Add("ϳ� ���������� ������� �� ��������.");
			break;
		}

	}
	else
	{
		if(i == 0)
		{
			Form2->Memo1->Lines->Add("ϳ� ���������� ������� �� ��������");
		}
		break;
	}
}

}

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
	if(Form2->CheckBox1->Checked == true)
  {
	Form2->CheckBox2->Enabled = false;
	Form2->Edit1->Text = Form2->CheckBox1->Caption;
  }
  else
	Form2->CheckBox2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox2Click(TObject *Sender)
{
   if(Form2->CheckBox2->Checked == true)
  {
	Form2->CheckBox1->Enabled = false;
	Form2->Edit1->Text = Form2->CheckBox2->Caption;
  }
  else
	Form2->CheckBox1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1Click(TObject *Sender)
{
	  Form2->Edit1->Text = "";
      Form2->Edit1->Font->Color = clWindowText;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2Click(TObject *Sender)
{
	  Form2->Edit2->Text = "";
	  Form2->Edit2->Font->Color = clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormDestroy(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N2Click(TObject *Sender)
{
	Form1->Close();
    Form2->Close();
}
//---------------------------------------------------------------------------

   void TForm2::makeExcel(){

	WideString str;
	TStringList *sl = new TStringList;
	for(int i = 0 ; i<StringGrid1->RowCount ;++i){
		for(int j = 0; j< StringGrid1->ColCount;++j)

		str +=StringGrid1->Cells[j][i]+ "\t";
        sl->Add(Trim(str));
        str = "\n\r" ;
	SaveDialog1->InitialDir = GetCurrentDir();
	SaveDialog1->DefaultExt = "xls";
	}
	if (SaveDialog1->Execute()){
		sl->SaveToFile(SaveDialog1->FileName);
	}
	delete sl;

	}

void __fastcall TForm2::ExporttoExcel2Click(TObject *Sender)
{
	makeExcel();
}

inline void TForm2::addCell(int row, int column, String ss){
	 Form2->StringGrid1->Cells[row][column] = ss;
}

//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{

	Edit2->Visible = !(ComboBox1->ItemIndex == 3);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::N1Click(TObject *Sender)
{
	Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Exporttotxt1Click(TObject *Sender)
{

	SaveTextFileDialog1->InitialDir = GetCurrentDir();
	SaveTextFileDialog1->DefaultExt = "txt";

	if (SaveTextFileDialog1->Execute()){
		Memo1->Lines->SaveToFile(SaveTextFileDialog1->FileName, NULL);
	}

}
//---------------------------------------------------------------------------

