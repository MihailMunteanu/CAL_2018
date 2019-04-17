#include "m_communication.h"

/*
 * u8Message:
 * [7-6] bits of message are for ROAD   (binary to dec)
 * [5-4] bits of message are for DIRECTION  (binary to dec: 0-inainte 1-stanga 2-dreapta)
 * [3-1] bits : NOT USED yet
 *   [0] bit of message is reserved for TYPE OF MESSAGE (0-external 1-internal)
 */

void vInterpretMessage (T_U8 u8Message)
{
    static struct _sQueue{
            T_U8 u8Road;
            T_U8 u8Direction;
            BOOL bPassedIntersection;
            BOOL bIsInIntersection;
        }sQueue[4];
        static T_U8 u8Index = 0;
        static T_U8 u8CarID = 5;
        static BOOL bQueueFull = 0;
        //if queue was already completed, 
        //do not enter this if() statement
        if ( 0 == bQueueFull )
        {
            T_U8 u8MessageCopy = u8Message;
            sQueue[u8Index].u8Road = u8MessageCopy >> 6;
            u8MessageCopy = u8Message;
            sQueue[u8Index].u8Direction = (u8MessageCopy >> 4) & 3;
            sQueue[u8Index].bPassedIntersection = 0;
            sQueue[u8Index].bIsInIntersection = 0;
            if ( u8Message & 1 ) 
            {
                u8CarID = sQueue[u8Index].u8Road;
            }
            if ( 3 == u8Index )
            {
                bQueueFull = 1;
                u8Index = 0;
            }
            else
            {
                u8Index++;
            }
        }
        //receives message and has to interpret it
        else 
        {
            
        }
}