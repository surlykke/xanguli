/*
 *  Xanguli.h
 *
 *  Created on: 03-10-2008
 *      Author: Christian Surlykke
 */

#ifndef XANGULI_H_
#define XANGULI_H_

#include <string>
#include "Variant.h"

namespace Xanguli {

	class Xanguli {// Singleton
	public:
		static void run();
		Xanguli();
		void CreateController(std::string& path);
		void Abort(int i, std::string s, Variant v) {};

	private:
		DBusConnection *sessionBus;
	};
}
#endif /* XANGULI_H_ */
