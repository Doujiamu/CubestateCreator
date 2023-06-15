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

//基础命令:start http://cube.rider.biz/visualcube.php?fmt=svg 
int main(void){
	FILE *fp = NULL;
	int checknum;
	int option;
	
	toHead();
	// system("cls");
	fp = fopen("C:\\VisualCubeBoom.bat","w");
	addDefaultOptions();
	fclose(fp);
	
	do{ //预备模块
		system("cls");
		printf("请输入代号以选择模式:\n1 - 继续\n2 - 查看默认配置\n0 - 退出程序\n>>");
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

	do{ //主体
		system("cls");
		option=listCommon();
		getchar();
		switch(option){
			case 1 : fmt();break;                                  //图像格式
			case 2 : pzl(),system("pause");break;                  //魔方类型
			case 3 : size(),system("pause");break;                 //图像大小
			case 4 : algOrCase(),system("pause");break;            //打乱公式
			case 5 : view(),system("pause");break;                 //图像视角
			case 6 : angle(),system("pause");break;                //旋转角度
			case 7 : stage(),system("pause");break;                //展示阶段
			case 8 : sch(),system("pause");break;                  //修改配色
			case 9 : bg(),system("pause");break;                   //改背景色
			case 10 : cc(),system("pause");break;                  //模仿底色
			case 11: co(),system("pause");break;                   //改透明度
			case 12: arw(),system("pause");break;                  //箭头指向
			case 13: ac(),system("pause");break;                   //箭头颜色
			case 0: execute();break;                               //生成魔方
			case 10086: toEnd();break;                             //结束程序
			default: printf("暂未开发...\n");system("pause");break; //容错
		}
	}while(1);

	system("pause");
	toEnd();
	
	system("pause");
	return 0;
}

void toHead(void){
	printf("=====Welcome to visual cube GUI 1.0 =====\n");
	printf("官方文档详见：http://cube.rider.biz/visualcube.php\n");
	printf("因手动生成需要输入大量参数，故设此GUI方便各位魔友\n");
	printf("=====END=====\n");
	system("pause");
}

void toEnd(void){
	printf("清理缓存文件...\n");
	remove("C:\\VisualCubeBoom.bat");
	printf("清理完毕!\n");
	printf("可安全退出\n");
	system("pause");
	exit(1);
}

int setClipbar(const char *data){ //将字符串写入到剪切板 
    int contentSize = strlen(data) + 1;
    HGLOBAL hMemory; LPTSTR lpMemory;
    if(!OpenClipboard(NULL)) return 0;/* 打开剪切板 */
    if(!EmptyClipboard()) return 0; /* 清空剪切板 */
    if(!(hMemory = GlobalAlloc(GMEM_MOVEABLE, contentSize))) return 0;/* 对剪切板分配内存 */
    if(!(lpMemory = (LPTSTR)GlobalLock(hMemory))) return 0;/* 锁定内存区域 */
    memcpy_s(lpMemory, contentSize, data, contentSize);    /* 复制数据到内存区域 */
    GlobalUnlock(hMemory);                                 /* 解除内存锁定 */
    if(!SetClipboardData(CF_TEXT, hMemory)) return 0;      /* 设置剪切板数据 */
    printf("成功复制【%s】到剪切板\n",data);
    CloseClipboard();/* 关闭剪切板 */
	system("pause");
    return 1;
}

void listDefault(void){ //展示默认值
//	printf("1 - 图像格式 - svg(default)\n");
	printf("1 - 魔方类型 -  3 (default)\n");
	printf("2 - 图像尺寸 - 128(default)\n");
	printf("3 - 图像视角 -  / (default)\n");
	printf("4 - 展示阶段 -  /(default)\n");
	printf("5 - 魔方角度 - y45x-34(default)\n");
	printf("6 - 打乱模式&公式 - NULL(default)\n");
	printf("7 - 配色方案 - yrbwog(default)\n");
	printf("8 - 图像背景色 - white(default)\n");
	printf("9 - 魔方底色 - black(default)\n");
	printf("10 - 底色透明度 - 100(default)\n");
	printf("11 - 箭头指向 - -i10-s10(default)\n");
	printf("12 - 箭头颜色 - grey(default)\n");
}

int listCommon(void){ //展示选项卡
	int result;

	printf("代号 -  简述       -  默认值\n");
	printf("0   - 生成魔方     -  /\n");
	printf("1   - 图像格式     -  svg\n");
	printf("2   - 魔方类型     -  3 \n");
	printf("3   - 图像尺寸     - 128\n");
	printf("4   - 打乱公式     -  / \n");
	printf("5   - 图像视角     -  /\n");
	printf("6   - 魔方角度     - y45x-34\n");
	printf("7   - 展示阶段     -  /\n");
	printf("8   - 配色方案     - yrbwog\n");
	printf("9   - 图像背景色   - white\n");
	printf("10  - 魔方底色    - black\n");
	printf("11  - 底色透明度   - 100\n");
	printf("12  - 箭头指向     - -i10-s10\n");
	printf("13  - 箭头颜色     - grey\n");
	printf("输入要修改的代号(输入10086退出程序)\n>>");
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