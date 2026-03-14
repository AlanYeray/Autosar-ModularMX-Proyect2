

#include "Bfx_8bits.h"
#include <stdint.h>




void Bfx_SetBit_u8u8(uint8_t *Data, uint8_t BitPn)
{
    *Data = *Data | (0x01 << BitPn);
}

void Bfx_ClrBit_u8u8(uint8_t *Data, uint8_t BitPn)
{
    *Data = (*Data & ~(0x01 << BitPn));
}

bool Bfx_GetBit_u8u8_u8(uint8_t *Data, uint8_t BitPn)
{
    if (((*Data & (0x01 << BitPn)) != 0))
    {
        return true;
    }
    else
    {
        return true;
    }
}

void Bfx_SetBits_u8u8u8u8(uint8_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Status)
{
    uint8_t mask = ((1 << BitLn) - 1) << BitStartPn;
    if (Status)
    {
        *Data |= mask;
    }
    else
    {
        *Data &= ~mask;
    }
}

uint8_t Bfx_GetBits_u8u8u8_u8(uint8_t Data, uint8_t BitStartPn, uint8_t BitLn)
{
    uint8_t mask = (1 << BitLn) - 1;
    mask = mask << BitStartPn;
    return (Data & mask) >> BitStartPn; // mover los bits de interés a las posiciones menos significativas
}

void Bfx_SetBitsMask_u8u8(uint8_t *Data, uint8_t Mask)
{
    *Data = *Data | Mask;
}

void Bfx_ClrBitMask_u8u8(uint8_t *Data, uint8_t Mask)
{
    *Data = *Data & ~Mask;
}

bool Bfx_TstBitMask_u8u8_u8(uint8_t Data, uint8_t Mask)
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

bool Bfx_TstBitLnMask_u8u8_u8(uint8_t Data, uint8_t Mask)
{ // This function make sateston the input data and if at least one bit is set as per the mask,then
    // the function shall return TRUE,other wise it shall return FALSE.
    if ((Data & Mask) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bfx_TstParityEven_u8_u8(uint8_t Data)
{
    // This function tests the number of bits set to 1. If this number is even, it shall return TRUE,
    // othe wise it returns FALSE.
    uint8_t count = 0;
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

void Bfx_ToggleBits_u8(uint8_t *Data)
{ // Thisfunctiontogglesall thebitsofdata(1’sComplementData).
    *Data = ~(*Data);
}

void Bfx_ToggleBitMask_u8u8(uint8_t *Data, uint8_t Mask)
{ // This function toggles the bits of data when the corresponding bit of the mask is enabled and set
  // to 1.
    *Data = *Data ^ Mask;
}

void Bfx_ShiftBitRt_u8u8(uint8_t *Data, uint8_t ShiftCnt)
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

void Bfx_ShiftBitLt_u8u8(uint8_t *Data, uint8_t ShiftCnt)
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

void Bfx_RotBitRt_u8u8(uint8_t *Data, uint8_t ShiftCnt)
{
    // This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
    // most significant bit location for every single bit shift cycle
    ShiftCnt %= 8; // Para asegurarnos de que ShiftCnt esté en el rango de 0 a 7
    *Data = (*Data >> ShiftCnt) | (*Data << (8 - ShiftCnt));
}

void Bfx_RotBitLt_u8u8(uint8_t *Data, uint8_t ShiftCnt)
{
    // This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
    // most significant bit location for every single bit shift cycle
    ShiftCnt %= 8; // Para asegurarnos de que ShiftCnt esté en el rango de 0 a 7
    *Data = (*Data << ShiftCnt) | (*Data >> (8 - ShiftCnt));
}

void Bfx_CopyBit_u8u8u8u8(uint8_t *DestinationData, uint8_t DestinationPosition, uint8_t SourceData, uint8_t SourcePosition)
{
    // Máscara para aislar el bit específico en SourceData
    uint8_t sourceBit = (SourceData >> SourcePosition) & 0x01;
    *DestinationData &= ~(1 << DestinationPosition);
    *DestinationData |= (sourceBit << DestinationPosition);
}

void Bfx_PutBits_u8u8u8u8(uint8_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Pattern)
{
    // ThisfunctionshallputbitsasmentionedinPatterntotheinputDatafromthespecifiedbit
    // position.
    uint8_t Mask = ((1 << BitLn) - 1) << BitStartPn;
    *Data &= ~Mask;
    *Data |= (Pattern << BitStartPn) & Mask;
}

void Bfx_PutBitsMask_u8u8u8(uint8_t *Data, uint8_t Pattern, uint8_t Mask)
{
    *Data = (*Data & ~Mask) | (Pattern & Mask);
}

void Bfx_PutBit_u8u8u8(uint8_t *Data, uint8_t BitPn, bool Status)
{
    uint8_t mask = 1 << BitPn;
    if (Status)
    {
        *Data |= mask; // Establecer el bit
    }
    else
    {
        *Data &= ~mask; // Limpiar el bit
    }
}

uint8_t Bfx_ShiftBitSat_u8s8_u8(int8_t ShitfCnt, uint8_t Data)
{
    uint8_t result;

    if (ShitfCnt > 0)
    {
        // Desplazamiento a la derecha (shift right)
        if (ShitfCnt >= 8)
        {
            result = 0; // Saturación, el resultado es 0
        }
        else
        {
            result = Data >> ShitfCnt;
        }
    }
    else if (ShitfCnt < 0)
    {
        // Desplazamiento a la izquierda (shift left)
        if (ShitfCnt <= -8)
        {
            result = 0xFF; // Saturación, el resultado es 0xFF (todos los bits a 1)
        }
        else
        {
            result = Data << (-ShitfCnt);
        }
    }
    else
    {
        // ShiftCnt == 0, no se realiza ningún desplazamiento
        result = Data;
    }

    return result;
}

int8_t Bfx_ShiftBitSat_s8s8_s8(int8_t ShitfCnt, uint8_t Data)
{
    uint8_t result;

    if (ShitfCnt > 0)
    {
        // Desplazamiento a la derecha (shift right)
        if (ShitfCnt >= 8)
        {
            result = 0; // Saturación, el resultado es 0
        }
        else
        {
            result = (int8_t)(Data >> ShitfCnt);
        }
    }
    else if (ShitfCnt < 0)
    {
        // Desplazamiento a la izquierda (shift left)
        if (ShitfCnt <= -8)
        {
            result = -1; // Saturación, el resultado es 0xFF (todos los bits a 1)
        }
        else
        {
            result = (int8_t)(Data << (-ShitfCnt));
        }
    }
    else
    {
        // ShiftCnt == 0, no se realiza ningún desplazamiento
        result = (int8_t)Data;
    }

    return result;
}

uint8_t Bfx_CountLeadingOnes_u8(uint8_t Data)
{
    // Count the number of consecutive ones in Data starting with the most significant bit and return
    // the result.
    uint8_t count = 0;

    // Mientras el bit más significativo sea 1, incrementa el contador
    while ((Data & 0x80) && (count < 8)) // 10000000
    {
        count++;
        Data <<= 1; // Desplaza el dato hacia la izquierda
    }

    return count;
}

uint8_t Bfx_CountLeadingSigns_u8(int8_t Data)
{
    uint8_t msb = (Data >> 7) & 1; // Obtiene el bit más significativo de Data
    uint8_t count = 0;

    // Mientras el bit en posición msb-1 sea igual al bit más significativo
    while (((Data >> 6) & 1) == msb && count < 7)
    {
        count++;
        Data <<= 1; // Desplaza el dato hacia la izquierda
    }

    return count;
}

uint8_t Bfx_CountLeadingZeros_u8(uint8_t Data)
{
    uint8_t count = 0;

    // Itera mientras el bit más significativo sea 0
    while ((Data & 0x80) == 0 && count < 8)
    {
        count++;
        Data <<= 1; // Desplaza el dato hacia la izquierda
    }

    return count;
}
