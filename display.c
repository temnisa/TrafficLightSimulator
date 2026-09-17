#include <stdio.h>
#include "display.h"

void Display_ShowState(SignalData* signal) {

	//system("cls"); // 画面をクリア

	// 赤信号の表示
	if (signal->state == SIGNAL_RED) {
		printf("信号：赤\n");
	}
	
	// 青信号の表示
	else if(signal->state == SIGNAL_GREEN){
		printf("信号：青\n");
	}

	// 黄信号の表示
	else if (signal->state == SIGNAL_YELLOW) {
		printf("信号：黄\n");
	}
}

void Display_ShowElapsedTime(SignalData* signal) {

	double elapsed_time;

	elapsed_time = signal->elapsed_count * 0.1; // 100ms単位なので0.1を掛ける

	printf("経過時間：%.1f秒\n", elapsed_time);

}