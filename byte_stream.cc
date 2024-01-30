#include "byte_stream.hh"

ByteStream::ByteStream(const size_t capacity):  _capacity(capacity) {}


size_t ByteStream::write(const string& data) {
    size_t len = data.length();
    if (len > _capacity - _buffer.size()) {
        len = _capacity - _buffer.size();
    }
    _write_count += len;
    for (size_t i = 0; i < len; i++) {
        _buffer.push_back(data[i]);
    }
    return len;
}


string ByteStream::peek_output(const size_t len) const {
    size_t length = len;
    if (length > _buffer.size()) {
        length = _buffer.size();
    }
    return string().assign(_buffer.begin(), _buffer.begin() + length);
}


void ByteStream::pop_output(const size_t len) 
{
    size_t length = len;
    if (length > _buffer.size()) {
        length = _buffer.size();
    }
    _read_count += length;
    while (length--) {
        _buffer.pop_front();
    }
    return;
}


void ByteStream::end_input() { _input_ended_flag = true; }

bool ByteStream::input_ended() const { return _input_ended_flag; }

size_t ByteStream::buffer_size() const { return _buffer.size(); }

bool ByteStream::buffer_empty() const { return _buffer.size() == 0; }

bool ByteStream::eof() const { return buffer_empty() && input_ended(); }

size_t ByteStream::bytes_written() const { return _write_count; }

size_t ByteStream::bytes_read() const { return _read_count; }

size_t ByteStream::remaining_capacity() const { return _capacity - _buffer.size(); }


