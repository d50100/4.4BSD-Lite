

// LAB0  ʵ��0  �� �����ֽ��� ��

/*
	in-order byte stream
*/
#include <cstddef>
#include <string>
#include <queue>

using namespace std;

class ByteStream {
public:
	// ���캯��
	ByteStream(const size_t capacity);

	// д������
	size_t write(const string& data);

	
	// ȡ������ ����ɾ����
	string peek_output(const size_t len) const;

	// ȡ������
	void pop_output(const size_t len);


	// ������������
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
	size_t _capacity = 0;            // ����
	size_t _read_count = 0;          // ��ȡ�ֽ���
	size_t _write_count = 0;		 // д���ֽ���
	bool _input_ended_flag = false;  // ���������־
	bool _error = false;             // �����־
};

