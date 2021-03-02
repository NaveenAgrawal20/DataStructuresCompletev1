# Binary Search Tree

## 1. SEARCH(INFO,LEFT,RIGHT,ROOT,ITEM)
This procedure return the location LOC of ITEM.

    1.  Set PTR = ROOT.
    2.  Repeat steps 3 to 5 while PTR != NULL:
    3.      [ITEM at ROOT ?]      
            If ITEM = INFO[PTR], then:
                return PTR.
    4.      If ITEM < INFO[PTR], then:
                Set PTR := LEFT[PTR].
    5.      If ITEM > INFO[PTR], then:
                Set PTR := RIGHT[PTR].
    6.  [ITEM not Present]
        return NULL.

## 2. INSERT(INFO,LEFT,RIGHT,ROOT,ITEM,AVAIL)
This procedure Insert the new Node with ITEM in Tree 'T'.

    1.  [Tree Empty ?]
        If ROOT = NULL
        1.  NEWNODE := AVAIL, AVAIL := LEFT[AVAIL]      [Get Node from AVAIL].
        2.  Set INFO[NEWNODE] := ITEM.
            Set LEFT[NEWNODE] := NULL and RIGHT[NEWNODE] := NULL.
        3.  Set ROOT := NEWNODE.
        4.  Return.
    2.  [Initialize pointers PTR, R] 
        Set PTR := ROOT and R = NULL
    3.  Repeat while PTR != NULL:
    4.      Set R := PTR.
    5.      If ITEM = INFO[PTR], then:
                return.         [Duplicate Item is Not Allowed].
    6.      Else If ITEM < INFO[PTR], then:
                Set PTR := LEFT[PTR].
    7.      Else:
                Set PTR := RIGHT[PTR].
        [Reached the parent Node to insert the New node]
    8.  NEWNODE := AVAIL, AVAIL := LEFT[AVAIL]      [Get Node from AVAIL].
    9.  Set INFO[NEWNODE] := ITEM.
        Set LEFT[NEWNODE] := NULL and RIGHT[NEWNODE] := NULL.
        If ITEM < INFO[R], then:
            LEFT[R] := NEWNODE.
        Else:
            LEFT[R] := NEWNODE.

## 3. DELETE(INFO,LEFT,RIGHT,ROOT,ITEM,AVAIL)
