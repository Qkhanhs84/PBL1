#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <windows.h>
struct edge{
    int u,v; 
    int w; 
};
FILE *fin, *fout;
int n , m ,khu = 0,tt; 
int t,p;
int x,y; 
char a[1000];
int parent[1000];int  size[1000]; 
struct edge canh[1000]; 
int room[1000];
void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void make_set()
{
    for(int i =1 ;i<=x;i++)
    {
        parent[room[i]] = room[i] ; 
        size[room[i]] =1 ; 
    }
}
int find(int v )
{
    if(v==parent[v]) return v;  
    return parent[v] = find(parent[v]) ; 
}
bool Union (int a,int b)
{
    a= find(a) ; 
    b = find(b) ; 
    if(a==b) return false ; 
    if(size[a]<size[b]) {
        int tmp = a; 
        a =b ; 
        b = tmp ; 
    } 
    parent[b] = a; 
    size[a]+=size[b] ; 
    return true; 
}
int cmp(const void *a, const void *b) {
    struct edge *ea = (struct edge*) a;
    struct edge *eb = (struct edge*) b;
    return ea->w - eb->w;
}
void inp()
{
    if(t==1)fscanf(fin ,"%d%d",&n,&m);
    if(t==2) scanf("%d%d",&n,&m);
    x=n; y = m; 
	
    for(int i = 1 ;i<=n;i++)
    { 
        if(t==1) fscanf(fin," %c",&a[i]);
        if(t==2) scanf(" %c",&a[i]);
        room[i] = a[i] - 'A'+1;
	}
    for(int i =1 ;i<=m;i++)
    { 
        char x ; 
        char y ;
        int z ;
        if(t==1) fscanf(fin," %c %c%d",&x,&y,&z);
        if(t==2) scanf(" %c %c%d",&x,&y,&z);
        struct edge e;
        e.u = x-'A'+1 ; e.v = y-'A'+1 ;e.w= z ;
        canh[i] = e; 
    }
    khu =1 ; 
}
void Kruskal()
{
	if(khu ==1) {
        if(p==1) {
            
            fprintf(fout,"Duong day toi thieu cho tat ca cac khu:\n");
        }
        if(p==2) {
            TextColor(khu+5);
            printf("\n__________________________________\n");
            printf("Duong day toi thieu cho tat ca cac khu:\n");
        }
    }
	else {
		if(p==1) {
            fprintf(fout,"Duong day toi thieu cho khu %c\n",a[tt]);
        }
        if(p==2) {
            TextColor(tt);
            printf("\n__________________________________\n");
            printf("Duong day toi thieu cho khu %c\n",a[tt]);
        }
	}
    //tao cay khung cuc tieu rong 
    struct edge mst[1000];
    int d =0 ,cnt =0 ;
    //sort danh sach canh theo chieu dai tang dan
    qsort(canh, y, sizeof(struct edge), cmp);
    for(int i =0 ;i<y;i++)
    {
        if(cnt==x-1) break; 
        struct edge e = canh[i] ; 
        if(Union(e.u,e.v)){
            mst[cnt++] = e;  
            d+=e.w;
        }
    }
    if(cnt!=x-1) {
        if(p==1) fprintf(fout,"khong ton tai cay khung");
        if(p==2) printf("khong ton tai cay khung");
    }
    else {
        if(p==1) {
            fprintf(fout,"duong day toi thieu: %d\n",d);
            }
        if(p==2) {
        	if(khu==1) TextColor(khu+5);
        	else 
            TextColor(tt);
            printf("duong day toi thieu: %d\n",d);}
        if(khu ==1)
        { 
        TextColor(khu+5);
		for(int i =0 ;i<cnt;i++)
            {
                if(p==1) {fprintf(fout,"%c %c %d\n",(char)(mst[i].u+'A'-1),(char)(mst[i].v+'A'-1),mst[i].w);
                }
                if(p==2) {printf("%c %c %d\n",(char)(mst[i].u+'A'-1),(char)(mst[i].v+'A'-1),mst[i].w);
                }
            }
            if(p==1) {
                    fprintf(fout,"\n__________________________________\n");
                }
                if(p==2) {
                    printf("\n__________________________________\n");
                }
        }

        else {
            for(int i =0 ;i<cnt;i++){
            if(p==1) {fprintf(fout,"%c%d %c%d %d\n",a[tt],mst[i].u,a[tt],mst[i].v,mst[i].w);
                }
            if(p==2) {
                TextColor(tt);
                printf("%c%d %c%d %d\n",a[tt],mst[i].u,a[tt],mst[i].v,mst[i].w);
                }
            }
            if(p==1) {
                fprintf(fout,"\n__________________________________\n");
                }
            if(p==2) {
                printf("\n__________________________________\n");
                }
		}
    }
}
void area()
{
	for(int o =1 ;o<=n;o++)
	{
		tt=o;
		khu = 0 ;
		char line[1000];
        if(t==1){
		fgetc(fin);
		fgets(line, sizeof(line), fin);
        }
        else if(t==2)
        {
            getchar();
            gets(line);
        }
		int g, h;
		if(t==1) fscanf(fin,"%d%d",&g,&h);
        if(t==2) scanf("%d%d",&g,&h);
		x = g; y =h ;
		for(int i =1 ;i<=g;i++)
		{
			char b5;
			if(t==1) fscanf(fin," %c%d",&b5,&room[i]);
            if(t==2) scanf(" %c%d",&b5,&room[i]);
		}
		for(int i =1;i<=h;i++)
		{
			int a1,a2,a3; 
			char b1,b2;
			if(t==1) fscanf(fin," %c%d %c%d%d",&b1,&a1,&b2,&a2,&a3);
            if(t==2) scanf(" %c%d %c%d%d",&b1,&a1,&b2,&a2,&a3);
			struct edge e ;
			e.u = a1; e.v = a2;e.w = a3;
			canh[i] =e ; 
		}
		make_set();
		Kruskal();
	}
}
int main()
{
    srand(time(NULL));
	printf("Welcome to our Project Base Learning\n");
	while(1){
		int mau = 1+rand()%15;
        TextColor(mau);
        for(int i=1;i<=15;i++){
			printf("%c", 196);
		}
		printf("MENU");
		for(int i=1;i<=15;i++){
			printf("%c", 196);
		}
		printf("\n");
		printf("%c1. Lay tu file                  %c\n", 179, 179);
		printf("%c2. Nhap tu ban phim             %c\n", 179, 179);
		printf("%c3. Thoat                        %c\n", 179, 179);
		for(int i=1;i<=34;i++){
			printf("%c", 196);
		}
        printf("\n");
        printf("nhap lua chon cua ban: ");
		int c;
		scanf("%d", &c);
        if(c<1||c>3){
            printf("moi nhap lai !!!\n");
            continue;
        }
        t =c;
		if(c==3){
            printf("thank you !!!");
            break;
        }
        if(c==1)
		{
            for(int i=1;i<=15;i++){
				printf("%c", 196);
			}
			printf("MENU");
			for(int i=1;i<=15;i++){
				printf("%c", 196);
			}
			printf("\n");
			printf("%c1. input                         %c\n", 179, 179);
			printf("%c2. input2                        %c\n", 179, 179);
			printf("%c3. file3                         %c\n", 179, 179);
			for(int i=1;i<=34;i++){
			printf("%c", 196);
			}
			printf("\n");
            char fn[30];
		printf("Moi nhap ten file: ");
		scanf("%s",fn);
        strcat(fn,".txt");
		fin = fopen(fn, "r");
        }
        for(int i=1;i<=15;i++){
			printf("%c", 196);
		}
		printf("MENU");
		for(int i=1;i<=15;i++){
			printf("%c", 196);
		}
		printf("\n");
		printf("%c1. Xuat file                    %c\n", 179, 179);
		printf("%c2. Xuat console                 %c\n", 179, 179);
		for(int i=1;i<=34;i++){
			printf("%c", 196);
		}
		printf("\n");
        printf("moi nhap lua chon xuat cua ban: ");
        scanf("%d",&p);
        if(p==1)
        {
            fout = fopen("F:\\DUT\\PBL\\output.txt", "w");
        }
        inp(); 
        make_set();
        Kruskal();
        area();
        if(p==1) fclose(fout);
        if(t==1) fclose(fin);
        printf("Thank you\n");
	}
}