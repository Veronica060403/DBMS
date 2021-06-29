#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<iomanip>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	struct student
	{
		char first_name[10],last_name[10],course[20];
		char section;
	};
	struct student e;
	char xfirst_name[10],xlast_name[10];
	long int recsize;
	fp=fopen("users.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("users.txt","wb+");
		if(fp==NULL)
		{
			puts("Cannot open file");
			return 0;
		}
	}
	recsize=sizeof(e);
	while(1)
	{
		system("cls");
		cout<<"\t\t           Student database management system           ";
		cout<<"\n\n\n\t1.Add Records ";
		cout<<"\n\t2.List Records ";
		cout<<"\n\t3.Modify Records ";
		cout<<"\n\t4.Delete Records ";
		cout<<"\n\t5.LExit Program  ";
		cout<<"\n\n\tSelect your choice : ";
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another='y';
				while(another=='Y'|| another=='y')
				{
					system("cls");
					cout<<"\n\tEnter the first name : ";
					cin>>e.first_name;
					cout<<"\n\tEnter the last name : ";
					cin>>e.last_name;
					cout<<"\n\tEnter the course : ";
					cin>>e.course;
					cout<<"\n\tEnter the section : ";
					cin>>e.section;
					fwrite(&e,recsize,1,fp);
					cout<<"\n\tAdd another record ";
					fflush(stdin);
					another=getchar();
				}
				break;
			case '2':
				system("cls");
				rewind(fp);
				cout<<"\n\t\t\t===View record in the database===\n";
				while(fread(&e,recsize,1,fp)==1)
				{
					cout<<"\n\t\tName :\t"<<e.first_name<<setw(5)<<e.last_name;
					cout<<"\n\t\tCourse :\t"<<e.course;
					cout<<"\n\t\tSection :\t"<<e.section;
				}
				cout<<"\n";
				system("pause");
				break;
			case '3':
				system("cls");
				another='Y';
				while(another=='Y'||another=='y')
				{
					cout<<"\n\tEnter the last name of the student :";
					cin>>xlast_name;
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.last_name,xlast_name)==0)
						{
							cout<<"\n\tEnter the new first name : ";
							cin>>e.first_name;
							cout<<"\n\tEnter the new last name : ";
							cin>>e.last_name;
							cout<<"\n\tEnter the new course : ";
							cin>>e.course;
							cout<<"\n\tEnter the new section : ";
							cin>>e.section;
							fseek(fp, - recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);
							break;
						}
						else
							cout<<"\n\tRecord not found";
					}
					cout<<"\n\tModify another record ";
					fflush(stdin);
					another=getchar();
				}
				break;
			case '4':
				system("cls");
				another='Y';
				while(another=='Y'||another=='y')
				{
					cout<<"\n\tEnter the last name of the student to delete : ";
					cin>>xlast_name;
					ft=fopen("temp.dat","wb");
					rewind(fp);
					while(fread(&e, recsize,1,fp)==1)
					{
						if(strcmp(e.last_name,xlast_name)!=0)
						{
							fwrite(&e,recsize,1,ft);
						}
						fclose(fp);
						fclose(ft);
						remove("users.txt");
						rename("temp.dat","users.txt");
						fp=fopen("users.txt","rb+");
						cout<<"\n\tDelete another record ";
						fflush(stdin);
						another=getchar();
					}	
				}
				break;
			case '5':
				fclose(fp);
				cout<<"\n\n\t  Thankyou for using this software  ";
				exit(0);
		}
	}
	system("pause");
	return 0;
}























