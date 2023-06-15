#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "options.c"

void addDefaultOptions(void);
void execute(void);
void list(void);
void toHead(void);
void toEnd(void);
void listDefault(void);
int listCommon(void);
int setClipbar(const char *data);

//��������:start http://cube.rider.biz/visualcube.php?fmt=svg 
int main(void){
	FILE *fp = NULL;
	int checknum;
	int option;
	
	toHead();
	// system("cls");
	fp = fopen("C:\\VisualCubeBoom.bat","w");
	addDefaultOptions();
	fclose(fp);
	
	do{ //Ԥ��ģ��
		system("cls");
		printf("�����������ѡ��ģʽ:\n1 - ����\n2 - �鿴Ĭ������\n0 - �˳�����\n>>");
		scanf("%d",&checknum);
		getchar();
		if(checknum==2){
			system("cls");
			listDefault();
			system("pause");
		}
		else if(checknum==0){
			toEnd();
		}
	}while(checknum!=1);

	do{ //����
		system("cls");
		option=listCommon();
		getchar();
		switch(option){
			case 1 : fmt();break;                                  //ͼ���ʽ
			case 2 : pzl(),system("pause");break;                  //ħ������
			case 3 : size(),system("pause");break;                 //ͼ���С
			case 4 : algOrCase(),system("pause");break;            //���ҹ�ʽ
			case 5 : view(),system("pause");break;                 //ͼ���ӽ�
			case 6 : angle(),system("pause");break;                //��ת�Ƕ�
			case 7 : stage(),system("pause");break;                //չʾ�׶�
			case 8 : sch(),system("pause");break;                  //�޸���ɫ
			case 9 : bg(),system("pause");break;                   //�ı���ɫ
			case 10 : cc(),system("pause");break;                  //ģ�µ�ɫ
			case 11: co(),system("pause");break;                   //��͸����
			case 12: arw(),system("pause");break;                  //��ͷָ��
			case 13: ac(),system("pause");break;                   //��ͷ��ɫ
			case 0: execute();break;                               //����ħ��
			case 10086: toEnd();break;                             //��������
			default: printf("��δ����...\n");system("pause");break; //�ݴ�
		}
	}while(1);

	system("pause");
	toEnd();
	
	system("pause");
	return 0;
}

void toHead(void){
	printf("=====Welcome to visual cube GUI 1.0 =====\n");
	printf("�ٷ��ĵ������http://cube.rider.biz/visualcube.php\n");
	printf("���ֶ�������Ҫ������������������GUI�����λħ��\n");
	printf("=====END=====\n");
	system("pause");
}

void toEnd(void){
	printf("�������ļ�...\n");
	remove("C:\\VisualCubeBoom.bat");
	printf("�������!\n");
	printf("�ɰ�ȫ�˳�\n");
	system("pause");
	exit(1);
}

int setClipbar(const char *data){ //���ַ���д�뵽���а� 
    int contentSize = strlen(data) + 1;
    HGLOBAL hMemory; LPTSTR lpMemory;
    if(!OpenClipboard(NULL)) return 0;/* �򿪼��а� */
    if(!EmptyClipboard()) return 0; /* ��ռ��а� */
    if(!(hMemory = GlobalAlloc(GMEM_MOVEABLE, contentSize))) return 0;/* �Լ��а�����ڴ� */
    if(!(lpMemory = (LPTSTR)GlobalLock(hMemory))) return 0;/* �����ڴ����� */
    memcpy_s(lpMemory, contentSize, data, contentSize);    /* �������ݵ��ڴ����� */
    GlobalUnlock(hMemory);                                 /* ����ڴ����� */
    if(!SetClipboardData(CF_TEXT, hMemory)) return 0;      /* ���ü��а����� */
    printf("�ɹ����ơ�%s�������а�\n",data);
    CloseClipboard();/* �رռ��а� */
	system("pause");
    return 1;
}

void listDefault(void){ //չʾĬ��ֵ
//	printf("1 - ͼ���ʽ - svg(default)\n");
	printf("1 - ħ������ -  3 (default)\n");
	printf("2 - ͼ��ߴ� - 128(default)\n");
	printf("3 - ͼ���ӽ� -  / (default)\n");
	printf("4 - չʾ�׶� -  /(default)\n");
	printf("5 - ħ���Ƕ� - y45x-34(default)\n");
	printf("6 - ����ģʽ&��ʽ - NULL(default)\n");
	printf("7 - ��ɫ���� - yrbwog(default)\n");
	printf("8 - ͼ�񱳾�ɫ - white(default)\n");
	printf("9 - ħ����ɫ - black(default)\n");
	printf("10 - ��ɫ͸���� - 100(default)\n");
	printf("11 - ��ͷָ�� - -i10-s10(default)\n");
	printf("12 - ��ͷ��ɫ - grey(default)\n");
}

int listCommon(void){ //չʾѡ�
	int result;

	printf("���� -  ����       -  Ĭ��ֵ\n");
	printf("0   - ����ħ��     -  /\n");
	printf("1   - ͼ���ʽ     -  svg\n");
	printf("2   - ħ������     -  3 \n");
	printf("3   - ͼ��ߴ�     - 128\n");
	printf("4   - ���ҹ�ʽ     -  / \n");
	printf("5   - ͼ���ӽ�     -  /\n");
	printf("6   - ħ���Ƕ�     - y45x-34\n");
	printf("7   - չʾ�׶�     -  /\n");
	printf("8   - ��ɫ����     - yrbwog\n");
	printf("9   - ͼ�񱳾�ɫ   - white\n");
	printf("10  - ħ����ɫ    - black\n");
	printf("11  - ��ɫ͸����   - 100\n");
	printf("12  - ��ͷָ��     - -i10-s10\n");
	printf("13  - ��ͷ��ɫ     - grey\n");
	printf("����Ҫ�޸ĵĴ���(����10086�˳�����)\n>>");
	scanf("%d",&result);

	return result;
}

void addDefaultOptions(void){
	FILE *fp = NULL;
	fp = fopen("C:\\VisualCubeBoom.bat","a");

	fputs("start http://cube.rider.biz/visualcube.php?fmt=svg^&size=128",fp);

	fclose(fp);
}

void execute(void){
	ShellExecute(NULL,"open","C:\\VisualCubeBoom.bat",NULL,NULL,SW_SHOWMAXIMIZED);
	/*FILE *fp;
	char str[512];
	int i=0;
	char ch;

	fp = fopen("C:\\VisualCubeBoom.bat","a");
	
	for(i=0;(fscanf(fp,"%d",str+i))!=EOF;i++){}
	str[i+1]='\0';
	
	printf("%s",str);
	system("pause");

	fclose(fp);

	setClipbar(str);*/
}