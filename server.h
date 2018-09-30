// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *   Copyright (C) 2018 Samsung Electronics Co., Ltd.
 */

#ifndef __SERVER_H__
#define __SERVER_H__

#define SERVER_STATE_STARTING_UP	0
#define SERVER_STATE_RUNNING		1
#define SERVER_STATE_SHUTTING_DOWN	2

#define SERVER_CONF_NETBIOS_NAME	0
#define SERVER_CONF_SERVER_STRING	1
#define SERVER_CONF_WORK_GROUP		2

struct cifsd_server_config {
	int		state;
	char		*conf[SERVER_CONF_WORK_GROUP + 1];

	short		signing;
	short		enforced_signing;
	short		min_protocol;
	short		max_protocol;
};

extern struct cifsd_server_config server_conf;

int cifsd_set_netbios_name(char *v);
int cifsd_set_server_string(char *v);
int cifsd_set_work_group(char *v);

char *cifsd_netbios_name(void);
char *cifsd_server_string(void);
char *cifsd_work_group(void);

static inline int cifsd_server_running(void)
{
	return server_conf.state == SERVER_STATE_RUNNING;
}

static inline void cifsd_server_set_running(void)
{
	server_conf.state = SERVER_STATE_RUNNING;
}

int cifsd_server_shutdown(void);
#endif /* __SERVER_H__ */