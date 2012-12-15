#include <vector>
#include <string>
#include <utility>



#ifndef CLASS_H_ABSTRACT_NODE
#define CLASS_H_ABSTRACT_NODE

#define VECTOR_NODE_ITERATOR std::vector< syntax_tree::AbstractNode* >::iterator
#define ITERATE(it, a) for (VECTOR_NODE_ITERATOR it = a->begin(); it != a->end(); it++)

namespace syntax_tree {
	enum token_type {
		STRING_LITERAL,
		INTEGER_LITERAL,
		DOUBLE_LITERAL,
		VARIABLE,
		OTHER,
	};
	class AbstractNode {
	protected:
		std::pair< int, int > beginPos;
		std::pair< int, int > endPos;
		AbstractNode(std::pair< int, int > beginPos, std::pair< int, int > endPos); //конструктор
	public:
		virtual std::vector< AbstractNode* > * getChildren() = 0; //массив, у которого не определен конец
		virtual std::string getDesc() = 0; // возвращает описание текуще вершины для синтаксического дерева
		
		virtual std::pair<int, int> getBeginPosition();
		virtual std::pair<int, int> getEndPosition();

		virtual void accept(class Visitor *v) = 0;
	};

	void reverseVector(std::vector< AbstractNode* > * a);
}

#endif
