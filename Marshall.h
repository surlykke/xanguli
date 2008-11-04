/*
 * marshall.h
 *
 *  Created on: 25-10-2008
 *      Author: christian
 */

#ifndef MARSHALL_H_
#define MARSHALL_H_
#include <string>
#include <vector>
#include <map>
#include "Variant.h"

template<typename T> void marshall(DBusMessageIter* iter, T& v) {
	dbus_message_iter_get_basic(iter, &v);
};

template<> void marshall<std::string>(DBusMessageIter* iter, std::string& s) {
   char* str;
   dbus_message_iter_get_basic(iter, str);
   s = str;
};

template<> void marshall<Variant>(DBusMessageIter* iter, Variant& s) {
	DBusMessageIter sub_iter;
	dbus_message_iter_recurse(iter, &sub_iter);
	char* var_sig = dbus_message_iter_get_signature(&sub_iter);
	switch (*var_sig) {
	case 'u': dbus_message_iter_get_basic(&sub_iter, &(s.ui)); s.type = DBUS_TYPE_UINT32; break;
	case 'i': dbus_message_iter_get_basic(&sub_iter, &(s.i));  s.type = DBUS_TYPE_INT32;  break;
	case 's': dbus_message_iter_get_basic(&sub_iter, &(s.s));  s.type = DBUS_TYPE_STRING; break;
	default:
	  // Throw an error
	  ;
	}
}

void deMarshall(DBusMessageIter* iter, int i) {
	dbus_message_iter_append_basic(iter, DBUS_TYPE_INT32, &i);
};

void deMarshall(DBusMessageIter* iter, std::string s) {
   const char* str = s.c_str();
   dbus_message_iter_append_basic(iter, DBUS_TYPE_STRING, &str);
};

void deMarshall(DBusMessageIter* iter, Variant& s) {
	DBusMessageIter sub_iter;
	dbus_message_iter_recurse(iter, &sub_iter);
	char* var_sig = dbus_message_iter_get_signature(&sub_iter);
	switch (*var_sig) {
	case 'u': dbus_message_iter_get_basic(&sub_iter, &(s.ui)); s.type = DBUS_TYPE_UINT32; break;
	case 'i': dbus_message_iter_get_basic(&sub_iter, &(s.i));  s.type = DBUS_TYPE_INT32;  break;
	case 's': dbus_message_iter_get_basic(&sub_iter, &(s.s));  s.type = DBUS_TYPE_STRING; break;
	default:
	  // Throw an error
	  ;
	}
}

template<typename T> void marshall(DBusMessageIter* iter, std::vector<T>& v) {
}

template<typename K, typename V> void marshall(DBusMessageIter* iter, std::map<K,V>& m) {
}

#endif /* MARSHALL_H_ */
