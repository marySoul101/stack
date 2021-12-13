#pragma once
#include "pch.h"
#include<assert.h>
namespace Algo {
	template<class T>
	class Node;
	template<class T>
	class Stack
	{

	public:
		
		void push(T* E)
		{
			Node<T>* newNode = new Node<T>();
			assert(newNode != 0);//débug
			//tru catch mode release 
			newNode->data = E;
			newNode->next = this->head;
			this->head = newNode;
		}
		void pop()
		{
			assert(!this->empty());
			Node<T>* supp = this->head;
			this->head = this->head->next;
			delete supp;
			supp = 0;
		}
		bool empty() const
		{
			bool res = (this->head == 0);
			return res;
		}
		T* top() const
		{
			assert(!this->empty());
			return this->head->data;
		}
		static Stack* creator()
		{
			Stack* S = new Stack();
			assert(S);
			return S;
		}
		static void garbage(Stack* S)
		{
			if (S)
				delete S;
		}
	private:
		class Node<T>* head;
		Stack()
		{
			this->head = 0;
		}

		~Stack()
		{
			while (this->head)
			{
				this->pop();
			}
			delete this->head;
			this->head = 0;
		}
		
	};
	template<class T>
	class Node
	{
	private:
		T* data;
		Node* next;
	public:
		//friend class Stack;
		/*T* getData()const {
			return this->data;
		}
		void setData(T* s) {
			this->data = s;
		}*/
	};
};

