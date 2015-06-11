/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

uint32_t reverseBits(uint32_t n)
{
	uint32_t mask_h = 0x80000000;
	uint32_t mask_l = 1;
	while (mask_l < mask_h)
	{
		if (mask_l & n)
		{
			if ((mask_h & n) == 0)
			{
				n |= mask_h;
				n ^= mask_l;
			}
		}
		else
		{
			if (mask_h & n)
			{
				n |= mask_l;
				n ^= mask_h;
			}
		}
		mask_h >>= 1;
		mask_l <<= 1;
	}
	return n;
}