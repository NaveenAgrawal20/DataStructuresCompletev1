## 1. LL_Rotation(INFO,LEFT,RIGHT,HEIGHT,P)
This algo rotates node P in Right direction.

    1. Intialize two POINTERs PL, PLR.
    2.  Set PL := LEFT[P] and PLR := RIGHT[PLR].
    3.  Set LEFT[P] := PLR.
    4.  Set RIGHT[PL] := P.  
    5.  Set HEIGHT[P] := NodeHeight(P).
    6.  Set HEIGHT[PL] := NodeHeight(PL).
    7.  If ROOT = P, then:
            ROOT = PL.
    8.  Return PL.
***

## 2. LR_Rotation(INFO,LEFT,RIGHT,HEIGHT,P)
This algo rotates node LEFT[P] in Right direction and P in Left direction.

    1.  Initialize two POINTERs PL,PLR.
    2.  Set PL := LEFT[P] and PLR := RIGHT[PL].
    3.  Set LEFT[P] := RIGHT[PLR].
    4.  Set RIGHT[PL] := LEFT[PLR].
    5.  Set LEFT[PLR] := PL and RIGHT[PLR] := P.
    6.  Set HEIGHT[P] := NodeHeight(P).
    7.  Set HEIGHT[PL] := NodeHeight(PL).
    8.  Set HEIGHT[PLR] := NodeHeight(PLR).
    9.  If ROOT = PLR, then:
            ROOT = PLR.
    10. Return PLR.
<br>

___

**_Note_**: You may now have idea of RR and RL rotation. 