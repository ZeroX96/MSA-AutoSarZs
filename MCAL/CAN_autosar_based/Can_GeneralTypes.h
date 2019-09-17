/*
 * Can_GeneralTypes.h
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef CAN_GENERALTYPES_H_
#define CAN_GENERALTYPES_H_

/* REQ
 * All software modules shall provide version and identification information
 * ComStack_Types   V0.0.0
 * AUTOSAR          V4.3.1
 */
/******************module******************/
#define CAN_GENERALTYPES_MAJOR_VERSION   0
#define CAN_GENERALTYPES_MINOR_VERSION   0
#define CAN_GENERALTYPES_PATCH_VERSION   0
/******************autosar******************/
#define CAN_GENERALTYPES_AR_MAJOR_VERSION   4
#define CAN_GENERALTYPES_AR_MINOR_VERSION   3
#define CAN_GENERALTYPES_AR_PATCH_VERSION   1


#define Can_ControllerStateType CAN_CS_UNINIT

#define CAN_CS_UNINIT  0x00 //CAN controller state UNINIT.
#define CAN_CS_STARTED 0x01 //CAN controller state STARTED.
#define CAN_CS_STOPPED 0x02 //CAN controller state STOPPED.
#define CAN_CS_SLEEP   0x03 //CAN controller state SLEEP.

#define Can_ErrorStateType CAN_ERRORSTATE_ACTIVE

#define CAN_ERRORSTATE_ACTIVE  0x00 //The CAN controller takes fully part in communication.
#define CAN_ERRORSTATE_PASSIVE 0x01 //The CAN controller takes part in communication, but does not send active error frames
#define CAN_ERRORSTATE_BUSOFF  0x02 //The CAN controller does not take part in communication.

//check if std or ext
typedef uint16 Can_HwHandleType;
typedef uint32 Can_IdType;

typedef struct
{
    Can_IdType          CanId;          //Standard/Extended CAN ID of CAN LPDU
    Can_HwHandleType    Hoh;            //ID of the corresponding Hardware Object Range
    uint8               ControllerId;   //ControllerId provided by CanIf clearly identify the corresponding controller
}Can_HwType;

typedef struct
{
    PduIdType   swPduHandle;    //define pduidtype
    uint8       length;
    Can_IdType  id;
    uint8*      sdu;
}Can_PduType;

#endif /* CAN_GENERALTYPES_H_ */
