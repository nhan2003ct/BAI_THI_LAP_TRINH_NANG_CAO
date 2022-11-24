// BAI TIM SO CHAN LE TRONG FILE
//------------------------------------------------------------------------------//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char input1[] = "day_so_nguyen.txt";
char input2[] = "day_so_nguyen.bin";
char ouput[] = "ket_qua.txt";

// Hàm đọc file
//------------------------------------------------------------------------------//
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
        fwrite(&num,1,sizeof(num),Fout);
        n++;
    }
    fclose(Fin);
    fclose(Fout);   
}

// Hàm ghi file
//------------------------------------------------------------------------------//
void writefile()
{
    FILE *Fin,*Fout;
    int b[100],num = 0, n = 0;
    if(((Fin = fopen(input2,"rb")) == NULL) || ((Fout = fopen(ouput,"w")) == NULL))
    {
        printf("FILE DEO TON TAI KIEM TRA LAI"); exit(1);
    }
    while (fread(&num,1,sizeof(num),Fin))
    {
        b[n] = num;
        n++;
        printf("%8d",num);
    }
    int i,max = 0, min = b[0], sc = 0, sl = 0;
    for(i = 0; i < n; i++)
    {
        if(b[i]%2 == 0)
        {
            sc++;
        }
        if(b[i]%2 != 0)
        {
            sl++;
        }
        if(b[i] > max)
        {
            max = b[i];
        }
        else if(b[i] < min)
        {
            min = b[i];
        }
    }
    printf("\n file co so chu so la %8d\n",n);
    printf("co %d so chan  \n",sc);
    printf("co %d so le \n",sl);
    printf("so lon nhat la %8d\n",max);
    printf("so nho nhat la %8d\n",min);
        fprintf(Fout,"\n file co so chu so la %8d\n",n);
        fprintf(Fout,"co %d so chan  \n",sc);
        fprintf(Fout,"co %d so le \n",sl);
        fprintf(Fout,"so lon nhat la %8d\n",max);
        fprintf(Fout,"so nho nhat la %8d\n",min);
    fclose(Fin);
    fclose(Fout);
}

// Chương trình chính
//------------------------------------------------------------------------------//
int main()
{
    readfile();
    system("pause");
    writefile();
    return 0;
}
