#ifndef DYNAMICLIST_H_
#define DYNAMICLIST_H_

#define NULL 0
// **** Node ****
template <typename T>
class Node
{
public:
	Node(int _nodeID, T* _data)
	{
		nodeID = _nodeID;
		next = NULL;
		data = _data;
	}

	Node()
	{

	}

	~Node()
	{
		if(data)
			delete data;
	}

	//sets e gets

	Node* GetNext() const
	{
		return next;
	}

	void SetNext(Node* _next)
	{
		next = _next;
	}

	int GetNodeID() const
	{
		return nodeID;
	}

	T* GetNodeData() const
	{
		return data;
	}

	void SetData(T* _data) //provavelmente não será usada
	{
		data = _data;
	}

private:

	int nodeID; //numero usado na busca
	Node* next; //ponteiro pro proximo node
	T* data;    //ponteiro pra uma imagem, uma mensagem, um som, o que quer que seja que precisar ser guardado
};





// **** DynamicList ****
template <typename T>
class DynamicList
{
public:
	DynamicList(Node<T>* _node)
	{
		this->SetHead(_node);
	}

	~DynamicList()
	{
		this->DeleteList();
	}

	//sets e gets
	Node<T>* GetHead() const
	{
		return head;
	}

	void SetHead(Node<T>* _head)
	{
		head = _head;
	}

	Node<T>* GetNode(int _nodeID) const
	{
		Node<T>* Finder;
		if (!head)
			return false;
		Finder = head;
		for (; Finder; Finder = Finder->GetNext()) 
		{
			if (Finder->GetNodeID() == _nodeID) //se o nome for igual, retorna o ponteiro do node
				return Finder;
		}
		return false;
	}

	void NewNode (Node<T>* _node) // Método para adicionar um elemento novo ao final da lista.
	{ 	
		if (!this->GetHead() || this->GetHead()->GetNodeData() == NULL) //Se ainda não houver head, ou se a data de head estiver nula
		{
			this->SetHead(_node);
		}
		else
		{
			Node<T>* Finder = this->GetHead();
			while (Finder->GetNext())
				Finder = Finder->GetNext();
			Finder->SetNext(_node);
		}
	}

	//outras
	bool Delete(int _nodeID)
	{
		Node<T>* deleter;
		Node<T>* aux;

		if(!this->GetNode(_nodeID) ) //não há mensagem com esse Id na lista
			return false;

		if(head->GetNodeID() == _nodeID)
		{
			if (!head->GetNext()) //se não houver outro nó além da head, não deletar
			{
				delete head;
				head = NULL;
			}
			else
			{
				aux = head->GetNext(); //se head tiver a mensagem a ser deletada, head agora aponta para o nó seguinte
				delete head;
				head = aux;
				return true;
			}
		}
		else
		{
			deleter = head;

			while (deleter) //enquanto não chegar no fim
			{
				if (deleter->GetNext()) //se há um próximo node
				{
					if (deleter->GetNext()->GetNodeID() == _nodeID) //verifica se o próximo tem a node mensagem procurada
					{
						aux = deleter->GetNext()->GetNext(); //caso tenha, perde o ponteiro do proximo node e pega o do seguinte
						delete deleter->GetNext();
						deleter->SetNext(aux);
						return true;
					}
				}
				deleter = deleter->GetNext(); //passa para o próximo
			}
			return false;
		}
	}

	void DeleteList()
	{
		Node<T>* superDeleter;
		Node<T>* aux;

		superDeleter = head;

		if(!superDeleter)
			return;
		else
		{
			while(superDeleter->GetNext()) //se há um próximo node
			{
				aux = superDeleter->GetNext(); //guarda o proximo
				delete superDeleter; //deleta o primeiro
				superDeleter = aux; //aponta para o proximo
			}
			delete superDeleter; //deleta o ultimo restante
		}
	}

private:

	Node<T>* head;
};

#endif