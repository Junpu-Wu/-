//��ͷ�ļ������ṹ��Ķ����뺯�����õ����� 
//��ѧ��ϵͳδ����ͼ�λ����� 
#pragma once//��ֹͷ�ļ��ظ����� 
typedef struct student
{
	int num;//ѧ��ѧ�� 
	char name[16];//ѧ������ 
	char sex[4];//ѧ���Ա� 
	char major[16];//ѧ��רҵ 
	int scoreA;//�ߵ���ѧ�ɼ�
	int scoreB;//������Ƴɼ�
	int scoreC;//Ӣ��ɼ�
	int scoreD;//˼����������ɼ�
	int score_sum;//�ܳɼ� 
	char postscript[50];//�ɼ�¼��״̬ 
	struct student *next;//����ڵ�ָ���� 
}STU;//ѧ����Ϣ�ṹ 


typedef struct administrator
{
	char username[32];
	char code[16];
	int stepcount;
}ADM;//����Ա�ṹ 


extern STU *insert_linkA(STU *head,STU tmp);//����ڵ㣬ͷ������ 
extern STU *insert_linkB(STU *head,STU tmp);//����ڵ㣬β������ 
extern STU *insert_linkC(STU *head,STU tmp);//�����Ĳ��뺯�� 
extern void stu_help(void);//ϵͳ�������� 
extern void search_name(STU *head); //���ձȶ���������ѧ����Ϣ��Ϣ 
extern void search_num(STU *head);//��ѯ 
extern STU *delete_link(STU *head);//ɾ���ڵ� 
extern STU *free_link(STU *head,int *n);//�ͷſռ� 
extern STU *alteration_link(STU *head);//�޸� 
extern void alter_major(char *major);//�޸�רҵ 
extern void alter_sex(char *sex);//�޸��Ա� 
extern void alter_name(char *name); //�޸����� 
extern int alter_num(int *num);//�޸�ѧ��
extern void alter_math(STU *p);//�޸ĸߵ���ѧ�ɼ�
extern void alter_programming(STU *p);//�޸ĳ�����Ƴɼ� 
extern void alter_English(STU *p);//�޸�Ӣ��ɼ�
extern void alter_Politition(STU *p);//�޸�˼�޳ɼ� 
extern ADM *Sys_Login(void);//��¼ 
extern ADM *File_adm_write(void);//��ȡ����Ա��Ϣ 
extern STU *readFile_stu(STU* head,int count);//��ȡѧ����Ϣ 
extern ADM *add_administrator(void);//д�����Ա��Ϣ
extern void File_memset(void);//����ļ�
extern STU *stu_link_made(STU *head,int count); //��������
extern STU *Trans_link_to_arr(STU *head,int count);//��ѧ����Ϣ����ת��Ϊ���� 
extern void writeFile_stu(STU *savehead,int count);//��ѧ����Ϣд���ļ�
extern void writeFile_adm(ADM *admpin);//������Ա��Ϣд���ļ� 
extern void print_msg(STU *head); //��ӡ���� 
extern void print_woman(STU *head);//��ӡ������Ϣ 
extern void print_man(STU *head);//��ӡŮ����Ϣ
extern void print_sex(STU *head);//�Ա�ѡ��
extern void print_major(STU *head);//����רҵ��ӡ
extern void adm_alter(ADM *admpin);//����Ա��Ϣ�޸� 
extern void username_alter(ADM *admpin);//����Ա�˺��޸� 
extern void code_alter(ADM *admpin); //����Ա�����޸� 
extern void soc_print(STU* head,int n);//��ӡѧ���ɼ� 
extern STU *soc_registration(STU *head);//��������ѧ���ɼ�
 
