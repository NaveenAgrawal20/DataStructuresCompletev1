## 1. Doubly Linked List
1. AddFirst 

This algo adds a new node at beginning.

    1.  If AVAIL = NULL then: RETURN.
    2.  Set NEW := AVAIL, AVAIL = NEXT[AVAIL].
    3.  Set INFO[NEW] := ITEM.
    4.  Set PREV[NEW] := NULL and NEXT[NEW] := START.
    5.  IF START != NULL, then:
            Set PREV[START] := NEW.
    5.  Set START = NEW.

2.  AddLast

This algo adds a new node at end.

    1.  If AVAIL = NULL then: RETURN.
    2.  Set NEW := AVAIL, AVAIL = NEXT[AVAIL].
    3.  Set INFO[NEW] := ITEM.
    4.  Set PTR := START.
    5.  Repeat step 6 while NEXT[PTR] != NULL.
    6.  Set PTR := NEXT[PTR].
    7.  Set NEXT[PTR] := NEW,
        NEXT[NEW] := NULL and PREV[NEW] := PTR.
    
3.  Delete

This algo delets a node from a doubly LL.
    
    1.  If START = NULL : RETURN.
    2.  [Only Node?]
        If INFO[START] = KEY and NEXT[START] := NULL   
            a.  Set TEMP := START.
            b.  Set START := NULL.
            c.  Set NEXT[TEMP] := AVAIL and AVAIL := TEMP. /*delete temp*/
    3.  [First Node?]
        If INFO[START] = KEY, then:
            a.  Set TEMP := START.
            b.  START := NEXT[TEMP].
            c.  PREV[START] := NULL.
            d.  Set NEXT[TEMP] := AVAIL and AVAIL := TEMP. /*delete temp.*/
    4.  [Middle Node ?]
        a.  Set Temp := NEXT[START].
        b.  Repeat step c to d while NEXT[TEMP] != NULL.
        c.  If INFO[TEMP] = KEY,then        [KEY FOUND ?]
                1.  NEXT[PREV[TEMP]] := NEXT[TEMP].
                2.  PREV[NEXT[TEMP]] := PREV[TEMP].
                3.  Delete TEMP and RETURN.
        d.  TEMP := NEXT[TEMP].
    5.  [Last Node ?]
        If INFO[TEMP] = KEY,then        [KEY FOUND ?]
            a.  NEXT[PREV[TEMP]] := NULL.
            b.  Delete TEMP and Return.
    6.  [Key Not Present ?]
        Write "key not found" and Return.

