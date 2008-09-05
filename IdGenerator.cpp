/*
 * IdGenerator.cpp
 *
 *  Created on: 27-08-2008
 *      Author: cpet2308
 */

#include "IdGenerator.h"
#include <sstream>

namespace Xanguli {

int IdGenerator::id;

std::string IdGenerator::generateId() {
	std::stringstream ss;
	ss << (++id);
	return ss.str();
}

IdGenerator::IdGenerator() {
	// TODO Auto-generated constructor stub

}

IdGenerator::~IdGenerator() {
	// TODO Auto-generated destructor stub
}


}
