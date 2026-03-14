#include "unity.h"

#include "Bfx_8bits.h"
#include <stdint.h>

/**
 * @defgroup <1 AND 0> macro to define 1s and 0s inside of conditionals
 *
 */


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
void test__Bfx_SetBit_u8u8__bit2(void)
{
    uint8_t Data = 0u;
    Bfx_SetBit_u8u8(&Data, 2u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x04, "Bit 2 was not set as supposed to be");
}
/**
 * @brief   **Test set bit 7**
 *
 * The test validates if bit 7 is set over a varible with value 0x00, to pass data tested should have
 * a value of 0x80.
 */
void test__Bfx_SetBit_u8u8__bit7(void)
{
    uint8_t Data = 0u;
    Bfx_SetBit_u8u8(&Data, 7u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x80, "Bit 7 was not set as supposed to be");
}

/**
 * @brief   **Test set bit 1**
 *
 * The test validates if bit 1 is set over a varible with value 0xA, to pass data tested should have
 * a value of 0x08.
 */
void test__Bfx_ClrBit_u8u8__bit1(void)
{
    uint8_t Data = 0xA;
    Bfx_ClrBit_u8u8(&Data, 1u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x08, "Bit 1 was not set as supposed to be");
}

/**
 * @brief   **Test set bit 0**
 *
 * The test validates if bit 0 is set over a varible with value 0x1, to pass data tested should have
 * a value of 0x08.
 */
void test__Bfx_ClrBit_u8u8__bit0(void)
{
    uint8_t Data = 0x1;
    Bfx_ClrBit_u8u8(&Data, 0u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x00, "Bit 1 was not set as supposed to be");
}

/**
 * @brief   **Get bit 7 ,1**
 *
 * The test validates if bit 7 return as 1
 *
 */
void test__Bfx_GetBit_u8u8_u8_bit7_1()
{
    uint8_t Data = 0x80;
    uint8_t bit = Bfx_GetBit_u8u8_u8(&Data, 7);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, "Bit 7 supposed to be 1 not 0");
}

/**
 * @brief   **Get bit 0 ,1**
 *
 * The test validates if bit 0 return as 0
 *
 */
void test__Bfx_GetBit_u8u8_u8_bit0_0()
{
    uint8_t Data = 0x80;
    uint8_t bit = Bfx_GetBit_u8u8_u8(&Data, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, "Bit 0 supposed to be 0");
}

/**
 * @brief   **Set bits 2 and 3 to 1**
 */
void test__Bfx_SetBits_u8u8u8u8_bit_ln2_set1()
{
    uint8_t Data = 0x32;
    Bfx_SetBits_u8u8u8u8(&Data, 2, 2, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x3E, "");
}

/**
 * @brief   **Set bits 6 and 7 to 0 to become 0xC8 to 0x08**
 */
void test__Bfx_SetBits_u8u8u8u8_bit_ln2_set0()
{
    uint8_t Data = 0xC8;
    Bfx_SetBits_u8u8u8u8(&Data, 6, 2, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x8, " ");
}

/**
 * @brief   **get high nibble**
 */
void test__Bfx_GetBits_u8u8u8_u8_return_high_nibble()
{
    uint8_t Data = 0xC8;
    uint8_t bits = Bfx_GetBits_u8u8u8_u8(Data, 4, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bits, 0xc, " ");
}

/**
 * @brief   **get low nibble**
 */
void test__Bfx_GetBits_u8u8u8_u8_return_low_nibble()
{
    uint8_t Data = 0xC8;
    uint8_t bits = Bfx_GetBits_u8u8u8_u8(Data, 4, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bits, 0x0, " ");
}

/**
 * @brief   **set mask arbitrari bits  0xA to 0x0f**
 */
void test__Bfx_SetBitMask_u8u8__mask_or__4bits()
{
    uint8_t Data = 0xA;
    Bfx_SetBitsMask_u8u8(&Data, 0b0101);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0F, " ");
}

/**
 * @brief   **set mask arbitrari bits  0x10 to 0x11**
 */
void test__Bfx_SetBitMask_u8u8__mask_or__1bit()
{
    uint8_t Data = 0x10;
    Bfx_SetBitsMask_u8u8(&Data, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x11, " ");
}

/**
 * @brief   **clear bit pos 1 to have 0x10**
 */
void test__Bfx_ClrBitMask_u8u8__0x11_to_0x10()
{
    uint8_t Data = 0x11;
    Bfx_ClrBitMask_u8u8(&Data, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x10, " ");
}

/**
 * @brief   **clear bit pos 7 to have 0x00 from 0x08**
 */
void test__Bfx_ClrBitMask_u8u8__0x80_to_0x00()
{
    uint8_t Data = 0x80;
    Bfx_ClrBitMask_u8u8(&Data, 0x80);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x00, " ");
}

/**
 * @brief   **to test if mask works fine, return 1**
 */
void test__Bfx_TstBitMask_u8u8_u8__test_return_true()
{
    uint8_t Data = 0x80;
    uint8_t bit = Bfx_TstBitMask_u8u8_u8(Data, 0x80);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitMask_u8u8_u8__test_return_false()
{
    uint8_t Data = 0b1010;
    uint8_t bit = Bfx_TstBitMask_u8u8_u8(Data, 0b0101);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitLnMask_u8u8_u8__return_false()
{
    uint8_t Data = 0b1010;
    uint8_t bit = Bfx_TstBitLnMask_u8u8_u8(Data, 0b0101);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, " ");
}

/**
 * @brief   **to test if mask is different to source, return 0**
 */
void test__Bfx_TstBitLnMask_u8u8_u8__return_true()
{
    uint8_t Data = 0b1010;
    uint8_t bit = Bfx_TstBitLnMask_u8u8_u8(Data, 0b1010);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, " ");
}

/**
 * @brief   **to test parity 10, **
 */
void test__Bfx_TstParityEven_u8_u8_10_even()
{
    uint8_t Data = 10;
    uint8_t bit = Bfx_TstParityEven_u8_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 1, "isnt pair ");
}

/**
 * @brief   **to test parity 1, **
 */
void test__Bfx_TstParityEven_u8_u8_1_()
{
    uint8_t Data = 1;
    uint8_t bit = Bfx_TstParityEven_u8_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(bit, 0, "isnt pair ");
}

/**
 * @brief   **bit inversion 0xaf to 0x50 **
 */
void test__Bfx_ToggleBits_u8_Af_to_0x50()
{
    uint8_t Data = 0xAF;
    Bfx_ToggleBits_u8(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x50, "");
}

/**
 * @brief   **bit inversion 0x0f to 0xf0 **
 */
void test__Bfx_ToggleBits_u8_0f_to_0xf0()
{
    uint8_t Data = 0x0F;
    Bfx_ToggleBits_u8(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xf0, " ");
}

/**
 * @brief   **Toggle with mask, mask 0x0f to have 0xA0 **
 */
void test__Bfx_ToggleBitMask_u8u8__()
{
    uint8_t Data = 0xAF;
    Bfx_ToggleBitMask_u8u8(&Data, 0x0F);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xA0, "");
}

/**
 * @brief   **Toggle with mask, mask 0x9f to have 0xac **
 */
void test__Bfx_ToggleBitMask_u8u8__mask_Ac()
{
    uint8_t Data = 0x9F;
    Bfx_ToggleBitMask_u8u8(&Data, 0x33);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xAC, "");
}

/**
 * @brief   **shift 1 bit to the right **
 */
void test__Bfx_ShiftBitRt_u8u8__move_right_1()
{
    uint8_t Data = 0x1;
    Bfx_ShiftBitLt_u8u8(&Data, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x2, "");
}



/**
 * @brief   **shift 1 bits to the left **
 */
void test__Bfx_ShiftBitLt_u8u8___return_true()
{
    uint8_t Data = 0x07;
    Bfx_ShiftBitLt_u8u8(&Data, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x0E, "");
}

/**
 * @brief   **shift 8 bits to the left **
 */
void test__Bfx_ShiftBitLt_u8u8__Cnt8plus_return_0()
{
    uint8_t Data = 0xA;
    Bfx_ShiftBitLt_u8u8(&Data, 8);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0, "");
}

/**
 * @brief   **shift 8 bits to the left **
 */
void test__Bfx_ShiftBitRt_u8u8__Cnt8plus_()
{
    uint8_t Data = 0xA;
    Bfx_ShiftBitRt_u8u8(&Data, 8);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0, "");
}

/**
 * @brief   **Rotate 4 bits right **
 */
void test__Bfx_RotBitRt_u8u8_rot_4pos()
{
    uint8_t Data = 0xAF;
    Bfx_RotBitRt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xFA, "");
}

/**
 * @brief   **Rotate 4 bits right **
 */
void test__Bfx_RotBitRt_u8u8_rot_4pos_ej2()
{
    uint8_t Data = 0xC2;
    Bfx_RotBitRt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0x2C, "");
}

/**
 * @brief   **Rotate 4 bits left **
 */
void test__Bfx_RotBitLt_u8u8_4pos_()
{
    uint8_t Data = 0x2c;
    Bfx_RotBitLt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xc2, "");
}

/**
 * @brief   **Rotate 4 bits left **
 */
void test__Bfx_RotBitLt_u8u8_4pos_ej2()
{
    uint8_t Data = 0xFa;
    Bfx_RotBitLt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0xaf, "");
}

/**
 * @brief   **copy bit 6 **
 */
void test__Bfx_CopyBit_u8u8u8u8__ej()
{
    uint8_t Data = 0b10100001;
    Bfx_CopyBit_u8u8u8u8(&Data, 6, 0b11011010, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11100001, "");
}

/**
 * @brief   **copy bit 1 **
 */
void test__Bfx_CopyBit_u8u8u8u8__ejemplo2()
{
    uint8_t Data = 0b10100001;
    Bfx_CopyBit_u8u8u8u8(&Data, 1, 0b11011010, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b10100011, "");
}

/**
 * @brief   **put 3 bits from others **
 */
void test__Bfx_PutBits_u8u8u8u8__()
{
    uint8_t Data = 0b11110000;
    Bfx_PutBits_u8u8u8u8(&Data, 1, 3, 0b00000011);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11110110, "");
}

/**
 * @brief   **put 4 bits from others **
 */
void test__Bfx_PutBits_u8u8u8u8__ejemplo2()
{
    uint8_t Data = 0b11110000;
    Bfx_PutBits_u8u8u8u8(&Data, 1, 4, 0b00000011);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11100110, "");
}

/**
 * @brief   **put mask **
 */
void test__Bfx_PutBitsMask_u8u8u8_ej1()
{
    uint8_t Data = 0b11100000;
    Bfx_PutBitsMask_u8u8u8(&Data, 0b11001101, 0b00001111);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11101101, "");
}

/**
 * @brief   **put bit 1 in arbitrari position,(4) **
 */
void test__BfxPutBit_u8u8u8__true()
{
    uint8_t Data = 0b11100111;
    Bfx_PutBit_u8u8u8(&Data, 4, true);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11110111, "");
}

/**
 * @brief   **put bit 0 in arbitrari position,(0) **
 */
void test__BfxBit_u8u8u8__put_0()
{
    uint8_t Data = 0b11100111;
    Bfx_PutBit_u8u8u8(&Data, 0, true);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(Data, 0b11100111, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__BfxShitftBitSat_u8s8_u8_negative3_()
{
    uint8_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_u8s8_u8(-3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x50, "");
}

/**
 * @brief   **shift bits 3  **
 */
void test__BfxShitftBitSat_u8s8_u8_plus3_()
{
    uint8_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_u8s8_u8(3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x19, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__BfxShitftBitSat_s8s8_u8_n3_()
{
    uint8_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_s8s8_s8(-3, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x50, "");
}

/**
 * @brief   **shift bits -3  **
 */
void test__BfxShitftBitSat_s8s8_u8_plus4_()
{
    uint8_t Data = 0xCA;
    uint8_t result = Bfx_ShiftBitSat_s8s8_s8(4, Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0x0C, "");
}

/**
 * @brief   **count three consecutives ones  **
 */
void test__Bfx_CountLeadingOnes_u8__threeOnes()
{
    uint8_t Data = 0xE6;
    uint8_t result = Bfx_CountLeadingOnes_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 3, "");
}

/**
 * @brief   **count eight consecutives ones  **
 */
void test__Bfx_CountLeadingOnes_u8__EightOnes()
{
    uint8_t Data = 0xFF;
    uint8_t result = Bfx_CountLeadingOnes_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 8, "");
}
/**
 * @brief   **count 2 **
 */
void test__Bfx_CountLeadingSigns_u8__()
{
    uint8_t Data = 0xE6;
    uint8_t result = Bfx_CountLeadingSigns_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 2, "");
}

/**
 * @brief   **count 7 **
 */
void test__Bfx_CountLeadingSigns_u8_count2_()
{
    uint8_t Data = 0xFF;
    uint8_t result = Bfx_CountLeadingSigns_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 7, "");
}

/**
 * @brief   **count zero consecutives zeross  **
 */
void test__Bfx_CountLeadingZeros_u8__count0zeros()
{
    uint8_t Data = 0xFF;
    uint8_t result = Bfx_CountLeadingZeros_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 0, "");
}

/**
 * @brief   **count 4 consecutives zeros  **
 */
void test__Bfx_CountLeadingZeros_u8__count4zeros()
{
    uint8_t Data = 0x0E;
    uint8_t result = Bfx_CountLeadingZeros_u8(Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE(result, 4, "");
}