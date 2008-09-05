/*
 * IdGenerator.h
 *
 *  Created on: 27-08-2008
 *      Author: cpet2308
 */

#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_
#include <string>

namespace Xanguli {

class IdGenerator {
public:
	static std::string generateId();
private:
	IdGenerator();
	virtual ~IdGenerator();
	static int id;
};

}
#endif /* IDGENERATOR_H_ */
