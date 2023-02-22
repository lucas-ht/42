#include <algorithm>
#include <exception>

class EasyFindNotFound : public std::exception {
public:
    const char *what() const throw() {
        return "Not found";
    }
};

template <typename T>
typename T::iterator   easyfind(T& a, int i) {
    typename T::iterator it;

    it = std::find (a.begin(), a.end(), i);
    if (it == a.end())
        throw EasyFindNotFound();
    return it;
}