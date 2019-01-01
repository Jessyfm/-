#include <fstream> 
#include<iostream>  
#include<stdio.h>                 //C���Ա�׼�������ͷ�ļ�
#include<stdlib.h>                //�ļ�������Ҫ�õ���ͷ�ļ�
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Teacher_inf.h"
using namespace std;  

 
Teacher::Teacher()
{        
      r_teacherinf();
}
 /*****************************************************************************************************************/
Teacher::~Teacher()
{        
     delete []teacher;
}
 /*****************************************************************************************************************/
void Teacher::w_teacherinf ()
{
		fstream File1;
		File1.open("��ʦ��Ϣ.txt",ios_base::out);
        File1<<teacherNum<<endl;
		for(int teacherNum1=0;teacherNum1<teacherNum;teacherNum1++)
		{ 
    	  File1<<"      "<<teacher[teacherNum1].id<<"         "<<teacher[teacherNum1].college<<"          "<<teacher[teacherNum1].name<<"      "<<teacher[teacherNum1].phone
			   <<"       "<<teacher[teacherNum1].password<<"         "<<teacher[teacherNum1].email<<"\r\n" ;
		}
	    File1.close();
}
 /*****************************************************************************************************************/
void Teacher::r_teacherinf ()
{
	    ifstream File1;
		File1.open("��ʦ��Ϣ.txt",ios_base::in | ios_base::binary);
		if (File1)
		{   
	     teacherNum=0;
		 File1>>teacherNum;

		for(int teacherNum1=0;teacherNum1<teacherNum;teacherNum1++)
		{ 
    	  File1>>teacher[teacherNum1].id>>teacher[teacherNum1].college>>teacher[teacherNum1].name>>teacher[teacherNum1].phone
			   >>teacher[teacherNum1].password>>teacher[teacherNum1].email;
		}
	    File1.close();
		}
		else
	    cout<<"�ļ���Ч\n";
}
 /*****************************************************************************************************************/
int Teacher:: teacherRegisteration()                    //��֤��ʦ������Ϣ�ĺ���
{  
    cout<<"���������Ľ�ʦ����:  ";
	cin>>teacherID;
	int i=0;
	while(strcmp(teacherID,teacher[i].id)!=0)
	{
		i++;
		if(i>teacherNum)
		{
		cout<<"        �����ID��Ч\n";
        	cout<<"        ���������� :";
        cin>>teacherID;
        	i=0;
		}
	}
	cout<<"        ����������:  ";
	cin>>teacherPassword;
	while(strcmp(teacherPassword,teacher[i].password)!=0)
	{
	  cout<<"        ������Ч\n";
      cout<<"        ��������������:  ";
      cin>>teacherPassword;
	}
	Tself_num=i;
	temp=teacher[i];
	return Tself_num;
}
 /*****************************************************************************************************************/
void Teacher::showedAllCourses()                      //�鿴���пγ���Ϣ
{
	Lesson::showalllesson();                          //��ʾ���еĿγ���Ϣ
	cout<<"\n�������ص���ʦ����ѡ�����\n"; 
	system("pause");
}
 /*****************************************************************************************************************/
void Teacher::showMyCourses_tea()    //�鿴�Լ�������Ŀγ�
{  
    cout<<"����Ϊ���ѿ���Ŀγ�: \n";
	Lesson::SearchByTeachername(temp.name);	
}
 /*****************************************************************************************************************/
void Teacher::searchcourse()                            //���ÿγ̲��� 
{
	int i,j,ii;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��ϵͳ�ṩ���ֲ�ѯ��ʽ��\n";
    cout<<"-------------[ 1.�γ̱�� ]\n";
    cout<<"-------------[ 2.�γ����� ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>2)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����2��:";
	    cin>>choose;
    }     
    switch(choose)
    {
    	case 1:
            system("cls");
		    cout<<"��������Ҫ���ҵĿγ̱�ţ�"<<endl;
			char ID[11];
			cin>>ID;	
			system("cls");                   
		    cout<<"����Ϊ���Ŀγ̲�ѯ���: \n";
			Lesson::showlesson_title();
			for(i=0;i<lessonNum;i++)
			{
				if((strcmp(ID,lesson[i].id)==0)&&(strcmp(teacher[Tself_num].name,lesson[i].teacherName)==0))
				{
					Lesson::showlesson(i);
                    ii=1;
				}
			}
	        break;
		case 2:
            system("cls");
		    cout<<"��������Ҫ���ҵĿγ����ƣ�"<<endl;
        	char Name[21];
			cin>>Name;
			system("cls");                       
			cout<<"����Ϊ���Ŀγ̲�ѯ���: \n";
			Lesson::showlesson_title();
			for(j=0;j<lessonNum;j++)
			{
				if((strcmp(Name,lesson[j].name)==0)&&(strcmp(teacher[Tself_num].name,lesson[j].teacherName)==0))
				{
					Lesson::showlesson(j);
				    ii=1;
				}
			}
			break;
	}
	if(ii!=1)
	{   
		system("cls");                      
	    cout<<"����ؿγ�"<<endl<<"�������ؽ�ʦ����ѡ�����"<<endl;
	    system("pause");
	}
	else
	{
	  cout<<endl;
	  cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
      cout<<"����������ѡ��\n";
      cout<<"-------------[ 1.�γ�ɾ��             ]\n";
      cout<<"-------------[ 2.�γ���Ϣ�޸�         ]\n";
      cout<<"-------------[ 3.���ؽ�ʦ����ѡ����� ]\n";
	  cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
      cout<<"��������Ӧ���ܵı�ţ�"; 
      int choose1;
	  cin>>choose1; 
	  cout<<endl;
      while(choose1<1||choose1>3)           //�ݴ�  �����������еĹ�������ʱѭ�� 
	  { 
	    cout<<"�����������Ч�����������루1����3��:";
	    cin>>choose1;
	  }     
	  switch(choose1)//switch���ѡ��ִ�й���
	  {
    	case 1:
			deletecourse();
			break;
		case 2:
			editcourse();
			break;
	  }
	}
}

 /*****************************************************************************************************************/
void Teacher:: modifycourse()              // �γ���Ϣ�޸�
{ 
	if(Savebutton)
   {
		cout<<"ϵͳ��ȷ�Ͽγ���Ϣ���ݲ�֧�ֱ༭����������ѯ����Ա:��ҽ1601�������Tel��18774854031��\n"<<"�������ؽ�ʦ����ѡ�����"<<endl;
        system("pause");
   }
  else
  {		
	showMyCourses_tea();    //�鿴�Լ�������Ŀγ�
	cout<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"����ѡ��\n";
    cout<<"------------[ 1.�γ�ɾ��             ]\n";
    cout<<"------------[ 2.�γ���Ϣ�޸�         ]\n";
    cout<<"------------[ 3.���ؽ�ʦ����ѡ����� ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose1;
	cin>>choose1; 
	 while(choose1<1||choose1>3)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����3��:";
	    cin>>choose1;
    }     
	switch(choose1)//switch���ѡ��ִ�й���
    {
    	case 1:
		    deletecourse();
			break;
		case 2:
			editcourse();
			break;
	}
  }
}
 /*****************************************************************************************************************/
void Teacher::deletecourse()
{
   if(Savebutton)
   {
		cout<<"ϵͳ��ȷ�Ͽγ���Ϣ���ݲ�֧�ֱ༭����������ѯ����Ա:��ҽ1601�������Tel��18774854031��"<<endl<<"�������ؽ�ʦ����ѡ�����"<<endl;
        system("pause");
   }
  else
  {
   cout<<"��������ɾ���γ̵ı�ţ�";
   char ID[11];
   cin>>ID;	
   int i=0;
   while(strcmp(ID,lesson[i].id)!=0 || strcmp(teacher[Tself_num].name,lesson[i].teacherName)!=0 || lesson[i].nownum>0)
    {
        i++;
        if(i>lessonNum)
        {
            cout<<"����Ŀγ̱����Ч��ÿγ���ѡ��������0����ɾ��\n";
			break;	
        }	
    }
   if(i<=lessonNum)
   {
   int deletedLine=i;
   fstream File2;
   File2.open("�γ�����.txt",ios_base::out);
   int lessonnum=lessonNum-1;
   File2<<lessonnum<<"   "<<Savebutton<<endl;
   for(int lessonNum1=0;lessonNum1<lessonNum;lessonNum1++)
   { 
	   if(lessonNum1!=deletedLine)
	   {
			File2<<lesson[lessonNum1].id<<"  "<<lesson[lessonNum1].name<<"    "<<lesson[lessonNum1].credit<<"    "<<lesson[lessonNum1].ltimes<<"    "<<lesson[lessonNum1].teacherName
			<<"  "<<lesson[lessonNum1].weeks<<"  "<<lesson[lessonNum1].time1<<"  "<<lesson[lessonNum1].time2<<"  "<<lesson[lessonNum1].classplace<<"  "<<lesson[lessonNum1].maxnum<<"  "<<lesson[lessonNum1].nownum<<endl;
	   }
	}
   File2.close();
   Lesson::r_lessoninf();      
   cout<<"\nɾ����ϡ�"<<endl;
   }
  cout<<"\n�������ص���ʦ����ѡ�����\n"; 
  system("pause");
}
}
/*****************************************************************************************************************/
void Teacher:: editcourse()
{
	if(Savebutton)
   {
		cout<<"ϵͳ��ȷ�Ͽγ���Ϣ���ݲ�֧�ֱ༭����������ѯ����Ա:��ҽ1601�������Tel��18774854031��"<<endl<<"�������ؽ�ʦ����ѡ�����"<<endl;
        system("pause");
   }
  else
  {
   cout<<"���������޸Ŀγ̵ı�ţ�";
   char ID[11];
   cin>>ID;	
   cout<<endl;
   int i=0;
   while(strcmp(ID,lesson[i].id)!=0 || strcmp(teacher[Tself_num].name,lesson[i].teacherName)!=0 || lesson[i].nownum>0)
    {
        i++;
        if(i>lessonNum)
        {
            cout<<"����Ŀγ̱����Ч��ÿγ���ѡ��������0�����޸�\n";
	        cout<<"�������ص���ʦ����ѡ�����\n"; 
            system("pause");
            allfunction();
			break;	
        }	
    }
   cout<<"�������µĿγ�ѧ��:";
   cin>>lesson[i].credit; cout<<endl;
   while(lesson[i].credit<1||(lesson[i].credit-(int) lesson[i].credit)!=0)
   {
	   cout<<"�γ�ѧ�ֱ���Ϊ���ڵ���1�����������������룺";
	   cin>>lesson[i].credit; cout<<endl;
   }	
   cout<<"�������µĿγ�ѧʱ:";
   cin>>lesson[i].ltimes; cout<<endl;
   while(lesson[i].ltimes<20)
   {
	   cout<<"�γ�ѧʱ�������20�����������룺";
	   cin>>lesson[i].ltimes; cout<<endl;
   }		
   cout<<"�������µĿγ��������磺X-X�ܣ�:";
   cin>>lesson[i].weeks; cout<<endl;
   cout<<"�������µĿγ��Ͽ�ʱ��1����:��X��XX��):";
   cin>>lesson[i].time1;   cout<<endl;
   cout<<"�������µĿγ��Ͽ�ʱ��2����:��X��XX��):";
   cin>>lesson[i].time2; cout<<endl;
   cout<<"�������µĿγ��Ͽεص㣨�磺S201��:";
   cin>>lesson[i].classplace; cout<<endl;
   cout<<"�������µĿγ����ѡ������:";
   cin>>lesson[i].maxnum; cout<<endl;
   Lesson:: w_lessoninf();
   Lesson:: r_lessoninf();
   cout<<"�޸ĳɹ����޸ĺ�Ŀγ���Ϣ���£�"<<endl<<endl;
   Lesson:: showlesson_title();
   Lesson::showlesson(i);
   cout<<"\n�������ص���ʦ����ѡ�����\n"; 
   system("pause");
}
}
 /*****************************************************************************************************************/
void Teacher::addcourse()
{	
	if(Savebutton)
	{
		cout<<"ϵͳ��ȷ�Ͽγ���Ϣ���ݲ�֧�ֱ༭����������ѯ����Ա:��ҽ1601�������Tel��18774854031��"<<endl<<"�������ؽ�ʦ����ѡ�����"<<endl;
        system("pause");
	}
	else
	{
		int x,i;
		for(x=0;x<2;x++)
		{	 system("cls");
			Lesson:: data1 temp;
			strcpy(temp.teacherName,teacher[Tself_num].name);
			cout<<"��ʼ��ӿγ�(����2��)"<<endl;
			cout<<"����γ̱��:";
			cin>>temp.id;   cout<<endl;
			cout<<"������γ�����(���޺�����ĸ����):";
			cin>>temp.name; cout<<endl;
			cout<<"������γ�ѧ��:";
			cin>>temp.credit; cout<<endl;
			while(temp.credit<1||(temp.credit-(int) temp.credit)!=0)
			{
				cout<<"�γ�ѧ�ֱ���Ϊ���ڵ���1�����������������룺";
				cin>>temp.credit; cout<<endl;
			}	
			cout<<"������γ�ѧʱ:";
			cin>>temp.ltimes; cout<<endl;
			while(temp.ltimes<20)
			{
				cout<<"�γ�ѧʱ�������20�����������룺";
				cin>>temp.ltimes; cout<<endl;
			}		
			cout<<"������γ�������X-X�ܣ�:";
			cin>>temp.weeks; cout<<endl;
			cout<<"������γ��Ͽ�ʱ��1����X��XX�ڣ�:";
			cin>>temp.time1; cout<<endl;
			cout<<"������γ��Ͽ�ʱ��2����X��XX�ڣ�:";
			cin>>temp.time2; cout<<endl;
			cout<<"������γ��Ͽεص㣨�磺S201��:";
			cin>>temp.classplace; cout<<endl;
			cout<<"������γ����ѡ��������";
			cin>>temp.maxnum; cout<<endl;
			temp.nownum=0;
			for(i=0;i<lessonNum;i++)   //ͨ�� for �� if ���ж�ͬһ����ʦ���Ͽ�ʱ�䲻�ܳ�ͻ 
			{
				if(strcmp(lesson[i].id, temp.id)==0)      //�γ̱�Ų����ظ�
				{
					cout<<"�ÿγ̱���뵱ǰ���ڵĿγ̱�ų�ͻ����������γ̱��:"<<i<<"  "<<lesson[i].id;
					cin>>temp.id;
				}
					if((strcmp(lesson[i].name ,temp.name)==0))   //�γ��������ظ�
				{
					cout<<"�ÿγ������뵱ǰ���ڵĿγ����Ƴ�ͻ����������γ�����:"<<i<<"  "<<lesson[i].id;
					cin>>temp.name;
				}
					if((strcmp(lesson[i].teacherName,temp.teacherName)==0))    //  �Լ����Ͽ�ʱ�䲻�ܳ�ͻ 
				{
					if((strcmp(lesson[i].weeks,temp.weeks)==0))
					{
						if((strcmp(lesson[i].time1,temp.time1)==0) ||(strcmp(lesson[i].time1,temp.time2)==0)||(strcmp(lesson[i].time2,temp.time1)==0) ||(strcmp(lesson[i].time2,temp.time2)==0))
						{
							cout<<"�ÿγ̺͸ý�ʦ�Ͽ�ʱ���ͻ"<<"\n����������γ�������X-X�ܣ�:";
							cin>>temp.weeks;
							cout<<"\n���������Ͽο�ʼʱ��1����X��XX��;��X��XX��;...;��:";
							cin>>temp.time1;
                            cout<<"\n���������Ͽο�ʼʱ��2����X��XX��;��X��XX��;...;��:";
							cin>>temp.time2;
						} 
					}
				}
					if(strcmp(lesson[i].weeks,temp.weeks)==0)               //�ͱ��˵��Ͽ�ʱ��ص���Ҳ��ܳ�ͻ 
				{
						if((strcmp(lesson[i].time1,temp.time1)==0) ||(strcmp(lesson[i].time1,temp.time2)==0)||(strcmp(lesson[i].time2,temp.time1)==0) ||(strcmp(lesson[i].time2,temp.time2)==0))
					{
						if(strcmp(lesson[i].classplace,temp.classplace)==0) 
						{
							cout<<"�ÿγ̸������Ͽ�ʱ��ص��ͻ"<<"\n����������γ�������X-X�ܣ�:";
							cin>>temp.weeks;
							cout<<"\n���������Ͽο�ʼʱ��1����X��XX��;��X��XX��;...;��:";
							cin>>temp.time1;
							cout<<"\n���������Ͽο�ʼʱ��2����X��XX��;��X��XX��;...;��:";
							cin>>temp.time2;
							cout<<"\n����������γ��Ͽεص㣨�磺S201��:";
							cin>>temp.classplace;
						} 
					} 
				}
			}
	   lesson[lessonNum]=temp;//���µĿγ̼ӽ�ȥ
	   lessonNum++;  
	   Lesson::w_lessoninf();
	   Lesson::r_lessoninf();
}
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"����������ѡ��\n";
    cout<<"-------------[ 1.����¼�� ]\n";
    cout<<"-------------[ 2.��������ʦ���ܽ��� ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
		int choose;
		cin>>choose;
		while(choose<1||choose>2)                 //�����������еĹ�������ʱѭ��
		{ 
			cout<<"�����������Ч�����������루1����2��:";
			cin>>choose;
		}   
		switch(choose) 
		{
		case 1:
			system("cls");	
			addcourse();
			break;
		case 2:
			system("cls");	
			break;  	
		}
	}
}
 /*****************************************************************************************************************/
 void Teacher::saveinf ()
 {  	
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"��ܰ��ʾ���γ���Ϣ����󲻿��޸�------------------------------------------------------------------------------------------\n";
    cout<<"����ѡ��\n";
    cout<<"---------[ 1.�γ���Ϣ����                       ]\n";
    cout<<"---------[ 2.ȡ�����β��������ؽ�ʦ����ѡ����� ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose1;
	cin>>choose1; 
	 while(choose1<1||choose1>2)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����2��:";
	    cin>>choose1;
    }     
	switch(choose1)//switch���ѡ��ִ�й���
    {
    	case 1:
              Savebutton=1;      //SavebuttonΪ0ʱ��ʵ�ֱ༭
			  system("cls");	
	          cout<<"ϵͳ��ȷ�Ͽγ���Ϣ���ݲ�֧�ֱ༭����������ѯ����Ա:��ҽ1601�������Tel��18774854031��"<<endl<<"�������ؽ�ʦ����ѡ�����"<<endl;
              system("pause");
		      break;
		case 2:	break;
 }
 }
 /*****************************************************************************************************************/
 void Teacher::master_inf ()
 { 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"����ѡ���޸ĸ�����Ϣ�� \n";
    cout<<"-------------[ 1.�޸�����   ] \n";
    cout<<"-------------[ 2.�����ֻ��� ]\n";
    cout<<"-------------[ 3.��������   ]\n";	
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>3)                 //�����������еĹ�������ʱѭ��
		{ 
			cout<<"�����������Ч�����������루1����3��:";
			cin>>choose;
		}   
		switch(choose) 
		{
		case 1:
			system("cls");	
			editpassword();
			break;
		case 2:
			system("cls");	
			edittel();
			break;
		case 3:
			system("cls");	
			editemail();
			break;
		}
		w_teacherinf ();
	    r_teacherinf ();
		cout<<"��ʦ��Ϣ�޸ĳɹ���";
		cout<<"�������ص���ʦ����ѡ�����\n"; 
        system("pause");
 }
 /*****************************************************************************************************************/
void Teacher::editpassword()
{
	cout<<"�����������룺  "<<endl;
	char password1[81];
    scanf("%s",password1);
    strcpy(teacher[Tself_num].password,password1);
}
 /*****************************************************************************************************************/
void Teacher::edittel()
{
	cout<<"�������µĵ绰���룺  "<<endl;
    char phone1[20];
	 scanf("%s",phone1);
    strcpy(teacher[Tself_num].phone,phone1);
}
 /*****************************************************************************************************************/
void Teacher::editemail()
{
	cout<<"�������µ����䣺  "<<endl;
	char email1[81];
	 scanf("%s",email1);
    strcpy(teacher[Tself_num]. email, email1);
}
/*****************************************************************************************************************/
void Teacher::allfunction()
{
	system("cls");                     
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------< �� ʦ �� �� ϵ ͳ >---------------------------------------------------------\n";
	cout<<"-----["<<setw(6)<<teacher[Tself_num].id<<"   " <<setw(4)<<teacher[Tself_num].name<<"]   ��ӭʹ��-------------------------------------------------------------------------------------------\n"; 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------------1.�鿴���п���γ�   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------2.��ʾ�ҵĿ���γ�   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------3.�γ̲���           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------4.�γ�¼��           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------5.�γ̱༭           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------6.�γ���Ϣ����       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------7.������Ϣ����       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------8.����Ȩ�޵�¼ϵͳ   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------9.�˳�ϵͳ           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>9)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����9��:";
	    cin>>choose;
    }     
    switch(choose)//switch���ѡ��ִ�й���
    {
    	case 1:
            system("cls");
			showedAllCourses();
	    	allfunction();
			break;
		case 2:
		    system("cls"); 
	        showMyCourses_tea();       //���ò�ѯ�Լ��ѿ���γ̺���
			cout<<"�������ص���ʦ����ѡ�����\n"; 
        	system("pause");
			allfunction();
			break;
	    case 3:
		    system("cls");
			searchcourse();        //���ÿγ̲��� 
		    allfunction(); 
			break;
    	case 4:
	        system("cls");         //���� 
	        addcourse();          
	        allfunction();     
	        break;
		case 5:		  
	        system("cls");      //���� 
	        modifycourse();     
	        allfunction();    //�ص���ʦ����ѡ�� 
	        break;
		case 6:
	        system("cls");         //���� 
	         saveinf();//����  ���ݿγ����Ʋ�ѯ ���� 
	        allfunction();     //�ص���ʦ����ѡ�� 
			break;
		case 7:
		    system("cls");
            master_inf();
			allfunction();
		case 8:
	        system("cls");       //���� 
			cout<<"�������ص�Ȩ�޵�¼����\n"; 
        	system("pause");
	        break;
		case 9:
	        system("cls");       //���� 
         	Lesson::over();
	        break;
	}
}
