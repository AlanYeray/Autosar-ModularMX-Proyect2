#include "IoHwAb.h"
#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"
#include "HwIoAb_2_Pots.h"
#include "HwIoAb_3_Buzzer.h"

static const IoHwAb0_ConfigType *IoHwAb_pConfigPtr;

void IoHwAb_Init0(const IoHwAb0_ConfigType *ConfigPtr)
{
    HwIoAb_Pots_Init(NULL_PTR);
    HwIoAb_Buttons_Init(&ButtonsCfg);
    HwIoAb_Buzzer_Init(NULL_PTR);

    IoHwAb_pConfigPtr = ConfigPtr;
}

/**
 * @brief   Returns the version information of this module.
 * @details The function Port_GetVersionInfo() will return the version
 *          information of this module. The version information includes:
 *          - Module Id,
 *          - Vendor Id,
 *          - Vendor specific version numbers.
 *
 * @param[in,out] versioninfo      Pointer to where to store the version
 *                                  information of this module.
 *
 *
 */
void IoHwAb_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    (versioninfo)->vendorID = (uint16)PORT_VENDOR_ID;
    (versioninfo)->moduleID = (uint16)PORT_MODULE_ID;
    (versioninfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
    (versioninfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
    (versioninfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
}