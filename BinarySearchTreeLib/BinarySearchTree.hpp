#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <utility>
#include <functional>

/*
	BinarySearchTree 
*/

template<typename KeyType, typename ValueType>
class BinarySearchTree;
template<typename KeyType, typename ValueType>
std::ostream& operator<<
(std::ostream&, const BinarySearchTree<KeyType, ValueType>&);

template<typename KeyType, typename ValueType>
class BinarySearchTree {

friend std::ostream& operator<<<KeyType, ValueType>
(std::ostream&, const BinarySearchTree<KeyType, ValueType>&);

public:
	BinarySearchTree(); //DONE
	~BinarySearchTree(); 

	void insert(const KeyType& key, const ValueType& value); //DONE
	void remove(const KeyType& key); //DONE

	ValueType* find(const KeyType& key) const; //DONE
	size_t size() const; //DONE

	std::string toString() const; //DONE
	template<typename StreamType>
	void print(StreamType& stream) const; //DONE
	
	std::list<std::pair<KeyType, ValueType>> enumerate() const; //DONE
	
protected:
	class Node;
	Node* _deeproot;
	Node* _root() const;
	size_t _size;
	
	Node* _find_parent(const KeyType& key) const; //DONE
	std::string _recursiveString(Node*) const; //DONE
	std::string _recursivePrint(Node*, std::string offset = "") const; //DONE
	bool _recursivePurge(Node*);
	
};

/*
	Node 
*/

template<typename KeyType, typename ValueType>
class AVLTree;

template<typename KeyType, typename ValueType>
class BinarySearchTree<KeyType, ValueType>::Node {

friend class BinarySearchTree<KeyType, ValueType>;
friend class AVLTree<KeyType, ValueType>;

public:
	Node(); //DONE
	Node(KeyType, ValueType); //DONE

	bool isLeaf() const; //DONE
	bool hasSingleChild() const; //DONE
	
	bool attachNode(KeyType, ValueType); //DONE
	bool detachNode(KeyType); //DONE
	
	bool operator==(const Node&) const;
	bool operator>(const Node&) const;
	bool operator<(const Node&) const;
	
private:
	KeyType _key;
	ValueType _value;
	Node* _child[2];
	int _balFactor;
};

#include "./BinarySearchTreeImpl.hpp"
