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
	T operator*();
	void operator=(Ptr<T> other);
	virtual ~Ptr();
};

template <class T> class Handle {
friend Ptr;
private:
	Handle<T>(T obj);
	~Handle<T>();
	T obj;
};

}
#endif /* PTR_H_ */
