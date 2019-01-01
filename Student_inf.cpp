#include <fstream> 
#include<iostream>  
#include<stdio.h>                 //C���Ա�׼�������ͷ�ļ�
#include<stdlib.h>                //�ļ�������Ҫ�õ���ͷ�ļ�
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Student_inf.h"
using namespace std; 

Student::Student()
{
  r_stu_inf();
  CreditVS4=false;     //Ĭ��ѡ��ѧ�ֲ���4���˳���ѡ���˿�ʱ���ٴθ���
}
/*****************************************************************************************************************/
Student::~Student()
{
	delete []stu;
}
 /*****************************************************************************************************************/
void Student::w_stu_inf ()                                             //д�ļ�
{
		fstream File2;
		File2.open("ѧ����Ϣ.txt",ios_base::out);
        File2<<stuNum<<endl;
		for(int stuNum1=0;stuNum1<stuNum;stuNum1++)
		{ 
	   	 File2<<stu[stuNum1].id<<"   "<<stu[stuNum1].college<<"   "<<stu[stuNum1].major<<"   "<<stu[stuNum1].name<<"   "<<stu[stuNum1].phone
			  <<"   "<<stu[stuNum1].password<<"   "<<stu[stuNum1].email<<"   "<<stu[stuNum1].course1<<"   "<<stu[stuNum1].course2<<"   "<<stu[stuNum1].course3<<endl;;		
	   }
	       File2.close();
}
 /*****************************************************************************************************************/
void Student::r_stu_inf ()                                      //���ļ�
{
     ifstream File2;
	 File2.open("ѧ����Ϣ.txt",ios_base::in | ios_base::binary);
	 if (File2)
	 {   
	   stuNum=0;
	   File2>>stuNum;
	   for(int stuNum1=0;stuNum1<stuNum;stuNum1++)
	   { 
		 File2>>stu[stuNum1].id>>stu[stuNum1].college>>stu[stuNum1].major>>stu[stuNum1].name>>stu[stuNum1].phone>>stu[stuNum1].password>>stu[stuNum1].email>>stu[stuNum1].course1>>stu[stuNum1].course2>>stu[stuNum1].course3;
	   }
	   File2.close();
	}
	else
	cout<<"�ļ���Ч\n";

}
 /*****************************************************************************************************************/
int  Student::stuRegisteration()                                                      //��¼����
{   
	 system("cls");
	cout<<"        ����������ѧ��:  ";
	cin>>studentID;
	int i=0;
	while(strcmp(studentID,stu[i].id)!=0)
	{
		i++;
		if(i>stuNum)
		{
	    	cout<<"        �����ѧ����Ч\n";
        	cout<<"        ���������� :";
            cin>>studentID;
        	i=0;
		}
	}
	cout<<"        ��������������:  ";
	cin>>studentPassword;
	while(strcmp(studentPassword,stu[i].password)!=0)
	{
	  cout<<"        ������Ч\n";
      cout<<"        �������������� :";
      cin>>studentPassword;
	}
	Sself_num=i;
	temp=stu[i];
	return Sself_num;
}
 /*****************************************************************************************************************/
void Student::showeAllCourses ()                          //��ʾ���еĿγ���Ϣ
{       
	Lesson::showalllesson();  
    cout<<"����������ѡ��\n";
    cout<<"---------------1.������Ի�ѡ��\n";
    cout<<"---------------2.����ѧ������ѡ�����\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>2)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����2��:";
	    cin>>choose;
    }     
    switch(choose)                            //switch���ѡ��ִ�й���
    {
    	case 1:
			ChooseCourse_stu();      //ѡ�κ���
			break;
		default: 
			cout<<endl<<"��������ѧ������ѡ�����"<<endl;
			system("pause");
			break;
	}
}
 /*****************************************************************************************************************/
void Student:: showMyCourses_stu()                       // ��ʾ�ҵ���ѡ�γ�
{
	cout<<"����Ϊ����ѡ�ν��: \nѧ     ��       �� ��       ��ѡ�γ�һ        ��ѡ�γ̶�          ��ѡ�γ���"<<endl;
    cout<<temp.id<<"      "<<temp.name<<"        "<<stu[Sself_num].course1<<"             "<<stu[Sself_num].course2<<"             "<<stu[Sself_num].course3<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    showlesson_title();
	for( int i=0;i<lessonNum;i++)
	{
	  if((strcmp(stu[Sself_num].course1,lesson[i].name)==0)||(strcmp(stu[Sself_num].course2,lesson[i].name)==0)||(strcmp(stu[Sself_num].course3,lesson[i].name)==0)) 
	  {	
		 Lesson::showlesson( i);
	  }
	}
}
 /*****************************************************************************************************************/
void Student::searchcourse_stu ()  //�γ���Ϣ����  
{

	int i,j,ii;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��ϵͳ�ṩ���ֲ�ѯ��ʽ��\n";
    cout<<"-------------1.�γ̱��\n";
    cout<<"-------------2.�γ�����\n";
    cout<<"-------------3.�ο���ʦ����\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>3)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����3��:";
	    cin>>choose;
    }     
    switch(choose)//switch���ѡ��ִ�й���
    {
    	case 1:
            system("cls");
		    cout<<"��������Ҫ���ҵĿγ̱�ţ�"<<endl;
			char ID[11];
			cin>>ID;
			cout<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"����Ϊ���Ŀγ̲�ѯ���: \n";
			Lesson::showlesson_title();
			for(i=0;i<lessonNum;i++)
			{
				if((strcmp(ID,lesson[i].id)==0))
				{
					Lesson::showlesson(i);
                    ii=1;
				}
			}
	        break;
		case 2:
            system("cls");	
			cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
		    cout<<"��������Ҫ���ҵĿγ����ƣ�"<<endl;
        	char Name[21];
			cin>>Name;
			cout<<endl;
			cout<<"����Ϊ���Ŀγ̲�ѯ���: \n";
			Lesson::showlesson_title();
			for(j=0;j<lessonNum;j++)
			{
				if((strcmp(Name,lesson[j].name)==0))
					Lesson::showlesson(j);
				    ii=1;
			}
			break;
		case 3:
            system("cls");
			cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
		    cout<<"��������Ҫ���ҵ��ο���ʦ������"<<endl;
        	char tName[21];
			cin>>tName;
			cout<<endl;
			cout<<"����Ϊ���Ŀγ̲�ѯ���: \n";
			Lesson::showlesson_title();
			for(j=0;j<lessonNum;j++)
			{
				if((strcmp(tName,lesson[j].name)==0))
					Lesson::showlesson(j);
				    ii=1;
			}
			break;
	}
	if(ii!=1)
	{   
		system("cls");                         //����  
	    cout<<"����ؿγ�"<<endl<<"��������ѧ������ѡ�����"<<endl;
	    system("pause");
	}
	else
	{
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"����������ѡ��\n";
    cout<<"---------------1.������Ի�ѡ��\n";
    cout<<"---------------2.����ѧ������ѡ�����\n";
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
		ChooseCourse_stu();
			break;
		case 2:
            allfunctionS(); 
			break;
	  }
	}

}
 /*****************************************************************************************************************/
void Student:: ChooseCourse_stu()    // i�� switch case
{  
	int i=0;
	int j=0;
	cout<<"��������Ҫѡ��Ŀγ�����: ";
	char Lname[81];
	cin>>Lname;
	if((strcmp(stu[Sself_num].course1,Lname)==0)||(strcmp(stu[Sself_num].course2,Lname)==0)||(strcmp(stu[Sself_num].course3,Lname)==0))  {	i=1;}
	else
	{
		for(;j<lessonNum;j++)
		{ 
			if(strcmp(Lname,lesson[j].name)==0)
			{   
				i=4;
				if(lesson[j].nownum==lesson[j].maxnum)
				i=3;
			}
			else if (j==lessonNum-1&&i!=4) {i=2;}
		}
	}
	switch(i)
	{
	case 1:
		cout<<"\n����ѡ��ÿγ̣�������ѡ��\n";
		break;
	case 2:
		cout<<"\n��δ������ؿγ̣�������ѡ��\n";
		break;
	case 3:
		cout<<"\n�ÿγ�ѡ������������������ѡ��\n";
		break;
	default:
	    break;
	}
	if(i==1||i==2||i==3)
	{
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"����������ѡ��\n";
        cout<<"-------------1.��������γ�����\n";
        cout<<"-------------2.ȡ��ѡ��        \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"��������Ӧ���ܵı�ţ�"; 
        int choose1;
	    cin>>choose1; 
        while(choose1<1||choose1>2)           //�ݴ�  �����������еĹ�������ʱѭ�� 
		{ 
			cout<<"�����������Ч�����������루1����2��:";
	        cin>>choose1;
		}     
		switch(choose1)                      //switch���ѡ��ִ�й���
		{
		case 1:
			ChooseCourse_stu();
		    break;
		case 2:
			break;
	  }
	}
	else 
	{
		if(strcmp(stu[Sself_num].course1,"NULL")==0)
		{
			strcpy(stu[Sself_num].course1,Lname);
		}
		else if(strcmp(stu[Sself_num].course2,"NULL")==0)
		{ 
			strcpy(stu[Sself_num].course2,Lname);
		}
		else if(strcmp(stu[Sself_num].course3,"NULL")==0)
		{
			strcpy(stu[Sself_num].course3,Lname);
		}
        w_stu_inf();
        r_stu_inf();
		for(int m=0;m<lessonNum;m++)
		{
			if(strcmp(Lname,lesson[m].name )==0)
            lesson[m].nownum ++;
		}
		Lesson::w_lessoninf() ;
		Lesson::w_lessoninf ();
		cout<<"ѡ�γɹ���\n";
		CreditVS4_stu();
	}
    system("pause");
}
 /*****************************************************************************************************************/
void Student::CancelChoose ()
{
	
    showMyCourses_stu();
	cout<<"��������Ҫ��ѡ�Ŀγ�����:    ";
	char Lname[81];
	cin>>Lname;
	if(strcmp(stu[Sself_num].course1,Lname)==0)
	{
		strcpy(stu[Sself_num].course1,"NULL");
	}
	else if(strcmp(stu[Sself_num].course2,Lname)==0)
	{ 
		strcpy(stu[Sself_num].course2,"NULL");
	}
	else if(strcmp(stu[Sself_num].course3,Lname)==0)
	{
		strcpy(stu[Sself_num].course3,"NULL");
	}
	w_stu_inf();
    r_stu_inf();
    for(int i=0;i<lessonNum;i++)
	{
	  if(strcmp(lesson[i].name,Lname)==0)
	  {
		lesson[i].nownum --;
	  }
	}
	Lesson::w_lessoninf() ;
	Lesson::w_lessoninf ();
	cout<<"�ѳɹ���ѡ�γ̣�\n";
	CreditVS4_stu();
    system("pause");
}
 /*****************************************************************************************************************/
void Student:: CreditVS4_stu()          // �жϸ�ͬѧ��ѡѧ��
{   
	int nowCredit=0;
	for(int j=0;j<lessonNum;j++)
	{
		if((strcmp(stu[Sself_num].course1,lesson[j].name)==0)||(strcmp(stu[Sself_num].course2,lesson[j].name)==0)||(strcmp(stu[Sself_num].course3,lesson[j].name)==0))
		{
			nowCredit=nowCredit+lesson[j].credit;
		}
	}
	cout<<"\n��ǰѡ��ѧ���Ѵ�  "<<nowCredit<<"  "<<endl;
	if(nowCredit>=4)
		CreditVS4=true;
	else
	{
		cout<<"\n����ѡ��ѧ�ֲ���4��δ�ﵽ��ѧҪ�������ѡ�Σ�\n";
	    system("pause");
		system("cls");  
		showeAllCourses();   
	}
}
/*****************************************************************************************************************/
void Student::master_inf ()             // ѧ��������Ϣ�޸�
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
			editpassword_stu();
			break;
		case 2:
			system("cls");	
			edittel_stu();
			break;
		case 3:
			system("cls");	
			editemail_stu();
			break;
		}
		w_stu_inf ();
	    r_stu_inf ();
		cout<<"ѧ����Ϣ�޸ĳɹ���";
		cout<<"�������ص�ѧ������ѡ�����\n"; 
        system("pause");
}
 /*****************************************************************************************************************/
void Student::editpassword_stu()
{
	cout<<"�����������룺  "<<endl;
	char password1[81];
    scanf("%s",password1);
    strcpy(stu[Sself_num].password,password1);

}
 /*****************************************************************************************************************/
void Student::edittel_stu()
{
	cout<<"�������µĵ绰���룺  "<<endl;
    char phone1[20];
	 scanf("%s",phone1);
    strcpy(stu[Sself_num].phone,phone1);
}
 /*****************************************************************************************************************/
void Student::editemail_stu()
{
	cout<<"�������µ����䣺  "<<endl;
	char email1[81];
	 scanf("%s",email1);
    strcpy(stu[Sself_num].email, email1);
}
 /*****************************************************************************************************************/

void Student::allfunctionS()               //ѧ��ϵͳ���ܽ���
{
	system("cls");                  
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------< ѧ �� ѡ �� ϵ ͳ >---------------------------------------------------------\n";
	cout<<"-----["<<setw(8)<<temp.id<<"   " <<setw(4)<<temp.name<<"]   ��ӭʹ��---------------------------------------------------------------------------------------\n"; 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------------1.�鿴���п���γ�   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------2.��ʾ�ҵ���ѡ�γ�   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------3.�γ���Ϣ����       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------4.���Ի�ѡ��         ---------------------------------------------------------\n";
	cout<<"--------------------------------------------5.���Ի���ѡ         ---------------------------------------------------------\n";
	cout<<"--------------------------------------------6.������Ϣ����       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------7.����Ȩ�޵�¼ϵͳ   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------8.�˳�ϵͳ           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"��������Ӧ���ܵı�ţ�"; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>8)           //�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	   cout<<"�����������Ч�����������루1����8��:";
	    cin>>choose;
    }     
    switch(choose)
    {
    	case 1:
            system("cls");
            showeAllCourses();   
            allfunctionS();
			break;
		case 2:
		    system("cls"); 
	        showMyCourses_stu();
			cout<<endl<<"��������ѧ������ѡ�����"<<endl;
			system("pause");
			allfunctionS();
			break;
	    case 3:
		    system("cls");
			searchcourse_stu();  
		    allfunctionS(); 
			break;
    	case 4:
	        system("cls");   
			showeAllCourses(); 
	        allfunctionS();     
	        break;
		case 5:		  
	        system("cls");      
	        CancelChoose();    
	        allfunctionS();    
	        break;
		case 6:
		    system("cls");
			master_inf ();
	        allfunctionS();
			break;
		case 7:
	        system("cls");  
			CreditVS4_stu();
			cout<<"�������ص�Ȩ�޵�¼����\n"; 
        	system("pause");
	        break;
		case 8:
	        system("cls"); 
			CreditVS4_stu();
         	Lesson::over();          
			break;
	}
}
