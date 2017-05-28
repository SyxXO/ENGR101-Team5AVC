#include <stdio.h>
#include "E101.h"

void open_gate(){
    char ip[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
    char please[24] = {'P','l','e','a','s','e'};
    char password[30];
    connect_to_server(ip,1024);
    send_to_server(please);
    receive_from_server(password);
	send_to_server(password);
}

int main(){
	init();
	open_gate();
	sleep1(1,0);
	set_motor(1,255);
	set_motor(2,-255);
	sleep1(3,0);
	set_motor(2,0);
	set_motor(1,0);
	stop(0);
}
