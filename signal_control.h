#ifndef SIGNAL_CONTROL_H
#define SIGNAL_CONTROL_H

// 信号の状態を表す列挙型
typedef enum {
	SIGNAL_RED,
	SIGNAL_YELLOW,
	SIGNAL_GREEN

} SignalState;

// 信号のデータを保持する構造体
typedef struct {
	SignalState state;
	int elapsed_count;

	int red_count;
	int green_count;
	int yellow_count;

}SignalData;

// 信号の初期化を行う関数
void Signal_Init(SignalData* signal);

// タイマーを更新する関数
void Signal_UpdateTimer(SignalData* signal);

// 信号の状態を更新する関数
void Signal_UpdateState(SignalData* signal);

#endif