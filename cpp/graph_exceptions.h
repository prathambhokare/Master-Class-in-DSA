#include <iostream> 
#include <stdexcept> 

class invalid_vertex : public std::runtime_error
{
    public: 
        invalid_vertex(const char* msg) : std::runtime_error(msg)
        {

        }
}; 


class invalid_edge : public std::runtime_error
{
    public: 
        invalid_edge(const char* msg) : std::runtime_error(msg)
        {

        }
}; 


class edge_exists : public std::runtime_error
{
    public: 
        edge_exists(const char* msg) : std::runtime_error(msg)
        {

        }
}; 


class vertex_exists : public std::runtime_error
{
    public: 
        vertex_exists(const char* msg) : std::runtime_error(msg)
        {

        }
}; 