#include <ctime>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#include <conio.h>
#include<mmsystem.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")
#define SOUND_FILE_NAME "C:\\unused_git_workspace\\school_timer_sounds\\BuzzerSoundEffect.wav"

using namespace std;
int main()
{
	//PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC);
	//PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC);
	while (1)
	{

		//1970년 1월 1일 자정부터 현재까지의 초 반환
		int totalSeconds = time(0);	

		// 현재 시간의 초(Sec) 계산
		int currentSecond = totalSeconds % 60;

		// 전체 분(Minutes) 계산
		int totalMinutes = totalSeconds / 60;

		// 현재의 시간 분 계산
		int currentMinute = totalMinutes % 60;

		//전체 시간(Hours) 계산
		//UCT -> KST 바꿔주기 위해 9를 더한다.
		int totalHours = totalMinutes / 60 + 9;

		//현재 시간 계산
		int currrentHour = totalHours % 24;

		int num = (totalHours % 168) / 24;
		//cout << "totalHours % 168 : " << totalHours % 168 << endl;
		//cout << "num :"<<num << endl;
		char day[8];

		int classes[7] = {0,0,0,0,0,0,0};
		char userans_d1[20];
		if (num == 6) {
			char day_temp[8] = "월요일";
			strcpy(day, day_temp);
		}
		else if (num == 5) {
			char day_temp[8] = "화요일";
			strcpy(day, day_temp);
		}
		else if (num == 4) {
			char day_temp[8] = "수요일";
			strcpy(day, day_temp);
		}
		else if (num == 3) {
			char day_temp[8] = "목요일";
			strcpy(day, day_temp);
		}
		else if (num == 2) {
			char day_temp[8] = "금요일";
			strcpy(day, day_temp);
		}
		else if (num == 1) {
			char day_temp[8] = "토요일";
			strcpy(day, day_temp);
		}
		else if (num == 0) {
			char day_temp[8] = "일요일";
			strcpy(day, day_temp);
		}
		for (int i = 0; i < 7; i++)
		{
			while (1)
			{
				printf("오늘 %s %d%d%d%d%d%d 교시에는 수업이 있습니까? (Y/N) or (1/0)\n>>",day,i+1, i + 1, i + 1, i + 1, i + 1, i + 1);
				scanf("%s", userans_d1);
				if (userans_d1[0] == 'y' || userans_d1 == "yes" || userans_d1[0] == '1')
				{
					classes[i] = 1;
					//cout << 'y' << endl;
					break;}
				else if (userans_d1[0] == 'n' || userans_d1 == "no" || userans_d1[0] == '0') {
					classes[i] = 0;
					//cout << 'n' << endl;
					break;}
				else {
					printf("답변이 잘못됐습니다.\n");
					continue;}
			}
		}
		//PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC);
		//13시30분 => 1330 만들고, 나중에 풀때 %100 와 /100 해서 나누기
		int start_times[7] = {0,0,0,0,0,0,0};
		for (int i = 0; i < 7; i++)
		{
			
			if (classes[i] == 1)
			{
				int start_time = 0;
				//1교시 시작시간 : 08:40
				//2교시 시작시간 : 09:30
				//3교시 시작시간 : 10:20
				//4교시 시작시간 : 11:10
				//5교시 시작시간 : 12:50
				//6교시 시작시간 : 13:40
				//7교시 시작시간 : 14:30
				switch (i)
				{
				case 0:
					start_time = 840;
					start_times[0] = start_time;
					break;
				case 1:
					start_time = 930;
					start_times[1] = start_time;
					break;
				case 2:
					start_time = 1020;
					start_times[2] = start_time;
					break;
				case 3:
					start_time = 1110;
					start_times[3] = start_time;
					break;
				case 4:
					start_time = 1250;
					start_times[4] = start_time;
					break;
				case 5:
					start_time = 1340;
					start_times[5] = start_time;
					break;
				case 6:
					start_time = 1430;
					start_times[6] = start_time;
					break;
				default:
					break;
				}
			}
		}
		for (int i = 0; i < 7; i++)
		{
			printf("classes[%d] = %d\n", i, classes[i]);
		}
		int temp = 0;
		while (1) {

			int totalSeconds = time(0);
			int currentSecond = totalSeconds % 60;
			int totalMinutes = totalSeconds / 60;
			int currentMinute = totalMinutes % 60;
			int totalHours = totalMinutes / 60 + 9;
			int currrentHour = totalHours % 24;

			//출력
			
			cout /*<< day*/ << " Time " << currrentHour << " : "
			<< currentMinute << " : "
			<< currentSecond << endl;
			//printf("(currrentHour * 100) + currentMinute = %d\n", (currrentHour * 100) + currentMinute);
			for (int i = 0; i < 7; i++)
			{
				if (start_times[i] != 0)
				{
					temp = (currrentHour * 100) + currentMinute;
					//printf("start_times[%d] = %d\n",i ,start_times[i]);
					//printf("start_times[%d] - temp = %d\n", i, start_times[i] - temp);
					if (start_times[i] - temp < 5 && start_times[i] - temp > 0)
					{
						//printf("start_times[i] - temp < 5 = %d\n", start_times[i] - temp < 5);
						//printf("start_times[i] - temp = %d\n", start_times[i] - temp);
						//printf("start_times[i] - temp > 0 = %d\n", start_times[i] - temp > 0);
						//printf("start_times[i] - temp < 5 && start_times - temp > 0 = %d\n", start_times[i] - temp < 5 && start_times[i] -temp > 0);
						start_times[i] = 2;
						for (int a = 0; a < i+1; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								printf("%d%d%d%d%d%d교시 수업 5분전\n",i+1, i + 1, i + 1, i + 1, i + 1, i + 1);
							}
							PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC);
							if (i <= 3)
							{
								Sleep(10000);
							}
							else {
							Sleep(3000);
							}
						}
					}
					else if (start_times[i] - temp < 0) {
						printf("%d교시 시작함.\n",i + 1);
					}
					else if (start_times[i] == 2) {
						printf("%d교시 곧 시작함.\n", i+1);
					}
					else {
						//temp / 100 시간
						//temp % 100 분
						// (temp / 100) * 60 + (temp % 100)
						// (start_times[i] / 100) * 60 + (start_times[i] % 100)
						printf("%d교시 시작까지 남은 시간 : %d분\n", i + 1, ((start_times[i] / 100) * 60 + (start_times[i] % 100)) - ((temp / 100) * 60 + (temp % 100)));
					}
				}
				else if (start_times[i] == 0) {
					printf("%d교시 오늘 수업일정 없음\n",i+1);
				}
			}
			Sleep(1000);
			system("cls");
		}

		//일주일
		//168 -24 = 일요일 시작 0시
		//168 -24 -24 = 토요일 시작 0시
		//168 -24 -24 -24 = 금요일 시작 0시
		//168 -24 -24 -24 -24 = 목요일 시작 0시
		//168 -24 -24 -24 -24 -24 = 수요일 시작 0시
		//168 -24 -24 -24 -24 -24 -24= 화요일 시작 0시
		//168 -24 -24 -24 -24 -24 -24 -24= 월요일 시작 0시

		//전체 {'시간'(Hour) % 168} / 24 = 몇번(num)
		//num 이 6 이라면 월요일
		//num 이 5 이라면 화요일
		//num 이 4 이라면 수요일
		//num 이 3 이라면 목요일
		//num 이 2 이라면 금요일
		//num 이 1 이라면 토요일
		//num 이 0 이라면 일요일

		//1교시 시작시간 : 08:40
		//2교시 시작시간 : 09:30
		//3교시 시작시간 : 10:20
		//4교시 시작시간 : 11:10
		//5교시 시작시간 : 12:50
		//6교시 시작시간 : 13:40
		//7교시 시작시간 : 14:30






	}
    






    return 0;
}