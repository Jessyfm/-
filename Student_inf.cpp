#include <fstream> 
#include<iostream>  
#include<stdio.h>                 //C语言标准输入输出头文件
#include<stdlib.h>                //文件操作需要用到的头文件
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Student_inf.h"
using namespace std; 

Student::Student()
{
  r_stu_inf();
  CreditVS4=false;     //默认选修学分不足4，退出或选课退课时会再次更新
}
/*****************************************************************************************************************/
Student::~Student()
{
	delete []stu;
}
 /*****************************************************************************************************************/
void Student::w_stu_inf ()                                             //写文件
{
		fstream File2;
		File2.open("学生信息.txt",ios_base::out);
        File2<<stuNum<<endl;
		for(int stuNum1=0;stuNum1<stuNum;stuNum1++)
		{ 
	   	 File2<<stu[stuNum1].id<<"   "<<stu[stuNum1].college<<"   "<<stu[stuNum1].major<<"   "<<stu[stuNum1].name<<"   "<<stu[stuNum1].phone
			  <<"   "<<stu[stuNum1].password<<"   "<<stu[stuNum1].email<<"   "<<stu[stuNum1].course1<<"   "<<stu[stuNum1].course2<<"   "<<stu[stuNum1].course3<<endl;;		
	   }
	       File2.close();
}
 /*****************************************************************************************************************/
void Student::r_stu_inf ()                                      //读文件
{
     ifstream File2;
	 File2.open("学生信息.txt",ios_base::in | ios_base::binary);
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
	cout<<"文件无效\n";

}
 /*****************************************************************************************************************/
int  Student::stuRegisteration()                                                      //登录函数
{   
	 system("cls");
	cout<<"        请输入您的学号:  ";
	cin>>studentID;
	int i=0;
	while(strcmp(studentID,stu[i].id)!=0)
	{
		i++;
		if(i>stuNum)
		{
	    	cout<<"        输入的学号无效\n";
        	cout<<"        请重新输入 :";
            cin>>studentID;
        	i=0;
		}
	}
	cout<<"        请输入您的密码:  ";
	cin>>studentPassword;
	while(strcmp(studentPassword,stu[i].password)!=0)
	{
	  cout<<"        密码无效\n";
      cout<<"        请重新输入密码 :";
      cin>>studentPassword;
	}
	Sself_num=i;
	temp=stu[i];
	return Sself_num;
}
 /*****************************************************************************************************************/
void Student::showeAllCourses ()                          //显示所有的课程信息
{       
	Lesson::showalllesson();  
    cout<<"接下来您可选择：\n";
    cout<<"---------------1.进入个性化选课\n";
    cout<<"---------------2.返回学生功能选择界面\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>2)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——2）:";
	    cin>>choose;
    }     
    switch(choose)                            //switch语句选择执行功能
    {
    	case 1:
			ChooseCourse_stu();      //选课函数
			break;
		default: 
			cout<<endl<<"即将返回学生功能选择界面"<<endl;
			system("pause");
			break;
	}
}
 /*****************************************************************************************************************/
void Student:: showMyCourses_stu()                       // 显示我的已选课程
{
	cout<<"以下为您的选课结果: \n学     号       姓 名       已选课程一        已选课程二          已选课程三"<<endl;
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
void Student::searchcourse_stu ()  //课程信息查找  
{

	int i,j,ii;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"本系统提供三种查询方式：\n";
    cout<<"-------------1.课程编号\n";
    cout<<"-------------2.课程名称\n";
    cout<<"-------------3.任课老师姓名\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>3)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——3）:";
	    cin>>choose;
    }     
    switch(choose)//switch语句选择执行功能
    {
    	case 1:
            system("cls");
		    cout<<"请输入需要查找的课程编号："<<endl;
			char ID[11];
			cin>>ID;
			cout<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"以下为您的课程查询结果: \n";
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
		    cout<<"请输入需要查找的课程名称："<<endl;
        	char Name[21];
			cin>>Name;
			cout<<endl;
			cout<<"以下为您的课程查询结果: \n";
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
		    cout<<"请输入需要查找的任课老师姓名："<<endl;
        	char tName[21];
			cin>>tName;
			cout<<endl;
			cout<<"以下为您的课程查询结果: \n";
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
		system("cls");                         //清屏  
	    cout<<"无相关课程"<<endl<<"即将返回学生功能选择界面"<<endl;
	    system("pause");
	}
	else
	{
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"接下来您可选择：\n";
    cout<<"---------------1.进入个性化选课\n";
    cout<<"---------------2.返回学生功能选择界面\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
      int choose1;
	  cin>>choose1; 
      while(choose1<1||choose1>2)           //容错  不在以上所列的功能以内时循环 
	  { 
	    cout<<"输入的数字无效，请重新输入（1——2）:";
	    cin>>choose1;
	  }     
	  switch(choose1)//switch语句选择执行功能
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
void Student:: ChooseCourse_stu()    // i用 switch case
{  
	int i=0;
	int j=0;
	cout<<"请输入你要选择的课程名称: ";
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
		cout<<"\n您已选择该课程，请重新选择！\n";
		break;
	case 2:
		cout<<"\n暂未开设相关课程，请重新选择！\n";
		break;
	case 3:
		cout<<"\n该课程选课人数已满，请重新选择！\n";
		break;
	default:
	    break;
	}
	if(i==1||i==2||i==3)
	{
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"接下来您可选择：\n";
        cout<<"-------------1.重新输入课程名称\n";
        cout<<"-------------2.取消选课        \n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"请输入相应功能的编号："; 
        int choose1;
	    cin>>choose1; 
        while(choose1<1||choose1>2)           //容错  不在以上所列的功能以内时循环 
		{ 
			cout<<"输入的数字无效，请重新输入（1——2）:";
	        cin>>choose1;
		}     
		switch(choose1)                      //switch语句选择执行功能
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
		cout<<"选课成功！\n";
		CreditVS4_stu();
	}
    system("pause");
}
 /*****************************************************************************************************************/
void Student::CancelChoose ()
{
	
    showMyCourses_stu();
	cout<<"请输入你要退选的课程名称:    ";
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
	cout<<"已成功退选课程！\n";
	CreditVS4_stu();
    system("pause");
}
 /*****************************************************************************************************************/
void Student:: CreditVS4_stu()          // 判断该同学已选学分
{   
	int nowCredit=0;
	for(int j=0;j<lessonNum;j++)
	{
		if((strcmp(stu[Sself_num].course1,lesson[j].name)==0)||(strcmp(stu[Sself_num].course2,lesson[j].name)==0)||(strcmp(stu[Sself_num].course3,lesson[j].name)==0))
		{
			nowCredit=nowCredit+lesson[j].credit;
		}
	}
	cout<<"\n当前选课学分已达  "<<nowCredit<<"  "<<endl;
	if(nowCredit>=4)
		CreditVS4=true;
	else
	{
		cout<<"\n您的选修学分不足4，未达到教学要求，请进行选课！\n";
	    system("pause");
		system("cls");  
		showeAllCourses();   
	}
}
/*****************************************************************************************************************/
void Student::master_inf ()             // 学生个人信息修改
{
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"您可选择修改个人信息： \n";
    cout<<"-------------[ 1.修改密码   ] \n";
    cout<<"-------------[ 2.更换手机号 ]\n";
    cout<<"-------------[ 3.更改邮箱   ]\n";	
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>3)                 //不在以上所列的功能以内时循环
		{ 
			cout<<"输入的数字无效，请重新输入（1——3）:";
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
		cout<<"学生信息修改成功！";
		cout<<"即将返回到学生功能选择界面\n"; 
        system("pause");
}
 /*****************************************************************************************************************/
void Student::editpassword_stu()
{
	cout<<"请输入新密码：  "<<endl;
	char password1[81];
    scanf("%s",password1);
    strcpy(stu[Sself_num].password,password1);

}
 /*****************************************************************************************************************/
void Student::edittel_stu()
{
	cout<<"请输入新的电话号码：  "<<endl;
    char phone1[20];
	 scanf("%s",phone1);
    strcpy(stu[Sself_num].phone,phone1);
}
 /*****************************************************************************************************************/
void Student::editemail_stu()
{
	cout<<"请输入新的邮箱：  "<<endl;
	char email1[81];
	 scanf("%s",email1);
    strcpy(stu[Sself_num].email, email1);
}
 /*****************************************************************************************************************/

void Student::allfunctionS()               //学生系统功能界面
{
	system("cls");                  
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------< 学 生 选 课 系 统 >---------------------------------------------------------\n";
	cout<<"-----["<<setw(8)<<temp.id<<"   " <<setw(4)<<temp.name<<"]   欢迎使用---------------------------------------------------------------------------------------\n"; 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------------1.查看所有开设课程   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------2.显示我的已选课程   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------3.课程信息查找       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------4.个性化选课         ---------------------------------------------------------\n";
	cout<<"--------------------------------------------5.个性化退选         ---------------------------------------------------------\n";
	cout<<"--------------------------------------------6.个人信息管理       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------7.返回权限登录系统   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------8.退出系统           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>8)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——8）:";
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
			cout<<endl<<"即将返回学生功能选择界面"<<endl;
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
			cout<<"即将返回到权限登录界面\n"; 
        	system("pause");
	        break;
		case 8:
	        system("cls"); 
			CreditVS4_stu();
         	Lesson::over();          
			break;
	}
}
