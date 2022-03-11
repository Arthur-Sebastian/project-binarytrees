/*
	Node
*/

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::operator==
(const Node& cmp) const {
	return (cmp._key == _key);
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::operator<
(const Node& cmp) const {
	return (cmp._key > _key);
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::operator>
(const Node& cmp) const {
	return (cmp._key < _key);
}


template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::Node::Node() {
	_key = KeyType();
	_value = ValueType();
	_child[0] = _child[1] = nullptr;
	_balFactor = 0;
}

template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::Node::Node(KeyType key, ValueType value) {
	_key = key;
	_value = value;
	_child[0] = _child[1] = nullptr;
	_balFactor = 0;
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::isLeaf() const {
	return (!_child[0] && !_child[1]);
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::hasSingleChild() const {
	return ((_child[0] == nullptr) ^ (_child[1] == nullptr));
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::attachNode
(KeyType key, ValueType value) {
	if(key == _key) {
		_value = value;
		return true;
	}
	if(key > _key && !_child[1]) {
		_child[1] = new Node(key, value);
		return true;
	}
	if(key < _key && !_child[0]) {
		_child[0] = new Node(key, value);
		return true;
	}
	return false;
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::Node::detachNode
(KeyType key) {
	for(Node*& child : _child) {
		//no child or no matching key
		if(!child || child -> _key != key) continue;
		//leaf node
		if(child -> isLeaf()) {
			delete child;
			child = nullptr;
			return true;
		}
		/*
			My friend Maurice expressed concerns
			regarding my naming ideas, but honestly
			he is as clueless as Inspector Norse.
		*/
		//node with one child
		if(child -> hasSingleChild()) {
			Node* orphan;
			if(child -> _child[0]) {
				orphan = child -> _child[0];
			}
			else {
				orphan = child -> _child[1];
			}
			delete child;
			child = orphan;
			return true;
		}
		//node with two kids
		if(!child -> hasSingleChild() && !isLeaf()) {
			Node *rep, *repPar;
			//find replacement
			repPar = child;
			rep = child -> _child[0];
			while(rep -> _child[1]) {
				repPar = rep;
				rep = rep -> _child[1];
			}
			//replace the two
			child -> _key = rep -> _key;
			child -> _value = rep -> _value;
			//check if replacement has left child
			if(rep -> _child[0]) {
				repPar -> detachNode(rep -> _key);
			}
			return true;
		}
	}
	return false;
}

/*
	BinarySearchTree
*/

template<typename KeyType, typename ValueType>
std::list<std::pair<KeyType, ValueType>>
BinarySearchTree<KeyType, ValueType>::enumerate() const {
	std::list<std::pair<KeyType, ValueType>> tree;
	//recursive tree traversal
	std::function<void(Node*)> recursion;
	recursion = [&recursion, &tree](Node* node) -> void {
		//traversals
		if(!node -> isLeaf()) {
			if(node -> _child[0]) {
				recursion(node -> _child[0]);			
			}
			if(node -> _child[1]) {
				recursion(node -> _child[1]);
			}
		}
		//exit with accumulation
		tree.push_front(
			std::pair<KeyType, ValueType>(
				node -> _key,
				node -> _value
			)
		);
	};
	recursion(_root());
	return tree;
}

template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::BinarySearchTree(){
	_deeproot = new Node();
	_size = 0;
}

template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::~BinarySearchTree(){
	_recursivePurge(_deeproot);
}

template<typename KeyType, typename ValueType>
size_t BinarySearchTree<KeyType, ValueType>::size() const {
	return _size;
}

template<typename KeyType, typename ValueType>
typename BinarySearchTree<KeyType, ValueType>::Node*
BinarySearchTree<KeyType, ValueType>::_root() const {
	if(_deeproot -> _child[0]) {
		return _deeproot -> _child[0];
	}
	else if(_deeproot -> _child[1]) {
		return _deeproot -> _child[1];
	}
	return nullptr;
}

template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::insert
(const KeyType& key, const ValueType& value) {
	//first added node
	if(!_size) {
		_deeproot -> attachNode(key, value);
		_size++;
		return;
	}
	//traverse the tree to find insertion place
	Node* c = _root();
	while(!c -> attachNode(key, value)) {
		//go left or right
		if(c -> _key < key) {
			c = c -> _child[1];
		}
		else {
			c = c -> _child[0];
		}
	}	
	_size++;
}

template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::remove(const KeyType& key) {
	//empty tree
	if(!_size) {
		return;
	}
	//non-empty tree
	Node* res = _find_parent(key);
	if(res == nullptr) {
		return;
	}
	res -> detachNode(key);
	_size--;
}

template<typename KeyType, typename ValueType>
ValueType* BinarySearchTree<KeyType, ValueType>::find(const KeyType& key) const {
	Node* c = _root();
	//"empty" tree
	if(c == nullptr) {
		return nullptr;
	}
	//traverse the tree
	while(c -> _key != key) {
		c -> _key > key ? c = c -> _child[0] : c = c -> _child[1];
		//if we went down to nullptr search failed
		if(!c) {
			return nullptr;
		}
	}
	return &(c -> _value);
}

template<typename KeyType, typename ValueType>
typename BinarySearchTree<KeyType, ValueType>::Node*
BinarySearchTree<KeyType, ValueType>::_find_parent(const KeyType& key) const {
	Node* c = _deeproot;
	while(c != nullptr) {
		//find child matching criteria
		for(Node* child : c -> _child){
			if(child && child -> _key == key) {
				return c;
			}
		}
		//otherwise traverse the tree
		c -> _key > key ? c = c -> _child[0] : c = c -> _child[1];
	}
	return nullptr;
}

template<typename KeyType, typename ValueType>
std::string BinarySearchTree<KeyType, ValueType>::toString() const {
	return _recursiveString(_root());
}

template<typename KeyType, typename ValueType>
template<typename StreamType>
void BinarySearchTree<KeyType, ValueType>::print(StreamType& stream) const {
	stream << _recursivePrint(_root());
}

template<typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& stream, const BinarySearchTree<KeyType, ValueType>& tree) {
	tree.print(stream);
	return stream;
}

template<typename KeyType, typename ValueType>
std::string BinarySearchTree<KeyType, ValueType>::_recursiveString(Node* n) const {
	//check if we reached the bottom of the structure
	if(n == nullptr) {
		return "";
	}
	//print self, then children and children...
	std::stringstream output;
	output << "([" << n -> _key << ',' << n -> _value << "],";
	if(n -> _child[0]) output << _recursiveString(n -> _child[0]);
	output << ',';
	if(n -> _child[1]) output << _recursiveString(n -> _child[1]);
	output << ')';
	return output.str();
}

template<typename KeyType, typename ValueType>
std::string BinarySearchTree<KeyType, ValueType>::_recursivePrint(Node* n, std::string offset) const {
	//check if we reached the bottom of the structure
	if(n == nullptr) {
		return "";
	}
	//print self, then children and children...
	std::stringstream output;
	output << "[" << n -> _key << ", " << n -> _value << "]" << '\n';
	offset += "    ";
	if(n -> _child[0]) output << offset << "L: " << _recursivePrint(n -> _child[0], offset);
	if(n -> _child[1]) output << offset << "R: " << _recursivePrint(n -> _child[1], offset);
	return output.str();
}

template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::_recursivePurge(Node* n) {
	//check for nullptr
	if(n == nullptr) {
		return false;
	}
	//for every child run destructor
	for(Node*& child : n -> _child) {
		if(_recursivePurge(child)) child = nullptr;
	}
	//remove self
	delete n;
	return true;
}


















