/*
 * http_main.h
 *
 *  Created on: Apr 28, 2020
 *      Author: anhpt
 */

#ifndef HTTP_MAIN_H_
#define HTTP_MAIN_H_

typedef struct CAMSETTING1{
	int(*authencation_callback)(int command_id, char *input, char *output);
	int(*mellody_callback)(int command_id, char *input, char *output);
}CAMSETTING1;

int http_server_running(CAMSETTING1 *setting);

#endif /* HTTP_MAIN_H_ */
