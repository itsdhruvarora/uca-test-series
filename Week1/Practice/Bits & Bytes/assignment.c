/* 

Bits and Bytes
Pre-requisites: 
Knowledge of
bitwise operators &, |, >>, <<, ^, ~
Data representation of signed and unsigned integers

*/


// Q1. BitAnd

// /*
// /*  bitAnd - x & y using only ~ and |
// /* Example bitAnd(6, 5) = 4
// */ Legal ops:  ~ |  
// /*Max ops: 8
// */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}



// Q2.   BitXor

/*
/*  bitXor - x ^ y using only ~ and &
/* Example bitXor(4, 5) = 1
*/ 
// Legal ops:  ~ &  
/* Max ops: 14
*/
int bitXor(int x, int y) {
    int a = x & (~y);
    int b = (~x) & y;
    int res = (~a) & (~b);
    return res;
}



// Q3. Sign

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/
int sign(int x) {
    return (x>>31 & ~0 ) | (!!x);  
}


// Q4. GetByte

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/
int getByte(int x, int n) {
    return (x>>(n<<3))&255;
}





// Q5. LogicalShift

/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/
int logicalShift(int x, int n) {
    int shift_amount = 32 + (~n + 1);
    int mask = ((1 << shift_amount) + ~0);

    return (x >> n) & mask;
}



// Q6. Conditional

/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/
int conditional(int x, int y, int z) {
    return 0;
}
int conditional(int x, int y, int z) {
    int mask = ((!x) + ~0);
    return (mask & y) | (~mask & z);
}






// Q7. Bang

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}



// Q8. Invert

/* 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
/* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
/* Legal ops: ~ & ^ | << >>
/* as zero
*/
int invert(int x, int p, int n) {
    int mask = ~((~0)<<n) << p;
    // printf("%x",a^mask);
    return x ^ mask;
}
