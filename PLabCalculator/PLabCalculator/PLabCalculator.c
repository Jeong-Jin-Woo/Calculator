#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <windows.h>
#include<string.h>


// ���� ����

#define BLACK	0

#define BLUE1	1

#define GREEN1	2

#define CYAN1	3

#define RED1	4

#define MAGENTA1 5

#define YELLOW1	6

#define GRAY1	7

#define GRAY2	8

#define BLUE2	9

#define GREEN2	10	

#define CYAN2	11

#define RED2	12

#define MAGENTA2 13

#define YELLOW2	14

#define WHITE	15

#define MAX_CHAR_PER_LINE	1000

#define MAX_CHAR_PER_LINE 1000

#define MAX_NAME	256

#define FALSE 0

#define TRUE 1

void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void removeCursor(void);
void showCursor(void);
void cls(int bg_color, int text_color);
// box �׸��� �Լ�, ch ���ڷ� (x1,y1) ~ (x2,y2) box�� �׸���.
void draw_box(int x1, int y1, int x2, int y2, char ch);
// box �׸��� �Լ�, ch ���ڿ��� (x1,y1) ~ (x2,y2) box�� �׸���.
// �ѱ� ���ڸ� �׸��� �뵵�� ��� "��" �� ���� �׸��� ���
void draw_box2(int x1, int y1, int x2, int y2, char *ch);
int GetBufferSizeX();
int GetBufferSizeY();
// ���ۻ���������
int SetWindowSize(const int width, const int height);
// ���ۻ���������´�
void print_ui();
void adder();
void PrintCurrentResultNum();
void WriteDoubleData(double result, int nAddResult);
int nIsStartNormalCal = 0;
void Grade();
void OvulationDay();
void AnnualInterest();
void MonthlyPay();
void Magin();
void SimpleInterest();
void ComplexInterest();
void LoanInterest();
//ùȭ��
int main() {
	//system("mode con cols=110 lines=48");
	//cols = ĭ/�� (����)  lines = ��/�� (����)

	char x;
	print_ui();
	showCursor();
	gotoxy(4, 32);
	printf("���ϴ� ��ȣ�� �Է� �� ����Ű�� �����ּ���. >>");
	gotoxy(50, 32);
	scanf("%c", &x);
	system("cls");
	switch (x) {
	case '1':
		adder();
		break;

	case '2':
		Grade();
		break;

	case '3':
		AnnualInterest();
		break;

	case '4':
		OvulationDay();
		break;

	case '5':
		MonthlyPay();
		break;

	case '6':
		Magin();
		break;

	case 'x':
		printf("\n �̿����ּż� �����մϴ�. (_ _)\n\n"); exit(0);
		break;
	default:
		gotoxy(40, 2); printf(" �߸��� �Է��Դϴ�.");
		break;
	}
	main();
}


//ù ȭ��
void print_ui() {

	gotoxy(15, 2);
	printf(" :: ���� :: ");
	gotoxy(4, 3); printf("************************************");
	gotoxy(12, 5);printf("�� �Ϲ� ����");
	gotoxy(4, 7); printf("------------------------------------");
	gotoxy(12, 9);printf("�� ���� ����");
	gotoxy(4, 11); printf("-----------------------------------");
	gotoxy(12, 13);printf("�� ������ ����");
	gotoxy(4, 15); printf("-----------------------------------");
	gotoxy(12, 17);printf("�� ���� ����� ����");
	gotoxy(4, 19); printf("-----------------------------------");
	gotoxy(12, 21);printf("�� ���� ����");
	gotoxy(4, 23); printf("-----------------------------------");
	gotoxy(12, 25);printf("�� ������ ����");
	gotoxy(4, 27); printf("-----------------------------------");
	gotoxy(12, 29);printf("�� �� �� �� ��");

	draw_box2(4, 1, 39, 31, "*");
}
void adder() {
	int clock = 1;
	while (clock) {

		char op;
		double x, y;
		double result;
		char re;
		char C;
		
		gotoxy(19, 2);
		printf(":: �Ϲ� ���� ::");

		draw_box2(4, 22, 50, 26, "-");
		draw_box2(20, 3, 35, 11, "|");
		draw_box2(27, 11, 50, 15, "|");
		draw_box2(4, 7, 50, 11, "-");
		draw_box2(4, 1, 50, 15, "*");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 24, 50, 26, "~");
		draw_box2(4, 1, 50, 26, "*");
		gotoxy(8, 5);printf("+ (����)");
		gotoxy(24, 5);printf("- (����)");
		gotoxy(39, 5);printf("+ (����)");
		gotoxy(8, 9);printf("/ (������)");
		gotoxy(24, 9);printf("%% (������)");
		gotoxy(39, 9);printf("^ (����)");
		gotoxy(9, 13);printf("C (��� �ʱ�ȭ)");
		gotoxy(32, 13);printf("�� (���ư���)");
		gotoxy(4, 29);printf("���� ȭ������ ���ư��� �ʹٸ� ��Ű�� �Է��ϼ���.");
		gotoxy(4, 30);printf("���ư��� ���� �ʴٸ� �ƹ�Ű�� �Է� >>");
		re = "";
		getchar();
		gotoxy(42, 30);scanf("%c", &re);
		if (re == 'r') {
			system("cls");
			clock = 0;
			main();
		}
		x = 0;
		op = "";
		y = 0;
		getchar();
		gotoxy(6, 17);
		scanf("%lf %c %lf", &x, &op, &y);

		if (op == '+') {
			result = 0;
			result = x + y;
		}
		else if (op == "-") {
			result = 0;
			result = x - y;
		}
		else if (op == '*') {
			result = 1;
			result = x * y;
		}
		else if (op == '/') {
			result = 1;
			result = x / y;
		}
		else if (op == '%') {
			result = 1;
			result = (int)x % (int)y;
		}
		else if (op == '^') {
			result = 1;
			result = pow(x, y);
		}
		else {
			result = 0;
			x, y = 0;
			clock = 0;
			gotoxy(25, 22);printf("�ٽ� �Է�\n");
			system("cls");
			adder();
		}
		gotoxy(6, 23);printf("= %.3lf", result);

		//���� I/O result���� ���� -> add() UI������ result.txt ������ �о�ͼ� ���������ְ�
		//���� �ϴܿ� result�� ��� ���Ѱ� ���. add()���⸦ ������ c��ư ������ �۵�.
		
		WriteDoubleData(result, 1);
		/*
		FILE *f;
		int dec, sign;
		char *pResult;
		f = fopen("..\\result.txt", "a");
		double nResult = 0;
		nResult = result;
		fprintf(f,"%.3lf",nResult);
		fprintf(f, ",");
		
		//pResult = ecvt(result, 1, &dec, &sign);
		int nResult = 0;
		nResult = result;
		//scanf_s("%c", pResult, nResult);
		itoa(nResult, &pResult, 10);

		fprintf(f, pResult);
		
		fclose(f);*/
	
		getch();
		system("cls");
		//���� i/o���
		PrintCurrentResultNum();
		/*
		f = fopen(".\\result.txt", "r");
		fscanf(f, "%.3lf", &nResult);   //scan�� �������ּҸ� ã���Ƿ� &�� �ٿ����Ѵ�
		
		fclose(f);
		
		gotoxy(6,25);printf("%.3lf", nResult);
		*/
		gotoxy(19, 2);
		printf(":: �Ϲ� ���� ::");

		draw_box2(4, 22, 50, 26, "-");
		draw_box2(20, 3, 35, 11, "|");
		draw_box2(27, 11, 50, 15, "|");
		draw_box2(4, 7, 50, 11, "-");
		draw_box2(4, 1, 50, 15, "*");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 24, 50, 26, "~");
		draw_box2(4, 1, 50, 26, "*");
		gotoxy(8, 5);printf("+ (����)");
		gotoxy(24, 5);printf("- (����)");
		gotoxy(39, 5);printf("+ (����)");
		gotoxy(8, 9);printf("/ (������)");
		gotoxy(24, 9);printf("%% (������)");
		gotoxy(39, 9);printf("^ (����)");
		gotoxy(9, 13);printf("C (��� �ʱ�ȭ)");
		gotoxy(32, 13);printf("�� (���ư���)");
		gotoxy(4, 29);printf("���� ȭ������ ���ư��� �ʹٸ� ��Ű�� �Է��ϼ���.");
		gotoxy(4, 30);printf("���ư��� ���� �ʴٸ� �ƹ�Ű�� �Է� >>");
		if (nIsStartNormalCal != 0)
		{
			getchar();
			gotoxy(54, 25);printf("��� �ʱ�ȭ�� �ϰ� ������ ��Ű�� �Է� >>");
			gotoxy(95, 25);scanf("%c", &C);
			if (C == 'C' || C == 'c') {
				FILE *f;
				f = fopen("..\\result.txt", "w");
				fprintf(f, "");
				system("cls");
			}
		}nIsStartNormalCal = 1;
	}
}

void WriteDoubleData(double result, int nAddResult) // 0�̸� ","�� ����´�
{
	FILE *f;
	int dec, sign;
	char *pResult;
	f = fopen("..\\result.txt", "a");
	double nResult = 0;
	nResult = result;

	if(result == 9999)
		fprintf(f, "");
	else
	{
		fprintf(f, "%.3lf", nResult);
		if (nAddResult == 1)
			fprintf(f, ",");
	}
	fclose(f);
}

void PrintCurrentResultNum()
{
	FILE *rf = fopen("..\\result.txt", "r");

	char line[256];
	char ret[] = ",";
	char *tok = NULL;

	char *total;
	double dTotal = 0;
	fgets(line, sizeof(line), rf);
	tok = strtok(line, ret);
	while (tok != NULL)
	{
		dTotal += atof(tok);

		tok = strtok(NULL, ret);
	}

	gotoxy(6, 25);printf("%.3lf", dTotal);
}

void Grade() {
	char r;
	int clock = 1;
	char select = 'x';
	int LessonScore;
	int LessonScore1;
	char Score[10];
	char LessonName[100];
	int LessonScoreSum = 0;
	double intScore = 0;
	double ScoreSum = 0;
	double total = 0;
	int lessonNum = 0;
	int res, ox;
	while (clock) {
		res = 1;
		ox = 1;
		gotoxy(32, 2);
		printf("::�� ���� ����::");
		gotoxy(63, 5);printf("���");
		gotoxy(7, 5);printf("���� ���� ��:");
		gotoxy(7, 7);printf("����");
		gotoxy(20, 7);printf("����");
		gotoxy(33, 7);printf("�����");

		draw_box2(4, 1, 80, 30, "*");
		draw_box2(50, 3, 80, 7, "-");
		draw_box2(4, 3, 80, 30, "*");
		draw_box2(50, 3, 80, 30, "*");
		if (select == 'x' || select == 'X') {
			getchar();
			gotoxy(26, 31); printf("�ؾణ�� ������ ���� �� �ֽ��ϴ�.");
			gotoxy(10, 34); printf("���� ȭ������ ���ư��� �ʹٸ� ��Ű �Է�");
			gotoxy(10, 35); printf("�ƴ϶�� �ƹ�Ű�� �Է� >>");
			gotoxy(35, 35);scanf("%c", &r);
			if (r == 'r') {
				clock = 0;
				system("cls");
				main();
			}
		}
		LessonScore = 0;
		for (int i = 0;i < 10;i++)
			Score[10] = "";
		for (int i = 0; i < 100; i++)
			LessonName[100] = "";
		getchar();
		gotoxy(21, 5);scanf("%d", &lessonNum);
		for (int i = 0; i < lessonNum; i++) {
			gotoxy(7, 8 + i);scanf("%d", &LessonScore);
			LessonScore1 = LessonScore;
			getchar();
			LessonScoreSum += LessonScore;
			gotoxy(20, 8 + i);scanf("%s", Score);
			while (ox) {
				if (strcmp(Score, "A+") == 0 || strcmp(Score, "a+") == 0) {
					intScore = 4.5;
					ox = 0;
				}
				else if (strcmp(Score, "A0") == 0 || strcmp(Score, "A") == 0
					|| strcmp(Score, "a0") == 0 || strcmp(Score, "a") == 0) {
					intScore = 4;
					ox = 0;
				}
				else if (strcmp(Score, "B+") == 0 || strcmp(Score, "b+") == 0) {
					intScore = 3.5;
					ox = 0;
				}
				else if (strcmp(Score, "B0") == 0 || strcmp(Score, "B") == 0
					|| strcmp(Score, "b0") == 0 || strcmp(Score, "b") == 0) {
					intScore = 3;
					ox = 0;
				}
				else if (strcmp(Score, "C+") == 0 || strcmp(Score, "c+") == 0) {
					intScore = 2.5;
					ox = 0;
				}
				else if (strcmp(Score, "C0") == 0 || strcmp(Score, "C") == 0
					|| strcmp(Score, "c0") == 0 || strcmp(Score, "c") == 0) {
					intScore = 2;
					ox = 0;
				}
				else if (strcmp(Score, "D+") == 0 || strcmp(Score, "d+") == 0) {
					intScore = 1.5;
					ox = 0;
				}
				else if (strcmp(Score, "D0") == 0 || strcmp(Score, "D") == 0
					|| strcmp(Score, "d0") == 0 || strcmp(Score, "d") == 0) {
					intScore = 1;
					ox = 0;
				}
				else if (strcmp(Score, "F") == 0 || strcmp(Score, "f") == 0) {
					intScore = 0;
					ox = 0;
				}
				else {
					gotoxy(17, 6);printf("�ٽ� �Է�");
					gotoxy(20, 8 + i);scanf("%s", Score);
				}
			}ox = 1;
			total += LessonScore1 * intScore;
			getchar();
			gotoxy(33, 8 + i);scanf("%s", LessonName);
			getchar();
		}
		//gotoxy(21,5);scanf("%d", lessonNum);

		gotoxy(53, 12);printf("��� ���� :     %d", LessonScoreSum);
		gotoxy(53, 16);printf("���� �Ѱ� :     %.1lf", total);
		gotoxy(53, 20);printf("��� ���� :     %.2lf", total / LessonScoreSum);
		gotoxy(13, 32);printf("�̾ �����б������ ������ �Է��Ͻðڽ��ϱ�?(�ʱ�ȭ x) (O/X) >>");
		gotoxy(79, 32);scanf("%c", &select);
		while (res)
			switch (select) {
			case 'o':
			case 'O':
				res = 0;
				break;
			case 'x':
			case 'X':
				LessonScoreSum = 0;
				intScore = 0;
				ScoreSum = 0;
				total = 0;
				lessonNum = 0;
				res = 0;
				break;
			default:
				gotoxy(77, 33);printf("�ٽ� �Է�");
				gotoxy(79, 32);scanf("%c", &select);
			}
		system("cls");
	}
}


void OvulationDay() {
	int clock = 1;
	char select;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (clock) {

		int PariodMonth = 0;
		int PariodYear = 0;
		int PariodDay = 0;
		int OvalMonth = 0;
		int OvalYear = 0;
		int OvalDay = 0;
		int Pariod = 0;
		int Oval = 0;
		int Year = 0;
		int Day = 0;
		int Month = 0;
		int TimeSet = 0;
		gotoxy(7, 0);printf("�ذ����� ������ ���� �� �ֽ��ϴ�.(1�⵿�� ���� �ֱⰡ ��Ģ���̾�߸� ������ ���� �� ����)");
		gotoxy(40, 2);
		printf("::�꿩�� ����� ����::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 70, 7, ".");
		draw_box2(72, 5, 98, 7, ".");
		gotoxy(6, 4);printf("�ֱ� ������");
		gotoxy(8, 6);printf("�⵵ : ");
		gotoxy(30, 6);printf("�� : ");
		gotoxy(50, 6);printf("��¥ : ");
		gotoxy(75, 6);printf("���� �ֱ� : ");

		gotoxy(4, 10);printf("�ب��� �Է��ϸ� ����ȭ������ ���ư��ϴ�. Enter�� ������ ����� ��� �����մϴ�. >>");
		getchar();
		gotoxy(87, 10);scanf("%c", &select);
		if (select == 'r') {
			system("cls");
			main();
		}

		//�����ֱ� , ��¥ �� �� �Է�      ���� �ּ��� ������ ���� ��������.
		gotoxy(16, 6);scanf("%d", &Year);
		if ((Year % 4 == 0) && ((Year % 100 != 0) || (Year % 400 == 0)))//���� �Ǵ� 
		{
			days[1] = 29;//2������ �� ���� 29�� ���� 
		}
		while (1) {
			getchar();
			gotoxy(36, 6);scanf("%d", &Month);
			if (Month < 1 || Month >12) {
				gotoxy(33, 8);printf("�ٽ� �Է�");
			}
			else break;
		}
		while (1) {
			getchar();
			gotoxy(58, 6);scanf("%d", &Day);
			if (Day > days[Month - 1] || Day < 1) {
				gotoxy(55, 8);printf("�ٽ� �Է�");
			}
			else break;
		}
		while (1) {
			getchar();
			gotoxy(88, 6);scanf("%d", &TimeSet);
			if (TimeSet < 21 || TimeSet>40) {
				gotoxy(74, 8);printf("�������� �����ֱ� : 21~40");
			}
			else break;
		}
		//��� ���
		draw_box2(4, 11, 100, 33, "-");
		draw_box2(4, 11, 100, 33, "-");
		draw_box2(4, 11, 100, 33, "-");
		draw_box2(4, 11, 100, 33, "-");
		draw_box2(4, 11, 100, 33, "-");
		draw_box2(13, 13, 23, 33, "|");
		draw_box2(53, 13, 100, 33, "|");
		draw_box2(4, 15, 100, 31, "-");
		draw_box2(4, 17, 100, 29, "-");
		draw_box2(4, 19, 100, 27, "-");
		draw_box2(4, 21, 100, 25, "-");
		draw_box2(4, 23, 100, 23, "-"); //���� ��� ĭ
		draw_box2(13, 11, 23, 13, "*");
		draw_box2(53, 11, 100, 13, "*");
		draw_box2(4, 11, 100, 13, "*");
		draw_box2(4, 11, 100, 33, "*");

		gotoxy(6, 12);printf("�� ��");
		gotoxy(16, 12);printf("�� ��");
		gotoxy(36, 12);printf("�� ��");
		gotoxy(72, 12);printf("�� �� �� ��");

		gotoxy(6, 14);printf("�����");
		gotoxy(6, 16);printf("����");
		gotoxy(6, 18);printf("�����");
		gotoxy(6, 20);printf("����");
		gotoxy(6, 22);printf("�����");
		gotoxy(6, 24);printf("����");
		gotoxy(6, 26);printf("�����");
		gotoxy(6, 28);printf("����");
		gotoxy(6, 30);printf("�����");
		gotoxy(6, 32);printf("����");
		//��� ���
		PariodMonth = Month;
		PariodYear = Year;
		PariodDay = Day;
		OvalMonth = Month;
		OvalYear = Year;
		OvalDay = Day;
		for (int i = 14;i <= 32;i += 2) {
			gotoxy(17, i);printf("%d", TimeSet);
		}
		//��� �˰��� �⵵ , �������ڴ� ����ϸ鼭 ����ؾ���.   1/1
		PariodDay = Day;// 31 
						/*
		if (PariodDay > days[PariodMonth - 1]) {  //31 > 31
			PariodDay = PariodDay - days[PariodMonth - 1];
		}
		if (PariodDay == days[PariodMonth - 1]) //31 == 31
			PariodDay = 1;*/ //1
		for (int i = 0;i < 20;i += 4) {
			PariodDay += TimeSet; //31
			while (1) {
				if (PariodDay > days[PariodMonth - 1]) { //31 > 31
					PariodDay = PariodDay - days[PariodMonth - 1];
					PariodMonth++; //2
				}
				else break;
				if (PariodMonth > 12) {
					PariodMonth = 1;
					PariodYear++;
				}
			}
			gotoxy(32, 16 + i);printf("%d �� %02d ��", PariodYear, PariodMonth);
			gotoxy(58, 16 + i);printf("%d / %02d / %02d", PariodYear, PariodMonth, PariodDay);
		}
		int PariodDay2 = 0;
		PariodMonth = Month;
		PariodYear = Year;
		PariodDay = Day;
		PariodDay2 = Day + 2;// 31 
						 /*
						 if (PariodDay > days[PariodMonth - 1]) {  //31 > 31
						 PariodDay = PariodDay - days[PariodMonth - 1];
						 }
						 if (PariodDay == days[PariodMonth - 1]) //31 == 31
						 PariodDay = 1;*/ //1
		for (int i = 0;i < 20;i += 4) {
			PariodDay2 += TimeSet; //31
			while (1) {
				if (PariodDay2 > days[PariodMonth - 1]) { //31 > 31
					PariodDay2 = PariodDay2 - days[PariodMonth - 1];
					PariodMonth++; //2
				}
				else break;
				if (PariodMonth > 12) {
					PariodMonth = 1;
					PariodYear++;
				}
			}
			gotoxy(76, 16 + i);printf("~     %d / %02d / %02d", PariodYear, PariodMonth, PariodDay2);
		}
		OvalDay = Day - 16;/*
		if (OvalDay > days[OvalMonth - 1]) {
			OvalDay = OvalDay - days[OvalMonth - 1];
		}
		if (OvalDay == days[OvalMonth - 1])
			OvalDay = 1;*/
		for (int i = 0;i < 20;i += 4) {
			OvalDay = TimeSet + OvalDay;
			while (1) {
				if (OvalDay > days[OvalMonth - 1]) {
					OvalDay = OvalDay - days[OvalMonth - 1];
					OvalMonth++;
				}
				else break;

				if (OvalMonth > 12) {
					OvalYear++;
					OvalMonth = 1;
				}
			}
			gotoxy(32, 14 + i);printf("%d �� %02d ��", OvalYear, OvalMonth);
			gotoxy(58, 14 + i);printf("%d / %02d / %02d", OvalYear, OvalMonth, OvalDay);
		}
		int OvalDay2 = 0;
		OvalMonth = Month;
		OvalYear = Year;
		OvalDay = Day;
		OvalDay2 = Day - 12;
		for (int i = 0;i < 20;i += 4) {
			OvalDay2 = TimeSet + OvalDay2;
			while (1) {
				if (OvalDay2 > days[OvalMonth - 1]) {
					OvalDay2 = OvalDay2 - days[OvalMonth - 1];
					OvalMonth++;
				}
				else break;

				if (OvalMonth > 12) {
					OvalYear++;
					OvalMonth = 1;
				}
			}
			gotoxy(76, 14 + i);printf("~     %d / %02d / %02d", OvalYear, OvalMonth, OvalDay2);
		}
		getch();
		system("cls");
	}
}

void AnnualInterest() {
	int clock = 1;
	char select;
	getchar();
	while (clock) {
		gotoxy(20, 2);printf(":: ���� ���� ::");
		gotoxy(15, 5);printf("�� �ܸ� ���� ���� ����");
		gotoxy(15, 9);printf("�� ������ ���� ���� ����");
		gotoxy(15, 13);printf("�� ���� ���� ����");
		draw_box2(4, 1, 50, 7, "-");
		draw_box2(4, 1, 50, 11, "-");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 1, 50, 15, "*");
		gotoxy(4, 17);printf("���ϴ� ������ ��ȣ�� �Է� �� ����Ű�� �����ּ���.");
		gotoxy(4, 18);printf("( �ب��� �Է��ϸ� ����ȭ������ ���ư��ϴ�. ) >>");
		gotoxy(52, 18);scanf("%c", &select);
		system("cls");
		switch (select) {
		case '1':
			SimpleInterest();
			break;
		case '2':
			ComplexInterest();
			break;
		case '3':
			LoanInterest();
			break;
		case 'r':
			clock = 0;
			main();
			break;
		default:
			break;
		}
	}
}
void SimpleInterest() {
	char sel;
	while (1) {
		double MoneyAmount = 0;
		double DepositTime = 0;
		double Rate = 0;
		double Interest = 0;
		//�Է¹��� ����ȭ��
		gotoxy(40, 2);printf("::�ܸ� ���� ���� ����::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("��ġ�ݾ�(��) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("���ݱⰣ(��) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("������(%%) : ");

		getchar();
		gotoxy(4, 11);printf("( �ب��� �Է��ϸ� ����ȭ������ ���ư��ϴ�. ) >>");
		gotoxy(4, 10);printf("��Enter�� ������ ���� �Է��ϸ� ���� ���ɾ��� �� �� �ֽ��ϴ�.");
		gotoxy(53, 11);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//�Է¹�����
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(70, 5);scanf("%lf", &DepositTime);
		gotoxy(91, 5);scanf("%lf", &Rate);

		//���
		Interest = MoneyAmount * (Rate / 100) * DepositTime;
		//��� ���
		draw_box2(4, 17, 100, 20, "-");
		draw_box2(4, 14, 100, 23, "*");
		draw_box2(59, 14, 76, 20, "*");
		draw_box2(4, 17, 20, 20, "*");
		draw_box2(59, 17, 76, 20, "*");
		draw_box2(4, 14, 20, 23, "*");
		draw_box2(4, 25, 100, 36, "*");
		gotoxy(7, 15);printf("�� ġ �� ��");
		gotoxy(7, 18);printf("�� �� �� ��");
		gotoxy(7, 21);printf("�� �� �� ��");
		gotoxy(62, 15);printf("�� ġ �� ��");
		gotoxy(61, 18);printf("���� ��� ���");
		gotoxy(24, 15);printf("%.0lf��", MoneyAmount);
		gotoxy(24, 18);printf("�� %.2lf%%", Rate);
		gotoxy(24, 21);printf("%0.lf��", Interest);
		gotoxy(79, 15);printf("%0.lf��", DepositTime);
		gotoxy(79, 18);printf("�ܸ�");
		draw_box2(57, 25, 100, 36, "|");
		draw_box2(4, 30, 100, 33, "-");
		draw_box2(4, 30, 21, 33, "*");
		draw_box2(57, 25, 100, 27, "*");
		draw_box2(4, 25, 100, 36, "*");
		draw_box2(4, 25, 100, 27, "*");
		draw_box2(4, 25, 21, 36, "*");
		gotoxy(8, 26);printf("�� �� �� ��");
		gotoxy(8, 28);printf("�� �� �� ��");
		gotoxy(8, 31);printf("�� �� ��");
		gotoxy(8, 34);printf("�� �� �� ��");
		gotoxy(5, 35);printf("(��뼼��(9.5%%))");
		gotoxy(32, 26);printf("�� �� �� �� ��");
		gotoxy(73, 26);printf("�� �� �� ��");

		gotoxy(75, 28);printf("%0.lf��", Interest - Interest * 0.154);
		gotoxy(75, 31);printf("%0.lf��", Interest);
		gotoxy(75, 34);printf("%0.lf��", Interest - Interest * 0.095);

		gotoxy(33, 28);printf("%0.lf��", MoneyAmount + (Interest - Interest * 0.154));
		gotoxy(33, 31);printf("%0.lf��", MoneyAmount + Interest);
		gotoxy(33, 34);printf("%0.lf��", MoneyAmount + (Interest - Interest * 0.095));
		getch();
		system("cls");
	}
}
void ComplexInterest() {
	char sel;
	while (1) {
		double MoneyAmount = 0;
		double DepositTime = 0;
		double Rate = 0;
		double Interest = 0;
		//�Է¹��� ����ȭ��
		gotoxy(40, 2);printf("::������ ���� ���� ����::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("��ġ�ݾ�(��) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("���ݱⰣ(����) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("������(%%) : ");

		getchar();
		gotoxy(4, 11);printf("( �ب��� �Է��ϸ� ����ȭ������ ���ư��ϴ�. ) >>");
		gotoxy(4, 10);printf("��Enter�� ������ ���� �Է��ϸ� ���� ���ɾ��� �� �� �ֽ��ϴ�.");
		gotoxy(53, 11);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//�Է¹�����
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(71, 5);scanf("%lf", &DepositTime);
		gotoxy(93, 5);scanf("%lf", &Rate);

		//���
		Interest = MoneyAmount * pow((1. + Rate / 100 / 12), 12 * DepositTime / 12) - MoneyAmount;
		//��� ���
		draw_box2(4, 17, 100, 20, "-");
		draw_box2(4, 14, 100, 23, "*");
		draw_box2(59, 14, 76, 20, "*");
		draw_box2(4, 17, 20, 20, "*");
		draw_box2(59, 17, 76, 20, "*");
		draw_box2(4, 14, 20, 23, "*");
		draw_box2(4, 25, 100, 36, "*");
		gotoxy(7, 15);printf("�� ġ �� ��");
		gotoxy(7, 18);printf("�� �� �� ��");
		gotoxy(7, 21);printf("�� �� �� ��");
		gotoxy(62, 15);printf("�� ġ �� ��");
		gotoxy(61, 18);printf("���� ��� ���");
		gotoxy(24, 15);printf("%0.lf��", MoneyAmount);
		gotoxy(24, 18);printf("�� %.2lf%%", Rate);
		gotoxy(24, 21);printf("%.0lf��", Interest);
		gotoxy(79, 15);printf("%.0lf����", DepositTime);
		gotoxy(79, 18);printf("������");
		draw_box2(57, 25, 100, 36, "|");
		draw_box2(4, 30, 100, 33, "-");
		draw_box2(4, 30, 21, 33, "*");
		draw_box2(57, 25, 100, 27, "*");
		draw_box2(4, 25, 100, 36, "*");
		draw_box2(4, 25, 100, 27, "*");
		draw_box2(4, 25, 21, 36, "*");
		gotoxy(8, 26);printf("�� �� �� ��");
		gotoxy(8, 28);printf("�� �� �� ��");
		gotoxy(8, 31);printf("�� �� ��");
		gotoxy(8, 34);printf("�� �� �� ��");
		gotoxy(5, 35);printf("(��뼼��(9.5%%))");
		gotoxy(32, 26);printf("�� �� �� �� ��");
		gotoxy(73, 26);printf("�� �� �� ��");

		gotoxy(75, 28);printf("%0.lf��", Interest - Interest * 0.154);
		gotoxy(75, 31);printf("%0.lf��", Interest);
		gotoxy(75, 34);printf("%0.lf��", Interest - Interest * 0.095);

		gotoxy(33, 28);printf("%0.lf��", MoneyAmount + (Interest - Interest * 0.154));
		gotoxy(33, 31);printf("%0.lf��", MoneyAmount + Interest);
		gotoxy(33, 34);printf("%0.lf��", MoneyAmount + (Interest - Interest * 0.095));
		getch();
		system("cls");
	}
}
void LoanInterest() {
	char sel;
	while (1) {
		int i = 0;
		int Case = 0;
		double MoneyAmount = 0;
		double LoanTime = 0;
		double Rate = 0;
		double Interest = 0;
		double sameAmount = 0;
		double LoanAmount = 0;
		double MoneyAmount2 = 0;
		//�Է¹��� ����ȭ��
		gotoxy(40, 2);printf("::���� ���� ����::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("����ݾ�(��) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("����Ⱓ(����) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("��������(%%) : ");
		gotoxy(53, 8);printf("�����ݱյ�:1, ���ݱյ�:2, �����Ͻ�:3 >>");
		getchar();
		gotoxy(4, 12);printf("( �ب��� �Է��ϸ� ����ȭ������ ���ư��ϴ�. ) >>");
		gotoxy(4, 11);printf("��Enter�� ������ ���� �Է��ϸ� ��ȯ���� �� �� �ֽ��ϴ�.");
		gotoxy(53, 12);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//�Է¹�����
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(72, 5);scanf("%lf", &LoanTime);
		gotoxy(93, 5);scanf("%lf", &Rate);
		gotoxy(94, 8);scanf("%d", &Case);
		switch (Case) {
		case 1:
			//�˰���
			sameAmount = (MoneyAmount *(Rate / 100 / 12)* pow((1 + Rate / 100 / 12), LoanTime)) / ((pow((1 + Rate / 100 / 12), LoanTime)) - 1);
			i = 0;
			draw_box2(4, 14, 100, 16, "*");
			draw_box2(4, 16, 100, 18, "*");
			draw_box2(15, 16, 35, 18, "*");
			draw_box2(54, 16, 71, 18, "*");
			gotoxy(6, 15);printf("���� ��ȯ�ݰ� �����ܱ� ( �����ݱյ��ȯ )");
			gotoxy(8, 17);printf("ȸ��");
			gotoxy(21, 17);printf("���Կ���");
			gotoxy(41, 17);printf("��������");
			gotoxy(59, 17);printf("����ȯ��");
			gotoxy(82, 17);printf("�����ܱ�");
			for (i = 2;i <= LoanTime * 2;i += 2) {
				gotoxy(8, 17 + i);printf("%d", i / 2);
				gotoxy(59, 17 + i);printf("%.0lf", sameAmount);
				LoanAmount = MoneyAmount * Rate / 100 / 12;
				gotoxy(41, 17 + i);printf("%.0lf", LoanAmount);
				gotoxy(21, 17 + i);printf("%.0lf", sameAmount - (MoneyAmount * Rate / 100 / 12));
				MoneyAmount -= sameAmount;
				MoneyAmount += LoanAmount;
				gotoxy(82, 17 + i);printf("%.0lf", MoneyAmount);	
				gotoxy(4, 18 + i);printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

			}
			draw_box2(4, 14, 100, 16 + i, "*");
			getch();
			system("cls");
			break;
		case 2:
			//�˰���
			MoneyAmount2 = MoneyAmount;
			i = 0;
			draw_box2(4, 14, 100, 16, "*");
			draw_box2(4, 16, 100, 18, "*");
			draw_box2(15, 16, 35, 18, "*");
			draw_box2(54, 16, 71, 18, "*");
			gotoxy(6, 15);printf("���� ��ȯ�ݰ� �����ܱ� ( ���ݱյ��ȯ )");
			gotoxy(8, 17);printf("ȸ��");
			gotoxy(21, 17);printf("���Կ���");
			gotoxy(41, 17);printf("��������");
			gotoxy(59, 17);printf("����ȯ��");
			gotoxy(82, 17);printf("�����ܱ�");
			for (i = 2;i <= LoanTime * 2;i += 2) {
				gotoxy(8, 17 + i);printf("%d", i / 2);
				sameAmount = MoneyAmount / LoanTime;
				gotoxy(21, 17 + i);printf("%.0lf", sameAmount);
				LoanAmount = MoneyAmount2 * Rate / 100 / 12;
				gotoxy(41, 17 + i);printf("%.0lf",LoanAmount);
				gotoxy(59, 17 + i);printf("%.0lf", (MoneyAmount / LoanTime) + LoanAmount);
				MoneyAmount2 -= sameAmount;
				gotoxy(82, 17 + i);printf("%.0lf", MoneyAmount2);
				gotoxy(4, 18 + i);printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			}
			draw_box2(4, 14, 100, 16 + i, "*");
			getch();
			system("cls");
			break;
		case 3:
			draw_box2(38, 16, 62, 22, "|");
			draw_box2(38, 16, 62, 18, "*");
			draw_box2(4, 14, 100, 18, "*");
			draw_box2(4, 14, 100, 22, "*");
			draw_box2(4, 16, 100, 22, "*");
			gotoxy(7, 15);printf("�����Ͻû�ȯ");
			gotoxy(18, 17);printf("�������");
			gotoxy(45, 17);printf("�Ѵ�������");
			gotoxy(75, 17);printf("�ѻ�ȯ�ݾ�");

			gotoxy(18, 20);printf("%0.lf��",MoneyAmount);
			Interest = MoneyAmount * Rate / 100 / 12 * LoanTime;
			gotoxy(47, 20);printf("%0.lf��",Interest);
			gotoxy(75, 20);printf("%0.lf��", MoneyAmount + Interest);
			getch();
			system("cls");
			break;
		default:
			break;
		}
	}

}
void MonthlyPay() {
	char op;
	int FamilyNum;
	int NonTaxAmount;
	int MoneyOfMonth;
	double PensionOfPeople=0;
	double HealthyInsurance=0;
	double LongtermCare=0;
	double EmploymentInsurance=0;
	double IncomeTax=0;
	double LocalIncomeTax=0;
	double taxtotal = 0;
	double total = 0;
	int smallMoney=0;
	while (1) {
		gotoxy(45, 2);printf("::�� ���� ����::");
		draw_box2(4, 3, 60, 17, "-");
		draw_box2(60, 3, 100, 31, "*");
		draw_box2(60, 3, 100, 5, "-");
		draw_box2(60, 3, 100, 9, "*");
		draw_box2(4, 3, 100, 31, "*");
		draw_box2(4, 1, 100, 31, "*");
		draw_box2(20, 10, 49, 12, "$");
		draw_box2(20, 10, 49, 12, "$");
		draw_box2(20, 21, 49, 23, ".");
		draw_box2(20, 26, 49, 28, ".");
		gotoxy(9, 5);printf("�޿� ���� : ����");
		gotoxy(20, 9);printf("����");
		gotoxy(45, 11);printf("(��)");
		gotoxy(20, 20);printf("�ξ� ���� ��(��������)");
		gotoxy(20, 25);printf("�������");
		gotoxy(45, 27);printf("(��)");
		gotoxy(45, 22);printf("(��)");
		gotoxy(17, 29);printf("�غ�������� 100,000���� �ִ��Դϴ�.");
		gotoxy(72, 4);printf("�� ���� �Ǽ��ɾ�");
		gotoxy(5, 32);printf("�ب��� ������ ����ȭ������ ���ư��ϴ�.");
		gotoxy(5, 33);printf("��Enter�� ������ ���� �Է��ϸ� ���� �Ǽ��ɾ��� �� �� �ֽ��ϴ�.>>");
		getchar();
		gotoxy(70, 33);scanf("%c", &op);
		if (op == 'r') {
			system("cls");
			main();
		}
		while (1) {
			gotoxy(30, 11);scanf("%d", &MoneyOfMonth);
				if (MoneyOfMonth < 870000 || MoneyOfMonth >1000000000) {
				gotoxy(8, 13);printf("���� 87���� �̻� 10�� ������ ��쿡 �Է°����մϴ�.");
				getchar();
			}
			else break;
		}
		gotoxy(41, 22);scanf("%d", &FamilyNum);
		gotoxy(37, 27);scanf("%d", &NonTaxAmount);
		if (NonTaxAmount >= 100000) {
			NonTaxAmount = 100000;
		}
		smallMoney = (MoneyOfMonth - NonTaxAmount) / 1000;
		/*
		char file_buffer[2048];
		FILE * file = fopen("..\\db.csv", "rt");
		if (file == NULL)
			printf("����");
		else {
			while (!feof(file_buffer)) {
				fgets(file_buffer, sizeof(file_buffer), file);
				printf(file_buffer);
			}
		}
		printf("data[%s]", file_buffer);
		fclose(file);
		printf("\n");
		getch();
		*/
		int nMoney1, nMoney2, nFam1, nFam2, nFam3, nFam4, nFam5, nFam6, nFam7,
			nFam8, nFam9, nFam10, nFam11, nMoneyCount = 0;
		FILE *rf = fopen("..\\db.csv", "rt");

		char line[256];
		char ret[] = "\t\n";
		char *tok = NULL;

		char token2[] = ",";
		int lineCount = 0;
		while (!feof(rf))
		{
			nMoneyCount = 0;
			lineCount++;
			fgets(line, sizeof(line), rf);
			tok = strtok(line, ret);

			// �Էµ� ���ް��� nMoney1, nMoney2�� ���Ͽ� ���ǿ� ������
			// ������������� 1���̸� nFam1, 2���̸� nFam2......
			// ��ū�� �и�
			tok = strtok(line, token2);
			while (tok != NULL)
			{
				// ��ū�� �����Ͽ� ���ϴ� ��ƾ
				if (nMoneyCount == 0)
				{
					nMoney1 = atoi(tok);
				}
				else if (nMoneyCount == 1)
					nMoney2 = atoi(tok);
				else if (nMoneyCount == 2) nFam1 = atoi(tok);
				else if (nMoneyCount == 3) nFam2 = atoi(tok);
				else if (nMoneyCount == 4) nFam3 = atoi(tok);
				else if (nMoneyCount == 5) nFam4 = atoi(tok);
				else if (nMoneyCount == 6) nFam5 = atoi(tok);
				else if (nMoneyCount == 7) nFam6 = atoi(tok);
				else if (nMoneyCount == 8) nFam7 = atoi(tok);
				else if (nMoneyCount == 9) nFam8 = atoi(tok);
				else if (nMoneyCount == 10) nFam9 = atoi(tok);
				else if (nMoneyCount == 11) nFam10 = atoi(tok);
				else nFam11 = atoi(tok);

				nMoneyCount++;
				tok = strtok(NULL, token2);
			}
			// �� �� ��ƾ
			if (nMoney1 <= smallMoney && nMoney2 > smallMoney) {
				if (FamilyNum == 1)
					IncomeTax = nFam1;
				else if (FamilyNum == 2)
					IncomeTax = nFam2;
				else if (FamilyNum == 3)
					IncomeTax = nFam3;
				else if (FamilyNum == 4)
					IncomeTax = nFam4;
				else if (FamilyNum == 5)
					IncomeTax = nFam5;
				else if (FamilyNum == 6)
					IncomeTax = nFam6;
				else if (FamilyNum == 7)
					IncomeTax = nFam7;
				else if (FamilyNum == 8)
					IncomeTax = nFam8;
				else if (FamilyNum == 9)
					IncomeTax = nFam9;
				else if (FamilyNum == 10)
					IncomeTax = nFam10;
				else
					IncomeTax = nFam11;
			}
		}
		if (MoneyOfMonth > 10000000 && MoneyOfMonth <= 14000000) {
			IncomeTax = IncomeTax+((MoneyOfMonth-10000000) * 0.98*0.35);
		}
		if (MoneyOfMonth > 14000000 && MoneyOfMonth <= 28000000) {
			IncomeTax = IncomeTax +1372000+ ((MoneyOfMonth - 14000000) * 0.98*0.38);
		}
		if (MoneyOfMonth > 28000000 && MoneyOfMonth < 45000000) {
			IncomeTax = IncomeTax + 6585600 +((MoneyOfMonth - 28000000) * 0.98*0.40);
		}
		if (MoneyOfMonth > 45000000) {
			IncomeTax = IncomeTax + 13249600 + ((MoneyOfMonth - 45000000) * 0.98*0.42);
		}
		PensionOfPeople = (MoneyOfMonth - NonTaxAmount)*0.045;
		if (MoneyOfMonth > 4600000) {
			PensionOfPeople = 202050;
		}
		HealthyInsurance = (MoneyOfMonth - NonTaxAmount)*0.0312;
		LongtermCare = HealthyInsurance * 0.0738;
		EmploymentInsurance = (MoneyOfMonth - NonTaxAmount)*0.0065;
		LocalIncomeTax = IncomeTax * 0.1;
		taxtotal = (PensionOfPeople + HealthyInsurance + LongtermCare + EmploymentInsurance + IncomeTax + LocalIncomeTax);

		total = MoneyOfMonth - (PensionOfPeople + HealthyInsurance + LongtermCare + EmploymentInsurance + IncomeTax + LocalIncomeTax);

		gotoxy(75, 7);printf("%.0lf(��)", total);
		gotoxy(65, 10);printf("���ο���        %.0lf(��)", PensionOfPeople);
		gotoxy(65, 13);printf("�ǰ�����        %.0lf(��)", HealthyInsurance);
		gotoxy(65, 16);printf("�����         %.0lf(��)", LongtermCare);
		gotoxy(65, 19);printf("��뺸��        %.0lf(��)", EmploymentInsurance);
		gotoxy(65, 22);printf("�ҵ漼          %.0lf(��)", IncomeTax);
		gotoxy(65, 25);printf("����ҵ漼       %.0lf(��)", LocalIncomeTax);
		gotoxy(65, 28);printf("������ �հ�     %.0lf(��)", taxtotal);
		gotoxy(65, 29);printf("---------------------------");

		getch();
		system("cls");
	}
}
void Magin() {
	while (1) {
		int buy, sell, delivery, freedelivery, pack, service, etc1;
		int openmarket, creditcard, etc2;
		int buysum, sellsum, deliverysum, freedeliverysum, packsum, servicesum, etc1sum;
		int openmarketsum, creditcardsum, etc2sum;
		char vat;
		char op;
		int total = 0;
		gotoxy(33, 2);
		printf("::�� ������ ����::");
		gotoxy(14, 4);printf("����");
		gotoxy(43, 4);printf("�Է�");
		gotoxy(70, 4);printf("��갡");
		gotoxy(7, 14);printf("��ǰ");
		gotoxy(17, 6);printf("���԰�");
		gotoxy(30, 6);printf("����(��):");
		gotoxy(13, 7);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 8);printf("VAT����");
		gotoxy(30, 8);printf("( O / X ) >>");
		gotoxy(13, 10);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 11);printf("�ǸŰ�");
		gotoxy(30, 11);printf("����(��):");
		gotoxy(13, 12);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 14);printf("��۷�");
		gotoxy(30, 13);printf("����(��):");
		gotoxy(40, 15);printf("(��) �̻� ���Ž� ������");
		gotoxy(13, 16);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 17);printf("�����");
		gotoxy(30, 17);printf("����(��):");
		gotoxy(13, 18);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 19);printf("����ǰ");
		gotoxy(30, 19);printf("����(��):");
		gotoxy(13, 20);
		printf("--------------------------------------------------------------------");
		gotoxy(18, 21);printf("��Ÿ");
		gotoxy(30, 21);printf("����(��):");
		gotoxy(13, 24);
		printf("--------------------------------------------------------------------");
		gotoxy(16, 23);printf("���¸���");
		gotoxy(35, 23);printf("(%%)");
		gotoxy(16, 25);printf("ī�����");
		gotoxy(35, 25);printf("(%%)");
		gotoxy(13, 26);
		printf("--------------------------------------------------------------------");
		gotoxy(16, 27);printf("��Ÿ");
		gotoxy(35, 27);printf("(%%)");
		gotoxy(6, 25);printf("������");
		gotoxy(13, 29);printf("���");
		draw_box2(4, 3, 27, 31, "*");
		draw_box2(65, 3, 80, 28, "*");
		draw_box2(4, 3, 80, 5, "*");
		draw_box2(4, 5, 13, 28, "*");
		draw_box2(4, 1, 80, 22, "*");
		draw_box2(4, 1, 80, 28, "*");
		draw_box2(4, 1, 80, 31, "*");
		gotoxy(13, 33);printf("�ع��� ����� ��۷Ḧ �Ǹ��ڰ� �δ��ϹǷ� ���ó�� �˴ϴ�.");
		gotoxy(5, 35);printf("�ب��� ������ ����ȭ������ ���ư��ϴ�.");
		gotoxy(5, 36);printf("��Enter�� ������ ������ ��갪 �Է��� �� �ֽ��ϴ�.>>");
		getchar();
		gotoxy(58, 36);scanf("%c", &op);
		if (op == 'r') {
			system("cls");
			main();
		}
		gotoxy(40, 6);scanf("%d", &buy);
		buysum = buy;
		getchar();
		gotoxy(44, 8);scanf("%c", &vat);
		int clock = 1;
		while (clock) {
			switch (vat) {
			case 'O':
				buysum = buysum + (buysum * 1 / 10);
				clock = 0;
				break;
			case 'o':
				buysum = buysum + (buysum * 1 / 10);
				clock = 0;
				break;
			case'x':
			case 'X':
				clock = 0;
				break;
			default:
				gotoxy(44, 8);scanf("%c", &vat);
				gotoxy(44, 9);printf("�ٽ��Է�");
				break;
			}
		}
		gotoxy(66, 8);printf("-%d", buysum);

		gotoxy(40, 11);scanf("%d", &sell);
		sellsum = sell;
		gotoxy(66, 11);printf("+%d", sellsum);

		gotoxy(40, 13);scanf("%d", &delivery);
		deliverysum = delivery;
		gotoxy(30, 15);scanf("%d", &freedelivery);
		freedeliverysum = freedelivery;
		if (freedeliverysum > sellsum) {
			deliverysum = 0;
			gotoxy(66, 14);printf("-%d��", deliverysum);
		}
		else {
			gotoxy(66, 14);printf("-%d", deliverysum);
		}
		gotoxy(40, 17);scanf("%d", &pack);
		packsum = pack;
		gotoxy(66, 17);printf("-%d", packsum);

		gotoxy(40, 19);scanf("%d", &service);
		servicesum = service;
		gotoxy(66, 19);printf("-%d", servicesum);

		gotoxy(40, 21);scanf("%d", &etc1);
		etc1sum = etc1;
		gotoxy(66, 21);printf("-%d", etc1sum);

		gotoxy(30, 23);scanf("%d", &openmarket);
		openmarketsum = (sellsum*openmarket / 100);
		gotoxy(66, 23);printf("-%d", openmarketsum);

		gotoxy(30, 25);scanf("%d", &creditcard);
		creditcardsum = (sellsum*creditcard / 100);
		gotoxy(66, 25);printf("-%d", creditcardsum);

		gotoxy(30, 27);scanf("%d", &etc2);
		etc2sum = (sellsum*etc2 / 100);
		gotoxy(66, 27);printf("-%d", etc2sum);
		total = -buysum + sellsum - deliverysum - packsum - servicesum - etc1sum - openmarketsum - creditcardsum - etc2sum;
		gotoxy(40, 29);printf("������ : %.2lf%%", ((double)total / sellsum * 100.));
		gotoxy(40, 30);printf("������ : %d��", total);
		getch();
		system("cls");
	}
}

void gotoxy(int x, int y) //���� ���ϴ� ��ġ�� Ŀ�� �̵�

{

	COORD pos; // Windows.h �� ����

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



void textcolor(int fg_color, int bg_color)

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);

}



void removeCursor(void)

{ // Ŀ���� �Ⱥ��̰� �Ѵ�

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void showCursor(void)

{ // Ŀ���� ���̰� �Ѵ�

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void cls(int bg_color, int text_color) // ȭ�� �����

{

	char cmd[100];

	system("cls");

	sprintf(cmd, "COLOR %x%x", bg_color, text_color);

	system(cmd);

}



// box �׸��� �Լ�, ch ���ڷ� (x1,y1) ~ (x2,y2) box�� �׸���.

void draw_box(int x1, int y1, int x2, int y2, char ch)

{

	int x, y;

	for (y = y1; y <= y2; y++) {

		if (y == y1 || y == y2) {

			for (x = x1; x <= x2; x++) {//x1 ó�� x2 ��

				gotoxy(x, y);

				printf("%c", ch);

			}

		}

		else {

			gotoxy(x1, y); printf("%c", ch);

			gotoxy(x2, y); printf("%c", ch);

		}

	}

	//�ϼ��Ұ�

}

// box �׸��� �Լ�, ch ���ڿ��� (x1,y1) ~ (x2,y2) box�� �׸���.

// �ѱ� ���ڸ� �׸��� �뵵�� ��� "��" �� ���� �׸��� ���

void draw_box2(int x1, int y1, int x2, int y2, char *ch)

{

	int x, y;

	for (y = y1; y <= y2; y++) {

		if (y == y1 || y == y2) {

			for (x = x1; x <= x2; x++) {//x1 ó�� x2 ��

				gotoxy(x, y);

				printf("%s", ch);

			}

		}

		else {

			gotoxy(x1, y); printf("%s", ch);

			gotoxy(x2, y); printf("%s", ch);

		}

	}

	// �ϼ��� �� ������ �� ��

}



// ���ۻ���������´�

int GetBufferSizeX()

{

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

	return screenInfo.dwSize.X;

}



int GetBufferSizeY()

{

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

	return screenInfo.dwSize.Y;

}


// ���������������

int SetWindowSize(const int width, const int height)

{

	if (width <= 0 || width > GetBufferSizeX() ||

		height <= 0 || height > GetBufferSizeY())

	{

		return 0;

	}

	SMALL_RECT rect;



	rect.Left = 0;

	rect.Right = width - 1;

	rect.Top = 0;

	rect.Bottom = height - 1;



	return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

}
