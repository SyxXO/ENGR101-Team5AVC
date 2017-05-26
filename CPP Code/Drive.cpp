#include <stdio.h>
#include "E101.h"

void wifi_gate(){ //opens the wifi gate
        char ip[15];
        char please[24];
        please[0] = 'P';
        please[1] = 'l';
        please[2] = 'e';
        please[3] = 'a';
        please[4] = 's';
        please[5] = 'e';
        ip[0] = '1';
        ip[1] = '3';
        ip[2] = '0';
        ip[3] = '.';
        ip[4] = '1';
        ip[5] = '9';
        ip[6] = '5';
        ip[7] = '.';
        ip[8] = '6';
        ip[9] = '.';
        ip[10] = '1';
        ip[11] = '9';
        ip[12] = '6';
        char password[30];
        connect_to_server(ip,1024);
        send_to_server(please);
        receive_from_server(password);
        send_to_server(password);
}
int main(){
	
}
