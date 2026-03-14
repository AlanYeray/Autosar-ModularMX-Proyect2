#ifndef BFX_8BITS_H_
#define BFX_8BITS_H_

#include <stdint.h>
#include <stdbool.h> // Booleanos

  void Bfx_SetBit_u8u8(uint8_t *Data, uint8_t BitPn);

  void Bfx_ClrBit_u8u8(uint8_t *Data, uint8_t BitPn);

  bool Bfx_GetBit_u8u8_u8(uint8_t *Data, uint8_t BitPn);

  void Bfx_SetBits_u8u8u8u8(uint8_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Status);

  uint8_t Bfx_GetBits_u8u8u8_u8(uint8_t Data, uint8_t BitStartPn, uint8_t BitLn);

  void Bfx_SetBitsMask_u8u8(uint8_t *Data, uint8_t Mask);

  void Bfx_ClrBitMask_u8u8(uint8_t *Data, uint8_t Mask);

  bool Bfx_TstBitMask_u8u8_u8(uint8_t Data, uint8_t Mask);

  bool Bfx_TstBitLnMask_u8u8_u8(uint8_t Data, uint8_t Mask);

  bool Bfx_TstParityEven_u8_u8(uint8_t Data);

  void Bfx_ToggleBits_u8(uint8_t *Data);

  void Bfx_ToggleBitMask_u8u8(uint8_t *Data, uint8_t Mask);

  void Bfx_ShiftBitRt_u8u8(uint8_t *Data, uint8_t ShiftCnt);

  void Bfx_ShiftBitLt_u8u8(uint8_t *Data, uint8_t ShiftCnt);

  void Bfx_RotBitRt_u8u8(uint8_t *Data, uint8_t ShiftCnt);

  void Bfx_RotBitLt_u8u8(uint8_t *Data, uint8_t ShiftCnt);

  void Bfx_CopyBit_u8u8u8u8(uint8_t *DestinationData, uint8_t DestinationPosition, uint8_t SourceData, uint8_t SourcePosition);

  void Bfx_PutBits_u8u8u8u8(uint8_t *Data, uint8_t BitStartPn, uint8_t BitLn, uint8_t Pattern);

  void Bfx_PutBitsMask_u8u8u8(uint8_t *Data, uint8_t Pattern, uint8_t Mask);

  void Bfx_PutBit_u8u8u8(uint8_t *Data, uint8_t BitPn, bool Status);

  uint8_t Bfx_ShiftBitSat_u8s8_u8(int8_t ShitfCnt, uint8_t Data);

  int8_t Bfx_ShiftBitSat_s8s8_s8(int8_t ShitfCnt, uint8_t Data);

  uint8_t Bfx_CountLeadingOnes_u8(uint8_t Data);

  uint8_t Bfx_CountLeadingSigns_u8(int8_t Data);

  uint8_t Bfx_CountLeadingZeros_u8(uint8_t Data);

#endif