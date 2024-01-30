
// LAB1  实验1  《 流重组器 》

/*
	stream reassembler
*/


/*
	流重组

	将带索引的字节流碎片 重组成有序的字节流
	
	每个字节流碎片 都通过索引、长度、内容三要素进行描述..

	重组完成的字节流 应当被送进指定的字节流对象中  _output


	1. 碎片可能交叉或者重叠
	2. 如果某次新碎片到达后字节流的开头部分被凑齐，那就应当立即把凑齐的部分立即写入到 _output 中
	3. 碎片可能是一个只包含eof标志的空串
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
	ByteStream _output;       // 流重组器把字节流写满后，只有当字节流腾出空后才能继续写
	size_t _capacity;

	long merge_block(block_node& elm1, const block_node& elm2);

	// data 带索引的字节流碎片  todo 这个函数理解不了
	void push_substring(const string& data, const size_t index,
		const bool eof);

	size_t unassembled_bytes() const;
	bool empty() const;
};
