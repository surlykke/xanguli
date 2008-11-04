/*
 * Variant.h
 *
 *  Created on: 19-10-2008
 *      Author: christian
 */

#ifndef VARIANT_H_
#define VARIANT_H_

struct Variant {
	int type;
	union {
		unsigned int ui;
		int           i;
		char**        s;
	};
};

#endif /* VARIANT_H_ */
