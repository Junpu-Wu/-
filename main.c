#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"link.h"
int main()
{
	//����һ���������ڱ��浱ǰѧ���ĸ��� 
	int count=0;
	//����һ������Ա�ṹ��ָ�룬���ڷ��ʹ���Ա����Ϣ
	ADM *admpin=NULL;
	//����½ʧ�ܣ����ָ�뱣��ĵ�ַΪ�գ�ֻ�������ù���Ա��Ϣ�����������������ȷ�󣬸�ָ����ܷ��ʹ���Ա�ṹ���б�������� 
	admpin=Sys_Login();
	if(admpin == NULL)//�����½ʧ�ܣ�ָ��Ϊ�� �����˳����� 
	{
		printf("ִ�г�����������û�ѡ���˳�\n"); 
		return 0;
	}
	count=admpin->stepcount;//����ѧ������ 
	//��¼�ɹ��ˣ���ӡ���ܲ˵� 
	stu_help(); //�˺�����ӡ��ϵͳ�˵� 
	STU *head=NULL;//����ѧ���ṹ���ָ�룬���ڶ�ȡ���Ķ����� 
	//��������ѧ���ļ��ж�ȡѧ����Ϣ 
	head=readFile_stu(head,count); 
	//��ӡ������Ϣ 
	printf("��ʼ��������...\n");
	//���ڱ������ļ��е�������������ķ�ʽ���棬�ֽ�ÿ������Ԫ��ת��Ϊ��������ķ�ʽ���ڴ���д洢 
	head=stu_link_made(head,count);
	//��ӡ������Ϣ 
	printf("��������ϣ�\n"); 
	while(1)
	{
		char cmd[32]="";
		printf("���������ָ�");
		scanf("%s",cmd);
		//ѡ���� 
		if(strcmp(cmd,"help") == 0) //��ӡ�˵� 
		{
			stu_help(); 
		}
		//����һ��ѧ������Ϣ����ϵͳ���������ַ�ʽȥ����һ��ѧ������Ϣ 
		else if(strcmp(cmd,"insert") == 0) 
		{
			 printf("-------insert------\n");
			 while(1)
			 {
			 	STU tmp;//����һ����ʱ�ṹ�� 
			 	printf("������ѧ��ѧ�ţ�");
			 	scanf("%d",&tmp.num);
				printf("������ѧ��������");
				scanf("%s",tmp.name);
				printf("������ѧ�����Ա�");
				scanf("%s",tmp.sex);
				printf("������ѧ����רҵ��");
			 	scanf("%s",&tmp.major); 
			 	tmp.scoreA=-1;//��ʼ���ɼ� 
			 	tmp.scoreB=-1;
				tmp.scoreC=-1;
				tmp.scoreD=-1;
			 	tmp.score_sum=-1; 
			 	//insert_linkC�ǰ���ѧ���������ѧ����Ϣ 
			 	head=insert_linkC(head,tmp);
			 	printf("��ѧ����Ϣ¼����ɣ�\n");
				count++;//����һ��ѧ����Ϣ��ѧ���ĸ�����һ
				printf("�Ƿ�������ѧ����Ϣ����������ѡ��ǰ����ţ�\n");
				printf("1.��\n");
				printf("2.��\n");
				int temp1=0;
				scanf("%d",&temp1);
				if(temp1==2)
				{
					printf("��ֹͣ¼�룡\n");
					break;
				}
			  } 
		}
		//����ѧ����Ϣ 
		else if(strcmp(cmd,"search") == 0)
		{
			 printf("-------search------\n");//����Ĳ�ѯ 
			 printf("��ϣ��ͨ��ʲô���ķ�ʽ���в�ѯ��(������ѡ��ǰ�����֣�\n");
			 printf("1.ͨ��ѧ��\n");
			 printf("2.ͨ������\n");
			 int example=0;
			 scanf("%d",&example);//ͨ�������ѡ����ҷ�ʽ 
			 switch(example)
			 {
			 	case 1:search_num(head);break;//����ѧ�Ų��� 
				case 2:search_name(head);break;//������������ 
				default:printf("������ź�����\n");break;//�û�������źŲ�������ӡ������Ϣ 
			 } 
		}
		//ɾ��ѧ����Ϣ 
		else if(strcmp(cmd,"delete") == 0)//�����ɾ�� 
		{
			 printf("-------delete------\n");
			 head=delete_link(head);
			 count--;//ɾ��һ��ѧ������Ϣ��ѧ���ĸ�����һ 
		}
		//�ͷ���������Ŀռ䣨��գ� 
		else if(strcmp(cmd,"free") == 0)//����������ͷ� 
		{
			 printf("-------free------\n");
			 head=free_link(head,&count);
			 //�ͷ���������������ѧ���ĸ��� 
			 count=0;
			 continue;
		}
		//�˳�����
		//ע�⣺�˳����򽫷������������
		//��һ����ѧ������Ϣ����ת��Ϊ�������ʽ�洢
		//�ڶ�����ѧ������Ϣ����д������ļ�
		//������������Ա����Ϣд������ļ� 
		else if(strcmp(cmd,"quit") == 0)
		{ 
			admpin->stepcount=count;//����ѧ������ 
			STU *savehead=NULL;
			printf("----------���ڱ���ѧ������Ϣ...\n");
			//��һ������ѧ����Ϣ������ṹת��Ϊ����ṹ 
			savehead=Trans_link_to_arr(head,count);
			//�ڶ������ṹ������д���ļ� 
			writeFile_stu(savehead,count);
			//��ӡ������Ϣ 
			printf("----------ѧ������Ϣ�������!----------\n");
			printf("���ڱ������Ա����Ϣ...\n");
			//������Ա����Ϣд���ļ� 
			writeFile_adm(admpin);
			//��ӡ������Ϣ 
			printf("----------����Ա����Ϣ�������!---------\n");
			printf("---------------------��л��ʹ�ñ�ϵͳ!---------------------\n");
			int aad=0;
			printf("----------�Ƿ��˳���----------\n");
			printf("--1.��\n");
			printf("--2.��\n");
			scanf("%d",&aad);
			if(aad == 1)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		else if(strcmp(cmd,"print") == 0)//��ӡ���� 
		{
			 printf("-------print------\n");
			 print_msg(head);
			 continue; 
		}
		else if(strcmp(cmd,"alteration") == 0)//�޸�ѧ����Ϣ���� 
		{
			printf("-------alteration------\n");
			int n1=0;
			head=alteration_link(head);
			continue;
		}
		else if(strcmp(cmd,"adm_alteration") == 0)//�޸Ĺ���Ա��Ϣ���� 
		{
			adm_alter(admpin);
			continue;
		}
		else if(strcmp(cmd,"soc_print") == 0)//��ӡѧ���ɼ� 
		{
			soc_print(head,count);
			continue;
		}
		else if(strcmp(cmd,"register") == 0)
		{
			soc_registration( head );
			continue;
		}
		
	}	
	return 0;
} 
