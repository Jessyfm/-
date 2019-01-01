//#include "Lesson_inf.h"

class Teacher:public Lesson
{
public:
	Teacher();
	~Teacher();
    void allfunction();
    int teacherRegisteration();    //登录验证 
	void showedAllCourses();      //查看所有课程信息
	void showMyCourses_tea();         //查看自己所开设的课程
    void searchcourse();        //调用课程查找 
    void deletecourse();             //删除课程
	void editcourse();              // 课程信息编辑
	void modifycourse();              // 课程信息修改
    void addcourse();          //课程录入
	void saveinf();           //课程保存
	void master_inf();       //教师个人信息管理
	void editpassword();      //修改教师登录密码
	void edittel();            //修改教师手机号
	void editemail();            //修改教师邮箱
    void w_teacherinf();             //写txt文件
    void r_teacherinf();             //读txt文件
	friend class allclass;
	typedef struct 
	{
    char id[11];
	char college[21];
	char name[21];
	char phone[20];
	char password[81];
	char email[81];
}data2;
	data2 teacher[10];
    data2 temp;
private:	
	char teacherID[11];            //登录教师的工号
	char teacherPassword[81];      //登录老师的工号
	int Tself_num;            //其信息的位置
	int teacherNum;                  //老师信息总数
};                       