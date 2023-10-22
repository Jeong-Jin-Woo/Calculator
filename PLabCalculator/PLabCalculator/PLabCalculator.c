#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <windows.h>
#include<string.h>


// 색상 정의

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
// box 그리기 함수, ch 문자로 (x1,y1) ~ (x2,y2) box를 그린다.
void draw_box(int x1, int y1, int x2, int y2, char ch);
// box 그리기 함수, ch 문자열로 (x1,y1) ~ (x2,y2) box를 그린다.
// 한글 문자를 그리는 용도로 사용 "□" 로 벽을 그리는 경우
void draw_box2(int x1, int y1, int x2, int y2, char *ch);
int GetBufferSizeX();
int GetBufferSizeY();
// 버퍼사이즈조절
int SetWindowSize(const int width, const int height);
// 버퍼사이즈를가져온다
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
//첫화면
int main() {
	//system("mode con cols=110 lines=48");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)

	char x;
	print_ui();
	showCursor();
	gotoxy(4, 32);
	printf("원하는 번호를 입력 후 엔터키를 눌러주세요. >>");
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
		printf("\n 이용해주셔서 감사합니다. (_ _)\n\n"); exit(0);
		break;
	default:
		gotoxy(40, 2); printf(" 잘못된 입력입니다.");
		break;
	}
	main();
}


//첫 화면
void print_ui() {

	gotoxy(15, 2);
	printf(" :: 계산기 :: ");
	gotoxy(4, 3); printf("************************************");
	gotoxy(12, 5);printf("① 일반 계산기");
	gotoxy(4, 7); printf("------------------------------------");
	gotoxy(12, 9);printf("② 학점 계산기");
	gotoxy(4, 11); printf("-----------------------------------");
	gotoxy(12, 13);printf("③ 연이자 계산기");
	gotoxy(4, 15); printf("-----------------------------------");
	gotoxy(12, 17);printf("④ 여성 배란일 계산기");
	gotoxy(4, 19); printf("-----------------------------------");
	gotoxy(12, 21);printf("⑤ 월급 계산기");
	gotoxy(4, 23); printf("-----------------------------------");
	gotoxy(12, 25);printf("⑥ 마진율 계산기");
	gotoxy(4, 27); printf("-----------------------------------");
	gotoxy(12, 29);printf("ⓧ 종 료 하 기");

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
		printf(":: 일반 계산기 ::");

		draw_box2(4, 22, 50, 26, "-");
		draw_box2(20, 3, 35, 11, "|");
		draw_box2(27, 11, 50, 15, "|");
		draw_box2(4, 7, 50, 11, "-");
		draw_box2(4, 1, 50, 15, "*");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 24, 50, 26, "~");
		draw_box2(4, 1, 50, 26, "*");
		gotoxy(8, 5);printf("+ (덧셈)");
		gotoxy(24, 5);printf("- (뺄셈)");
		gotoxy(39, 5);printf("+ (곱셈)");
		gotoxy(8, 9);printf("/ (나눗셈)");
		gotoxy(24, 9);printf("%% (나머지)");
		gotoxy(39, 9);printf("^ (제곱)");
		gotoxy(9, 13);printf("C (기록 초기화)");
		gotoxy(32, 13);printf("ⓡ (돌아가기)");
		gotoxy(4, 29);printf("이전 화면으로 돌아가고 싶다면 ⓡ키를 입력하세요.");
		gotoxy(4, 30);printf("돌아가고 싶지 않다면 아무키나 입력 >>");
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
			gotoxy(25, 22);printf("다시 입력\n");
			system("cls");
			adder();
		}
		gotoxy(6, 23);printf("= %.3lf", result);

		//파일 I/O result값을 저장 -> add() UI옆에다 result.txt 파일을 읽어와서 값을보여주고
		//계산기 하단에 result를 모두 더한값 출력. add()계산기를 나갈때 c버튼 무조건 작동.
		
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
		//파일 i/o출력
		PrintCurrentResultNum();
		/*
		f = fopen(".\\result.txt", "r");
		fscanf(f, "%.3lf", &nResult);   //scan은 포인터주소를 찾으므로 &를 붙여야한다
		
		fclose(f);
		
		gotoxy(6,25);printf("%.3lf", nResult);
		*/
		gotoxy(19, 2);
		printf(":: 일반 계산기 ::");

		draw_box2(4, 22, 50, 26, "-");
		draw_box2(20, 3, 35, 11, "|");
		draw_box2(27, 11, 50, 15, "|");
		draw_box2(4, 7, 50, 11, "-");
		draw_box2(4, 1, 50, 15, "*");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 24, 50, 26, "~");
		draw_box2(4, 1, 50, 26, "*");
		gotoxy(8, 5);printf("+ (덧셈)");
		gotoxy(24, 5);printf("- (뺄셈)");
		gotoxy(39, 5);printf("+ (곱셈)");
		gotoxy(8, 9);printf("/ (나눗셈)");
		gotoxy(24, 9);printf("%% (나머지)");
		gotoxy(39, 9);printf("^ (제곱)");
		gotoxy(9, 13);printf("C (기록 초기화)");
		gotoxy(32, 13);printf("ⓡ (돌아가기)");
		gotoxy(4, 29);printf("이전 화면으로 돌아가고 싶다면 ⓡ키를 입력하세요.");
		gotoxy(4, 30);printf("돌아가고 싶지 않다면 아무키나 입력 >>");
		if (nIsStartNormalCal != 0)
		{
			getchar();
			gotoxy(54, 25);printf("기록 초기화를 하고 싶으면 ⓒ키를 입력 >>");
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

void WriteDoubleData(double result, int nAddResult) // 0이면 ","를 안찍는다
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
		printf("::② 학점 계산기::");
		gotoxy(63, 5);printf("결과");
		gotoxy(7, 5);printf("수강 과목 수:");
		gotoxy(7, 7);printf("학점");
		gotoxy(20, 7);printf("성적");
		gotoxy(33, 7);printf("과목명");

		draw_box2(4, 1, 80, 30, "*");
		draw_box2(50, 3, 80, 7, "-");
		draw_box2(4, 3, 80, 30, "*");
		draw_box2(50, 3, 80, 30, "*");
		if (select == 'x' || select == 'X') {
			getchar();
			gotoxy(26, 31); printf("※약간의 오차가 있을 수 있습니다.");
			gotoxy(10, 34); printf("이전 화면으로 돌아가고 싶다면 ⓡ키 입력");
			gotoxy(10, 35); printf("아니라면 아무키나 입력 >>");
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
					gotoxy(17, 6);printf("다시 입력");
					gotoxy(20, 8 + i);scanf("%s", Score);
				}
			}ox = 1;
			total += LessonScore1 * intScore;
			getchar();
			gotoxy(33, 8 + i);scanf("%s", LessonName);
			getchar();
		}
		//gotoxy(21,5);scanf("%d", lessonNum);

		gotoxy(53, 12);printf("취득 학점 :     %d", LessonScoreSum);
		gotoxy(53, 16);printf("평점 총계 :     %.1lf", total);
		gotoxy(53, 20);printf("평균 평점 :     %.2lf", total / LessonScoreSum);
		gotoxy(13, 32);printf("이어서 다음학기까지의 학점을 입력하시겠습니까?(초기화 x) (O/X) >>");
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
				gotoxy(77, 33);printf("다시 입력");
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
		gotoxy(7, 0);printf("※계산기의 오차가 있을 수 있습니다.(1년동안 생리 주기가 규칙적이어야만 오차를 줄일 수 있음)");
		gotoxy(40, 2);
		printf("::④여성 배란일 계산기::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 70, 7, ".");
		draw_box2(72, 5, 98, 7, ".");
		gotoxy(6, 4);printf("최근 생리일");
		gotoxy(8, 6);printf("년도 : ");
		gotoxy(30, 6);printf("월 : ");
		gotoxy(50, 6);printf("날짜 : ");
		gotoxy(75, 6);printf("생리 주기 : ");

		gotoxy(4, 10);printf("※ⓡ을 입력하면 이전화면으로 돌아갑니다. Enter를 누르면 배란일 계산 가능합니다. >>");
		getchar();
		gotoxy(87, 10);scanf("%c", &select);
		if (select == 'r') {
			system("cls");
			main();
		}

		//생리주기 , 날짜 년 월 입력      여기 주석은 결과출력 위로 보내야함.
		gotoxy(16, 6);scanf("%d", &Year);
		if ((Year % 4 == 0) && ((Year % 100 != 0) || (Year % 400 == 0)))//윤년 판단 
		{
			days[1] = 29;//2월달의 날 수를 29로 설정 
		}
		while (1) {
			getchar();
			gotoxy(36, 6);scanf("%d", &Month);
			if (Month < 1 || Month >12) {
				gotoxy(33, 8);printf("다시 입력");
			}
			else break;
		}
		while (1) {
			getchar();
			gotoxy(58, 6);scanf("%d", &Day);
			if (Day > days[Month - 1] || Day < 1) {
				gotoxy(55, 8);printf("다시 입력");
			}
			else break;
		}
		while (1) {
			getchar();
			gotoxy(88, 6);scanf("%d", &TimeSet);
			if (TimeSet < 21 || TimeSet>40) {
				gotoxy(74, 8);printf("정상적인 생리주기 : 21~40");
			}
			else break;
		}
		//결과 출력
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
		draw_box2(4, 23, 100, 23, "-"); //생리 배란 칸
		draw_box2(13, 11, 23, 13, "*");
		draw_box2(53, 11, 100, 13, "*");
		draw_box2(4, 11, 100, 13, "*");
		draw_box2(4, 11, 100, 33, "*");

		gotoxy(6, 12);printf("분 류");
		gotoxy(16, 12);printf("주 기");
		gotoxy(36, 12);printf("년 도");
		gotoxy(72, 12);printf("예 상 일 자");

		gotoxy(6, 14);printf("배란기");
		gotoxy(6, 16);printf("생리");
		gotoxy(6, 18);printf("배란기");
		gotoxy(6, 20);printf("생리");
		gotoxy(6, 22);printf("배란기");
		gotoxy(6, 24);printf("생리");
		gotoxy(6, 26);printf("배란기");
		gotoxy(6, 28);printf("생리");
		gotoxy(6, 30);printf("배란기");
		gotoxy(6, 32);printf("생리");
		//계산 출력
		PariodMonth = Month;
		PariodYear = Year;
		PariodDay = Day;
		OvalMonth = Month;
		OvalYear = Year;
		OvalDay = Day;
		for (int i = 14;i <= 32;i += 2) {
			gotoxy(17, i);printf("%d", TimeSet);
		}
		//계산 알고리즘 년도 , 예상일자는 계산하면서 출력해야함.   1/1
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
			gotoxy(32, 16 + i);printf("%d 년 %02d 월", PariodYear, PariodMonth);
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
			gotoxy(32, 14 + i);printf("%d 년 %02d 월", OvalYear, OvalMonth);
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
		gotoxy(20, 2);printf(":: 이자 계산기 ::");
		gotoxy(15, 5);printf("① 단리 예금 이자 계산기");
		gotoxy(15, 9);printf("② 월복리 예금 이자 계산기");
		gotoxy(15, 13);printf("③ 대출 이자 계산기");
		draw_box2(4, 1, 50, 7, "-");
		draw_box2(4, 1, 50, 11, "-");
		draw_box2(4, 1, 50, 3, "*");
		draw_box2(4, 1, 50, 15, "*");
		gotoxy(4, 17);printf("원하는 계산기의 번호를 입력 후 엔터키를 눌러주세요.");
		gotoxy(4, 18);printf("( ※ⓡ을 입력하면 이전화면으로 돌아갑니다. ) >>");
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
		//입력받을 실행화면
		gotoxy(40, 2);printf("::단리 예금 이자 계산기::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("예치금액(원) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("예금기간(년) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("연이율(%%) : ");

		getchar();
		gotoxy(4, 11);printf("( ※ⓡ을 입력하면 이전화면으로 돌아갑니다. ) >>");
		gotoxy(4, 10);printf("※Enter를 누르고 값을 입력하면 세후 수령액을 볼 수 있습니다.");
		gotoxy(53, 11);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//입력받을곳
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(70, 5);scanf("%lf", &DepositTime);
		gotoxy(91, 5);scanf("%lf", &Rate);

		//계산
		Interest = MoneyAmount * (Rate / 100) * DepositTime;
		//계산 출력
		draw_box2(4, 17, 100, 20, "-");
		draw_box2(4, 14, 100, 23, "*");
		draw_box2(59, 14, 76, 20, "*");
		draw_box2(4, 17, 20, 20, "*");
		draw_box2(59, 17, 76, 20, "*");
		draw_box2(4, 14, 20, 23, "*");
		draw_box2(4, 25, 100, 36, "*");
		gotoxy(7, 15);printf("예 치 금 액");
		gotoxy(7, 18);printf("예 금 금 리");
		gotoxy(7, 21);printf("세 전 이 자");
		gotoxy(62, 15);printf("예 치 기 간");
		gotoxy(61, 18);printf("이자 계산 방법");
		gotoxy(24, 15);printf("%.0lf원", MoneyAmount);
		gotoxy(24, 18);printf("연 %.2lf%%", Rate);
		gotoxy(24, 21);printf("%0.lf원", Interest);
		gotoxy(79, 15);printf("%0.lf년", DepositTime);
		gotoxy(79, 18);printf("단리");
		draw_box2(57, 25, 100, 36, "|");
		draw_box2(4, 30, 100, 33, "-");
		draw_box2(4, 30, 21, 33, "*");
		draw_box2(57, 25, 100, 27, "*");
		draw_box2(4, 25, 100, 36, "*");
		draw_box2(4, 25, 100, 27, "*");
		draw_box2(4, 25, 21, 36, "*");
		gotoxy(8, 26);printf("이 자 과 세");
		gotoxy(8, 28);printf("일 반 과 세");
		gotoxy(8, 31);printf("비 과 세");
		gotoxy(8, 34);printf("세 금 우 대");
		gotoxy(5, 35);printf("(우대세율(9.5%%))");
		gotoxy(32, 26);printf("만 기 지 급 액");
		gotoxy(73, 26);printf("세 후 이 자");

		gotoxy(75, 28);printf("%0.lf원", Interest - Interest * 0.154);
		gotoxy(75, 31);printf("%0.lf원", Interest);
		gotoxy(75, 34);printf("%0.lf원", Interest - Interest * 0.095);

		gotoxy(33, 28);printf("%0.lf원", MoneyAmount + (Interest - Interest * 0.154));
		gotoxy(33, 31);printf("%0.lf원", MoneyAmount + Interest);
		gotoxy(33, 34);printf("%0.lf원", MoneyAmount + (Interest - Interest * 0.095));
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
		//입력받을 실행화면
		gotoxy(40, 2);printf("::월복리 예금 이자 계산기::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("예치금액(원) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("예금기간(개월) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("연이율(%%) : ");

		getchar();
		gotoxy(4, 11);printf("( ※ⓡ을 입력하면 이전화면으로 돌아갑니다. ) >>");
		gotoxy(4, 10);printf("※Enter를 누르고 값을 입력하면 세후 수령액을 볼 수 있습니다.");
		gotoxy(53, 11);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//입력받을곳
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(71, 5);scanf("%lf", &DepositTime);
		gotoxy(93, 5);scanf("%lf", &Rate);

		//계산
		Interest = MoneyAmount * pow((1. + Rate / 100 / 12), 12 * DepositTime / 12) - MoneyAmount;
		//계산 출력
		draw_box2(4, 17, 100, 20, "-");
		draw_box2(4, 14, 100, 23, "*");
		draw_box2(59, 14, 76, 20, "*");
		draw_box2(4, 17, 20, 20, "*");
		draw_box2(59, 17, 76, 20, "*");
		draw_box2(4, 14, 20, 23, "*");
		draw_box2(4, 25, 100, 36, "*");
		gotoxy(7, 15);printf("예 치 금 액");
		gotoxy(7, 18);printf("예 금 금 리");
		gotoxy(7, 21);printf("세 전 이 자");
		gotoxy(62, 15);printf("예 치 기 간");
		gotoxy(61, 18);printf("이자 계산 방법");
		gotoxy(24, 15);printf("%0.lf원", MoneyAmount);
		gotoxy(24, 18);printf("연 %.2lf%%", Rate);
		gotoxy(24, 21);printf("%.0lf원", Interest);
		gotoxy(79, 15);printf("%.0lf개월", DepositTime);
		gotoxy(79, 18);printf("월복리");
		draw_box2(57, 25, 100, 36, "|");
		draw_box2(4, 30, 100, 33, "-");
		draw_box2(4, 30, 21, 33, "*");
		draw_box2(57, 25, 100, 27, "*");
		draw_box2(4, 25, 100, 36, "*");
		draw_box2(4, 25, 100, 27, "*");
		draw_box2(4, 25, 21, 36, "*");
		gotoxy(8, 26);printf("이 자 과 세");
		gotoxy(8, 28);printf("일 반 과 세");
		gotoxy(8, 31);printf("비 과 세");
		gotoxy(8, 34);printf("세 금 우 대");
		gotoxy(5, 35);printf("(우대세율(9.5%%))");
		gotoxy(32, 26);printf("만 기 지 급 액");
		gotoxy(73, 26);printf("세 후 이 자");

		gotoxy(75, 28);printf("%0.lf원", Interest - Interest * 0.154);
		gotoxy(75, 31);printf("%0.lf원", Interest);
		gotoxy(75, 34);printf("%0.lf원", Interest - Interest * 0.095);

		gotoxy(33, 28);printf("%0.lf원", MoneyAmount + (Interest - Interest * 0.154));
		gotoxy(33, 31);printf("%0.lf원", MoneyAmount + Interest);
		gotoxy(33, 34);printf("%0.lf원", MoneyAmount + (Interest - Interest * 0.095));
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
		//입력받을 실행화면
		gotoxy(40, 2);printf("::대출 이자 계산기::");
		draw_box2(4, 1, 100, 9, "*");
		draw_box2(4, 1, 100, 3, "*");
		draw_box2(6, 5, 50, 7, "$");
		gotoxy(8, 6);printf("대출금액(원) : ");
		draw_box2(53, 4, 75, 6, ".");
		gotoxy(55, 5);printf("대출기간(개월) : ");
		draw_box2(77, 4, 98, 6, ".");
		gotoxy(79, 5);printf("연이자율(%%) : ");
		gotoxy(53, 8);printf("원리금균등:1, 원금균등:2, 만기일시:3 >>");
		getchar();
		gotoxy(4, 12);printf("( ※ⓡ을 입력하면 이전화면으로 돌아갑니다. ) >>");
		gotoxy(4, 11);printf("※Enter를 누르고 값을 입력하면 상환액을 볼 수 있습니다.");
		gotoxy(53, 12);scanf("%c", &sel);
		if (sel == 'r') {
			system("cls");
			AnnualInterest();
		}
		//입력받을곳
		gotoxy(23, 6);scanf("%lf", &MoneyAmount);
		gotoxy(72, 5);scanf("%lf", &LoanTime);
		gotoxy(93, 5);scanf("%lf", &Rate);
		gotoxy(94, 8);scanf("%d", &Case);
		switch (Case) {
		case 1:
			//알고리즘
			sameAmount = (MoneyAmount *(Rate / 100 / 12)* pow((1 + Rate / 100 / 12), LoanTime)) / ((pow((1 + Rate / 100 / 12), LoanTime)) - 1);
			i = 0;
			draw_box2(4, 14, 100, 16, "*");
			draw_box2(4, 16, 100, 18, "*");
			draw_box2(15, 16, 35, 18, "*");
			draw_box2(54, 16, 71, 18, "*");
			gotoxy(6, 15);printf("월별 상환금과 대출잔금 ( 원리금균등상환 )");
			gotoxy(8, 17);printf("회차");
			gotoxy(21, 17);printf("납입원금");
			gotoxy(41, 17);printf("대출이자");
			gotoxy(59, 17);printf("월상환금");
			gotoxy(82, 17);printf("대출잔금");
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
			//알고리즘
			MoneyAmount2 = MoneyAmount;
			i = 0;
			draw_box2(4, 14, 100, 16, "*");
			draw_box2(4, 16, 100, 18, "*");
			draw_box2(15, 16, 35, 18, "*");
			draw_box2(54, 16, 71, 18, "*");
			gotoxy(6, 15);printf("월별 상환금과 대출잔금 ( 원금균등상환 )");
			gotoxy(8, 17);printf("회차");
			gotoxy(21, 17);printf("납입원금");
			gotoxy(41, 17);printf("대출이자");
			gotoxy(59, 17);printf("월상환금");
			gotoxy(82, 17);printf("대출잔금");
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
			gotoxy(7, 15);printf("만기일시상환");
			gotoxy(18, 17);printf("대출원금");
			gotoxy(45, 17);printf("총대출이자");
			gotoxy(75, 17);printf("총상환금액");

			gotoxy(18, 20);printf("%0.lf원",MoneyAmount);
			Interest = MoneyAmount * Rate / 100 / 12 * LoanTime;
			gotoxy(47, 20);printf("%0.lf원",Interest);
			gotoxy(75, 20);printf("%0.lf원", MoneyAmount + Interest);
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
		gotoxy(45, 2);printf("::⑤ 월급 계산기::");
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
		gotoxy(9, 5);printf("급여 기준 : 월급");
		gotoxy(20, 9);printf("월급");
		gotoxy(45, 11);printf("(원)");
		gotoxy(20, 20);printf("부양 가족 수(본인포함)");
		gotoxy(20, 25);printf("비과세액");
		gotoxy(45, 27);printf("(원)");
		gotoxy(45, 22);printf("(명)");
		gotoxy(17, 29);printf("※비과세액은 100,000원이 최대입니다.");
		gotoxy(72, 4);printf("월 예상 실수령액");
		gotoxy(5, 32);printf("※ⓡ을 누르면 이전화면으로 돌아갑니다.");
		gotoxy(5, 33);printf("※Enter를 누르고 값을 입력하면 월급 실수령액을 볼 수 있습니다.>>");
		getchar();
		gotoxy(70, 33);scanf("%c", &op);
		if (op == 'r') {
			system("cls");
			main();
		}
		while (1) {
			gotoxy(30, 11);scanf("%d", &MoneyOfMonth);
				if (MoneyOfMonth < 870000 || MoneyOfMonth >1000000000) {
				gotoxy(8, 13);printf("월급 87만원 이상 10억 이하일 경우에 입력가능합니다.");
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
			printf("에러");
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

			// 입력된 월급값을 nMoney1, nMoney2를 비교하여 조건에 맞으면
			// 가족세대원수가 1명이면 nFam1, 2명이면 nFam2......
			// 토큰값 분리
			tok = strtok(line, token2);
			while (tok != NULL)
			{
				// 토큰값 저장하여 비교하는 루틴
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
			// 값 비교 루틴
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

		gotoxy(75, 7);printf("%.0lf(원)", total);
		gotoxy(65, 10);printf("국민연금        %.0lf(원)", PensionOfPeople);
		gotoxy(65, 13);printf("건강보험        %.0lf(원)", HealthyInsurance);
		gotoxy(65, 16);printf("장기요양         %.0lf(원)", LongtermCare);
		gotoxy(65, 19);printf("고용보험        %.0lf(원)", EmploymentInsurance);
		gotoxy(65, 22);printf("소득세          %.0lf(원)", IncomeTax);
		gotoxy(65, 25);printf("지방소득세       %.0lf(원)", LocalIncomeTax);
		gotoxy(65, 28);printf("공제액 합계     %.0lf(원)", taxtotal);
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
		printf("::⑥ 마진율 계산기::");
		gotoxy(14, 4);printf("구분");
		gotoxy(43, 4);printf("입력");
		gotoxy(70, 4);printf("계산가");
		gotoxy(7, 14);printf("상품");
		gotoxy(17, 6);printf("매입가");
		gotoxy(30, 6);printf("가격(원):");
		gotoxy(13, 7);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 8);printf("VAT별도");
		gotoxy(30, 8);printf("( O / X ) >>");
		gotoxy(13, 10);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 11);printf("판매가");
		gotoxy(30, 11);printf("가격(원):");
		gotoxy(13, 12);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 14);printf("배송료");
		gotoxy(30, 13);printf("가격(원):");
		gotoxy(40, 15);printf("(원) 이상 구매시 무료배송");
		gotoxy(13, 16);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 17);printf("포장비");
		gotoxy(30, 17);printf("가격(원):");
		gotoxy(13, 18);
		printf("--------------------------------------------------------------------");
		gotoxy(17, 19);printf("사은품");
		gotoxy(30, 19);printf("가격(원):");
		gotoxy(13, 20);
		printf("--------------------------------------------------------------------");
		gotoxy(18, 21);printf("기타");
		gotoxy(30, 21);printf("가격(원):");
		gotoxy(13, 24);
		printf("--------------------------------------------------------------------");
		gotoxy(16, 23);printf("오픈마켓");
		gotoxy(35, 23);printf("(%%)");
		gotoxy(16, 25);printf("카드결제");
		gotoxy(35, 25);printf("(%%)");
		gotoxy(13, 26);
		printf("--------------------------------------------------------------------");
		gotoxy(16, 27);printf("기타");
		gotoxy(35, 27);printf("(%%)");
		gotoxy(6, 25);printf("수수료");
		gotoxy(13, 29);printf("결과");
		draw_box2(4, 3, 27, 31, "*");
		draw_box2(65, 3, 80, 28, "*");
		draw_box2(4, 3, 80, 5, "*");
		draw_box2(4, 5, 13, 28, "*");
		draw_box2(4, 1, 80, 22, "*");
		draw_box2(4, 1, 80, 28, "*");
		draw_box2(4, 1, 80, 31, "*");
		gotoxy(13, 33);printf("※무료 배송은 배송료를 판매자가 부담하므로 비용처리 됩니다.");
		gotoxy(5, 35);printf("※ⓡ을 누르면 이전화면으로 돌아갑니다.");
		gotoxy(5, 36);printf("※Enter를 누르면 마진율 계산값 입력할 수 있습니다.>>");
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
				gotoxy(44, 9);printf("다시입력");
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
			gotoxy(66, 14);printf("-%d원", deliverysum);
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
		gotoxy(40, 29);printf("마진율 : %.2lf%%", ((double)total / sellsum * 100.));
		gotoxy(40, 30);printf("순이익 : %d원", total);
		getch();
		system("cls");
	}
}

void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동

{

	COORD pos; // Windows.h 에 정의

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



void textcolor(int fg_color, int bg_color)

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);

}



void removeCursor(void)

{ // 커서를 안보이게 한다

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void showCursor(void)

{ // 커서를 보이게 한다

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void cls(int bg_color, int text_color) // 화면 지우기

{

	char cmd[100];

	system("cls");

	sprintf(cmd, "COLOR %x%x", bg_color, text_color);

	system(cmd);

}



// box 그리기 함수, ch 문자로 (x1,y1) ~ (x2,y2) box를 그린다.

void draw_box(int x1, int y1, int x2, int y2, char ch)

{

	int x, y;

	for (y = y1; y <= y2; y++) {

		if (y == y1 || y == y2) {

			for (x = x1; x <= x2; x++) {//x1 처음 x2 끝

				gotoxy(x, y);

				printf("%c", ch);

			}

		}

		else {

			gotoxy(x1, y); printf("%c", ch);

			gotoxy(x2, y); printf("%c", ch);

		}

	}

	//완성할것

}

// box 그리기 함수, ch 문자열로 (x1,y1) ~ (x2,y2) box를 그린다.

// 한글 문자를 그리는 용도로 사용 "□" 로 벽을 그리는 경우

void draw_box2(int x1, int y1, int x2, int y2, char *ch)

{

	int x, y;

	for (y = y1; y <= y2; y++) {

		if (y == y1 || y == y2) {

			for (x = x1; x <= x2; x++) {//x1 처음 x2 끝

				gotoxy(x, y);

				printf("%s", ch);

			}

		}

		else {

			gotoxy(x1, y); printf("%s", ch);

			gotoxy(x2, y); printf("%s", ch);

		}

	}

	// 완성할 수 있으면 할 것

}



// 버퍼사이즈를가져온다

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


// 윈도우사이즈조절

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
