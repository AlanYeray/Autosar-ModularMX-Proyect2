#ifndef _IOHWAB_H_
#define _IOHWAB_H_

#include "StandardTypes.h" //Std_ReturnType

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*/
#define PORT_VENDOR_ID                    434
#define PORT_MODULE_ID                    1244
#define PORT_AR_RELEASE_MAJOR_VERSION     44
#define PORT_AR_RELEASE_MINOR_VERSION     77
#define PORT_AR_RELEASE_REVISION_VERSION  00
#define PORT_SW_MAJOR_VERSION             22
#define PORT_SW_MINOR_VERSION             0
#define PORT_SW_PATCH_VERSION             0

typedef struct _IoHwAb_ConfigType
{
 uint8 value;

}IoHwAb0_ConfigType;




void IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr );

void IoHwAb_GetVersionInfo( Std_VersionInfoType* versioninfo );

#endif