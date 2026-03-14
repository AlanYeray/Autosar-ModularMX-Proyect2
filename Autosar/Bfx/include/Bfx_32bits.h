#ifndef BFX_32BITS_H_
#define BFX_32BITS_H_

#include <stdbool.h>// Booleanos
#include <stdint.h>

 void Bfx_SetBit_u32u8( uint32_t *Data, uint8_t BitPn );

 void Bfx_ClrBit_u32u8( uint32_t *Data, uint8_t BitPn );

 bool Bfx_GetBit_u32u8_u8( uint32_t Data, uint8_t BitPn );

 void Bfx_SetBits_u32u8u8u8( uint32_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Status );

 uint32_t Bfx_GetBits_u32u8u8_u8( uint32_t Data, uint8_t BitStartPn, uint8_t BitLn );

 void Bfx_SetBitsMask_u32u32( uint32_t *Data, uint32_t Mask);

 void Bfx_ClrBitMask_u32u32( uint32_t *Data, uint32_t Mask);

 bool Bfx_TstBitMask_u32u32_u8( uint32_t Data, uint32_t Mask);

 bool Bfx_TstBitLnMask_u32u32_u8(uint32_t Data, uint32_t Mask);

 bool Bfx_TstParityEven_u32_u8( uint32_t Data);

 void Bfx_ToggleBits_u32( uint32_t *Data);

 void Bfx_ToggleBitMask_u32u32(uint32_t *Data, uint32_t Mask);

 void Bfx_ShiftBitRt_u32u8( uint32_t *Data, uint8_t ShiftCnt);

 void Bfx_ShiftBitLt_u32u8( uint32_t *Data, uint8_t ShiftCnt);

 void Bfx_RotBitRt_u32u8( uint32_t *Data, uint8_t ShiftCnt );

 void Bfx_RotBitLt_u32u8( uint32_t *Data, uint8_t ShiftCnt );

 void Bfx_CopyBit_u32u8u32u8( uint32_t *DestinationData, uint8_t DestinationPosition, uint32_t SourceData, uint8_t SourcePosition);

 void Bfx_PutBits_u32u8u8u8( uint32_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint32_t Pattern);

 void Bfx_PutBitsMask_u32u32u32( uint32_t *Data, uint32_t Pattern, uint32_t Mask);

 void Bfx_PutBit_u32u8u8( uint32_t *Data, uint8_t BitPn, bool Status);

 uint32_t Bfx_ShiftBitSat_u32s8_u32( int8_t ShitfCnt, uint8_t Data);

 int32_t Bfx_ShiftBitSat_s32s8_s32( int32_t ShitfCnt, int8_t Data);

 uint32_t Bfx_CountLeadingOnes_u32(uint32_t Data);

 uint32_t Bfx_CountLeadingSigns_s32(int32_t Data);

 uint32_t Bfx_CountLeadingZeros_u32(uint8_t Data);

#endif