class Foo
{
    private:
        int* array, size;
    public:
        Foo(int s)
        {
            this->size = s;
            this->array = new int[s] {0};
        }

        Foo(const Foo& rhs)
        {   
            size = rhs.size;
            array = new int[size];

            for(int i =0; i < size; i++)
                array[i] = rhs.array[i];
        }

        Foo(Foo&& rhs) noexcept
        {
            size = rhs.size;
            this->array = rhs.array;
            rhs.array = nullptr; 
        }

        ~Foo()
        {
            if(array)
                delete [] array;
        }

        Foo operator+(const Foo& rhs)
        {
            Foo temp(size + rhs.size);
            auto i = 0;
            for(; i < size; i++)
                temp[i] = this->array[i];
            for(auto j = 0; j < rhs.size; j++, i++)
                temp[i] = rhs.array[j];
            
            return temp;
        }

        int length() const {return this->size;}

        int& operator[](int i)
        {
            return this->array[i];
        }

        Foo& operator=(Foo&& rhs) noexcept
        {
            size = rhs.size;
            this->array = rhs.array;
            rhs.array = nullptr; 

            return *this;
        }

        Foo& operator=(const Foo& rhs)
        {
            if (this == &rhs)
                return *this;
            
            if (this->array)
                delete [] array;
            
            size = rhs.size;
            array = new int[size];

            for (int i =0; i < size; i++)
                array[i] = rhs.array[i];
            
            return *this;
        }
}

int main()
{
    Foo f(5);

    for (int i = 0; i < f.length(); i++)
        f[i] = 3 * i;
    
    Foo g(f); 

    Foo h(3);

    h = f + g;
}