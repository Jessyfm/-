class Student:public Lesson
{
public:
	Student();
	~Student();
    void w_stu_inf();
	void r_stu_inf();
	int stuRegisteration();   //��¼����
	void allfunctionS();       //ѧ��ϵͳ����   ����
	void showeAllCourses();       //��ʾ���п���Ŀγ���Ϣ
   	void showMyCourses_stu();         // ��ʾ�ҵ���ѡ�γ�
	void searchcourse_stu();        //���ÿγ̲��� 
    void ChooseCourse_stu();      //ѡ�κ���
	void CancelChoose();           //�˿κ���
	void master_inf();       //ѧ��������Ϣ����
	void editpassword_stu();
    void edittel_stu();
	void editemail_stu();
	void CreditVS4_stu();          // �жϸ�ͬѧ��ѡѧ��
	friend class allclass;
	typedef struct                      //ѧ����Ϣ�ṹ������
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
   	char studentID[20];            //��¼ѧ���Ĺ���
	char studentPassword[81];      //��¼ѧ���Ĺ���
	int Sself_num;                 //��ѧ����Ϣ��λ��
	int stuNum;                  //ѧ����Ϣ����	
	bool CreditVS4;              //�ñ���Ϊ��ʱ����ѧ����ѡѧ�ִ���4;
};
