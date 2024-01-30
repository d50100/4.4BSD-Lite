
// LAB1  ʵ��1  �� �������� ��

/*
	stream reassembler
*/


/*
	������

	�����������ֽ�����Ƭ �����������ֽ���
	
	ÿ���ֽ�����Ƭ ��ͨ�����������ȡ�������Ҫ�ؽ�������..

	������ɵ��ֽ��� Ӧ�����ͽ�ָ�����ֽ���������  _output


	1. ��Ƭ���ܽ�������ص�
	2. ���ĳ������Ƭ������ֽ����Ŀ�ͷ���ֱ����룬�Ǿ�Ӧ�������Ѵ���Ĳ�������д�뵽 _output ��
	3. ��Ƭ������һ��ֻ����eof��־�Ŀմ�
	4. 



*/

#include <cstddef>
#include <string>
#include <vector>
#include <set>
#include "byte_stream.hh"

using namespace std;

class StreamReassembler {
public:
	StreamReassembler(const size_t capacity);
private:
	// Your code here
	struct block_node {
		size_t begin = 0;
		size_t length = 0;
		std::string data = ""; 
		bool operator<(const block_node& t) const { return begin < t.begin; }
	};

	std::set<block_node> _blocks = {};
	std::vector<char> _buffer = {};
	size_t _unassembled_byte = 0;
	size_t _head_index = 0;
	bool _eof_flag = false;
	ByteStream _output;       // �����������ֽ���д����ֻ�е��ֽ����ڳ��պ���ܼ���д
	size_t _capacity;

	long merge_block(block_node& elm1, const block_node& elm2);

	// data ���������ֽ�����Ƭ  todo ���������ⲻ��
	void push_substring(const string& data, const size_t index,
		const bool eof);

	size_t unassembled_bytes() const;
	bool empty() const;
};
