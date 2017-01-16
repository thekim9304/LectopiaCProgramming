/*
	!!주민번호 유효성 검사

	@2017.01.15 pm09:57
*/
#if 0
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);

int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availabilityCheck()함수: 주민등록번호 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char *resident_number)
{
	int ret;

	ret = checkLengthCharacter(resident_number);
	if (ret == FALSE) return FALSE;

	ret = checkGender(resident_number);
	if (ret == FALSE) return FALSE;

	ret = checkDate(resident_number);
	if (ret == FALSE) return FALSE;

	ret = checkIdentification(resident_number);
	if (ret == FALSE) return FALSE;

	return TRUE;
}
/*-------------------------------------------------------------------------
checkLengthCharacter()함수: 주민등록번호 길이 및 문자 유효성검사 함수
전달인자: 검사할 주민등록번호(문자열)
리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면TRUE,
길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면FALSE 리턴
--------------------------------------------------------------------------*/
int checkLengthCharacter(char *resident_number)
{
	int i = 0;

	while (resident_number[i] != '\0')
	{
		i++;
	}

	if (i != RESIDENT_NUMBER_LENGTH)
		return FALSE;
	else
		return TRUE;
}
/*----------------------------------------------------------------
checkDate()함수: 첫6자리(연,월,일)의 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
------------------------------------------------------------------*/
int checkDate(char *resident_number)  // 연 : 0 ~ 1   /  월 : 2 ~ 3  / 일 : 4 ~ 5
{
	int monthD[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day, checkY;

	year = ((resident_number[0] - 48) * 10) + (resident_number[1] - 48);
	month = ((resident_number[2] - 48) * 10) + (resident_number[3] - 48);
	day = ((resident_number[4] - 48) * 10) + (resident_number[5] - 48);

	if (resident_number[6] - 48 > '2')
	{
		if ((year == 17))
		{
			if (month > 1)
				return FALSE;
			else
			{
				if (day > 15)
					return FALSE;
			}
		}
		else if (year > 17)
			return FALSE;

		year += 2000;
	}
	else
	{
		year += 1900;
	}

	if (checkYear(year) == TRUE)
		monthD[1] = 29;
	else
		monthD[1] = 28;

	if (month > 0 && month < 13)
	{
		if ((day >= 1) && (day <= monthD[month - 1]))
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;

	

	/*
	int i, retGender, retYear, numYear;

	if(resident_number[])

    retGender = checkGender(resident_number);

	if (retGender == TRUE)
		numYear = 1900 + ((resident_number[0] - 48) * 10) + (resident_number[1] - 48);
	else
		numYear = 2000 + ((resident_number[0] - 48) * 10) + (resident_number[1] - 48);

	retYear = checkYear(numYear);

	if (retYear == FALSE)
	{
	}*/
}
/*----------------------------------------------------------------------
checkGender()함수: 7번째 자리의 성별식별번호 유효성 검사함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 성별식별번호가'1'~'4'이면TRUE, 그 외 숫자 문자이면FALSE 리턴
-----------------------------------------------------------------------*/
int checkGender(char *resident_number)
{
	if (resident_number[6] >= '1' && resident_number[6] <= '4')
		return TRUE;
	else
		return FALSE;
}
/*------------------------------------------------------------------------
checkIdentification()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 인식자이면TRUE, 유효하지 않은 인식자이면 FALSE 리턴
-------------------------------------------------------------------------*/
int checkIdentification(char *resident_number)
{
	int i, sum = 0, result;

	for (i = 0; i < RESIDENT_NUMBER_LENGTH - 1; i++)
	{
		sum += (resident_number[i] - 48);
	}	

	result = sum % 10;

	if (result == (resident_number[12] - 48))
		return TRUE;
	else
		return FALSE;
}
/*----------------------------------------------------------------
checkYear ()함수: 년도의 윤,평년 여부 검사
전달인자: 윤,평년 검사할 년도
리턴값: 윤년이면 TRUE, 평년이면FALSE 리턴
------------------------------------------------------------------*/
int checkYear(int year)
{
	int result;

	if ((year % 4) != 0)
		return FALSE;
	else if ((year % 100) != 0)
		return TRUE;
	else if ((year % 400) != 0)
		return FALSE;
	else
		return TRUE;
}
#endif
