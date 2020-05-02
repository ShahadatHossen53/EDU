#include <reg52.h>
#define SW P0
#define LED P2
void main(){
	SW = 0xFF;
	LED = 0x00;
	while(1)
		LED  = SW;
}