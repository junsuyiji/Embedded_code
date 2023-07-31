#include "8051.h"
#include "send.h"

// 定义串口波特率
#define BAUDRATE 9600

// 主函数
void main() {
    init_serial();  // 初始化串口

    while (1) {
		puts_test("Hello World!\n");
		Delay(1000);
	}  // 程序主循环
}
