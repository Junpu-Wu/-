#include"link.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�����ͷ������ 
STU *insert_linkA(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));
	if(pi == NULL)//�˿��ӡ��̬������� 
	{
		perror("calloc");
		return head;
	}
	*pi = tmp;
	if(head != NULL) pi->next=head;
	else pi->next = NULL;
	head=pi;//��������֮ǰ��������
	return head;
}


//�����β������
STU *insert_linkB(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));
	if(pi == NULL)//�˿��ӡ��̬������� 
	{
		perror("calloc");
		return head;
	}
	*pi=tmp;
	pi->next = NULL;
	if(head == NULL) head=pi;
	else
	{
		STU *p3=head;
		while(p3->next != NULL) p3=p3->next;
		p3->next=pi;
	}
	return head;
}



//������������ ������ѧ�ţ� 
 STU *insert_linkC(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));//��̬���� 
	if(pi == NULL)//�˿��ӡ��̬������� 
	{
		perror("calloc");
		//��ӡ���� 
		return head;
	}
	*pi=tmp;
	STU *pb=head;
	STU *pf=head;
	if(head == NULL)//���һ���ԭ�������޽ڵ� 
	{
	pi->next=NULL;
	return pi;
	}
	else 
	{
		STU *checkp=head;
		while(checkp!=NULL)//���ѧ���Ƿ�ע�� 
		{
			if(checkp->num==pi->num)
			{
				printf("Invalid Input\n");
				printf("�����ѧ���ѱ�ע��\n");
				free(pi);
				return head;
			}
			checkp=checkp->next; 
		} 
		
		while(pb->num < pi->num&&pb->next!=NULL)
		{
			pf=pb;
			pb=pb->next;
		}
		if(pf == head&&pf->num > pi->num)//�½ڵ�������ͷ��λ�ã� 
		{
			pi->next=head;
			head=pi;
		}//����Ϊֹ��Ѱ���½ڵ����λ�ý��� 
		else if(pb->num > pi->num) //�½ڵ���ԭ�ڵ�֮�� 
		{
			pf->next=pi;
			pi->next=pb;
		}
		else//�½ڵ㽫���뵽�����β�� 
		{
			pb->next=pi;
			pi->next=NULL;
		}
	}

	return head;
}


//ѧ��ϵͳ������Ϣ���˵�Ŀ¼ 
void stu_help(void)
{
	printf("--------------------ע��:���룣�ͣ�֮���Ӣ��ָ����ʵ�ֹ��ܣ�--------------------\n"); 
	printf("--------------------������������һ��ѧ������Ϣ�����롰insert��-------------------\n");
	printf("#########################################\n");
	printf("#help:��ӡ�����˵���Ҳ���Ǹò˵���      #\n");
	printf("#insert������һ��ѧ������Ϣ             #\n");
	printf("#print�������ӡѧ������Ϣ              #\n");
	printf("#search����ѯһ��ѧ������Ϣ             #\n");
	printf("#deleteɾ��һ��ѧ������Ϣ               #\n");
	printf("#free��ɾ������ѧ������Ϣ               #\n");
	printf("#quit���˳�����                         #\n");
	printf("#alteration���޸�һ��ѧ������Ϣ         #\n");
	printf("#adm_alteration:�޸Ĺ���Ա����Ϣ        #\n");
	printf("#register:�����Ǽ�ѧ���ĳɼ�            #\n");
	printf("#soc_print:�����ӡѧ���ĳɼ�           #\n");
	printf("#########################################\n");
}



//����������ѯ 
void search_name(STU *head)//����ѧ��������ѯ 
{
	printf("��������ϣ����ѯ������:"); 
	char exm[32]="";
	scanf("%s",exm);
	STU *pb=head;
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!!!\n");
	else 
	{
	printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
	printf("ѧ��������%*s",5,pb->name);printf(" ");
	printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
	printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
	printf("��ѧ���ɼ����£�\n");
	printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
	printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
	printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
	printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
	printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
	}
}


//����ѧ�Ų�ѯ 
void search_num(STU *head)
{
	printf("��������ϣ����ѯ��ѧ��ѧ�ţ�");
	int example1=0;
	STU *pb=head;
	scanf("%d",&example1);
	while(pb != NULL)
	{
		if(example1 == pb->num) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!\n");
	else 
	{
	printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
	printf("ѧ��������%*s",5,pb->name);printf(" ");
	printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
	printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
	printf("��ѧ���ɼ����£�\n");
	printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
	printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
	printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
	printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
	printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
	}
}



//����ڵ��ɾ������ 
//�˲���Ӧע�⣬ÿִ��һ��ɾ��Ҫˢ���׵�ַ
STU *delete_link(STU *head)
{
	char exm[32]="";
	printf("��������Ҫ��ɾ�������֣�"); 
	scanf("%s",exm); 
	if(head == NULL)//���׵�ַΪ�� 
	{
		printf("NO DATA FOUND!!!\n");
		return head;
	}
	STU *pb=head;//����һ��ָ�����ɨ������ 
	STU *pf=head;//����һ��ָ�������������Է����ַ�޸Ĳ��� 
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pf=pb; 
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!!!\n");
	else if(pb == head)//ע�⣺��Ҫɾ��ͷ�ڵ㣬Ӧ�ø����׵�ַ 
	{
		head=pb->next;
		free(pb);//�ͷŸýڵ�ռ� 
	}
	else//�в�ɾ��������β��ɾ�� 
	{
		pf->next=pb->next;
		free(pb);//�ͷŸýڵ�ռ� 
	}
	return head; 
}



//����������ͷź��� 
STU *free_link(STU *head,int *n)
{
	printf("------------ȷ��Ҫɾ������ѧ������Ϣ��------------\n");
	printf("1.��ȷ��\n");
	printf("2.����\n");
	int choice=0;
	while(1)
	{
		int test=0;
		test=scanf("%d",&choice);
		if(test==0)
		{
			printf("------------����������������룡-----------\n");
			continue; 
		}
		else break;
	}
	if(choice==1)
	{
		head=NULL;
		*n=0;
		printf("-----------��ɾ�����е����ݣ�----------\n"); 
		return head;
	}
	if(choice==2)
	{
		printf("-----------��ȡ����������----------\n");
		return head;
	}
}



//�������ݵ��޸�
STU *alteration_link(STU *head)
{
	if(head == NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return head;
	}
	printf("-----��������ϣ�����޸���Ϣ������:"); 
	char exm[32]="";
	scanf("%s",exm);
	STU *pb=head;
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("---------------NO DATA FOUND!!!-----------------\n");
	else
	{
		printf("-------------��ϣ���޸ĸ�ѧ������һ����Ϣ��--------------\n");
		printf("1.�޸�ѧ��\n");
		printf("2.�޸�����\n");
		printf("3.�޸��Ա�\n");
		printf("4.�޸�רҵ\n");
		printf("5.�޸ĸߵ���ѧ�ɼ�\n");
		printf("6.�޸ĳ�����Ƶĳɼ�\n");
		printf("7.�޸�Ӣ��ɼ�\n");
		printf("8.�޸�˼����������뷨�ɻ����ĳɼ�\n"); 
		int n2=0;
		scanf("%d",&n2);
		switch(n2)
		
		{
		case 1: pb->num=alter_num(&pb->num);break;
		case 2: alter_name(pb->name);break;
		case 3: alter_sex(pb->sex);break;
		case 4: alter_major(pb->major);break;
		case 5: alter_math(pb);break;//�޸ĸ����ɼ� 
		case 6: alter_programming(pb);break;//�޸ĳ�����Ƴɼ� 
		case 7: alter_English(pb);break;//�޸�Ӣ��ɼ� 
		case 8: alter_Politition(pb);break;//�޸�˼�޳ɼ� 
		default:printf("������Ϣ����\n");break;
		}
		
	}
	return head;
} 



//����������޸�֮ѧ���޸�
 int alter_num(int *num)
 {
 	printf("--����������µ�ѧ��\n");
 	scanf("%d",num);
 	return *num;
 }
 
 
 
 //����������޸�֮�����޸�
 void alter_name(char *name) 
 {
 	printf("--����������µ�������\n");
 	scanf("%s",name);
 	return;
 }
 
 
 
 //����������޸�֮�Ա��޸�
 void alter_sex(char *sex)
 {
 	printf("----����������µ��Ա�\n");
 	scanf("%s",sex);
 	return;
 }
 
 //����������޸�֮�����ɼ����޸�
 void alter_math(STU *p)
 {
 	printf("---�������µĳɼ�\n");
	scanf("%d",&p->scoreA);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("-------------------�ɼ��޸����!-------------------\n"); 
	return; 
 }
 
 //����������޸�֮�ɼ����޸�
void alter_programming(STU *p)
 {
 	printf("�������µĳɼ�\n");
	scanf("%d",&p->scoreB);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("�ɼ��޸����\n"); 
	return; 
 }
  
//����������޸�֮�ɼ����޸�
   void alter_English(STU *p)
   {
	printf("�������µĳɼ�\n");
	scanf("%d",&p->scoreC);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("�ɼ��޸����\n"); 
	return;
	} 
//����������޸�֮�ɼ����޸�
  void alter_Politition(STU *p)
  {
  	printf("�������µĳɼ�\n");
	scanf("%d",&p->scoreD);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("�ɼ��޸����\n"); 
	return;
  }
 //����������޸�֮רҵ�޸�
void alter_major(char *major)
{
	printf("����������µ�רҵ��\n");
 	scanf("%s",major);
 	return;
}



//��¼ 
ADM *Sys_Login(void)
{
	ADM *sample=NULL;
	sample=File_adm_write();
	if(sample==NULL)
	{
		printf("�ļ���ȡ�������û��ѧ�����ݣ�\n");
		printf("��ע�����˺ţ�\n"); 
	}
	else printf("�Ѵ��ļ���ȡ���ݣ�\n"); 
	printf("����������Ҫ�Ĳ�����\n");
	printf("1.��¼(���û���ѡ��ڶ��������ܵ���ϵͳ����)\n");
	printf("2.�����µĹ����˻���ע�⣺�˲�������ɾ����ǰ���е��������ݣ�\n");
	printf("3.�˳�����\n");
	int choice=0;
	int test=0;
	while(1)
	{
	test=scanf("%d",&choice);
	if(test==0)
	{
		printf("�������\n");
		continue;
	}
	else break;
	}
	if(choice==1)
	{
		int count3=0; 
		while(1)
		{
		char usernameA[32];//�����˻� 
		char codeA[16];//�������� 
		printf("����������˻���\n");
		scanf("%s",usernameA);
		printf("������������룺\n");
		scanf("%s",codeA);
		int cmp1=99;//���ڷ���strcmp��ֵ 
		int cmp2=99;
		cmp1=strncmp(usernameA,sample->username,strlen(sample->username));
		cmp2=strncmp(codeA,sample->code,strlen(sample->code));
		if(cmp1==0&&cmp2==0) return sample;//��¼�ɹ� 
		else
		{
			count3++;
			if(count3==3)
			{
				printf("���������������\n");
				printf("Ϊ����ϵͳ�ļ���ԭ�е����ݽ�ɾ����\n");
				printf("�Ƿ񴴽����˻���\n");
				printf("1.��\n");
				printf("2.����Ҫ�˳�����\n");
				int choice3=0;
				while(1)
				{
					test=scanf("%d",&choice3);
					if(test==0)
					{
						printf("�������\n");
						continue;
					}
					else break;
				}
				if(choice3==1)
				{
					File_memset();
					sample=add_administrator();
					return sample;
				}
				if(choice3==2)
				{
					File_memset();
					return NULL;
				}
			}
			printf("������˻��������������\n");
			printf("��ѡ�񣺣�����ѡ��ǰ����ţ�\n");
			printf("1.���������˻�������\n");
			printf("2.�˳�����\n");
			int temp3=0;
			while(1)
			{
				test=scanf("%d",&temp3);
				if(test==0)
				{
					printf("�������\n");
					continue;
				}
				else break;
			}
			if(temp3==2) return NULL;
			else continue;
		}
		}
	}
	else if(choice==2) 
	{
		File_memset();
		sample=add_administrator();
		return sample;
	}
	else
	{
		return NULL;
	}
}



//����Ա��Ϣ��ȡ���� 
ADM *File_adm_write(void)
{
	FILE *fp=NULL;
	ADM *pin=NULL;
	pin=(ADM *)malloc(sizeof(ADM));
	fp=fopen("administrator.txt","r");
	if(fp == NULL)
	{
		perror("fopen");
		printf("�ļ���ʱ����\n");
		return NULL;
	}
	int testnum=0;
	testnum=fread(pin,sizeof(ADM),1,fp);
	fclose(fp); 
	if(testnum != 1)
	{
		printf("��ȡ�ļ�ʱ����\n");
		return NULL; 
	}
	return pin;
}



//ѧ����Ϣ��ȡ����
STU *readFile_stu(STU* head,int count)
{
	if(count == 0) return NULL;
	else
	{
		FILE *fp=NULL;
		fp=fopen("student.txt","r");
		int testnum = 0;
		if(fp == NULL)
		{
			perror("fopen");
			return NULL;
		}
		STU *tmp=NULL;
		tmp=(STU *)calloc(count,sizeof(STU));
		testnum=fread(tmp,sizeof(STU),count,fp);
		fclose(fp);
		if(testnum != count) 
		{
			printf("������Ϣ����\n");
			return NULL;
		}else if(testnum == 0) return NULL;
		else return tmp;
	}
} 




//��������Ա��Ϣ
ADM *add_administrator(void)
{
	ADM *newuser=NULL;
	newuser=(ADM *)malloc(sizeof(ADM));
	printf("�������˻���\n");
	scanf("%s",newuser->username);
	printf("��������������\n");
	scanf("%s",newuser->code);
	newuser->stepcount=0;
	printf("������ϣ��ù���Ա��Ϣ����ϵͳ�Ϸ��˳��󱣴档\n");
	return newuser;
}



//����ļ� 
void File_memset(void)
{
	FILE *fp1=NULL;
	 if((fp1=fopen("student.txt","w"))==NULL)  
    {    
	    perror("fopen");
        return;
    }
    FILE *fp2=NULL;
	if((fp2=fopen("administrator.txt","w"))==NULL)  
    {    
	    perror("fopen");
        return;
    }
    fputs("0",fp2);
    fputs("0",fp1);
    fclose(fp1);
    fclose(fp2);
    return;
}



//��������
STU *stu_link_made(STU *head,int count)
{
	int i=1;
	STU *pb=head;
	STU *pf=head;
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		while(i<count)
		{
			pb++;
			pf->next=pb;
			pf++;
			i++;
		}
		pb->next=NULL;
	}
	return head;
} 



//ѧ����Ϣ����ת���� 
STU *Trans_link_to_arr(STU *head,int count)
{
	int i=0;
	STU *pb=head;
	STU *temp;
	temp=(STU *)calloc(count,sizeof(STU));
	for(i=0;pb!=NULL;i++)
	{
		*(temp+i)=*pb;
		pb=pb->next;
	}
	return temp;
}



//��ѧ����Ϣд���ļ� 
void writeFile_stu(STU *savehead,int count)
{
	FILE *fp=NULL;
	int testnum=0;
	fp=fopen("student.txt","w");
	if(fp==NULL)
	{
		perror("fopen");
		return;
	}
	testnum=fwrite(savehead,sizeof(STU),count,fp);printf("�ѱ���%d��ѧ������Ϣ\n",testnum);
	fclose(fp);
	return;
}



//������Ա��Ϣд���ļ�
void writeFile_adm(ADM *admpin)
{
	FILE *fp=NULL;
	int testnum=0;
	fp=fopen("administrator.txt","w");
	if(fp == NULL)
	{
		perror("fopen");
		return;	
	}
	testnum=fwrite(admpin,sizeof(ADM),1,fp);
	printf("�ѱ���%d������Ա����Ϣ\n",testnum);
	fclose(fp);
	return;
} 



//���յ�ǰ˳�����ѧ��
void print_order(STU *head)
{
	STU *pb=head;
	if(pb == NULL)
	{
		printf("NO DATA FOND!!!\n");
		return;
	}
	else
	{
		while(pb != NULL)
		{
			printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
			printf("ѧ��������%*s",5,pb->name);printf(" ");
			printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
			printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
			printf("��ѧ���ɼ����£�\n");
			printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
			printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
			printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
			printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
			printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
			pb=pb->next;
		}
	}
	return;
}



//�����Ա�ѡ��
void print_sex(STU *head)
{
	printf("��ѡ����Ҫ��ȡ���Ա�\n");
	printf("1.��\n");
	printf("2.Ů\n");
	int choice_sex = 0;
	scanf("%d",&choice_sex);
	switch(choice_sex)
	{
		case 1:print_man(head);break;
		case 2:print_woman(head);break;
		default:print_sex(head);break;
	}
	return;
}



//��ӡ���Ե���Ϣ
void print_man(STU *head)
{
	STU *pb=head;
	if(pb == NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb != NULL)
		{
			if(strcmp(pb->sex,"��") == 0)
			{
			printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
			printf("ѧ��������%*s",5,pb->name);printf(" ");
			printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
			printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
			printf("��ѧ���ɼ����£�\n");
			printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
			printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
			printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
			printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
			printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
}



//��ӡŮ�Ե���Ϣ
void print_woman(STU *head)
{
	STU *pb=head;
	if(pb==NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb!=NULL)
		{
			if(strcmp(pb->sex,"Ů") == 0)
			{
				printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
				printf("ѧ��������%*s",5,pb->name);printf(" ");
				printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
				printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
				printf("��ѧ���ɼ����£�\n");
				printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
				printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
				printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
				printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
				printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
}  



//��ӡ����
void print_msg(STU *head)
{
	int choice_print=0;
	printf("�������ʲô������\n");
	printf("1.ѧ��˳��\n");
	printf("2.��Ů�Ա�\n");
	printf("3.רҵ����\n");
	scanf("%d",&choice_print);
	switch(choice_print)
	{
		case 1:print_order(head);break;
		case 2:print_sex(head);break;
		case 3:print_major(head);break;
		defult:print_msg(head);break;
	}
	return;
}
void print_major(STU *head)
{
	printf("����������Ҫ���רҵ���ƣ�\n");
	char majorex[16];
	scanf("%s",majorex);
	STU *pb=head;
	if(pb==NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb!=NULL)
		{
			if(strcmp(pb->major,majorex) == 0)
			{
				printf("ѧ��ѧ�ţ�%05d",pb->num);printf(" "); 
				printf("ѧ��������%*s",5,pb->name);printf(" ");
				printf("ѧ���Ա�%*s",2,pb->sex);printf(" ");
				printf("ѧ��רҵ��%*s",8,pb->major);printf("\n");
				printf("��ѧ���ɼ����£�\n");
				printf("�ߵ���ѧ�ɼ���%5d",pb->scoreA);printf(" ");
				printf("������Ƴɼ���%5d",pb->scoreB);printf(" ");
				printf("��ѧӢ��ɼ���%5d",pb->scoreC);printf(" ");
				printf("˼�޽����ɼ���%5d",pb->scoreD);printf(" ");
				printf("��ѧ���ܳɼ���%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
} 



//����Ա��Ϣ�޸ĺ���
void adm_alter(ADM *admpin)
{
	int choice_alter=0;
	printf("��������Ҫ�޸Ĺ���Ա����һ����Ϣ��\n");
	printf("1.�˻�����\n");
	printf("2.����\n");
	scanf("%d",&choice_alter);
	switch(choice_alter)
	{
		case 1:username_alter(admpin);break;
		case 2:code_alter(admpin);break;
		default:printf("�������\n");adm_alter(admpin);break;
	}
	return;
} 



//����Ա�˻��޸�
void username_alter(ADM *admpin)
{
	printf("�������µĹ���Ա�˺ţ�\n");
	scanf("%s",admpin->username); 
	printf("��Ϣ�޸���ϣ�"); 
	return; 
} 



//����Ա�����޸� 
void code_alter(ADM *admpin)
{
	printf("�������µĹ���Ա���룺\n");
	scanf("%s",admpin->code);
	printf("��Ϣ�޸���ϣ�\n");
	return;
}


//��ӡѧ���ɼ� 
void soc_print(STU* head,int n)
{
	int i;
	STU* p = head;
	
	printf("1.��ӡ�����ɼ�\n");
	printf("2.��ӡӢ��ɼ�\n");
	printf("3.��ӡ������Ƴɼ�\n");
	printf("4.��ӡ˼�޳ɼ�\n");
	printf("5.��ӡ�ܳɼ�\n"); 
	printf("��ѡ���ܣ�1~5����");
	scanf("%d", &i);
	
	if (i == 1)
	{
		int sum1 = 0;
		while (p)
		{
			sum1 += p->scoreA;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreA);
			p = p->next;
		}
		int average1 = sum1/n;
		printf("�ߵ���ѧ��ƽ���ɼ�Ϊ��%d\n", average1);
	}
	
	else if (i==2)
	{
		int sum2 = 0;
		while (p)
		{
			sum2 += p->scoreB;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreB);
			p = p->next;
		}
		int average2 = sum2/n;
		printf("������Ƶ�ƽ���ɼ�Ϊ��%d\n", average2);
	}
	
	else if (i==3)
	{
		int sum3 = 0;
		while (p)
		{
			sum3 += p->scoreC;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreC);
			p = p->next;
		}
		int average3 = sum3/n;
		printf("��ѧӢ���ƽ���ɼ�Ϊ��%d\n", average3);
	}
	
	else if (i==4)
	{
		int sum4 = 0;
		while (p)
		{
			sum4 += p->scoreD;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreD);
			p = p->next;
		}
		int average4 = sum4/n;
		printf("˼�����������ƽ���ɼ���%d\n", average4);
	}
	
	else if (i==5)
	{
		int sum5 = 0;
		while (p)
		{
			sum5 += p->score_sum;
			printf("%05d %5s %5d\n", p->num,p->name,p->score_sum);
			p = p->next;
		}
		int average5 = sum5/n;
		printf("�ֵܷ�ƽ���ɼ�Ϊ��%d\n", average5);
	}
	return;
}
	STU *soc_registration(STU *head)//��������ѧ���ɼ�
	{
		STU *pb=head;
		if(pb==NULL)
		{
			printf("��ѧ�����ݣ�\n");
			return head;
		}
		printf("�Ƿ���Ҫ���ϴ�ֹͣ�Ǽǵĵط�����¼�룿(������ѡ��ǰ�����)\n");
		printf("1.�ǵ�\n");
		printf("2.���������ͷ��ʼ����\n");
		int temp2=0;
		scanf("%d",&temp2);
		if(temp2==1)
		{
			while(pb->score_sum!=-1)
			{
				if(pb->next==NULL)
				{
					printf("δ�ҵ�û�гɼ���ѧ������Ҫ����֮ǰ��ѧ���ɼ����ݣ�����ָ���ȡ������������registerָ�\n");
					return head; 
				}
				pb=pb->next;
			}
		} 
		while(1)
		{
			printf("ѧ��������%s\n",pb->name);
			printf("�ߵ���ѧ��\n");
			scanf("%d",&pb->scoreA);
			printf("������ƣ�\n");
			scanf("%d",&pb->scoreB);
			printf("��ѧӢ�\n");
			scanf("%d",&pb->scoreC);
			printf("˼����£�\n");
			scanf("%d",&pb->scoreD);
			pb->score_sum=pb->scoreA+pb->scoreB+pb->scoreC+pb->scoreD;
			printf("��ѧ������Ϣ¼����ϣ�\n");
			if(pb->next==NULL)
			{
				printf("��ѧ����Ϣ�������һ��!\n");
				return head; 
			}
			printf("�Ƿ����¼��ɼ���������дѡ�����ţ�\n");
			printf("1.��\n");
			printf("2.��\n"); 
			int temp=0;
			scanf("%d",&temp);
			if(temp == 2)
			{
				return head;
			}
			else pb=pb->next;
		}
	 } 
	

