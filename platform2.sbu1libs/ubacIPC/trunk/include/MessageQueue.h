#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#include <ubacutils/Exceptions.h>

using namespace std;

namespace UBACIPC {

    template < class MessageQueueItem >
        class MessageQueue {

            public:
                MessageQueue( key_t key, bool bNewQ = false ) {

                    this->bOwner = bNewQ;

                    int msgflg = 0;
                    if( bNewQ ) {

                        msgflg |= IPC_CREAT | 0660;

                    }
                    
                    /* Default Queue Size is 16384 bytes */
                    if( ( msgid = msgget( key, msgflg ) ) == -1 ) {

                        Exceptions ex;
                        ex.setMessage( "msgget failed : " );
                        ex.setMessage( strerror( errno ) );
                        throw ex;

                    }

                    //setMessageQueueSize();

                }

                ~MessageQueue(){

                    if( bOwner && ( msgctl( msgid, IPC_RMID, NULL ) == -1 ) ){

                        Exceptions ex;
                        ex.setMessage( "msgctl failed : " );
                        ex.setMessage( strerror( errno ) );
                        throw ex;

                    }

                }

                void enqueue( const MessageQueueItem & item, long mtype = 1 ){

                    struct msgbuf msgQBuf;
                    msgQBuf.mtype = mtype;
                    memmove( &(msgQBuf.item), &item, sizeof( MessageQueueItem ) );

                    if( msgsnd( msgid, &msgQBuf, sizeof( MessageQueueItem ), 0 ) == -1 ) {

                        Exceptions ex;
                        ex.setMessage( "msgsnd failed : " );
                        ex.setMessage( strerror( errno ) );
                        throw ex;

                    }

                }

                MessageQueueItem dequeue( long mtype = 0 ){

                    struct msgbuf msgQBuf;
                    if( msgrcv( msgid, &msgQBuf, sizeof( MessageQueueItem ), mtype, 0 ) == -1 ) {

                        Exceptions ex;
                        ex.setMessage( "msgrcv failed : " );
                        ex.setMessage( strerror( errno ) );
                        throw ex;

                    }

                    return msgQBuf.item;

                }

                void setMessageQueueSize(msglen_t queueSize) {

                    Exceptions ex;

                    if(queueSize > MAX_QUEUE_SIZE_IN_BYTES)
                    {
                        ex.setMessage("Max Queue size permitted is 67108864.");
                        throw ex;
                    }

                    if( msgctl( msgid, IPC_STAT, &queueProperties) < 0 )
                    {
                        ex.setMessage("Queue properties reading error : ");
                        ex.setMessage( strerror( errno ) );
                        throw ex;
                    }

                    queueProperties.msg_qbytes = queueSize;

                    if( msgctl( msgid, IPC_SET, &queueProperties) < 0 )
                    {
                        ex.setMessage("Invalid queue configuration : ");
                        ex.setMessage( strerror( errno ) );
                        throw ex;
                    }
                }

                void setNonBlocking(){
                }

            private:

                struct msgbuf {

                    long mtype; /* message type, must be > 0 */
                    MessageQueueItem item; /* message data */

                };

                struct msqid_ds queueProperties;

                int msgid;
                bool bOwner;

                static const msglen_t MAX_QUEUE_SIZE_IN_BYTES = 64*1024*1024; // Max Queue Size
        };

};

#endif /* __MESSAGE_QUEUE_H__ */
