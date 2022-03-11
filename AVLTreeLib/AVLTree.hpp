#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>
#include "../BinarySearchTreeLib/BinarySearchTree.hpp"

template<typename KeyType, typename ValueType>
class AVLTree : public BinarySearchTree<KeyType, ValueType> {
	
public:
	using BinarySearchTree<KeyType, ValueType>::BinarySearchTree;
	void insert(const KeyType& key, const ValueType& value); //DONE
	void insert(
		const KeyType& key,
		const ValueType& value, 
		ValueType (*functor)(const ValueType&)
	);
	
	
private:
	typedef typename BinarySearchTree<KeyType, ValueType>::Node Node;
	
	Node* _rotL(Node*); //DONE
	Node* _rotR(Node*); //DONE
	int _recursiveInsert(
		Node*&, 
		const KeyType&, 
		const ValueType&, 
		ValueType (*functor)(const ValueType&) = nullptr
	); //DONE

};

template<typename ValueType>
AVLTree<std::string, ValueType>& counter(const std::string& fileName) {
	//open up the file
	std::ifstream file(fileName);
	if(!file) {
		throw std::runtime_error("File opening failed.");
	}
	//create a tree
	static AVLTree<std::string, ValueType> output;
	//start reading file and putting words inside the tree
	auto lambda = [](const ValueType& input){
		return input+1;
	};
	std::string word;
	while(file >> word) {
		// Uses overloaded method to pass incrementation function
		output.insert(word, 1, lambda);
	}
	return output;
}

template<typename ValueType>
void listing(const AVLTree <std::string, ValueType>& dictionary) {
	std::list<std::pair<std::string, int>> result = dictionary.enumerate();
	//sorting using custom comparison
	struct compare {
		bool operator()(
			const std::pair<std::string, int>& a,
			const std::pair<std::string, int>& b
		){
			if(a.second == b.second) {
				return a.first < b.first;
			}
			return a.second > b.second;
				
		}
	};
	result.sort(compare());
	for(std::pair<std::string, int> elem : result) {
		std::cout << elem.first << ',' << elem.second << '\n';
	}
}

#include "./AVLTreeImpl.hpp"


