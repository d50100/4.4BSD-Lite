

// LAB0  实验0  《 有序字节流 》

/*
	in-order byte stream
*/
#include <cstddef>
#include <string>
#include <queue>

using namespace std;

class ByteStream {
public:
	// 构造函数
	ByteStream(const size_t capacity);

	// 写入数据
	size_t write(const string& data);

	
	// 取出数据 （不删除）
	string peek_output(const size_t len) const;

	// 取出数据
	void pop_output(const size_t len);


	// 其他辅助函数
	void end_input();

	bool input_ended() const;

	size_t buffer_size() const;

	bool buffer_empty() const;

	bool eof() const;

	size_t bytes_written() const;

	size_t bytes_read() const;

	size_t remaining_capacity() const;

private:
	std::deque<char> _buffer = {};
	size_t _capacity = 0;            // 容量
	size_t _read_count = 0;          // 读取字节数
	size_t _write_count = 0;		 // 写入字节数
	bool _input_ended_flag = false;  // 输入结束标志
	bool _error = false;             // 错误标志
};

