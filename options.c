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
    printf("支持的图像格式有如下几种:\n");
    printf("1  -  png\n");
    printf("2  -  jpg\n");
    printf("3  -  gif\n");
    printf("4  -  svg(默认)\n");
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
        default :printf("暂不支持"),system("pause");
    }

    fclose(fp);
}

void pzl(void){
    FILE *fp=NULL;
    int result;
    char str[2];
    system("cls");

    printf("魔方类型\n请输入1-10之间的一个整数作为魔方的阶数, 默认值为3\n>>");
    scanf("%d",&result);
    getchar();

    if((result<2)&&(result>10)){
        printf("\n\n\n\t\t暂时不支持%d阶魔方, 本次输入无效, 五秒后自动返回上级",result);
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
    printf("图像尺寸, 参数值N为0-1024, 图像大小为N x N像素\n>>");
    scanf("%d",&result);
    getchar();

    if((result<0)&&(result>1024)){
        printf("%dx%d图像过大, 暂不支持,5秒后返回上级\n",result,result);
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

    printf("请输入打乱公式(转动符号之间不得有空格)\n>>");
    scanf("%s",result);
    getchar();

    system("cls");
    printf("%s\n",result);
    printf("请输入打乱模式(如何处理您输入的打乱公式)代号:\n");
    printf("1 - 将魔方按照此打乱公式打乱\n");
    printf("2 - 将魔方打乱，并使其能按此打乱公式还原\n>>");
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
    printf("代号   修改项\n");
    printf("1  -  只展示 U 层(即俯视视角)\n");
    printf("2  -  将底色改为透明(即展示所有块)\n");
    printf("0  -  退出更改\n");
    printf("注意，此项改动不可逆\n");
    printf("请输入视图代号\n");
    printf(">>");
    scanf("%d",&result);
    getchar();

    if((result!=1)&&(result!=2)){
        printf("退出更改...\n");
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
    printf("注意: 若无特殊需求, 不建议修改旋转角度, 默认值本身就很完美!\n");
    /*do(
        ;
    )while(method==0);*/
    printf("请输入y轴旋转角度(默认45)\n>>");
    scanf("%d",&y);
    getchar();
    printf("请输入x轴旋转角度(默认-34)");
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
    printf("参数说明: 只展示指定阶段, 将不相关的块变为灰色\n");
    /*( fl | f2l | ll | cll | ell | oll |
     ocll | oell | coll | ocell | wv | vh | els |
      cls | cmll | cross | f2l_3 | f2l_2 | f2l_sm | f2l_1 | f2b |*/
    printf("代号  阶段\n");
    printf("0   - 退出更改");
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
    printf("请输入需展示的阶段\n>>");
    scanf("%d",&result);
    getchar();

    if((result<0)||(result>20)){
        printf("暂无此模式\n");
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
    printf("注意:强烈建议使用默认的国际标准配色方案, 不建议修改\n暂时支持以下颜色及对应代号: \n");
    printf("d = dark grey(深灰色)\nl = light grey(浅灰色)\ns = silver(更亮的浅灰色)\n");
    printf("w = white(白)\ny = yellow(黄)\nr = red(红)\n");
    printf("o = orange(橙)\nb = blue(蓝)\ng = green(绿)\nm = purple(紫)\n");
    printf("p = pink(粉)\nt = transparent(透明)\n");

    printf("请按 U R F D L B的顺序输入配色方案(国际标准配色yrbwog)");
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
    printf("图像背景色仅对png和gif格式图像生效! 默认为白色");

    printf("有如下选择\n");
    printf("white  - 白(默认)\n");
    printf("black  - 黑\n");
    printf("dgrey  - 深灰\n");
    printf("grey   - 灰\n");
    printf("silver - 浅灰\n");
    printf("yellow - 黄\n");
    printf("red    - 红\n");
    printf("orange - 橙\n");
    printf("blue   - 蓝\n");
    printf("green  - 绿\n");
    printf("purple - 紫\n");
    printf("pink   - 粉\n");
    printf("请输入背景色(英文)\n>>");
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
    printf("修改魔方底色\n");

    printf("有如下选择\n");
    printf("white  - 白\n");
    printf("black  - 黑(默认)\n");
    printf("dgrey  - 深灰\n");
    printf("grey   - 灰\n");
    printf("silver - 浅灰\n");
    printf("yellow - 黄\n");
    printf("red    - 红\n");
    printf("orange - 橙\n");
    printf("blue   - 蓝\n");
    printf("green  - 绿\n");
    printf("purple - 紫\n");
    printf("pink   - 粉\n");
    printf("请输入魔方底色(英文)\n>>");
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
    printf("魔方透明度\n");
    printf("透明度为1-100之间的整数(含1 100), 数字越小越透明\n请输入\n>>");
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
    printf("请确认是否需要添加箭头(添加箭头后不可撤销), 输入1继续，0取消\n>>");
    scanf("%d",&buff);
    getchar();
    if (buff=0){
        return;
    }

    system("cls");
    printf("箭头建立流程: 程序将依次询问连接点编码, 最后依次将这些连接点用箭头首尾相连\n\n");
    printf("魔方每面的编码顺序为:\nU1 U2 U3\nU4 U5 U6\nU7 U8 U9\n");
    system("pause");
    fp = fopen("C:\\VisualCubeBoom.bat","a");
    fputs("^&arw=",fp);
    fclose(fp);
    do{
        printf("请输入第%d连接点的编码\n>>",count + 1);
        scanf("%s",connect);
        getchar();

        fp = fopen("C:\\VisualCubeBoom.bat","a");
        fputs(connect,fp);
        fclose(fp);

        printf("请问是否需要第%d个连接点(1是0否)\n>>",count + 2);
        scanf("%d",&buff);
        getchar();
    }while(buff == 0);
}

void ac(void){
    FILE *fp = NULL;
    char result[6];

    system("cls");
    printf("箭头颜色默认为灰色\n");
    system("pause");

    system("cls");
    printf("有如下选择\n");
    printf("white  - 白\n");
    printf("black  - 黑\n");
    printf("dgrey  - 深灰\n");
    printf("grey   - 灰(默认)\n");
    printf("silver - 浅灰\n");
    printf("yellow - 黄\n");
    printf("red    - 红\n");
    printf("orange - 橙\n");
    printf("blue   - 蓝\n");
    printf("green  - 绿\n");
    printf("purple - 紫\n");
    printf("pink   - 粉\n");
    printf("请输入魔方底色(英文)\n>>");
    scanf("%s",result);
    getchar();

    fp = fopen("C:\\VisualCubeBoom.bat","a");

    fputs("^&ac=",fp);
    fputs(result,fp);

    fclose(fp);
}