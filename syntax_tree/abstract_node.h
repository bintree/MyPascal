#include <vector>
#include <string>
#include <utility>



#ifndef CLASS_H_ABSTRACT_NODE
#define CLASS_H_ABSTRACT_NODE

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
		AbstractNode(std::pair< int, int > beginPos, std::pair< int, int > endPos); //�����������
	public:
		virtual std::vector< AbstractNode* > * getChildren() = 0; //������, � �������� �� ��������� �����
		virtual std::string getDesc() = 0; // ���������� �������� ������ ������� ��� ��������������� ������
		
		virtual std::pair<int, int> getBeginPosition();
		virtual std::pair<int, int> getEndPosition();

		virtual void accept(class Visitor *v) = 0;
	};

	void reverseVector(std::vector< AbstractNode* > * a);
}

#endif
