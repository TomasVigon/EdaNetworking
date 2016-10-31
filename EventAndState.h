
#ifndef EVENTANDSTATE_H
#define EVENTANDSTATE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {IDLE,FIRST_WRITE,FIRST_READ,WRITE,READ,LAST_WRITE,FINISH} typeState;
typedef enum {wrq,rrq,timeout,ack,quit,last_data,data,error}	typeEvent;

#ifdef __cplusplus
}
#endif

#endif /* EVENTANDSTATE_H */

