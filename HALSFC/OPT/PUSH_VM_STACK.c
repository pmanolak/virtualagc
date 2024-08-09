/*
  File PUSH_VM_STACK.c generated by XCOM-I, 2024-08-09 12:38:53.
*/

#include "runtimeC.h"

int32_t
PUSH_VM_STACK (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (int32_t)0;
    }
  reentryGuard = guardReentry (reentryGuard, "PUSH_VM_STACK");
  // IF C_TRACE THEN (2628)
  if (1 & (bitToFixed (getBIT (8, mC_TRACE))))
    // OUTPUT = 'PUSH_VM_STACK '; (2629)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "PUSH_VM_STACK ");
      OUTPUT (0, stringRHS);
      stringRHS->inUse = 0;
    }
  // ST = LOOP_STACKSIZE - (V_STACK_INX = 0); (2630)
  {
    int32_t numberRHS
        = (int32_t)(xsubtract (5, xEQ (COREHALFWORD (mV_STACK_INX), 0)));
    descriptor_t *bitRHS;
    bitRHS = fixedToBit (32, (int32_t)(numberRHS));
    putBIT (16, mST, bitRHS);
    bitRHS->inUse = 0;
  }
  // DO WHILE ST >= LOOP_STACKSIZE - 1; (2631)
  while (1 & (xGE (COREHALFWORD (mST), 4)))
    {
      // IF ST = LOOP_STACKSIZE THEN (2632)
      if (1 & (xEQ (COREHALFWORD (mST), 5)))
        // ST1 = LOOP_STACKSIZE -1; (2633)
        {
          int32_t numberRHS = (int32_t)(4);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mST1, bitRHS);
          bitRHS->inUse = 0;
        }
      // ELSE (2634)
      else
        // ST1 = 0; (2635)
        {
          int32_t numberRHS = (int32_t)(0);
          descriptor_t *bitRHS;
          bitRHS = fixedToBit (32, (int32_t)(numberRHS));
          putBIT (16, mST1, bitRHS);
          bitRHS->inUse = 0;
        }
      // CALL MOVE_LOOP_STACK; (2636)
      MOVE_LOOP_STACK (0);
      // ST = ST - 1; (2637)
      {
        int32_t numberRHS = (int32_t)(xsubtract (COREHALFWORD (mST), 1));
        descriptor_t *bitRHS;
        bitRHS = fixedToBit (32, (int32_t)(numberRHS));
        putBIT (16, mST, bitRHS);
        bitRHS->inUse = 0;
      }
    } // End of DO WHILE block
  // IF V_STACK_INX = 0 THEN (2638)
  if (1 & (xEQ (COREHALFWORD (mV_STACK_INX), 0)))
    // V_STACK_INX = 1; (2639)
    {
      int32_t numberRHS = (int32_t)(1);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mV_STACK_INX, bitRHS);
      bitRHS->inUse = 0;
    }
  // ELSE (2640)
  else
    // V_STACK_INX = 2; (2641)
    {
      int32_t numberRHS = (int32_t)(2);
      descriptor_t *bitRHS;
      bitRHS = fixedToBit (32, (int32_t)(numberRHS));
      putBIT (16, mV_STACK_INX, bitRHS);
      bitRHS->inUse = 0;
    }
  {
    reentryGuard = 0;
    return 0;
  }
}
