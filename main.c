#include <xc.h>

// --- コンフィギュレーション設定 (PIC18F14K50) ---
// CONFIG1H
#pragma config FOSC = IRC           // 内部発振器
#pragma config PLLEN = OFF          // PLL無効
#pragma config PCLKEN = ON          // プライマリクロック有効

// CONFIG2L
#pragma config BOREN = OFF          // ブラウンアウトリセット無効

// CONFIG2H
#pragma config WDTEN = OFF          // ウォッチドッグタイマー無効

// CONFIG3H
#pragma config MCLRE = ON           // MCLRピン有効

// CONFIG4L
#pragma config LVP = ON             // 低電圧書き込み有効 (Picoプログラマに必須)
#pragma config STVREN = ON          // スタックフルでリセット

#define _XTAL_FREQ 1000000          // 1MHz (内部発振器のデフォルト)

void main(void) {
    // OSCCON = 0x30; // 内部 1MHz (必要に応じて調整)

    // ポート設定: RC0を出力に設定
    TRISCbits.TRISC0 = 0;

    while (1) {
        LATCbits.LATC0 = 1;  // 点灯
        __delay_ms(500);
        LATCbits.LATC0 = 0;  // 消灯
        __delay_ms(500);
    }
}
