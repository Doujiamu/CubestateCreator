#include <stdio.h>

void fmt(void);
void pzl(void);
void size(void);
void algOrCase(void);
void view(void);
void angle(void);
void stage(void);
void sch(void);
void bg(void);
void cc(void);
void co(void);
void arw(void);
void ac(void);

void fmt(void){
    FILE *fp = NULL;
    int result = 0;

    system("cls");
    printf("֧�ֵ�ͼ���ʽ�����¼���:\n");
    printf("1  -  png\n");
    printf("2  -  jpg\n");
    printf("3  -  gif\n");
    printf("4  -  svg(Ĭ��)\n");
    printf("5  -  tiff\n");
    printf("6  -  ico\n>>");
    scanf("%d",&result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");
    fputs("^&fmt=",fp);

    switch(result){
        case 1:fputs("png",fp);break;
        case 2:fputs("jpg",fp);break;
        case 3:fputs("gif",fp);break;
        case 4:fputs("svg",fp);break;
        case 5:fputs("tiff",fp);break;
        case 6:fputs("ico",fp);break;
        default :printf("�ݲ�֧��"),system("pause");
    }

    fclose(fp);
}

void pzl(void){
    FILE *fp=NULL;
    int result;
    char str[2];
    system("cls");

    printf("ħ������\n������1-10֮���һ��������Ϊħ���Ľ���, Ĭ��ֵΪ3\n>>");
    scanf("%d",&result);
    getchar();

    if((result<2)&&(result>10)){
        printf("\n\n\n\t\t��ʱ��֧��%d��ħ��, ����������Ч, ������Զ������ϼ�",result);
        Sleep(5000);
        return;
    }
    sprintf(str,"%d",result);
    
    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&pzl=",fp);
    fputs(str,fp);

    fclose(fp);
}

void size(void){
    FILE *fp = NULL;
    int result;
    char str[4];

    system("cls");
    printf("ͼ��ߴ�, ����ֵNΪ0-1024, ͼ���СΪN x N����\n>>");
    scanf("%d",&result);
    getchar();

    if((result<0)&&(result>1024)){
        printf("%dx%dͼ�����, �ݲ�֧��,5��󷵻��ϼ�\n",result,result);
        Sleep(5000);
        return;
    }

    sprintf(str,"%d",result);

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&size=",fp);
    fputs(str,fp);

    fclose(fp);
}

void algOrCase(void){
    FILE *fp=NULL;
    char result[1024];
    char ch;
    int i = 0;
    int checknum=0;

    printf("��������ҹ�ʽ(ת������֮�䲻���пո�)\n>>");
    scanf("%s",result);
    getchar();

    system("cls");
    printf("%s\n",result);
    printf("���������ģʽ(��δ���������Ĵ��ҹ�ʽ)����:\n");
    printf("1 - ��ħ�����մ˴��ҹ�ʽ����\n");
    printf("2 - ��ħ�����ң���ʹ���ܰ��˴��ҹ�ʽ��ԭ\n>>");
    scanf("%d",&checknum);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    if(checknum==1){
        fputs("^&alg=",fp);
    }
    else if(checknum==2){
        fputs("^&case=",fp);
    }

    fprintf(fp,"%s",result);

    fclose(fp);
}

void view(void){
    FILE *fp = NULL;
    int result = 0;


    system("cls");
    printf("����   �޸���\n");
    printf("1  -  ֻչʾ U ��(�������ӽ�)\n");
    printf("2  -  ����ɫ��Ϊ͸��(��չʾ���п�)\n");
    printf("0  -  �˳�����\n");
    printf("ע�⣬����Ķ�������\n");
    printf("��������ͼ����\n");
    printf(">>");
    scanf("%d",&result);
    getchar();

    if((result!=1)&&(result!=2)){
        printf("�˳�����...\n");
        system("pause");
        return;
    }
    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&view=",fp);
    switch(result){
        case 1: fputs("plan",fp);break;
        case 2: fputs("trans",fp);break;
    }

    fclose(fp);
}

void angle(void){
    FILE *fp = NULL;
    int method = 0;
    signed int y = 45;
    signed int x = -34;
    char yc[10];
    char xc[10];

    system("cls");
    printf("ע��: ������������, �������޸���ת�Ƕ�, Ĭ��ֵ����ͺ�����!\n");
    /*do(
        ;
    )while(method==0);*/
    printf("������y����ת�Ƕ�(Ĭ��45)\n>>");
    scanf("%d",&y);
    getchar();
    printf("������x����ת�Ƕ�(Ĭ��-34)");
    scanf("%d",&x);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&r=",fp);

    sprintf(yc,"%d",y);
    sprintf(xc,"%d",x);

    fputs("y",fp);
    fputs(yc,fp);
    fputs("x",fp);
    fputs(xc,fp);

    fclose(fp);
}

void stage(void){
    FILE *fp=NULL;
    int result=0;

    system("cls");
    printf("����˵��: ֻչʾָ���׶�, ������صĿ��Ϊ��ɫ\n");
    /*( fl | f2l | ll | cll | ell | oll |
     ocll | oell | coll | ocell | wv | vh | els |
      cls | cmll | cross | f2l_3 | f2l_2 | f2l_sm | f2l_1 | f2b |*/
    printf("����  �׶�\n");
    printf("0   - �˳�����");
    printf("1   - fl\n");
    printf("2   - cross\n");
    printf("3   - f2l\n");
    printf("4   - oll\n");
    printf("5   - ll\n");
    printf("6   - cll\n");
    printf("7   - ell\n");
    printf("8   - ocll\n");
    printf("9   - oell\n");
    printf("10  - ocell\n");
    printf("11  - wv\n");
    printf("12  - vh\n");
    printf("13  - els\n");
    printf("14  - cls\n");
    printf("15  - cmll\n");
    printf("16  - f2l_3\n");
    printf("17  - f2l_2\n");
    printf("18  - fel_1\n");
    printf("19  - f2l_sm\n");
    printf("20  - f2b\n");
    printf("��������չʾ�Ľ׶�\n>>");
    scanf("%d",&result);
    getchar();

    if((result<0)||(result>20)){
        printf("���޴�ģʽ\n");
        system("pause");
        return;
    }

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&stage=",fp);
    
    switch(result){
        case 1 :fputs("fl",fp);break;
        case 2 :fputs("cross",fp);break;
        case 3 :fputs("f2l",fp);break;
        case 4 :fputs("oll",fp);break;
        case 5 :fputs("ll",fp);break;
        case 6 :fputs("cll",fp);break;
        case 7 :fputs("ell",fp);break;
        case 8 :fputs("ocll",fp);break;
        case 9 :fputs("oell",fp);break;
        case 10:fputs("ocell",fp);break;
        case 11:fputs("wv",fp);break;
        case 12:fputs("vh",fp);break;
        case 13:fputs("els",fp);break;
        case 14:fputs("cls",fp);break;
        case 15:fputs("cmll",fp);break;
        case 16:fputs("f2l_3",fp);break;
        case 17:fputs("f2l_2",fp);break;
        case 18:fputs("f2l_1",fp);break;
        case 19:fputs("f2l_sm",fp);break;
        case 20:fputs("f2b",fp);break;
    }

    fclose(fp);
}

void sch(void){
    FILE *fp = NULL;
    char result[6];
    /*n=black (noir), d=dark grey, l=light grey,
     s=silver (lighter grey), w=white, y=yellow, r=red,
      o=orange, b=blue, g=green, m=purple (magenta), p=pink, t=transparent*/
    
    system("cls");
    printf("ע��:ǿ�ҽ���ʹ��Ĭ�ϵĹ��ʱ�׼��ɫ����, �������޸�\n��ʱ֧��������ɫ����Ӧ����: \n");
    printf("d = dark grey(���ɫ)\nl = light grey(ǳ��ɫ)\ns = silver(������ǳ��ɫ)\n");
    printf("w = white(��)\ny = yellow(��)\nr = red(��)\n");
    printf("o = orange(��)\nb = blue(��)\ng = green(��)\nm = purple(��)\n");
    printf("p = pink(��)\nt = transparent(͸��)\n");

    printf("�밴 U R F D L B��˳��������ɫ����(���ʱ�׼��ɫyrbwog)");
    scanf("%s",result);

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&sch=",fp);
    fputs(result,fp);

    fclose(fp);
}

void bg(void){
    FILE *fp = NULL;
    char result[6];

    system("cls");
    printf("ͼ�񱳾�ɫ����png��gif��ʽͼ����Ч! Ĭ��Ϊ��ɫ");

    printf("������ѡ��\n");
    printf("white  - ��(Ĭ��)\n");
    printf("black  - ��\n");
    printf("dgrey  - ���\n");
    printf("grey   - ��\n");
    printf("silver - ǳ��\n");
    printf("yellow - ��\n");
    printf("red    - ��\n");
    printf("orange - ��\n");
    printf("blue   - ��\n");
    printf("green  - ��\n");
    printf("purple - ��\n");
    printf("pink   - ��\n");
    printf("�����뱳��ɫ(Ӣ��)\n>>");
    scanf("%s",result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&bg=",fp);
    fputs(result,fp);

    fclose(fp);
}

void cc(void){
    FILE *fp = NULL;
    char result[6];

    system("cls");
    printf("�޸�ħ����ɫ\n");

    printf("������ѡ��\n");
    printf("white  - ��\n");
    printf("black  - ��(Ĭ��)\n");
    printf("dgrey  - ���\n");
    printf("grey   - ��\n");
    printf("silver - ǳ��\n");
    printf("yellow - ��\n");
    printf("red    - ��\n");
    printf("orange - ��\n");
    printf("blue   - ��\n");
    printf("green  - ��\n");
    printf("purple - ��\n");
    printf("pink   - ��\n");
    printf("������ħ����ɫ(Ӣ��)\n>>");
    scanf("%s",result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&cc=",fp);
    fputs(result,fp);

    fclose(fp);
}

void co(void){
    FILE *fp = NULL;
    int num = 0;
    char result[3];

    system("cls");
    printf("ħ��͸����\n");
    printf("͸����Ϊ1-100֮�������(��1 100), ����ԽСԽ͸��\n������\n>>");
    scanf("%d",&result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&co=",fp);

    sprintf(result,"%d",num);
    fputs(result,fp);

    fclose(fp);
}

void arw(void){
    FILE *fp = NULL;
    int buff=0;
    int count = 0;
    char connect[2];

    system("cls");
    printf("��ȷ���Ƿ���Ҫ��Ӽ�ͷ(��Ӽ�ͷ�󲻿ɳ���), ����1������0ȡ��\n>>");
    scanf("%d",&buff);
    getchar();
    if (buff=0){
        return;
    }

    system("cls");
    printf("��ͷ��������: ��������ѯ�����ӵ����, ������ν���Щ���ӵ��ü�ͷ��β����\n\n");
    printf("ħ��ÿ��ı���˳��Ϊ:\nU1 U2 U3\nU4 U5 U6\nU7 U8 U9\n");
    system("pause");
    fp = fopen("C:\\VisualCubeBoom.bat","a");
    fputs("^&arw=",fp);
    fclose(fp);
    do{
        printf("�������%d���ӵ�ı���\n>>",count + 1);
        scanf("%s",connect);
        getchar();

        fp = fopen("C:\\VisualCubeBoom.bat","a");
        fputs(connect,fp);
        fclose(fp);

        printf("�����Ƿ���Ҫ��%d�����ӵ�(1��0��)\n>>",count + 2);
        scanf("%d",&buff);
        getchar();
    }while(buff == 0);
}

void ac(void){
    FILE *fp = NULL;
    char result[6];

    system("cls");
    printf("��ͷ��ɫĬ��Ϊ��ɫ\n");
    system("pause");

    system("cls");
    printf("������ѡ��\n");
    printf("white  - ��\n");
    printf("black  - ��\n");
    printf("dgrey  - ���\n");
    printf("grey   - ��(Ĭ��)\n");
    printf("silver - ǳ��\n");
    printf("yellow - ��\n");
    printf("red    - ��\n");
    printf("orange - ��\n");
    printf("blue   - ��\n");
    printf("green  - ��\n");
    printf("purple - ��\n");
    printf("pink   - ��\n");
    printf("������ħ����ɫ(Ӣ��)\n>>");
    scanf("%s",result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&ac=",fp);
    fputs(result,fp);

    fclose(fp);
}