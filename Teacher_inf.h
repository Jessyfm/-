//#include "Lesson_inf.h"

class Teacher:public Lesson
{
public:
	Teacher();
	~Teacher();
    void allfunction();
    int teacherRegisteration();    //��¼��֤ 
	void showedAllCourses();      //�鿴���пγ���Ϣ
	void showMyCourses_tea();         //�鿴�Լ�������Ŀγ�
    void searchcourse();        //���ÿγ̲��� 
    void deletecourse();             //ɾ���γ�
	void editcourse();              // �γ���Ϣ�༭
	void modifycourse();              // �γ���Ϣ�޸�
    void addcourse();          //�γ�¼��
	void saveinf();           //�γ̱���
	void master_inf();       //��ʦ������Ϣ����
	void editpassword();      //�޸Ľ�ʦ��¼����
	void edittel();            //�޸Ľ�ʦ�ֻ���
	void editemail();            //�޸Ľ�ʦ����
    void w_teacherinf();             //дtxt�ļ�
    void r_teacherinf();             //��txt�ļ�
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
	char teacherID[11];            //��¼��ʦ�Ĺ���
	char teacherPassword[81];      //��¼��ʦ�Ĺ���
	int Tself_num;            //����Ϣ��λ��
	int teacherNum;                  //��ʦ��Ϣ����
};                       