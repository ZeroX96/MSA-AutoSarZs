/*
 * ComStack_Types.h
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef COMSTACK_TYPES_H_
#define COMSTACK_TYPES_H_
/* REQ
 * All software modules shall provide version and identification information
 * ComStack_Types   V0.0.0
 * AUTOSAR          V4.3.1
 */
/******************module******************/
#define COMSTACK_TYPES_MAJOR_VERSION   0
#define COMSTACK_TYPES_MINOR_VERSION   0
#define COMSTACK_TYPES_PATCH_VERSION   0
/******************autosar******************/
#define COMSTACK_TYPES_AR_MAJOR_VERSION   4
#define COMSTACK_TYPES_AR_MINOR_VERSION   3
#define COMSTACK_TYPES_AR_PATCH_VERSION   1

#include "Std_Types.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if((COMSTACK_TYPES_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION)||\
    (COMSTACK_TYPES_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION)||\
    (COMSTACK_TYPES_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
  #error "The AR version of ComStack_Types.h differ than Std_Types.h"

#endif

typedef IcomConfigIdType;
typedef IcomSwitch_ErrorType;

/*PduIdType
 * The size of this global type depends on the maximum number of PDUs used within one software module.
 * This parameter shall be generated by the generator tool.
 */
typedef uint16 PduIdType;

/*PduLengthType
 * The size of this global type depends on the maximum length of PDUs to be sent by an ECU.
 * This parameter shall be generated by the generator tool.
 */
typedef uint32 PduLengthType;

typedef struct
{
    /*SduDataPtr
     * Pointer to the SDU (i.e. payload data) of the PDU.
     * The type of this pointer depends on the memory model being used at compile time*/
    uint8* SduDataPtr;
    /*MetaDataPtr
     * Pointer to the meta data (e.g. CAN ID, socket ID, diagnostic addresses)*/
    uint8*  MetaDataPtr;
    /*SduLength
     * Length of the SDU in bytes.*/
    PduLengthType  SduLength
}PduInfoType;

/*PNCHandleType
 * Used to store the identifier of a partial network cluster*/
typedef uint8 PNCHandleType;

/*TPParameterType
 * Specify the parameter to which the value has to be changed (BS or STmin)
 * Can take one of the following [TP_STMIN-TP_BS-TP_BC]
 */
#define TPParameterType TP_STMIN

#define TP_STMIN  0x00  //Separation Time
#define TP_BS     0x01  //Block Size
#define TP_BC     0x02  //The Band width control parameter used in FlexRay transport protocol module.

/*BufReq_ReturnType
 * Variables of this type shall be used to store the result of a buffer request.
 * Can take one of the following [BUFREQ_OK-BUFREQ_E_NOT_OK-BUFREQ_E_BUSY-BUFREQ_E_OVFL]
 * */
#define BufReq_ReturnType BUFREQ_OK

#define BUFREQ_OK        0x00  //Buffer request accomplished successful.
#define BUFREQ_E_NOT_OK  0x01  //Buffer request not successful. Buffer cannot be accessed.
#define BUFREQ_E_BUSY    0x02  //Temporarily no buffer available. It's up the requester to retry request for a certain time.
#define BUFREQ_E_OVFL    0x03  //No Buffer of the required length can be provided.

/*TpDataStateType
 * Variables of this type shall be used to store the state of TP buffer.
 * Can take one of the following [TP_DATACONF-TP_DATARETRY-TP_CONFPENDING]
 * */
#define TpDataStateType TP_DATACONF

#define TP_DATACONF  0x00    //TP_DATACONF indicates that all data, that have been copied so far,
                             //are confirmed and can be removed from the TP buffer.
                             //Data copied by this API call are excluded and will be confirmed later.

#define TP_DATARETRY  0x01    //TP_DATARETRY indicates that this API call shall copyalready copied data
                              //in order to recover from an error. In this case TxTpDataCnt specifies
                              //the offset of the first byte to be copied by the API call.

#define TP_CONFPENDING  0x02  //TP_CONFPENDING indicates that the previously copied data must remain in the TP.


#endif /* COMSTACK_TYPES_H_ */