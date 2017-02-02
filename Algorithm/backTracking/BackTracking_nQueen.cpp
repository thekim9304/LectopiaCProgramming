#if 01
#pragma warning(disable: 4996)
#include <stdio.h>
#define CHECK (1)
#define MAX_CNT 15
int columnChk[MAX_CNT+1];             // column 체크 배열 (0번방 사용 안함)
int incDiagonalLineChk[MAX_CNT*2+1];  // 각도가 증가하는 대각선 체크 배열 (0번방 사용 안함)
int decDiagonalLineChk[MAX_CNT*2+1];  // 각도가 감소하는 대각선 체크 배열 (0번방 사용 안함)
int placementCnt;                     // 서로 공격못하게 배치 가능한 경우의 수 카운트 변수
int n;                                // queen의 수(또한 행,열의 수) 저장변수

void nQueen(int row);

int main()
{
	while(1)  // 퀸의 개수가 1~MAX_CNT 개 범위가 아니면 재입력
	{
		printf("퀸의 개수를 입력 하시오 : ");
		scanf("%d", &n);
		if(n>0 && n<=MAX_CNT) 
			break;
	}
	placementCnt = 0;
	nQueen(1);
	printf("배치 가능한 경우의 수 : %d\n\n", placementCnt);	
	return 0;
}
/*------------------------------------------------------------------
  함수명 및 기능: nQueen() - n개의 queen을 배치하기 위한 재귀호출 함수
  전달인자 : row - 체스판의 행번호(0행은 사용 안함)
  리턴값: 없음
------------------------------------------------------------------*/
void nQueen(int row)
{
	//내가 짠 코드
#if 01
	int col;

	if (row == n + 1)
		placementCnt++;

	for (col = 1; col <= n; col++) {
		if ((columnChk[col] != CHECK) && (incDiagonalLineChk[row + col] != CHECK) && (decDiagonalLineChk[n + (row - col)] != CHECK)) {
			columnChk[col] = incDiagonalLineChk[row + col] = decDiagonalLineChk[n + (row - col)] = CHECK;

			nQueen(row + 1);

			incDiagonalLineChk[row + col] = decDiagonalLineChk[n + (row - col)] = columnChk[col] = 0;
		}
	}
#endif

#if 0
	int i;


	if (row>n) // 행값이 n을 초과하면 퀸을 서로 공격못하게 배치하는 작업이 1회 끝난 것이므로 
	{
		placementCnt++; // 배치 카운트를 증가시키고
		return; // backtrack
	}


	for (i = 1; i <= n; ++i)
	{
		if (!columnChk[i] && !incDiagonalLineChk[row + i] && !decDiagonalLineChk[n + (row - i)])
		{
			columnChk[i] = incDiagonalLineChk[row + i] = decDiagonalLineChk[n + (row - i)] = CHECK; // 퀸 배치
			nQueen(row + 1); // 현재 행이 가능하므로 다음 행을 검사하기 위해 재귀호출 함
			columnChk[i] = incDiagonalLineChk[row + i] = decDiagonalLineChk[n + (row - i)] = 0; // backtrack 후 체크했던 내용 삭제 
		}
	}
	return;
#endif
}
#endif
