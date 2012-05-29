
/*!
 * \file 	sccp_channel.h
 * \brief 	SCCP Channel Header
 * \author 	Sergio Chersovani <mlists [at] c-net.it>
 * \date
 * \note	Reworked, but based on chan_sccp code.
 *        	The original chan_sccp driver that was made by Zozo which itself was derived from the chan_skinny driver.
 *        	Modified by Jan Czmok and Julien Goodwin
 * \note        This program is free software and may be modified and distributed under the terms of the GNU Public License.
 *		See the LICENSE file at the top of the source tree.
 *
 * $Date$
 * $Revision$  
 */

#ifndef __SCCP_CHANNEL_H
#    define __SCCP_CHANNEL_H

#    define sccp_channel_release(x) 		__sccp_channel_release(x, __FILE__, __LINE__, __PRETTY_FUNCTION__)
#    define sccp_channel_retain(x) 		__sccp_channel_retain(x, __FILE__, __LINE__, __PRETTY_FUNCTION__)

sccp_channel_t *sccp_channel_allocate(sccp_line_t * l, sccp_device_t * device);	// device is optional
inline sccp_channel_t *__sccp_channel_retain(sccp_channel_t * c, const char *filename, int lineno, const char *func);
inline sccp_channel_t *__sccp_channel_release(sccp_channel_t * c, const char *filename, int lineno, const char *func);

#    define sccp_channel_get_active_nolock sccp_channel_get_active						//temporary
#    define sccp_channel_get_active_lock sccp_channel_get_active						//temporary
#    define sccp_channel_get_active sccp_channel_get_active							//temporary
sccp_channel_t *sccp_channel_get_active(const sccp_device_t * d);
void sccp_channel_updateChannelDesignator(sccp_channel_t * c);
void sccp_channel_updateChannelCapability(sccp_channel_t * channel);
void sccp_channel_set_active(sccp_device_t * d, sccp_channel_t * c);
void sccp_channel_send_callinfo(sccp_device_t * device, sccp_channel_t * c);
void sccp_channel_send_callinfo2(sccp_channel_t * c);
void sccp_channel_setSkinnyCallstate(sccp_channel_t * c, skinny_callstate_t state);
void sccp_channel_display_callInfo(sccp_channel_t * channel);
void sccp_channel_set_callingparty(sccp_channel_t * c, char *name, char *number);
void sccp_channel_set_calledparty(sccp_channel_t * c, char *name, char *number);
boolean_t sccp_channel_set_originalCallingparty(sccp_channel_t * channel, char *name, char *number);
boolean_t sccp_channel_set_originalCalledparty(sccp_channel_t * c, char *name, char *number);
void sccp_channel_reset_calleridPresenceParameter(sccp_channel_t * c);
void sccp_channel_set_calleridPresenceParameter(sccp_channel_t * c, sccp_calleridpresence_t presenceParameter);
void sccp_channel_connect(sccp_channel_t * c);
void sccp_channel_disconnect(sccp_channel_t * c);
void sccp_channel_openreceivechannel(sccp_channel_t * c);
void sccp_channel_startmediatransmission(sccp_channel_t * c);
void sccp_channel_closereceivechannel(sccp_channel_t * c);
void sccp_channel_stopmediatransmission(sccp_channel_t * c);
void sccp_channel_openMultiMediaChannel(sccp_channel_t * channel);
void sccp_channel_startMultiMediaTransmission(sccp_channel_t * channel);
void sccp_channel_endcall(sccp_channel_t * c);
void sccp_channel_StatisticsRequest(sccp_channel_t * c);
sccp_channel_t *sccp_channel_newcall(sccp_line_t * l, sccp_device_t * device, char *dial, uint8_t calltype);
void sccp_channel_answer(const sccp_device_t * d, sccp_channel_t * c);
void sccp_channel_destroy(sccp_channel_t * c);

//int sccp_channel_destroy_callback(const void *data);
void sccp_channel_clean(sccp_channel_t * c);
int sccp_channel_hold(sccp_channel_t * c);
int sccp_channel_resume(sccp_device_t * device, sccp_channel_t * c, boolean_t swap_channels);

void sccp_channel_transfer(sccp_channel_t * c);
void sccp_channel_transfer_complete(sccp_channel_t * c);
void sccp_channel_forward(sccp_channel_t * parent, sccp_linedevices_t * lineDevice, char *fwdNumber);

#    if DEBUG
#        define sccp_channel_getDevice_retained(_x) __sccp_channel_getDevice_retained(_x, __FILE__,__LINE__,__PRETTY_FUNCTION__)
sccp_device_t *__sccp_channel_getDevice_retained(const sccp_channel_t * channel, const char *filename, int lineno, const char *func);
#    else
sccp_device_t *sccp_channel_getDevice_retained(const sccp_channel_t * channel);
#    endif
void sccp_channel_setDevice(sccp_channel_t * channel, const sccp_device_t * device);
const char *sccp_channel_device_id(const sccp_channel_t * channel);

#    ifdef CS_SCCP_PARK
void sccp_channel_park(sccp_channel_t * c);
#    endif

boolean_t sccp_channel_setPreferredCodec(sccp_channel_t * c, const void *data);
int sccp_channel_callwaiting_tone_interval(sccp_channel_t * c);

#endif
