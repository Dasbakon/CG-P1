#include "SceneObjectList.h"

using namespace cg;


void SceneObjectList::append(Reference<SceneObject> scn_object)
{
	if (this->_tail != nullptr)
	{
		this->_tail->next() = scn_object;
		scn_object->previous() = this->_tail;
	}

	this->_tail = scn_object;

	if (this->_head == nullptr)
	{
		this->_head = this->_tail;
	}
}

void SceneObjectList::remove(Reference<SceneObject> scn_object)
{
	bool is_head = false;
	bool is_tail = false;

	// 1 - caso seja no meio da lista
	
	// 2 - caso seja cabeça da lista
	if (&this->_head == &scn_object)
		is_head = true;

	// 3 - caso seja fim da lista
	if (&this->_tail == &scn_object)
		is_tail = true;

	// 4 - caso seja lista unitária
	if (is_head && is_tail)
	{
		this->head() = this->tail() = NULL;
	}

	return;

	SceneObject* previous = scn_object->previous();
	SceneObject* next = scn_object->next();

	previous->next() = scn_object->next();
	next->previous() = scn_object->previous();

	scn_object->previous() = nullptr;
	scn_object->next() = nullptr;

	/*if (this->previous() != nullptr)
		this->previous().get()->_next = this->next();
	if (this->next() != nullptr)
		this->next().get()->_previous = this->previous();*/


}

Reference<SceneObject> SceneObjectList::iterate() const
{
	for (Reference<SceneObject> node = _head; node != nullptr; node = node.get()->next())
		return (node);
}