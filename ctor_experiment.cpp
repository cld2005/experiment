#include <iostream>
#include <cstring>
class String
{
    public:
        String() = default;

        String(const char* string){
            printf("Created!\n");
            m_size = strlen(string);
            m_data = new char[m_size];
            memcpy(m_data,string,m_size);
        }

        String(const String& other){
            printf("Copied!\n");
            m_size = other.m_size;
            m_data = other.m_data;
            memcpy(m_data,other.m_data, m_size);
        }

        String(String && other) noexcept{
            printf("Moved!\n");
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_size = 0;
            other.m_data = nullptr;
        }

        ~String(){
            printf("Destroyed!\n");
            delete m_data;
        }

        void Print(){
            for (uint32_t i = 0; i< m_size;i++){
                printf("%c",m_data[i]);
            }
            printf("\n");
        }
    private:
        char * m_data;
        uint32_t m_size;
};

class Entity
{
    public:
    /*
    Entity(const String& name) : m_name(name){
    }

        Entity (String&& name):m_name(std::move(name)){

    }
    */


    Entity (String name):m_name(std::move(name)){

    }

    void PrintName(){
        m_name.Print();
    }

    private:
     String m_name;

};

int main(){
    String str("Experiment Entity");
    Entity entity(std::move(str));
}