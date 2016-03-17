#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mf_msg_parser.h"
#include "mf_msg_handler.h"
#include "mf_logger.h"
#include "mf_rx_queue.h"
#include "mf_switch.h"
#include "./Openflow/openflow.h"
#include "./Openflow/openflow-common.h"

static inline uint8_t parse_msg_type(struct q_node* qn)
{
	if(qn == NULL || qn->rx_packet == NULL)
	{
		return 0;
	}
	uint8_t type;
	memcpy(&type, qn->rx_packet + 1, 1);
	return type;
}

static inline uint8_t parse_msg_version(struct q_node* qn)
{
	if(qn == NULL || qn->rx_packet == NULL)
	{
		return 0;
	}
	uint8_t version;
	memcpy(&version, qn->rx_packet, 1);
	return version;
}

void parse_msg(struct mf_switch* sw, struct q_node* qn)
{
	if(sw==NULL || qn == NULL)
	{
		printf("invalid node\n");
	}
	else
	{
		uint8_t type = parse_msg_type(qn);
		uint8_t version = parse_msg_version(qn);
		msg_handler(sw, type, version, qn);
	}

}

