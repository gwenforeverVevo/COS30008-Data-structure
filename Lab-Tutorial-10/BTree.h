
// COS30008, Tutorial 12, 2024

#pragma once

#include <memory>
#include <cassert>
#include <iostream>

#include "Visitors.h"

template <typename T>
class BTree
{
public:
	using Node = std::unique_ptr<BTree>;

	BTree(const T &aKey = T{}) noexcept : fKey(aKey), fLeft(nullptr), fRight(nullptr)
	{
	}
	BTree(T &&aKey) noexcept : fKey(move(aKey)), fLeft(nullptr), fRight(nullptr)
	{
	}

	~BTree()
	{
		std::cout << "Delete " << fKey << std::endl;
	}

	template <typename... Args>
	static Node makeNode(Args &&...args)
	{
		return std::make_shared<BTree>(std::forward<Args>(args)...);
	}

	// copy semantics
	BTree(const BTree &aOther) : fKey(aOther.fKey),
								 fLeft(aOther.fLeft ? std::make_unique<BTree>(*aOther.fLeft) : nullptr),
								 fRight(aOther.fRight ? std::make_unique<BTree>(*aOther.fRight) : nullptr) {}

	BTree &operator=(const BTree &aOther)
	{
		if (this != &aOther)
		{
			fKey = aOther.fKey;
			fLeft = aOther.fLeft ? std::make_unique<BTree>(*aOther.fLeft) : nullptr;
			fRight = aOther.fRight ? std::make_unique<BTree>(*aOther.fRight) : nullptr;
		}
		return *this;
	}

	// move semantics
	BTree(BTree &&aOther) noexcept : fKey(std::move(aOther.fKey)), fLeft(std::move(aOther.fLeft)), fRight(std::move(aOther.fRight)) {}

	BTree &operator=(BTree &&aOther) noexcept
	{
		if (this != &aOther)
		{
			fKey = std::move(aOther.fKey);
			fLeft = std::move(aOther.fLeft);
			fRight = std::move(aOther.fRight);
		}
		return *this;
	}

	void swap(BTree &aOther) noexcept
	{
		std::swap(fKey, aOther.fKey);
		std::swap(fLeft, aOther.fLeft);
		std::swap(fRight, aOther.fRight);
	}

	// Accessors
	const T &operator*() const noexcept { return fKey; }
	bool hasLeft() const noexcept { return fLeft != nullptr; }
	BTree &left() const
	{
		assert(hasLeft());
		return *fLeft;
	}
	bool hasRight() const noexcept { return fRight != nullptr; }
	BTree &right() const
	{
		assert(hasRight());
		return *fRight;
	}

	// Mutators
	void attachLeft(Node aNode) { fLeft = std::move(aNode); }
	void attachRight(Node aNode) { fRight = std::move(aNode); }

	Node detachLeft() { return std::move(fLeft); }
	Node detachRight() { return std::move(fRight); }

	// Leaf node check
	bool leaf() const noexcept { return !fLeft && !fRight; }

	// Tree height
	size_t height() const noexcept
	{
		size_t leftHeight = fLeft ? fLeft->height() : 0;
		size_t rightHeight = fRight ? fRight->height() : 0;
		return 1 + std::max(leftHeight, rightHeight);
	}

	// Find maximum value
	const T &findMax() const noexcept
	{
		return fRight ? fRight->findMax() : fKey;
	}

	// Find minimum value
	const T &findMin() const noexcept
	{
		return fLeft ? fLeft->findMin() : fKey;
	}

	// Tree traversal
	void doDepthFirstSearch(const TreeVisitor<T> &aVisitor) const noexcept
	{
		if (fLeft)
			fLeft->doDepthFirstSearch(aVisitor);
		aVisitor.visit(fKey);
		if (fRight)
			fRight->doDepthFirstSearch(aVisitor);
	}

private:
	T fKey;
	Node fLeft;
	Node fRight;
};