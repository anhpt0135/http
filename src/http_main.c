/*
 * http_main.c
 *
 *  Created on: Apr 28, 2020
 *      Author: anhpt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "http_main.h"

CAMSETTING1 *g_cam_setting = NULL;

int http_server_running(CAMSETTING1 *setting){
	int ret = 0;
	struct addrinfo hints;
	g_cam_setting = setting;// because setting is already allocated in the main.c
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	struct addrinfo *bindAddress;
	if(getaddrinfo(0,"80", &hints, &bindAddress)<0){
		perror("getaddrinfo() failed:\n");
		return errno;
	}

	int socket_listen = socket(bindAddress->ai_family, bindAddress->ai_socktype, bindAddress->ai_protocol);
	if(ret <=0 ){
		perror("socket() failed: \n");
		return errno;
	}
	ret = bind(socket_listen, bindAddress->ai_addr, bindAddress->ai_addrlen);
	if(ret < 0){
		perror("bind() failed:\n");
		return errno;
	}
	free(bindAddress);
	ret = listen(socket_listen, 10);
	if(ret < 0){
		perror("listen() failed:\n");
		return errno;
	}
	printf("Waiting for connection...\n");

	struct sockaddr_storage client_address;
	socklen_t client_len = sizeof(client_address);
	int sock_peer = accept(socket_listen, (struct sockaddr*) &client_address, &client_len);
	if(sock_peer <= 0){
		perror("accept() failed \n");
		return errno;
	}

	printf("accept the conection \n");

	return 0;
}
