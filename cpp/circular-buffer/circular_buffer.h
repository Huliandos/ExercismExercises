#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <stdexcept>
#include <utility>
#include <memory>

namespace circular_buffer {
    template <typename T>
    class circular_buffer{
public:
        explicit circular_buffer(unsigned int bufferSize) : buffer_{std::make_unique<T[]>(bufferSize)}, maxSize_{bufferSize} {}

        T read(){
            if(size_ == 0)
                throw std::domain_error("Can't read from empty buffer");

            size_--;
            
            unsigned int oldHeadPos = head_;
            head_ = advanceIndex(head_);
            
            return std::move(buffer_[oldHeadPos]);
        }

        void write(const T& item){
            if(size_ == maxSize_)
                throw std::domain_error("Can't write into full buffer");

            size_++;
            
            unsigned int oldTailPos = tail_;
            tail_ = advanceIndex(tail_);
            
            buffer_[oldTailPos] = item;
        }

        void overwrite(const T& item){
            //if buffer is full then clear oldest element in buffer
            if(size_ == maxSize_)
                read();

            //write item into buffer
            write(item);
        }

        void clear(){
            tail_ = head_;
            size_ = 0;
        }
private:
        std::unique_ptr<T[]> buffer_;
    	unsigned int head_ = 0, tail_ = 0;
    	unsigned int size_ = 0, maxSize_ = 0;

        unsigned int advanceIndex(unsigned int position){
            return (position + 1)%maxSize_;
        }
    };
}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H