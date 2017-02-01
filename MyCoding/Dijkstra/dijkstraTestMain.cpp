#include<stdio.h>
#include<malloc.h>
#include "graph.h"
void displayTitle(char *message);
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent);
void printWeightArray(int *weightArray, int vNum, int vCnt);
void printParent(int *parent, int vCnt);
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum);

/*----------------------------------------------------------------------------------
함수명 : main() 
----------------------------------------------------------------------------------*/
int main()
{
	GraphMatrix g;
	int weightArray[MAX_VERTEX];  /* 가중치를 순차적으로 저장하는 배열 */
	int parent[MAX_VERTEX];      /* 부모 정점 저장 배열*/
	int i;

	initGraph(&g, "c:\\data\\graphData2.txt");/* 그래프 초기화 */

	displayTitle("[가중 그래프의 인접 행렬 출력]");
	outputGraph(&g);   /* 그래프 연결 및 가중치 상태 출력*/        
	NEWL; NEWL;

	/* 다익스트라 알고리즘 수행 */

	displayTitle("[가중치 변화 상태 출력]");
	dijkstra(&g, 5, weightArray, parent);  /* 5번에 해당하는 정점을 기준으로 다익스트라 알고리즘 실행 */

	displayTitle("[정점간의 부모, 자식관계 출력]");
	printParent(parent, g.vertexCnt);  /* parent 배열 출력 */

	/* 기준 정점(F-5번 정점)로 부터 그래프태의 모든 정점(A~K)가지의 경로 및 가중치 출력 */
	displayTitle("[F(5번 정점)기준으로 각 정점으로의 path 출력하기]");
	for(i=0; i<g.vertexCnt; ++i)
		pathPrint(parent, weightArray, 5, i);

	return 0;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: displayTitle() - 전달된 메시지를 출력 함 
전달인자:  message - 출력할 메시지
리턴값: 없음
--------------------------------------------------------------------------------------*/
void displayTitle(char *message)
{
	printf("\n----------------------------------------\n");
	printf(" %s\n", message);
	printf("----------------------------------------\n");
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: dijkstra() - 전달된 그래프내에 선택된 정점으로 부터 나머지 정점까지의 
			최소 가중치를 계산하고 부모자식 관계를 연산함
전달인자:  g - 그래프 정보 구조체의 주소
			vNum - 선택된 정점 번호
			weightArray - 가중치를 저장할 배열의 시작주소
			parent - 정점간의 부모자식관계를 저장할 배열의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent)
{
	int check[100];
	int i, j, k;
	int standard, standardIndex, saveWeight, compare;
	//기준 초기화, 부모 경로 초기화
	for (i = 0; i < g->vertexCnt; i++) {
		check[i] = 0;
		parent[i] = vNum;
	}
	parent[vNum] = -1;
	check[vNum] = 1;
	standardIndex = vNum;
	//가중치 초기화
	for (i = 0; i < g->vertexCnt; i++) {
		weightArray[i] = g->graph[standardIndex][i];
	}
	printWeightArray(weightArray, standardIndex, g->vertexCnt);
	//가중치 차수
	for (j = 0; j < g->vertexCnt - 1; j++) {
		standard = 1000;
		//가장 작은 가중치를 갖는 정점 기준으로
		for (i = 0; i < g->vertexCnt; i++) {
			if (weightArray[i] < standard && check[i] != 1) {
				standard = weightArray[i];
				standardIndex = i;
			}
		}
		check[standardIndex]++;
		//가중치 갱신
		for (i = 0; i < g->vertexCnt; i++) {
			if (g->graph[standardIndex][i] != 1000) {
				if (i == vNum)
					continue;

				saveWeight = weightArray[standardIndex] + g->graph[standardIndex][i];
				if (saveWeight < weightArray[i]) {
					weightArray[i] = saveWeight;
					parent[i] = standardIndex;
				}
			}
		}
		printWeightArray(weightArray, standardIndex, g->vertexCnt);
	}
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: printWeightArray() - weight배열을 출력 함
전달인자:  weightArray - 가중치 저장 배열의 시작주소
           vNum - 기준 정점 번호
           vCnt - 출력할 정점의 개수
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printWeightArray(int *weightArray, int vNum, int vCnt)
{
	int i;
	printf("%3c : ", 'A'+vNum);
	for(i=0; i<vCnt; ++i)
		printf("%5d", weightArray[i]);

	NEWL;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: printParent() - 부모, 자식 노드를 표시하는 배열 출력
전달인자:  parent - 부모, 자식 노들 표시 배열의 시작주소
			vCnt - 출력할 정점의 개수
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printParent(int *parent, int vCnt)
{
	int i;
	printf("\n---------------------------------------------------------\n");
	printf("child :  ");
	for(i=0; i<vCnt; ++i)
		printf("%3c", i+'A');
	NEWL;
	printf("Parent : ");
	for(i=0; i<vCnt; ++i)
		if(parent[i]==-1) printf("  *");
		else printf("%3c", parent[i]+'A');
		printf("\n--------------------------------------------------------\n");
		NEWL;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: pathPrint() - 시작 정점->끝 정점까지의 path 및 가중치 출력
전달인자:  parent - 부모, 자식관계를 저장한 배열의 시작주소
			weightArray - 가중치 저장 배열의 시작주소
			startVNum - 시작 정점 번호
			endVNum - 도착 정점 번호
리턴값: 없음
--------------------------------------------------------------------------------------*/
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum)
{
	int i, count = 0;
	char save[1000];

	printf("%c ", startVNum + 'A');

	if (endVNum != startVNum) {
		i = endVNum;
		do {
			save[count++] = i;
			i = parent[i];
		} while (i != startVNum);

		for (i = count - 1; i > -1; i--) {
			printf("->   %c", save[i] + 'A');
		}
	}
	printf("   (weight : %d)\n", weightArray[endVNum]);
}

/*======================================================================================================
[ 출력 결과 ]
----------------------------------------
[가중 그래프의 인접 행렬 출력]
----------------------------------------
A  B  C  D  E  F  G  H  I  J  K
A  0  4  1  2  3 ∞ ∞ ∞ ∞ ∞ ∞
B  4  0 ∞ ∞ ∞  4 ∞ ∞ ∞ ∞ ∞
C  1 ∞  0  2 ∞ ∞ ∞ ∞ ∞ ∞ ∞
D  2 ∞  2  0 ∞  4  4 ∞ ∞ ∞ ∞
E  3 ∞ ∞ ∞  0  4 ∞ ∞ ∞ ∞ ∞
F ∞  4 ∞  4  4  0 ∞ ∞ ∞  2  4
G ∞ ∞ ∞  4 ∞ ∞  0  3  3  4 ∞
H ∞ ∞ ∞ ∞ ∞ ∞  3  0  2 ∞ ∞
I ∞ ∞ ∞ ∞ ∞ ∞  3  2  0  2 ∞
J ∞ ∞ ∞ ∞ ∞  2  4 ∞  2  0  1
K ∞ ∞ ∞ ∞ ∞  4 ∞ ∞ ∞  1  0

∞ : 1000값으로 계산됨

----------------------------------------
[가중치 변화 상태 출력]
----------------------------------------
F :  1000    4 1000    4    4    0 1000 1000 1000    2    4
J :  1000    4 1000    4    4    0    6 1000    4    2    3
K :  1000    4 1000    4    4    0    6 1000    4    2    3
B :     8    4 1000    4    4    0    6 1000    4    2    3
D :     6    4    6    4    4    0    6 1000    4    2    3
E :     6    4    6    4    4    0    6 1000    4    2    3
I :     6    4    6    4    4    0    6    6    4    2    3
A :     6    4    6    4    4    0    6    6    4    2    3
C :     6    4    6    4    4    0    6    6    4    2    3
G :     6    4    6    4    4    0    6    6    4    2    3
H :     6    4    6    4    4    0    6    6    4    2    3

----------------------------------------
[정점간의 부모, 자식관계 출력]
----------------------------------------
child :    A  B  C  D  E  F  G  H  I  J  K
Parent :   D  F  D  F  F  *  J  I  J  F  J

----------------------------------------
[F기준 각 정점으로의 path 출력]
----------------------------------------
F ->   D ->   A  (weight: 6)
F ->   B  (weight: 4)
F ->   D ->   C  (weight: 6)
F ->   D  (weight: 4)
F ->   E  (weight: 4)
F  (weight: 0)
F ->   J ->   G  (weight: 6)
F ->   J ->   I ->   H  (weight: 6)
F ->   J ->   I  (weight: 4)
F ->   J  (weight: 2)
F ->   J ->   K  (weight: 3)

*/