#include "8051.h"

// 定义串口波特率
#define BAUDRATE 9600

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void init_serial() {
    TMOD = 0X20;
    TH1 = 256 - (11059200UL / 12 / 32 / BAUDRATE);
    TR1 = 1;  // 启动定时器1
    // 设置串口工作模式
    SCON = 0x50;  // 设置串口为模式1，允许接收

    // 启用全局中断
    EA = 1;
    ES = 1;  // 启用串口中断
}

// 串口发送一个字符
void putchar_test(char c) {
    SBUF = c;
    while (!TI) {}  // 等待发送完成
    TI = 0;  // 清除发送完成标志位
}

// 串口发送字符串
void puts_test(const char *str) {
    while (*str) {
        putchar_test(*str++);
    }
}
