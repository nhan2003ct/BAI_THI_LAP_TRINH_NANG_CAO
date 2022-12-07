// SAP XEP DAY SO VA THEM SO TU BAN PHIM
//------------------------------------------------------------------------------//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char input1[] = "day_so_nguyen.txt";
char input2[] = "day_so_nguyen.bin";

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void sapxep(int a[],long n)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        for(int i=left;i<right;i++)
            if(a[i]>a[i+1])
           swap(&a[i],&a[i+1]);
           right--;
           for(int j=right;j>left;j--)
            if(a[j]<a[j-1])
            swap(&a[j],&a[j-1]);
           left++;
    }
}

void readfile()
{
    FILE *Fin,*Fout;
    int a[100],num = 0, n = 0;
    if(((Fin = fopen(input1,"r")) == NULL) || ((Fout = fopen(input2,"wb")) == NULL))
    {
        printf("FILE DEO TON TAI KIEM TRA LAI"); exit(1);
    }
    while (fscanf(Fin,"%d",&num) != EOF)
    {
        a[n] = num;
        printf("%8d",num);
        n++;
    }
    printf("\nfile co %d so \n",n);
    sapxep(a,n);
    printf("file sao khi sap xep \n");
    for(int i=0;i<n;i++)
    {
        printf("%8d",a[i]);
        fwrite(&a[i],1,sizeof(int),Fout);
    }
    fclose(Fin);
    fclose(Fout);   
}

void writefile()
{
     FILE *Fin,*Fout;
    int a[100],num = 0, n = 0;
    if(((Fin = fopen(input2,"rb")) == NULL) || ((Fout = fopen(input2,"ab")) == NULL))
    {
        printf("FILE DEO TON TAI KIEM TRA LAI"); exit(1);
    }
    while (fread(&a[n],1,sizeof(int),Fin))
    {
        printf("%8d",a[n]);
        n++;
    }
    printf("\nnhap so phan tu ma ban muon nhap them :");scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
       printf("nhap so thu b[%d]",i);scanf("%d",&a[i]);
       fwrite(&a[i],1,sizeof(int),Fout);
    }
    fclose(Fin);
    fclose(Fout);
}

void writefile2()
{
    FILE *Fin,*Fout;
    int a[100],num = 0, n = 0;
    if(((Fin = fopen(input2,"rb")) == NULL) || ((Fout = fopen(input2,"ab")) == NULL))
    {
        printf("FILE DEO TON TAI KIEM TRA LAI"); exit(1);
    }
    while(fread(&a[n],1,sizeof(int),Fin))
    {
        printf("%8d\n",a[n]);
        n++;
    }
    printf("\nfile co %d so \n",n);
    sapxep(a,n);
    printf("file sao khi sap xep \n");
    for(int i=0;i<n;i++)
    {
        printf("%8d\n",a[i]);
        fwrite(&a[i],1,sizeof(int),Fout);
    }
    fclose(Fin);
    fclose(Fout);   
}
int main()
{
    readfile();
    system("pause");
    writefile();
    writefile2();
    return 0;
}

