#include "unity.h"

#include "Bfx_32bits.h"

#define TRUE 1
#define FALSE 0

/**
 * @brief Set the Up object
 *
 */
void setUp(void)
{
}

/**
 * @brief teadDown
 *
 */
void tearDown(void)
{
}

/**
 * @brief   **Test set bit 2**
 *
 * The test validates if bit 2 is set over a varible with value 0x00, to pass the test data should have
 * a value of 0x04.
 */
void test__Bfx_SetBit_u32u8__bit2(void)
{
    uint32_t Data = 0u;
    Bfx_SetBit_u32u8(&Data, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x01, "");
}
/**
 * @brief   **Test set bit 13**
 *
 * The test validates if bit 13 is set over a varible
 *
 */
void test__Bfx_SetBit_u32u8__bit7(void)
{
    uint32_t Data = 0xEFFF;
    Bfx_SetBit_u32u8(&Data, 13u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xFFFF, "");
}

/**
 * @brief   **Test set bit 1**
 *
 * The test validates if bit 1 is set over a varible with value 0xA, to pass data tested should have
 * a value of 0x08.
 */
void test__Bfx_ClrBit_u32u8__bit12(void)
{
    uint32_t Data = 0xffff;
    Bfx_ClrBit_u32u8(&Data, 12u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xEFFF, "");
}

/**
 * @brief   **Test set bit 0**
 *
 * The test validates if bit 0 is set over a varible with value 0x1, to pass data tested should have
 * a value of 0x08.
 */
void test__Bfx_ClrBit_u32u8__clear_bit15(void)
{
    uint32_t Data = 0x8000;
    Bfx_ClrBit_u32u8(&Data, 16u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x00, "Bit 1 was not set as supposed to be");
}

/**
 * @brief   **Get bit 16 ,1**
 *
 * The test validates if bit 7 return as 1
 *
 */
void test__Bfx_GetBit_u32u8_u8_get_bit16()
{
    uint32_t Data = 0x8000;
    uint8_t bit = Bfx_GetBit_u32u8_u8(Data, 15);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, "");
}

/**
 * @brief   **Get bit 14 ,0**
 *
 * The test validates if bit 0 return as 0
 *
 */
void test__Bfx_GetBit_u32u8_u8_bit0_0()
{
    uint32_t Data = 0x8000;
    uint8_t bit = Bfx_GetBit_u32u8_u8(Data, 14);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, "");
}

/**
 * @brief   **Set bits 2 and 3 to 1**
 */
void test__Bfx_SetBits_u32u8u8u8_bit_ln2_set1()
{
    uint32_t Data = 0xf0f0;
    Bfx_SetBits_u32u8u8u8(&Data, 4, 9, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xfff0, "");
}

/**
 * @brief   **Set bits 4 and 12 to 16 to become 0x0fff to 0xffff**
 */
void test__Bfx_SetBits_u32u8u8u8_bit_ln2_set0()
{
    uint32_t Data = 0x0fff;
    Bfx_SetBits_u32u8u8u8(&Data, 4, 12, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0f, " ");
}

/**
 * @brief   **get high nibble 0**
 */
void test__Bfx_GetBits_u32u8u8_u8_return_high_nibble()
{
    uint32_t Data = 0x0f0f00;
    uint32_t bits = Bfx_GetBits_u32u8u8_u8(Data, 20, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bits, 0x0, " ");
}

/**
 * @brief   **get  third nibble bits 1111**
 */
void test__Bfx_GetBits_32u8u8_u8_return__nibble()
{
    uint32_t Data = 0x0f0f00;
    uint32_t bits = Bfx_GetBits_u32u8u8_u8(Data, 16, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bits, 0xf, " ");
}

/**
 * @brief   ****
 */
void test__Bfx_SetBitMask_u32u32__mask_or__4bits()
{
    uint32_t Data = 0xFAFFF;
    Bfx_SetBitsMask_u32u32(&Data, 0xF5FFF);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0FFFFF, " ");
}

/**
 * @brief   ****
 */
void test__Bfx_SetBitMask_u32u32__mask_or__1bit()
{
    uint32_t Data = 0x10;
    Bfx_SetBitsMask_u32u32(&Data, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x11, " ");
}

/**
 * @brief   ** **
 */
void test__Bfx_ClrBitMask_u32u8__0x11_to_0x10()
{
    uint32_t Data = 0x11;
    Bfx_ClrBitMask_u32u32(&Data, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x10, " ");
}

/**
 * @brief   ****
 */
void test__Bfx_ClrBitMask_u32u8__0()
{
    uint32_t Data = 0xEFFFF;
    Bfx_ClrBitMask_u32u32(&Data, 0xFFFFF);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0, " ");
}

/**
 * @brief   **to test if mask works fine, return 1**
 */
void test__Bfx_TstBitMask_u32u32_u8__test_return_true()
{
    uint32_t Data = 0x8000;
    uint32_t bit = Bfx_TstBitMask_u32u32_u8(Data, 0x8000);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitMask_u32u32_u8__test_return_false()
{
    uint32_t Data = 0b101000000000;
    uint32_t bit = Bfx_TstBitMask_u32u32_u8(Data, 0b010100000000);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitLnMask_u32u32_u8__return_false()
{
    uint32_t Data = 0xA00000;
    uint32_t bit = Bfx_TstBitLnMask_u32u32_u8(Data, 0x500000);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitLnMask_u32u32_u8__return_true()
{
    uint32_t Data = 0xA00000;
    uint32_t bit = Bfx_TstBitLnMask_u32u32_u8(Data, 0xA00000);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, " ");
}

/**
 * @brief   **to test parity 10000, **
 */
void test__Bfx_TstParityEven_u8_u8_10000_even()
{
    uint32_t Data = 100000;
    uint32_t bit = Bfx_TstParityEven_u32_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, "isnt pair ");
}

/**
 * @brief   **to test parity 65120, **
 */
void test__Bfx_TstParityEven_u32_u8_65120_()
{
    uint32_t Data = 65120;
    uint32_t bit = Bfx_TstParityEven_u32_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, "isnt pair ");
}

/**
 * @brief   **bit inversion AFAFAF to FAFAFA **
 */
void test__Bfx_ToggleBits_u32_AFAFAF_to_0x50505()
{
    uint32_t Data = 0xAFAFA;
    Bfx_ToggleBits_u32(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x50505, "");
}

/**
 * @brief   **bit inversion 0x0f to 0xf0 **
 */
void test__Bfx_ToggleBits_u8_0f_to_f0fffff()
{
    uint32_t Data = 0x0F00000;
    Bfx_ToggleBits_u32(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xf0fffff, " ");
}

/**
 * @brief   **Toggle with mask, mask 0x0f to have 0xA0 **
 */
void test__Bfx_ToggleBitMask_u32u32__()
{
    uint32_t Data = 0xAF0000;
    Bfx_ToggleBitMask_u32u32(&Data, 0x0Fffff);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xA0ffff, "");
}

/**
 * @brief   **Toggle with mask, mask 0x9f to have 0xac **
 */
void test__Bfx_ToggleBitMask_u32u32__mask_Ac()
{
    uint32_t Data = 0x9F0000;
    Bfx_ToggleBitMask_u32u32(&Data, 0x33ffff);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xACffff, "");
}

/**
 * @brief   **shift 1 bit to the right **
 */
void test__Bfx_ShiftBitRt_u32u8__move_right_1()
{
    uint32_t Data = 0x01000;
    Bfx_ShiftBitRt_u32u8(&Data, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0, "");
}

/**
 * @brief   **shift 8 bits to the right **
 */
void test__Bfx_ShiftBitRt_u32u8__Cnt8plus_return_0()
{
    uint32_t Data = 0xA0000;
    Bfx_ShiftBitRt_u32u8(&Data, 8);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0, "");
}

/**
 * @brief   **shift 1 bits to the left **
 */
void test__Bfx_ShiftBitLt_u32u8___return_true()
{
    uint32_t Data = 0x11107;
    Bfx_ShiftBitLt_u32u8(&Data, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0E, "");
}

/**
 * @brief   **shift 8 bits to the left **
 */
void test__Bfx_ShiftBitLt_u32u8__Cnt8plus_return_0()
{
    uint32_t Data = 0xA;
    Bfx_ShiftBitLt_u32u8(&Data, 8);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0, "");
}



/**
 * @brief   **Rotate 12 bits right **
 */
void test__Bfx_RotBitRt_u32u8_rot_4pos()
{
    uint32_t Data = 0xAF00000;
    Bfx_RotBitRt_u32u8(&Data, 12);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x00, "");
}

/**
 * @brief   **Rotate 16 bits right **
 */
void test__Bfx_RotBitRt_u32u8_rot_4pos_ej2()
{
    uint32_t Data = 0xC200000;
    Bfx_RotBitRt_u32u8(&Data, 16);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x20, "");
}

/**
 * @brief   **Rotate 3 bits left **
 */
void test__Bfx_RotBitLt_u32u8_4pos_()
{
    uint32_t Data = 0x2cffff;
    Bfx_RotBitLt_u32u8(&Data, 3);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xf8, "");
}

/**
 * @brief   **Rotate 4 bits left **
 */
void test__Bfx_RotBitLt_u32u8_4pos_ej2()
{
    uint32_t Data = 0xcfffffc;
    Bfx_RotBitLt_u32u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xc0, "");
}

/**
 * @brief   **copy bit 6 **
 */
void test__Bfx_CopyBit_u32u8u32u8__ej()
{
    uint32_t Data = 0b10100001;
    Bfx_CopyBit_u32u8u32u8(&Data, 6, 0b11011010, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11100001, "");
}

/**
 * @brief   **copy bit 1 **
 */
void test__Bfx_CopyBit_u32u8u32u8__ejemplo2()
{
    uint32_t Data = 0xFFCC;
    Bfx_CopyBit_u32u8u32u8(&Data, 1, 0xFFCA, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xCE, "");
}

/**
 * @brief   **put 3 bits from others **
 */
void test__Bfx_PutBits_u32u8u8u8__()
{
    uint32_t Data = 0b11110000;
    Bfx_PutBits_u32u8u8u8(&Data, 1, 3, 0b00000011);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11110110, "");
}

/**
 * @brief   **put 4 bits from others **
 */
void test__Bfx_PutBits_u32u8u8u8__ejemplo2()
{
    uint32_t Data = 0xF0000;
    Bfx_PutBits_u32u8u8u8(&Data, 1, 4, 0x02);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x04, "");
}

/**
 * @brief   **put mask **
 */
void test__Bfx_PutBitsMask_u32u32u32_ej1()
{
    uint32_t Data = 0b11100000;
    Bfx_PutBitsMask_u32u32u32(&Data, 0b11001101, 0b00001111);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11101101, "");
}

/**
 * @brief   **put bit 1 in arbitrari position,(4) **
 */
void test__BfxPutBit_u32u8u8__true()
{
    uint32_t Data = 0b11100111;
    Bfx_PutBit_u32u8u8(&Data, 4, true);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11110111, "");
}

/**
 * @brief   **put bit 0 in arbitrari position,(0) **
 */
void test__Bfx_PutBit_u32u8u8__put_0()
{
    uint32_t Data = 0b11100111;
    Bfx_PutBit_u32u8u8(&Data, 0, false);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11100110, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__BfxShitftBitSat_u32s8_u32_negative3_()
{
    uint32_t Data = 0xCA;
    uint32_t result = Bfx_ShiftBitSat_u32s8_u32(-3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x50, "");
}

/**
 * @brief   **shift bits 3  **
 */
void test__BfxShitftBitSat_u32s8_u32_plus3_()
{
    uint32_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_u32s8_u32(3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x19, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__BfxShitftBitSat_s32s8_u32_n3_()
{
    uint32_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_s32s8_s32(-3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x50, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__Bfx_ShitftBitSat_s32s8_u32_plus4_()
{
    uint32_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_s32s8_s32(4, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0xFC, "");
}

/**
 * @brief   **count three consecutives ones  **
 */
void test__Bfx_CountLeadingOnes_u32__threeOnes()
{
    uint32_t Data = 0xE6;
    uint32_t result = Bfx_CountLeadingOnes_u32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0, "");
}

/**
 * @brief   **count eight consecutives ones  **
 */ 
void test__Bfx_CountLeadingOnes_u32__EightOnes()
{
    uint32_t Data = 0xf0;
    uint32_t result = Bfx_CountLeadingOnes_u32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0, "");
}
/**
 * @brief   **count 2 **
 */
void test__Bfx_CountLeadingSigns_u32__()
{
    uint32_t Data = 0xE6;
    uint8_t result = Bfx_CountLeadingSigns_s32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x17, "");
}

/**
 * @brief   **count 7 **
 */
void test__Bfx_CountLeadingSigns_u32_count2_()
{
    uint32_t Data = 0xFF;
    uint32_t result = Bfx_CountLeadingSigns_s32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x17, "");
}

/**
 * @brief   **count zero consecutives zeross  **
 */
void test__Bfx_CountLeadingZeros_u32__count0zeros()
{
    uint32_t Data = 0xFF;
    uint8_t result = Bfx_CountLeadingZeros_u32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x20, "");
}

/**
 * @brief   **count 4 consecutives zeros  **
 */
void test__Bfx_CountLeadingZeros_u32__count4zeros()
{
    uint32_t Data = 0x0E;
    uint8_t result = Bfx_CountLeadingZeros_u32(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x20, "");
}
