#include "signal_control.h"

// 信号の初期化を行う関数
void Signal_Init(SignalData* signal) {
	signal->state = SIGNAL_RED;
	signal->elapsed_count = 0;

	signal->red_count = 100;
	signal->green_count = 100;
	signal->yellow_count = 30;
}

// タイマーを更新する関数
void Signal_UpdateTimer(SignalData* signal) {
	signal->elapsed_count++;
}

// 信号状態の更新処理を行う関数
void Signal_UpdateState(SignalData* signal) {

	// 赤から青への遷移
	if (signal->state == SIGNAL_RED) {
		if (signal->elapsed_count >= signal->red_count) {
			signal->state = SIGNAL_GREEN;
			signal->elapsed_count = 0;
		}
	}
	
	// 青から黄への遷移
	else if (signal->state == SIGNAL_GREEN) {
		if (signal->elapsed_count >= signal->green_count) {
			signal->state = SIGNAL_YELLOW;
			signal->elapsed_count = 0;
		}
	}

	// 黄から赤への遷移
	else if (signal->state == SIGNAL_YELLOW) {
		if (signal->elapsed_count >= signal->yellow_count) {
			signal->state = SIGNAL_RED;
			signal->elapsed_count = 0;
		}
	}


}