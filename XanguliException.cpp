/*
 * XanguliException.cpp
 *
 *  Created on: 15-10-2008
 *      Author: christian
 */

#include "XanguliException.h"

XanguliException::XanguliException(std::string errorMsg) {
	this->errorMsg = errorMsg;
}

XanguliException::~XanguliException() {
}
