/*
 * XanguliException.h
 *
 *  Created on: 15-10-2008
 *      Author: christian
 */

#ifndef XANGULIEXCEPTION_H_
#define XANGULIEXCEPTION_H_
#include <string>

class XanguliException {
public:
	XanguliException(std::string errorMsg);
	virtual ~XanguliException();
	std::string errorMsg;
};

#endif /* XANGULIEXCEPTION_H_ */
