/*
 * Ptr.h
 *
 *  Created on: 01-09-2008
 *      Author: cpet2308
 */

#ifndef PTR_H_
#define PTR_H_

namespace Xanguli {

template <class T> class Ptr {
public:
	Ptr<T>(T obj);
	Ptr<T>(const Ptr<T>& ptr);
	T operator->();
	virtual ~Ptr();
};

}

#endif /* PTR_H_ */
