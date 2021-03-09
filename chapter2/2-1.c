#include <stdio.h>
#include <limits.h>
#include <float.h>

void main(void)
{
	printf(	"Integer and floating point range table\n\n"

		"unsigned char 	: %d ~ %d\n"
		"signed char 	: %d ~ %d\n"
		"unsigned short int :%d ~ %d\n"
		"signed short int : %d ~ %d\n"
		"unsigned int : %u ~ %u\n"
		"signed int : %d ~ %d\n"
		"unsigned long int : %lu ~ %lu\n"
		"signed long int : %ld ~ %ld\n"
		"unsigned long long int : %llu ~%llu\n"
		"signed long long int : %lld ~ %lld\n\n"

		"float : %e ~ %e\n"
		"double : %e ~ %e\n"
		"long double : %Le ~ %Le\n"
		, 0, UCHAR_MAX, SCHAR_MIN, SCHAR_MAX
		, 0, USHRT_MAX, SHRT_MIN, SHRT_MAX
		, 0, UINT_MAX, INT_MIN, INT_MAX
		, 0, ULONG_MAX, LONG_MIN, LONG_MAX
		, 0, ULLONG_MAX, LLONG_MIN, LLONG_MAX

		, FLT_MIN, FLT_MAX
		, DBL_MIN, DBL_MAX
		, LDBL_MIN, LDBL_MAX
		);
}