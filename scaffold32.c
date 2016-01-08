#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include "scaffold32.h"
void Product32(void *a, void *b, void *c, unsigned int wa,
        unsigned int ba, unsigned int wb, unsigned int bb, unsigned int
        *wc, unsigned int *bc){
    unsigned int *int_a = (unsigned int *) a;
    unsigned int *int_b = (unsigned int *) b;
	
	*wc = wa + wb;
	unsigned int i,j;
	unsigned long long int mp,mc;
	unsigned int *int_c = (unsigned int *) c;
	
	for(i = 0; i < *wc; i++) int_c[i] = 0;
	for(i = 0; i < wa; i++) {
		mc = 0;
		for(j = 0; j < wb; j++) {
			mp = (unsigned long long int)int_a[i] * int_b[j] + int_c[i+j] + mc;
			int_c[i+j] = mp & 0xffffffff;
			mc = mp>>32;
		}
		int_c[i + wb] = mc;
	}
}