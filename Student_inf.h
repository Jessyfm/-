class Student:public Lesson
{
public:
	Student();
	~Student();
    void w_stu_inf();
	void r_stu_inf();
	int stuRegisteration();   //登录函数
	void allfunctionS();       //学生系统功能   界面
	void showeAllCourses();       //显示所有开设的课程信息
   	void showMyCourses_stu();         // 显示我的已选课程
	void searchcourse_stu();        //调用课程查找 
    void ChooseCourse_stu();      //选课函数
	void CancelChoose();           //退课函数
	void master_inf();       //学生个人信息管理
	void editpassword_stu();
    void edittel_stu();
	void editemail_stu();
	void CreditVS4_stu();          // 判断该同学已选学分
	friend class allclass;
	typedef struct                      //学生信息结构体数组
	{
    char id[20];
	char college[41];
	char major[81];
	char name[21];
	char phone[12];
	char password[81];
	char email[81];
	char course1[81];
	char course2[81];
	char course3[81]; 
}data3;
	data3 stu[20];
	data3 temp;
private:
   	char studentID[20];            //登录学生的工号
	char studentPassword[81];      //登录学生的工号
	int Sself_num;                 //该学生信息的位置
	int stuNum;                  //学生信息总数	
	bool CreditVS4;              //该变量为真时，该学生已选学分大于4;
};
