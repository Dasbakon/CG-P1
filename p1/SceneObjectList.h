#ifndef __SceneObjectList_h
#define __SceneObjectList_h

#include "SceneObject.h"

using namespace::cg;

class SceneObjectList
{
public:
	SceneObjectList()
	{
		this->_head = nullptr;
		this->_tail = nullptr;
	}
	auto head() const
	{
		return _head;
	}

	auto tail() const
	{
		return _tail;
	}

	void append(Reference<SceneObject> scn_object);

	void remove(Reference<SceneObject> scn_object);

	Reference<SceneObject> iterate() const;

private:
	Reference<SceneObject> _head;
	Reference<SceneObject> _tail;
};
#endif