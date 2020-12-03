# File Format

## Format

***int is stored in little-endian format.***

||different char count (n)|char & count array|bit length (m)|compressed data content|
|------|-----|-----|-----|-----|
|length|1    |5*n  |4    |m/8  |

- appeared char count

    the number of different characters in the file.

- char & count array

    each element in this array is composed from two parts:
        
    - char (char, 1 byte)

        which character it is.
        
    - count (int, 4 bytes)

        the number of each character appeared in the file.

    so each element has 5 bytes and there are *n* elements in this array.

- bit length

    how many **bits** does the compressed data has.

- compressed data content

    compressed data.

## Example

data:

    0x03650400000061020000006c010000000A000000B70

decompressed data:

    eaeaeel

note:

    0x65: e
    0x61: a
    0x6c: l

    huffman code:
        e: 1
        a: 01
        l: 00

explaination:

    0x03: the number of different characters is 3.

    0x6504000000: the first character is e, and it appears 4 times in the original file.

    0x6102000000: the second character is a, and it appears twice in the original file.

    0x6c01000000: the third character is l. and it appears once in the origianl file.

    0x0A000000: there are 10 bits in the compressed data.

    0xB70 or 0b101101110000:
        1 ->  e
        01 -> a
        1 ->  e
        01 -> a
        1 ->  e
        1 ->  e
        00 -> l
