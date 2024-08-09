/*
  File DUMPITxFORM_UP.c generated by XCOM-I, 2024-08-09 12:38:15.
*/

#include "runtimeC.h"

descriptor_t *
DUMPITxFORM_UP (int reset)
{
  static int reentryGuard = 0;
  if (reset)
    {
      reentryGuard = 0;
      return (descriptor_t *)0;
    }
  reentryGuard = guardReentry (reentryGuard, "DUMPITxFORM_UP");
  // IF VAL2>VAL1 THEN (9828)
  if (1
      & (xGT (getFIXED (mDUMPITxFORM_UPxVAL2),
              getFIXED (mDUMPITxFORM_UPxVAL1))))
    // S = ' <-<-<- '; (9829)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, " <-<-<- ");
      putCHARACTER (mS, stringRHS);
      stringRHS->inUse = 0;
    }
  // ELSE (9830)
  else
    // S = ''; (9831)
    {
      descriptor_t *stringRHS;
      stringRHS = cToDescriptor (NULL, "");
      putCHARACTER (mS, stringRHS);
      stringRHS->inUse = 0;
    }
  // S = I_FORMAT(VAL2, 8) || S; (9832)
  {
    descriptor_t *stringRHS;
    stringRHS
        = xsCAT ((putFIXED (mI_FORMATxNUMBER, getFIXED (mDUMPITxFORM_UPxVAL2)),
                  putFIXED (mI_FORMATxWIDTH, 8), I_FORMAT (0)),
                 getCHARACTER (mS));
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // S = I_FORMAT(VAL1, 10) || S; (9833)
  {
    descriptor_t *stringRHS;
    stringRHS
        = xsCAT ((putFIXED (mI_FORMATxNUMBER, getFIXED (mDUMPITxFORM_UPxVAL1)),
                  putFIXED (mI_FORMATxWIDTH, 10), I_FORMAT (0)),
                 getCHARACTER (mS));
    putCHARACTER (mS, stringRHS);
    stringRHS->inUse = 0;
  }
  // RETURN MSG || S; (9834)
  {
    reentryGuard = 0;
    return xsCAT (getCHARACTER (mDUMPITxFORM_UPxMSG), getCHARACTER (mS));
  }
}
