# Chess

### Prerequisites:
- Python3
- Flask



### Automated installation:
```chmod +x script_1_71_0.sh```

```./script_1_71_0.sh```

This script automatically builds and installs all required files for boost. Using boost_1_71_0

### Manual installation:


```sudo add-apt-repository universe```

```sudo apt-get update```

```sudo apt-get install libboost-all-dev```

```sudo apt-get install gcc (not needed)```

```sudo apt-get install g++(not needed)```



```./bootstrap.bat gcc --with-python=PYTHON```

```./b2 clean```

```./b2 --with-python link=static cxxflags="-std=c++11 -fPIC" variant=release stage```

```./b2 --with-python link=static cxxflags="-std=c++11 -fPIC" variant=release install```


test code from https://stackoverflow.com/questions/7195959/hello-world-with-boost-python-and-python-3-2?fbclid=IwAR2BDN60iFKOi28ep-99fL7FLx622alLhQu9_YBE3nYod0_aVylnMmsFWWA:

```
#include <iostream>

using namespace std;

void say_hello(const char* name) {
    cout << "Hello " <<  name << "!\n";
}

int main(){return 0;}

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(hello)
{
    def("say_hello", say_hello);
}
```

```g++ -std=c++11 hellopy.cpp -I/usr/include/python3.6 -I/Desktop/Boost/boost_1_60_0/ -lboost_python3  -o hello.so -shared -fPIC```


```python3```

```import hello```

```hello.say_hello('string')```




### Documentation:
https://docs.google.com/document/d/1X6gbnl_c4IqO27oWqCdfzpGKbXuc61YNTEv0DQXR5UQ/edit?usp=sharing
