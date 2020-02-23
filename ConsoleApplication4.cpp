#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<io.h>
#include<string.h>
struct 	student {
	int xuehao;
	char name[20];
	int math;
	int english;
	int com;
	struct student* next;
};
student* inset(struct student* head);
student* read(FILE* fp);
int main() {
	const char* path = "D:\\1编程文件\\Devcpp文件\\实验3\\student.txt";
	FILE* fp = NULL;
	while (1) {
		printf("--学生成绩管理系统--\n");
		printf("菜单：\n");
		printf("1.成绩录入\n");
		printf("2.成绩修改\n");
		printf("3.成绩添加\n");
		printf("4.成绩删除\n");
		printf("5.成绩查询\n");
		printf("6.成绩统计\n");
		printf("7.退出\n");
		printf("输入序号来打开菜单\n");
		int a;
		a = getch();
		a -= 48;
		system("cls");
		switch ((int)a) {
		case 1: {
			printf("成绩录入：\n");
			printf("1.录入\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩录入：\n");
			fp = fopen(path, "w+");
			if (fp == NULL) {
				printf("文件打开失败");
				break;
			}
			student* head = NULL;
			int b;
			do {
				head = inset(head);
				printf("是否继续输入?  1---是，2---否");
				scanf("%d", &b);
			} while (b == 1);
			student* h = NULL;
			h = head;
			while (h != NULL) {
				fwrite(h, sizeof(struct student), 1, fp);
				h = h->next;
			}
			fclose(fp);
			system("cls");
			break;
		}
		case 2: {
			printf("成绩修改：\n");
			printf("1.修改\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩修改：\n");
			fp = fopen(path, "r+");
			printf("输入需要修改的学生学号：\n");
			int c = 0;
			scanf("%d", &c);
			student* head = NULL;
			student* p = (struct student*)malloc(sizeof(struct student));
			head = p;
			fread(p, sizeof(struct student), 1, fp);
			if (p->xuehao == c) {
				printf("输入学生修改的信息：\n");
				printf("输入姓名："); scanf("%c", p->name);
				printf("输入数学成绩："); scanf("%d", p->math);
				printf("输入英语成绩："); scanf("%d", p->english);
				printf("输入计算机导论与程序设计成绩："); scanf("%d", p->com);
				fseek(fp, -sizeof(struct student), 1);
				fwrite(p, sizeof(struct student), 1, fp);
				printf("成功\n");
				printf("按任意键返回");
				a = getch();
				fclose(fp);
				system("cls");
				break;
			}
			p = p->next;
			while (p != NULL) {
				student* pr = (struct student*)malloc(sizeof(struct student));
				fread(pr, sizeof(struct student), 1, fp);
				if (pr->xuehao == c) {
					printf("输入学生修改的信息：\n");
					printf("输入姓名："); scanf("%c", &p->name);
					printf("输入数学成绩："); scanf("%d", &p->math);
					printf("输入英语成绩："); scanf("%d", &p->english);
					printf("输入计算机导论与程序设计成绩："); scanf("%d", &p->com);
					fseek(fp, -sizeof(struct student), 1);
					fwrite(pr, sizeof(struct student), 1, fp);
					fclose(fp);
					system("cls");
					break;
				}
				p = pr;
				p = pr->next;
			}
			printf("没有找到。");
			fclose(fp);
			break;
		}
		case 3: {
			printf("成绩添加：\n");
			printf("1.添加\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩添加：\n");
			fp = fopen(path, "r+");
			student* head = NULL;
			head = read(fp);
			int i = 0;
			do {
				printf("输入添加的信息：");
				head = inset(head);
				printf("是否继续输入？ 1---是；2---否");
				scanf("%d", i);
			} while (i == 1);
			fclose(fp);
			fopen(path, "w+");
			student* h = NULL;
			h = head;
			while (h != NULL) {
				fwrite(h, sizeof(struct student), 1, fp);
				h = h->next;
			}
			fclose(fp);
			system("cls");
			break;
		}
		case 4: {
			printf("成绩删除：\n");
			printf("1.删除\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩删除：\n");
			fp = fopen(path, "r+");
			student* head = NULL;
			head = read(fp);
			fp = fopen(path, "r+");
			printf("输入需要删除的学生学号：\n");
			int c = 0;
			scanf("%d", &c);
			student* f = NULL, * fk = NULL;
			f = head;


			while (f != NULL && f->xuehao != c) {
				fk = f;
				f = f->next;
			}
			if (f == NULL) {
				printf("无此学生成绩");
				break;
			}
			fk->next = f->next;
			free(f);
			fclose(fp);
			fp = fopen(path, "w+");
			student* h = NULL;
			h = head;
			while (h != NULL) {
				fwrite(h, sizeof(struct student), 1, fp);
				h = h->next;
			}
			fclose(fp);
			system("cls");
			break;
		}
		case 5: {
			printf("成绩查询：\n");
			printf("1.查询\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩查询：\n");
			fp = fopen(path, "r+");
			student* head = NULL;
			head = read(fp);
			int z;
			do {
				printf("输入需要查询的方式：\n");
				printf("1.学号\n2.姓名\n3.成绩查询\n");
				int a;
				scanf("%d", a);
				system("cls");
				switch (a) {
				case 1: {
					student* h = NULL;
					h = head;
					printf("输入该学生的学号：");
					int b;
					scanf("%d", &b);
					while (h != NULL && h->xuehao != b) {
						h = h->next;
					}
					if (h == NULL) {
						printf("没有该学号\n");
					}
					else {
						system("cls");
						printf("该学生的信息为：\n");
						printf("学号：%d\n", h->xuehao);
						printf("姓名：%s\n", h->name);
						printf("数学成绩：%d\n", h->math);
						printf("英语成绩：%d\n", h->english);
						printf("计算机导论与程序设计成绩：%d\n", h->com);
					}
					break;
				}
				case 2: {
					student* h = NULL;
					h = head;
					printf("输入该学生的姓名：");
					char b[20];
					scanf("%s", b);
					while (h != NULL && strcmp(b, h->name) != 0) {
						h = h->next;
					}
					if (h == NULL) {
						printf("没有该姓名\n");
					}
					else {
						printf("该学生的信息为：\n");
						printf("学号：%d\n", h->xuehao);
						printf("姓名：%s\n", h->name);
						printf("数学成绩：%d\n", h->math);
						printf("英语成绩：%d\n", h->english);
						printf("计算机导论与程序设计成绩：%d\n", h->com);
					}
					break;
				}
				case 3: {
					printf("成绩查询：\n");
					printf("选择查询方式：1---各科成绩查询  2---成绩段查询");
					int b;
					scanf("%d", &b);
					system("cls");
					switch (b) {
					case 1: {
						printf("选择查询科目：\n1.数学\n2.英语\n3.计算机导论与程序设计\n");
						int c = getch() - 48;
						switch (c) {
						case 1: {
							student* h = NULL;
							h = head;
							printf("输入该学生的数学成绩：");
							int d;
							scanf("%d", d);
							while (h != NULL && h->math == d) {
								h = h->next;
							}
							if (h == NULL) {
								printf("没有该学生\n");
							}
							else {
								system("cls");
								printf("该学生的信息为：\n");
								printf("学号：%d\n", h->xuehao);
								printf("姓名：%s\n", h->name);
								printf("数学成绩：%d\n", h->math);
								printf("英语成绩：%d\n", h->english);
								printf("计算机导论与程序设计成绩：%d\n", h->com);
							}
							break;
						}
						case 2: {
							student* h = NULL;
							h = head;
							printf("输入该学生的英语成绩：");
							int d;
							scanf("%d", d);
							while (h != NULL && h->english == d) {
								h = h->next;
							}
							if (h == NULL) {
								printf("没有该学生\n");
							}
							else {
								system("cls");
								printf("该学生的信息为：\n");
								printf("学号：%d\n", h->xuehao);
								printf("姓名：%s\n", h->name);
								printf("数学成绩：%d\n", h->math);
								printf("英语成绩：%d\n", h->english);
								printf("计算机导论与程序设计成绩：%d\n", h->com);
							}
							break;
						}
						case 3: {
							student* h = NULL;
							h = head;
							printf("输入该学生的计算机导论与程序设计成绩：");
							int d;
							scanf("%d", d);
							while (h != NULL && h->com == d) {
								h = h->next;
							}
							if (h == NULL) {
								printf("没有该学生\n");
							}
							else {
								system("cls");
								printf("该学生的信息为：\n");
								printf("学号：%d\n", h->xuehao);
								printf("姓名：%s\n", h->name);
								printf("数学成绩：%d\n", h->math);
								printf("英语成绩：%d\n", h->english);
								printf("计算机导论与程序设计成绩：%d\n", h->com);
							}
							break;
						}
						default:printf("输入错误");
						}
						break;
					}

					case 2: {
						student* h = NULL;
						h = head;
						printf("成绩段查询：");
						printf("选择查询科目：\n1.数学\n2.英语\n3.计算机导论与程序设计\n");
						int d = getch() - 48;

						printf("输入查询下限：");
						int b = getch() - 48;
						printf("输入查询上限：");
						int c = getch() - 48;
						switch (d) {
						case 1: {
							int i = 0;
							while (h != NULL) {
								if (h->math >= b && h->math <= c) {
									printf("该学生的信息为：\n");
									printf("学号：%d\n", h->xuehao);
									printf("姓名：%s\n", h->name);
									printf("数学成绩：%d\n", h->math);
									printf("英语成绩：%d\n", h->english);
									printf("计算机导论与程序设计成绩：%d\n", h->com);
									i++;
								}
								h = h->next;
							}
							if (i == 0) {
								printf("没有该学生\n");
							}

							break;
						}
						case 2: {
							int i = 0;
							while (h != NULL) {
								if (h->english >= b && h->english <= c) {
									printf("该学生的信息为：\n");
									printf("学号：%d\n", h->xuehao);
									printf("姓名：%s\n", h->name);
									printf("数学成绩：%d\n", h->math);
									printf("英语成绩：%d\n", h->english);
									printf("计算机导论与程序设计成绩：%d\n", h->com);
									i++;
								}
								h = h->next;
							}
							if (i == 0) {
								printf("没有该学生\n");
							}
							break;
						}
						case 3: {
							int i = 0;
							while (h != NULL) {
								if (h->com >= b && h->com <= c) {
									printf("该学生的信息为：\n");
									printf("学号：%d\n", h->xuehao);
									printf("姓名：%s\n", h->name);
									printf("数学成绩：%d\n", h->math);
									printf("英语成绩：%d\n", h->english);
									printf("计算机导论与程序设计成绩：%d\n", h->com);
									i++;
								}
								h = h->next;
							}
							if (i == 0) {
								printf("没有该学生\n");
							}
							break;
						}
						default: printf("输入错误");
						}
						break;
					}
						  break;
					}
				}
				}
				printf("是否继续查询？  1---是   2---否");
				z = getch() - 48;
			} while (z == 1);
			break;
		}
		case 6: {
			printf("成绩统计：\n");
			printf("1.统计\n");
			printf("2.返回主菜单\n");
			a = getch() - 48;
			if (a == 2) {
				system("cls");
				break;
			};
			system("cls");
			printf("成绩统计：\n");
			fp = fopen(path, "r+");
			student* head = NULL;
			head = read(fp);
			int z;
			do {
				student* h = head;
				printf("输入统计成绩段");
				printf("选择查询科目：\n1.数学\n2.英语\n3.计算机导论与程序设计\n");
				int d = getch() - 48;

				printf("输入查询下限：");
				int b = getch() - 48;
				printf("输入查询上限：");
				int c = getch() - 48;
				switch (d) {
				case 1: {
					int i = 0;
					while (h != NULL) {
						if (h->math >= b && h->math <= c) {
							i++;
						}
						h = h->next;
					}
					printf("共有%d个人", i);

					break;
				}
				case 2: {
					int i = 0;
					while (h != NULL) {
						if (h->english >= b && h->english <= c) {

							i++;
						}
						h = h->next;
					}
					printf("共有%d个人", i);

					break;
				}
				case 3: {
					int i = 0;
					while (h != NULL) {
						if (h->com >= b && h->com <= c) {

							i++;
						}
						h = h->next;
					}
					printf("共有%d个人", i);

					break;
				}
				default: printf("输入错误");
				}
				printf("是否继续输入？  1---是  2---否");
				z = getch() - 48;
			} while (z == 1);
			break;
		}
		case 7: {
			exit(0);
			break;
		}
		}
		system("cls");
	}while (1);
}



student* inset(struct student* head) {
	student* pr;
	pr = head;
	student* p = (struct student*)malloc(sizeof(struct student));
	printf("输入学生信息：\n");
	printf("输入学生学号："); scanf("%d", &p->xuehao);
	printf("输入姓名："); scanf("%s", p->name);
	printf("输入数学成绩："); scanf("%d", &p->math);
	printf("输入英语成绩："); scanf("%d", &p->english);
	printf("输入计算机导论与程序设计成绩："); scanf("%d", &p->com);
	p->next = NULL;
	if (pr == NULL) {
		return p;

	}
	else {
		student* pf;
		pf = pr;
		while (pr->next != NULL) {
			pr = pr->next;
		}
		pr->next = p;
		return pf;
	}
}



student* read(FILE* fp) {
	student* head = NULL;
	student* p = (struct student*)malloc(sizeof(struct student));
	head = p;
	int i;
	while (i != EOF) {
		i = fread(p, sizeof(struct student), 1, fp);
		p = p->next;
		student* p = (struct student*)malloc(sizeof(struct student));
	}
	p = NULL;
	return head;
}