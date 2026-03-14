/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
 *   @file Det.c
 *
 *   @addtogroup DET_MODULE
 *   @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section Det_c_REF_1
 * Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
 * This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
 *
 * @section Det_c_REF_2
 * Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
 * <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
 */

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
 * @file           Det.c
 * @requirements   DET004
 */
#include "Mcal.h"
#include "OsIf.h"
#include "Det.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DET_VENDOR_ID_C 43
#define DET_AR_RELEASE_MAJOR_VERSION_C 4
#define DET_AR_RELEASE_MINOR_VERSION_C 7
#define DET_AR_RELEASE_REVISION_VERSION_C 0
#define DET_SW_MAJOR_VERSION_C 2
#define DET_SW_MINOR_VERSION_C 0
#define DET_SW_PATCH_VERSION_C 0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DET header file are of the same vendor */
#if (DET_VENDOR_ID_C != DET_VENDOR_ID)
#error "Det.c and Det.h have different vendor ids"
#endif

/* Check if source file and DET header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
     (DET_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Det.c and Det.h are different"
#endif

/* Check if source file and DET header file are of the same Software version */
#if ((DET_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
     (DET_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
     (DET_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION))
#error "Software Version Numbers of Det.c and Det.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if DET source file and STD header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Det.c and Std_Types.h are different"
#endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#include "Port.h"
#include "Dio.h"
    DefaultErrorTrace_dinamic Port_Det_Handler_dinamic[SIZE_PORT_HASH] =
        {
            {.ApiId = PORT_INIT_ID,
             .cApi = "Port_Init()\0",
             .ErrorId = PORT_E_PARAM_CONFIG,
             .cError = " Port Init Failed wrong parameter . Failed\0"},
            {.ApiId = PORT_INIT_ID,
             .cApi = "Port_Init()\0",
             .ErrorId = PORT_E_INIT_FAILED,
             .cError = "Port Init Failed\0"},
            {.ApiId = PORT_SETPINDIRECTION_ID,
             .cApi = "Port_SetPinDirection()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "  API service called without module initialization. Failed\0 "},
            {.ApiId = PORT_SETPINDIRECTION_ID,
             .cApi = "Port_SetPinDirection()\0",
             .ErrorId = PORT_E_DIRECTION_UNCHANGEABLE,
             .cError = "Port Pin not configured as changeable. Failed\0"},
            {.ApiId = PORT_SET2PINSDIRECTION_ID,
             .cApi = "Port_Set2PinDirection()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called without module initialization. Failed\0"},
            {.ApiId = PORT_SET2PINSDIRECTION_ID,
             .cApi = "Port_Set2PinDirection()\0",
             .ErrorId = PORT_E_PARAM_PIN,
             .cError = "invalid Port Pin ID requested. Failed\0"},
            {.ApiId = PORT_SET2PINSDIRECTION_ID,
             .cApi = "Port_Set2PinDirection()\0",
             .ErrorId = PORT_E_DIRECTION_UNCHANGEABLE,
             .cError = "Port Pin not configured as changeable. Failed\0"},
            {.ApiId = PORT_SETPINMODE_ID,
             .cApi = "Port_SetPinMode()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called without module initialization. Failed\0 "},
            {.ApiId = PORT_SETPINMODE_ID,
             .cApi = "Port_SetPinMode()\0",
             .ErrorId = PORT_E_PARAM_INVALID_MODE,
             .cError = "API Port_SetPinMode service called when mode is unchangeable.. Failed \0"},
            {.ApiId = PORT_REFRESHPINDIRECTION_ID,
             .cApi = "Port_RefreshPortDirection()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called without module initialization . Failed\0 "},
            {.ApiId = PORT_REFRESHPINDIRECTION_ID,
             .cApi = "Port_RefreshPortDirection()\0",
             .ErrorId = PORT_E_PARAM_CONFIG,
             .cError = " Port Init function Failed wrong parameter. Failed\0 "},
            {.ApiId = PORT_GETVERSIONINFO_ID,
             .cApi = "Port_GetVersionInfo()\0",
             .ErrorId = PORT_E_PARAM_POINTER,
             .cError = "Api called with a NULL Pointer Parameter. Failed\0"},
            {.ApiId = PORT_SETASUNUSEDPIN_ID,
             .cApi = "Port_SetAsUnusedPin()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called prior to module initialization. Failed\0"},
            {.ApiId = PORT_SETASUSEDPIN_ID,
             .cApi = "Port_SetAsUsedPin()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called prior to module initialization. Failed\0"},
            {.ApiId = PORT_RESETPINMODE_ID,
             .cApi = "Port_ResetPinMode()\0",
             .ErrorId = PORT_E_UNINIT,
             .cError = "API service called prior to module initialization. Failed\0"},

    };

    DefaultErrorTrace_dinamic Dio_Det_Handler_dinamic[SIZE_HASH_DINAMIC] =
        {
            {.ApiId = DIO_WRITECHANNEL_ID,
             .cApi = "Dio_ValidateChannelLevel()\0",
             .ErrorId = DIO_E_PARAM_LEVEL,
             .cError = " invalid Dio param level. Failed\0"},
            {.ApiId = DIO_WRITECHANNEL_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelForWrite() \0",
             .ErrorId = DIO_E_PARAM_CONFIG,
             .cError = " invalid Dio param configuration. Failed\0"},
            {.ApiId = DIO_WRITECHANNEL_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelForWrite()\0",
             .ErrorId = DIO_E_PARAM_INVALID_CHANNEL_ID,
             .cError = "Invalid channel requested. Service id. Failed \0"},
            {.ApiId = DIO_READPORT_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelForRead()\0",
             .ErrorId = DIO_E_PARAM_CONFIG,
             .cError = " invalid Dio param service ID. Failed\0"},
            {.ApiId = DIO_READPORT_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelForRead()\0",
             .ErrorId = DIO_E_PARAM_CONFIG,
             .cError = " invalid Dio param channel ID. Failed\0"},
            {.ApiId = DIO_WRITEPORT_ID, // u8ServiceId,
             .cApi = "Dio_ValidatePortForWrite()\0",
             .ErrorId = DIO_E_PARAM_CONFIG,
             .cError = " invalid Dio param config. Failed\0"},
            {.ApiId = DIO_WRITEPORT_ID, // u8ServiceId,
             .cApi = "Dio_ValidatePortForWrite()\0",
             .ErrorId = DIO_E_PARAM_INVALID_PORT_ID,
             .cError = "Invalid port requested\0"},
            {.ApiId = DIO_READCHANNEL_ID, // u8ServiceId,
             .cApi = "Dio_ValidatePortForRead()\0",
             .ErrorId = DIO_E_PARAM_CONFIG,
             .cError = "invalid param serviceID\0"},
            {.ApiId = DIO_READCHANNEL_ID, // u8ServiceId,
             .cApi = "Dio_ValidatePortForRead()\0",
             .ErrorId = DIO_E_PARAM_INVALID_PORT_ID,
             .cError = "invalid param port ID\0"},
            {.ApiId = DIO_WRITECHANNELGROUP_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelGroupForWrite()\0",
             .ErrorId = DIO_E_PARAM_INVALID_GROUP_ID,
             .cError = "Invalid channel group requested\0"},
            {.ApiId = DIO_READCHANNELGROUP_ID, // u8ServiceId,
             .cApi = "Dio_ValidateChannelGroupForRead()\0",
             .ErrorId = DIO_E_PARAM_INVALID_GROUP_ID,
             .cError = "Invalid channel group requested\0"},
            {.ApiId = DIO_GETVERSIONINFO_ID,
             .cApi = "Dio_GetVersionInfo()\0",
             .ErrorId = DIO_E_PARAM_POINTER,
             .cError = "API service called with a NULL pointer\0"},
            {.ApiId = DIO_MASKEDWRITEPORT_ID,
             .cApi = "Dio_MaskedWritePort()\0",
             .ErrorId = DIO_MASKEDWRITEPORT_ID,
             .cError = "invalid masked write param\0"}};

    DefaultErrorTrace_static Det_Handler_static[SIZE_HASH] =
        {
            {.ModuleId = PORT_MODULE_ID,
             .cModule = "PORT Module\0",
             .InstanceId = PORT_INSTANCE_ID,
             .cInstance = "PORT API\0"},
            {.ModuleId = DIO_MODULE_ID,
             .cModule = "DIO Module\0",
             .InstanceId = DIO_INSTANCE_ID,
             .cInstance = "DIO API\0"},

    };

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define DET_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
    /* Variables to store last DET error */
    uint8 Det_InstanceId[DET_NO_ECU_CORES]; /**< @brief DET instance ID*/
    uint8 Det_ApiId[DET_NO_ECU_CORES];      /**< @brief DET API ID*/
    uint8 Det_ErrorId[DET_NO_ECU_CORES];    /**< @brief DET Error ID*/
    /* Variables to store last DET runtime error */
    uint8 Det_RuntimeInstanceId[DET_NO_ECU_CORES]; /**< @brief DET instance ID*/
    uint8 Det_RuntimeApiId[DET_NO_ECU_CORES];      /**< @brief DET API ID*/
    uint8 Det_RuntimeErrorId[DET_NO_ECU_CORES];    /**< @brief DET Error ID*/
    /* Variables to store last DET transient error */
    uint8 Det_TransientInstanceId[DET_NO_ECU_CORES]; /**< @brief DET instance ID*/
    uint8 Det_TransientApiId[DET_NO_ECU_CORES];      /**< @brief DET API ID*/
    uint8 Det_TransientFaultId[DET_NO_ECU_CORES];    /**< @brief DET Error ID*/
#define DET_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
    uint16 Det_TransientModuleId[DET_NO_ECU_CORES]; /**< @brief DET module ID*/
    uint16 Det_ModuleId[DET_NO_ECU_CORES];          /**< @brief DET module ID*/
    uint16 Det_RuntimeModuleId[DET_NO_ECU_CORES];   /**< @brief DET module ID*/
#define DET_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* put all DET code into defined section */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

/*================================================================================================*/
/**
 * @brief          This function initializes the DET module.
 * @details        This is a function stub only. Functionality is void in this implementation
 *
 * @requirements   DET008
 *
 */
#include "SEGGER_RTT.h"
    void Det_Init(void)
    {
        SEGGER_RTT_printf(0, "Det Init Ready\n");
    }

    /*================================================================================================*/
    /**
     * @brief   This function provides the service for reporting of development errors.
     * @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
     *
     * @param[in]     ModuleId    Module ID of Calling Module
     * @param[in]     InstanceId  Index of Module starting at 0
     * @param[in]     ApiId       ID of API with Error
     * @param[in]     ErrorId     ID of Error
     *
     * @requirement DET009
     */

    const char *getModuleString(uint16_t ModuleId)
    {
        for (int i = 0; i < SIZE_HASH; i++)
        {
            if (Det_Handler_static[i].ModuleId == ModuleId)
            {
                return Det_Handler_static[i].cModule;
            }
        }
        return "Unknown Module";
    }

    const char *getInstanceString(uint16_t ModuleId, uint16_t InstanceId)
    {
        for (int i = 0; i < SIZE_HASH; i++)
        {
            if (Det_Handler_static[i].ModuleId == ModuleId)
            {
                if (Det_Handler_static[i].InstanceId == InstanceId)
                {
                    return Det_Handler_static[i].cInstance;
                }
            }
        }
        return "Unknown Instance";
    }

    const char *getApiString(uint16_t ApiId, uint16_t ModuleId)
    {
        if (ModuleId == DIO_MODULE_ID)
        {
            for (int i = 0; i < SIZE_HASH_DINAMIC; i++)
            {

                if (Dio_Det_Handler_dinamic[i].ApiId == ApiId)
                {
                    return Dio_Det_Handler_dinamic[i].cApi;
                }
            }
        }
        else if ((ModuleId == PORT_MODULE_ID))
        {
            for (int i = 0; i < SIZE_PORT_HASH; i++)
            {
                if (Port_Det_Handler_dinamic[i].ApiId == ApiId)
                {
                    return Port_Det_Handler_dinamic[i].cApi;
                }
            }
        }

        return "Unknown API";
    }

    const char *getErrorString(uint16_t ApiId, uint16_t ErrorId, uint16_t ModuleId)
    {
        if (ModuleId == DIO_MODULE_ID)
        {
            for (int i = 0; i < SIZE_HASH_DINAMIC; i++)
            {
                if (Dio_Det_Handler_dinamic[i].ApiId == ApiId)
                {
                    if (Dio_Det_Handler_dinamic[i].ErrorId == ErrorId)
                    {
                        return Dio_Det_Handler_dinamic[i].cError;
                    }
                }
            }
        }
        else if (ModuleId == PORT_MODULE_ID)
        {
            for (int i = 0; i < SIZE_PORT_HASH; i++)
            {
                if (Port_Det_Handler_dinamic[i].ApiId == ApiId)
                {
                    if (Port_Det_Handler_dinamic[i].ErrorId == ErrorId)
                    {
                        return Port_Det_Handler_dinamic[i].cError;
                    }
                }
            }
        }

        return "Unknown Error";
    }

    Std_ReturnType Det_ReportError(uint16 ModuleId,
                                   uint8 InstanceId,
                                   uint8 ApiId,
                                   uint8 ErrorId)
    {
        uint32 u32CoreId = (uint32)OsIf_GetCoreID();

        Det_ModuleId[u32CoreId] = ModuleId;
        Det_InstanceId[u32CoreId] = InstanceId;
        Det_ApiId[u32CoreId] = ApiId;
        Det_ErrorId[u32CoreId] = ErrorId;

        const char *moduleStr = getModuleString(ModuleId);
        const char *instanceStr = getInstanceString(ModuleId, InstanceId);
        const char *apiStr = getApiString(ApiId, ModuleId);
        const char *errorStr = getErrorString(ApiId, ErrorId, ModuleId);

        SEGGER_RTT_printf(0, "Report Error: %s | %s in function: %s with the error ""%s""\n", moduleStr, instanceStr, apiStr, errorStr);

        // printmodule = moduleTableGet( ModuldeId);
        // instance
        // api
        return E_OK;
    }

    /*================================================================================================*/
    /**
     * @brief   This function provides the service for reporting of runtime errors.
     * @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
     *
     * @param[in]     ModuleId    Module ID of Calling Module
     * @param[in]     InstanceId  Index of Module starting at 0
     * @param[in]     ApiId       ID of API with Error
     * @param[in]     ErrorId     ID of Error
     *
     * @requirement SWS_Det_01001
     */
    Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId,
                                          uint8 InstanceId,
                                          uint8 ApiId,
                                          uint8 ErrorId)
    {
        uint32 u32CoreId = (uint32)OsIf_GetCoreID();

        Det_RuntimeModuleId[u32CoreId] = ModuleId;
        Det_RuntimeInstanceId[u32CoreId] = InstanceId;
        Det_RuntimeApiId[u32CoreId] = ApiId;
        Det_RuntimeErrorId[u32CoreId] = ErrorId;

        return E_OK;
    }

    /*================================================================================================*/
    /**
     * @brief   This function provides the service for reporting of transient errors.
     * @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
     *
     * @param[in]     ModuleId    Module ID of Calling Module
     * @param[in]     InstanceId  Index of Module starting at 0
     * @param[in]     ApiId       ID of API with Error
     * @param[in]     FaultId     ID of Fault
     *
     * @requirement SWS_Det_01001
     */
    Std_ReturnType Det_ReportTransientFault(uint16 ModuleId,
                                            uint8 InstanceId,
                                            uint8 ApiId,
                                            uint8 FaultId)
    {
        uint32 u32CoreId = (uint32)OsIf_GetCoreID();

        Det_TransientModuleId[u32CoreId] = ModuleId;
        Det_TransientInstanceId[u32CoreId] = InstanceId;
        Det_TransientApiId[u32CoreId] = ApiId;
        Det_TransientFaultId[u32CoreId] = FaultId;

        return E_OK;
    }

    /*================================================================================================*/
    /**
     * @brief   This function provides the starting after the Det_Init has been called.
     * @details This is a function stub only.  Det_Init and Det_Start shall always be available.
     *          Functionality is void in this implementation
     *
     * @requirement DET010
     */
    void Det_Start(void)
    {
        /* Do nothing */
    }

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
