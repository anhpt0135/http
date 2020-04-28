/*
 ============================================================================
 Name        : serverhttp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "http_main.h"
#include "callback/callback.h"
int main(void) {
	int ret = 0;
	CAMSETTING1 *setting = malloc(sizeof(CAMSETTING1));
	setting->authencation_callback = authencation_callback_func;
	setting->mellody_callback = mellody_callback_func;
	ret = http_server_running(setting);
	if(ret != 0){
		free(setting);
		perror("http_server_running() failed \n");
		return ret;
	}
	free(setting);
	return EXIT_SUCCESS;
}
