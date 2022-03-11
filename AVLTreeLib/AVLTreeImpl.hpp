template<typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::Node*
AVLTree<KeyType, ValueType>::_rotL(Node* pivot) {
	//rotation impossible, return
	if(!pivot -> _child[1]) {
		return pivot;
	}
	Node* newPivot = pivot -> _child[1];
	pivot -> _child[1] = newPivot -> _child[0];
	newPivot -> _child[0] = pivot;
	return newPivot;
}

template<typename KeyType, typename ValueType>
typename AVLTree<KeyType, ValueType>::Node*
AVLTree<KeyType, ValueType>::_rotR(Node* pivot) {
	//rotation impossible, return
	if(!pivot -> _child[0]) {
		return pivot;
	}
	Node* newPivot = pivot -> _child[0];
	pivot -> _child[0] = newPivot -> _child[1];
	newPivot -> _child[1] = pivot;
	return newPivot;
}

template<typename KeyType, typename ValueType>
int AVLTree<KeyType, ValueType>::_recursiveInsert
(Node*& node, const KeyType& key, const ValueType& value, ValueType (*functor)(const ValueType&)) {
	//first element + deep root skip
	if(node == AVLTree::_deeproot){
		if(!AVLTree::_size) {
			AVLTree::_deeproot -> _child[0] = new Node(key, value);
			AVLTree::_size++;
		}
		else {
			_recursiveInsert(AVLTree::_deeproot -> _child[0], key, value, functor);
		}
		return 0;
	}
	//multiple elements
	int returnVal = 0;
	if(key > node -> _key) {
		//traversal right
		if(node -> _child[1]) {
			returnVal = _recursiveInsert(node -> _child[1], key, value, functor);
			node -> _balFactor += returnVal;
		}
		//insertion
		else {
			node -> _child[1] = new Node(key, value);
			node -> _balFactor++;
			AVLTree::_size++;
			//tree height influence
			if(node -> _balFactor) {
				returnVal = 1;
			}
		}
	}
	else if(key < node -> _key) {
		//traversal left
		if(node -> _child[0]) {
			returnVal = _recursiveInsert(node -> _child[0], key, value, functor);
			node -> _balFactor -= returnVal;
		}
		//insertion
		else {
			node -> _child[0] = new Node(key, value);
			node -> _balFactor--;
			AVLTree::_size++;
			//tree height influence
			if(node -> _balFactor) {
				returnVal = 1;
			}
		}
	}
	//replacing
	else if(key == node -> _key) {
		if(!functor) {
			node -> _value = value;
		}
		else {
			node -> _value = functor(node -> _value);
		}
	}
	//non-exit return traversal with balancing
	if(node -> _balFactor > 1) {
		Node* pivot = node -> _child[1];
		//RL
		if(pivot -> _balFactor < 0) {
			node -> _child[1] = _rotR(pivot);
		}
		//adjust balance factors
		pivot -> _balFactor = 0;
		node -> _balFactor = 0;
		//LL
		node = _rotL(node);
		returnVal = 0;
	}
	if(node -> _balFactor < -1) {
		Node* pivot = node -> _child[0];
		//LR
		if(pivot -> _balFactor > 0) {
			node -> _child[0] = _rotL(pivot);
		}
		//adjust balance factors
		pivot -> _balFactor = 0;
		node -> _balFactor = 0;
		//RR
		node = _rotR(node);
		returnVal = 0;
	}
	//merge return paths
	return returnVal;
}

template<typename KeyType, typename ValueType>
void AVLTree<KeyType, ValueType>::insert
(const KeyType& key, const ValueType& value) {
	_recursiveInsert(AVLTree::_deeproot, key, value);
}

template<typename KeyType, typename ValueType>
void AVLTree<KeyType, ValueType>::insert
(const KeyType& key, const ValueType& value, ValueType (*functor)(const ValueType&)) {
	_recursiveInsert(AVLTree::_deeproot, key, value, functor);
}

template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, AVLTree<KeyType, ValueType> const& tree) {
	tree.print(stream);
	return stream;
}
