#include <iostream>

using namespace std;

void input(int **student, const int stuCnt, const int subCnt);
void output(int **student, const int stuCnt, const int subCnt);
int** myAlloc(const int, const int);
void mydelete(int **student, const int stuCnt, const int subCnt);

int main()
{
	int stuCnt, subCnt;
	int **student;

	cout << "학생 수 : ";
	cin >> stuCnt;
	cout << "과목 수 : ";
	cin >> subCnt;

	student = myAlloc(stuCnt, subCnt);

	input(student, stuCnt, subCnt);

	output(student, stuCnt, subCnt);
}

int** myAlloc(const int stuCnt, const int subCnt)
{
	int *subject;
	int **stud;

	stud = new int*[stuCnt];

	for (int i = 0; i < stuCnt; i++) {
		subject = new int[subCnt];
		stud[i] = subject;
	}

	return stud;
}

void mydelete(int **student, const int stuCnt, const int subCnt)
{
	for (int i = 0; i < stuCnt; i++)
		delete[] student[i];

	delete[] student;
}

void output(int **student, const int stuCnt, const int subCnt)
{
	int sum;

	for (int i = 0; i < stuCnt; i++) {
		sum = 0;
		cout << i + 1 << "번 : ";
		for (int j = 0; j < subCnt; j++) {
			cout << student[i][j] << "    ";
			sum += student[i][j];
		}
		cout << "총점 : " << sum << endl;
	}
}

void input(int **student, const int stuCnt, const int subCnt)
{
	for (int i = 0; i < stuCnt; i++) {
		cout << i + 1 << "번 학생 성적 입력: ";
		for (int j = 0; j < subCnt; j++) {
			cin >> student[i][j];
		}
	}
}

