#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;


void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void login();

void viewdetails(void)
{
	system("cls");
	printf("-------------------------------------------------------------------------------------");
	printf("\nSTT\tTen\t\tHanh trinh\t\tGia tien\tThoi gian khoi hanh\n");
	printf("-------------------------------------------------------------------------------------");
	printf("\n1001\tMarvel Express\tTra Vinh di Can Tho\t500000 VND\t\t9am");
	printf("\n1002\tMarvel Express\tCan Tho di TPHCM\t500000 VND\t\t12pm");
	printf("\n1003\tMarvel Express\tTPHCM di Dalat\t\t450000 VND\t\t8am");
	printf("\n1004\tMarvel Express\tDalat di TPHCM\t\t450000 VND\t\t11am");
	printf("\n1005\tMarvel Express\tTra Vinh di Hau Giang\t400000 VND\t\t7am");
	printf("\n1006\tMarvel Express\tHau Giang di An Giang\t400000 VND\t\t9:30am");
    printf("\n1007\tMarvel Express\tCan Tho di Dong Thap\t350000 VND\t\t1pm");
    printf("\n1008\tMarvel Express\tCan Tho di Tra Vinh\t500000 VND\t\t2pm");
    printf("\n1009\tMarvel Express\tVietnam to HongKong\t600000 VND\t\t3:35pm");
    printf("\n10010\tMarvel Express\tVietnam to Thailandt\t600000 VND\t\t4:15pm");

}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nNhap ten cua ban:> ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\nNhap vi tri ngoi mong muon:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Nhan Enter de xem các chuyen bay hien co<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nNhap ma tau:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nMa tau khong hop le! Thu lai--> ");
		goto start1;
	}

	printf("\n\nXin moi quy khach xac nhan thong (nhan phim Y/N):))");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'Y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Dat ve thanh cong\n");
		printf("==================");
		printf("\nNhan Enter de tro ve Menu chinh");
	}
	else
	{
		if(confirm=='N'){
			printf("\nDat ve khong thanh cong!\nNhan Enter de den Menu chinh!");
		}
		else
		{
			printf("\nThao tac khong hop le! Thu lai-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("---------------------------\n");
	printf("\tTICKET\n");
	printf("---------------------------\n\n");
	printf("Ten:\t\t\t%s",name);
	printf("\nVi tri ngoi:\t%d",num_of_seats);
	printf("\nChuyen tau so:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nGia tien:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tTra Vinh di Can Tho");
		printf("\nTG khoi hanh:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tCan Tho di TPHCM");
		printf("\nTG khoi hanh:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tTPHCM di Dalat");
		printf("\nTG khoi hanh:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tDalat di TPHCM");
		printf("\nTG khoi hanh:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tTra Vinh di Hau Giang");
		printf("\nTG khoi hanh:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\nHang tau:\t\t\tIron City Express");
		printf("\nHanh trinh:\t\tHau Giang di An Giang");
		printf("\nTG khoi hanh:\t\t9:30am ");
	}
	if (train_num==1007)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tCan Tho di Dong Thap");
		printf("\nTG khoi hanh:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\n Hanh trinh:\t\tCan Tho di Tra Vinh");
		printf("\nTG khoi hanh:\t\t2pm ");
	}
	if (train_num==1009)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tHanoi to HongKong");
		printf("\nTG khoi hanh:\t\t3:35pm ");
	}
	if (train_num==1010)
	{
		printf("\nHang tau:\t\t\tMarvel Express");
		printf("\nHanh trinh:\t\tHanoi to Bangcok");
		printf("\nTG khoi hanh:\t\t4:15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{

    printf("\n           \t\t\t=======================  DANG NHAP  =======================\n  ");
    printf(" \n                              \t\t\t    NHAP TEN NGUOI DUNG:-");
	scanf("%s", &uname);
	printf(" \n                              \t\t\t      NHAP MAT KHAU:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"KDKU")==0 && strcmp(pword,"0907079309")==0)
	{
	printf("  \n\n\n\t\t\t\t    CHAO MUNG QUY KHACH DEN VOI HE THONG TAU HOA VIET NAM");
	printf("\n\n\n\t\t\t\t\t\t   Nhan Enter de tiep tuc...");
	getch();
	break;
	}
	else
	{
		printf("\n\n            \t\t\t\tLOI!! TEN NGUOI DUNG HOAC MAT KHAU KHONG DUNG");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nXIN LOI BAN DA NHAP SAI MAT KHAU 4 LAN!!!");
		getch();

		}
		system("cls");
}

void cancel(void)   /* Sorry this function does not work. Coding is not completed. Codes have been removed due to some errors  */
{
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Nhap ma tau muon huy: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nDa huy");
		getch();
}

int main()

{
		system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|          HE THONG VE TAU HOA VIET NAM         |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n An phim bat ki de tiep tuc:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("        HE THONG BAN VE TAU ");
	printf("\n=================================");
	printf("\n1>> Dat ve tau");
	printf("\n---------------------------------");
	printf("\n2>> Xem cac chuyen tau hien co");
	printf("\n---------------------------------");
	printf("\n3>> Huy ve chuyen tau");
	printf("\n---------------------------------");
	printf("\n4>> Thoat");
	printf("\n---------------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nAn Enter de den Menu chinh..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nLua chon khong hop le!");
	}
	goto start;
	return(0);
}
