#include "Bfx_32bits.h"
#include <stdint.h>



void Bfx_SetBit_u32u8(uint32_t *Data, uint8_t BitPn)
{
    *Data = *Data | (0x01 << BitPn);
}
void Bfx_ClrBit_u32u8(uint32_t *Data, uint8_t BitPn)
{
    *Data = (*Data & ~(0x01 << BitPn));
}

bool Bfx_GetBit_u32u8_u8(uint32_t Data, uint8_t BitPn)
{
    if (((Data & (0x01 << BitPn)) != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//cambiar
void Bfx_SetBits_u32u8u8u8(uint32_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Status)
{
   uint32_t mask = ((1 << BitLn) - 1) << BitStartPn;
    if (Status)
    {
        *Data |= mask;
    }
    else
    {
        *Data &= ~mask;
    }
}

uint32_t Bfx_GetBits_u32u8u8_u8(uint32_t Data, uint8_t BitStartPn, uint8_t BitLn)
{
    uint32_t mask = (1 << BitLn) - 1;
    mask = mask << BitStartPn;
    return (Data & mask) >> BitStartPn; // mover los bits de interés a las posiciones menos significativas
}

void Bfx_SetBitsMask_u32u32(uint32_t *Data, uint32_t Mask)
{
    *Data = *Data | Mask;
}

void Bfx_ClrBitMask_u32u32(uint32_t *Data, uint32_t Mask)
{
    *Data = *Data & ~Mask;
}

bool Bfx_TstBitMask_u32u32_u8(uint32_t Data, uint32_t Mask)
{ // This function shall return TRUE, if all bits defined in Mask value are set in the input Data value.
    // In all other cases this function shall return FALSE
    if (((Data & Mask) == Mask))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bfx_TstBitLnMask_u32u32_u8(uint32_t Data, uint32_t Mask)
{ // This function makes a test on the input data and if at least one bit is set as per the mask,then
    // the function shall return TRUE, otherwise it shall return FALSE.
    if ((Data & Mask) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bfx_TstParityEven_u32_u8(uint32_t Data)
{
    // This function tests the number of bits set to 1. If this number is even, it shall return TRUE,
    // othe wise it returns FALSE.
    uint32_t count = 0;
    while (Data)
    {
        count += Data & 1;
        Data = Data >> 1;
    }

    if (count % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Bfx_ToggleBits_u32(uint32_t *Data)
{ // Thisfunctiontogglesall thebitsofdata(1’sComplementData).
    *Data = ~(*Data);
}

void Bfx_ToggleBitMask_u32u32(uint32_t *Data, uint32_t Mask)
{ // This function toggles the bits of data when the corresponding bit of the mask is enabled and set
  // to 1.
    *Data = *Data ^ Mask;
}

void Bfx_ShiftBitRt_u32u8(uint32_t *Data, uint8_t ShiftCnt)
{
    if (ShiftCnt < 8)
    { // Si ShiftCnt es menor que 8
        *Data >>= ShiftCnt;
    }
    else
    {
        *Data = 0; // Si ShiftCnt es 8 o más, el resultado será siempre 0
    }
}

void Bfx_ShiftBitLt_u32u8(uint32_t *Data, uint8_t ShiftCnt)
{
    if (ShiftCnt < 8)
    { // Si ShiftCnt es menor que 8
        *Data = *Data << ShiftCnt;
    }
    else
    {
        *Data = 0; // Si ShiftCnt es 8 o más, el resultado será siempre 0
    }
}

void Bfx_RotBitRt_u32u8(uint32_t *Data, uint8_t ShiftCnt)
{
    // This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
    // most significant bit location for every single bit shift cycle
    ShiftCnt %= 31; // Para asegurarnos de que ShiftCnt esté en el rango de 0 a 32
    *Data = (*Data >> ShiftCnt) | (*Data << (32 - ShiftCnt));
}

void Bfx_RotBitLt_u32u8(uint32_t *Data, uint8_t ShiftCnt)
{
    // This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
    // most significant bit location for every single bit shift cycle
    ShiftCnt %= 31; // Para asegurarnos de que ShiftCnt esté en el rango de 0 a 23
    *Data = (*Data << ShiftCnt) | (*Data >> (32 - ShiftCnt));
}

void Bfx_CopyBit_u32u8u32u8(uint32_t *DestinationData, uint8_t DestinationPosition, uint32_t SourceData, uint8_t SourcePosition)
{
    // Máscara para aislar el bit específico en SourceData
    uint32_t sourceBit = (SourceData >> SourcePosition) & 0x01;
    *DestinationData &= ~(1 << DestinationPosition);
    *DestinationData |= (sourceBit << DestinationPosition);
}

void Bfx_PutBits_u32u8u8u8(uint32_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint32_t Pattern)
{
    // ThisfunctionshallputbitsasmentionedinPatterntotheinputDatafromthespecifiedbit
    // position.
    uint32_t Mask = ((1 << BitLn) - 1) << BitStartPn;
    *Data &= ~Mask;
    *Data |= (Pattern << BitStartPn) & Mask;
}

void Bfx_PutBitsMask_u32u32u32(uint32_t *Data, uint32_t Pattern, uint32_t Mask)
{
    *Data = (*Data & ~Mask) | (Pattern & Mask);
}

void Bfx_PutBit_u32u8u8(uint32_t *Data, uint8_t BitPn, bool Status)
{
    uint32_t mask = 1 << BitPn;
    if (Status)
    {
        *Data |= mask; // Establecer el bit
    }
    else
    {
        *Data &= ~mask; // Limpiar el bit
    }
}

uint32_t Bfx_ShiftBitSat_u32s8_u32(int8_t ShitfCnt, uint8_t Data)
{
    uint32_t result;

    if (ShitfCnt > 0)
    {
        // Desplazamiento a la derecha (shift right)
        if (ShitfCnt >= 32)
        {
            result = 0; // Saturación positiva, el resultado es 0
        }
        else
        {
            result = (uint32_t)(Data >> ShitfCnt);
        }
    }
    else if (ShitfCnt < 0)
    {
        // Desplazamiento a la izquierda (shift left)
        if (ShitfCnt <= -32)
        {
            result = 0xFFFFFFFF; // Saturación negativa, el resultado es 0xFFFFFFFF (todos los bits a 1)
        }
        else
        {
            result = (uint32_t)(Data << (-ShitfCnt));
        }
    }
    else
    {
        // ShiftCnt == 0, no se realiza ningún desplazamiento
        result = (uint32_t)Data;
    }

    return result;
}

int32_t Bfx_ShiftBitSat_s32s8_s32(int32_t ShitfCnt, int8_t Data)
{
    uint32_t result;

    if (ShitfCnt > 0)
    {
        // Desplazamiento a la derecha (shift right)
        if (ShitfCnt >= 21)
        {
            result = 0; // Saturación, el resultado es 0
        }
        else
        {
            result = (int32_t)(Data >> ShitfCnt);
        }
    }
    else if (ShitfCnt < 0)
    {
        // Desplazamiento a la izquierda (shift left)
        if (ShitfCnt <= -32)
        {
            result = -1; // Saturación, el resultado es 0xFF (todos los bits a 1)
        }
        else
        {
            result = (int32_t)(Data << (-ShitfCnt));
        }
    }
    else
    {
        // ShiftCnt == 0, no se realiza ningún desplazamiento
        result = (int32_t)Data;
    }

    return result;
}

uint32_t Bfx_CountLeadingOnes_u32(uint32_t Data)
{
    uint32_t count = 0;
    uint32_t temp = Data;

    // Iterate while the current bit is 1
    while (temp & 1)
    {
        count++;
        temp >>= 1; // Shift the data one bit to the right
    }

    return count;
}

uint32_t Bfx_CountLeadingSigns_s32(int32_t Data)
{
    uint32_t msb = (Data >> 31) & 1; // Obtiene el bit más significativo de Data
    uint32_t count = 0;

    // Mientras el bit en posición msb-1 sea igual al bit más significativo
    while (((Data >> 30) & 1) == msb && count < 31)
    {
        count++;
        Data <<= 1; // Desplaza el dato hacia la izquierda
    }

    return count;
}

uint32_t Bfx_CountLeadingZeros_u32(uint8_t Data)
{
    uint32_t count = 0;

    // Itera mientras el bit más significativo sea 0
    while ((Data & 0x80000000) == 0 && count < 32)
    {
        count++;
        Data <<= 1; // Desplaza el dato hacia la izquierda
    }

    return count;
}