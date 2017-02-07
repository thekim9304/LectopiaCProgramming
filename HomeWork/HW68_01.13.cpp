/*
	!!�ֹι�ȣ ��ȿ�� �˻�

	@2017.01.15 pm09:57
*/
#if 1
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε��Ϲ�ȣ ����*/

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);

int main()
{
	/* �׽�Ʈ�� �ֹε��Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* �˻��� �ֹε��Ϲ�ȣ�� ���� ����*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* �ֹε��Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availabilityCheck()�Լ�: �ֹε��Ϲ�ȣ ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε��Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
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
checkLengthCharacter()�Լ�: �ֹε��Ϲ�ȣ ���� �� ���� ��ȿ���˻� �Լ�
��������: �˻��� �ֹε��Ϲ�ȣ(���ڿ�)
���ϰ�: �ֹε��Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ� ������TRUE,
���̰� ª�ų� ����, ���� ���ڰ� �ƴ� ���ڰ� ���� ������FALSE ����
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
checkDate()�Լ�: ù6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε��Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
------------------------------------------------------------------*/
int checkDate(char *resident_number)  // �� : 0 ~ 1   /  �� : 2 ~ 3  / �� : 4 ~ 5
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
checkGender()�Լ�: 7��° �ڸ��� �����ĺ���ȣ ��ȿ�� �˻��Լ�
��������: ��ȿ�� �˻��� �ֹε��Ϲ�ȣ(���ڿ�)
���ϰ�: �����ĺ���ȣ��'1'~'4'�̸�TRUE, �� �� ���� �����̸�FALSE ����
-----------------------------------------------------------------------*/
int checkGender(char *resident_number)
{
	if (resident_number[6] >= '1' && resident_number[6] <= '4')
		return TRUE;
	else
		return FALSE;
}
/*------------------------------------------------------------------------
checkIdentification()�Լ�: �ֹε��Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε��Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� �ν����̸�TRUE, ��ȿ���� ���� �ν����̸� FALSE ����
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
checkYear ()�Լ�: �⵵�� ��,���� ���� �˻�
��������: ��,���� �˻��� �⵵
���ϰ�: �����̸� TRUE, �����̸�FALSE ����
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


/**
 * 전반적으로 48 이라는 숫자가 엄청나게 등장함!
 * 이런 숫자는 define으로 빼거나 전역변수로 빼야함!
 * 이 문제 (오로지 이문제)에 있어서는 48밖에 될수 없을지라도,
 * 하드코딩 이라고 할 수 있기때문에
 * 변수로 선언하고 변수를 써주는게 좋음
 *
 * 또 다른경우에는, 48이라는 숫자를 49로 바꿔야 할 경우 지금 처럼 코딩되있으면 지옥임
 * "유지보수성" 이 좋은 코드는 "하드코딩" 을 줄여야함 <<중요>>
 */
