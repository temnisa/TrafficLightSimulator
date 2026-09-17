#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "signal_control.h"
#include "display.h"


int main(void) {
	SignalData signal;

	// 初期化
	Signal_Init(&signal);

	while (1) {


		Sleep(100);							// 100ms待機

		Signal_UpdateTimer(&signal);		// タイマーを更新
		Signal_UpdateState(&signal);		// 信号の状態を更新
		Display_ShowState(&signal);			// 信号の状態を表示
		Display_ShowElapsedTime(&signal);   // 経過時間を表示
		
		if (_kbhit()) {						// キー入力があった場合
			char ch = _getch();				// キー入力を取得
			if (ch == 'q') {				// 'q'キーで終了
				break;
			}
		}

	}

	return 0;
}